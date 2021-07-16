#ifndef __CONTROL_H
#define __CONTROL_H
#include <sys.h>

void Tracking(void);	//Ñ­¼£
void BACK_Track(int data);
void FRONT_Track(int data);
void RIGHT_Track(int data);
void LEFT_Track(int data);

void BACK_BZ(int data);
void FRONT_BZ(int data);
void RIGHT_BZ(int data);
void LEFT_BZ(int data);

void FRONT(int n);
void BACK(int n);
void LEFT(int n);
void RIGHT(int n);
void Move(int x,int y);


#endif

