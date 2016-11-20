#include <windows.h>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Help_View.H>
#include <string>
#include "shop.h"
#include "head.h"
#include "arm.h"
#include "locomotor.h"
#include "torso.h"
#include "battery.h"
#include "robotModelDlg.h"
#include "robotmodel.h"
#include "customerDlg.h"
#include "customer.h"
#include "salesAssociateDlg.h"
#include "salesAssociate.h"
#include "order.h"

Customer_Dialog *new_customer_dialog;
Robot_Model_Dialog *new_robot_model_dialog;
Sales_Associate_Dialog *new_sales_associate_dialog;


using namespace std;

//Create and Store Robot Heads
void Shop::create_head(string name, string part_number, string type, double weight, double cost, string description)
{

	Head *head = new Head(name, part_number, type, weight, cost, description);
	if (head->check_made())
	{
		fl_message("A head was made!");
	}
	else
	{
		throw runtime_error("Failed to make a head.");
	}

	head->next = NULL;

	Head *temp = heads;

	//add head to shop list of heads
	if (temp == NULL)
	{
		heads = head;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = head;
	}
}

//Create Robot Arms and store them into the shop arms list
void Shop::create_arm(string name, string part_number, string type, double weight, double cost, string description)
{
	Arm *arm = new Arm(name, part_number, type, weight, cost, description);
	if (arm->check_made())
	{
		fl_message("An arm was made!");
	}
	else
	{
		throw runtime_error("Failed to make an arm.");
	}

	arm->next = NULL;

	Arm *temp = arms;

	//add arm to shop list of arms
	if (temp == NULL)
	{
		arms = arm;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = arm;
	}
}

//Create Robot Locomotors and store them into the shop locomotors list
void Shop::create_locomotor(string name, string part_number, string type, double weight, double cost, string description, double speed)
{
	//Create a locomotor
	Locomotor *locomotor = new Locomotor(name, part_number, type, weight, cost, description, speed);
	if (locomotor->check_made())
	{
		fl_message("A locomotor was made!");
	}
	else
	{
		throw runtime_error("Failed to make a locomotor.");
	}

	locomotor->next = NULL;

	Locomotor *temp = locomotors;

	//add locomotor to shop list of locomotors
	if (temp == NULL)
	{
		locomotors = locomotor;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = locomotor;
	}
}

//Create Robot Torsos and store them into the shop torsos list
void Shop::create_torso(string name, string part_number, string type, double weight, double cost, string description)
{
	//Create a torso
	Torso *torso = new Torso(name, part_number, type, weight, cost, description);
	if (torso->check_made())
	{
		fl_message("A torso was made!");
	}
	else
	{
		throw runtime_error("Failed to make a torso.");
	}

	torso->next = NULL;

	Torso *temp = torsos;

	//add torso to shop list of torsos
	if (temp == NULL)
	{
		torsos = torso;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = torso;
	}
}

//Create Robot Batteries and store them into the shop batteries list
void Shop::create_battery(string name, string part_number, string type, double weight, double cost, string description, double power, double energy)
{
	//Create a battery
	Battery *battery = new Battery(name, part_number, type, weight, cost, description, power, energy);
	if (battery->check_made())
	{
		fl_message("A battery was made!");
	}
	else
	{
		throw runtime_error("Failed to make a battery.");
	}

	battery->next = NULL;

	Battery *temp = batteries;

	//add battery to shop list of batteries
	if (temp == NULL)
	{
		batteries = battery;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = battery;
	}
}

