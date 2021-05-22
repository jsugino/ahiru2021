//
//  Navigator.hpp
//
//  Copyright © 2021 Ahiruchan Koubou. All rights reserved.
//

#ifndef Navigator_hpp
#define Navigator_hpp

#include "ahiru_common.hpp"
#include "utility.hpp"

class Navigator {
private:
protected:
    int8_t forward;      /* 前後進命令 */
    int8_t turn;         /* 旋回命令 */
    int8_t pwm_L, pwm_R; /* 左右モータPWM出力 */
    int8_t speed;
    int16_t         trace_pwmLR;
    Motor*          leftMotor;
    Motor*          rightMotor;
    PIDcalculator*  ltPid;
public:
    Navigator();
    void activate();
    virtual void haveControl() = 0;
    virtual void operate() = 0;
    void deactivate();
    virtual ~Navigator();
};

extern Navigator*   activeNavigator;

#endif /* Navigator_hpp */
