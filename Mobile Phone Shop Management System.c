
/*******************************************************************
********************************************************************

        <<<<<<Daffodil International University>>>>>>>
        _______________________________________________
          Project name:Mobile Phone Shop Management System
          Implementation using C programming language
          Implementation by Mahbub Hasan
          ID number  :183-35-2616
          Department :SWE
          E-mail:mahbub35-2616@diu.edu.bd

**********************************************************************
**********************************************************************/


//Add here some needed header file
#include<stdio.h>   //This header file for stander input and output
#include<windows.h> //This header file for windows
#include<string.h>  //This header file for string
#include<stdlib.h>  //This header file for file
#include<process.h> //This header file for processing
//#include"color.h"   //I have created this header file for color


//Set here preprocessor macro
#define INTER 13
#define BKSP 8
#define PERCENTAGE 37

//Create a structure for using in this program
struct productinfo
{

    char pbrand[12];
    char pmodel[12];
    char pram[12];
    char prom[12];
    char pcamera[12];
    char pdisplay[12];
    char pcolor[12];
    int  pprice;
    char pproductid[12];

}product;


//Declare here character type variable
    char ch=-1;
    char username[12];
    char password[32];
    char vusername[12];
    char vpassword[32];
    char brand[12];
    char model[12];
    char ram[12];
    char rom[12];
    char camera[12];
    char display_size[12];
    char color[12];
    char productid[12];
    char deleteid[12];
    char editid[12];
    char search[12];
    char customer_name[12];
    char customer_number[12];
    char selling_date[12];
    char afname[12];
    char alname[12];
    char agender[12];
    char amail[25];

//Declare here integer type variable
    int counter=0;
    int vat;
    int selling_price;
    int i;

//Declare here float type variable
    float sum=0;



/**********************************************************************
Function declaration
**********************************************************************/

void AddProduct();
void SearchProduct();
void EditProduct();
void DeleteProduct();
void addmin_profile();
void newser();
void singup();
void login();
void userchoice();
void admin();
void user();
void useroption();
void UserSearch();
void settings();
void option();
void more();
void contact();
void AboutApplication();
void changePassword();
void loading();
void Amount_Topsold();

//Main function
void main()
{
    system("cls");
    display();
    SetColor(555);
    printf("\n\t\tAccess System\n\t\t*************\n");
    SetColor(12);
    printf("\t\t1.Admin\n");
    printf("\t\t2.User\n");
    printf("\t\t0.Exit\n\n");

    SetColor(70);
    printf("\t\tPlease enter your choice:");
    fflush(stdin);
    scanf("%c",&ch);
    switch(ch)
    {
    case '1':
        {
            system("cls");
            display();
            admin();
        }
        break;
    case '2':
        {
            system("cls");
            display();
            user();
        }
        break;
    case '0':exit(0);
        break;
        default:
            {
                system("cls");
                display();
                SetColor(4);
                printf("\t\tSorry,you have selected invalid option!\n\n");
                main();
            }
    }

}


//Add new product
void AddProduct()
{

   system("cls");
   display();
   SetColor(555);
   printf("\t\tAdd a new product\n");
   printf("\t\t**************************\n");
   SetColor(70);
   fflush(stdin);
   printf("\t\tEnter phone brand:");
   gets(product.pbrand);
   fflush(stdin);
   printf("\t\tEnter phone model:");
   gets(product.pmodel);
   fflush(stdin);
   printf("\t\tEnter phone ram:");
   gets(product.pram);
   fflush(stdin);
   printf("\t\tEnter phone rom:");
   gets(product.prom);
   fflush(stdin);
   printf("\t\tEnter phone camera:");
   gets(product.pcamera);
   fflush(stdin);
   printf("\t\tEnter phone display:");
   gets(product.pdisplay);
   fflush(stdin);
   printf("\t\tEnter phone color:");
   gets(product.pcolor);
   printf("\t\tEnter phone price:");
   scanf("%d",&product.pprice);
   printf("\t\tEnter product id:");
   fflush(stdin);
   gets(product.pproductid);

   SetColor(555);
   printf("\n\n\t\tDo you want to save this product?");
   SetColor(12);
   printf("\n\t\t1.Yes\n\t\t0.No");
   SetColor(70);
   printf("\n\t\tEnter choice:");
   fflush(stdin);
   scanf("%c",&ch);

   if(ch=='1')
   {

     FILE *fp;
     fp=fopen("product.txt","a");
     fprintf(fp,"\n%s %s %s %s %s %s %s %d %s\n",product.pbrand,product.pmodel,product.pram,product.prom,product.pcamera,product.pdisplay,product.pcolor,product.pprice,product.pproductid);
     fclose(fp);
     system("cls");
     display();
     SetColor(90);
     printf("\n\t\tPlease wait saving product information");
     loading();
     system("cls");
     display();
     SetColor(90);
     printf("\t\tProduct information has been saved successfully....!!!\n\n");
     userchoice();
   }
   else option();

}


