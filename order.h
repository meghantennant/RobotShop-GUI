#pragma once
#ifndef __ORDER_H
#define __ORDER_H 2016
#include <windows.h>
#include <string>
class Customer;
class SalesAssoc;
class RobotModel;

using namespace std;

class Order {
public:
	Order(string p_order_number, string p_model_number, string p_customer, string p_sales_associate, double cost, double weight)
		:order_number(p_order_number), model_number(p_model_number), customer_name(p_customer), sales_associate_number(p_sales_associate) 
	{
		status = "Placed";
		price = cost;
		model_weight = weight;
	};

	string get_order_number();
	string get_model_number();
	string get_customer();
	string get_sales_associate();
	string to_string();
	string get_status();
	void change_status();
	double get_price();
	double get_model_weight();
	double calc_shipping();
	double calc_tax();
	double total_price();
	Order *next; // points to the next order in the shop list
	
private:
	string order_number;
	string model_number;
	string customer_name;
	string sales_associate_number;
	string status;
	double price;
	double model_weight;
};
#endif // __ORDER_H

