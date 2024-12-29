#include "uint_mutex.h"

uint_mutex::uint_mutex(){
    variable=0;
    variable_mutex=nullptr;
    #ifdef USE_MUTEX
     variable_mutex=xSemaphoreCreateMutex();  // Create the mutex
    #endif

}

bool uint_mutex::set_variable(unsigned const param){
#ifdef USE_MUTEX
    if(variable_mutex!=nullptr){// Sanity check if the mutex exists
        if (xSemaphoreTake(variable_mutex, MUTEX_WAIT_TICKS) == pdTRUE){// Try to take the mutex and wait  MUTEX_WAIT_TICKS if needed
        // Mutex successfully taken
#endif
            variable=param; //change variable value
#ifdef USE_MUTEX
            xSemaphoreGive( variable_mutex);// After accessing the shared resource give the mutex and allow other processes to access it
        }
        else{
            //can not access
            return false;
        }
    }
#endif
    return true;
}
bool uint_mutex::get_variable(unsigned*return_value){
    #ifdef USE_MUTEX
    if(variable_mutex!=nullptr){// Sanity check if the mutex exists
        if (xSemaphoreTake(variable_mutex, MUTEX_WAIT_TICKS) == pdTRUE){// Try to take the mutex and wait  MUTEX_WAIT_TICKS if needed
        // Mutex successfully taken
#endif
            *return_value=variable;//change variable value
#ifdef USE_MUTEX
            xSemaphoreGive( variable_mutex);// After accessing the shared resource give the mutex and allow other processes to access it
        }
        else{
            //can not access
            return false;
        }
    }
#endif
    return true;
}