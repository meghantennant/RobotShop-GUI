#pragma once
#ifndef __ROBOTPART_H
#define __ROBOTPART_H 2016

#include <string>
using namespace std;

class RobotPart {
protected:
	string name;
	int partNumber;
	string componentType;
	double weight;
	double cost;
	string description;


public:
	RobotPart(string p_name, int p_partNumber, string p_componentType, double p_weight, double p_cost, string p_description)
		: name(p_name), partNumber(p_partNumber), componentType(p_componentType), weight(p_weight), cost(p_cost), description(p_description) {};

	virtual string get_name() = 0;
	virtual int get_part_number() = 0;
	virtual string get_comp_type() = 0;
	virtual double get_weight() = 0;
	virtual double get_cost() = 0;
	virtual string get_description() = 0;
	virtual void to_string() = 0;

	RobotPart *next;

};
#endif // __ROBOTPART_H