//Create a new robot model and add it to the list of models 'robotModels'
void Shop::add_robot_model(string name, string model_number, string head, string right_arm, string left_arm, string locomotor, string torso, string battery1, string battery2, string battery3)
{
	//Get list of specific parts
	Head *hd = heads;
	Arm *a1 = arms;
	Torso *ts = torsos;
	Locomotor *lm = locomotors;
	Battery *bt = batteries;

	//Check for empty lists
	if (heads == NULL)
	{
		fl_message("There are no heads in the program to attach!");
		return;
	}
	else if (arms == NULL)
	{
		fl_message("There are no arms in the program to attach!");
		return;
	}
	else if (locomotors == NULL)
	{
		fl_message("There are no locomotors in the program to attach!");
		return;
	}
	else if (torsos == NULL)
	{
		fl_message("There are no torsos in the program to attach!");
		return;
	}
	else if (batteries == NULL)
	{
		fl_message("There are no batteries in the program to attach!");
		return;
	}

	//Check to see if part number given by the user is in the lists
	double price = 0;
	double weight = 0;

	while (hd != NULL)
	{
		if (hd->get_part_number() == head)
		{ 
			price += hd->get_cost();     // add cost of head to price of robot model
			weight += hd->get_weight();  // add weight of part to total robot weight
			break;
		}
		else { hd = hd->next; }
	}
	if (hd == NULL)
	{
		fl_message("No matching part number for that head was found.");
		return;
	}

	while (a1 != NULL)
	{
		if (a1->get_part_number() == right_arm) 
		{ 
			price += a1->get_cost();    //add cost of arm to price of robot model
			weight += a1->get_weight();  // add weight of part to total robot weight
			break;
		}
		else { a1 = a1->next; }
	}
	if (a1 == NULL)
	{
		fl_message("No matching part number for that right arm was found.");
		return;
	}

	a1 = arms; //reset to first part in list
	while (a1 != NULL)
	{
		if (a1->get_part_number() == left_arm)
		{ 
			price += a1->get_cost();    //add cost of arm to price of robot model
			weight += a1->get_weight();  // add weight of part to total robot weight
			break; 
		}
		else { a1 = a1->next; }
	}
	if (a1 == NULL)
	{
		fl_message("No matching part number for that left arm was found.");
		return;
	}

	while (lm != NULL)
	{
		if (lm->get_part_number() == locomotor) 
		{ 
			price += lm->get_cost();    //add cost of locomotor to price of robot model
			weight += lm->get_weight();  // add weight of part to total robot weight
			break;
		}
		else { lm = lm->next; }
	}
	if (lm == NULL)
	{
		fl_message("No matching part number for that locomotor was found.");
		return;
	}

	while (ts != NULL)
	{
		if (ts->get_part_number() == torso)
		{ 
			price += ts->get_cost();     // add cost of torso to price of robot model
			weight += ts->get_weight();  // add weight of part to total robot weight
			break;
		}
		else { ts = ts->next; }
	}
	if (ts == NULL)
	{
		fl_message("No matching part number for that torso was found.");
		return;
	}

	while (bt != NULL)
	{
		if (bt->get_part_number() == battery1) 
		{ 
			price += bt->get_cost();    // add cost of battery to price of robot model
			weight += bt->get_weight();  // add weight of part to total robot weight
			break;
		}
		else { bt = bt->next; }
	}
	if (bt == NULL)
	{
		fl_message("No matching part number for battery1 was found.");
		return;
	}
	bt = batteries; // reset to first part in list
	while (bt != NULL)
	{
		if (bt->get_part_number() == battery2)
		{
			price += bt->get_cost();    // add cost of battery to price of robot model
			weight += bt->get_weight();  // add weight of part to total robot weight
			break;
		}
		else { bt = bt->next; }
	}
	if (bt == NULL)
	{
		fl_message("No matching part number for battery2 was found.");
		return;
	}
	bt = batteries; // reset to first part in list
	while (bt != NULL)
	{
		if (bt->get_part_number() == battery3) 
		{
			price += bt->get_cost();    // add cost of battery to price of robot model
			weight += bt->get_weight();  // add weight of part to total robot weight
			break;
		}
		else { bt = bt->next; }
	}
	if (bt == NULL)
	{
		fl_message("No matching part number for battery3 was found.");
		return;
	}



	//If all part numbers are found in the shop list of robot parts, define a model
	RobotModel *rm = new RobotModel(name, model_number, head, left_arm, right_arm, locomotor, torso, battery1, battery2, battery3);
	if (rm->is_made())
	{
		fl_message("Robot Model Created!");
	}

	rm->set_price(price);    //set cost of robot model
	rm->set_weight(weight); // set weight of robot model

	if (robotModels == NULL) //Check for empty list
	{
		robotModels = rm; // start list for robotModels
		rm->next = NULL;
	}
	else
	{
		RobotModel *temp = robotModels;
		while (temp->next != NULL) //find end of list
		{
			temp = temp->next;
		}
		temp->next = rm; //add model to end of list
		rm->next = NULL;
	}
}

