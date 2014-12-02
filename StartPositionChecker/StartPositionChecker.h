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

// ‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct StartPositionChecker
{
	LightSensor *lightSensor;
	Runner *runner;
	TouchSensor *touchSensor;
} StartPositionChecker;

// ŒöŠJ‘€ì
void StartPositionChecker_sound(StartPositionChecker* this);


#endif /* STARTPOSITIONCHECKER_H_ */
