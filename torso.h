#pragma once
#ifndef __TORSO1_H
#define __TORSO1_H 2016
#include "battery.h"

class Torso : public RobotPart {
public:
	Torso(string p_name, string p_partNumber, string p_componentType, double p_weight, double p_cost, string p_description)
		: RobotPart(p_name, p_partNumber, p_componentType, p_weight, p_cost, p_description)
	{
		isMade = true;
	};

	string get_name();
	string get_part_number();
	string get_comp_type();
	double get_weight();
	double get_cost();
	string get_style();
	string get_description();
	void to_string();
	bool check_made();
	Torso *next; // points to the next torso in the robot parts list

private:
	bool isMade = false;
};
#endif // __TORSO_H
