/*#include <Windows.h>
#include "robotPart.h"
#include "locomotor.h"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <stdexcept>


using namespace std;
void create_locomotor();

int main()
{
	Fl_Window *win = new Fl_Window{ 640,340, "Robot Shop 2016" };

	create_locomotor();


	win->end();
	win->show();

	return (Fl::run());
}

void create_locomotor()
{
	string partName = "Robot Locomotor";
	int partNumberID = 00100;
	string partComponentType = "Locomotor";
	double partWeight = 50; //in pounds
	double partCost = 100; // in dollars
	string partDescription = "Small Robot Locomotor";
	double partMaxSpeed = 3; // in MPH

	Locomotor *lm = new Locomotor(partName, partNumberID, partComponentType, partWeight, partCost, partDescription, partMaxSpeed);
	
	if (lm->check_made())
	{
		Fl_Box *box = new Fl_Box{ 0,0, 340,170, "A locomotor was made!" };
	}
	else
	{
		throw runtime_error("Could not make a locomotor");
	}
} */