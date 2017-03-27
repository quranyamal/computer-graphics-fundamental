main: *.c *.h 
	gcc -o game main.c gambar.c glob_var_type.h rotasi.c refleksi.c framebuffer_init.c keystroke_listener.c -lm -lpthread
