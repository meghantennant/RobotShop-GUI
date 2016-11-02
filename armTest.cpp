/*#include <Windows.h>
#include "robotPart.h"
#include "arm.h"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <stdexcept>


using namespace std;
void create_arm();

int main()
{
	Fl_Window *win = new Fl_Window{ 640,340, "Robot Shop 2016" };

	create_arm();


	win->end();
	win->show();

	return (Fl::run());
}

void create_arm()
{
	string partName = "Robot Arm";
	int partNumberID = 01000;
	string partComponentType = "Arm";
	double partWeight = 2; //in pounds
	double partCost = 10; // in dollars
	string partDescription = "Small Robot Arm";
	

	Arm *arm = new Arm(partName, partNumberID, partComponentType, partWeight, partCost, partDescription);
	
	if (arm->check_made())
	{
		Fl_Box *box = new Fl_Box(0, 0, 340, 170, "An arm was made!");
	}
	else
	{
		throw runtime_error("Cannot make an arm");
	}
} */