//Customer Billing System or sell product
void SellProduct()
{
    system("cls");
    display();
    SetColor(555);
    printf("\n\t\tCustomer Billing System:\n");
    printf("\t\t------------------------\n");
    SetColor(70);
    printf("\t\tEnter customer full name:");
    fflush(stdin);
    gets(customer_name);
    printf("\t\tEnter customer contact number:");
    gets(customer_number);
    printf("\t\tEnter date:");
    gets(selling_date);
    printf("\t\tEnter model number:");
    gets(model);
    printf("\t\tEnter price:");
    scanf("%d",&selling_price);
    printf("\t\tEnter VAT tax %c:",PERCENTAGE);
    scanf("%d",&vat);

    system("cls");
    display();
    SetColor(555);
    printf("\n\n\t\tCustomer Billing System:\n");
    printf("\t\t------------------------\n");
    SetColor(12);
    printf("\t\tCustomer name       :%s\n",customer_name);
    printf("\t\tContact number      :%s\n",customer_number);
    printf("\t\tPhone model number  :%s\n",model);
    printf("\t\tDate                :%s\n",selling_date);
    printf("\t\tPhone price         :%d tk\n",selling_price);
    printf("\t\tVAT tax             :%d %c\n",vat,PERCENTAGE);
    sum=selling_price+(selling_price*vat)/(100.00);
    printf("\n\t\tTotal price       :%.2f tk\n\n\n",sum);

    FILE *fp3;
    fp3=fopen("soldproduct.txt","a");
    fprintf(fp3,"%s %.2f\n",model,sum);
    fclose(fp3);

    userchoice();

}

//Displaying all product
void DisplayProduct()
{

    system("cls");
    display();
    SetColor(555);
    printf("\n\t\t\xB2\xB2\xB2 List of all product: \xB2\xB2\xB2\n");
    printf("\t\t============================\n\n");
    SetColor(12);

    FILE *fp;
    fp=fopen("product.txt","r");

    counter=0;
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %s",&brand,&model,&ram,&rom,&camera,&display_size,&color,&selling_price,&productid)!=EOF)
    {
        printf("\t\tPhone brand:%s\n",brand);
        printf("\t\tPhone model:%s\n\n",model);
        counter++;
    }
    fclose(fp);

    if(counter==0)
        printf("\n\t\tSorry,no product found!\n\n");
    userchoice();

}


//Search a product for admin
void SearchProduct()
{
    system("cls");
    display();
    SetColor(555);
    printf("\n\t\tSearching a product:\n");
    printf("\t\t====================\n");
    SetColor(70);
    printf("\t\tEnter phone model number:");
    fflush(stdin);
    gets(search);

    system("cls");
    display();
    SetColor(90);
    printf("\n\t\tPlease wait searching");
    loading();
    system("cls");
    display();
    SetColor(555);
    printf("\n\t\tProduct information:\n");
    printf("\t\t====================\n");
    SetColor(12);
    FILE *fp;
    fp=fopen("product.txt","r");

    counter=0;
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %s",&brand,&model,&ram,&rom,&camera,&display_size,&color,&selling_price,&productid)!=EOF)
    {
        if(strcmp(search,model)==0)
        {

          printf("\t\t--------------------------\n");
          printf("\t\tBrand      :%s\n",brand);
          printf("\t\tModel      :%s\n",model);
          printf("\t\tRAM        :%s\n",ram);
          printf("\t\tROM        :%s\n",rom);
          printf("\t\tCamera     :%s\n",camera);
          printf("\t\tDisplay    :%s\n",display_size);
          printf("\t\tColor      :%s\n",color);
          printf("\t\tPrice      :%d tk\n",selling_price);
          printf("\t\tProduct id :%s\n\n",productid);
          counter++;

        }
    }
    fclose(fp);

    if(counter==0)
        printf("\n\t\tSorry,no product found!\n\n");

    userchoice();

}

