#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE * fp = fopen("output.txt", "w");
    fputs("Message in parent process\n", fp);
    fflush(fp);
    switch(fork()) 
    {
    case -1:
	perror("fork failed");
        return -1;
    case 0:
	fputs("Message in Child\n", fp);
        break;
    default:
	break;
    }

    fclose(fp);
    return 0;
}
