//
//  BlindRunner.hpp
//
//  Copyright © 2021 Ahiruchan Koubou. All rights reserved.
//

#ifndef BlindRunner_hpp
#define BlindRunner_hpp
#include "ahiru_common.hpp"
#include "LineTracer.hpp"
#include <stdio.h>
#define PERIOD_SPEED_CHG 200 * 1000 // Trace message in every 200 ms
#define PROP_NAME_LEN	48	// プロパティー名の最大長
#define NUM_PROPS	13	// プロパティーの個数
struct courseSection {
	char	id[6];
	int32_t sectionEnd;
	double  curvature;
};
// section id starts with L for LineTracer deligaton
//                   with B for SPEED_BLIND
//                   with R to return to LineTracer 
// Note:
//  curve +625, 0.45 makes right angle
//        +650, 0.40
//        +795, 0.30
const struct courseSection courseMap[] = {
/*
	{"Lst00", 90755, 0.0},    // the st00 end point used to set d_cv01_midpoint below!!!
	{"Bcv01", 91270, 0.5334},
	{"Bcv01", 1821, 0.5333}, // the cv01 end point used to set d_cv01_midpoint below!!!
	{"Bst02", 2175, 0.0},
	{"Bcv03", 3361,-0.4793},
	{"Bst04", 3902, 0.0},
  	{"Bcv05", 4527,-0.45},
	{"Bst06", 5050, 0.0},
	{"Bcv07", 5676, 0.45},
	{"Bst08", 5951, 0.0},
	{"Bcv09", 6567, 0.45},
#if defined(MAKE_RIGHT)
	{"Bst10", 6885, 0.0},  //  6905
	{"Bcv11", 7660, 0.3},  //  7675
	{"Bst12", 9165, 0.0},  //  9070
	{"Bcv13", 9840,-0.33}, //  9745
	{"Rst14",10858, 0.0},  // 10763
	{"Lst14",10858, 0.0},  // 10763
#else
	{"Bst10", 6875, 0.0},  //  6905
	{"Bcv11", 7645, 0.3},  //  7675
	{"Bst12", 9040, 0.0},  //  9070
	{"Bcv13", 9715,-0.33}, //  9745
	{"Rst14",10733, 0.0},  // 10763
	{"Lst14",10733, 0.0},  // 10763
#endif
*/
	{"Bst00", 2050, 0.0},
	{"Bcv00", 2565, -0.5334},
	{"Bcv02", 3265, 0.0},
	{"Bcv03", 3980, -0.8},
	{"Bst04", 4285, 0.0},
	{"Bcv05", 4750, 0.5334},
	{"Bst06", 4910, 0.0},
	{"Bcv07", 5375, 0.5335},
	{"Bst08", 5535, 0.0},
	{"Bcv09", 6000, -0.5335},
	{"Bst10", 6008, 0.0},
	{"Bcv11", 6483, -0.5335},
	{"Bst12", 6493, 0.0},
	{"Bcv13", 7133, 0.927},
	{"Bst14", 7200, 0.0},
	{"Lst15", 9000, 0.0},
	{"Lcv16",DIST_end_blind,-0.247}

}; // Note: size of this array is given by sizeof(courseMap)/sizeof(*courseMap)
const char sBcv01[] = "Bcv01";
const int32_t d_cv01_midpoint = (755 + 1821) / 2; // <--- this has to agree with st00 and cv01 end points in the course map above!!!
class BlindRunner : public LineTracer {
private:
	int16_t s_trace_counter;
    Motor*	leftMotor;
    Motor*  rightMotor;
    Motor*	tailMotor;
	int		courseMapSize, currentSection, speedChgCnt;
	int32_t d_offset, d_cv01_line_lost, d_cv01_line_found;
	bool	stopping;
	struct property{
		char name[PROP_NAME_LEN];
		int value;
	};
	struct property props[NUM_PROPS];
	int readLine( FILE* file, char* dst, size_t len );
	void readPropFile( const char* filename );
	int getProp( const char* propname );
protected:
public:
    BlindRunner();
    BlindRunner(Motor* lm, Motor* rm, Motor* tm);
    void haveControl();
    void operate(); // method to invoke from the cyclic handler
    ~BlindRunner();
};
#endif /* BlindRunner_hpp */
