#include <stdio.h>
#include "./libs/dorm.h"
#include "./libs/student.h"
#include "./libs/gender.h"
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv)
{
    char input[100];
    char kalimat[100];
    char command[50];

    char mhs_id[10];
    char mhs_name[25];
    char mhs_year[5];
    char mhs_gender[8];
    unsigned short int ang_gender;

    struct student_t *mhs = malloc(50 * sizeof(struct student_t));
    struct dorm_t *dorms = malloc(50 * sizeof(struct dorm_t));

    unsigned short int stop = 0;

    unsigned short int prt_std = 0;
    unsigned short int prt_dorm = 0;

    while (stop != 1)
    {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\r\n")] = 0;
        strcpy(kalimat, input);

        strcpy(command, strtok(kalimat, "#"));
        if (strcmp(command, "student-add") == 0)
        {
            strcpy(mhs_id, strtok(NULL, "#"));
            strcpy(mhs_name, strtok(NULL, "#"));
            strcpy(mhs_year, strtok(NULL, "#"));
            strcpy(mhs_gender, strtok(NULL, "#"));

            if (strcmp(mhs_gender, "male") == 0)
            {
                ang_gender = GENDER_MALE;
            }
            else if (strcmp(mhs_gender, "female") == 0)
            {
                ang_gender = GENDER_FEMALE;
            }

            mhs[prt_std] = create_student(mhs_id, mhs_name, mhs_year, ang_gender);
            prt_std++;
        }
        else if (strcmp(command, "student-print-all-detail") == 0)
        {
            student_print_detail(mhs, prt_std);
        }
        else if (strcmp(command, "dorm-add") == 0)
        {
            strcpy(mhs_id, strtok(NULL, "#"));

            unsigned short int capacity;
            strcpy(mhs_year, strtok(NULL, "#"));
            capacity = atoi(mhs_year);

            strcpy(mhs_gender, strtok(NULL, "#"));

            if (strcmp(mhs_gender, "male") == 0)
            {
                ang_gender = GENDER_MALE;
            }
            else if (strcmp(mhs_gender, "female") == 0)
            {
                ang_gender = GENDER_FEMALE;
            }

            dorms[prt_dorm] = create_dorm(mhs_id, capacity, ang_gender);
            prt_dorm++;
        }
        else if (strcmp(command, "dorm-print-all-detail") == 0)
        {
            print_all_dorm(dorms, prt_dorm);
        }
        else if (strcmp(command, "assign-student") == 0)
        {
            strcpy(mhs_id, strtok(NULL, "#"));
            strcpy(mhs_name, strtok(NULL, "#"));

            int poin_std = -1;
            int poin_drm = -1;

            for (int x = 0; x < prt_std; x++)
            {
                if (strcmp(mhs[x].id, mhs_id) == 0)
                {
                    poin_std = x;
                    break;
                }
            }
            for (int x = 0; x < prt_dorm; x++)
            {
                if (strcmp(dorms[x].name, mhs_name) == 0)
                {
                    poin_drm = x;
                    break;
                }
            }
            if (poin_std != -1 && poin_drm != -1)
            {
                assign_student(&mhs[poin_std], &dorms[poin_drm], mhs_id, mhs_name);
            }
            else
            {
                printf("Mahasiswa atau asrama tidak ditemukan.\n");
            }
        }
        else if (strcmp(command, "move-student") == 0)
        {
            strcpy(mhs_id, strtok(NULL, "#"));
            strcpy(mhs_name, strtok(NULL, "#"));

            int poin_std = -1;
            int poin_drm = -1;

            for (int x = 0; x < prt_std; x++)
            {
                if (strcmp(mhs[x].id, mhs_id) == 0)
                {
                    poin_std = x;
                    break;
                }
            }
            for (int x = 0; x < prt_dorm; x++)
            {
                if (strcmp(dorms[x].name, mhs_name) == 0)
                {
                    poin_drm = x;
                    break;
                }
            }
            if (poin_std != -1 && poin_drm != -1)
            {
                move_student(&mhs[poin_std], &dorms[poin_drm], NULL, mhs_id, mhs_name);
            }
            else
            {
                printf("Mahasiswa atau asrama tidak ditemukan.\n");
            }
        }
        else if (strcmp(command, "dorm-empty") == 0)
        {
            strcpy(mhs_name, strtok(NULL, "#"));
            for (int x = 0; x < prt_dorm; x++)
            {
                if (strcmp(dorms[x].name, mhs_name) == 0)
                {
                    empty_dorm(&dorms[x]);
                    break;
                }
            }
        }
        else if (strcmp(command, "---") == 0)
        {
            stop = 1;
        }
    }

    free(mhs);
    free(dorms);
    return 0;
}
