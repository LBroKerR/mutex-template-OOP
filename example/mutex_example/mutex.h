#pragma once
#ifndef MUTEX_H
#define MUTEX_H

class mutex{

public:
    mutex();
    ~mutex();
    virtual void get_variable(void*)=0;
    virtual void set_variable(void*)=0; 
};

#endif //MUTEX_H