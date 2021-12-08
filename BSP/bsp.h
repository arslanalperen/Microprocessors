#ifndef BSP_H_
#define BSP_H_

void BSP_init();

void delay(volatile unsigned int);

void BSP_led_init();
void BSP_led_set();
void BSP_led_reset();
void BSP_led_toggle();

void BSP_button_init();
int BSP_button_read();

void init_timer1();

void BSP_SetSSD(char pin);

#endif /* BSP_H_ */
