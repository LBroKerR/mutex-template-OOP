#pragma once
#ifndef VARIABLE_LIMITS_H
#define VARIABLE_LIMITS_H

#define WIFI_TASK                          1
#define GUI_TASK                           0
#define EEPROM_TASK                        2

#define THREE_CONDITIONS                   3
#define TWO_CONDITIONS                     2
#define ONE_CONDITION                      1

#define UPPER_CONDITION_LIMIT              2
#define LOWER_CONDITION_LIMIT              0

#define TRUE                               1
#define FALSE                              0

#define WAITING_TIME                       1

#define NOT_RELIABLE                      FALSE
#define RELIABLE                          TRUE

#define SEN_NOT_AVAILABLE                 FALSE
#define SEN_AVAILABLE                     TRUE

#define BOOL                               0
#define FLOAT                              1
#define SINT                               2
#define STRING                             3
#define UINT                               4

#define UPPER_CONDITION_LIMIT              3
#define LOWER_CONDITION_LIMIT              0

/*Temperature*/
#define UPPER_TEMPERATURE_LIMIT            100
#define LOWER_TEMPERATURE_LIMIT            -20

#define TEMPERATURE_CONDITION              2
#define TEMPERATURE_TYPE                   FLOAT


/*Humidity*/
#define UPPER_HUMIDITY_LIMIT               100
#define LOWER_HUMIDITY_LIMIT               0

#define HUMIDITY_CONDITION                 2
#define HUMIDITY_TYPE                      UINT

/*Program_mode*/

#define UPPER_PROGRAM_MODE_LIMIT           TRUE
#define LOWER_PROGRAM_MODE_LIMIT           FALSE

#define PROGRAM_MODE_CONDITION             1
#define PROGRAM_MODE_TYPE                  BOOL

/*Program_selector*/
#define UPPER_PROGRAM_SELECTOR_LIMIT       5
#define LOWER_PROGRAM_SELECTOR_LIMIT       0

#define PROGRAM_SELECTOR_CONDITION         3
#define PROGRAM_SELECTOR_TYPE              SINT

/*Program_elem_selector*/
#define UPPER_PROGRAM_ELEM_SELECTOR_LIMIT  23
#define LOWER_PROGRAM_ELEM_SELECTOR_LIMIT  0

#define PROGRAM_ELEM_SELECTOR_CONDITION    1
#define PROGRAM_ELEM_SELECTOR_TYPE         SINT

/*Hour*/
#define UPPER_HOUR_LIMIT                   23
#define LOWER_HOUR_LIMIT                   0

#define HOUR_CONDITION                     3
#define HOUR_TYPE                          SINT


/*Minute*/
#define UPPER_MINUTE_LIMIT                 59
#define LOWER_MINUTE_LIMIT                 0

#define MINUTE_CONDITION                   3
#define MINUTE_TYPE                        SINT

/*Heating_Switch*/
#define UPPER_HEATING_SWITCH_LIMIT         3
#define LOWER_HEATING_SWITCH_LIMIT         0

#define HEATING_SWITCH_ON                  3
#define HEATING_SWITCH_OFF                 2
#define COOLING_SWITCH_ON                  1
#define COOLING_SWITCH_OFF                 0

#define HEATING_SWITCH_CONDITION           2
#define HEATING_SWITCH_TYPE                UINT

/*Wanted_temperature*/
#define UPPER_WANTED_TEMPERATURE_LIMIT     30.0
#define LOWER_WANTED_TEMPERATURE_LIMIT     10.0

#define WANTED_TEMPERATURE_CONDITION       2
#define WANTED_TEMPERATURE_TYPE            FLOAT

/*Heating_mode*/
#define UPPER_HEATING_MODE_LIMIT           2
#define LOWER_HEATING_MODE_LIMIT           0

#define GAS_HEATER                         0
#define HEATING_PUMP_HEATER                1
#define AUTO_DECIDED                       2

#define HEATING_MODE_CONDITION             1
#define HEATING_MODE_TYPE                  UINT


/*Components*/
#define UPPER_COMPONENTS_TEMPERATURE_LIMIT UPPER_TEMPERATURE_LIMIT
#define LOWER_COMPONENTS_TEMPERATURE_LIMIT LOWER_TEMPERATURE_LIMIT

#define UPPER_COMPONENTS_ID_LIMIT          9999
#define LOWER_COMPONENTS_ID_LIMIT          0

#define MAX_IP_LENGTH                      16
#define NAME_LENGTH                        20

#define COMPONENTS_CONDITION               2
#define COMPONENTS_TEMPERATURE_TYPE        TEMPERATURE_TYPE
#define COMPONENTS_ID_TYPE                 UINT
#define COMPONENTS_IP_TYPE                 STRING
#define COMPONENTS_NAME_TYPE               STRING

#endif /* VARIABLE_LIMITS_H */