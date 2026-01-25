#include "../helpers/helpers.h"
#include <pthread.h>
#include <stdio.h>
#include <threads.h>

void *inside_thread(void *i) {
  pthread_t thread_i = (pthread_t)i;
  pthread_t thread_id = pthread_self();
  printf("Inside Thread Index %ld with ID = %ld", thread_i, thread_id);
  new_line(1);
  return (void *)(thread_id);
}

void c_multi_thread_nonsequential(void) {
  // Program description.
  printf("---------------------------------------------------");
  new_line(1);
  printf("program: ex_concurrency/c_multi_thread_nonsequential.c");
  new_line(1);
  printf("---------------------------------------------------");
  new_line(1);

  // Initialize and declare variables.
  int arr_size = 5;
  pthread_t *arr_thread_ids_ptr = malloc(arr_size * sizeof(pthread_t));

  // Create a 5 nonsequential threads.
  for (pthread_t i = 0; i < 5; i++) {
    pthread_t current_thread;
    pthread_create(&current_thread, NULL, inside_thread, (void *)i);
    arr_thread_ids_ptr[i] = current_thread;
    pthread_cancel(current_thread);
  }

  // Print the array thread IDs outside of thread.
  for (int i = 0; i < 5; i++) {
    printf("Outside Thread Index %d with ID = %ld", i, arr_thread_ids_ptr[i]);
    new_line(1);
  }

  // Release the allocated memory.
  free(arr_thread_ids_ptr);
}
