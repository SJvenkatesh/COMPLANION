#include<stdio.h>

struct police {
int no;
char name[50];
char area[50];
char type[50];
char phone[50];
char age[100];
char sex[50];
char des[1000];
char mail[100];
char name1;
int id;
// char policenumber[50];
};
FILE *file;
char name1(int id);
void input(struct police *p);
void display(struct police po);
void write_police();
void display_sp();
void display_sn(int n);
void modify_police();
void delete_police();
void entry_menu();
//void policenumber();
int main()
{
    
int choice;
do
{
printf("\n\nMain menu");
printf("\n1.Entry Menu");
printf("\n2.Exit Menu");
printf("\nPlease select your choice(1-2):");
scanf("%d",&choice);
switch(choice)
{
case 1:
entry_menu();
break;
}
}while(choice!=2);
return 0;
}
char police_name(int id)
{
if(id>1 && id<100)
{
return 'A';
// return 'Police no-9441532436';
}
else if(id>100 && id<200)
{
return 'B';
// return 'Police no-8985875421';
}
else if(id>200 && id<300)
{
return 'C';
// return 'Police no-9912356102';9
}
else if(id>300 && id<400)
{
return 'D';
// return 'Police no-9182996804';
}
else
{
return 'E';
// return 'Police no-8048253690';
}
}
void input(struct police *p)
{
printf("\nEnter the no:");
scanf("%d",&p->no);
fflush(stdin);
printf("\nEnter the name of the person: ");
gets(p->name);
printf("\nEnter the area: ");
gets(p->area);
printf("\nEnter the type: ");
gets(p->type);
printf("\nEnter phone number: ");
gets(p->phone);
printf("\nEnter the age: ");
gets(p->age);
printf("\nEnter the gender: ");
gets(p->sex);
printf("\nEnter the description of the complaint");
gets(p->des);
printf("\nEnter the mail addrress");
gets(p->mail);
p->id=p->no+1;
p->name1 = police_name(p->id);
}
void display(struct police po)
{
printf("\nNumber of a person: %d",po.no);
printf("\nName of person: %s",po.name);
printf("\nName of the area: %s",po.area);
printf("\nName of the type: %s",po.type);
printf("\nPhone number of the person: %s",po.phone);
printf("\nAge of the person: %s",po.age);
printf("\nGender of the person: %s",po.sex);
printf("\nDescription of the complaint: %s",po.des);
printf("\nMail address of the person: %s",po.mail);
printf("\nPolice details : %c",po.name1);
}
void write_police()
{
struct police data;
file=fopen("police.dat","ab");
printf("\n\nPlease enter the details of complaintee\n");
input(&data);
fwrite(&data,sizeof(data),1,file);
fclose(file);
printf("\nComplaintee Record Has Been Created ");
}
void display_all()
{
struct police data;
printf("\n\nDISPLAY ALL RECORD!!!\n");
file=fopen("police.dat","rb");
while((fread(&data,sizeof(data),1,file))>0)
{
display(data);
printf("\n================\n");
}fclose(file);
}
void display_sp()
{
struct police data;
char type1[50];
printf("\nEnter the type u wanna search\n");
scanf("%s",&type1);
int flag=0;
file=fopen("police.dat","rb");
while((fread(&data,sizeof(data),1,file))>0)
{
if(strcmp(data.type,type1)==0)
{
display(data);
printf("\n================\n");
flag=1;
}
}
fclose(file);
if(flag==0)
printf("\nRecord not exist");
}
void display_sn(int n)
{
struct police data;
int flag=0;
file=fopen("police.dat","rb");
while((fread(&data,sizeof(data),1,file))>0)
{
if(data.no==n)
{
display(data);
flag=1;
}
}
fclose(file);
if(flag==0)
printf("\nRecord not exist");
}
void modify_police()
{
struct police data;
int num,found=0;
printf("\nTo modify ");
printf("Enter the number of student: ");
scanf("%d",&num);
file=fopen("police.dat","rb+");
while((fread(&data,sizeof(data),1,file))>0 && found==0)
{
if(data.no==num)
{
display(data);
printf("\nPlease enter the new details of person\n");
input(&data);
fseek(file, -(long)sizeof(data),1);
fwrite(&data,sizeof(data),1,file);
printf("\n Record Updated");
found=1;
}
}
fclose(file);
if(found==0)
printf("\n Record Not Found");
}
void delete_police()
{
int num;
struct police data;
FILE *file2;
printf("\n\nDelete Record");
printf("\nPlease enter the number you want to delete: ");
scanf("%d",&num);
file=fopen("police.dat","rb");
file2=fopen("temp.dat","wb");
rewind(file);
while((fread(&data,sizeof(data),1,file))>0)
{
if(data.no!=num)
{
fwrite(&data,sizeof(data),1,file2);
}
}
fclose(file2);
fclose(file);
remove("police.dat");
rename("temp.dat","police.dat");
printf("\nRecord deleted.");
}
void entry_menu()
{
int choice;
printf("\n\nEntry menu");
printf("\n1.Create Person Record");
printf("\n2.Display all persons records");
printf("\n3.Search person record by type of complaint");
printf("\n4.Search person record by id/number given");
printf("\n5.Modify person record");
printf("\n6.Delete person record");
printf("\n7.Back to main menu");
printf("\nEnter your choice(1-7)");
scanf("%d",&choice);
switch(choice)
{
case 1:
write_police();
break;
case 2:{
display_all();
}
break;
case 3:
display_sp();
break;
case 4:
{
int num;
printf("\n\nPlease enter the number: ");
scanf("%d",&num);
display_sn(num);
}
break;
case 5:
modify_police();
break;
case 6:
delete_police();
break;
case 7:
break;
default:
printf("\a");
entry_menu();
}
}
