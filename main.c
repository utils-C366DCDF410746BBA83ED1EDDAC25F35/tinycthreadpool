#include "src/threadpool.h"
#include "src/tinycthread.h"
#include <stdio.h>

void sleep(long milliseconds) {
    long seconds = milliseconds / 1000;
    long nanoseconds = milliseconds % 1000 * 1000000;
    thrd_sleep(&(struct timespec) {.tv_sec=seconds, .tv_nsec=nanoseconds}, NULL);
}

void run(void *data) {
    thrd_t current = thrd_current();

    for (int i = 0; i < 10; ++i) {
        printf("[%#x] %d\n", current, i);
        sleep(1000);
    }
}

int main(void) {

    threadpool_t *threadpool = threadpool_create(3, 5, 0);

    for (int i = 0; i < 10; ++i) {
        sleep(500);
        int result = threadpool_add(threadpool, run, NULL, 0);
        printf("Add task result: %d\n", result);
    }


    return 0;
}