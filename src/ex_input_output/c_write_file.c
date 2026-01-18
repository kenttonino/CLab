#include "../helpers/helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void c_write_file(void) {
  // Program description.
  printf("-----------------------------------------------");
  new_line(1);
  printf("Program: ex_input_output/c_write_file.c");
  new_line(1);
  printf("-----------------------------------------------");
  new_line(1);

  // Initialize variables.
  FILE *i_file_pointer;
  FILE *o_file_pointer;
  char *working_directory = malloc(1000);
  static char *i_file_path = "/src/ex_input_output/files/input.csv";
  static char *o_file_path = "/src/ex_input_output/files/output.csv";
  char *i_absolute_path = malloc(1000);
  char *o_absolute_path = malloc(1000);

  // Concatenate and get the absolute path of the input and output files.
  working_directory = get_cwd(working_directory);
  strcpy(i_absolute_path, working_directory);
  strcat(i_absolute_path, i_file_path);
  strcpy(o_absolute_path, working_directory);
  strcat(o_absolute_path, o_file_path);

  printf("input: %s", i_absolute_path);
  new_line(1);
  printf("output: %s", o_absolute_path);

  // Open a stream for the input and output file.
  i_file_pointer = fopen(i_absolute_path, "r");
  o_file_pointer = fopen(o_absolute_path, "w");
  if (i_file_pointer == NULL) {
    printf("Input file not found.");
    return;
  }
  if (o_absolute_path == NULL) {
    printf("Output file not found.");
    return;
  }

  // Read the character of the input file.
  // Then, write the character into the output file.
  char *input_data = malloc(1000);
  while ((input_data = fgets(input_data, 1000, i_file_pointer)) != NULL) {
    fputs(input_data, o_file_pointer);
  }

  // Close all the stream.
  fclose(i_file_pointer);
  fclose(o_file_pointer);

  // Release all the variables with memory allocated.
  free(working_directory);
  free(i_absolute_path);
  free(o_absolute_path);
  free(input_data);
}
