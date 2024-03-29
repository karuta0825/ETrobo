/*
 * StartpositionChecker.h
 *
 *  Created on: 2014/09/12
 *      Author: miyaji
 */

#ifndef STARTPOSITIONCHECKER_H_
#define STARTPOSITIONCHECKER_H_

#include "ecrobot_interface.h"
#include "kernel.h"

#include "LightSensor.h"
#include "Runner.h"

// 属性を保持するための構造体の定義
typedef struct StartPositionChecker
{
	LightSensor *lightSensor;
	Runner *runner;
	TouchSensor *touchSensor;
} StartPositionChecker;

// 公開操作
void StartPositionChecker_sound(StartPositionChecker* this);


#endif /* STARTPOSITIONCHECKER_H_ */
