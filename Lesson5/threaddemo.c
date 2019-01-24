#include <stdio.h>
#include <pthread.h>

#define LOOP_COUNT   1000000
int glob_value = 0;
    
void * thread_func(void * args)
{
    int counter = 0;
    while(counter++ < LOOP_COUNT)
    {
        int local = glob_value;
        local++;
        glob_value = local;
    }
}

int main(int argc, char * argv[])
{
    pthread_t threads[10];

    int ret = 0;
    for(int i = 0; i < 10; i++)
    {
        ret = pthread_create(&threads[i], NULL, thread_func, NULL);
        if(ret != 0)
        {
            printf("pthread_create failed, index: %d\n", i);
            continue;
        }
    }
    
    for(int i = 0; i < 10; i++)
    {
        ret = pthread_join(threads[i], NULL);
        if(ret != 0)
        {
            printf("pthread_join failed, index: %d\n", i);
            continue;
        }
    }

    printf("glob_value: %d\n", glob_value);

    return 0;
}
