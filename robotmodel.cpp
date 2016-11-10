#include <windows.h>
#include <iostream>
#include <string>
#include "robotmodel.h"
#include "robotpart.h"

using namespace std;

void RobotModel::add_robotpart(RobotPart *rp) //Adds a Robot part to the linked list 'first'
{
	if (first == NULL) //check if list is empty
	{
		first = rp;
		rp->next = NULL;
	}
	else
	{
		RobotPart *temp = first;
		while (temp->next != NULL) // go to end of list
		{
			temp = temp->next;
		}
		temp->next = rp; //add robot part to list
		rp->next = NULL;
	}
}

void RobotModel::set_bat_compart(int num) //sets number of battery compartments for the model
{
	batCompartments = num;
}

int RobotModel::get_bat_compart()
{
	return batCompartments;
}
int RobotModel::get_model_number()
{
	return modelNumber;
}

void RobotModel::set_price() //Goes through list of parts for model and adds up prices of each part.
{
	RobotPart *temp = first;
	price = 0;
	while (temp != NULL)
	{
		price += temp->get_cost();
		temp = temp->next;
	}
}

string RobotModel::get_name()
{
	return name;
}

double RobotModel::get_price()
{
	return price;
}

double RobotModel::get_weight()
{
	RobotPart *temp = first;
	double weight = 0;
	while (temp != NULL)
	{
		weight += temp->get_weight();
		temp = temp->next;
	}

	return weight;
}

void RobotModel::to_string()
{
	cout << "Name: " << name << endl;
	cout << "Model Number: " << modelNumber << endl;
	cout << "Price: " << price << endl;
}
