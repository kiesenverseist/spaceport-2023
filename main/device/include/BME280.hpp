// BME280.hpp
// Header file for the BME280 pressure sensor
// Matt Rossouw (omeh-a)
// 05/2023

#ifndef BME280_H
#define BME280_H

#include "Device.hpp"


class BME280 : public Device {
public:
    BME280();

    // Device methods
    std::vector<baro_reading_t> read();
    status checkOK() override;
    status init() override;
};
#endif