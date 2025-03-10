#pragma once
#ifndef STRING_MUTEX_H
#define STRING_MUTEX_H

#include "mutex.h"

class String_mutex: public mutex{

    char* array_var;

public:
    String_mutex();

    void set_variable(void*)override;
    void get_variable(void*)override;
};



#endif //STRING_MUTEX_H