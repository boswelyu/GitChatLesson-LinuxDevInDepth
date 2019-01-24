#include <stdio.h>
#include <stdlib.h>

static char static_data[16] = "I'm Static Data";
static char raw_static_data[40960];
static const char const_data[16] = "I'm Const Data";

int main(int args,char ** argv)
{
    printf("Message In Main\n");

    return 0;
}