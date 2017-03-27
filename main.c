#include <pthread.h>
#include "Point.h"
#include "framebuffer_handler.h"
#include "screen.h"
#include "drawer.h"
#include "keystroke_listener.h"

int main() {
	pthread_t keystrokeThread;
	pthread_create(&keystrokeThread, NULL, keystrokeListener, NULL);

	init_fb();
	int i, j;
	Color red = {255,0,0,255};


	for (i=1;i<SCREEN_SIZE_X;i++) {
		for (j=1;j<SCREEN_SIZE_Y;j++) {
			Point p = {i,j};
			drawDot(p, red);
		}
	}



	pthread_join(keystrokeThread, NULL);
	return 0;
}