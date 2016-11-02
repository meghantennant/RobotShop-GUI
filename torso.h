#pragma once
#ifndef __TORSO1_H
#define __TORSO1_H 2016
#include "battery.h"

class Torso : public RobotPart {
public:
	Torso(string p_name, int p_partNumber, string p_componentType, double p_weight, double p_cost, string p_description, int p_batteryCompartments)
		: RobotPart(p_name, p_partNumber, p_componentType, p_weight, p_cost, p_description)
	{
		batteryCompartments = p_batteryCompartments;
		isMade = true;
	};

	string get_name();
	int get_part_number();
	string get_comp_type();
	double get_weight();
	double get_cost();
	string get_style();
	string get_description();
	int get_bat_compart();
	void to_string();
	bool check_made();

protected:
	int batteryCompartments;
	bool isMade = false;
	string style;
};
#endif // __TORSO_H
