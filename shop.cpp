#include <windows.h>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <string>
#include "shop.h"
#include "head.h"
#include "arm.h"
#include "locomotor.h"
#include "torso.h"
#include "battery.h"
#include "robotmodel.h"
#include "customer.h"
//#include "salesassoc.h"
//#include "order.h"


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
	while (hd != NULL)
	{
		if (hd->get_part_number() == head) { break;}
		else { hd = hd->next; }
	}
	if (hd == NULL)
	{
		fl_message("No matching part number for that head was found.");
		return;
	}

	while (a1 != NULL)
	{
		if (a1->get_part_number() == right_arm) { break; }
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
		if (a1->get_part_number() == left_arm) { break; }
		else { a1 = a1->next; }
	}
	if (a1 == NULL)
	{
		fl_message("No matching part number for that left arm was found.");
		return;
	}

	while (lm != NULL)
	{
		if (lm->get_part_number() == locomotor) { break; }
		else { lm = lm->next; }
	}
	if (lm == NULL)
	{
		fl_message("No matching part number for that locomotor was found.");
		return;
	}

	while (ts != NULL)
	{
		if (ts->get_part_number() == torso) { break; }
		else { ts = ts->next; }
	}
	if (ts == NULL)
	{
		fl_message("No matching part number for that torso was found.");
		return;
	}

	while (bt != NULL)
	{
		if (bt->get_part_number() == battery1) { break; }
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
		if (bt->get_part_number() == battery2) { break; }
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
		if (bt->get_part_number() == battery3) { break; }
		else { bt = bt->next; }
	}
	if (bt == NULL)
	{
		fl_message("No matching part number for battery3 was found.");
		return;
	}



	//If all part numbers are found in the shop list of robot parts, define a model
	RobotModel *rm = new RobotModel(name, model_number, head, left_arm, right_arm, locomotor, torso, battery1, battery2, battery3);

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

void Shop::add_customer(string name, string number, double wallet)
{
	Customer *customer = new Customer(name, number, wallet);

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

/*
void Shop::add_order()
{
	int orderNum;
	string date;
	Customer *customer;
	SalesAssoc *sa;
	RobotModel *rm;
	char cust;

	cout << "Order Number? ";
	cin >> orderNum;
	cout << "Date? (mm/dd/yyyy) ";
	cin >> date;
	cout << "Is this a new customer? (Y/N): ";
	cin >> cust;

	if (cust == 'y' || cust == 'Y')
	{
		add_customer();
	}
	cout << endl << endl;
	cout << "START ORDER";
	cout << endl << endl;
	string s_name;
	cout << "Customer name? ";
	cin.ignore();
	getline(cin, s_name);

	Customer *temp = customers;
	if (customers == NULL)
	{
		cerr << "There are no customers in the shop list!" << endl;
		return;
	}
	else
	{
		while (temp != NULL)
		{
			if (s_name == temp->get_name())
			{
				customer = temp;
				int modelNum;

				cout << "Enter the Robot Model Number you would to order: ";
				cin >> modelNum;

				RobotModel *temp2 = robotModels;

				if (temp2 == NULL)
				{
					cerr << "There are no robot models to order. Please make a robot model." << endl;
				}
				else
				{
					while (temp2 != NULL)
					{
						if (modelNum == temp2->get_model_number())
						{
							rm = temp2;
							break;
						}
						else
						{
							temp2 = temp2->next;
						}
					}
					if (temp2 == NULL)
					{
						cerr << "That model number was not found!";
					}
				}
				int empID;
				cout << "Employee ID? ";
				cin >> empID;

				SalesAssoc *temp3 = salesAssocs;
				if (temp3 == NULL)
				{
					cerr << "There are no sales associates in shop list. Please add an associate." << endl;
				}
				else
				{
					while (temp3 != NULL)
					{
						if (empID == temp3->get_id())
						{
							sa = temp3;
							break;
						}
						else
						{
							temp3 = temp3->next;
						}
					}
					if (temp3 == NULL)
					{
						cerr << "Could not find employee with that ID number." << endl;
					}
				}

				//Add order to shop list and to customer list
				Order *cOrder = new Order(orderNum, date, "Placed");

				Order *temp4 = orders;
				//Add order, shop, and sales associate list
				if (temp4 == NULL)
				{
					orders = cOrder;
					cOrder->sNext = NULL;
				}
				else
				{
					while (temp4->sNext != NULL)
					{
						temp4 = temp4->sNext;
					}
					temp4->sNext = cOrder;
					cOrder->sNext = NULL;
				}

				//add order to customer
				Order *temp5 = customer->orders;

				if (temp5 == NULL)
				{
					customer->orders = cOrder;
					cOrder->cNext = NULL;
				}
				else
				{
					while (temp5->cNext != NULL)
					{
						temp5 = temp5->cNext;
					}
					temp5->cNext = cOrder;
					cOrder->cNext = NULL;
				}

				//add order to sales associate list
				Order *temp6 = sa->orders;

				if (temp6 == NULL)
				{
					sa->orders = cOrder;
					cOrder->empNext = NULL;
				}
				else
				{
					while (temp6->empNext != NULL)
					{
						temp6 = temp6->empNext;
					}
					temp6->empNext = cOrder;
					cOrder->empNext = NULL;
				}
				cOrder->customer = customer;
				cOrder->salesAssoc = sa;
				cOrder->robotModel = rm;

				cOrder->to_string();
				break;

			}
			else
			{
				temp = temp->next;
			}
		}

	}
}



void Shop::add_salesAssoc()
{
	string name;
	int empID;
	cout << "Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Employee ID: ";
	cin >> empID;

	SalesAssoc *sa = new SalesAssoc(name, empID);
	SalesAssoc *temp = salesAssocs;
	if (temp == NULL)
	{
		salesAssocs = sa;
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
*/