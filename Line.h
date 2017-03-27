#ifndef LINE_H
#define LINE_H

#include "Point.h"

typedef struct {
	Point p1;
	Point p2;
	Color c;
} Line;

typedef struct {
	int size;
	int isOpen;
	Point p[];
} PolyLine;

Color defColor = {255,255,255,255};

/* create line with default color */
Line createLine(Point p1, Point p2);

/* create line with color c */
Line createLineColor(Point p1, Point p2, Color c);

/* create polyline with 'size' number of point, isOpen=0 for polygon */
Line createPolyLine(int size, Point p[], int isOpen);

#endif