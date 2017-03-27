#ifndef KEYSTROKE_LISTENER_H
#define KEYSTROKE_LISTENER_H

#include <stdio.h>
#include <unistd.h>
#include <linux/input.h>
#include <fcntl.h>

struct input_event ev;

void *keystrokeListener();

#endif