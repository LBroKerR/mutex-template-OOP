#include "sint_mutex.h"

sint_mutex::sint_mutex(){
    variable=0;
}

void sint_mutex::set_variable(void* param){
    if(param!=nullptr){
        variable=*(int*)param;
    }
}
void sint_mutex::get_variable(void*return_value){
    if(return_value!=nullptr){
        *(int *)return_value=variable;//change variable value
    }
}