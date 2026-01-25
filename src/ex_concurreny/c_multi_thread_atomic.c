#include "../helpers/helpers.h"
#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>

struct inner_thread_arg {
  pthread_t i;
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
  _Atomic int *counter = malloc(sizeof(_Atomic int));
  int arr_size = 5;
  pthread_t *arr_pthread_ids_ptr = malloc(arr_size * sizeof(pthread_t));
  struct inner_thread_arg args;

  for (pthread_t i = 0; i < arr_size; i++) {
    args.i = i;
    pthread_t current_thread;
    pthread_create(&current_thread, NULL, inner_thread, &args);
  }

  printf("Counter = %d", *counter);

  // Release the memory allocated.
  free(arr_pthread_ids_ptr);
  free(counter);
}
