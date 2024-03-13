#include "CROZONE_VEML6040.h"
/*
    getAllColor.ino

    Examples for using functions that our company has developed. To be used with the Crozone veml6040 board.

    Created 13 March 2024
    By YuTTYL
    Modified 13 March 2024
    By YuTTYL

    https://github.com/crozone-technology/crozone-veml6040

*/

CROZONE_VEML6040 VEML(&Wire); // You can change I2C wire channel according to your hardware communication wiring.

uint16_t r, g, b, w;
void setup()
{

    Serial.begin(115200);
    VEML.begin(); // Initial communication with the CROZONE VEML6040
    VEML.setConfiguration(VEML6040_IT_320MS, VEML6040_TRIG_DISABLE, VEML6040_AF_AUTO, VEML6040_ON);
    Serial.println(VEML.getStatus() ? "ON" : "OFF");
}

void loop()
{
    /*Get all color*/
    VEML.getAll(&r, &g, &b, &w);
    Serial.print("Red: ");
    Serial.println(r);
    Serial.print("Green: ");
    Serial.println(g);
    Serial.print("Blue: ");
    Serial.println(b);
    Serial.print("White: ");
    Serial.println(w);

    // You can read the color values of each function as follows.

    // Serial.print("Red: ");
    // Serial.println(VEML.getRed());
    // Serial.print("Green: ");
    // Serial.println(VEML.getGreen());
    // Serial.print("Blue: ");
    // Serial.println(VEML.getBlue());
    // Serial.print("White: ");
    // Serial.println(VEML.getWhite());
    delay(1000);
}