//
//  LineFinder.cpp
//
//  Copyright © 2021 Ahiruchan Koubou. All rights reserved.
//

#include "app.h"
#include "LineFinder.hpp"
#include "Observer.hpp"

LineFinder::LineFinder(Motor* lm, Motor* rm, Motor* tm) {
    _debug(syslog(LOG_NOTICE, "%08u, LineFinder constructor", clock->now()));
    leftMotor   = lm;
    rightMotor  = rm;
    speed       = SPEED_SLOW;
	turn        = 0;

	turnCount   = 100;
}

void LineFinder::haveControl() {
    activeNavigator = this;
    syslog(LOG_NOTICE, "%08u, LineFinder has control", clock->now());
}

void LineFinder::operate() {
	if ( turnCount > 0 ) {
		forward = speed;
		turn = -10;
		--turnCount;
	} else if ( turnCount == 0 ) {
		if ( g_grayScale < 60 ) {
			turnCount = -1;
		} else {
			forward = speed;
			turn = 0;
		}
	} else if ( g_grayScale < 60 ) {
		forward = speed;
		turn = 25;
	} else {
		forward = speed;
		turn = -25;
	}

    pwm_L = forward - turn;
    pwm_R = forward + turn;

    leftMotor->setPWM(pwm_L);
    rightMotor->setPWM(pwm_R);
}

LineFinder::~LineFinder() {
    _debug(syslog(LOG_NOTICE, "%08u, LineFinder destructor", clock->now()));
}
