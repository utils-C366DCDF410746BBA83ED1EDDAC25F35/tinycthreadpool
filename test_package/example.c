#include <threadpool.h>
#include <tinycthread.h>
#include <stdio.h>

int main(void) {
  threadpool_t *threadpool = threadpool_create(3, 5, 0);

  threadpool_destroy(threadpool, threadpool_graceful);
  return 0;
}