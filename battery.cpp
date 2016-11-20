#include <windows.h>
#include <iostream>
#include <string>
#include "robotpart.h"
#include "battery.h"

using namespace std;

string Battery::get_name() { return name; }
string Battery::get_part_number() { return partNumber; }
string Battery::get_comp_type() { return componentType; }
double Battery::get_weight() { return weight; }
double Battery::get_cost() { return cost; }
string Battery::get_description() { return description; }
double Battery::get_energy() { return energy; }
double Battery::get_max_power() { return maxPower; }
bool Battery::check_made() { return isMade; }
void Battery::to_string()
{
	cout << endl;
	cout << "Name: " << get_name() << endl;
	cout << "Part Number: " << get_part_number() << endl;
	cout << "Component Type: " << get_comp_type() << endl;
	cout << "Weight: " << get_weight() << endl;
	cout << "Cost: " << get_cost() << endl;
	cout << "Energy: " << get_energy() << endl;
	cout << "Max Power: " << get_max_power() << endl;
	cout << "Description: " << get_description() << endl;
}
