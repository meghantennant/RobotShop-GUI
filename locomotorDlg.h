#pragma once
#ifndef __LOCOMOTORDLG_H
#define __LOCOMOTOR_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void cancel_locomotorCB(Fl_Widget *w, void *p);
extern void create_locomotorCB(Fl_Widget *w, void *p);

class Locomotor_Dialog {
public:
	Locomotor_Dialog() {
		dialog = new Fl_Window(340, 430, "Robot Locomotor");
		l_name = new Fl_Input(120, 10, 210, 25, "Name:");
		l_name->align(FL_ALIGN_LEFT);

		l_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		l_part_number->align(FL_ALIGN_LEFT);

		l_type = new Fl_Input(120, 70, 210, 25, "Type:");
		l_type->align(FL_ALIGN_LEFT);

		l_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		l_weight->align(FL_ALIGN_LEFT);

		l_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		l_cost->align(FL_ALIGN_LEFT);

		l_speed = new Fl_Input(120, 160, 210, 25, "Speed:");
		l_speed->align(FL_ALIGN_LEFT);

		l_description = new Fl_Multiline_Input(120, 190, 210, 75, "Description:");
		l_description->align(FL_ALIGN_LEFT);

		locomotor_image = new Fl_Box(150, 300, 50, 50);
		Fl_PNG_Image *locomotor_orange = new Fl_PNG_Image("locomotor_orange.png");
		locomotor_image->image(locomotor_orange);

		l_create = new Fl_Return_Button(145, 400, 120, 25, "Create");
		l_create->callback((Fl_Callback *)create_locomotorCB, 0);

		l_cancel = new Fl_Button(270, 400, 60, 25, "Cancel");
		l_cancel->callback((Fl_Callback *)cancel_locomotorCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return l_name->value(); }
	string part_number() { return l_part_number->value(); }
	string type() { return l_type->value(); }
	string weight() { return l_weight->value(); }
	string cost() { return l_cost->value(); }
	string description() { return l_description->value(); }
	string speed() { return l_speed->value(); }



private:
	Fl_Window *dialog;
	Fl_Input *l_name;
	Fl_Input *l_part_number;
	Fl_Input *l_type;
	Fl_Input *l_weight;
	Fl_Input *l_cost;
	Fl_Input *l_description;
	Fl_Input *l_speed;
	Fl_Box *locomotor_image;
	Fl_Return_Button *l_create;
	Fl_Button *l_cancel;

};
#endif // __LOCOMOTOR_H 2016