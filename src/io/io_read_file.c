#include "../helper/helper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * A sample program that reads a file and print in the console.
 * */
void io_read_file(void) {
  FILE *input_file_pointer;
  char *working_directory = malloc(1000);

  // Concatenate the working directory and file path.
  working_directory = get_cwd(working_directory);
  char *file_path = "/src/io/files/input.csv";
  char *absolute_file_path = malloc(1000);
  strcpy(absolute_file_path, working_directory);
  strcat(absolute_file_path, file_path);

  // Read the input file.
  input_file_pointer = fopen(absolute_file_path, "r");
  if (input_file_pointer == NULL) {
    printf("File not found.");
    return;
  }

  // Read a character from the stream (input_file_pointer).
  // Output the result in stdout.
  char character;
  while ((character = fgetc(input_file_pointer)) != EOF) {
    putchar(character);
  }

  // Close the stream (input_file_pointer);
  fclose(input_file_pointer);

  // Release all the allocated memories.
  free(working_directory);
  free(absolute_file_path);
}
