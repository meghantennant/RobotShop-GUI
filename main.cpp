#include <Windows.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H> 
#include <FL/Fl_PNG_Image.H>
#include <Fl/Fl_Select_Browser.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Help_View.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Text_Display.H>
#include <string>
#include <iostream>
#include "view.h"
#include "shop.h"
#include "headDlg.h"
#include "head.h"
#include "armDlg.h"
#include "arm.h"
#include "locomotorDlg.h"
#include "locomotor.h"
#include "torsoDlg.h"
#include "torso.h"
#include "batteryDlg.h"
#include "battery.h"
#include "robotModelDlg.h"
#include "robotmodel.h"
#include "customerDlg.h"
#include "customer.h"

using namespace std;

//
// Declarations
//

class Arm_Dialog;
class Head_Dialog;
class Locomotor_Dialog;
class Torso_Dialog;
class Battery_Dialog;
class Robot_Model_Dialog;

//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
View *view;
Shop shop = Shop("Robot Shop GUI");
Head_Dialog *head_dialog;
Arm_Dialog *arm_dialog;
Locomotor_Dialog *locomotor_dialog;
Torso_Dialog *torso_dialog;
Battery_Dialog *battery_dialog;
Robot_Model_Dialog *robot_model_dialog;
Customer_Dialog *customer_dialog;

//
// Callbacks
//

void CloseCB(Fl_Widget *w, void *p)
{
	int selection = 1;
	selection = fl_choice("Program not saved. Exit anyways?", fl_no, fl_yes, 0);
	
	if (selection == 1)
	{
		win->hide();
	}
}

//
// Callbacks for making robot parts
//

void HeadCB(Fl_Widget *w, void *p) { head_dialog->show();}
void cancel_headCB(Fl_Widget *w, void *p) { head_dialog->hide(); }
void create_headCB(Fl_Widget *w, void *p)
{
	//Converts dialog input into variables
	string name = head_dialog->name();
	string part_number = head_dialog->part_number();
	string type = head_dialog->type();
	string wt = head_dialog->weight();
	double weight;
	try
	{
		weight = stod(wt);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert weight to double");
	}
	string ct = head_dialog->cost();
	double cost;
	try
	{
		cost = stod(ct);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert cost to double");
	}

	string description = head_dialog->description();

	//Take Variables and Make a Head
	shop.create_head(name, part_number, type, weight, cost, description);
} 


void ArmCB(Fl_Widget *w, void *p) { arm_dialog->show(); }
void cancel_armCB(Fl_Widget *w, void *p) { arm_dialog->hide(); }
void create_armCB(Fl_Widget *w, void *p)
{
	string name = arm_dialog->name();
	string part_number = arm_dialog->part_number();
	string type = arm_dialog->type();
    string wt = arm_dialog->weight();
	double weight;
	try
	{
		weight = stod(wt);
	}
	catch(...)
	{
		throw runtime_error("Cannot convert weight to double");
	}
	string ct = arm_dialog->cost();
	double cost;
	try
	{
		cost = stod(ct);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert cost to double");
	}
	
	string description = arm_dialog->description();
	
	shop.create_arm(name, part_number, type, weight, cost, description);
}

void LocomotorCB(Fl_Widget *w, void *p) { locomotor_dialog->show(); }
void cancel_locomotorCB(Fl_Widget *w, void *p) { locomotor_dialog->hide(); }
void create_locomotorCB(Fl_Widget *w, void *p)
{
	string name = locomotor_dialog->name();
	string part_number = locomotor_dialog->part_number();
	string type = locomotor_dialog->type();
    string wt = locomotor_dialog->weight();
	double weight;
	try
	{
		weight = stod(wt);
	}
	catch(...)
	{
		throw runtime_error("Cannot convert weight to double");
	}
	string ct = locomotor_dialog->cost();
	double cost;
	try
	{
		cost = stod(ct);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert cost to double");
	}
	
	string description = locomotor_dialog->description();
	string spd = locomotor_dialog->speed();
	double speed;
	try
	{
		speed = stod(spd);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert speed to double");
	}

	shop.create_locomotor(name, part_number, type, weight, cost, description, speed);
}

void TorsoCB(Fl_Widget *w, void *p) { torso_dialog->show(); }
void cancel_torsoCB(Fl_Widget *w, void *p) { torso_dialog->hide(); }
void create_torsoCB(Fl_Widget *w, void *p)
{
	string name = torso_dialog->name();
	string part_number = torso_dialog->part_number();
	string type = torso_dialog->type();
	string wt = torso_dialog->weight();
	double weight;
	try
	{
		weight = stod(wt);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert weight to double");
	}
	string ct = torso_dialog->cost();
	double cost;
	try
	{
		cost = stod(ct);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert cost to double");
	}

	string description = torso_dialog->description();

	shop.create_torso(name, part_number, type, weight, cost, description);
}