//Search a product for user
void UserSearch()
{
    system("cls");
    display();
    SetColor(555);
    printf("\n\t\tSearching a product:\n");
    printf("\t\t====================\n");
    SetColor(70);
    printf("\t\tEnter phone model number:");
    fflush(stdin);
    gets(search);

    system("cls");
    display();
    SetColor(90);
    printf("\n\t\tPlease wait searching");
    loading();
    system("cls");
    display();
    SetColor(555);
    printf("\n\t\tProduct information:\n");
    printf("\t\t====================\n");
    SetColor(12);
    FILE *fp;
    fp=fopen("product.txt","r");

    counter=0;
    while(fscanf(fp,"%s %s %s %s %s %s %s %d %s",&brand,&model,&ram,&rom,&camera,&display_size,&color,&selling_price,&productid)!=EOF)
    {
        if(strcmp(search,model)==0)
        {

          printf("\t\t--------------------------\n");
          printf("\t\tBrand      :%s\n",brand);
          printf("\t\tModel      :%s\n",model);
          printf("\t\tRAM        :%s\n",ram);
          printf("\t\tROM        :%s\n",rom);
          printf("\t\tCamera     :%s\n",camera);
          printf("\t\tDisplay    :%s\n",display_size);
          printf("\t\tColor      :%s\n",color);
          printf("\t\tPrice      :%d tk\n",selling_price);
          printf("\t\tProduct id :%s\n\n",productid);
          counter++;

        }
    }
    fclose(fp);

    if(counter==0)
    printf("\n\t\tSorry,no product found!\n\n");
    SetColor(555);
    printf("\t\tDo you want go back?\n\t\t********************\n");
    SetColor(12);
    printf("\t\t1.Yes\n");
    printf("\t\t0.No\n");
    SetColor(70);
    printf("\t\tEnter your choice:");
    fflush(stdin);
    scanf("%c",&ch);
    switch(ch)
    {
    case '1':useroption();
        break;
    default:exit(0);
    }

}


//Product deleting system
void DeleteProduct()
{
  system("cls");
  display();
  SetColor(555);
  printf("\n\t\tProduct deleting system:\n");
  printf("\t\t========================\n");
  SetColor(70);
  printf("\t\tEnter product id for deleting:");
  fflush(stdin);
  gets(deleteid);

  FILE *fp,*fp1;
  fp=fopen("product.txt","r");
  fp1=fopen("replica.txt","w");

  counter=0;
  rewind(fp);

  while(fscanf(fp,"%s %s %s %s %s %s %s %d %s",&brand,&model,&ram,&rom,&camera,&display_size,&color,&selling_price,&productid)!=EOF)
  {

      if(strcmp(deleteid,productid)==0)
      {
           system("cls");
           display();
           SetColor(555);
           printf("\n\t\tProduct editing system:\n");
           printf("\t\t========================\n");
           SetColor(12);
           printf("\t\tDo you want to delete this product?\n");
           printf("\t\t1.Yes\n\t\t0.No\n");
           SetColor(70);
           printf("\t\tEnter your choice:");
           fflush(stdin);
           scanf("%c",&ch);
           if(ch=='1')
           counter++;
           else
           {
           fprintf(fp1,"\n%s %s %s %s %s %s %s %d %s\n",brand,model,ram,rom,camera,display_size,color,selling_price,productid);
           counter++;
           }
      }

      else
        fprintf(fp1,"\n%s %s %s %s %s %s %s %d %s\n",brand,model,ram,rom,camera,display_size,color,selling_price,productid);

  }

  fclose(fp);
  fclose(fp1);

  if(counter!=0)
  {
    system("cls");
    display();
    SetColor(90);
    printf("\n\t\tProduct has been deleted successfully....!\n\n");
  }
  else
  {
   system("cls");
   display();
   SetColor(4);
   printf("\n\t\tSorry,product not found!\n\n");
  }

  remove("product.txt");
  rename("replica.txt","product.txt");

  userchoice();

}


