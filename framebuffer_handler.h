#ifndef FRAMEBUFFER_HANDLER_H
#define FRAMEBUFFER_HANDLER_H

#include <stdio.h>		// printf()
#include <stdlib.h>		// exit(), usleep()
#include <unistd.h>		// close(), usleep()

// Framebuffer dependencies library
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#include "Point.h"
#include "screen.h"

// Variabel Statis Global
extern struct fb_var_screeninfo    global_vinfo;
extern struct fb_fix_screeninfo    global_finfo;
extern long int                    global_screensize;
extern int                         global_fbfd;
extern char                        *global_fbp;

/* Deklarasi awal variabel statis global */
struct fb_var_screeninfo    global_vinfo;
struct fb_fix_screeninfo    global_finfo;
long int                    global_screensize;
int                         global_fbfd;
char                        *global_fbp;

unsigned char buffer_r[SCREEN_SIZE_X][SCREEN_SIZE_Y];
unsigned char buffer_g[SCREEN_SIZE_X][SCREEN_SIZE_Y];
unsigned char buffer_b[SCREEN_SIZE_X][SCREEN_SIZE_Y];
unsigned char buffer_a[SCREEN_SIZE_X][SCREEN_SIZE_Y];


/* inisialisasi terhadap lima variabel statis global diatas */
void init_fb();

/* delokasi dan variabel statis diatas dan deattach hal-hal yang dibutuhkan */
void garbage_fb();

/* mengganti nilai pixel dengan posisi x,y (dari kiri atas) pada buffer dengan warna c */
void setPixelColor(int x, int y, Color c);


// GA PAKE LAGI KARNA SKRN LANGUSNG DRAW KE FRAMEBUFFER /////////////////////
/* memasukkan nilai buffer ke driver */
// void loadBuffer();

#endif