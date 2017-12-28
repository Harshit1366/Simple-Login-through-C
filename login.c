#include<stdio.h>
//#include"header.h"
//#include<stdlib.h>
#include<string.h>
#include<stdlib.h>
#define p printf
#define s scanf
struct r
{
unsigned int age,add,pass;
char gen,email[50],name[50],user[50];
long unsigned int phone;
}reg;

FILE *fp;

/*void fun()
{
char dis[100];
fp=fopen(reg.user,"a");
p("Enter your disease : ");
s(" %s",dis);
fprintf(fp,"%s",dis);
fclose(fp);}*/

void username()
{
fp=fopen("register.txt","a+");
//int found=0;
char aim[50];
p("\nCreate a username : ");
s(" %s",aim);
if(fp!=NULL)
{
while(fscanf(fp," %s",reg.user)!=EOF)
{
if(strcmp(reg.user,aim)==0)
{
//flag=1;
p("\n\tUsername already exists!\tPlease choose another username!\n");
return username();
//found++;
}
}
}
strcpy(reg.user,aim);
fflush(stdin);
fprintf(fp," %s",reg.user);
fclose(fp);
}

void password()
{
fp=fopen("register.txt","a");
long unsigned int pas;
p("\nCreate a password with digits only : ");
s("%u",&reg.pass);
p("\nPlease Confirm your password : ");
s("%u",&pas);
if(reg.pass==pas)
p("Password is Confirmed!");
else
{
p("Password is not Confirmed!");
return password();
}
//fflush(stdin);
fprintf(fp," %u\n",reg.pass);
fclose(fp);
}

void regi()
{
fp=fopen("register.txt","a");
p("\nEnter your Name : ");
s(" %s",reg.name);
fflush(stdin);
p("\nEnter your Gender (m/f) : "); 
s(" %c",&reg.gen);
fflush(stdin);
p("\nEnter your age : ");
s("%u",&reg.age);
fflush(stdin);
p("\nEnter your contact number : ");
s("%lu",&reg.phone);
fflush(stdin);
p("\nEnter your email address : ");
s(" %s",reg.email);
fflush(stdin);
p("\nEnter your address : ");
s("%u",&reg.add);
fflush(stdin);
fprintf(fp,"%s %c %u %lu %s %u",reg.name,reg.gen,reg.age,reg.phone,reg.email,reg.add);
fclose(fp);
username();

password();
//fwrite(&reg,sizeof(reg),1,fp);
//fprintf(fp,"%s %c %u %lu %s %u %s %lu\n",reg.name,reg.gen,reg.age,reg.phone,reg.email,reg.add,reg.user,reg.pass);

}

void login()
{
int found=0,f1,f2;
int flag;
char nam[50],a;
long unsigned int pa;
fp=fopen("register.txt","r");
p("Enter username : ");
s("%s",nam);
p("Enter password : ");
s("%u",&pa);
//while(fscanf(fp," %s%lu",reg.user,&reg.pass)!=EOF)
while(fread(&reg,sizeof(reg),1,fp)==1)
{
//p("!");
if(strcmp(reg.user,nam)==0) 
f1;
if(reg.pass==pa)
f2;
if(f1 && f2)
{
//flag=1;
p("LOGIN SUCCESSFUL!\n\nYou are logged in as %s!\n\n\n\t\t\t*****WELCOME %s*****",reg.user,reg.name);
//fun();
}
else
{
p("INVALID LOGIN!\n\n");
p("Wanna try again (y/n)? ");
s(" %c",&a);
if(a=='y'||a=='Y')
return login();
else
return exit(1);
}
found++;
}
//if(flag==1)
//{p("LOGIN SUCCESSFUL!\n\nYou are logged in as %s!\n\n\n\t\t\t*****WELCOME %s*****",reg.user,reg.name);fun();}
fclose(fp);
}

void main()
{
unsigned int a;
p("Press 1 to register otherwise press 2 to login : ");
s("%u",&a);
switch(a)
{
case 1:
regi();
break;
case 2 : login();
break;
default :
{
p("INVALID OPERATOR !\n\n\tTHANKYOU FOR ACCESING US!");
}
}
}





