//
//  LineTracer.hpp
//
//  Copyright © 2021 Ahiruchan Koubou. All rights reserved.
//

#ifndef LineTracer_hpp
#define LineTracer_hpp

#include "ahiru_common.hpp"
#include "Navigator.hpp"

class LineTracer : public Navigator {
private:
    int32_t motor_ang_l, motor_ang_r;
protected:
    bool    frozen;
    bool    cntl_p_flg;
public:
    LineTracer();
    LineTracer(Motor* lm, Motor* rm, Motor* tm);
    void haveControl();
    void operate(); // method to invoke from the cyclic handler
    int8_t getSpeed();
    void setSpeed(int8_t s);
    void freeze();
    void unfreeze();
    float calcPropP();
    void setCntlP(bool p);
    ~LineTracer();
};

#endif /* LineTracer_hpp */
