#include <windows.h>
#include <sstream>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Input.H>
#include "order.h"
#include "customer.h"
#include "robotmodel.h"
#include "salesAssociate.h"


using namespace std;

string Order::get_order_number()  { return order_number; }
string Order::get_model_number()  { return model_number; }
string Order::get_customer() { return customer_name; }
string Order::get_sales_associate() { return sales_associate_number; }

string Order::to_string()
{
	double cost = total_price();
	ostringstream ss;
	ss << cost;
	string m_cost = ss.str();

	return ("Order Number: " + order_number + "     Model Number: " + model_number + "      Customer: " + customer_name + "     Sales Associate: " + sales_associate_number +
		"     Total Cost: $" + m_cost);
}

string Order::get_status() { return status; }

void Order::change_status()
{
	string new_status = string{ fl_input("Enter new status",0) };

	status = new_status;
}

double Order::get_price() { return price; }
double Order::get_model_weight() { return model_weight; }

double Order::calc_shipping()
{
	double shipping = 6.75;

	shipping += (model_weight * 0.30);

	return shipping;
}

double Order::calc_tax() { return (price * 0.0825); }

double Order::total_price()
{
	double tot_price = price + calc_shipping() + calc_tax();
	return tot_price;
}
