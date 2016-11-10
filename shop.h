#pragma once
#ifndef __SHOP_H
#define __SHOP_H 2016
//class Order;
class RobotModel;
//class Customer;
//class SalesAssoc;

class Shop {
public:
	void add_robot_model();
	//void add_order();
	//void add_customer();
	//void add_salesAssoc();
	RobotModel *robotModels = NULL;
	//Order *orders = NULL;
	//Customer *customers = NULL;
	//SalesAssoc *salesAssocs = NULL;

};
#endif // __SHOP_H