#include "./helpers/helpers.h"
#include "ex_concurreny/ex_concurrency.h"
#include "ex_input_output/ex_input_output.h"

int main(void) {
  // Cleanup the terminal.
  clear_terminal();
  new_line(2);

  // Below are the sample programs of different sections.
  ex_concurrency();
  new_line(2);
  ex_input_output();
  new_line(2);

  return 0;
}
