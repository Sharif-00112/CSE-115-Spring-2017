#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#include <string.h>

void   getCalculation(void);
float  marksToGP(float marks);
char  *marksToG(float gp);

int main()
{

    char choice;
    int password, help;
    char again;

    printf("\t\t\tWelcome to our project!!!");
    printf("\n\nDo you want to calculate your CGPA and view information...??\n");
    printf("\n(1) Yes (Press 'Y')\n");
    printf("(2) Exit (Press 'N')\n");
    printf("\nPlease enter your choice:\t");
    scanf("%c",&choice);

    if(choice == 'y'|| choice == 'Y')
        {
        printf("Please Enter your password:\t");
        scanf("%d", & password);

    if (password==12345)
    {
        getCalculation();
    }
    else
    {
        printf("\n'Sorry, wrong password'\n");
        printf("\nHaving trouble? To get info press 1, to exit press 2:\t");
        scanf("%d", & help);
        if (help==1)
        {
            printf("\nRun the program again and enter password: 12345 in password bar to continue...\n");
            printf("\n\t\t\tThanks for visiting our project \n\t\tDesigned by: Md. Sharif Hossain\n");
        }
        else
        {
            printf("\n\t\t\tThanks for visiting our project \n\t\tDesigned by: Md. Sharif Hossain\n");
        }
    }
    }

    else if(choice == 'n'||choice == 'N')
    {
        printf("\n\t\t\tThanks you for visiting our project");
        printf("\n\t\tDesigned by:\t Md. Sharif Hossain \n");

    }

    else
    {
        printf("\nWrong input! Please try again...\n");
        printf("\n\t\t\tThank you for visiting our project");
        printf("\n\t\tDesigned by:\t Md. Sharif Hossain\n");

    }

    return 0;
    }


    void getCalculation(void)
    {

    int loop;
    int numOfSubject;
    float gp[100];
    int ch[100];
    int sumch=0;
    double sumchxgp=0;
    char nameSubject[100][40];
    float mark[100];
    char g[100][10];

    struct student
    {
        char name[100];
        int  ID;
    };

    struct student s1;
    printf("\nEnter your name(nick name): ");
    scanf("%s",&s1.name);
    printf("\nEnter your ID: ");
    scanf("%d",&s1.ID);


    printf("\nEnter your current semester total subject: ");
    scanf("%d",&numOfSubject);

    for(loop=0;loop<numOfSubject;loop++)
        {
        printf("\nSubject %d\n",loop+1);

        printf("Enter subject name: ");
        scanf("%s",&nameSubject[loop]);

        fflush stdin;
        printf("Credit Hour: ");
        scanf("%d",&ch[loop]);

        fflush stdin;
        printf("Your mark: ");
        scanf("%f",&mark[loop]);

        gp[loop]=marksToGP(mark[loop]);
        strcpy(g[loop],marksToG(mark[loop]));

        }

    printf("***********************************************************************************************************\n\n");
    printf("\n");
    printf("Subject\t         CreditHour\t        Marks\t     GradePoint\t      Grade\t");
    for (loop=0;loop<numOfSubject;loop++)
    {

        printf("\n%d %s\t\t%d\t\t%.2f         %.2f\t         %s\n\n",loop+1,nameSubject[loop],ch[loop],mark[loop],gp[loop],g[loop]);

    }

    for (loop=0;loop<numOfSubject;loop++)
    {
        sumch=sumch+ch[loop];
        sumchxgp=sumchxgp+ch[loop]*gp[loop];
    }

    printf("Total credit hour is = %d\n\n",sumch);
    printf("Total credit hour X grade point is = %.2f\n\n",sumchxgp);
    printf("Grade point average is = %.2f\n\n",sumchxgp/sumch);

    printf("NAME:%s and ID:%d your CGPA in this semester is:%.2f\n\n",s1.name,s1.ID,sumchxgp/sumch);
    printf("***********************************************************************************************************\n\n");

    printf("\n\t\t\tThank you for using CGPA Calculator");
    printf("\n\t\tDesigned by:\t Md. Sharif Hossain\n");


    }

    float marksToGP(float marks)
    {
        if(marks >= 93 && marks<=100)
        {
            return (float)4.00;
        }
        else if(marks <= 92 && marks>= 90)
        {
            return (float)3.70;
        }
        else if(marks <= 89 && marks>= 87)
        {
            return (float)3.30;
        }
        else if(marks <= 86 && marks>= 83)
        {
            return (float)3.00;
        }
        else if(marks <= 82 && marks>= 80)
        {
            return (float)2.7;
        }
        else if(marks <= 79 && marks>= 77)
        {
            return (float)2.30;
        }
        else if(marks <=76  && marks>= 73)
        {
            return (float)2.00;
        }
        else if(marks <= 72 && marks>= 70)
        {
            return (float)1.70;
        }
        else if(marks <= 69 && marks>= 67)
        {
            return (float)1.30;
        }
        else if(marks <= 66 && marks>= 60)
        {
            return (float)1.00;
        }
        else
        {
            return (float)0.00;
        }
    }


    char *marksToG(float marks)
    {
        if(marks >= 93 && marks<=100)
        {
            return "A";
        }
        else if(marks <= 92 && marks>= 90)
        {
            return "A-";
        }
        else if(marks <= 89 && marks>= 87)
        {
            return "B+";
        }
        else if(marks <= 86 && marks>= 83)
        {
            return "B";
        }
        else if(marks <= 82 && marks>= 80)
        {
            return "B-";
        }
        else if(marks <= 79 && marks>= 77)
        {
            return "C+";
        }
        else if(marks <=76  && marks>= 73)
        {
            return "C";
        }
        else if(marks <= 72 && marks>= 70)
        {
            return "C-";
        }
        else if(marks <= 69 && marks>= 67)
        {
            return "D+";
        }
        else if(marks <= 66 && marks>= 60)
        {
            return "D";
        }
        else
        {
            return "F";
        }

    }
