///////////////////////////////////////////////////////////
//  main.c
///////////////////////////////////////////////////////////

#include "UI.h"
#include "Runner.h"
#include "TouchSensor.h"
#include "Motor.h"
#include "StartPositionChecker.h"

#include "kernel.h"
#include "kernel_id.h"
#include "ecrobot_interface.h"



Runner 	runner;
UI ui;
TouchSensor 	touchSensor;
Motor leftMotor, rightMotor;
LightSensor lightSensor;
StartPositionChecker startPositionChecker;


void ecrobot_device_initialize()
{

	ecrobot_set_light_sensor_active(NXT_PORT_S1);
	if(ecrobot_get_bt_status()==BT_NO_INIT){
		ecrobot_set_bt_device_name("NXT");
	}
	ecrobot_init_bt_slave("1234");

}


void ecrobot_device_terminate()
{

	ecrobot_set_light_sensor_inactive(NXT_PORT_S4);
	ecrobot_term_bt_connection();
}

// 1msec
void user_1ms_isr_type2(void)
{
}

TASK(TaskMain)
{


	/* send Sensor/Motors/NXT internal status to the host.
	 * NXT GamePad in the host PC accumulates all logging data
	 * and later you can save the logging data into a CSV file
	 */


	/* display Sensors/Motors/NXT internal status */



	ui.touchSensor		   = &touchSensor;
	ui.startPositionChecker = &startPositionChecker;
	runner.leftMotor    = &leftMotor;
	runner.rightMotor   = &rightMotor;
	runner.lightSensor = &lightSensor;
	runner.touchSensor = &touchSensor;
	startPositionChecker.lightSensor = &lightSensor;
	startPositionChecker.touchSensor = &touchSensor;
	startPositionChecker.runner = &runner;


	UI_init(&ui);
	TouchSensor_init(&touchSensor, NXT_PORT_S4);
	LightSensor_init(&lightSensor, NXT_PORT_S1);
	Motor_init(&leftMotor, NXT_PORT_C);
	Motor_init(&rightMotor, NXT_PORT_B);
	Runner_init(&runner);



	UI_waitStart(&ui);
	ecrobot_device_terminate();


}

