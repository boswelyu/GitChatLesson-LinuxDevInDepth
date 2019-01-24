#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char static_data[16] = "I'm Static Data";
static char raw_static_data[40960];
static const char const_data[16] = "I'm Const Data";

int main(int args,char ** argv)
{
    printf("Message In Main\n");

    int BLOCK_SIZE = 1024 * 1024 * 100;
    char * ptr = (char *)malloc(BLOCK_SIZE);
    memset(ptr, 0, BLOCK_SIZE);

    while(1) sleep(1);

    return 0;
}