//Product editing system
void EditProduct()
{
  system("cls");
  display();
  SetColor(555);
  printf("\n\t\tProduct editing system:\n");
  printf("\t\t========================\n");
  SetColor(70);
  printf("\t\tEnter product id for editing:");
  fflush(stdin);
  gets(editid);
  system("cls");
  display();


  FILE *fp,*fp1;
  fp=fopen("product.txt","r");
  fp1=fopen("replica.txt","w");

  counter=0;
  rewind(fp);
  while(fscanf(fp,"%s %s %s %s %s %s %s %d %s",&brand,&model,&ram,&rom,&camera,&display_size,&color,&selling_price,&productid)!=EOF)
  {

 if(strcmp(editid,productid)==0)
  {

   system("cls");
   display();
   SetColor(555);
   printf("\n\t\tProduct editing system:\n");
   printf("\t\t========================\n");
   SetColor(70);
   fflush(stdin);
   printf("\t\tEnter phone brand:");
   gets(brand);
   printf("\t\tEnter phone model:");
   gets(model);
   printf("\t\tEnter phone ram:");
   gets(ram);
   printf("\t\tEnter phone rom:");
   gets(rom);
   printf("\t\tEnter phone camera:");
   gets(camera);
   printf("\t\tEnter phone display:");
   gets(display_size);
   printf("\t\tEnter phone color:");
   gets(color);
   printf("\t\tEnter phone price:");
   fflush(stdin);
   scanf("%d",&selling_price);
   printf("\t\tEnter product id:");
   fflush(stdin);
   gets(productid);
   system("cls");
   display();
   SetColor(555);
   printf("\n\t\tProduct editing system:\n");
   printf("\t\t========================\n");
   SetColor(12);
   printf("\t\tDo you want to save this update?\n");
   printf("\t\t1.Yes\n\t\t0.No\n");
   SetColor(70);
   printf("\t\tEnter your choice:");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='1')
   fprintf(fp1,"\n%s %s %s %s %s %s %s %d %s\n",brand,model,ram,rom,camera,display_size,color,selling_price,productid);
   else option();
   counter++;

  }

 else
 fprintf(fp1,"\n%s %s %s %s %s %s %s %d %s\n",brand,model,ram,rom,camera,display_size,color,selling_price,productid);

  }

  fclose(fp);
  fclose(fp1);

  if(counter!=0)
  {
    system("cls");
    display();
    SetColor(90);
    printf("\t\tPlease wait updating information");
    loading();
    system("cls");
    display();
    SetColor(90);
    printf("\n\t\tProduct information has been updated successfully!\n\n");
  }
  else
  {
   system("cls");
   display();
   SetColor(4);
   printf("\n\t\tSorry,product not found!\n\n");
  }

  remove("product.txt");
  rename("replica.txt","product.txt");

  userchoice();

}

//If user don't have a account than this function will be called for creating a new account
void singup()
{

   system("cls");
   display();
   SetColor(555);
   printf("\n\t\tRegistration System:\n\t\t********************\n");
   SetColor(70);
   printf("\t\tFirst name   :");
   fflush(stdin);
   gets(afname);
   printf("\t\tLast name    :");
   fflush(stdin);
   gets(alname);
   printf("\t\tGender       :");
   fflush(stdin);
   gets(agender);
   printf("\t\tE-mail       :");
   fflush(stdin);
   gets(amail);
   printf("\t\tUser name    :");
   fflush(stdin);
   gets(username);
   printf("\t\tPassword     :");
   fflush(stdin);
   i=0;
   while(i<32)
    {
        if(INTER==(ch=getch()))
        {
            password[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
            i--;
            printf("\b \b");
            }
        }
        else
        {
            password[i]=ch;
            printf("*");
            i++;
        }
    }
   system("cls");
   display();
   SetColor(555);
   printf("\n\t\tDo you want to create new account?");
   SetColor(12);
   printf("\n\t\t1.Yes\n\t\t0.No\n");
   SetColor(70);
   printf("\t\tEnter choice:");
   fflush(stdin);
   scanf("%c",&ch);
   system("cls");
   display();

   if(ch=='1')
   {
     FILE *fp1;//Create a file pointer
     fp1=fopen("singup.txt","w");
     fprintf(fp1,"%s %s %s %s %s %s",afname,alname,agender,amail,username,password);
     fclose(fp1);

     system("cls");
     display();
     SetColor(90);
     printf("\n\t\tPlease wait saving account");
     loading();
     system("cls");
     display();
     SetColor(90);
     printf("\t\tRegistration has been successful.....!!!\n\n");
     userchoice();
   }
   else admin();

 }




