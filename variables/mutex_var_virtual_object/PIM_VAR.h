#pragma once
#ifndef PIM_VAR
#define PIM_VAR

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include "mutex.h"
#include "limits.h"


#define USE_MUTEX                     TRUE
#define MUTEX_WAIT_TIME_MS            WAITING_TIME
#define MUTEX_WAIT_TICKS              pdMS_TO_TICKS(MUTEX_WAIT_TIME_MS)

#define QUALIFIER_NOT_AVAILABLE       NOT_AVAILABLE
#define QUALIFIER_AVAILABLE           AVAIABLE

typedef unsigned dtQualifier;
typedef SemaphoreHandle_t dtExcusiveArea;


class Pim_var
{
    mutex **var;
    dtQualifier qualifier;
    dtExcusiveArea excusiveArea;

public:

    Pim_var();
    Pim_var(mutex* var);
    ~Pim_var();

    void set_variable_type(mutex* var);

#ifdef USE_MUTEX
    bool enter_ExcusiveArea();
    void leave_ExcusiveArea();
#endif
    void set(void* value);
    void get(void* value);

    dtQualifier get_qualifier();
};



#endif //PIM_VAR