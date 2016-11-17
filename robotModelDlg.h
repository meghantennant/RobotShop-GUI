#pragma once
#ifndef __ROBOTMODELDLG_H
#define __ROBOTMODELDLG 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void cancel_robot_modelCB(Fl_Widget *w, void *p);

extern void create_robot_modelCB(Fl_Widget *w, void *p);

class Robot_Model_Dialog {
public:
	Robot_Model_Dialog() {
		dialog = new Fl_Window(340, 450, "Robot Model");
		m_name = new Fl_Input(120, 10, 210, 25, "Name:");
		m_name->align(FL_ALIGN_LEFT);

		m_model_number = new Fl_Input(120, 40, 210, 25, "Model Number:");
		m_model_number->align(FL_ALIGN_LEFT);

		m_head = new Fl_Input(120, 70, 210, 25, "Head:");
		m_head->align(FL_ALIGN_LEFT);

		m_rarm = new Fl_Input(120, 100, 210, 25, "Right Arm:");
		m_rarm->align(FL_ALIGN_LEFT);

		m_larm = new Fl_Input(120, 130, 210, 25, "Left Arm:");
		m_larm->align(FL_ALIGN_LEFT);

		m_locomotor = new Fl_Input(120, 160, 210, 25, "Locomotor:");
		m_locomotor->align(FL_ALIGN_LEFT);

		m_torso = new Fl_Input(120, 190, 210, 25, "Torso:");
		m_torso->align(FL_ALIGN_LEFT);

		m_battery1 = new Fl_Input(120, 220, 210, 25, "Battery 1:");
		m_battery1->align(FL_ALIGN_LEFT);

		m_battery2 = new Fl_Input(120, 250, 210, 25, "Battery 2:");
		m_battery2->align(FL_ALIGN_LEFT);

		m_battery3 = new Fl_Input(120, 280, 210, 25, "Battery 3:");
		m_battery3->align(FL_ALIGN_LEFT);

		model_image = new Fl_Box(150, 340, 50, 50);
		Fl_JPEG_Image *orange_model = new Fl_JPEG_Image("full_orange_humanoid_meditating.jpg");
		model_image->image(orange_model);

		m_create = new Fl_Return_Button(145, 420, 120, 25, "Create");
		m_create->callback((Fl_Callback *)create_robot_modelCB, 0);

		m_cancel = new Fl_Button(270, 420, 60, 25, "Cancel");
		m_cancel->callback((Fl_Callback *)cancel_robot_modelCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return m_name->value(); }
	string model_number() { return m_model_number->value(); }
	string head() { return m_head->value(); }
	string right_arm() { return m_rarm->value(); }
	string left_arm() { return m_larm->value(); }
	string locomotor() { return m_locomotor->value(); }
	string torso() { return m_torso->value(); }
	string battery1() { return m_battery1->value(); }
	string battery2() { return m_battery2->value(); }
	string battery3() { return m_battery3->value(); }


private:
	Fl_Window *dialog;
	Fl_Input *m_name;
	Fl_Input *m_model_number;
	Fl_Input *m_head;
	Fl_Input *m_rarm;
	Fl_Input *m_larm;
	Fl_Input *m_locomotor;
	Fl_Input *m_torso;
	Fl_Input *m_battery1;
	Fl_Input *m_battery2;
	Fl_Input *m_battery3;
	Fl_Box *model_image;
	Fl_Return_Button *m_create;
	Fl_Button *m_cancel;

};

#endif // __HEADDLG_H