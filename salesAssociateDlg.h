#pragma once
#ifndef __SALESASSOCIATEDLG_H
#define __SALESASSOCIATE_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void create_sales_associateCB(Fl_Widget *w, void *p);
extern void cancel_sales_associateCB(Fl_Widget *w, void *p);

class Sales_Associate_Dialog {
public:
	Sales_Associate_Dialog() {
		dialog = new Fl_Window(360, 150, "Sales Associate");
		s_name = new Fl_Input(130, 10, 210, 25, "Name:");
		s_name->align(FL_ALIGN_LEFT);

		s_number = new Fl_Input(130, 40, 210, 25, "Employee Number:");
		s_number->align(FL_ALIGN_LEFT);

		s_create = new Fl_Return_Button(145, 120, 120, 25, "Create");
		s_create->callback((Fl_Callback *)create_sales_associateCB, 0);

		s_cancel = new Fl_Button(270, 120, 60, 25, "Cancel");
		s_cancel->callback((Fl_Callback *)cancel_sales_associateCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return s_name->value(); }
	string employee_number() { return s_number->value(); }


private:
	Fl_Window *dialog;
	Fl_Input *s_name;
	Fl_Input *s_number;
	Fl_Return_Button *s_create;
	Fl_Button *s_cancel;
};
#endif //__SALESASSOCIATEDLG_H 2016

