#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct doub_list_s {
  char *val;
  struct doub_list_s *prev;
  struct doub_list_s *next;
} doub_list_t;

#endif
