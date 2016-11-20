#pragma once
#ifndef __ORDERDLG_H
#define __ORDERDLG_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>

extern void cancel_orderCB(Fl_Widget *w, void *p);
extern void create_orderCB(Fl_Widget *w, void *p);

class Order_Dialog {
public:
	Order_Dialog() {
		dialog = new Fl_Window(340, 400, "Robot Order");
		o_number = new Fl_Input(120, 10, 210, 25, "Order Number:");
		o_number->align(FL_ALIGN_LEFT);

		o_model = new Fl_Input(120, 40, 210, 25, "Model Number:");
		o_model->align(FL_ALIGN_LEFT);

		o_customer = new Fl_Input(120, 70, 210, 25, "Customer:");
		o_customer->align(FL_ALIGN_LEFT);

		o_sales_associate = new Fl_Input(120, 100, 210, 25, "Sales Associate:");
		o_sales_associate->align(FL_ALIGN_LEFT);

		o_create = new Fl_Return_Button(145, 370, 120, 25, "Create");
		o_create->callback((Fl_Callback *)create_orderCB, 0);

		o_cancel = new Fl_Button(270, 370, 60, 25, "Cancel");
		o_cancel->callback((Fl_Callback *)cancel_orderCB, 0);
		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string number() { return o_number->value(); }
	string model() { return o_model->value(); }
	string customer() { return o_customer->value(); }
	string sales_associate() { return o_sales_associate->value(); }



private:
	Fl_Window *dialog;
	Fl_Input *o_number;
	Fl_Input *o_model;
	Fl_Input *o_customer;
	Fl_Input *o_sales_associate;
	Fl_Return_Button *o_create;
	Fl_Button *o_cancel;

};
#endif //ORDERDLG_H 2016
