#include "float_mutex.h"

float_mutex::float_mutex(){
    variable=0.0;
}

void float_mutex::set_variable(void* const param){
    if(param!=nullptr){
        variable=*(float*)param;
    }
}
void float_mutex::get_variable(void*return_value){
    if(return_value!=nullptr){
        *(float *)return_value=variable;
    }
}