//If user have a account than this function will be called
void login()
{
  system("cls");
  display();
  SetColor(555);
  printf("\n\t\tLogin System:\n\t\t*************\n");
  SetColor(70);
  printf("\t\tUser name  :");
  fflush(stdin);
  gets(vusername);

  printf("\n\t\tPassword   :");
  fflush(stdin);
    i=0;
    while(i<32)
    {
        if(INTER==(ch=getch()))
        {
            vpassword[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
            i--;
            printf("\b \b");
            }
        }
        else
        {
            vpassword[i]=ch;
            printf("*");
            i++;
        }
    }

   FILE *fp1;
   fp1=fopen("singup.txt","r");
   fscanf(fp1,"%s %s %s %s %s %s",&afname,&alname,&agender,&amail,&username,&password);
   fclose(fp1);

   if(strcmp(vpassword,password)==0 && strcmp(vusername,username)==0)
   {

       system("cls");
       display();
       SetColor(90);
       printf("\n\t\tPlease wait loading");
       loading();
       system("cls");
       display();
       SetColor(90);
       printf("\n\t\tLogin successful.......!!!\n\n");
       userchoice();

   }
   else
   {

       system("cls");
       display();
       SetColor(4);
       printf("\n\t\tSorry,your user name or password not matched!\n\n");
       admin();

   }

}

//After completing one operation this function will be called for user
void userchoice()
{

    SetColor(555);
    printf("\t\tBack to go main menu:\n");
    printf("\t\t____________________\n");
    SetColor(12);
    printf("\t\t1.Yes\n");
    printf("\t\t0.No\n");
    SetColor(70);
    printf("\t\tEnter choice:");
    fflush(stdin);
    scanf("%c",&ch);

    switch(ch)
    {
    case '1':{
              system("cls");
              display();
              option();
             }
        break;
    case '0':exit(0);
        break;
    default:
        {
            system("cls");
            display();
            SetColor(4);
            printf("\n\t\tSorry,you have selected invalid option!\n");
            userchoice();
        }
    }


}

//Option function
void option()
{

    SetColor(555);
    printf("\t\tMain menu:\n");
    printf("\t\t__________\n");
    SetColor(12);
    printf("\t\t1.My profile\n");
    printf("\t\t2.Add new product\n");
    printf("\t\t3.Sell product\n");
    printf("\t\t4.Show all product\n");
    printf("\t\t5.Search product\n");
    printf("\t\t6.Delete product\n");
    printf("\t\t7.Edit product\n");
    printf("\t\t8.Settings\n");
    printf("\t\t9.More\n");
    printf("\t\t0.Exit\n");
    SetColor(30);
    printf("\t\t==================\n");
    SetColor(70);
    printf("\t\tEnter your choice:");
    fflush(stdin);
    scanf("%c",&ch);

 switch(ch)
 {
 case '1':addmin_profile();
    break;
 case '2':AddProduct();
    break;
 case '3':SellProduct();
    break;
 case '4':DisplayProduct();
    break;
 case '5':SearchProduct();
    break;
 case '6':DeleteProduct();
    break;
 case '7':EditProduct();
    break;
 case '8':settings();
    break;
 case '9':more();
    break;
 case '0':exit(0);
    break;
    default:
        {
            system("cls");
            display();
            SetColor(4);
            printf("\n\t\tSorry,you have selected invalid option!\n");
            option();
        }

 }

}

//Display function created for displaying project name and shop name
void display()
{
    SetColor(70);
    printf("\n\n\t\t\t Mobile Phone Shop Management System\n");
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Daffodil Computer Limited (DCL) \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    SetColor(30);
    printf("\t\t=====================================================\n\n");
}

