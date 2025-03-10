#pragma once
#ifndef SINT_MUTEX_H
#define SINT_MUTEX_H

#include "mutex.h"


class sint_mutex: public mutex{
    int variable;
public:
    sint_mutex();

    void set_variable(void*)override;
    void get_variable(void*)override;
};

#endif //SINT_MUTEX_H