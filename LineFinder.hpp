//
//  LineFinder.hpp
//
//  Copyright © 2021 Ahiruchan Koubou. All rights reserved.
//

#ifndef LineFinder_hpp
#define LineFinder_hpp

#include "ahiru_common.hpp"
#include "Navigator.hpp"

class LineFinder : public Navigator {
private:
	int turnCount;
protected:
public:
    LineFinder(Motor* lm, Motor* rm, Motor* tm);
    void haveControl();
    void operate(); // method to invoke from the cyclic handler
    ~LineFinder();
};

#endif /* LineFinder_hpp */
