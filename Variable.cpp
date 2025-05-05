#include "Variable.h"

Variable::Variable() {
    size_of_conditions = 0;
    variable = nullptr;
    condition = nullptr;
}

Variable::~Variable() {
    if (variable != nullptr) {
        delete variable;
    }
    for (unsigned index = 0; index < size_of_conditions; index++) {
        if (condition[index] != nullptr) {
            delete condition[index];
        }
    }
    if(condition!=nullptr){
        delete[] condition;
    }
}
void init(unsigned size_of_conditions, unsigned variable_selector){
    bool helper = SEN_AVAILABLE;
    if(size_of_conditions > UPPER_CONDITION_LIMIT){
        #error "Size of conditions is out of bounds"
    }
    condition = new Pim_var*[size_of_conditions];
    for (unsigned i = 0; i < size_of_conditions; i++){
        condition[i]=new Pim_var(new bool_mutex);
        condition[i]->set((void*)&helper);
    }
    this->size_of_conditions = size_of_conditions;
    switch (variable_selector){
    case BOOL:   variable = new Pim_var(new bool_mutex);   return;
    case FLOAT:  variable = new Pim_var(new float_mutex);  return;
    case SINT:   variable = new Pim_var(new sint_mutex);   return;
    case STRING: variable = new Pim_var(new String_mutex); return;
    case UINT:   variable = new Pim_var(new uint_mutex);   return;
    default: break;
    }
    #error "Variable is not on the list"
}

bool Variable::set_Variable(void* Variable) {
    bool status = SEN_NOT_AVAILABLE;
    bool output = NOT_RELIABLE;
    bool condition_helper[size_of_conditions] = {FALSE};
    for (unsigned index = 0; index < size_of_conditions; index++) {
        if (condition[index]->enter_ExclusiveArea()) {
            condition_helper[index] = RELIABLE;
        }
    }
    if (this->variable->enter_ExclusiveArea() 
        && condition_helper[WIFI_TASK] 
        && condition_helper[GUI_TASK]) {
            status = SEN_AVAILABLE;
            this->variable->set(Variable);
            this->variable->leave_ExclusiveArea();
            output = RELIABLE;
    }
    for (unsigned index = 0; index < size_of_conditions; index++) {
        if (condition[index]->get_qualifier() == RELIABLE) {
            condition[index]->set((void*)&status);
            condition[index]->leave_ExclusiveArea();
        }
    }
    return output;
}

bool Variable::get_Variable(void *Variable) {
    bool output = NOT_RELIABLE;
    if (Variable != nullptr && this->variable->enter_ExclusiveArea()) {
        this->variable->get(Variable);
        output = RELIABLE;
        this->variable->leave_ExclusiveArea();
    }
    return output;
}

bool Variable::get_Variable_via_condition(void*Variable, unsigned condition) {
    bool status = SEN_NOT_AVAILABLE;
    bool output = NOT_RELIABLE;
    if (condition < size_of_conditions 
        && Variable != nullptr 
        && this->condition[condition]->enter_ExclusiveArea()) {
            this->condition[condition]->get((void*)&status);
            if (get_Variable(Variable)) {
                if (status == SEN_AVAILABLE) {
                    status = SEN_NOT_AVAILABLE;
                    this->condition[condition]->set((void*)&status);
                    output = RELIABLE;
                }
            }
            this->condition[condition]->leave_ExclusiveArea();
    }
    return output;
}