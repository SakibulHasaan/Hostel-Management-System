#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct slist
{
    char name[30];
    char ID[20];
    int room_no;
    int mealcount;
    double monthlycost;
} slist;
int i = 0,deletedStudent[50],d=0,totalhostelmeal=0;
double totalhostelcost=0,mealrate;
slist st[50];
void menu();
void costupdate(int s);
void newStudent();
void NoOfStudent();
void viewList();
void Delete();
void travarse();
void Exit();
void mealcost();
int main()
{
    memset(deletedStudent,-1,50*sizeof(deletedStudent[0]));
    system("color 5f");
    menu();
    return 0;
}
void menu()
{
    system("CLS");
    system("color 5f");
    int choice;
    printf("\n\n\t\t\t HOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1>> Enter new Student's data\n\t\t2>> See Number Of Students\n\t\t3>> View all students list\n\t\t4>> View a particular Students Information\n\t\t5>> Remove existing account\n\t\t6>> For Hostel's Cost Management\n\t\t7>> Exit \n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

    case 1:
        newStudent();
        break;
    case 2:
        NoOfStudent();
        break;
    case 3:
        viewList();
        break;
    case 4:
        travarse();
        break;
    case 5:
        Delete();
        break;
    case 6:
        mealcost();
        break;
    case 7:
        Exit();
        break;
    default:
        menu();
    }
}
void newStudent()
{
    system("color 5f");
    system("CLS");
    printf("\n\t\t ENTER STUDENT'S NAME: ");
    fgets(st[i].name, sizeof(st[i].name), stdin);
    scanf("%s",st[i].name);
    printf("\n\t\t ENTER STUDENT'S ID: ");
    scanf("%s",st[i].ID);
    printf("\n\t\t ENTER STUDENT'S Room NO: ");
    scanf("%d",&st[i].room_no);
    printf("\n\n\t\t Student Added Successfully\n");
    i++;
    int choice;
newstudentchoice:
    printf("\n\n\t\t ENTER 1 TO ADD ANOTHER STUDENT,2 FOR MAIN MENU\n\n\t\t ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    if (choice==1)
        newStudent();
    if (choice==2)
        menu();
    else
    {
        printf("\n\n\t\t Invelid choice\n");
        goto newstudentchoice;
    }
}
void viewList()
{
    system("color 5f");
    system("CLS");
    int j,k=0,s=1;
    for(j = 0; j<i; j++,s++)
    {
        if(deletedStudent[k]==j)
        {
            k++;
            s--;
            continue;
        }
        printf("\n\n\t\t Student No %d's Informations\n",s);
        printf("\n\t\t NAME: %s\n",st[j].name);
        printf("\n\t\t ID: %s\n",st[j].ID);
        printf("\n\t\t ROOM NO: %d\n",st[j].room_no);

        if (j==i-1)
        {
            printf("\n\n\t\t THATS ALL THANK YOU\n");
        }
    }
    int choice;
viewlistchoice:
    printf("\n\n\t\t ENTER 1 SEARCH AGAIN,2 FOR MAIN MENU\n\n\t ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    if (choice==1)
        travarse();
    if (choice==2)
        menu();
    else
    {
        printf("\n\t\t Invelid choice\n");
        goto viewlistchoice;
    }
}
void travarse()
{
    system("color 5f");
    system("CLS");
    printf("\n\n\t\t ENTER THE ID PLEASE: ");
    char id[20];
    scanf("%s",id);
    int j=0;
    int flag = 0;
    for (int k=0; k<i; k++)
    {
        if(deletedStudent[j]==k)
        {
            printf("\n\t\t NO RECORD FOUND\n");
            j++;
            flag = 1;
            continue;
        }
    }
    if (flag==1)
        goto travarsechoice;

    int s;
    for (s=0; s<i; s++)
    {
        if (strcmp(st[s].ID,id)==0)
        {
            printf("\n\n\t\t NAME: %s\n",st[s].name);
            printf("\n\t\t ID: %s\n",st[s].ID);
            printf("\n\t\t ROOM NO: %d\n",st[s].room_no);
            printf("\n\n\t\t Monthly Cost: %.2lf\n",st[j].monthlycost);
            printf("\n\t\t THATS ALL THANK YOU\n");
            break;
        }

    }
    int choice;
travarsechoice:
    printf("\n\n\t\t ENTER 1 SEARCH ANOTHER STUDENT,2 FOR MAIN MENU \n\t\t ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    if (choice==1)
        travarse();
    if (choice==2)
        menu();
    else
    {
        printf("\n\t\t Invelid choice\n");
        goto travarsechoice;
    }
}
void NoOfStudent()
{
    system("color 5f");
    system("CLS");
    printf("\n\t\t THERE IS %d STUDETS IN THIS HOSTEL\n",i-d);
    int choice;
Noofchoice:
    printf("\n\n\t\t ENTER 1 FOR MAIN MENU\n\n\n\t\t ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    if (choice==1)
        menu();
    else
    {
        printf("\n\t\t Invelid choice\n");
        goto Noofchoice;
    }
}
void Delete()
{
    system("color 5f");
    system("CLS");
    printf("\n\t\t ENTER THE ID YOU WANT TO DELETE: ");
    char id[20];
    scanf("%s",id);
    for(int s=0; s<i; s++)
    {
        if (strcmp(st[s].ID,id)==0)
        {
            deletedStudent[d]=s;
            d++;
            costupdate(s);
            printf("\n\t\t DELETION SUCCESSFUL\n");
            break;
        }
        if(s==i-1 && strcmp(st[s].ID,id)!=0)
        {
            printf("\n\t\t NO RECORD FOUND\n");
            break;
        }
    }
    int choice;
Deletechoice:
    printf("\n\n\t\t ENTER 1 TO DELETE ANOTHER STUDENT,2 FOR MAIN MENU\n\t\t ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    if (choice==1)
        Delete();
    if (choice==2)
        menu();
    else
    {
        printf("\n\t\t Invelid choice\n");
        goto Deletechoice;
    }
}
void mealcost()
{
    system("color 5f");
    system("CLS");
    system("color 4f");
    int meal;
    printf("\n\t\t Enter Total Hostel Cost: ");
    scanf("%lf",&totalhostelcost);
    int s = 0,j=0;
    while(s<i)
    {
        if(deletedStudent[j]==s)
        {
            j++;
            s++;
            continue;
        }
        printf("\n\t\tPlease Enter %s's Total meal: ",st[s].ID);
        scanf("%d",&st[s].mealcount);
        totalhostelmeal +=st[s].mealcount;
        s++;
    }
    mealrate = totalhostelcost/totalhostelmeal;
    int k = 0,p=0;
    while(k<i)
    {
        if(deletedStudent[p]==k)
        {
            p++;
            k++;
            continue;
        }
        st[k].monthlycost = st[k].mealcount * mealrate;
        k++;
    }
    int choice;
costchoice:
    printf("\n\n\t\t ENTER 1 FOR MAIN MENU\n\t\t ENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    if (choice==1)
        menu();
    else
    {
        printf("\n\t\t Invelid choice\n");
        goto costchoice;
    }
}
void costupdate(int s)
{
    totalhostelmeal -= st[s].mealcount;
    totalhostelcost-=st[s].monthlycost;
}
void Exit()
{
    system("color 2f");
    system("CLS");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 A PROJECT BY>> \xB2\xB2\xB2\xB2\xB2\xB2\xB2 \n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Md. Sakibul Hasan \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Golam Rabbi \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Nur Nafish Ahmed Nobel \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
}
