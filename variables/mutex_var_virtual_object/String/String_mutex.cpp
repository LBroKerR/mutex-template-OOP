#include "String_mutex.h"

String_mutex::String_mutex(/* args */){
    array_var=nullptr;
}

void String_mutex::set_variable(void* param){
    if(param!=nullptr){
        array_var=(char*)param;
    }
}
void String_mutex::get_variable(void*param){
    if(param!=nullptr){
        param = (void*)array_var;
    }
}