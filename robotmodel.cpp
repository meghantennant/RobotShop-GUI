#include <windows.h>
#include <sstream>
#include <string>
#include "shop.h"
#include "robotmodel.h"
#include "head.h"

using namespace std;


void RobotModel::set_price(double model_cost) { price = model_cost; } 
void RobotModel::set_weight(double model_weight) { weight = model_weight; }
double RobotModel::get_price() { return price; }
double RobotModel::get_weight() { return weight; }

string RobotModel::to_string()
{
	ostringstream ss;
	ss << price;
	string m_price = ss.str();

	return ("Name: " + name + "     Model Number: " + model_number + "      Head: " + head + "     Right Arm: " + right_arm +
		"     Left Arm: " + left_arm + "     Locomotor: " + locomotor + "     Torso: " + torso + "     Battery 1: " + battery1 +
		"      Battery 2: " + battery2 + "     Battery 3: " + battery3 + "     Price: $" + m_price);
}
