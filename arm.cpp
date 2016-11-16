#include <windows.h>
#include <iostream>
#include <string>
#include "robotpart.h"
#include "arm.h"

using namespace std;

string Arm::get_name() { return name; }
string Arm::get_part_number() { return partNumber; }
string Arm::get_comp_type() { return componentType; }
double Arm::get_weight() { return weight; }
double Arm::get_cost() { return cost; }
string Arm::get_description() { return description; }
bool Arm::check_made() { return isMade; }
void Arm::to_string()
{
	cout << endl;
	cout << "Name: " << get_name() << endl;
	cout << "Part Number: " << get_part_number() << endl;
	cout << "Component Type: " << get_comp_type() << endl;
	cout << "Weight: " << get_weight() << endl;
	cout << "Cost: " << get_cost() << endl;
	cout << "Description: " << get_description() << endl;
}

double Arm::power_consumed(double speed)
{
	double power = (get_weight()*4.4) * speed; //convert pounds to Newtons to get Watts
	return power; // in Watts
}