#ifndef CROZONE_VEML6040_H
#define CROZONE_VEML6040_H

#include <Arduino.h>
#include <Wire.h>

#define VEML6040_ADDRESS 0x10
#define VEML6040_CONF_CODE 0x00
#define VEML6040_RED_CMD 0x08
#define VEML6040_GREEN_CMD 0x09
#define VEML6040_BLUE_CMD 0x0A
#define VEML6040_WHITE_CMD 0x0B

#define VEML6040_IT_40MS 0x00   /* G sensitivity is 0.25168 & Max. detectable lux is 16.496 */
#define VEML6040_IT_80MS 0x10   /* G sensitivity is 0.12584 & Max. detectable lux is 8248 */
#define VEML6040_IT_160MS 0x20  /* G sensitivity is 0.06292 & Max. detectable lux is 4124 */
#define VEML6040_IT_320MS 0x30  /* G sensitivity is 0.03146 & Max. detectable lux is 2062 */
#define VEML6040_IT_640MS 0x40  /* G sensitivity is 0.01573 & Max. detectable lux is 1031 */
#define VEML6040_IT_1280MS 0x50 /* G sensitivity is 0.007865 & Max. detectable lux is 515.4 */

#define VEML6040_TRIG_ENABLE 0x04
#define VEML6040_TRIG_DISABLE 0x00

#define VEML6040_AF_AUTO 0x00
#define VEML6040_AF_FORCE 0x02

#define VEML6040_ON 0x00
#define VEML6040_OFF 0x01

class CROZONE_VEML6040
{
private:
    TwoWire *_wire_port;
    bool _device_found;
    uint8_t _configuration = 0;
    bool _veml_on = false;

    uint16_t read(uint8_t command);
    void write(uint8_t command, uint16_t data);

public:
    CROZONE_VEML6040(TwoWire *wire_set = &Wire);

    bool begin(int sda = -1, int scl = -1);
    void setConfiguration(int it_conf, int trig_conf, int af_conf, int sd_conf);
    void setOn(void);
    void setOff(void);
    bool getStatus(void);
    uint16_t getRed(void);
    uint16_t getGreen(void);
    uint16_t getBlue(void);
    uint16_t getWhite(void);
    void getAll(uint16_t *red, uint16_t *green, uint16_t *blue, uint16_t *white);
};

#endif