#include <stdio.h>
#include <stdlib.h>

static char static_data[16] = "I'm Static Data";
static char raw_static_data[40960];
static const char const_data[16] = "I'm Const Data";

typedef struct {
    char field[4096];
}SecurityDataStruct;

__attribute__((section(".protect"))) SecurityDataStruct g_secData;

#define IS_PROTECT_ADDRESS(ptr)  (((char *)ptr >= &__protect_start && (char *)ptr < &__protect_end) ? 1 : 0)

int main(int args,char ** argv)
{
    printf("Message In Main\n");

    return 0;
}
