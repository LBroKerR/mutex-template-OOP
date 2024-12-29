#pragma once
#ifndef UINT_MUTEX_H
#define UINT_MUTEX_H

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>

#define USE_MUTEX 1

#define MUTEX_WAIT_TIME_MS 1
#define MUTEX_WAIT_TICKS pdMS_TO_TICKS(MUTEX_WAIT_TIME_MS)

class uint_mutex{
    unsigned variable;
    SemaphoreHandle_t variable_mutex;
public:
    uint_mutex();

    bool set_variable(unsigned const);
    bool get_variable(unsigned*);
};

#endif //UINT_MUTEX_H