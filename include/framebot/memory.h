#ifndef MEMORY_H
#define MEMORY_H

#include <framebot/framebot.h>

char *alloc_string(const char * str);
char *realloc_string(char *base, char *str);

char * found_str_attach(char * str);
void ffree_array_str(char **str);

#endif
