#pragma once

#include <types.h>

extern int strlen(const char *str);
extern char *joinstr(const char *str1, const char *str2, char *dest);
extern void strcpy(char *dest, const char *src);
extern int streql(const char *str1, const char *str2);
extern int split_str(char *str, char separator, char **result, int max_splits);
extern char *strrchr(const char *str, int c);
extern char *strcat(char *dest, const char *src);
extern bool starts_with(const string *str, const string *prefix);
extern char* strslice(char *dest, const char *src, size_t n);