/****************************************************
 *  UI.c                                         
 *  Created on: 2012/05/05 8:28:46                      
 *  Implementation of the Class UI       
 *  Original author: hiroyuki.watanabe                     
 ****************************************************/

#include "UI.h"


void UI_init(UI* this)
{
	// �������Ȃ�
}

void UI_waitStart(UI* this)
{
	//��ʒu����
	StartPositionChecker_sound(this->startPositionChecker);
	// �^�b�`�Z���T���������܂ŁA�҂�������
	while(1)
	{
		if(TouchSensor_isPressed(this->touchSensor))
		{
			break;		// �^�b�`�Z���T�������ꂽ
		}
	}
} 


