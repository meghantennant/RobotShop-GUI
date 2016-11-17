#include <windows.h>
#include <iostream>
#include <string>
#include "customer.h"
//#include "order.h"

string Customer::get_name()
{
	return name;
}

string Customer::get_cust_num()
{
	return customer_number;
}

double Customer::get_wallet()
{
	return wallet;
}

void Customer::set_wallet(double money)
{
	wallet = money;
}

void Customer::to_string()
{
	cout << endl << endl;
	cout << "Name: " << name << "\t" << "Customer Number: " << customer_number << endl;
	cout << "Wallet: " << wallet << endl;

	//Order *temp = orders;
	//int token = 0;
	//while (temp != NULL)
	//{
	//	token++;
	//	temp = temp->cNext;
	//}

	//cout << token << " orders placed." << endl;
}

/*void Customer::view_orders()
{
	Order *temp = orders;

	if (temp == NULL)
	{
		cout << "This customer has not placed any orders." << endl;
	}
	else
	{
		while (temp != NULL)
		{
			temp->to_string();
			temp = temp->cNext;
		}
	}
} */
