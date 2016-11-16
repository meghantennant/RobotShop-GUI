#pragma once
#ifndef __ARM_H
#define __ARM_H 2016
#include "robotPart.h"


class Arm : public RobotPart {

public:
	Arm(string p_name, string p_partNumber, string p_componentType, double p_weight, double p_cost, string p_description)
		: RobotPart(p_name, p_partNumber, p_componentType, p_weight, p_cost, p_description)
	{
		isMade = true;
	};

	string get_name();
	string get_part_number();
	string get_comp_type();
	double get_weight();
	double get_cost();
	string get_description();
	bool check_made();
	void to_string();
	double power_consumed(double speed);
	Arm *next; // points to the next arm in the robot parts list

private:
	bool isMade = false;
};
#endif // __ARM_H
