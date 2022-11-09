/* Roll no. : 19bcs150
 * Name     : J.Jetson Cyrus
 * Date     : 30/10/2019
 * ex name  : employee payroll processing system
 * ex no.   : ex8 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct emp
{
char name[20];
int empId;
char design[20];
char branch[20];
int baspay;
float netsal;
}em;
void high_sal(em emp[10],int);
void sal_range(em emp[10],int);
void designation(em emp[10],int);
void branch(em emp[10],int,char[]);
void display(em emp);  
