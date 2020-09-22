#include "output_handler.h"

#include "LCD_DISCO_F769NI.h"
#include "constants.h"
#include <stdio.h>
#include "mbed.h"


// The LCD driver
LCD_DISCO_F769NI lcd;

const int dot_radius = 10;
bool initialized = false;
int width;
int height;
int midpoint;
int x_increment;
int y_weight;

void HandleOutput(tflite::ErrorReporter* error_reporter, float x_value, float y_value) { 
  if (!initialized) {
    lcd.Clear(LCD_COLOR_BLUE);
    lcd.SetBackColor(LCD_COLOR_BLUE);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    width = lcd.GetXSize();
    height = lcd.GetYSize();
    midpoint = height / 2;
    x_increment = static_cast<float>(width - dot_radius) / kXrange;
    y_weight = static_cast<float>(midpoint/2);
    initialized = true;
  }

  lcd.Clear(LCD_COLOR_BLUE);
  //lcd.DisplayStringAt(0, LINE(1), (uint8_t *)"Hello EML World", CENTER_MODE);

  int x_pos = dot_radius + static_cast<int>(x_value * x_increment);
  int y_pos = midpoint + static_cast<int>(y_value * y_weight) ;  
  //TF_LITE_REPORT_ERROR(error_reporter, "width: %d - height: %d - midpoint: %d - x_pos: %d - y_pos: %d\n", width, height, midpoint, x_pos, y_pos);
  
  lcd.FillCircle(x_pos, y_pos, dot_radius);
}