//User function created for sing up or log in
void admin()
{

    SetColor(555);
    printf("\n\t\tAccess System\n\t\t*************\n");
    SetColor(700);
    printf("\t\t1.Sing up\n");
    printf("\t\t2.Login\n");
    printf("\t\t0.Exit\n\n");

    SetColor(70);
    printf("\t\tPlease enter your choice:");
    fflush(stdin);
    scanf("%c",&ch);
    switch(ch)
    {
    case '1':singup();
        break;
    case '2':login();
        break;
    case '0':exit(0);
        break;
        default:
            {
                system("cls");
                display();
                SetColor(4);
                printf("\t\tSorry,you have selected invalid option!\n\n");
                admin();
            }
    }
}

//User Login System
void user()
{

  SetColor(555);
  printf("\n\t\tUser Login System:\n\t\t******************\n");
  SetColor(70);
  printf("\t\tUser name  :");
  fflush(stdin);
  gets(vusername);

  printf("\n\t\tPassword   :");
  fflush(stdin);
    i=0;
    while(i<32)
    {
        if(INTER==(ch=getch()))
        {
            vpassword[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
            i--;
            printf("\b \b");
            }
        }
        else
        {
            vpassword[i]=ch;
            printf("*");
            i++;
        }
    }

   FILE *fp2;
   fp2=fopen("newuser.txt","r");
   //fscanf(fp2,"%s %s",&username,&password);
   counter=0;
   rewind(fp2);

   while(fscanf(fp2,"%s %s",&username,&password)!=EOF)
   {
      if(strcmp(vpassword,password)==0 && strcmp(vusername,username)==0)
      {
       counter++;
       system("cls");
       display();
       SetColor(90);
       printf("\n\t\tPlease wait loading");
       loading();
       system("cls");
       display();
       SetColor(90);
       printf("\n\t\tLogin successful.......!!!\n\n");
       useroption();

     }

   }
   fclose(fp2);

   if(counter==0)
   {
       system("cls");
       display();
       SetColor(4);
       printf("\n\t\tSorry,user name or password not matched...!!!\n\n");
       SetColor(555);
       printf("\t\tOption\n\t\t******\n");
       SetColor(12);
       printf("\t\t1.Try again\n");
       printf("\t\t2.Back\n");
       printf("\t\t0.Exit\n");
       SetColor(70);
       printf("\t\tEnter choice:");
       fflush(stdin);
       scanf("%c",&ch);
       system("cls");
       display();
       if(ch=='1')
       user();
       if(ch=='2')
       main();
       else exit(0);
   }

}

//By the help of this function user will get more security
void settings()
{
   system("cls");
   display();
   SetColor(555);
   printf("\t\tOption > Settings\n");
   printf("\t\t*****************\n");
   SetColor(12);
   printf("\t\t1.Change password\n");
   printf("\t\t2.Back\n");
   printf("\t\t0.Log out\n");
   SetColor(70);
   printf("\t\tEnter your choice:");
   fflush(stdin);
   scanf("%c",&ch);

   switch(ch)
   {
   case '1':changePassword();
    break;
   case '2':
       {
       system("cls");
       display();
       option();
       }
    break;
   case '0':exit(0);
    break;
    default:settings();
   }
}

