#pragma once
#ifndef __BATTERY_H
#define __BATTERY_H 2016
#include "robotPart.h"

class Battery : public RobotPart {
public:
	Battery(string p_name, int p_partNumber, string p_componentType, double p_weight, double p_cost, string p_description, double p_power, double p_energy)
		: RobotPart(p_name, p_partNumber, p_componentType, p_weight, p_cost, p_description)
	{
		energy = p_energy;
		maxPower = p_power;
		isMade = true;
	};
	string get_name();
	int get_part_number();
	string get_comp_type();
	double get_weight();
	double get_cost();
	string get_description();
	double get_max_power();
	double get_energy();
	bool check_made();
	void to_string();

private:
	double energy;
	double maxPower;
	bool isMade = false;
};
#endif // __BATTERY_H

