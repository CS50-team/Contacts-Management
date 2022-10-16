#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

/* Simple Contact Managment System By Mohamed Mostafa */

void addcontact(void);
void searchcontact(void);
void listcontacts(void);
void rerun(void);

typedef struct 
{
    char* name;
    char* number;
}s1;

typedef struct 
{
    char* name1;
    char* number1;
}s2;

int main(void)
{
    int select;
    printf("\n----------------------------------------------------------------------------\n");
    printf("\n[1] Add Contact\n\n[2] Search Contacts\n\n[3] List Contacts\n\n[4] Exit\n\n");
    do 
    {
        select = get_int("Select From Menu: ");
        if(select == 1)
        {
            addcontact();
        }
        else if(select == 2)
        {
            searchcontact();
        }
        else if(select == 3)
        {
            listcontacts();
        }
        else if(select == 4)
        {
            return 0;
        }
    } while(select < 1 || select > 4);
}

void addcontact(void)
{
    char save;int type;int input;
    do
    {
        input = get_int("\n[*] How Many Contacts You Wanna Add?: ");
        if(input > 25)
        {
            printf("\n[!] Maximum Contacts Input Length Is: 25.\n");
        }
        else if(input < 1)
        {
            printf("\n[!] Minimum Contacts Input Length Is: 1.\n");
        }
    } while (input < 1 || input > 25);
    s2 data[input];
    for(int t = 0; t < input;t++)
    {
        do
        {
            data[t].name1 = get_string("\n[*] Enter Name: ");
            for(int x = 0; x < strlen(data[t].name1);x++)
            {
                if(isdigit(data[t].name1[x]) != 0)
                {
                    printf("\n[!] Please Enter Plain Text Only Not Numbers.\n");
                    return;
                }
            }
            if(strlen(data[t].name1) > 25)
            {
                printf("\n[!] Contact Name Maximum Length is 25 Characters.\n");
            }
            else if(strlen(data[t].name1) < 3)
            {
                printf("\n[!] Contact Name Minimum Length is 3 Characters.\n");
            }
        } while (strlen(data[t].name1) > 25 || strlen(data[t].name1) < 3);

        do
        {
            data[t].number1 = get_string("\n[*] Enter Number: ");
            for(int z = 0; z < strlen(data[t].number1);z++)
            {
                if(isspace(data[t].number1[z]) != 0)
                {
                    printf("\n[!] Please Enter Number Without Spaces (Ex: 01200011122).\n");
                    return;
                }
                if(isalpha(data[t].number1[z]) != 0)
                {

                    printf("\n[!] Please Enter Numbers Only Not Letters (Ex: 01200011122).\n");
                    return;
                }
            }
            if(strlen(data[t].number1) != 11)
            {
                printf("\n[!] Contact Number Length Is 11 Digits.\n");
            }
        } while (strlen(data[t].number1) != 11);      
    }
    do
    {
        save = get_char("\n[!] Save Contacts To A file? (y / n): ");
        save = tolower(save);
        if(save == 'y')
        {
            printf("\n--------------------------");
            printf("\n[?] Select File Extension\n\n[1] .Txt File\n\n[2] .CSV File\n\n[0] Return");
            printf("\n--------------------------\n");

            {
                type = get_int("\n[*] Select: ");
                if(type == 1)
                {
                    for(int q = 0; q < input;q++)
                    {
                        FILE* contacts = fopen("contacts.txt","a");
                        fprintf(contacts,"Name: %s\nNumber: %s\n\n",data[q].name1,data[q].number1);
                        fclose(contacts);
                        if(q == input - 1)
                        {
                            printf("\n[ツ] Data Saved Successfully.\n");
                        }
                    }
                }
                else if(type == 2)
                {
                    for(int q = 0; q < input;q++)
                    {
                        FILE* contacts = fopen("contacts.csv","a");
                        fprintf(contacts,"Name: %s\nNumber: %s\n\n",data[q].name1,data[q].number1);
                        fclose(contacts);
                        if(q == input - 1)
                        {
                            printf("\n[ツ] Data Saved Successfully.\n");
                        }
                    }
                }
                else if(type == 0)
                {
                    main();
                    return;
                }
                else
                {
                    printf("\n[!] Invalid Option Please Choose (0 or 1 or 2).\n");
                }
            } while (type < 0 || type > 2);
        }
        else if(save == 'n')
        {
            printf("\n[☉_☉] Data Not Saved.\n");
        }
        else
        {
            printf("\n[º_º] Invalid Answer, Please Enter (y or n).\n");
        }
    } while (save != 'y' && save != 'n');
    rerun();
}

void searchcontact(void)
{
    s1 data[3];char* search;int choose;
    data[0].name = "ahmed";data[0].number = "01200011122";
    data[1].name = "mohamed";data[1].number = "01000011122";
    data[2].name = "mostafa";data[2].number = "01100011122";
    
    search = get_string("\n[*] Enter Contact Name: ");
    for(int z = 0; z < strlen(search) ;z++)
    {
        if(isupper(search[z]) != 0)
        {
            search[z] = tolower(search[z]);
        }
        if(z == strlen(search) - 1)
        {
            for(int x = 0; x < 3;x++)
            {
                if(strcmp(search,data[x].name) == 0)
                {
                    printf("\n[ツ] Contact Found!\n");
                    printf("\n---------------------------------\n");
                    printf("| Name: \t%s\t\t|\n",data[x].name);
                    printf("---------------------------------\n");
                    printf("| Number: \t%s\t|\n",data[x].number);
                    printf("---------------------------------\n");
                    rerun();
                    return;
                }
                if(x == 2)
                {
                    printf("\n[☉_☉] Contact Not Found!\n");
                    rerun();
                }
            }
        }
    }
}


void listcontacts(void)
{
    s1 data[3];
    data[0].name = "ahmed";data[0].number = "01200011122";
    data[1].name = "mohamed";data[1].number = "01000011122";
    data[2].name = "mostafa";data[2].number = "01100011122";

        printf("\n-------------------------------------------------\n");
        printf("| Name\t\tNumber\t\t\t\t|\n");
        printf("-------------------------------------------------\n");
        printf("| %s\t\t%s\t\t\t|\n",data[0].name,data[0].number);
        printf("-------------------------------------------------\n");
        printf("| %s\t%s\t\t\t|\n",data[1].name,data[1].number);
        printf("-------------------------------------------------\n");
        printf("| %s\t%s\t\t\t|\n",data[2].name,data[2].number);
        printf("-------------------------------------------------\n");
        rerun();
}

void rerun(void)
{   
    char q1;
    do
    {
        q1 = get_char("\n[ツ] Do You Wanna Perform Another Action? (y = Continue / n = Exit): ");
        q1 = tolower(q1);
        if(q1 == 'y')
        {
            main();
        }
        else if(q1 == 'n')
        {
            printf("\n[☉_☉] Contact Management Has Been Terminated.\n");
            return;
        }
        else
        {
            printf("\n[º_º] Invalid Answer, Please Enter (y or n).\n");
        }
    } while(q1 != 'y' && q1 != 'n');
}
