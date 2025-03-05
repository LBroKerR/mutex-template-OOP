#pragma once
#ifndef UINT_MUTEX_H
#define UINT_MUTEX_H

#include "mutex.h"


class uint_mutex: public mutex{
    unsigned variable;
public:
    uint_mutex();

    void set_variable(void* const);
    void get_variable(void*);
};

#endif //UINT_MUTEX_H