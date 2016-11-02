#include <Windows.h>
#include "head.h"
#include <iostream>
#include <string>

using namespace std;

string Head::get_name() { return name; }
int Head::get_part_number() { return partNumber; }
string Head::get_comp_type() { return componentType; }
double Head::get_weight() { return weight; }
double Head::get_cost() { return cost; }
string Head::get_description() { return description; }
bool Head::check_made() { return isMade; }
void Head::to_string()
{
	cout << endl;
	cout << "Name: " << get_name() << endl;
	cout << "Part Number: " << get_part_number() << endl;
	cout << "Component Type: " << get_comp_type() << endl;
	cout << "Weight: " << get_weight() << endl;
	cout << "Cost: " << get_cost() << endl;
	cout << "Description: " << get_description() << endl;
}
