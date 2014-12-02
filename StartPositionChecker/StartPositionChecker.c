/*
 * StartPositionChecker.c
 *
 *  Created on: 2014/09/12
 *      Author: miyaji
 */

#include "StartPositionChecker.h"


void StartPositionChecker_sound(StartPositionChecker* this)
{	
	//タッチセンサが押されるまで、待ち続ける
	while(1){
		//灰色をゲット
		int gray = Runner_getGrayValue(this->runner);
		
		//取得灰色が、取得光量と同値のとき、音を鳴らす
		if( gray-50 <= LightSensor_getBrightness(this->lightSensor) && LightSensor_getBrightness(this->lightSensor) <= gray+50 ){

			ecrobot_sound_tone(950, 120, 70);
			systick_wait_ms(1200);
			display_goto_xy(0, 2);
			display_string("Good");
		}else{
			display_goto_xy(0, 2);
			display_string("Bad ");
			
		}
		display_update();

		if(ecrobot_is_ENTER_button_pressed() == 1))
			{
				break;		// タッチセンサが押された
			}

	}
}
