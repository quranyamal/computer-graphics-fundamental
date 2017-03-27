#include "Point.h"

Point CreatePoint(int x, int y) {
	Point p;
	p.x = x;
	p.y = y;
	return p;
}

Color CreateColor(int r, int g, int b, int a) {
	Color c;
	c.r = r;
	c.g = g;
	c.b = b;
}

void setColor(Color color, Color colorIn) {
	color.r = colorIn.r;
	color.g = colorIn.g;
	color.b = colorIn.b;
	color.a = colorIn.a;
}