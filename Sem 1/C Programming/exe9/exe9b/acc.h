/* Roll no. : 19bcs167
 *  * Name     : B.Saravanan
 *   * Date     : 06/11/2019
 *    * ex name  : getting bank customer details
 *     * ex no.   : ex9b */
#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct customer
{
char cname[25];
long accno;
long balance;
char add[30];
}cust;
cust* searchAcno(cust[],int,int);
void searchname(cust[],int,char[]);
void display(cust*);
