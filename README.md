# CardReader
Software which can read MIFARE / FeliCa cards and also execute commands to a PIC18F4550 MCU.

A system which can be implemented in public transport (buses) or fare collection systems.

## Synopsis
For this project, a project board which was had a PIC18F4550 MCU, LEDs, Switches, UM232R and a RS-485 Transceiver was given along with a Autostar Wiegand Card Reader. I was tasked to design an executable which will be able to read the cards from the reader and also execute commands to the project board. This is to simulate a system which can be implemented in public buses to aid in the passenger count, card value deduction and assisting the bus captain.

This project serves as a skeleton code for any project which requires the need to serially communicate (read/write) to external peripherals through USB.

This is the final project of Computer Interfacing, a subject in my institution, Temasek Polytechnic


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

```
CreateFile
```

```
WriteFile
```

```
ReadFile
```

```
CloseHandle
```

### 3rd Party Card Reader's Packet Schematic

![1](http://i.imgur.com/hQxFmHV.png)

## Screenshots of the executable

![1](http://i.imgur.com/RhI9tRU.png)

![2](http://i.imgur.com/dVvzEYD.png)

![3](http://i.imgur.com/sqiG80Z.png)

![4](http://i.imgur.com/rPF68pw.png)

## Contributors
* Abilash - Code 
* Darrick, Jeanie - Wiring of the Project Board, Card Reader
* Temasek Polytechnic - Project Resources


