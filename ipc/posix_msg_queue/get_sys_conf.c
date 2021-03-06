#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    long mq_open_max = sysconf(_SC_MQ_OPEN_MAX);

    // return -1 and errno == 0, means no definite limit
    if (-1 == mq_open_max && 0 != errno)
    {
        printf("sysconf return -1 and errno = %d\n", errno);
        printf("MQ_OPEN_MAX == -1 means no definite limit\n");
    }

    printf("MQ_OPEN_MAX = %ld, MQ_PRIO_MAX = %ld\n", mq_open_max,
            sysconf(_SC_MQ_PRIO_MAX));

    return 0;
}
