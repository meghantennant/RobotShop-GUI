#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include "robotpart.h"
#include "torso.h"

using namespace std;

string Torso::get_name() { return name; }
int Torso::get_part_number() { return partNumber; }
string Torso::get_comp_type() { return componentType; }
double Torso::get_weight() { return weight; }
double Torso::get_cost() { return cost; }
string Torso::get_description() { return description; }
string Torso::get_style() { return style; }
int Torso::get_bat_compart() { return batteryCompartments; }
bool Torso::check_made() { return isMade; }
void Torso::to_string()
{
	cout << endl;
	cout << "Name: " << get_name() << endl;
	cout << "Part Number: " << get_part_number() << endl;
	cout << "Component Type: " << get_comp_type() << endl;
	cout << "Weight: " << get_weight() << endl;
	cout << "Cost: " << get_cost() << endl;
	cout << "Style: " << get_style() << endl;
	cout << "Battery Compartments: " << get_bat_compart() << endl;
	cout << "Description: " << get_description() << endl;
}
