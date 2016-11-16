#pragma once
#ifndef __HEADDLG_H
#define __HEADDLG_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_PNG_Image.H>

extern void cancel_headCB(Fl_Widget *w, void *p);
extern void create_headCB(Fl_Widget *w, void *p);

class Head_Dialog {
public:
	Head_Dialog() {
		dialog = new Fl_Window(340, 270, "Robot Head");
			h_name = new Fl_Input(120, 10, 210, 25, "Name:");
			h_name->align(FL_ALIGN_LEFT);

			h_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
			h_part_number->align(FL_ALIGN_LEFT);

			h_type = new Fl_Input(120, 70, 210, 25, "Type:");
			h_type->align(FL_ALIGN_LEFT);

			h_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
			h_weight->align(FL_ALIGN_LEFT);

			h_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
			h_cost->align(FL_ALIGN_LEFT);

			h_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
			h_description->align(FL_ALIGN_LEFT);

			head_image = new Fl_Box(120,190,50,50);
			//Fl_PNG_Image *orange_head = new Fl_PNG_Image("head_orange.png");
			//head_image->image(orange_head);

			h_create = new Fl_Return_Button(145, 320, 120, 25, "Create");
			h_create->callback((Fl_Callback *)create_headCB, 0);

			h_cancel = new Fl_Button(270, 320, 60, 25, "Cancel");
			h_cancel->callback((Fl_Callback *)cancel_headCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return h_name->value(); }
	string part_number() { return h_part_number->value(); }
	string type() { return h_type->value(); }
	string weight() { return h_weight->value(); }
	string cost() { return h_cost->value(); }
	string description() { return h_description->value(); }
	


private:
	Fl_Window *dialog;
	Fl_Input *h_name;
	Fl_Input *h_part_number;
	Fl_Input *h_type;
	Fl_Input *h_weight;
	Fl_Input *h_cost;
	Fl_Input *h_description;
	Fl_Box *head_image;
	Fl_Return_Button *h_antennae;
	Fl_Return_Button *h_create;
	Fl_Button *h_cancel;

};

#endif // __HEADDLG_H
