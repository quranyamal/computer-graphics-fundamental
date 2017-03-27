#include <math.h>
#include "Point.h"
#include "screen.h"

void drawDot(Point p, Color c){
    setPixelColor(p.x, p.y, c);
}

void drawLine(Point p0, Point p1, Color c) {
    int x0 = p0.x; int x1 = p1.x; int y0 = p0.y; int y1 = p1.y;
    int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;

    for(;;){
      Point temp = {x0, y0};
      drawDot(temp, c);
      if (x0==x1 && y0==y1) break;
      e2 = err;
      if (e2 >-dx) { err -= dy; x0 += sx; }
      if (e2 < dy) { err += dx; y0 += sy; }
    }
}


void drawPlane(Point* p, Color c, int sisi){
	int i = 0;

	for (i = 0; i < sisi-1; i++) {
		drawLine(p[i], p[i+1], c);
	}
	drawLine(p[i], p[0], c);
}

void drawCircle(Point p, int radius, Color c){
    inline void bufferDrawHorizontalLine(int x1, int x2, int y, Color c)
    {
        int i; 
        Point l;
        for (i = x1; i < x2 ; i++){
            l.x = i; l.y = y;
            drawDot(l, c);
        }
    }
    inline void plot4poin(Point p1, int x, int y, Color c)
    {
        bufferDrawHorizontalLine(p1.x - x, p1.x + x, p1.y + y,c);
        bufferDrawHorizontalLine(p1.x - x, p1.x + x, p1.y - y,c);
    }

    inline void plot8poin(Point p1, int x, int y, Color c)
    {
        plot4poin(p1, x, y, c);
        plot4poin(p1, y, x, c);
    }


    int error = -radius;
    int x = radius;
    int y = 0;

    while (x >= y)
    {
        plot8poin(p, x, y, c);

        error += y;
        y++;
        error += y;

        if (error >= 0)
        {
            error += -x;
            x--;
            error += -x;
        }
    }
}

Point getMidPoint(Point *citra, int sisi) {
  Point ans;
  int i = 0, midx = 0, midy = 0;
  for (i = 0; i < sisi; i++) {
    midx += citra[i].x;
    midy += citra[i].y;
  }
  midx /= sisi; midy /= sisi;
  ans.x = midx; ans.y = midy;
  return ans;
}

int dotDistance(Point p1, Point p2){
    double hasil;
    hasil = sqrt(((p2.x-p1.x)*(p2.x-p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));
    return hasil;
}

int is_color(Point p, Color c) {
  if ((p.x < 1) || (p.x >= SCREEN_SIZE_X) || (p.y < 1) || (p.y >= SCREEN_SIZE_Y)){
      return 1;
  }

	return buffer_r[p.x][p.y] == c.r && buffer_g[p.x][p.y] == c.g
	&& buffer_b[p.x][p.y] == c.b && buffer_a[p.x][p.y] == c.a;
}


void fillRectangle(Point p1, Point p2, Color c) {
  for (int i = p1.x; i < p2.x; i++) {
    for (int j = p1.y; j < p2.y; j++) {
      Point p = {i, j};
      drawDot(p, c);
    }
  }
}



// krn ga pake buffer jadi ga prosedur ini ga dipake

// void refreshBuffer(Point p0, Point p1){
//     Color warna_default = {25, 25, 255, 255};

//     int i, j;
//     if(p0.x < p1.x && p0.y < p1.y){
//         for(i = p0.x; i < p1.x; i++)
//             for(j = p0.y; j < p1.y; j++){
//                 buffer_r[i][j] = warna_default.r;
//                 buffer_g[i][j] = warna_default.g;
//                 buffer_b[i][j] = warna_default.b;
//                 buffer_a[i][j] = warna_default.a;
//             }

//         return;
//     }

//     if(p0.x > p1.x && p0.y < p1.y){
//         for(i = p1.x; i < p0.x; i++)
//             for(j = p0.y; j < p1.y; j++){
//                 buffer_r[i][j] = warna_default.r;
//                 buffer_g[i][j] = warna_default.g;
//                 buffer_b[i][j] = warna_default.b;
//                 buffer_a[i][j] = warna_default.a;
//             }

//         return;
//     }

//     if(p0.x > p1.x && p0.y > p1.y){
//         for(i = p1.x; i < p0.x; i++)
//             for(j = p1.y; j < p0.y; j++){
//                 buffer_r[i][j] = warna_default.r;
//                 buffer_g[i][j] = warna_default.g;
//                 buffer_b[i][j] = warna_default.b;
//                 buffer_a[i][j] = warna_default.a;
//             }

//         return;
//     }

//     if(p0.x < p1.x && p0.y > p1.y){
//         for(i = p0.x; i < p1.x; i++)
//             for(j = p1.y; j < p0.y; j++){
//                 buffer_r[i][j] = warna_default.r;
//                 buffer_g[i][j] = warna_default.g;
//                 buffer_b[i][j] = warna_default.b;
//                 buffer_a[i][j] = warna_default.a;
//             }

//         return;
//     }
// }