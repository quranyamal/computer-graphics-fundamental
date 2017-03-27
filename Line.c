#include "Line.h"

Line createLine(Point p1, Point p2) {
	Line line;
	line.p1 = p1;
	line.p2 = p2;
	setColor(line.c, defColor);
	return line;
}

Line createLineColor(Point p1, Point p2, Color c) {
	Line line = createLine(p1, p2);
	setColor(line.c, c);
}

Line createPolyLine(int size, Point p[], int isOpen) {
	PolyLine poLine;
	int i;
	Point* arrPoint = (Point*) malloc(size*sizeof(Point));

	poLine.size = size;
	//poLine.p = (Point*) malloc(size*sizeof(Point));
	//poLine.p = Point[size];
	for (i=0;i<size;i++) {
		poLine.p[i].x = p[i].x;
		poLine.p[i].y = p[i].y;
	}
}