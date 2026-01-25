#include "../helpers/helpers.h"
#include <pthread.h>

void *inside_tread(void *i) {
  pthread_t thread_i = (pthread_t)i;
  pthread_t thread_id = pthread_self();
  printf("Inside Thread Index %ld with ID = %ld", thread_i, thread_id);
  new_line(1);
  return (void *)(thread_id);
}

void c_multi_thread_sequential(void) {
  // Program description.
  printf("---------------------------------------------------");
  new_line(1);
  printf("program: ex_concurrency/c_multi_thread_sequential.c");
  new_line(1);
  printf("---------------------------------------------------");
  new_line(1);

  // Intialize variables._
  int array_size = 5;
  pthread_t *arr_thread_ids_ptr = malloc(array_size * sizeof(pthread_t));

  // Create a 5 sequential threads.
  // Print its index and ID inside the thread.
  for (pthread_t i = 0; i < 5; i++) {
    pthread_t current_thread;
    pthread_create(&current_thread, NULL, inside_tread, (void *)i);
    arr_thread_ids_ptr[i] = (pthread_t)current_thread;
    pthread_join(current_thread, NULL);
  }

  // Print the index and ID outside the thread.
  for (pthread_t i = 0; i < 5; i++) {
    pthread_t current_id = arr_thread_ids_ptr[i];
    printf("Outside Thread Index %ld with ID = %ld", i, current_id);
    new_line(1);
  }

  // Release allocated memory.
  free(arr_thread_ids_ptr);
}
