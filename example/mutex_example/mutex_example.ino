#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "float_mutex.h"

#include "Pim_var.h"

#include "project_limit.h"

void core1_task(void*parameters){
  Pim_var wtmp= *(Pim_var*)parameters;
  float tmp=5.0;
  while(true){
    if(wtmp.enter_ExcusiveArea()){
        wtmp.set((void*)&tmp);// ? Serial.println("core1 task: set done") : Serial.println("core1 task: set falied");
        wtmp.leave_ExcusiveArea();
    }
    //vTaskDelay(10 / portTICK_PERIOD_MS);
    delay(random(1000));
  }
}
void core0_task(void*parameters){
  Pim_var wtmp= *(Pim_var*)parameters;
  float tmp=10.0;
  while(true){
    
    if(wtmp.enter_ExcusiveArea()){
      wtmp.set((void*)&tmp);// ? Serial.println("core0 task: set done") : Serial.println("core0 task: set falied");
      wtmp.leave_ExcusiveArea();
    }
    //vTaskDelay(100 / portTICK_PERIOD_MS);
    delay(random(1000));
    if(wtmp.enter_ExcusiveArea()){
      wtmp.enter_ExcusiveArea();
      wtmp.get(&tmp);// ? Serial.println("core0 task: get done") : Serial.println("core0 task: get falied");
      wtmp.leave_ExcusiveArea();
      }
   // Serial.println(tmp);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  float tmp=0.0;
  TaskHandle_t core1, core0;
  Pim_var wtmp(new float_mutex);
  wtmp.set((void*)&tmp);
  xTaskCreatePinnedToCore(core1_task, "core1", 1000, &wtmp, 5, &core1, 1);
  xTaskCreatePinnedToCore(core0_task, "core0", 1000, &wtmp, 5, &core0, 0);

  //Serial.begin(115200);

}
void loop() {
  // put your main code here, to run repeatedly:

}
