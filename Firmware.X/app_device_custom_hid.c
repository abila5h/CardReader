/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

To request to license the code under the MLA license (www.microchip.com/mla_license), 
please contact mla_licensing@microchip.com
*******************************************************************************/

/** INCLUDES *******************************************************/
#include "usb.h"
#include "usb_device_hid.h"

#include <string.h>

#include "system.h"

/** VARIABLES ******************************************************/
/* Some processors have a limited range of RAM addresses where the USB module
 * is able to access.  The following section is for those devices.  This section
 * assigns the buffers that need to be used by the USB module into those
 * specific areas.
 */

USB_HANDLE USBOutHandle;    
USB_HANDLE USBInHandle;
unsigned char ReceivedDataBuffer[64] @ HID_CUSTOM_OUT_DATA_BUFFER_ADDRESS;
unsigned char ToSendDataBuffer[64] @ HID_CUSTOM_IN_DATA_BUFFER_ADDRESS;

/** FUNCTIONS ******************************************************/

/*********************************************************************
* Function: void APP_DeviceCustomHIDInitialize(void);
*
* Overview: Initializes the Custom HID demo code
*
* PreCondition: None
*
* Input: None
*
* Output: None
*
********************************************************************/


void APP_DeviceCustomHIDInitialize()
{
    //initialize the variable holding the handle for the last
    // transmission
    USBInHandle = 0;

    //enable the HID endpoint
    USBEnableEndpoint(CUSTOM_DEVICE_HID_EP, USB_IN_ENABLED|USB_OUT_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);

    //Re-arm the OUT endpoint for the next packet
    USBOutHandle = HIDRxPacket(CUSTOM_DEVICE_HID_EP,&ReceivedDataBuffer,5);
}

/*********************************************************************
* Function: void APP_DeviceCustomHIDTasks(void);
*
* Overview: Keeps the Custom HID demo running.
*
* PreCondition: The demo should have been initialized and started via
*   the APP_DeviceCustomHIDInitialize() and APP_DeviceCustomHIDStart() demos
*   respectively.
*
* Input: None
*
* Output: None
*
********************************************************************/
void APP_DeviceCustomHIDTasks()
{   
     /* If the USB device isn't configured yet, we can't really do anything
     * else since we don't have a host to talk to.  So jump back to the
     * top of the while loop. */
       /*  D3 = 0;
            D2 = 0;
            D1 = 0;
            D4 = 0; */

            
    if( USBGetDeviceState() < CONFIGURED_STATE )
    {
        return;
    }

    /* If we are currently suspended, then we need to see if we need to
     * issue a remote wakeup.  In either case, we shouldn't process any
     * keyboard commands since we aren't currently communicating to the host
     * thus just continue back to the start of the while loop. */
    if( USBIsDeviceSuspended()== true )
    {
        return;
    }
                
    if(HIDRxHandleBusy(USBOutHandle) == 0)
    {           
      
        
        if (ReceivedDataBuffer[2] == 0x41)//switch 2 door open
        {         	
            if(S2==0)
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x55;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x55+0x00);
            }
            else
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x00;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
            }
            
            if(!HIDTxHandleBusy(USBInHandle))
                USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
		}  
        
        if (ReceivedDataBuffer[2] == 0x42)//switch 3 door close
        {
			if(S3==0)
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x65;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x65+0x00);
            }
            else
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x00;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
            }
            if(!HIDTxHandleBusy(USBInHandle))
                USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
		}
        
        if (ReceivedDataBuffer[2] == 0x43)//if receive alarm ring command from host app
        {
			
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x00;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
                D1=~D1; //turn on LED 4
                if(!HIDTxHandleBusy(USBInHandle))
                USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
		}
        
        if (ReceivedDataBuffer[2] == 0x44) //INVALID ENTRY LED 3 Flash
        {
			
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x00;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
              
                
               D3 = 0;//Turn on LED 2
               D2 = 1;

                
                if(!HIDTxHandleBusy(USBInHandle))
                USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
		}
        
        if (ReceivedDataBuffer[2] == 0x45)	//VALID ENTRY FLASH
        {
			
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x00;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
               
                D3 =  1;
                D2 = 0;
                
                if(!HIDTxHandleBusy(USBInHandle))
                USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
		}
        
          if (ReceivedDataBuffer[2] == 0x50)//temperature up button pressed ? S4
        {
			if(PORTBbits.RB3==0)
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x65;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x65+0x00);
            }
            else
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x00;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
            }
            if(!HIDTxHandleBusy(USBInHandle))
                USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
		}
        
          if (ReceivedDataBuffer[2] == 0x51)//temperature down button pressed ? S5
        {
			if(PORTBbits.RB2==0)
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x65;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x65+0x00);
            }
            else
            {
                ToSendDataBuffer[0]=0xAB;
                ToSendDataBuffer[1]=0x01;
                ToSendDataBuffer[2]=0x00;
                ToSendDataBuffer[3]=0x00;
                ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
            }
            if(!HIDTxHandleBusy(USBInHandle))
                USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
		}
   
           //Re-arm the OUT endpoint for the next packet
        USBOutHandle = HIDRxPacket(CUSTOM_DEVICE_HID_EP, &ReceivedDataBuffer, 5); // OUT Endpoint package size is 5 bytes
    }    
} // end APP_DeviceCustomHIDTasks ()