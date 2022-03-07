#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void addstudent();
void searchstudent();
void studentrecord();
void delete();
void library();
struct student {
    char first_name[20];
    char last_name[20];
    int roll_no;
    char Class[10];
     char vill[20];
    float per;
};


void  main(){
    char s[20]={"abc"},s1[20];
int value=0,ch;
printf("\t\t\t\t*************Password protected**************\n\n\n");
printf("\n\t\t\t\tEnter the password:");
gets(s1);
value=strcmp(s,s1);
if(value==0)
    {
        printf("\n\t\t\t\tLogin Succesfully\n");
        system("cls");

       while(ch!=5)
        {
        printf("\t\t\t====Quantum University Management System====\n\n\n");
        printf("\n\n\n\t\t\t\t  1.Add Students");
        printf("\n\t\t\t 2.Student Record");
         printf("\n\t\t\t 3.Search Student");
        printf("\n\t\t\t 4.Delete Record");
        printf("\n\t\t\t 5.Library");
        printf("\n\t\t\t 6.Exit");
        printf("\t\t\t\t    _____________________\n");
    printf("\t\t\t\t     ");
    scanf("%d",&ch);

   switch(ch){
       case 1:
system("cls");
system("cls");
        addstudent();
system("cls");
         break;
     case 2:
         system("cls");

          studentrecord();
          system("cls");
          printf("\t\t\t\t  press any key to exit..... \n");

         break;

     case 3:
         system("cls");

         searchstudent();
         system("cls");
         printf("\n\t\t\t\t  Press any key to exit.......\n");


         break;

     case 4:
system("cls");
        delete();
        system("cls");
        printf("\n\t\t\t\tPress any key to exit.......\n");

               break;
     case 5:
system("cls");
system("cls");
quantumlibrary();
 printf("\n\t\t\t\tPress any key to exit.......\n");

               break;
     case 6:
        system("cls");
          printf("\n\t\t\t\tThank you, for used this software.\n\n");
          exit(0);
        break;

     default :


         printf("\n\t\t\t\t\tEnter a valid number\n\n");
         printf("\t\t\t\tPress any key to continue.......");


         break;
        }

        }
}


    else
    {
        printf("\n\t\t\t\tWrong password\n");
    }
}
 void addstudent(){

     char another;
     FILE *fp;
     int n,i;
     struct student info;
   do{

       printf("\t\t\t\t=======Add Students Info=======\n\n\n");
       fp=fopen("information.txt","a"); //use can give any file name. Give the name with extention or without extention.

        printf("\n\t\t\tEnter First Name     : ");
          scanf("%s",&info.first_name);
          printf("\n\t\t\tEnter Last Name     : ");
          scanf("%s",&info.last_name);
          printf("\n\t\t\tEnter Roll-No       : ");
          scanf("%d",&info.roll_no);
          printf("\n\t\t\tEnter Class(course) : ");
          scanf("%s",&info.Class);
          printf("\n\t\t\tEnter Address       : ");
          scanf("%s",&info.vill);
          printf("\n\t\t\tEnter Percentage    : ");
          scanf("%f",&info.per);
          printf("\n\t\t\t______________________________\n");

      if(fp==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\t\t\tRecord stored successfuly\n");
    }

    fwrite(&info, sizeof(struct student), 1, fp);
    fclose(fp);

    printf("\t\t\tYou want to add another record?(y/n) : ");


    scanf("%s",&another);


   }while(another=='y'||another=='Y');
}
void studentrecord(){

     FILE *fp;

    struct student info;
    fp=fopen("information.txt","r");

     printf("\t\t\t\t=======STUDENTS RECORD=======\n\n\n");

    if(fp==NULL){

        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("\t\t\t\tRECORDS :\n");
        printf("\t\t\t\t___________\n\n");
    }

        while(fread(&info,sizeof(struct student),1,fp)){
        printf("\n\t\t\t\t Student Name  : %s %s",info.first_name,info.last_name);
        printf("\n\t\t\t\t Roll NO       : %d",info.roll_no);
        printf("\n\t\t\t\t Class         : %s",info.Class);
        printf("\n\t\t\t\t Village/City  : %s",info.vill);
        printf("\n\t\t\t\t Percentage    : %f%",info.per);


        printf("\n\t\t\t\t ________________________________\n");

         }
        fclose(fp);
getch();

  }




