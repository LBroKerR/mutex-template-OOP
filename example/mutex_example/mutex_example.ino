#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "float_mutex.h"

#include "Pim_var.h"

#include "project_limit.h"

bool change_var_value(Pim_var *var, void* value){
  if(var->enter_ExcusiveArea()){
    var->set(value);
    var->leave_ExcusiveArea();
    return true;
  }
  return false;
}
bool read_var_value(Pim_var *var, void* value){
  if(var->enter_ExcusiveArea()){
    var->get(value);
    var->leave_ExcusiveArea();
    return true;
  }
  return false;
}

void core1_task(void*parameters){
  Pim_var wtmp = *(Pim_var*)parameters;
  float tmp     =  5.0;
  while(true){
    change_var_value(&wtmp, (void*)&tmp);
    if(read_var_value(&wtmp,(void*)&tmp)){
      Serial.println("Core1:"+String(tmp,2));
    }
    delay(random(1000));
  }
}
void core0_task(void*parameters){
  Pim_var wtmp = *(Pim_var*)parameters;
  float tmp     =  10.0;
  while(true){
    tmp     =  10.0;
    change_var_value(&wtmp, (void*)&tmp);
    if(read_var_value(&wtmp,(void*)&tmp)){
      Serial.println("Core0_1:"+String(tmp,2));
    }
    tmp     =  13.0;
    delay(random(500));
    change_var_value(&wtmp, (void*)&tmp);
    if(read_var_value(&wtmp,(void*)&tmp)){
      Serial.println("Core0_2:"+String(tmp,2));
    }
    delay(random(100));
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  float tmp=0.0;
  TaskHandle_t core1, core0;
  Pim_var wtmp(new float_mutex);
  wtmp.set((void*)&tmp);
  xTaskCreatePinnedToCore(core1_task, "core1", 100, &wtmp, 5, &core1, 1);
  xTaskCreatePinnedToCore(core0_task, "core0", 100, &wtmp, 5, &core0, 0);

}
void loop() {
  // put your main code here, to run repeatedly:

}
