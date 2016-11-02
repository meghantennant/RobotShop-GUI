/*#include <Windows.h>
#include "robotPart.h"
#include "battery.h"
#include "torso.h"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <stdexcept>


using namespace std;
void create_torso();

int main()
{
	Fl_Window *win = new Fl_Window{ 640,340, "Robot Shop 2016" };

	create_torso();


	win->end();
	win->show();

	return (Fl::run());
}

void create_torso()
{
	string partName = "Robot Torso";
	int partNumberID = 00001;
	string partComponentType = "Torso";
	double partWeight = 50; //in pounds
	double partCost = 100; // in dollars
	string partDescription = "Small Robot Torso";
	int num_bats = 2;

	Torso *torso = new Torso(partName, partNumberID, partComponentType, partWeight, partCost, partDescription, num_bats);
	if (torso->check_made())
	{
		Fl_Box *box = new Fl_Box{ 0,0,340,170,"A torso was created!" };
	}
	else
	{
		throw runtime_error("Could not make a torso.");
	}
} */
