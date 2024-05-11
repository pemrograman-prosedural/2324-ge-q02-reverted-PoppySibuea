#ifndef STUDENT_H
#define STUDENT_H

#include "gender.h"
#include "dorm.h"

struct student_t
{
    char id[12];
    char name[40];
    char year[5];
    enum gender_t gender;
    struct dorm_t *dorm;
};

void print_student(struct student_t mhs);
void printStudentdetails (struct student_t mhs);
struct student_t create_student(char *nim, char *nama, char *tahun, enum gender_t gender);
#endif

