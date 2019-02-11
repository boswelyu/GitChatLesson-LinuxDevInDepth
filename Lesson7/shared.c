#include <stdio.h>

static int static_val;
extern int extern_val;
int global_val;

extern void external();

static void internal() {
    static_val = 0x11223344;
}

void sharefunc(int caller) {
    internal();
    extern_val = 0x55667788;
    global_val = 0x99AABBCC;
    external();
}