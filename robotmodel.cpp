#include <windows.h>
#include <iostream>
#include <string>
#include "robotmodel.h"
#include "robotpart.h"

using namespace std;


/*void RobotModel::set_price() //Goes through list of parts for model and adds up prices of each part.
{
	RobotPart *temp = first;
	price = 0;
	while (temp != NULL)
	{
		price += temp->get_cost();
		temp = temp->next;
	}
} */



double RobotModel::get_price() { return price; }

/*double RobotModel::get_weight()
{
	RobotPart *temp = first;
	double weight = 0;
	while (temp != NULL)
	{
		weight += temp->get_weight();
		temp = temp->next;
	}

	return weight;
} */

string RobotModel::to_string()
{
	return ("Name: " + name + "     Model Number: " + model_number + "      Head: " + head + "     Right Arm: " + right_arm +
		"     Left Arm: " + left_arm + "     Locomotor: " + locomotor + "     Torso: " + torso + "     Battery 1: " + battery1 +
		"      Battery 2: " + battery2 + "     Battery 3: " + battery3 + "        ");
}
