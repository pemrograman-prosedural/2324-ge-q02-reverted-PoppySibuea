// 12S23004 - Poppy Putri Sibuea
// 12S23020 - Rachel C.P. Simorangkir

#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv)
{
    struct dorm_t *dorms =  malloc (10 * sizeof(dorms));
    struct student_t *student =  malloc(1 * sizeof(student));
    unsigned short totalStudent;
    unsigned short totaldorm;
    char line[255];
    char delim[2] = "#";

    while (1) {
        line[0] = '\0';
        fgets(line,255, stdin);
        fflush(stdin);

        {
            int len = strlen(line);
            for (short a = 0; a < len; a++){
                if(line[a] == '\r' || line[a] == '\n'){
                    for(short b = a; b < len; b++) { line[b] = line[b + 1];
                    }
                    len--;
                    a--;
                }
            }
        }

        if ( strcmp(line, "---") == 0) break;

        else if (strcmp(line, "student-print-all") == 0){
            for (short i = 0; i<totalStudent; i++){
                print_student(student[i]);
            }
        }

        else if (strcmp(line, "dorm-print-all") == 0){
            for (short i=0; i<totaldorm; i++) {
                print_dorm(dorms[i]);
            }
        }

        else if (strcmp(line, "student-print-all-detail") == 0 ){
            for (short i=0; i<totalStudent; i++){
                printStudentdetails(student[i]);
            }
        }

        else if ( strcmp(line, "dorm-print-all-detail") == 0 ){
            for (short i=0; i<totaldorm; i++) {
                printdormdetails(dorms[i]);
            }
        }

        else {
            char *token = strtok(line, delim);

            if ( strcmp(token, "student-add") == 0){
                token = strtok(NULL, delim); char *_nim = token;
                token = strtok(NULL, delim); char *_nama = token;
                token = strtok(NULL, delim); char *_tahun = token;

                token = strtok(NULL, delim);
                if ( totalStudent > 0 ) {
                    student =  realloc(student, (totalStudent+1) * sizeof(student));
                }           
                if ( strcmp(token, "male") == 0 ) {
                    student[totalStudent] = create_student(_nim, _nama, _tahun, GENDER_MALE);
                    totalStudent++;
                }
                else if( strcmp(token, "female") == 0){
                    student[totalStudent] = create_student(_nim, _nama, _tahun, GENDER_FEMALE);
                    totalStudent++;
                }
            }

            else if ( strcmp(token, "dorm-ad") == 0 ) {
                token = strtok(NULL, delim); char *_nama = token;
                token = strtok(NULL, delim); unsigned short _kapasitas = atoi(token);
                token = strtok(NULL, delim);
                if( totaldorm > 0 ) {
                    dorms = realloc(dorms, (totaldorm+1) * sizeof(dorms));
                }
                if ( strcmp(token, "male") == 0 ) {
                    dorms[totaldorm] = create_dorm(_nim, _kapasitas, GENDER_MALE);
                    totaldorm++;
                }
                else if ( strcmp(token, "female") == 0 ){
                    dorms[totaldorm] = create_dorm(_nama, _kapasitas, GENDER_FEMALE);
                    totaldorm++;
                }
            }

            else if (strcmp(token, "assign-student") == 0 ) {
                token = strtok(NULL, delim); char *_nim = token;
                token = strtok(NULL, delim); char *dorm_nama = token;

                short studentIdx = findingStudentIdx(_nim, students, totalStudent);
                short newdormIdx = findingdormIdx(dorm_nama, dorms, totaldorm);
                char *_nama = students[studentIdx].dorm->nama;
                if(_nama != NULL) {
                    short oldormIdx = finddormUdx( _nama, dorms, totaldorm );

                    if ( studentIdx>=0 && newdormIdx>0 && oldormIdx>=0 ){
                        moveStudent(&students[studentIdx], &dorms[newdormIdx] , &dorms[oldormIdx]);
                    }
                } else {
                    assign(&students[studentIdx], &dorms[newdormIdx]);
                }
            }

            else if ( strcmp(token, "dorm-empty") == 0 ){
                token = strtok(NULL, delim);
                char = *dorm_name = token;
                short target = findormIdx(dorm_name, dorms, totaldorm);

                for (short i=0; i<totalStudent; i++) {
                    if (students[i].dorm != NULL) {
                        if (strcmp(students[i].dorm->nama, dorm_name) == 0 ){
                            unassign(&students[i], &dorms[target]);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
