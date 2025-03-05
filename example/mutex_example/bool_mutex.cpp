#include "bool_mutex.h"

bool_mutex::bool_mutex(){
    variable=false;
}

void bool_mutex::set_variable(void* param){
    if(param!=nullptr){
        variable=*(bool*)param;
    }
}
void bool_mutex::get_variable(void*return_value){
    if(return_value!=nullptr){
        *(bool*)return_value=variable;
    }
}