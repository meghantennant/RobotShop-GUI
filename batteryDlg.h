#pragma once
#ifndef __BATTERYDLG_H
#define __BATTERYDLG_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void cancel_batteryCB(Fl_Widget *w, void *p);
extern void create_batteryCB(Fl_Widget *w, void *p);

class Battery_Dialog {
public:
	Battery_Dialog() {
		dialog = new Fl_Window(340, 400, "Robot Battery");
		b_name = new Fl_Input(120, 10, 210, 25, "Name:");
		b_name->align(FL_ALIGN_LEFT);

		b_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		b_part_number->align(FL_ALIGN_LEFT);

		b_type = new Fl_Input(120, 70, 210, 25, "Type:");
		b_type->align(FL_ALIGN_LEFT);

		b_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		b_weight->align(FL_ALIGN_LEFT);

		b_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		b_cost->align(FL_ALIGN_LEFT);

		b_power = new Fl_Input(120, 160, 210, 25, "Power:");
		b_power->align(FL_ALIGN_LEFT);

		b_energy = new Fl_Input(120, 190, 210, 25, "Energy:");
		b_energy->align(FL_ALIGN_LEFT);

		b_description = new Fl_Multiline_Input(120, 220, 210, 75, "Description:");
		b_description->align(FL_ALIGN_LEFT);

		battery_image = new Fl_Box(50, 300, 50, 50);
		Fl_PNG_Image *yellow_battery = new Fl_PNG_Image("battery_yellow.png");
		battery_image->image(yellow_battery);

		b_create = new Fl_Return_Button(145, 370, 120, 25, "Create");
		b_create->callback((Fl_Callback *)create_batteryCB, 0);

		b_cancel = new Fl_Button(270, 370, 60, 25, "Cancel");
		b_cancel->callback((Fl_Callback *)cancel_batteryCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return b_name->value(); }
	string part_number() { return b_part_number->value(); }
	string type() { return b_type->value(); }
	string weight() { return b_weight->value(); }
	string cost() { return b_cost->value(); }
	string energy() { return b_energy->value(); }
	string power() { return b_power->value(); }
	string description() { return b_description->value(); }



private:
	Fl_Window *dialog;
	Fl_Input *b_name;
	Fl_Input *b_part_number;
	Fl_Input *b_type;
	Fl_Input *b_weight;
	Fl_Input *b_cost;
	Fl_Input *b_power;
	Fl_Input *b_energy;
	Fl_Input *b_description;
	Fl_Box *battery_image;
	Fl_Return_Button *b_create;
	Fl_Button *b_cancel;

};
#endif //BATTERYDLG_H 2016
