#pragma once
#ifndef FLOAT_MUTEX_H
#define FLOAT_MUTEX_H

#include "mutex.h"



class float_mutex: public mutex{
    float variable;
public:
    float_mutex();

    void set_variable(void* const);
    void get_variable(void*);
};

#endif //FLOAT_MUTEX_H