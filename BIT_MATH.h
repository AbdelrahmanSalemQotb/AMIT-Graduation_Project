#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNUM) 		VAR|=(1<<BITNUM)
#define CLR_BIT(VAR,BITNUM) 		VAR&=(~(1<<BITNUM))
#define TOGGLE_BIT(VAR,BITNUM)		VAR^=(1<<BITNUM)
#define GET_BIT(VAR,BITNUM) 		((VAR>>BITNUM)&1)

#endif
