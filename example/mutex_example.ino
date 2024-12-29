#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "float_mutex.h"

float_mutex wtmp;

void core1_task(void*parameters){
  while(true){
    wtmp.set_variable(5.0);// ? Serial.println("core1 task: set done") : Serial.println("core1 task: set falied");
    //vTaskDelay(10 / portTICK_PERIOD_MS);
    delay(random(1000));
  }
}
void core0_task(void*parameters){
  float tmp=0.0;
  while(true){
    wtmp.set_variable(10.0);// ? Serial.println("core0 task: set done") : Serial.println("core0 task: set falied");
    //vTaskDelay(100 / portTICK_PERIOD_MS);
    delay(random(1000));
    wtmp.get_variable(&tmp);// ? Serial.println("core0 task: get done") : Serial.println("core0 task: get falied");
   // Serial.println(tmp);
  }
}

void setup() {
  // put your setup code here, to run once:
  TaskHandle_t core1, core0;
  xTaskCreatePinnedToCore(core1_task, "core1", 1000, nullptr, 5, &core1, 1);
  xTaskCreatePinnedToCore(core0_task, "core0", 1000, nullptr, 5, &core0, 0);

  //Serial.begin(115200);

}
void loop() {
  // put your main code here, to run repeatedly:

}
