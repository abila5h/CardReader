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
//#include "system.h"


/** SWITCH (button) *********************************************************/
    #define InitAllSwitches()   TRISBbits.TRISB4=1;TRISBbits.TRISB5=1;
    #define InitS2()            TRISBbits.TRISB4=1;
    #define InitS3()            TRISBbits.TRISB5=1;
    #define S2                  PORTBbits.RB4
    #define S3                  PORTBbits.RB5

/** LED ************************************************************/
    #define InitAllLEDs()       TRISD &= 0xF0;		// To configure RD0 to RD3 as output, leave RD4-RD7 unchanged.
    
    #define D1                  PORTDbits.RD0		// 	Define mLED_1 as PORTDbits.RD0
    #define D2                  PORTDbits.RD1		//	
    #define D3                  PORTDbits.RD2   	//	
    #define D4                  PORTDbits.RD3   	//	


