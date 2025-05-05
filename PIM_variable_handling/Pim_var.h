#pragma once
#ifndef PIM_VAR
#define PIM_VAR

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include "mutex.h"
#include "project_limit.h"


#define USE_MUTEX                     TRUE
#define MUTEX_WAIT_TIME_MS            WAITING_TIME
#define MUTEX_WAIT_TICKS              pdMS_TO_TICKS(MUTEX_WAIT_TIME_MS)

#define VARIABLE_NOT_AVAILABLE        NOT_AVAILABLE
#define VARIABLE_AVAILABLE            AVAIABLE
#define POINTER                       0

//typedef unsigned dtQualifier;
//typedef SemaphoreHandle_t dtExcusiveArea;


class Pim_var
{
    mutex **var;
    unsigned qualifier;
#ifdef USE_MUTEX
    SemaphoreHandle_t exclusiveArea;
#endif
public:

    Pim_var();
    Pim_var(mutex* var);
    ~Pim_var();

    void set_variable_type(mutex* var);

#ifdef USE_MUTEX
    bool enter_ExclusiveArea();
    void leave_ExclusiveArea();
#endif
    void set(void* value);
    void get(void* value);
    unsigned get_qualifier() const;
};



#endif //PIM_VAR