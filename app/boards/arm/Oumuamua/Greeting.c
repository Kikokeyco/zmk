/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */



#include <device.h>
#include <drivers/display.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr.h>


static const struct device *display_dev;

void greeting(void)
{
	lv_obj_t *Oumuamua_label;


	display_dev = device_get_binding(CONFIG_LVGL_DISPLAY_DEV_NAME);

	if (display_dev == NULL) {
		return;
	}

	Oumuamua_label = lv_label_create(lv_scr_act(), NULL);

	lv_label_set_text(Oumuamua_label, "Oumuamua");
	lv_obj_align(Oumuamua_label, NULL, LV_ALIGN_CENTER, 0, 0);

	
	lv_task_handler();
	display_blanking_off(display_dev);
    k_sleep(K_MSEC(2000));
}

SYS_INIT(greeting, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);




