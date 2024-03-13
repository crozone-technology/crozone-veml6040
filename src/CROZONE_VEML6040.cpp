#include "CROZONE_VEML6040.h"

CROZONE_VEML6040::CROZONE_VEML6040(TwoWire *wire_set)
{
    _wire_port = wire_set;
};

bool CROZONE_VEML6040::begin(int sda, int scl)
{

    _wire_port->begin();
    _wire_port->beginTransmission(VEML6040_ADDRESS);
    if (_wire_port->endTransmission() == 0)
    {
        _device_found = true;
    }
    if (!_device_found)
    {
#ifdef VEML6040_DEBUG
        Serial.println("The CROZONE VEML6040 module is not found");
#endif
    }
    return _device_found;
}

void CROZONE_VEML6040::setConfiguration(int it_conf, int trig_conf, int af_conf, int sd_conf)
{
    _configuration = it_conf + trig_conf + af_conf + sd_conf;
    write(VEML6040_CONF_CODE, _configuration);
    if (sd_conf)
    {
        _veml_on = false;
    }
    else
    {
        _veml_on = true;
    }
}

void CROZONE_VEML6040::setOn(void)
{
    _configuration |= 1;
    write(VEML6040_CONF_CODE, _configuration);
    _veml_on = true;
#ifdef VEML6040_DEBUG
    Serial.println("The CROZONE VEML6040 module is enabled");
#endif
}

void CROZONE_VEML6040::setOff(void)
{
    _configuration ^= 1;
    write(VEML6040_CONF_CODE, _configuration);
    _veml_on = false;
#ifdef VEML6040_DEBUG
    Serial.println("The CROZONE VEML6040 module is disabled");
#endif
}

bool CROZONE_VEML6040::getStatus(void)
{
    return _veml_on;
}

uint16_t CROZONE_VEML6040::getRed(void)
{
    return read(VEML6040_RED_CMD);
}

uint16_t CROZONE_VEML6040::getGreen(void)
{
    return read(VEML6040_GREEN_CMD);
}

uint16_t CROZONE_VEML6040::getBlue(void)
{
    return read(VEML6040_BLUE_CMD);
}

uint16_t CROZONE_VEML6040::getWhite(void)
{
    return read(VEML6040_WHITE_CMD);
}

void CROZONE_VEML6040::getAll(uint16_t *red, uint16_t *green, uint16_t *blue, uint16_t *white)
{
    *red = read(VEML6040_RED_CMD);
    *green = read(VEML6040_GREEN_CMD);
    *blue = read(VEML6040_BLUE_CMD);
    *white = read(VEML6040_WHITE_CMD);
}

uint16_t CROZONE_VEML6040::read(uint8_t command)
{
    uint16_t data_read = 0;
    _wire_port->beginTransmission(VEML6040_ADDRESS);
    _wire_port->write(command);
    _wire_port->endTransmission(false);
    _wire_port->requestFrom(VEML6040_ADDRESS, 2);
    while (_wire_port->available())
    {
        data_read = _wire_port->read();
        data_read |= _wire_port->read() << 8;
    }
#ifdef VEML6040_DEBUG
    Serial.printf("data read: %d", data_read);
#endif
    return data_read;
}

void CROZONE_VEML6040::write(uint8_t command, uint16_t data)
{
    _wire_port->beginTransmission(VEML6040_ADDRESS);
    _wire_port->write(command);
    _wire_port->write(data);
    _wire_port->write(0); /* DATA BYTE HIGH is Reserved*/
    _wire_port->endTransmission();
}
