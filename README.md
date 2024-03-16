
![Build Status](https://img.shields.io/badge/Build-Pass-Green)

# crozone-veml6040 Library
This library is designed for use with the CROZONE VEML6040 module manufactured by Crozone Technology Company Limited. It enables easy integration of the VEML6040 module functionality into your Arduino or ESP-based projects.

## Installation

### Arduino Library Manager

You can install this library directly through the Arduino Library Manager. Follow these steps:

1. Open the Arduino IDE.
2. Navigate to **Sketch > Include Library > Manage Libraries...**.
3. In the Library Manager, search for "CROZONE-VEML6040".
4. Click on the library in the list.
5. Click the "Install" button.

### Manual Installation

To manually install the library, follow these steps:

1. Download the latest version of the library from the [GitHub repository](https://github.com/crozone-technology/crozone-veml6040/releases/tag/0.1.0).
2. Extract the downloaded ZIP file.
3. Move the extracted folder to your Arduino libraries folder. Typically, this folder is located at:
   - **For Windows**: `Documents\Arduino\libraries`
   - **For macOS**: `~/Documents/Arduino/libraries`
   - **For Linux**: `~/Arduino/libraries`


## Usage
### Include the Library

```cpp
#include "CROZONE_VEML6040.h"
```
### Initialize the Library
```cpp
// Create an instance of the library
CROZONE_VEML6040 VEML;

// Optionally, pass the Wire object if using a different I2C bus
// CROZONE_VEML6040 VEML(&Wire1);
```
### Initialize the Module
```cpp
void setup() {
    // Initialize the module
    VEML.begin();
    //Config
    VEML.setConfiguration(VEML6040_IT_320MS, VEML6040_TRIG_DISABLE, VEML6040_AF_AUTO, VEML6040_ON);
}
```
## PARAMETER FOR CONFIGURATION
### Integration time setting
| Integration Time | Hex Value | G Sensitivity | Max. Detectable Lux |
|------------------|-----------|---------------|---------------------|
| VEML6040_IT_40MS | 0x00      | 0.25168       | 16.496              |
| VEML6040_IT_80MS | 0x10      | 0.12584       | 8248                |
| VEML6040_IT_160MS| 0x20      | 0.06292       | 4124                |
| VEML6040_IT_320MS| 0x30      | 0.03146       | 2062                |
| VEML6040_IT_640MS| 0x40      | 0.01573       | 1031                |
| VEML6040_IT_1280MS| 0x50     | 0.007865      | 515.4               |

### Proceed one detecting cycle at manual force mode
| Name | Hex Value | Mode  |
|------------------|-----------|---------------|
| VEML6040_TRIG_ENABLE | 0x04      |  trigger one time detect cycle  |
| VEML6040_TRIG_DISABLE | 0x00     |  no trigger  |
 
### AF mode
| Name | Hex Value | Mode  |
|------------------|-----------|---------------|
| VEML6040_AF_AUTO | 0x00      |  Auto mode  |
| VEML6040_AF_FORCE | 0x02      |  Force mode  |
 
 
### Enable sensor
| Name | Hex Value | Mode  |
|------------------|-----------|---------------|
| VEML6040_ON | 0x00      |  Enable sensor  |
| VEML6040_OFF | 0x01      |  Disable sensor  |


### Control the Module
```cpp
// Turn the module on
VEML.setOn();

// Turn the module off
VEML.setOff();

// Check if the module is on
bool isOn = VEML.getStatus();
```
### Read Sensor Data
```cpp
// Read individual color values
uint16_t redValue = VEML.getRed();
uint16_t greenValue = VEML.getGreen();
uint16_t blueValue = VEML.getBlue();
uint16_t whiteValue = VEML.getWhite();

// Read all color values at once
uint16_t red, green, blue, white;
VEML.getAll(&red, &green, &blue, &white);
```
