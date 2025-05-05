#pragma once
#ifndef VARIABLE_H
#define VARIABLE_H

#include "Variable_limits.h"

#include "Pim_var.h"

class Variable {

    Pim_var *variable;
    Pim_var **condition;
    unsigned size_of_conditions;

public:

    Variable();
    ~Variable();

    bool init(unsigned size_of_conditions, unsigned variable_selector);

    bool set_Variable(void* Variable);
    
    bool get_Variable(void *Variable);
    bool get_Variable_via_condition(void *Variable, unsigned condition);

};

#endif // VARIABLE_H