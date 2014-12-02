/****************************************************
 *  Runner.h                                         
 *  Created on: 2012/05/05 8:34:02                      
 *  Implementation of the Class BalanceRunner       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#if !defined(EA_37548F8E_C7BF_4044_9E50_5C184B895EEE__INCLUDED_)
#define EA_37548F8E_C7BF_4044_9E50_5C184B895EEE__INCLUDED_


#include "ecrobot_interface.h"
#include "kernel.h"

#include "Motor.h"
#include "LightSensor.h"
#include "TouchSensor.h"


// 螻樊�ｧ繧剃ｿ晄戟縺吶ｋ縺溘ａ縺ｮ讒矩��菴薙�ｮ螳夂ｾｩ
typedef struct Runner
{
	int black,white, gray;
	Motor *leftMotor;
	Motor *rightMotor;
	LightSensor *lightSensor;
	TouchSensor *touchSensor;
} Runner;

// 蜈ｬ髢区桃菴�
void Runner_init(Runner* this);
void Runner_StraightRun(Runner* this, double distance);
void Runner_RotateRun(Runner *this, long degree);
int Runner_getGrayValue(Runner *this);

#endif /*!defined(EA_37548F8E_C7BF_4044_9E50_5C184B895EEE__INCLUDED_)*/

