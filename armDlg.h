#pragma once
#ifndef __ARMDLG_H
#define __ARMDLG_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void cancel_armCB(Fl_Widget *w, void *p);

extern void create_armCB(Fl_Widget *w, void *p);

class Arm_Dialog {
public:
	Arm_Dialog() {
		dialog = new Fl_Window(340, 270, "Robot Arm");
		a_name = new Fl_Input(120, 10, 210, 25, "Name:");
		a_name->align(FL_ALIGN_LEFT);

		a_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		a_part_number->align(FL_ALIGN_LEFT);

		a_type = new Fl_Input(120, 70, 210, 25, "Type:");
		a_type->align(FL_ALIGN_LEFT);

		a_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		a_weight->align(FL_ALIGN_LEFT);

		a_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		a_cost->align(FL_ALIGN_LEFT);

		a_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		a_description->align(FL_ALIGN_LEFT);

		a_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		a_create->callback((Fl_Callback *)create_armCB, 0);

		a_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		a_cancel->callback((Fl_Callback *)cancel_armCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return a_name->value(); }
	string part_number() { return a_part_number->value(); }
	string type() { return a_type->value(); }
	string weight() { return a_weight->value(); }
	string cost() { return a_cost->value(); }
	string description() { return a_description->value(); }



private:
	Fl_Window *dialog;
	Fl_Input *a_name;
	Fl_Input *a_part_number;
	Fl_Input *a_type;
	Fl_Input *a_weight;
	Fl_Input *a_cost;
	Fl_Input *a_description;
	Fl_Return_Button *a_create;
	Fl_Button *a_cancel;
};
#endif // __ARMDLG_H 2016