void Shop::add_customer(string name, string number, string email, double wallet)
{
	Customer *customer = new Customer(name, number, email, wallet);
	if (customer->is_made())
	{
		fl_message("Customer was added!");
	}

	if (customers == NULL)
	{
		customer->next = NULL;
		customers = customer;
	}
	else
	{
		Customer *temp = customers;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = customer;
		customer->next = NULL;
	}
}

void Shop::add_sales_associate(string name, string number)
{

	Sales_Associate *sa = new Sales_Associate(name, number);
	if (sa->is_made())
	{
		fl_message("Sales associate was added!");
	}

	Sales_Associate *temp = sales_associates;
	if (temp == NULL)
	{
		sales_associates = sa;
		sa->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = sa;
		sa->next = NULL;
	}
}

void Shop::add_order(string order_number, string model_number, string customer_name, string sales_associate_number)
{

	Customer *temp = customers; //gets shop customer list
	while (temp != NULL) //loop until end of list or customer name is found
	{
		if (customer_name != temp->get_name())
		{
			temp = temp->next;
		}
		else
		{
			break;
		}
	}

	if (temp == NULL) //if end of list is reached
	{
		//Make a new customer for order or start over
		if (fl_choice("That customer was not found, enter a new customer?", 0, fl_yes, fl_no) == 1)
		{
			new_customer_dialog = new Customer_Dialog{};
			new_customer_dialog->show();
			customer_name = new_customer_dialog->name();
		}
		else { return; }
	}
	

	RobotModel *temp2 = robotModels; //gets shop's list of robot models

	while (true)
	{
		while (temp2 != NULL) //loop until model number is found or end of list is reached
		{
			if (model_number != temp2->get_model_number())
			{
				temp2 = temp2->next;
			}
			else
			{
				break;
			}
		}

		if (temp2 == NULL)
		{
			//If model number not found, make a new model for the order or start over
			if (fl_choice("That model number was not found. Make a new model?", 0, fl_yes, fl_no) == 1)
			{
				new_robot_model_dialog = new Robot_Model_Dialog{};
				new_robot_model_dialog->show();
				model_number = new_robot_model_dialog->model_number();
			}
			else { return; }
		}
		else { break; }
	}
	
	
	
	Sales_Associate *temp3 = sales_associates; //get shop's list of sales associates
	while (temp3 != NULL)   //loop until employee number is found or reach end of list 
	{
		if (sales_associate_number != temp3->get_id())
		{
			temp3 = temp3->next;
		}
		else
		{
			break;
		}
	}

	if (temp3 == NULL)
	{
		//if employee number is not found, make a new sales associate for order or start over
		if (fl_choice("That sales associate was not found, enter a new sales associate?", 0, fl_yes, fl_no) == 1)
		{
			new_sales_associate_dialog = new Sales_Associate_Dialog{};
			new_sales_associate_dialog->show();
			sales_associate_number = new_sales_associate_dialog->employee_number();
		}
		else { return; }		
	}
	


	//Add order to shop list of orders
	double price = temp2->get_price();
	double weight = temp2->get_weight();

	Order *order = new Order(order_number, model_number, customer_name, sales_associate_number, price, weight);


	//View Order
	Fl_Window *w2 = new Fl_Window{ 300,300,"Order Details" };

	string r_order = order->to_string();
	const char *m_order = r_order.c_str();
	Fl_Help_View *out = new Fl_Help_View(30, 30, 210, 150, "Customer Order");
	out->value(m_order);

	w2->end();
	w2->set_non_modal();
	w2->show();

	Order *temp4 = orders;
	if (orders == NULL)
	{
		orders = order;
	}
	else
	{
		while (temp4->next != NULL)
		{
			temp4 = temp4->next;
		}

		temp4->next = order;
	}

				
}

