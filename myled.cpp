#include <Windows.h>
#include <stdio.h>
#include <math.h>
#include <charconv>
#include "vsm.hpp"
using namespace std;

class MYLED : public IACTIVEMODEL
{
	virtual VOID initialize(ICOMPONENT* cpt) ;
	virtual ISPICEMODEL* getspicemodel(CHAR* primitive) ;
	virtual IDSIMMODEL* getdsimmodel(CHAR* primitive) ;
	virtual VOID plot(ACTIVESTATE state) ;
	virtual VOID animate(INT element, ACTIVEDATA* newstate) ;
	virtual BOOL actuate(WORD key, INT x, INT y, DWORD flags) ;
private:
	ICOMPONENT* component;
};

extern "C" __declspec(dllexport) IACTIVEMODEL *createactivemodel (CHAR *device, ILICENCESERVER *ils)
{
	return new MYLED;
}
extern "C" VOID __declspec(dllexport) deleteactivemodel (IACTIVEMODEL *model)
{
	delete (MYLED *)model;
}

//Methods implemetation
VOID MYLED::initialize(ICOMPONENT* cpt) 
{
	component = cpt;
};

ISPICEMODEL *MYLED::getspicemodel(CHAR* primitive) { return NULL; };
IDSIMMODEL *MYLED::getdsimmodel(CHAR* primitive) { return NULL; };
VOID MYLED::plot(ACTIVESTATE state) {};

VOID MYLED::animate(INT element, ACTIVEDATA* newstate) 
{
	component->repaint(false);
	const char* caption = "This is a LED LED";
	component->drawtext(1, 1, 0, 2, (char *)caption);
};


BOOL MYLED::actuate(WORD key, INT x, INT y, DWORD flags) { return false; };
