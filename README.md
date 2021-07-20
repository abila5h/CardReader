# CardReader
Software which can read MIFARE / FeliCa cards and also execute commands to a PIC18F4550 MCU.

A system which can be implemented in public transport (buses) or fare collection systems.

## Synopsis
For this project, a project board which had a PIC18F4550 MCU, LEDs, Switches, UM232R and a RS-485 Transceiver was given along with a Autostar Wiegand Card Reader. I was tasked to design an executable which will be able to read the cards from the reader and also execute commands to the project board. This is to simulate a system which can be implemented in public buses to aid in the passenger count, card value deduction and assisting the bus captain.

This project serves as a skeleton code for any project which requires the need to serially communicate (read/write) to external peripherals through USB.


## Project Functionalities
* Detecting MiFare / Felica Card along with the Unique Card ID
* Passenger count based on entry and exit (2 card readers)
* Open and Close Door simulation based on switch buttons
* Temperature control simulation based on switch buttons
* Validation for entries and exits (low fare, multiple taps)


## Built With

### Software
* [MPLAB X Ide](http://www.microchip.com/mplab/mplab-x-ide) - Used for programming the MCU firmware
* [XC8 Compiler](http://www.microchip.com/mplab/compilers) - Needed for translating C code to machine language
* [Visual C++](https://www.visualstudio.com/vs/cplusplus/) - GUI for the executable and serial communications to the MCU and Card Reader
* External Libraries in C++ (USB_Hid and Serial_Comm)

### Hardware
* [PIC18F4550 MCU](http://www.microchip.com/wwwproducts/en/PIC18F4550)
* LEDs and Switches
* UM232R USB to Serial UART
* RS-485 Transceiver
* [Project Board](http://pic-microcontroller.com/usb-interface-board-tutorial-using-pic18f4550/) - PIC18F4550 interfaced and wired together with the above LEDs, Switches, UM232R and RS-485 IC. (The project board was issued by the school)
* [ICD 3](http://www.microchip.com/Developmenttools/ProductDetails.aspx?PartNO=DV164035) - Required to program the MCU with the firmware
* [Autostar Wiegand Card Reader](http://www.autostar.com.sg/images/pdf/TSSOHO%20Prof.pdf)

## System Diagram
![Picture](http://i.imgur.com/kBkCchY.png)


## Getting Started

### Prerequisites

```
MPLAB X IDE, Visual Studio 
```

### Installing
* Download the Zip File of this Project
* Open Visual Studio and in the file menu, click on Open ▸ Project/Solution and select

```
Bus Project.sln
```

* Open MPLAB X IDE and File ▸ Open Project and select

```
Firmware.X
```

The main code you should have opened are

```
Form1.h in Visual Studio
```

and

```
app_device_custom_hid.c in MPLAB
```
## Code Example

### The API that is used for USB Communication is Microsoft' USB HID API which has these four functions

```cpp
CreateFile
```

```cpp
WriteFile
```

```cpp
ReadFile
```

```cpp
CloseHandle
```

### Enabling Serial Communication
```cpp
int ret;
Serial_SetComport(comportval);
Serial_SetBaudrate(19200);
Serial_ClearBuffer();
ret=Serial_Open();

```
### Polling for a button
Application sends a command to the MCU to check if switch is pressed in project board using USB HID function (Visual Studio)
```cpp
 write_buffer[0] = 0x00;
 write_buffer[1] = 0xAB;
 write_buffer[2] = 0x04;
 write_buffer[3] = 0x41; //command packet to be sent to MCU
 write_buffer[4] = 0x00;
 write_buffer[5] = 0xFF - (0x04 + 0x41 + 0x00);
 result3 = WriteFile(HID_Handle, write_buffer, 6, &bytes_written,0);
 result3 = ReadFile(HID_Handle, read_buffer, 6, &bytes_read, 0); // Packets received from MCU
 if(result3 ==0)
	{
	return;
	}
 if(result3 != 0)
	{
	if(read_buffer[3] == 0x55)
	{
		lblDoor -> Text = "Open";
	}

	}
```
MCU replies to the host (Firmware, MPLAB)
```C
if (ReceivedDataBuffer[2] == 0x41)//Received command from Host Application to poll for switch
{         	
        if(S2==0) // If switch is pressed
         {
             ToSendDataBuffer[0]=0xAB;
             ToSendDataBuffer[1]=0x01;
             ToSendDataBuffer[2]=0x55; //Command packet to send to PC
             ToSendDataBuffer[3]=0x00;
             ToSendDataBuffer[4]=0xFF -(0x01+0x55+0x00);
         }
         else
         {
             ToSendDataBuffer[0]=0xAB;
             ToSendDataBuffer[1]=0x01;
             ToSendDataBuffer[2]=0x00; //Command packet to send to PC
             ToSendDataBuffer[3]=0x00;
             ToSendDataBuffer[4]=0xFF -(0x01+0x00+0x00);
         }
            
         if(!HIDTxHandleBusy(USBInHandle))
             USBInHandle=HIDTxPacket(CUSTOM_DEVICE_HID_EP, &ToSendDataBuffer[0],5);
}  
```
### 3rd Party Card Reader's Packet Schematic

![1](http://i.imgur.com/hQxFmHV.png)

## Screenshots of the executable

![1](http://i.imgur.com/RhI9tRU.png)

![2](http://i.imgur.com/dVvzEYD.png)

![3](http://i.imgur.com/sqiG80Z.png)

![4](http://i.imgur.com/rPF68pw.png)

## Contributors
* Abilash - Code and Documentation


