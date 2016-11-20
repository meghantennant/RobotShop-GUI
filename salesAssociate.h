#pragma once
#ifndef ___SALESASSOCIATE_H
#define ___SALESASSOCIATE_H 2016
#include <string>

using namespace std;

class Sales_Associate {
public:
	Sales_Associate(string p_name, string p_empID) : name(p_name), employeeID(p_empID) { made = true; };
	string get_name();
	string get_id();
	bool is_made();
	Sales_Associate *next;

private:
	string name;
	string employeeID;
	bool made = false;

};
#endif // __SALESASSOCIATE_H 2016