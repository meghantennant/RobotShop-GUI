#pragma once
#ifndef __VIEW_H
#define __VIEW_H 2016
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
using namespace std;

class View : public Fl_Box {
	bool dirty = false;

public:
	View(int X, int Y, int W, int H)
		: Fl_Box(X, Y, W, H) {}
	void draw() override;
	bool saved();


};
#endif //VIEW_H
