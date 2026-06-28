#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    int id;
    char name[50];
    char password[20];
};

struct student s[100];
int count=0;


void addstudent()
{
    printf("\nEnter id Number:");
    scanf("%d",&s[count].id);

    printf("Enter name:");
    scanf("%s",s[count].name);

    printf("Enter password:");
    scanf("%s",s[count].password);

    count++;

    printf("\nStudent Added successfully!\n");
}


void displaystudents()
{
    int i;

    if(count==0)
    {
        printf("\nNo Record Found!\n");
        return;
    }

    printf("\n----Student Records----\n");

    for(i=0;i<count;i++)
    {
        printf("\nID No:%d",s[i].id);
        printf("\nName:%s",s[i].name);
        printf("\nPassword:%s\n",s[i].password);
    }
}


void searchstudent()
{
    int id,i,found=0;

    printf("Enter id number to search:");
    scanf("%d",&id);

    for(i=0;i<count;i++)
    {
        if(s[i].id==id)
        {
            printf("\nStudent Found!");

            printf("\nID No:%d",s[i].id);
            printf("\nName:%s",s[i].name);
            printf("\nPassword:%s\n",s[i].password);

            found=1;
            break;
        }
    }

    if(!found)
        printf("\nStudent Not Found!\n");
}


void deletestudent()
{
    int id,i,j,found=0;

    printf("\nEnter id number to delete:");
    scanf("%d",&id);

    for(i=0;i<count;i++)
    {
        if(s[i].id==id)
        {
            for(j=i;j<count-1;j++)
            {
                s[j]=s[j+1];
            }

            count--;

            found=1;

            printf("\nStudent Deleted successfully!\n");
            break;
        }
    }

    if(!found)
        printf("\nStudent Not Found!\n");
}


int main()
{
    int choice;

    while(1)
    {
        printf("\n\n====Student Management System====");
        printf("\n1.Add student");
        printf("\n2.Display student");
        printf("\n3.Search student");
        printf("\n4.Delete student");
        printf("\n5.Exit");

        printf("\nEnter choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addstudent();
                break;

            case 2:
                displaystudents();
                break;

            case 3:
                searchstudent();
                break;

            case 4:
                deletestudent();
                break;

            case 5:
                printf("\nThank you!\n");
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}
