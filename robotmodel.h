#pragma once
#ifndef __ROBOTMODEL_H
#define __ROBOTMODEL_H 2016
#include "robotpart.h"
class RobotModel {
public:
	RobotModel(string m_name, string m_model_number, string m_head, string m_right_arm, string m_left_arm, string m_locomotor, string m_torso, string m_battery1, string m_battery2, string m_battery3)
		: name(m_name), model_number(m_model_number), head(m_head), right_arm(m_right_arm), left_arm(m_left_arm), locomotor(m_locomotor), torso(m_torso), battery1(m_battery1), battery2(m_battery2), battery3(m_battery3) 
	{
		made = true;
	};

	string get_name() {return name;}
	string get_model_number() { return model_number; }
	string get_head() { return head; }
	string get_right_arm() { return right_arm; }
	string get_left_arm() { return left_arm; }
	string get_locomotor() { return locomotor; }
	string get_torso() { return torso; }
	string get_battery1() { return battery1; }
	string get_battery2() { return battery2; }
	string get_battery3() { return battery3; }
	void set_price( double model_cost);
	void set_weight(double model_weight);
	double get_price();
	double get_weight();
	string to_string();
	bool is_made() { return made; }

	RobotModel *next = NULL; // points to the next robot model in the shop list

private:
	string name;
	string model_number;
	string head;
	string right_arm;
	string left_arm;
	string locomotor;
	string torso;
	string battery1;
	string battery2;
	string battery3;
	double price;
	double weight;
	bool made = false;


};
#endif // __ROBOTMODEL_H
