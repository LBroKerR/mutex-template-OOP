#pragma once
#ifndef STRING_MUTEX_H
#define STRING_MUTEX_H

#include "mutex.h"
#include "char_list.h"

class String_mutex: public mutex{

    char_list *array_var;

public:
    String_mutex();
    ~String_mutex();

    void set_variable(void*)override;
    void get_variable(void*)override;
};



#endif //STRING_MUTEX_H