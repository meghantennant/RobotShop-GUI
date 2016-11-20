#pragma once
#ifndef __CUSTOMER_H
#define __CUSTOMER_H 2016
#include <string>
//#include "order.h"

using namespace std;

class Customer {
public:
	Customer(string p_name, string custNum, string p_email, double p_wallet)
		: name(p_name), customer_number(custNum), email(p_email), wallet(p_wallet)
	{
		made = true;
	};

	string get_name();
	string get_cust_num();
	string get_email();
	double get_wallet();
	void set_wallet(double money);
	void to_string();
	bool is_made();
	Customer *next;


private:
	string name;
	string customer_number;
	string email;
	double wallet;
	bool made = false;
};
#endif // __CUSTOMER_H
