#include<stdio.h>
#include<string.h>
#define FILE_NAME "booklist.txt"

void header()
{
    printf(" \n\t\t\t*************************************\n ");
    printf(" \n\t\t\t|                                    |\n");
    printf(" \n\t\t\t|          :-WELCOME TO:-            |\n");
    printf(" \n\t\t\t|        :-NSU BOOK STORE:-          |\n");
    printf(" \n\t\t\t|  :-Directed by Md Sharif Hossain:- |\n");
    printf(" \n\t\t\t|                                    |\n");
    printf(" \n\t\t\t*************************************\n ");
}
struct list
{
    char author[20];
    char title[30];
    float price;

    struct
    {
        char month[10];
        int year;
    }date;

    char publisher[10];
    int quantity;
};



int search(struct list table[],char c1[],char c2[],int n);

void get(char string[]);

main()
{   FILE *fptr;
    fptr = fopen("booklist.text", "w");
    int index,no_of_record;
    char title[30],author[20];
    char responce[10],quantity[10];
    struct list book[]=
    {
        {
            "Jk Rowling ","Harry Potter",245.00,"May",1998,"PHI",15
        },

        {
            "Jk Rowling ","Harry Potter 2",345.00,"Mar",2000,"PHI",15
        },

        {
            "Jk Rowling ","Harry Potter 3",332.00,"May",2002,"PHI",15
        },

        {
           "Jk Rowling ","Harry Potter 4",355.00,"May",2004,"PHI",15
        },

        {
            "Mario Puzo","The Godfather",305.50,"july",1968,"hayden",25
        },

        {
            "Dan Brown", "The Vinci Code",510.00,"Jun",2001,"TMH",20
        },

        {
            "Dan Brown","Digital Fortress",468.00,"Jan",2005,"TMH",20
        },

        {
            "Dietel", "C",420.00,"Aug",2003,"TMH",15
        },

        {
            "Himu","Humayun Ahmed",260.00,"Feb",2004,"Onno",25
        },

        {
            "Rasha","Jafor Iqbal",340.00,"Feb",2012,"Tramo Lipi",20
        }
    };

    no_of_record=sizeof(book)/sizeof(struct list);
    do
    {
        system("cls");
        header();
        printf("\n\n\n\n\t:- ENTER THE TITLE AND AUTHOR OF THE BOOK WHICH YOU WANT TO PURCHASE :- \n");

        printf("\n\n\t:- TITLE :-");
        get(title);

        printf("\n\n\t:- AUTHOR :-");
        get(author);

        index=search(book,title,author,no_of_record);
        if(index !=-1)

        {
            printf("\n\n YOUR DESIRE BOOK AVAILBLE IN THE STOCK.\n\n");
            printf("[AUTHOR]   [TITLE]   [PRICE]   [MONTH]   [YEAR]   [PUBLISHER]\n");

            printf("-------------------------------------------------------------");
            printf("\n%s  %s  %.2f  %s   %d   %s \n\n",book[index].author,book[index].title,book[index].price,book[index].date.month,book[index].date.year,book[index].publisher);

            printf("\n\n ENTER THE NUMBER OF COPIES:");

            get(quantity);

            if(atoi(quantity)<=book[index].quantity)

            printf("\n\nCOST OF THE %d COPIES IS=%.2f\n ",atoi(quantity),book[index].price*atoi(quantity));

            else
            printf("\n REQUIRED COPIES NOT IN THE STOCK \n\n");
        }

        else
        printf("\n YOUR DESIRED BOOK IS NOT IN THE STOCK.\n\n");
        printf("\n DO YOU WANT TO PURCHASE ANY OTHER BOOK ? (Y/N):");
        get(responce);
    }

    while(responce[0]=='y'||responce[0]=='y');
    printf("\n\n THANK YOU....!!!!\n");
    printf("Designed By: Sharif-1712336642\n");

    }

    void get(char string[])

    {
        char c;
        int i=0;
        do
        {
            c=getchar();
            string[i++]=c;
        }
        while(c !='\n');
        string[i-1]='\0';
    }

    int search(struct list table[],char c1[],char c2[],int n)
    {
        int i;
        for(i=0;i<n;i++)
        if(strcmp(c1,table[i].title)==0 && strcmp(c2,table[i].author)==0)
        return(i);
        return(-1);
    }