//By the help of this function user will be able to change password
void changePassword()
{
   system("cls");
   display();
   SetColor(555);
   printf("\t\tSettings > Change password\n");
   printf("\t\t**************************\n");
   SetColor(70);
   printf("\t\tEnter your old password:");
   fflush(stdin);
    i=0;
   while(i<32)
    {
        if(INTER==(ch=getch()))
        {
            vpassword[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
            i--;
            printf("\b \b");
            }
        }
        else
        {
            vpassword[i]=ch;
            printf("*");
            i++;
        }
    }

   FILE *fp1;
   fp1=fopen("singup.txt","r");
   fscanf(fp1,"%s %s %s %s %s %s",&afname,&alname,&agender,&amail,&username,&password);
   fclose(fp1);

   if(strcmp(vpassword,password)==0)
 {

   FILE *fp1;
   fp1=fopen("singup.txt","w");
   printf("\n\t\tEnter new password:");
   fflush(stdin);
   for(int i=0;i<32;i++)
   {

    if(INTER==(ch=getch()))
    break;
    else
    {
        password[i]=ch;
        printf("*");
    }

   };
   fprintf(fp1,"%s %s",username,password);
   fclose(fp1);
   system("cls");
   display();
   SetColor(90);
   printf("\n\t\tYour password has been changed successfully!\n\n");
   userchoice();

 }
   else
   {

       system("cls");
       display();
       SetColor(4);
       printf("\n\t\tSorry,your password not matched!\n\n");
       SetColor(555);
       printf("\t\tSettings > Change password\n");
       printf("\t\t**************************\n");
       SetColor(12);
       printf("\t\t1.Change password\n");
       printf("\t\t2.Back to main menu\n");
       printf("\t\t3.Log out\n");
       SetColor(70);
       printf("\t\tEnter your choice:");
       fflush(stdin);
       scanf("%c",&ch);

       switch(ch)
       {
         case '1':changePassword();
           break;
         case '2':
             {
                system("cls");
                display();
                option();
             }
           break;
         case '3':exit(0);
           break;
         default:settings();
       }


   }
}

//For getting more option
void more()
{

   system("cls");
   display();
   SetColor(555);
   printf("\t\tOption > More:\n");
   printf("\t\t**************\n");
   SetColor(12);
   printf("\t\t1.About this application\n");
   printf("\t\t2.Contact with me\n");
   printf("\t\t3.Back\n");
   SetColor(70);
   printf("\t\tEnter your choice:");
   fflush(stdin);
   scanf("%c",&ch);

   switch(ch)
   {
   case '1':AboutApplication();
    break;
   case '2':contact();
    break;
   case '3':
       {
           system("cls");
           display();
           option();
       }
    break;
    default:more();
   }

}

//About this application
void AboutApplication()
{
    system("cls");
    display();
    printf("\n\t\tThis application use for controlling mobile\n\t\tshop of Daffodil Computer Limited (DCL).\n\n");
    printf("\t\tThank You!!!\n");
    printf("\t\t=============================================\n\n");

    userchoice();
}


//Display contact information of programmer
void contact()
{
    system("cls");
    SetColor(60);
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2 Contact Information \xB2\xB2\xB2\xB2\xB2\xB2\n");
    SetColor(30);
    printf("\t\t=================================\n\n");
    printf("\t\tName    :Mahbub Hasan\n");
    printf("\t\tID      :183-35-2616\n");
    printf("\t\tContact :+8801623218618\n");
    printf("\t\tE-mail  :mahbub35-2616@diu.edu.bd\n");
    printf("\t\tFacebook:https://www.facebook.com/mahbubhswe\n\n");
    printf("\t\tThank You!!!\n");
    printf("\t\t=================================\n\n");

    userchoice();

}

//Admin profile
void addmin_profile()
{

    system("cls");
    FILE *fp1;
    fp1=fopen("singup.txt","r");
    fscanf(fp1,"%s %s %s %s %s %s",&afname,&alname,&agender,&amail,&username,&password);
    fclose(fp1);
    SetColor(60);
    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2 My Profile \xB2\xB2\xB2\xB2\xB2\xB2\n");
    SetColor(30);
    printf("\t\t========================\n\n");
    printf("\t\tName        :%s %s\n",afname,alname);
    printf("\t\tGender      :%s\n",agender);
    printf("\t\tE-mail      :%s\n",amail);
    printf("\t\tUser name   :%s\n",username);
    printf("\t\tPassword    :%s\n",password);
    printf("\t\t========================\n\n");
    SetColor(555);
    printf("\t\tOption\n\t\t******\n");
    SetColor(12);
    printf("\t\t1.Add new user\n");
    printf("\t\t2.Total amount and top sold product\n");
    printf("\t\t0.Back\n");
    SetColor(70);
    printf("\t\tEnter choice:");
    fflush(stdin);
    scanf("%c",&ch);

    switch(ch)
    {
     case '1':newuser();
        break;
     case '2':Amount_Topsold();
        break;
     case '0':
         {
             system("cls");
             display();
             option();
         }
        break;
     default:addmin_profile();

    }
}

