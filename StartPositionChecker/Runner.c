/****************************************************
 *  BalanceRunner.c                                         
 *  Created on: 2012/05/05 8:34:02                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "Runner.h"

#define LOW     30
#define NORMAL  50
#define HIGH    70
#define BATT  8000
#define Pai 3.14
#define daiamater 56
#define Around 360
#define pwm_r 70
#define pwm_l 70


static double Runner_calcDegree(Runner *this, double distance);
static long Runner_calcTurnDegree(Runner *this, long degree);



void Runner_init(Runner* this){
	while( TouchSensor_isPressed(this->touchSensor) == 0){
		this->black = LightSensor_getBrightness(this->lightSensor);

		display_clear(0);
		display_goto_xy(0, 1);
		display_string("Black=");
		display_int(this->black, 4);
		display_update();

		systick_wait_ms(100);
	}

	systick_wait_ms(1000);

	while( TouchSensor_isPressed(this->touchSensor) == 0 )
	{

		this->white=LightSensor_getBrightness(this->lightSensor);

		display_clear(0);
		display_goto_xy(0, 1);
		display_string("WHITE=");
		display_int(this->white, 4);
		display_update();

		systick_wait_ms(10);
	}

	systick_wait_ms(1000);

	this->gray=(this->black+this->white)/2;

	display_clear(0);
	display_goto_xy(0, 1);
	display_string("gray=");
	display_int(this->gray, 4);
	display_update();
	systick_wait_ms(1000);

}


void Runner_StraightRun(Runner* this, double distance)
{
	int turn;
	long motor_ang_l;
	long motor_ang_r;
	double degree;
	
	Motor_resetAngle(this->leftMotor);
	degree = Runner_calcDegree(this,distance);
			
	while( degree > Motor_getAngle(this->leftMotor) ){

		Motor_rotate(this->leftMotor, pwm_r);
		Motor_rotate(this->rightMotor, pwm_l);
	}
	Motor_rotate(this->leftMotor, 0);
	Motor_rotate(this->rightMotor, 0);
} 



void Runner_RotateRun(Runner *this, long degree){
	double ReturnDegree;
	ReturnDegree = Runner_calcTurnDegree(this, degree);

	while( ReturnDegree > Motor_getAngle(this->leftMotor)){
		Motor_rotate(this->leftMotor, pwm_r);
		Motor_rotate(this->rightMotor, pwm_l);
	}
	Motor_rotate(this->leftMotor, 0);
	Motor_rotate(this->rightMotor, 0);

}

//灰色ゲッター
int Runner_getGrayValue(Runner *this){
	return this->gray;
}

//private

static double Runner_calcDegree(Runner *this,double distance){
	double degree;

	degree = distance * Around / Pai / daiamater ;

	return degree;
}

//private 
static long Runner_calcTurnDegree(Runner *this,long degree){
	long ReturnDegree;
	long MotorsDis = 110;
	long arc = (long)(MotorsDis * Pai * degree / 360);
	ReturnDegree = Runner_calcDegree(this,arc);
	return ReturnDegree;

}

