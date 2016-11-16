#pragma once
#ifndef __SHOP_H
#define __SHOP_H 2016
class Head;
class Arm;
class Torso;
class Locomotor;
class Battery;
//class Order;
class RobotModel;
//class Customer;
//class SalesAssoc;

using namespace std;

class Shop {
public:
	Shop(string sname) : name(sname) {}

	void create_head(string name, string part_number, string type, double weight, double cost, string description);
	void create_arm(string name, string part_number, string type, double weight, double cost, string description);
	void create_locomotor(string name, string part_number, string type, double weight, double cost, string description, double speed);
	void create_torso(string name, string part_number, string type, double weight, double cost, string description);
	void create_battery(string name, string part_number, string type, double weight, double cost, string description, double power, double energy);
	void add_robot_model(string name, string model_number, string head, string right_arm, string left_arm, string locomotor, string torso, string battery1, string battery2, string battery3);
	//void add_order();
	//void add_customer();
	//void add_salesAssoc();
	Arm *arms = NULL;
	Head *heads = NULL;
	Torso *torsos = NULL;
	Locomotor *locomotors = NULL;
	Battery *batteries = NULL;
	RobotModel *robotModels = NULL;
	//Order *orders = NULL;
	//Customer *customers = NULL;
	//SalesAssoc *salesAssocs = NULL;

private:
	string name;

};
#endif // __SHOP_H