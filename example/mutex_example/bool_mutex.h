#pragma once
#ifndef BOOL_MUTEX_H
#define BOOL_MUTEX_H

#include "mutex.h"


class bool_mutex: public mutex{
    bool variable;
public:
    bool_mutex();

    void set_variable(void* const);
    void get_variable(void*);
};

#endif //BOOL_MUTEX_H