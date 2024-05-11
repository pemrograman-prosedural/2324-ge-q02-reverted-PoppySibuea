#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct student_t create_student(char *nim, char *nama, char *tahun, enum gender_t gender)
{
  struct student_t mhs;
  strcpy(mhs.id, nim); 
  strcpy(mhs.name, nama);
  strcpy(mhs.year, tahun);
  mhs.gender = gender; 
  return mhs;
}

void print_student(struct student_t mhs)
{
  printf("%s|%s|%s|", mhs.id, mhs.name, mhs.year);
  if (mhs.gender == GENDER_MALE)
  {
    printf("male\n");
  }
  else if (mhs.gender == GENDER_FEMALE)
  {
    printf("female\n");
  }
}

void printStudentdetails (struct student_t mhs)
{
  printf("%s|%s|%s|", mhs.id, mhs.name, mhs.year);
  if (mhs.gender == GENDER_MALE)
  {
    printf("male\n");
  }
  else if (mhs.gender == GENDER_FEMALE)
  {
    printf("female\n");
  }
}