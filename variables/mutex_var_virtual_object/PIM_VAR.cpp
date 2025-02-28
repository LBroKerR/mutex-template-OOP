#include "Pim_var.h"

Pim_var::Pim_var(/* args */)
{
    var=new mutex*[TRUE];
    qualifier=QUALIFIER_AVAILABLE;
}
Pim_var::Pim_var(mutex* variable){
    var=new mutex*[TRUE];
    *var=variable;
    qualifier=QUALIFIER_AVAILABLE;
}
Pim_var::~Pim_var()
{
    if(var!=nullptr){
        delete var;
    }
}
#ifdef USE_MUTEX
bool Pim_var::enter_ExcusiveArea(){
 while(xSemaphoreTake(excusiveArea, MUTEX_WAIT_TICKS) == pdTRUE){
    qualifier=QUALIFIER_AVAILABLE;
    return TRUE;
 }
 return FALSE;
}

void Pim_var::leave_ExcusiveArea(){
    xSemaphoreGive(excusiveArea);
    qualifier=QUALIFIER_NOT_AVAILABLE;
}
#endif
void Pim_var::set(void* value){
    if(QUALIFIER_AVAILABLE==qualifier && value!=nullptr){
        var[0]->set_variable(value);
    }
}
void Pim_var::get(void* value){
    if(QUALIFIER_AVAILABLE==QUALIFIER_AVAILABLE){
        var[0]->get_variable(value);
    }
}