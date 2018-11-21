#pragma once
#include"ComplexNum.h"

class ControlComplexNum {
public:
	ComplexNum in();
	void out(ComplexNum a);
	ComplexNum sum(ComplexNum a, ComplexNum b);
	ComplexNum max(ComplexNum a, ComplexNum b);
	ComplexNum min(ComplexNum a, ComplexNum b);
};