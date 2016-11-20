#pragma once
#ifndef __CUSTOMERDLG_H
#define __CUSTOMERDLG_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void create_customerCB(Fl_Widget *w, void *p);
extern void cancel_customerCB(Fl_Widget *w, void *p);

class Customer_Dialog {
public:
	Customer_Dialog() {
		dialog = new Fl_Window(340, 270, "Customer");
		c_name = new Fl_Input(120, 10, 210, 25, "Name:");
		c_name->align(FL_ALIGN_LEFT);

		c_number = new Fl_Input(120, 40, 210, 25, "Phone Number:");
		c_number->align(FL_ALIGN_LEFT);

		c_email = new Fl_Input(120, 70, 210, 25, "Email:");
		c_email->align(FL_ALIGN_LEFT);

		c_wallet = new Fl_Input(120, 100, 210, 25, "Wallet Amount:");
		c_wallet->align(FL_ALIGN_LEFT);

		c_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		c_create->callback((Fl_Callback *)create_customerCB, 0);

		c_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		c_cancel->callback((Fl_Callback *)cancel_customerCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return c_name->value(); }
	string customer_number() { return c_number->value(); }
	string email() { return c_email->value(); }
	string wallet() { return c_wallet->value(); }


private:
	Fl_Window *dialog;
	Fl_Input *c_name;
	Fl_Input *c_number;
	Fl_Input *c_email;
	Fl_Input *c_wallet;
	Fl_Return_Button *c_create;
	Fl_Button *c_cancel;
};
#endif //__CUSTOMERDLG_H 2016
