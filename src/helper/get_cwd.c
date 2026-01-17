#include <unistd.h>

char *get_cwd(char *working_directory) {
  return getcwd(working_directory, 1000);
}
