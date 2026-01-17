#ifndef HELPERS_H
#define HELPERS_H
#include "get_cwd.c"
#include "clear_terminal.c"
#include "new_line.c"

extern void clear_terminal(void);
extern char* get_cwd(char *working_directory);
extern void new_line(int num_lines);

#endif
