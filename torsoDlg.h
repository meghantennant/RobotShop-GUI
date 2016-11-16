#pragma once
#ifndef __TORSDLG_H
#define __TORSODLG_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void cancel_torsoCB(Fl_Widget *w, void *p);
extern void create_torsoCB(Fl_Widget *w, void *p);

class Torso_Dialog {
public:
	Torso_Dialog() {
		dialog = new Fl_Window(340, 270, "Robot Torso");
		t_name = new Fl_Input(120, 10, 210, 25, "Name:");
		t_name->align(FL_ALIGN_LEFT);

		t_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		t_part_number->align(FL_ALIGN_LEFT);

		t_type = new Fl_Input(120, 70, 210, 25, "Type:");
		t_type->align(FL_ALIGN_LEFT);

		t_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		t_weight->align(FL_ALIGN_LEFT);

		t_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		t_cost->align(FL_ALIGN_LEFT);

		t_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		t_description->align(FL_ALIGN_LEFT);

		t_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		t_create->callback((Fl_Callback *)create_torsoCB, 0);

		t_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		t_cancel->callback((Fl_Callback *)cancel_torsoCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return t_name->value(); }
	string part_number() { return t_part_number->value(); }
	string type() { return t_type->value(); }
	string weight() { return t_weight->value(); }
	string cost() { return t_cost->value(); }
	string description() { return t_description->value(); }



private:
	Fl_Window *dialog;
	Fl_Input *t_name;
	Fl_Input *t_part_number;
	Fl_Input *t_type;
	Fl_Input *t_weight;
	Fl_Input *t_cost;
	Fl_Input *t_description;
	Fl_Return_Button *t_create;
	Fl_Button *t_cancel;
};
#endif // __TORSODLG_H 2016
