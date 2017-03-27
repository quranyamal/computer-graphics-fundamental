#include "keystroke_listener.h"

void *keystrokeListener() {
	const char *dev = "/dev/input/event3";
	int fd = open(dev, O_RDONLY);

    if (fd == -1) {
    	printf("Error opning input device\n");
        exit(-1);
    }

    int listen = 1;
	printf("Keystroke listener started\n");
	while (listen == 1) {
		read(fd, &ev, sizeof ev);

		if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 2){
	        if(ev.value == 1){ // when it pressed, 0 is released
	        	printf("----%d----",ev.code);
	            switch(ev.code){
					case 30:
						printf("You pressed a\n");
						break;
					case 48:
						printf("You pressed b\n");
						break;
					case 1:
						listen = 0;
						break;
					default:
						printf("You pressed neither a nor b\n");
						break;
				}
			}
		}
	}
	printf("Keystroke listener stopped\n");
	printf("Exiting program\n");
	return NULL;
}