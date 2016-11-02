/*#include <Windows.h>
#include "robotPart.h"
#include "head.h"
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include <stdexcept>

class Head;

using namespace std;
void create_head();

int main()
{
	Fl_Window *win = new Fl_Window{ 640,340, "Robot Shop 2016" };

	create_head();


	win->end();
	win->show();

	return (Fl::run());
}

void create_head()
{
	string partName = "Robot Head";
	int partNumberID = 10000;
	string partComponentType = "Head";
	double partWeight = 10; //in pounds
	double partCost = 20; // in dollars
	string partDescription = "Small Robot Head";
	string partStyle = "Small";

	Head *head = new Head(partName, partNumberID, partComponentType, partWeight, partCost, partDescription);

	if (head->check_made())
	{
		Fl_Box *box = new Fl_Box{ 0,0,340,170, "A Head was made!" };
	}
	else
	{
		throw runtime_error("Failed to make a head.");
	}
} */