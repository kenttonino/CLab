/*
 * This function implemented a sample usage
 * of _Atomic typename. The variable is passed
 * as value for struct inner_thread_arg which
 * will be incremented inside the thread using
 * the atomic_fetch_add. That incremented variable,
 * will be accessed again outside the thread.
 *
 * */

#include "../helpers/helpers.h"
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>

struct inner_thread_arg {
  int i;
  _Atomic int c;
};

void *inner_thread(void *arguments) {
  struct inner_thread_arg *args = arguments;
  pthread_t thread_i = (pthread_t)args->i;
  pthread_t thread_id = pthread_self();
  atomic_fetch_add(&args->c, 1);
  printf("Inside Thread Index = %ld, ID = %ld", thread_i, thread_id);
  new_line(1);
  return (void *)(thread_id);
}

void c_multi_thread_atomic(void) {
  // Program description.
  printf("-------------------------------------------------------");
  new_line(1);
  printf("program: ex_concurrency/c_multi_thread_atomic.c");
  new_line(1);
  printf("-------------------------------------------------------");
  new_line(1);

  // Declare and initialize a variable.
  _Atomic int counter = 0;
  int arr_size = 5;
  struct inner_thread_arg args;

  for (pthread_t i = 0; i < arr_size; i++) {
    args.i = i;
    args.c = counter;
    pthread_t current_thread;
    pthread_create(&current_thread, NULL, inner_thread, &args);
    pthread_join(current_thread, NULL);
    counter = args.c;
  }

  printf("Counter = %d", counter);
  new_line(1);
  printf("Size of args: %ld", sizeof(args));
  new_line(1);
  printf("Size of args.i: %ld", sizeof(args.i));
  new_line(1);
  printf("Size of args.c: %ld", sizeof(args.c));
  new_line(1);
  // Release the memory allocated.
}
