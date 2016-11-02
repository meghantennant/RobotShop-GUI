#include <Windows.h>
#include "view.h"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

using namespace std;

void View::draw()
{
	Fl_Box::draw();
}

bool View::saved()
{
	return !dirty;
}