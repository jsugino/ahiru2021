//
//  StateMachine.hpp
//
//  Copyright © 2021 Ahiruchan Koubou. All rights reserved.
//

#ifndef StateMachine_hpp
#define StateMachine_hpp

#include "ahiru_common.hpp"
#include "LineFinder.hpp"
#include "BlindRunner.hpp"
#include "ChallengeRunner.hpp"

/* LCDフォントサイズ */
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6/*TODO: magic number*/)
#define CALIB_FONT_HEIGHT (8/*TODO: magic number*/)

class StateMachine {
private:
    TouchSensor*    touchSensor;
    SonarSensor*    sonarSensor;
    ColorSensor*    colorSensor;
    GyroSensor*     gyroSensor;
    Motor*          leftMotor;
    Motor*          rightMotor;
    Motor*          tailMotor;
    Motor*          armMotor;
    Steering*       steering;
    LineFinder*     lineFinder;
    LineTracer*     lineTracer;
    BlindRunner*    blindRunner;
    ChallengeRunner*    challengeRunner;
protected:
public:
    StateMachine();
    void initialize();
    void sendTrigger(uint8_t event);
    void wakeupMain();
    void exit();
    ~StateMachine();
};

extern StateMachine* stateMachine;

#endif /* StateMachine_hpp */
