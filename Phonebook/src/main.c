#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

int num;

struct phonebook{
    char first_name[15];
    char last_name[15];
    char contact_no[15];
    char gender[8];
    char postal_code[8];
};

//FUNCTION PROTOTYPES
void close_()
{
    printf("\t\t\t    ------------------------\n");
    printf("\t\t\t    Thank you from NAME Group.\n");
    printf("\t\t\t    ------------------------\n");
    exit(0);
}
void menu();
void start();
void add_info();
int contact_check(char *contact);
void list_info();
void search_info();
void method_1(int value);
void method_2(int value);
void method_3(int value);
void method_4(int value);
void delete_info();
void copy_data();
void modify_info();


int main()
{
    system("color 0f");
    printf("\t\t_____________________________________________________\n");
    printf("\t\t               WELCOME TO PHONEBOOK           \n");
    printf("\t\t_____________________________________________________\n\n");

    start();
    return 0;
}

void start()
{
    menu();
}

void menu()
{
    system("color cf"); //Red
    system("cls");

    printf("\n\n\t\t\t\t\tMENU\t\t\n\n");

    printf("\t\t   ______________________________________________\n");
    printf("\t\t   1.Add New    \t2.List   \t3.Delete");
    printf("\n\t\t   4.Modify      \t5.Search\t6.Exit\t\n");
    printf("\t\t   ______________________________________________\n");

    printf("\n\t\t     Please Enter the Number you Want to Choose:\n\n");

    switch(getch())
    {
        case '1': add_info();
        break;
        case '2': list_info();
        break;
        case '3': delete_info();
        break;
        case '4': modify_info();
        break;
        case '5': search_info();
        break;
        case '6': close_();
        break;

        default:
            system("cls");
            printf("\n\t\t\t\t    Enter 1 to 6 only\n");
            getch();
            menu();
    }
}

void add_info()
{
    system("cls");
    system("color 5f"); //purple
    printf("\n\t\t\t    Option 1 [Add new] selected.\n");

    FILE *f_name, *l_name, *contact, *gender, *postal, *Quantity;

    struct phonebook x;

    printf("\nEnter First Name:");
    scanf("%s", x.first_name);
    printf("\nEnter Last Name:");
    scanf("%s", x.last_name);
    printf("\nEnter Contact Number:");
    scanf("%s",x.contact_no);
    printf("\nEnter Gender:");
    scanf("%s", x.gender);
    printf("\nEnter Postal Code:");
    scanf("%s", x.postal_code);

    int check;
    check = contact_check(x.contact_no);

    if(check == 1)
    {
        printf("\n\n[ This record cannot be inserted ]\n\n");
    }
    else
    {
        f_name = fopen("First Name.txt", "a");
        fprintf(f_name,"%s\n",x.first_name);
        fclose(f_name);

        l_name = fopen("Last Name.txt", "a");
        fprintf(l_name, "%s\n", x.last_name);
        fclose(l_name);

        contact = fopen("Contact.txt", "a");
        fprintf(contact,"%s\n",x.contact_no);
        fclose(contact);

        gender = fopen("Gender.txt", "a");
        fprintf(gender,"%s\n",x.gender);
        fclose(gender);

        postal = fopen("Postal.txt", "a");
        fprintf(postal,"%s\n",x.postal_code);
        fclose(postal);

        printf("\n [ New Record Has Been Successfully Saved ]\n");

        Quantity = fopen("Quantity.txt", "r");
        fscanf(Quantity, "%d", &num);
        num ++;
        fclose(Quantity);

        Quantity = fopen("Quantity.txt", "w+");
        fprintf(Quantity, "%d", num);
        fclose(Quantity);
    }

    printf("\nEnter 1 - For Add Again.\nEnter 2 - For back to Menu.\n");

    switch(getch())
    {
        case '1': add_info();
        break;
        case '2': menu();
        break;
        default:
            system("cls");
                menu();
    }
}


