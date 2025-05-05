#pragma once
#ifndef VARIABLE_TYPES_H
#define VARIABLE_TYPES_H

#include "Variable.h"
#include "char_list.h"



typedef Variable  dtTemperature;              
typedef Variable  dtHumidity;                 
typedef Variable  dtProgram_mode;             
typedef Variable  dtProgram_selector;         
typedef Variable  dtProgram_elem_selector;    
typedef Variable  dtHour;                    
typedef Variable  dtMinute;                  
typedef Variable  dtHeating_Switch;
typedef Variable  dtWanted_temperature;
typedef Variable  dtHeating_mode;
typedef Variable  dtSensor_location;
typedef char_list dtRaw_IP_Address;
typedef Variable  dtIP_Address;
typedef char_list dtRaw_Nick_name;
typedef Variable  dtNick_name;
typedef Variable  dtID;

typedef char_list dtSSID;
typedef char_list dtPassword;
typedef char_list dtMAC_Address;

#endif // VARIABLE_TYPES_H