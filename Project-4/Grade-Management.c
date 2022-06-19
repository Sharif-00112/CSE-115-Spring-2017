#include<stdio.h>


 void filewrite();
 void avgmarks();
 void fileprint();
 void rollin();


/*********************** FILE WRITING FUNCTION ******************************/
void filewrite()
{
  int roll,ch,mark;
  char nam[50];
   FILE *fp;
  fp = fopen("student.txt","a");
   printf("ENTER ROLL NUMBER, NAME , MARKS \n");
  ch =1;
  while(ch)
  {
  scanf("%d%s%d",&roll,&nam,&mark);
  fprintf(fp,"%d %s %d\n",roll,nam,mark);
  printf("\n\n press 1 to continue,0 to stop");
  scanf("%d",&ch);
  }
   fclose(fp) ;
}
/******************** OUTPUTING DATA ON SCREEN***************/
void fileprint()
{
  int marks[100],rollno[100],x[100],i;
  char name[100][50];
  FILE *fp;

  fp = fopen("student.txt","r");
   i=0;
   printf("ROLLNO       NAME        MARK\n");
   while(!feof(fp))
  {
     fscanf(fp,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
     printf(" %d          %s          %d\n",rollno[i],name[i],marks[i]);
     i=i+1;
   }
   fclose(fp);
   printf("\n\n\nPRESS ANY KEY");
   getch();

  }

/************************* DATA USING ROLLNO***************************/
void rollin()
{   int i,roll,ch,mark,roll1;
    char nam[50];
    FILE *fm;

    ch=1;
  while(ch)
  {
    fm = fopen("marks.txt","r");
    printf(" \n ENTER ROLL NUMBER - ");
    scanf("%d",&roll1);
      i=0;
   while(! feof(fm))
    {
     fscanf(fm,"%d %s %d\n",&roll,&nam,&mark);
     if(roll1==roll)
    {printf("\nROLLNO.     NAME        MARKS\n ");
     printf(" %d          %s          %d\n",roll,nam,mark);
     break;
     }
     else
     i=i+1;
      }
  printf("\n\npress 1 to see student info, 0 to return to main menu\n");
  scanf("%d",&ch);
  fclose(fm);
  }



 }

void avgmarks()
 {
    int marks[100],rollno[100],n,i;
    float avg,x;
    char name[100][50];
    FILE *fm;
    fm = fopen("marks.txt","r");
    i=0;
   while(! feof(fm))
    {

     fscanf(fm,"%d %s %d\n",&rollno[i],&name[i],&marks[i]);
     x = x + marks[i];
     i=i+1;
      }
     n = i;
   avg = x/n;
  printf("AVERAGE MARKS OF %d STUDENTS ARE -  %f ",n,avg);
  fclose(fm);
  printf("\n\n\nPRESS ANY KEY");
   getch();

 }


/**************** FUNC. ENDS************************/
void main()
{
  int marks[100],rollno[100],x[100],n,i,j,roll,c,mark,roll1;
  char name[100][10],nam[50];

  while(c!=6)
   {
     printf("GIVE CHOICE--\n");
     printf("   1 TO ENTER STUDENT INFO.\n");
     printf("   2 TO SEE STUDENT.TXT FILE\n");
     printf("   3 TO PRINT STUDENT INFO. USING ROLL NO\n");
     printf("   4 TO FIND AVERAGE OF MARKS\n");
     printf("   5 TO EXIT\n\n--");
     scanf("%d",&c);

     switch(c)
     {
     case 1:
          filewrite();
          break;
     case 2:
          fileprint();
         break;

     case 3:  rollin();
          break;
     case 4:  avgmarks();
          break;
     case 5:   exit(0);
          break;
     default:
          break;
     }
    }
  }
