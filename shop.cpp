#include <windows.h>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <stdio.h>
#include <string>
#include "shop.h"
#include "robotmodel.h"
//#include "customer.h"
//#include "salesassoc.h"
//#include "order.h"

using namespace std;

//Create a new robot model and add it to the list of models 'robotModels'
void Shop::add_robot_model()
{
	string name = string{ fl_input("Enter Model Name: ", 0) };
	const char *num = fl_input("Enter model number: ");
	int number;
	if (isdigit(*num))
	{
		number = atoi(num);
	}
	else
	{
		throw runtime_error("Cannot convert model number to integer");
	}

	RobotModel *rm = new RobotModel(name, number);

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

void Shop::add_customer()
{
	string name;
	int customerNum;
	double wallet;

	cout << endl << endl;
	cout << "Name? ";
	cin.ignore();
	getline(cin, name);
	cout << "Customer Number?  ";
	cin >> customerNum;
	cout << "Wallet amount? ";
	cin >> wallet;

	Customer *cust = new Customer(name, customerNum, wallet);

	if (customers == NULL)
	{
		cust->next = NULL;
		customers = cust;
	}
	else
	{
		Customer *temp = customers;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = cust;
		cust->next = NULL;
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
}*/