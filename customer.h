#pragma once
#ifndef __CUSTOMER_H
#define __CUSTOMER_H 2016
#include <string>
//#include "order.h"

using namespace std;

class Customer {
public:
	Customer(string p_name, string custNum, double p_wallet)
		: name(p_name), customer_number(custNum), wallet(p_wallet) {};

	string get_name();
	string get_cust_num();
	double get_wallet();
	void set_wallet(double money);
	void to_string();
	//void view_orders();
	//Order *orders = NULL;
	Customer *next;


private:
	string name;
	string customer_number;
	double wallet;
};
#endif // __CUSTOMER_H
