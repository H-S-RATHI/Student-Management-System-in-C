#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void addstudent();
void studentrecord();
void searchstudent();
void delete();

struct student{
    char first_name[20];
    char last_name[20];
    int roll_no;
    char class[20];
    char vill[30];
    float per;
};

int main(){
    int choice;
    while(choice != 5){
        printf("\n\n\n\t\t\t\t=======STUDENT MANAGEMENT SYSTEM=======\n\n\n");
        printf("\t\t\t\t\t 1. ADD STUDENT\n");
        printf("\t\t\t\t\t 2. STUDENT RECORD\n");
        printf("\t\t\t\t\t 3. SEARCH STUDENT\n");
        printf("\t\t\t\t\t 4. DELETE STUDENT\n\n");
        printf("\t\t\t\t\t 5.--------EXIT----------\n\n\n");
        printf("\t\t\t\t\t= Enter your Choice->");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                addstudent();
                system("cls");
                break;

            case 2:
                studentrecord();
                printf("\n\t\t\t\t Press any key to exit\n\n");
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                searchstudent();
                printf("\n\t\t\t\t Press any key to exit\n\n");
                getch();
                system("cls");
                break;

            case 4:
                system("cls");
                delete();
                printf("\n\t\t\t\t Press any key to exit\n\n");
                getch();
                system("cls");
                break;


        }
    }
}

void addstudent(){
    char another;
    FILE *fp;
    struct student info;

    do{
    system("cls");
       printf(" \t\t\t\t====ADD STUDENT INFO====\n\n\n");
        fp = fopen("student_info.txt", "a");
        printf("\n\t\t\t\tENTER THE FIRST NAME: ");
        scanf("%s", info.first_name);
        printf("\n\t\t\t\tENTER THE LAST NAME : ");
        scanf("%s", info.last_name);
        printf("\n\t\t\t\tENTER THE Rollno : ");
        scanf("%d", &info.roll_no);
        printf("\n\t\t\t\tENTER THE CLASS     : ");
        scanf("%s", info.class);
        printf("\n\t\t\t\tENTER THE ADDRESS   : ");
        scanf("%s", info.vill);
        printf("\n\t\t\t\tENTER THE PERCENTAGE: ");
        scanf("%f", &info.per);

        if (fp == NULL){
            fprintf(stderr, "\n\t\t\t\tCAN'T OPEN FILE\n");
        }else{
            printf("\n\t\t\t\tRECORD STORED SUCCESSFULLY\n");
        }
        fwrite(&info, sizeof(struct student), 1, fp);
        fclose(fp);

        printf("\t\t\t\tDO YOU WANT TO ADD ANOTHER RECORD? (Y/N): ");
        scanf(" %c", &another);

    } while (another == 'y' || another=='Y');
}
    

void studentrecord(){
    FILE *fp;
    struct student info;
    fp=fopen("student_info.txt","r");
    system("cls");
    printf(" \n\n\t\t\t\t====STUDENT RECORD====\n\n\n");

    if(fp==NULL){
        fprintf(stderr,"\t\t\t\tCAN'T OPEN FILE\n");
    }else{
        printf("\t\t\t\t\t   Records\n");
        printf("\t\t\t\t____________________________\n\n");
    }
    while(fread(&info,sizeof(struct student),1,fp)){
        printf("\n\t\t\t\tStudent name   : %s %s ", info.first_name, info.last_name);
        printf("\n\t\t\t\tRoll number    : %d ",info.roll_no);
        printf("\n\t\t\t\tClass          : %s ",info.class);
        printf("\n\t\t\t\tAddress        : %s ",info.vill);
        printf("\n\t\t\t\tPercentage     : %f ",info.per);
        printf("\n\t\t\t\t_______________________________");

    }
    fclose(fp);
    getch();
    }


void searchstudent(){
        FILE *fp;
        struct student info;
        int roll_no,found=0;
        fp=fopen("student_info.txt","r");
        system("cls");
        printf(" \n\n\t\t\t\t====SEARCH STUDENT====\n\n\n");
        printf("\t\t\t\t ENTER THE ROLL NO. :");
        scanf("%d",&roll_no);

        while(fread(&info,sizeof(struct student),1,fp)){
            if(info.roll_no==roll_no){
                found=1;
            printf("\n\t\t\t\tStudent name   : %s %s ", info.first_name, info.last_name);
            printf("\n\t\t\t\tRoll number    : %d ",info.roll_no);
            printf("\n\t\t\t\tClass          : %s ",info.class);
            printf("\n\t\t\t\tAddress        : %s ",info.vill);
            printf("\n\t\t\t\tPercentage     : %f ",info.per);
            printf("\n\t\t\t\t_______________________________");

    }
        }
        if(!found){
            printf("\t\t\t\tRecord not found");
        }
    fclose(fp);
    getch();

    }

void delete() {
    FILE *fp, *fp1;
    struct student info;
    int roll_no, found = 0;

    fp = fopen("student_info.txt", "r");
    fp1 = fopen("temp.txt", "w");

    system("cls");
    printf(" \n\n\t\t\t\t====DELETE STUDENT====\n\n\n");
    printf("\t\t\t\t\t ENTER THE ROLL NO.: ");
    scanf("%d", &roll_no);

    if (fp == NULL) {
        fprintf(stderr, "\t\t\t\t CAN'T OPEN FILE\n");
    } else {
        while (fread(&info, sizeof(struct student), 1, fp)) {
            if (info.roll_no == roll_no) {
                found = 1;
            } else {
                fwrite(&info, sizeof(struct student), 1, fp1);
            }
        }
        fclose(fp);
        fclose(fp1);

        if (found) {
            remove("student_info.txt");
            rename("temp.txt", "student_info.txt");
            printf("\t\t\t\t RECORD DELETED SUCCESSFULLY\n");
        } else {
            remove("temp.txt");
            printf("\t\t\t\t RECORD NOT FOUND\n");
        }
    }

    getch();
}
