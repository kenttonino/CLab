#include "../helpers/helpers.h"
#include <pthread.h>
#include <stdio.h>

void *func_inside_thread(void *x) {
  pthread_t xi = (pthread_t)x;
  printf("inside thread: x = %ld \n", xi);
  return (void *)(xi + 123);
}

void c_basic_thread(void) {
  // program description.
  printf("-----------------------------------------------");
  new_line(1);
  printf("program: ex_concurrency/c_basic_thread.c");
  new_line(1);
  printf("-----------------------------------------------");
  new_line(1);

  // Initialized the thread variable and instances.
  // Create the thread. And just print the parameters.
  pthread_t th;
  pthread_create(&th, NULL, func_inside_thread, (void *)200);

  // Get the return of the paramater.
  // Print the result outside of the thread.
  void *ret_from_thread;
  pthread_t ri;
  pthread_join(th, &ret_from_thread);
  ri = (pthread_t)ret_from_thread;

  new_line(1);
  printf("outside thread, which returned %ld.", ri);
  new_line(1);
  printf("Sizeof th: %ld", sizeof(th));
  new_line(1);
  printf("Sizeof ret_from_thread: %ld", sizeof(ret_from_thread));
}
