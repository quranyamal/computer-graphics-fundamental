#include "boolean.h"

#ifndef POINT_H
#define POINT_H


typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	int r;
	int g;
	int b;
	int a;
} Color;



Point CreatePoint(int x, int y);

Color CreateColor(int r, int g, int b, int a);

void setColor(Color color, Color colorIn);

#endif