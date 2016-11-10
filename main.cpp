#include <Windows.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Text_Display.H>
#include <string>
#include <iostream>
#include "view.h"
#include "shop.h"
#include "head.h"
#include "arm.h"
#include "locomotor.h"
#include "torso.h"
#include "battery.h"
#include "robotmodel.h"

using namespace std;

//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;
Shop shop;

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
	//Check for empty robot model list
	if (shop.robotModels == NULL)
	{
		fl_message("Need to make a robot model first!");
		return;
	}
	else
	{
		int flag = 0;

		//Select model to add part to
		const char *model = fl_input("Enter the model number you would like to add this part to: ");
		int modelNum;
		if (isdigit(*model))
		{
			modelNum = atoi(model); //Convert string to interger
		}
		else
		{
			throw runtime_error("Cannot convert model number into an interger.");
		}

		RobotModel *temp = shop.robotModels; //Get list of robot models

		while (temp != NULL)
		{
			if (modelNum == temp->get_model_number()) //if model number is found
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

				if (head->check_made())
				{
					fl_message("A head was made!");
				}
				else
				{
					throw runtime_error("Failed to make a head.");
				}


				RobotPart *temp2 = temp->first; //find model's list of robot parts

				if (temp2 == NULL) //check for empty parts list
				{
					temp->add_robotpart(head); //start parts list
					fl_message("A head has been added to the model.");
					temp->set_price();
					return;
				}
				else
				{
					//search through model's parts list to see if part has already been created
					while (temp2 != NULL)
					{
						//If model already has a head
						if (temp2->get_comp_type() == "Head" || temp2->get_comp_type() == "head")
						{
							fl_message("There is already a head for this model!");
							flag = 1;
							return;
						}
						else
						{
							temp2 = temp2->next;
						}
					}

					if (flag == 0) //If model does not already have a head
					{
						temp->add_robotpart(head);
						fl_message("A head has been added to the model.");
						temp->set_price();
						return;
					}
				}
			}
			else
			{
				temp = temp->next; //go to next model
			}
		}
		if (temp == NULL) // end of model list
		{
			fl_message("No matching robot model number was found.");
		}
	}
}

void ArmCB(Fl_Widget *w, void *p)
{
	if (shop.robotModels == NULL)
	{
		fl_message("Need to make a robot model first!");
		return;
	}
	else
	{
		int flag = 0;

		//Select model to add part to
		const char *model = fl_input("Enter the model number you would like to add this part to: ");
		int modelNum;
		if (isdigit(*model))
		{
			modelNum = atoi(model); //Convert string to interger
		}
		else
		{
			throw runtime_error("Cannot convert model number into an interger.");
		}

		RobotModel *temp = shop.robotModels;

		while (temp != NULL) //Go through model list to find matching model number
		{
			if (modelNum == temp->get_model_number()) //if model number is found
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

				if (arm->check_made())
				{
					fl_message("An arm was made!");
				}
				else
				{
					throw runtime_error("Could not make an arm.");
				}
				RobotPart *temp2 = temp->first; //find model's list of robot parts

				if (temp2 == NULL) //check for empty parts list
				{
					temp->add_robotpart(arm); //start parts list
					fl_message("An arm has been added to the model.");
					temp->set_price();
					return;
				}
				else
				{
					//Search through parts list for arms
					while (temp2 != NULL)
					{
						if (temp2->get_comp_type() == "Arm" || temp2->get_comp_type() == "arm")
						{
							flag++;
							temp2 = temp2->next;
						}
						else
						{
							temp2 = temp2->next;
						}
					}

					if (flag < 2) //add arm if model does not have 2 arms
					{
						temp->add_robotpart(arm);
						fl_message("An arm has been added to the model.");
						temp->set_price();
						return;
					}
					else
					{
						//If model already has two arms
						fl_message("There are already two arms for this model!");
						return;
					}
				}
			}
			else
			{
				temp = temp->next; //go to next model
			}
		}
		if (temp == NULL) // end of model list
		{
			fl_message("No matching robot model number was found.");
		}
	}
}

void LocomotorCB(Fl_Widget *w, void *p)
{
	RobotModel *temp = shop.robotModels; //Get list of robot models

	if (shop.robotModels == NULL)
	{
		fl_message("Need to make a robot model first!");
		return;
	}
	else
	{
		int flag = 0;

		//Select model to add part to
		const char *model = fl_input("Enter the model number you would like to add this part to: ");
		int modelNum;
		if (isdigit(*model))
		{
			modelNum = atoi(model); //Convert string to interger
		}
		else
		{
			throw runtime_error("Cannot convert model number into an interger.");
		}

		while (temp != NULL) //Go through model list to find matching model number
		{
			if (modelNum == temp->get_model_number()) //if model number is found
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

				if (loco->check_made())
				{
					fl_message("A locomotor was made!");
				}
				else
				{
					throw runtime_error("Cannot make a locomotor.");
				}

				RobotPart *temp2 = temp->first; //Get list of parts for model
				if (temp2 == NULL) //Check for empty parts list
				{
					temp->add_robotpart(loco);
					fl_message("A locomotor has been added to the model.");
					temp->set_price();
					return;
				}
				//Search through parts list to see if part is already in model
				while (temp2 != NULL)
				{
					if (temp2->get_comp_type() == "Locomotor" || temp2->get_comp_type() == "locomotor")
					{
						flag++;
						temp2 = temp2->next;
					}
					else
					{
						temp2 = temp2->next;
					}
				}
				if (flag == 0) //Add part if part was not found
				{
					temp->add_robotpart(loco);
					fl_message("A locomotor has been added to the model.");
					temp->set_price();
					return;
				}
				else
				{
					fl_message( "There is already a locomotor for this model");
					return;
				}
			}
			else
			{
				temp = temp->next; //go to next model
			}
		}

	}
	if (temp == NULL) //End of model list
	{
		fl_message( "No matching model number was found.");
	}
	
}

