/*#include <windows.h>
#include<FL/Fl.H>
#include <FL/Fl_Window.H>
#include<FL/fl_ask.H>
#include <iostream>
#include <stdio.h>
#include <string>
#include "robotmodel.h"
#include "shop.h"

using namespace std;

Fl_Window *w;
Shop shop;

int main() {

	w = new Fl_Window(680, 440, "Robot Model Test");

	string name = "Robot Model";
	int modelNumber = 1;
	RobotModel *rm = new RobotModel(name, modelNumber);


		if (rm->get_model_number() == modelNumber)
		{
			if (rm->get_name() == "Robot Model")
			{
				fl_message("Passed!");
			}
			else
			{
				fl_message("Failed: Model name did not match!");
			}
		}
		else
		{
			fl_message("Failed: Robot Model number did not match.");
		}

		w->end();
		w->show();

		return(Fl::run());
} */