void BatteryCB(Fl_Widget *w, void *p) { battery_dialog->show(); }
void cancel_batteryCB(Fl_Widget *w, void *p) { battery_dialog->hide(); }
void create_batteryCB(Fl_Widget *w, void *p)
{
	string name = battery_dialog->name();
	string part_number = battery_dialog->part_number();
	string type = battery_dialog->type();
	string wt = battery_dialog->weight();
	double weight;
	try
	{
		weight = stod(wt);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert weight to double");
	}
	string ct = battery_dialog->cost();
	double cost;
	try
	{
		cost = stod(ct);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert cost to double");
	}

	string description = battery_dialog->description();
	string pw = battery_dialog->power();
	double power;
	try
	{
		power = stod(pw);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert power to double");
	}
	string en = battery_dialog->energy();
	double energy;
	try
	{
		energy = stod(en);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert energy to double");
	}		

	shop.create_battery(name, part_number, type, weight, cost, description, power, energy);
} 

//
//Callbacks for making robot models
//

void ModelCB(Fl_Widget *w, void *p) { robot_model_dialog->show(); }
void cancel_robot_modelCB(Fl_Widget *w, void *p) { robot_model_dialog->hide(); }
void create_robot_modelCB(Fl_Widget *w, void *p)
{
	string name = robot_model_dialog->name();
	string m_number = robot_model_dialog->model_number();
	string head = robot_model_dialog->head();
	string right_arm = robot_model_dialog->right_arm();
	string left_arm = robot_model_dialog->left_arm();
	string locomotor = robot_model_dialog->locomotor();
	string torso = robot_model_dialog->torso();
	string battery1 = robot_model_dialog->battery1();
	string battery2 = robot_model_dialog->battery2();
	string battery3 = robot_model_dialog->battery3();

	shop.add_robot_model(name, m_number, head, right_arm, left_arm, locomotor, torso, battery1, battery2, battery3);
	fl_message("Robot Model Created!");
}

//
//Callbacks for listing robot models
//

void show_modelCB(Fl_Widget *w, void *p)
{
			Fl_Window *m_win2 = new Fl_Window(340, 270, "Robot Model List");
			Fl_Select_Browser *b = (Fl_Select_Browser*)w;
			int index = b->value();

			RobotModel *temp = shop.robotModels;
			for (int i = 1; i < index; i++)
			{
				temp = temp->next;
			}
			string p_model = temp->to_string();
			const char *model = p_model.c_str();
			Fl_Help_View *out = new Fl_Help_View(30, 30, 210, 150, "Robot Models");
			out->value(model);

			m_win2->end();
			m_win2->set_non_modal();
			m_win2->show();
}

void ListmodelsCB(Fl_Widget *w, void *p)
{
	RobotModel *temp = shop.robotModels;
	int count = 0;
	Fl_Window *m_win = new Fl_Window(340, 270, "Robot Model List");
	Fl_Select_Browser *models = new Fl_Select_Browser(30, 30, 210, 150, "Robot Models");
	while (temp != NULL)
	{
		string p_name = temp->get_name();
		const char *name = p_name.c_str();
		models->add(name);
		
		//Fl_Output *out = new Fl_Output(120, 10, 210, 25, "Name:");
		//out->value(name); 
		
		//Fl_Help_View *out = new Fl_Help_View(30, 30, 210, 150, "Robot Models");
		//out->value(model);
		temp = temp->next;

	}

	models->callback((Fl_Callback *)show_modelCB, 0);
	m_win->end();
	m_win->set_non_modal();
	m_win->show();
}

//
//Callbacks for creating customers
//

void CustomerCB(Fl_Widget *w, void *p) { customer_dialog->show(); }
void cancel_customerCB(Fl_Widget *w, void *p) { customer_dialog->hide(); }
void create_customerCB(Fl_Widget *w, void *p)
{
	//Converts dialog input into variables
	string name = customer_dialog->name();
	string customer_number = customer_dialog->customer_number();
	string wt = customer_dialog->wallet();
	double wallet;
	try
	{
		wallet = stod(wt);
	}
	catch (...)
	{
		throw runtime_error("Cannot convert wallet to double");
	}

	shop.add_customer(name, customer_number, wallet);
	fl_message("A customer was added!");
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
			{"&Torso",0,(Fl_Callback *)TorsoCB},
			{"&Battery",0,(Fl_Callback *)BatteryCB},
			{0},
		{"&Robot Model",0,(Fl_Callback *)ModelCB},
		{"&Customer",0,(Fl_Callback *)CustomerCB},
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
	fl_register_images();
	//Set window length and height
	const int X = 640;
	const int Y = 480;

	// Create Dialogs
	head_dialog = new Head_Dialog{};
	arm_dialog = new Arm_Dialog{};
	locomotor_dialog = new Locomotor_Dialog{};
	torso_dialog = new Torso_Dialog{};
	battery_dialog = new Battery_Dialog{};
	robot_model_dialog = new Robot_Model_Dialog{};
	customer_dialog = new Customer_Dialog();

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
