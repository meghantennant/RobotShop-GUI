#include <Windows.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Round_Button.H>
#include <string>
#include <iostream>
#include "view.h"
#include "head.h"
#include "arm.h"
#include "locomotor.h"
#include "torso.h"
#include "battery.h"

using namespace std;

//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;

//
// Callbacks
//

void CloseCB(Fl_Widget *w, void *p)
{
	int selection = 1;
	if (!view->saved())
	{
		selection = fl_choice("Program not saved. Exit anyways?", fl_no, fl_yes, 0);
	}
	if (selection == 1)
	{
		win->hide();
	}
}

void HeadCB(Fl_Widget *w, void *p)
{
	string name = string{ fl_input("Enter Name: ",0) };
	const char * num = fl_input("Enter part number: ", 0);
	int pnum;
	if (isdigit(*num))
	{
		pnum = atoi(num);
	}
	else
	{
		throw runtime_error("Cannot convert part number to integer");
	}
	const char *wt = fl_input("Enter weight: ", 0);
	double weight;
	if (isdigit(*wt))
	{
		weight = atof(wt);
	}
	else
	{
		throw runtime_error("Cannot convert weight to double");
	}
	const char *ct = fl_input("Enter cost: ", 0);
	double cost;
	if (isdigit(*ct))
	{
		cost = atof(ct);
	}
	else
	{
		throw runtime_error("Cannot convert cost to double");
	}
	string description = string{ fl_input("Enter description: ") };

	Head *head = new Head(name, pnum, "Head", weight, cost, description);

}

void ArmCB(Fl_Widget *w, void *p)
{
	string name = string{ fl_input("Enter Name: ",0) };
	const char * num = fl_input("Enter part number: ", 0);
	int pnum;
	if (isdigit(*num))
	{
		pnum = atoi(num);
	}
	else
	{
		throw runtime_error("Cannot convert part number to integer");
	}
	const char *wt = fl_input("Enter weight: ", 0);
	double weight;
	if (isdigit(*wt))
	{
		weight = atof(wt);
	}
	else
	{
		throw runtime_error("Cannot convert weight to double");
	}
	const char *ct = fl_input("Enter cost: ", 0);
	double cost;
	if (isdigit(*ct))
	{
		cost = atof(ct);
	}
	else
	{
		throw runtime_error("Cannot convert cost to double");
	}
	string description = string{ fl_input("Enter description: ") };

	Arm *arm = new Arm(name, pnum, "Arm", weight, cost, description);
}

void LocomotorCB(Fl_Widget *w, void *p)
{
	string name = string{ fl_input("Enter Name: ",0) };
	const char * num = fl_input("Enter part number: ", 0);
	int pnum;
	if (isdigit(*num))
	{
		pnum = atoi(num);
	}
	else
	{
		throw runtime_error("Cannot convert part number to integer");
	}
	const char *wt = fl_input("Enter weight: ", 0);
	double weight;
	if (isdigit(*wt))
	{
		weight = atof(wt);
	}
	else
	{
		throw runtime_error("Cannot convert weight to double");
	}
	const char *ct = fl_input("Enter cost: ", 0);
	double cost;
	if (isdigit(*ct))
	{
		cost = atof(ct);
	}
	else
	{
		throw runtime_error("Cannot convert cost to double");
	}
	string description = string{ fl_input("Enter description: ") };
	const char *spd = fl_input("Enter max speed: ", 0);
	double speed;
	if (isdigit(*spd))
	{
		speed = atof(spd);
	}

	Locomotor *loco = new Locomotor(name, pnum, "Locomotor", weight, cost, description, speed);
}

void TorsoCB(Fl_Widget *w, void *p)
{
	string name = string{ fl_input("Enter Name: ",0) };
	const char * num = fl_input("Enter part number: ", 0);
	int pnum;
	if (isdigit(*num))
	{
		pnum = atoi(num);
	}
	else
	{
		throw runtime_error("Cannot convert part number to integer");
	}
	const char *wt = fl_input("Enter weight: ", 0);
	double weight;
	if (isdigit(*wt))
	{
		weight = atof(wt);
	}
	else
	{
		throw runtime_error("Cannot convert weight to double");
	}
	const char *ct = fl_input("Enter cost: ", 0);
	double cost;
	if (isdigit(*ct))
	{
		cost = atof(ct);
	}
	else
	{
		throw runtime_error("Cannot convert cost to double");
	}
	string description = string{ fl_input("Enter description: ") };

	const char *bc = fl_input("Enter number of battery compartments: ");
	int batcom;
	if (isdigit(*bc))
	{
		batcom = atoi(bc);
	}
	else
	{
		throw runtime_error("Cannot convert number of battery compartments to integer.");
	}

	Torso *torso = new Torso(name, pnum, "Torso", weight, cost, description, batcom);

}

void BatteryCB(Fl_Widget *w, void *p)
{
	string name = string{ fl_input("Enter Name: ",0) };
	const char * num = fl_input("Enter part number: ", 0);
	int pnum;
	if (isdigit(*num))
	{
		pnum = atoi(num);
	}
	else
	{
		throw runtime_error("Cannot convert part number to integer");
	}
	const char *wt = fl_input("Enter weight: ", 0);
	double weight;
	if (isdigit(*wt))
	{
		weight = atof(wt);
	}
	else
	{
		throw runtime_error("Cannot convert weight to double");
	}
	const char *ct = fl_input("Enter cost: ", 0);
	double cost;
	if (isdigit(*ct))
	{
		cost = atof(ct);
	}
	else
	{
		throw runtime_error("Cannot convert cost to double");
	}
	string description = string{ fl_input("Enter description: ") };

	const char *pow = fl_input("Enter power: ", 0);
	double power;
	if (isdigit(*pow))
	{
		power = atof(pow);
	}
	else
	{
		throw runtime_error("Cannot convert power to double");
	}
	const char *eny = fl_input("Enter energy: ", 0);
	double energy;
	if (isdigit(*eny))
	{
		energy = atof(eny);
	}
	else
	{
		throw runtime_error("Cannot convert energy to double");
	}

	Battery *bat = new Battery(name, pnum, "Battery", weight, cost, description, power, energy);
}

//
//Menu
//

Fl_Menu_Item menuitems[] = {
	{"&File", 0, 0, 0, FL_SUBMENU},
		{"&Quit", FL_ALT + 'q', (Fl_Callback *)CloseCB},
		{0},
	{"&Create", 0, 0, 0, FL_SUBMENU},
		{"&Robot Part",0,0,0,FL_SUBMENU},
			{"&Head",0,(Fl_Callback *)HeadCB},
			{"&Arm", 0,(Fl_Callback *)ArmCB},
			{"&Locomotor",0,(Fl_Callback *)LocomotorCB},
			{"&Tosro",0,(Fl_Callback *)TorsoCB},
			{"&Battery",0,(Fl_Callback *)BatteryCB},
		{0},
	{0}

};

//
// Main
//

int main() {
	//Set window length and height
	const int X = 640;
	const int Y = 480;

	//Create a window
	win = new Fl_Window{ X,Y,"Robot Shop 2016" };

	//Create MenuBar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);

	//Create a view
	view = new View{ 0,0,X,Y };

	//Callbacks
	win->callback(CloseCB, view);

	//Make it resizable
	win->resizable(*view);

	//Let FLTK work
	win->end();
	win->show();

	return (Fl::run());




}
