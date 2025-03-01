// DS3231.hpp
// Header file for the DS3231 RTC module
// Matt Rossouw (omeh-a)
// 05/2023

#ifndef DS3231_H
#define DS3231_H

#include <sys/time.h>
#include "Device.hpp"
#include "i2c_cxx.hpp"

#define DS3231_I2C_ADDR 0x68

typedef struct {
    int seconds;
    int minutes;
    int hours;
    int day; // of week
    int date; // of month
    int month;
    int year;
} rtc_datetime_t;

// Class prototype
class DS3231 : public Device {
public:
    DS3231();

    // Device methods
    struct timeval getTime();
    status checkOK() override;
    status init(std::shared_ptr<idf::I2CMaster>);
    status update();

    rtc_datetime_t getDateTime();

    void stop() override;

protected: 
    void watchdog_task(void *parameters) override;
    void watchdog_callback(TimerHandle_t xtimer) override;

private:
    std::unique_ptr<idf::I2CAddress> addr;
    std::shared_ptr<idf::I2CMaster> i2c;

    status alive;
    rtc_datetime_t rtcTime;
};

#endif
