#include "Pim_var.h"

Pim_var::Pim_var() {
    var = new mutex*[TRUE]; 
    var[POINTER] = nullptr; 
    qualifier = VARIABLE_AVAILABLE;
    excusiveArea=xSemaphoreCreateMutex();
}
Pim_var::Pim_var(mutex* variable) {
    var = new mutex*[TRUE];
    var[POINTER] = variable; 
    qualifier = VARIABLE_AVAILABLE;
    excusiveArea=xSemaphoreCreateMutex();
}
Pim_var::~Pim_var()
{
    if(var!=nullptr){
        delete[] var;
    }
}
#ifdef USE_MUTEX
bool Pim_var::enter_ExcusiveArea(){
    if(excusiveArea!=nullptr){
        if(xSemaphoreTake(excusiveArea, MUTEX_WAIT_TICKS) == pdTRUE && var!=nullptr && var[POINTER]!=nullptr){
            qualifier=VARIABLE_AVAILABLE;
            return TRUE;
        }
    }
 return FALSE;
}

void Pim_var::leave_ExcusiveArea(){
    xSemaphoreGive(excusiveArea);
    qualifier=VARIABLE_NOT_AVAILABLE;
}
#endif
void Pim_var::set(void* value){
    if(VARIABLE_AVAILABLE == qualifier && value!=nullptr){
        var[POINTER]->set_variable(value);
    }
}
void Pim_var::get(void* value){
    if(VARIABLE_AVAILABLE == qualifier){
        var[POINTER]->get_variable(value);
    }
}
unsigned Pim_var::get_qualifier() const{
  return qualifier;
}