void TorsoCB(Fl_Widget *w, void *p)
{
	int flag = 0;

	if (shop.robotModels == NULL)
	{
		fl_message("Need to make a robot model first!");
		return;
	}
	else
	{
		//Select model to add part to
		const char *model = fl_input("Enter the model number you would like to add this part to: ");
		int modelNum;
		if (isdigit(*model))
		{
			modelNum = atoi(model); //Convert string to interger
		}
		else
		{
			throw runtime_error("Cannot convert model number into an interger.");
		}

		RobotModel *temp = shop.robotModels;

		while (temp != NULL)
		{
			if (modelNum == temp->get_model_number()) //if model number is found
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

				if (torso->check_made())
				{
					fl_message("A toros was made!");
				}
				else
				{
					throw runtime_error("Cannot make a torso.");
				}


				RobotPart *temp2 = temp->first; //Get parts list for model
				if (temp2 == NULL) //Check for empty parts list
				{
					temp->add_robotpart(torso);
					fl_message("A torso has been added to the model.");
					temp->set_price();
					return;
				}
				//Search through parts list to see if model already has the part
				while (temp2 != NULL)
				{
					if (temp2->get_comp_type() == "Torso" || temp2->get_comp_type() == "torso")
					{
						flag++;
						temp2 = temp2->next;
					}
					else
					{
						temp2 = temp2->next;
					}
				}
				if (flag == 0) //Add part if it was not found
				{
					temp->add_robotpart(torso);
					fl_message("A torso has been added to the model.");
					temp->set_price();
					return;
				}
				else
				{
					fl_message( "There is already a Torso for this model.");
					return;
				}
			}
			else
			{
				temp = temp->next;
			}
		}
		if(temp == NULL)
		{
			fl_message("No matching model number was found.");
		}
	}

}

void BatteryCB(Fl_Widget *w, void *p)
{
	int flag = 0;

	if (shop.robotModels == NULL)
	{
		fl_message("Need to make a robot model first!");
		return;
	}
	else
	{
		//Select model to add part to
		const char *model = fl_input("Enter the model number you would like to add this part to: ");
		int modelNum;
		if (isdigit(*model))
		{
			modelNum = atoi(model); //Convert string to interger
		}
		else
		{
			throw runtime_error("Cannot convert model number into an interger.");
		}

		RobotModel *temp = shop.robotModels;

		while (temp != NULL)
		{
			if (modelNum == temp->get_model_number()) //if model number is found
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

				if (bat->check_made())
				{
					fl_message("A battery was made!");
				}
				else
				{
					throw runtime_error("Cannot make a battery.");
				}

				RobotPart *temp2 = temp->first; //Get model's parts list
												//Search through model list for a torso
				while (temp2 != NULL)
				{
					if (temp2->get_comp_type() == "Torso" || temp2->get_comp_type() == "torso")
					{
						flag = 1;
						break;
					}
					else
					{
						temp2 = temp2->next;
					}
				}
				if (flag == 1) // If there is a torso for the model
				{
					flag = 0;

					temp2 = temp->first;
					//Search through parts list for batteries
					while (temp2 != NULL)
					{
						if (temp2->get_comp_type() == "Battery" || temp2->get_comp_type() == "battery")
						{
							flag++;
							temp2 = temp2->next;
						}
						else
						{
							temp2 = temp2->next;
						}
					}
					if (flag != temp->get_bat_compart()) // Check for number of battery compartments
					{
						//add battery if there is room for another
						temp->add_robotpart(bat);
						fl_message("A battery has been added to the model.");
						temp->set_price();
						return;
					}
					else
					{
						fl_message("All of the battery compartments have already been filled for this model.");
						return;
					}
				}
				else
				{
					fl_message("No torso was found for this model.Must have a torso to add batteries!");
					return;
				}
			}
			else
			{
				temp = temp->next; //Go to next model
			}
		}
		if (temp == NULL)
		{
			fl_message("No matching model number was found.");
		}
	}
}

void ModelCB(Fl_Widget *w, void *p)
{
	shop.add_robot_model();
	fl_message("Robot Model Created!");
}

/*void ListmodelsCB(Fl_Widget *w, void *p)
{
	Fl_Text_Display *ls = new Fl_Text_Display(rm->to_string());
	

}*/


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
		{"&Robot Model",0,(Fl_Callback *)ModelCB},
		{0},
	{"&Report", 0, 0, 0, FL_SUBMENU},
		{"&All Robot Models", 0,(Fl_Callback *)ListmodelsCB},
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
