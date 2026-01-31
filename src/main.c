#include "./helpers/helpers.h"
#include "ex_concurreny/ex_concurrency.h"

int main(void) {
  // Cleanup the terminal.
  clear_terminal();
  new_line(2);

  // Below are the sample programs of different sections.
  c_multi_thread_atomic();
  new_line(2);

  return 0;
}