int contact_check(char *contact)
{
    // For checking existence in record base
    // But only for number
    // One number cannot belongs to multiple people

    struct phonebook x;
    FILE *Quantity, *Contact_num;
    Quantity = fopen("Quantity.txt", "r");
    fscanf(Quantity, "%d", &num);

    Contact_num = fopen("Contact.txt", "r");
    for(int i=0; i<num; i++)
    {
        fscanf(Contact_num, "%s", x.contact_no);

        if(strcmp(contact, x.contact_no) == 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    fclose(Quantity);
    fclose(Contact_num);
}

void list_info()
{
    system("cls");
    system("color Af");
    printf("\n\t\t\t     Option 2 [ List ] selected.\n\n");

    //FILE POINTERS - Main
    FILE *f_name, *l_name, *contact, *gender, *postal, *Quantity;

    Quantity = fopen("Quantity.txt", "r");
    int value;
    fscanf(Quantity,"%d", &value);
    fclose(Quantity);

    f_name = fopen("First Name.txt", "r");
    l_name = fopen("Last Name.txt", "r");
    contact = fopen("Contact.txt", "r");
    gender = fopen("Gender.txt", "r");
    postal = fopen("Postal.txt", "r");

    if(f_name == NULL)
    {
        printf("\t\t\t\t-------------------\n");
        printf("\t\t\t\tDatabase is empty.\n");
        printf("\t\t\t\t-------------------\n\n");
        printf("\t\t    [ Add some records and try to view again. ]\n\n");
    }
    else
    {
        // Arrays for storing data
        char arr_f_name[value][15], arr_l_name[value][15], arr_contact[value][15], arr_gender[value][8], arr_postal[value][8];

        // Temp arrays
        char name_temp[25], l_n_temp[25], con_temp[15], gen_temp[8], pos_temp[8];

        for(int i=0; i<value; i++)
        {
            fscanf(f_name, "%s", arr_f_name[i]);
            fscanf(l_name, "%s", arr_l_name[i]);
            fscanf(contact, "%s", arr_contact[i]);
            fscanf(gender, "%s", arr_gender[i]);
            fscanf(postal, "%s", arr_postal[i]);
        }

        //Quick sort applied
        //But only for first name. Other value will follow first name to sort themselves with first name
        for(int i=0;i<value;i++)
        {
            for(int j=i+1;j<value;j++)
            {
                if(strcmp(arr_f_name[i],arr_f_name[j])>0)
                {
                    //First Name
                    strcpy(name_temp,arr_f_name[i]);
                    strcpy(arr_f_name[i],arr_f_name[j]);
                    strcpy(arr_f_name[j],name_temp);

                    //Last Name
                    strcpy(l_n_temp,arr_l_name[i]);
                    strcpy(arr_l_name[i],arr_l_name[j]);
                    strcpy(arr_l_name[j],l_n_temp);

                    //Contact
                    strcpy(con_temp,arr_contact[i]);
                    strcpy(arr_contact[i],arr_contact[j]);
                    strcpy(arr_contact[j],con_temp);

                    //Gender
                    strcpy(gen_temp,arr_gender[i]);
                    strcpy(arr_gender[i],arr_gender[j]);
                    strcpy(arr_gender[j],gen_temp);

                    //postal
                    strcpy(pos_temp,arr_postal[i]);
                    strcpy(arr_postal[i],arr_postal[j]);
                    strcpy(arr_postal[j],pos_temp);
                }
            }
        }

        printf("\t    Name \t    Contact Number     \t  Gender     \tPostal\n");
        printf("\t---------------------------------------------------------------\n");

        //Record printing on the console
        for(int i=0;i<value;i++)
        {
            printf("    +");
            printf("\t%s ", arr_f_name[i]);
            printf("%s", arr_l_name[i]);
            printf("\t      %s ", arr_contact[i]);
            printf("\t   %s ", arr_gender[i]);
            printf("\t  %s\n", arr_postal[i]);
            printf("\t---------------------------------------------------------------\n");

        }

        printf("\n\tTotal records : %d\n\n", value);
    }

    fclose(f_name);
    fclose(l_name);
    fclose(contact);
    fclose(gender);
    fclose(postal);

    printf("\nEnter any key to return menu.\n\n");

    getch();
    system("cls");
    menu();
}

void search_info()
{
    system("cls");
    system("color 1f");
    printf("\n\t\t\t    Option 5 [ Search ] selected.\n\n");

    FILE *Quantity;
    Quantity = fopen("Quantity.txt", "r");


    //GETTING TOTAL RECORD NUMBER
    int value;  //Hosing the value of total saved records
    fscanf(Quantity,"%d", &value);
    fclose(Quantity);


    //FOUR METHODS FOR SEARCHING
    printf("\tChoose search method:\n\n");
    printf("\tPress 1 - Search by Name.\n");
    printf("\tPress 2 - Search by Contact Number.\n");
    printf("\tPress 3 - Search by Postal Code.\n");
    printf("\tPress 4 - Search by Gender.\n\n");


    switch(getch())
    {
        case '1': method_1(value);
        break;
        case '2': method_2(value);
        break;
        case '3': method_3(value);
        break;
        case '4': method_4(value);
        break;
        default:
            printf("\t---------------------------------------------\n");
            printf("\t\tWrong method input. Taking you back to menu.\n");
            printf("\t---------------------------------------------\n");
            menu();
    }

    printf("\nPress 1 - To search again\n");
    printf("Press 2 - Go back o menu\n");

    switch(getch())
    {
        case '1': search_info();
        break;
        case '2': menu();
        break;
        default:
            printf("\t---------------------------------------------\n");
            printf("\t\tWrong method input. Taking you back to menu.\n");
            printf("\t---------------------------------------------\n");
            menu();
    }

}

// METHOD 1 FUNCTION Name
void method_1(int value)
{
    struct phonebook from_user, y;

    FILE *f_name, *l_name, *contact, *gender, *postal;

    //FILE OPENINGS - Reading mode - Main
    f_name = fopen("First Name.txt", "r");
    l_name = fopen("Last Name.txt", "r");
    contact = fopen("Contact.txt", "r");
    gender = fopen("Gender.txt", "r");
    postal = fopen("Postal.txt", "r");

    // GETTING SEARCHABLE NAME
    printf("Enter First name:");
    scanf("%s", from_user.first_name);
    printf("Enter Last name:");
    scanf("%s", from_user.last_name);

    int count = 1;
    bool Flag = false;

    for(int i=0; i<value; i++)
    {
        fscanf(f_name, "%s", y.first_name);
        fscanf(l_name, "%s", y.last_name);
        fscanf(contact, "%s", from_user.contact_no);
        fscanf(gender, "%s", from_user.gender);
        fscanf(postal, "%s", from_user.postal_code);

        if((strcmp(from_user.first_name, y.first_name) == 0) && strcmp(from_user.last_name, y.last_name) == 0)
        {
            Flag = true;

            printf("\n\t\tSearch result of [ %s %s] - %d\n", from_user.first_name, y.last_name, count);
            printf("\t\t________________________________________\n");
            printf("\n\t\tName : %s %s\n\t\tContact : %s\n\t\tGender: %s\n\t\tPostal code: %s\n", from_user.first_name, y.last_name, from_user.contact_no, from_user.gender, from_user.postal_code);
            count++;
        }
    }

    if(Flag == false)
    {
        printf("\t\tRecord for Name < %s %s > is not in the record.\n", from_user.first_name, from_user.last_name);
    }
    else
    {
        printf("\n\t\tTotal records for Name [ %s %s ] - %d\n", from_user.first_name, from_user.last_name, --count);
    }

    //FILE CLOSING
    fclose(f_name);
    fclose(gender);
    fclose(postal);
    fclose(contact);
}

// METHOD 2 FUNCTION Contact
void method_2(int value)
{
    struct phonebook from_user, y;

    FILE *f_name, *l_name, *contact, *gender, *postal;

    //FILE OPENINGS - Reading mode - Main
    f_name = fopen("First Name.txt", "r");
    l_name = fopen("Last Name.txt", "r");
    contact = fopen("Contact.txt", "r");
    gender = fopen("Gender.txt", "r");
    postal = fopen("Postal.txt", "r");


    printf("Enter Contact no:");
    scanf("%s", from_user.contact_no);

    bool Flag = false;

    for(int i=0; i<value; i++)
    {
        fscanf(f_name, "%s", y.first_name);
        fscanf(l_name, "%s", y.last_name);
        fscanf(contact, "%s", y.contact_no);
        fscanf(gender, "%s", y.gender);
        fscanf(postal, "%s", y.postal_code);

        if (strcmp(from_user.contact_no, y.contact_no) == 0)
        {
            Flag = true;

            printf("\n\t\tSearch result for [ %s ]\n", from_user.contact_no);
            printf("\t\t________________________________________\n");
            printf("\n\t\tName : %s %s\n\t\tContact : %s\n\t\tGender: %s\n\t\tPostal code: %s\n", y.first_name, y.last_name, from_user.contact_no, y.gender, y.postal_code);
            break;
        }

    }

    if(Flag == false)
    {
        printf("\t\tRecord for Contact no < %s > is not in the record.\n", from_user.contact_no);
    }


    //FILE CLOSING
    fclose(f_name);
    fclose(gender);
    fclose(postal);
    fclose(contact);

}

// METHOD 3 FUNCTION Postal
void method_3(int value)
{
    struct phonebook from_user, y;

    FILE *f_name, *l_name, *contact, *gender, *postal;

    //FILE OPENINGS
    f_name = fopen("First Name.txt", "r");
    l_name = fopen("Last Name.txt", "r");
    contact = fopen("Contact.txt", "r");
    gender = fopen("Gender.txt", "r");
    postal = fopen("Postal.txt", "r");

    // GETTING SEARCHABLE POSTAL CODE
    printf("Enter Postal Code:");
    scanf("%s", from_user.postal_code);


    int count = 1;
    bool Flag = false;

    for(int i=0; i<value; i++)
    {
        fscanf(f_name, "%s", y.first_name);
        fscanf(l_name, "%s", y.last_name);
        fscanf(contact, "%s", y.contact_no);
        fscanf(gender, "%s", y.gender);
        fscanf(postal, "%s", y.postal_code);

        if((strcmp(from_user.postal_code, y.postal_code) == 0))
        {
            Flag = true;

            printf("\n\t\tSearch result for [ %s ] - %d\n", from_user.postal_code, count);
            printf("\t\t________________________________________\n");
            printf("\n\t\tName : %s %s\n\t\tContact : %s\n\t\tGender: %s\n\t\tPostal code: %s\n", y.first_name, y.last_name, y.contact_no, y.gender, y.postal_code);
            count++;
        }
    }

    if(Flag == false)
    {
        printf("\t\tAny Record for Postal Code < %s > is not in the record.\n", from_user.postal_code);
    }
    else
    {
        printf("\n\t\tTotal records for Postal code [ %s ] - %d\n", from_user.postal_code, --count);
    }

    //FILE CLOSING
    fclose(f_name);
    fclose(gender);
    fclose(postal);
    fclose(contact);
}

// METHOD 4 FUNCTION Gender
void method_4(int value)
{
    struct phonebook from_user, y;

    FILE *f_name, *l_name, *contact, *gender, *postal;

    //FILE OPENINGS
    f_name = fopen("First Name.txt", "r");
    l_name = fopen("Last Name.txt", "r");
    contact = fopen("Contact.txt", "r");
    gender = fopen("Gender.txt", "r");
    postal = fopen("Postal.txt", "r");

    // GETTING SEARCHABLE POSTAL CODE
    printf("Enter Gender:");
    scanf("%s", from_user.gender);


    int count = 1;
    bool Flag = false;

    for(int i=0; i<value; i++)
    {
        fscanf(f_name, "%s", y.first_name);
        fscanf(l_name, "%s", y.last_name);
        fscanf(contact, "%s", y.contact_no);
        fscanf(gender, "%s", y.gender);
        fscanf(postal, "%s", y.postal_code);

        if((strcmp(from_user.gender, y.gender) == 0))
        {
            Flag = true;

            printf("\n\t\tSearch result for Gender [ %s] - %d\n", from_user.gender, count);
            printf("\t\t________________________________________\n");
            printf("\n\t\tName : %s %s\n\t\tContact : %s\n\t\tGender: %s\n\t\tPostal code: %s\n", y.first_name, y.last_name, y.contact_no, y.gender, y.postal_code);
            count++;
        }
    }

    if(Flag == false)
    {
        printf("\t\tNo Record for Gender < %s > is in the record.\n", from_user.gender);
    }
    else
    {
        printf("\n\t\tTotal records for Gender [ %s ] - %d\n", from_user.gender, --count);
    }

    //FILE CLOSING
    fclose(f_name);
    fclose(gender);
    fclose(postal);
    fclose(contact);
}

void delete_info()
{
    struct phonebook del, del2;

    system("cls");
    system("color 8f"); //Gray
    printf("\n\t\t\t    Option 6 [Delete] selected.\n");

    printf("\nEnter First Name:");
    scanf("%s", del2.first_name);
    printf("\nEnter Last Name:");
    scanf("%s", del2.last_name);
    printf("\nEnter Number:");
    scanf("%s", del2.contact_no);

    //FILE POINTER DECLARATION - Main
    FILE *f_name, *l_name, *contact, *gender, *postal, *Quantity;

    //FILE POINTER DECLARATION - Temp
    FILE *temp_f_name, *temp_l_name, *temp_contact, *temp_gender, *temp_postal;

    //FILE OPENINGS - Reading mode - Main
    f_name = fopen("First Name.txt", "r");
    l_name = fopen("Last Name.txt", "r");
    contact = fopen("Contact.txt", "r");
    gender = fopen("Gender.txt", "r");
    postal = fopen("Postal.txt", "r");

    //FILE OPENINGS - Overwrite mode - Temp
    temp_f_name = fopen("TempFirstName.txt", "w+");
    temp_l_name = fopen("TempLastName.txt", "w+");
    temp_contact = fopen("TempContact.txt", "w+");
    temp_gender = fopen("TempGender.txt", "w+");
    temp_postal = fopen("TempPostal.txt", "w+");


    Quantity = fopen("Quantity.txt", "r");

    //GETTING TOTAL RECORD NUMBER
    int value;  //Hosting the value of total saved records
    fscanf(Quantity,"%d", &value);
    fclose(Quantity);

    for(int i=0; i<value; i++)
    {
        fscanf(f_name, "%s", del.first_name);
        fscanf(l_name, "%s", del.last_name);
        fscanf(contact, "%s", del.contact_no);
        fscanf(gender, "%s", del.gender);
        fscanf(postal, "%s", del.postal_code);

        if((strcmp(del.first_name, del2.first_name) == 0) && (strcmp(del2.contact_no, del.contact_no) == 0))
        {
            continue;
        }
        else
        {
            fprintf(temp_f_name, "%s\n", del.first_name);
            fprintf(temp_l_name, "%s\n", del.last_name);
            fprintf(temp_contact, "%s\n", del.contact_no);
            fprintf(temp_gender, "%s\n", del.gender);
            fprintf(temp_postal, "%s\n", del.postal_code);
        }

    }

    // Decrease value after successful deletion
    --value;
    Quantity = fopen("Quantity.txt", "w+");
    fprintf(Quantity, "%d", value);

    //FILE CLOSING - Quantity
    fclose(Quantity);

    //FILE CLOSING - Main
    fclose(f_name);
    fclose(l_name);
    fclose(gender);
    fclose(postal);
    fclose(contact);

    //FILE CLOSING - Temp
    fclose(temp_f_name);
    fclose(temp_l_name);
    fclose(temp_gender);
    fclose(temp_postal);
    fclose(temp_contact);

    printf("\n\t\t\t\t    Record include\n\n");
    printf("\t\t    Name: %s %s\tContact Number: %s\n\n\t\t      Has been successfully deleted from the record.\n", del2.first_name, del2.last_name, del2.contact_no);

    copy_data();

    printf("\nPress 1 - To delete again\n");
    printf("Press 2 - Go back o menu\n");

    switch(getch())
    {
        case '1': delete_info();
        break;
        case '2': menu();
        break;
        default:
            printf("\t---------------------------------------------\n");
            printf("\t\tWrong method input. Taking you back to menu.\n");
            printf("\t---------------------------------------------\n");
            menu();
    }
}

//COPY DATA AND FROM TEMP FILES TO MAIN FILES AFTER DELETION
void copy_data()
{
    struct phonebook x;
    //FILE POINTER - Main
    FILE *f_name, *l_name, *contact, *gender, *postal, *Quantity;

    //FILE POINTER - Temp
    FILE *temp_f_name, *temp_l_name, *temp_contact, *temp_gender, *temp_postal;

    //FILE OPENINGS - Reading mode - Temp
    temp_f_name = fopen("TempFirstName.txt", "r");
    temp_l_name = fopen("TempLastName.txt", "r");
    temp_contact = fopen("TempContact.txt", "r");
    temp_gender = fopen("TempGender.txt", "r");
    temp_postal = fopen("TempPostal.txt", "r");

    //FILE OPENINGS - Overwrite mode - Main
    f_name = fopen("First Name.txt", "w+");
    l_name = fopen("Last Name.txt", "w+");
    contact = fopen("Contact.txt", "w+");
    gender = fopen("Gender.txt", "w+");
    postal = fopen("Postal.txt", "w+");


    Quantity = fopen("Quantity.txt", "r");

    //GETTING TOTAL RECORD NUMBER
    int value;  //Hosting the value of total saved records
    fscanf(Quantity,"%d", &value);
    fclose(Quantity);


    for(int i=0; i<value; i++)
    {
        fscanf(temp_f_name, "%s", x.first_name);
        fscanf(temp_l_name, "%s", x.last_name);
        fscanf(temp_contact, "%s", x.contact_no);
        fscanf(temp_gender, "%s", x.gender);
        fscanf(temp_postal, "%s", x.postal_code);

        fprintf(f_name, "%s\n", x.first_name);
        fprintf(l_name, "%s\n", x.last_name);
        fprintf(contact, "%s\n", x.contact_no);
        fprintf(gender, "%s\n", x.gender);
        fprintf(postal, "%s\n", x.postal_code);
    }


    //FILE CLOSING - Main
    fclose(f_name);
    fclose(l_name);
    fclose(gender);
    fclose(postal);
    fclose(contact);

    //FILE CLOSING - Temp
    fclose(temp_f_name);
    fclose(temp_l_name);
    fclose(temp_gender);
    fclose(temp_postal);
    fclose(temp_contact);
}

void modify_info()
{
    struct phonebook  modify, user_modify, replace_modify;

    system("cls");
    system("color 3f"); //Aqua
    printf("\n\t\t\t    Option 4 [ Modify ] selected.\n\n");

    // FIND DESIRED RECORD FIRST
    printf("\t\tFind record first.\n\n");

    printf("Enter First name:");
    scanf("%s", user_modify.first_name);
    printf("\nEnter Last name:");
    scanf("%s", user_modify.last_name);
    printf("\nEnter phone:");
    scanf("%s", user_modify.contact_no);


    //FILE POINTERS - Main
    FILE *f_name, *l_name, *contact, *gender, *postal, *Quantity;

    //Temp pointers
    FILE *modify_f_name, *modify_l_name, *modify_contact, *modify_gender, *modify_postal;

    Quantity = fopen("Quantity.txt", "r");
    int value;
    fscanf(Quantity,"%d", &value);
    fclose(Quantity);

    //FILE OPENINGS - Reading mode - Main
    f_name = fopen("First Name.txt", "r");
    l_name = fopen("Last Name.txt", "r");
    contact = fopen("Contact.txt", "r");
    gender = fopen("Gender.txt", "r");
    postal = fopen("Postal.txt", "r");

    //FILE OPENINGS - Temp - Modified storage
    modify_f_name = fopen("ModifiedFirstName.txt", "w+");
    modify_l_name = fopen("ModifiedLastName.txt", "w+");
    modify_contact = fopen("ModifiedContact.txt", "w+");
    modify_gender = fopen("ModifiedGender.txt", "w+");
    modify_postal = fopen("ModifiedPostal.txt", "w+");


    for(int i=0; i<value; i++)
    {
        fscanf(f_name, "%s", modify.first_name);
        fscanf(l_name, "%s", modify.last_name);
        fscanf(contact, "%s", modify.contact_no);
        fscanf(gender, "%s", modify.gender);
        fscanf(postal, "%s", modify.postal_code);

        //FINDING RECORD IN THE LIST
        if ((strcmp(user_modify.first_name, modify.first_name) == 0) && (strcmp(user_modify.contact_no, modify.contact_no) == 0))
        {
            //Get data for replace
            printf("\n\t\tEnter Data you want to replace:\n\n");
            printf("Enter New First Name:");
            scanf("%s", replace_modify.first_name);
            printf("\nEnter New Last Name:");
            scanf("%s", replace_modify.last_name);
            printf("\nEnter new Contact No:");
            scanf("%s", replace_modify.contact_no);
            printf("\nEnter new gender:");
            scanf("%s", replace_modify.gender);
            printf("\nEnter new postal code:");
            scanf("%s", replace_modify.postal_code);

            // Replacing pointer values with new one
            strcpy(modify.first_name, replace_modify.first_name);
            strcpy(modify.last_name, replace_modify.last_name);
            strcpy(modify.contact_no, replace_modify.contact_no);
            strcpy(modify.gender, replace_modify.gender);
            strcpy(modify.postal_code, replace_modify.postal_code);

        }

        fprintf(modify_f_name, "%s\n", modify.first_name);
        fprintf(modify_l_name, "%s\n", modify.last_name);
        fprintf(modify_contact, "%s\n", modify.contact_no);
        fprintf(modify_gender, "%s\n", modify.gender);
        fprintf(modify_postal, "%s\n", modify.postal_code);

    }

    // Giving changes insight
    printf("\n\n\t\t\tData has been Modified.\n");

    printf("\t\t    New record will save as below:\n\n");
    printf("\t\t\t  Name: %s\n", replace_modify.first_name);
    printf("\t\t\t  Contact no: %s\n", replace_modify.contact_no);
    printf("\t\t\t  Gender: %s\n", replace_modify.gender);
    printf("\t\t\t  Postal code: %s\n", replace_modify.postal_code);

    //FILE CLOSING
    fclose(f_name);
    fclose(l_name);
    fclose(contact);
    fclose(gender);
    fclose(postal);

    fclose(modify_f_name);
    fclose(modify_l_name);
    fclose(modify_contact);
    fclose(modify_gender);
    fclose(modify_postal);


    //FILE OPENINGS - overwrite mode - Main
    f_name = fopen("First Name.txt", "w+");
    l_name = fopen("Last Name.txt", "w+");
    contact = fopen("Contact.txt", "w+");
    gender = fopen("Gender.txt", "w+");
    postal = fopen("Postal.txt", "w+");

    //FILE OPENINGS - Reading mode - Temp - Modified storages
    modify_f_name = fopen("ModifiedFirstName.txt", "r");
    modify_l_name = fopen("ModifiedLastName.txt", "r");
    modify_contact = fopen("ModifiedContact.txt", "r");
    modify_gender = fopen("ModifiedGender.txt", "r");
    modify_postal = fopen("ModifiedPostal.txt", "r");


    //Coping modified data to main files
    for(int i=0; i<value; i++)
    {
        fscanf(modify_f_name, "%s", modify.first_name);
        fscanf(modify_l_name, "%s", modify.last_name);
        fscanf(modify_contact, "%s", modify.contact_no);
        fscanf(modify_gender, "%s", modify.gender);
        fscanf(modify_postal, "%s", modify.postal_code);

        fprintf(f_name, "%s\n", modify.first_name);
        fprintf(l_name, "%s\n", modify.last_name);
        fprintf(contact, "%s\n", modify.contact_no);
        fprintf(gender, "%s\n", modify.gender);
        fprintf(postal, "%s\n", modify.postal_code);
    }

    //FILE CLOSING
    fclose(f_name);
    fclose(l_name);
    fclose(contact);
    fclose(gender);
    fclose(postal);

    fclose(modify_f_name);
    fclose(modify_l_name);
    fclose(modify_contact);
    fclose(modify_gender);
    fclose(modify_postal);

    printf("\nPress 1 - To modify again\n");
    printf("Press 2 - Go back o menu\n");

    switch(getch())
    {
        case '1': modify_info();
        break;
        case '2': menu();
        break;
        default:
            printf("\t---------------------------------------------\n");
            printf("\t\tWrong method input. Taking you back to menu.\n");
            printf("\t---------------------------------------------\n");
            menu();
    }
}
