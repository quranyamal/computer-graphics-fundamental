#include "framebuffer_handler.h"
#include "screen.h"

void init_fb(){
    int         x               = 0;
    int         y               = 0;
    long int    location        = 0;

    printf("Log 1");

    // Membuka driver framebuffer
    global_fbfd = open("/dev/fb0", O_RDWR);
    if (global_fbfd == -1) {
        perror("Error: driver framebuffer tidak dapat dibuka");
        exit(1);
    }

    printf("Log 2");

    // Get fixed screen information
    if (ioctl(global_fbfd, FBIOGET_FSCREENINFO, &global_finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(global_fbfd, FBIOGET_VSCREENINFO, &global_vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    printf("Informasi Layar: %dx%d px, %dbits per pixel\n", global_vinfo.xres, 
        global_vinfo.yres, global_vinfo.bits_per_pixel);

    // Mengubah ukuran layar ke satuan bytes
    global_screensize = global_vinfo.xres * global_vinfo.yres 
                        * global_vinfo.bits_per_pixel / 8;

    // Mapping driver framebuffer ke memori
    global_fbp = (char *) mmap(0, global_screensize, PROT_READ | PROT_WRITE, 
        MAP_SHARED, global_fbfd, 0);

    if((int)global_fbp == -1){
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
}

void garbage_fb(){
    munmap(global_fbp, global_screensize);
    close(global_fbfd);
}



void setPixelColor(int x, int y, Color c){
    if((x < 0) || (x >= SCREEN_SIZE_X) || (y < 0) || (y >= SCREEN_SIZE_Y)){
        return ;
    }

    long int position = (x + global_vinfo.xoffset) * (global_vinfo.bits_per_pixel / 8) +
       (y + global_vinfo.yoffset) * global_finfo.line_length;

    if(global_vinfo.bits_per_pixel == 32){
        *(global_fbp + position) = c.b;
        *(global_fbp + position + 1) = c.g;
        *(global_fbp + position + 2) = c.r;
        *(global_fbp + position + 3) = c.a;
    }
}


///////////////////// OBSOLETE FUNCTION //////////////////////////////

/* memasukkan nilai pada titik p ke framebuffer */
// void loadDot(Point p){
//     if((p.x < 0) || (p.x >= SCREEN_SIZE_X) || (p.y < 0) || (p.y >= SCREEN_SIZE_Y)){
//         return ;
//     }

//     long int position = (p.x + global_vinfo.xoffset) * (global_vinfo.bits_per_pixel / 8) +
//        (p.y + global_vinfo.yoffset) * global_finfo.line_length;

//     if(global_vinfo.bits_per_pixel == 32){
//         *(global_fbp + position) = buffer_b[p.x][p.y];
//         *(global_fbp + position + 1) = buffer_g[p.x][p.y];
//         *(global_fbp + position + 2) = buffer_r[p.x][p.y];
//         *(global_fbp + position + 3) = buffer_a[p.x][p.y];
//     }else{                                      // assume 16 bit color
//         int b = buffer_b[p.x][p.y];
//         int g = buffer_g[p.x][p.y];
//         int r = buffer_r[p.x][p.y];
//         unsigned short int t = r<<11 | g << 5 | b;
//         *((unsigned short int*)(global_fbp + position)) = t;
//     }
// }

/* memasukkan nilai buffer ke driver */
// void loadBuffer(){
//     int i, j;

//     Point titik_sementara;
//     Color warna_sementara;
//     Color warna_kosong = {0, 0, 0, 0};
//     for(i = 0; i < SCREEN_SIZE_X; i++)
//         for(j = 0; j < SCREEN_SIZE_Y; j++){
//             titik_sementara.x = i;
//             titik_sementara.y = j;

//             if(buffer_r[i][j] && buffer_g[i][j] &&
//             buffer_b[i][j] && buffer_a[i][j]){
//                 warna_sementara.r = buffer_r[i][j];
//                 warna_sementara.g = buffer_g[i][j];
//                 warna_sementara.b = buffer_b[i][j];
//                 warna_sementara.a = buffer_a[i][j];
//             }else{
//                 warna_sementara = warna_kosong;
//             }

//             drawDot(titik_sementara, warna_sementara);
//         }
// }