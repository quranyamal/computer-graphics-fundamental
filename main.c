#include "gambar.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "keystroke_listener.h"

void drawObjects();		//menggambar tembakan dan objekTabrak ke buffer
void *preUpdate();		//(1)cek inputuser
void update();	//(1)ubah posisi. (2)spawnObjek, (3)drawBuffer
void postUpdate();	 	//(1)cek kolisi, (2)loadbuffer ke layar
int fd;

int main()
{
//**setup-pendengar-keyboard********************************************************************
	// Input keyboard device file
    //const char *dev = "/dev/input/by-id/usb-_USB_Keyboard-event-kbd";
    const char *dev = "/dev/input/event3";
    //const char *dev = "/dev/input/by-id/usb-_USB_Keyboard-event-kbd";
    // Open device for reference
    fd = open(dev, O_RDONLY);

    // Check if device is opened
    if (fd == -1) {
        fprintf(stderr, "Cannot open %s: %s.\n", dev, strerror(errno));
        return EXIT_FAILURE;
    }

// *setup-pendengar-keyboard v2, if2an nya ada di keystroke_listener.c
	//pthread_t keystrokeThread;
	//pthread_create(&keystrokeThread, NULL, keystrokeListener, NULL);

//**setup-objek-game****************************************************************************
	init_fb();

	warna c = {255,255,255,255};
	warna bound = {10,10,10,10};

	titik pl0 = {0,0};
	titik pl1 = {700,400};

	refreshBuffer(pl0,pl1);

	loadBuffer();
	//pthread_join(keystrokeThread, NULL);
	return 0;
}


void drawObjects()
{

}

void update()
{

}


void *preUpdate()
{
	
}
