#include "c_basic_thread.c"
#include "c_multi_thread_sequential.c"

/*
 * Below are the sample concurrency programs.
 * */
void ex_concurrency(void) {
  c_basic_thread();
  new_line(2);
  c_multi_thread_sequential();
  new_line(2);
}
