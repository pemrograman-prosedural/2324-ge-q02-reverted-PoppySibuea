#ifndef DORM_H
#define DORM_H

#include "gender.h"

struct dorm_t
{
  char name[20];
  unsigned short capacity;
  enum gender_t gender;
  unsigned short residents_num;
};

struct dorm_t create_dorm(char *input);
void print_dorm(struct dorm_t dorm);
void printdormdetails (struct dorm_t dorm);
#endif