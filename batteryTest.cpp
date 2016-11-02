/*#include <Windows.h>
#include "robotPart.h"
#include "battery.h"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <stdexcept>


using namespace std;
void create_battery();

int main()
{
	Fl_Window *win = new Fl_Window{ 640,340, "Robot Shop 2016" };

	create_battery();


	win->end();
	win->show();

	return (Fl::run());
}

void create_battery()
{
	string partName = "Robot Battery";
	int partNumberID = 00010;
	string partComponentType = "Battery";
	double partWeight = 5; //in pounds
	double partCost = 119.99; // in dollars
	string partDescription = "Small Robot Battery";
	double partEnergy = 110; // in kWh
	double partMaxPower = 3; // in W

	Battery *bat = new Battery(partName, partNumberID, partComponentType, partWeight, partCost, partDescription, partMaxPower, partEnergy);
	if (bat->check_made())
	{
		Fl_Box *box = new Fl_Box{ 0,0,340,170,"A battery was made!" };
	}
	else
	{
		throw runtime_error("Could not make a battery!");
	}
} */