//Create user account
void newuser()
{

   system("cls");
   display();
   SetColor(555);
   printf("\n\t\tCreate user account:\n\t\t********************\n");
   SetColor(70);
   printf("\t\tUser name    :");
   fflush(stdin);
   gets(username);
   printf("\t\tPassword     :");
   fflush(stdin);
   i=0;
   while(i<32)
    {
        if(INTER==(ch=getch()))
        {
            password[i]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(i>0)
            {
            i--;
            printf("\b \b");
            }
        }
        else
        {
            password[i]=ch;
            printf("*");
            i++;
        }
    }
   system("cls");
   display();
   SetColor(555);
   printf("\n\t\tDo you want to create new user account?");
   SetColor(12);
   printf("\n\t\t1.Yes\n\t\t0.No\n");
   SetColor(70);
   printf("\t\tEnter choice:");
   fflush(stdin);
   scanf("%c",&ch);
   system("cls");
   display();

   if(ch=='1')
   {
     FILE *fp2;//Create a file pointer
     fp2=fopen("newuser.txt","a");
     fprintf(fp2,"%s %s\n",username,password);
     fclose(fp2);

     system("cls");
     display();
     SetColor(90);
     printf("\n\t\tPlease wait saving account");
     loading();
     system("cls");
     display();
     SetColor(90);
     printf("\t\tUser account has been created successfully.....!!!\n\n");
     SetColor(555);
     printf("\t\tBack?\n\t\t*****\n");
     SetColor(12);
     printf("\t\t1.Yes\n");
     printf("\t\t0.No\n");
     SetColor(70);
     printf("\t\tEnter choice:");
     fflush(stdin);
     scanf("%c",&ch);
     if(ch=='1')
     addmin_profile();
     else option();
   }
}

//User Menu
void useroption()
{
    system("cls");
    display();
    SetColor(555);
    printf("\t\tUser Menu\n\t\t*********\n");
    SetColor(12);
    printf("\t\t1.Search\n");
    printf("\t\t0.Exit\n");
    SetColor(70);
    printf("\t\tEnter your choice:");
    fflush(stdin);
    scanf("%c",&ch);
    switch(ch)
    {
    case '1':UserSearch();
        break;
    default:exit(0);
    }

}

//Loading
void loading()
{
    for(int i=0;i<13;i++)
    {
       Sleep(110);
       printf(".");
    }
}

void Amount_Topsold()
{
    system("cls");
    display();
    SetColor(555);
    printf("\t\tSold product information:\n\t\t*************************\n");
    SetColor(30);
   FILE *fp3;
   fp3=fopen("soldproduct.txt","r");
   int cx,c5,c6,c7,c8,c9,count;
   cx=c5=c6=c7=c8=c9=count=0;
   sum=0;
   while(fscanf(fp3,"%s %f",&model,&selling_price)!=EOF)
   {
       count++;
       sum=sum+selling_price;
       if(strcmp(model,"iPhonex")==0)
        cx++;
      else if(strcmp(model,"iPhone5")==0)
        c5++;
       else if(strcmp(model,"iPhone6")==0)
        c6++;
       else if(strcmp(model,"iPhone7")==0)
        c7++;
        else if(strcmp(model,"iPhone8")==0)
        c8++;
        else if(strcmp(model,"iPhone9")==0)
        c9++;
   }
   fclose(fp3);
  int max=cx;
  if(max<c5)
    max=c5;
  else if(max<c6)
    max=c6;
  else if(max<c7)
    max=c7;
  else if(max<c8)
    max=c8;
  else if(max<c9)
    max=c9;

  printf("\t\tTotal amount           : %.2f tk\n",sum);
  printf("\t\tTotal sold product     : %d\n",count);
  if(max==cx)
    printf("\t\tTop sold product       : iPhoneX\n\n");
  if(max==c5)
    printf("\t\tTop sold product       : iPhone5\n\n");
  if(max==c6)
    printf("\t\tTop sold product       : iPhone6\n\n");
  if(max==c7)
    printf("\t\tTop sold product       : iPhone7\n\n");
  if(max==c8)
    printf("\t\tTop sold product       : iPhone8\n\n");
  if(max==c9)
    printf("\t\tTop sold product       : iPhone9\n\n");
    userchoice();

}



//How to Change Text Color in CodeBlocks Console Window
void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}


/***********************************************************************************
                                Thank You!
************************************************************************************/
