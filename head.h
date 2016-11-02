#pragma once
#ifndef __HEAD_H
#define __HEAD_H 2016
#include "robotPart.h"
#include <string>

using namespace std;

class Head : public RobotPart {
public:
	Head(string p_name, int p_partNumber, string p_componentType, double p_weight, double p_cost, string p_description)
		: RobotPart(p_name, p_partNumber, p_componentType, p_weight, p_cost, p_description)
	{
		isMade = true;
	};


	string get_name();
	int get_part_number();
	string get_comp_type();
	double get_weight();
	double get_cost();
	string get_description();
	bool check_made();
	void to_string();

private:
	bool isMade = false;
};

#endif

