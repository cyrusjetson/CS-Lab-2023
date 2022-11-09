#include<stdio.h>
#include<string.h>
typedef struct book
{
char name[20];
int ser;
char usage[20];
}b;
void display(b p);
void show(FILE *fp,int ,b p[20]);
