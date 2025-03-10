#include "uint_mutex.h"

uint_mutex::uint_mutex(){
    variable=0;
}

void uint_mutex::set_variable(void* param){
    if(param!=nullptr){
        variable=*(unsigned*)param;
    }
}
void uint_mutex::get_variable(void*return_value){
    if(return_value!=nullptr){
        *(unsigned *)return_value=variable;//change variable value
    }
}