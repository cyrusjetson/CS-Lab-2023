#include<stdio.h>
#include<string.h>


char exor(char a,char b)
{
        if(a == b)
                return '0';
        else
                return '1';
}

int crc(char data[],char div[])
{
        int datalen = strlen(data);
        int divlen = strlen(div);
        int i,j;


        for(i = 0;i < divlen-1;i++)
        data[datalen+i] = '0';
        data[datalen+divlen-1] = '\0';

        int codelen = datalen+divlen-1;
        char temp[20],rem[20],rem1[20];

        for(i=0;i<divlen;i++)
        rem[i] = data[i];

        for(j=divlen;j<=codelen;j++)
        {
                for(i=0;i<divlen;i++)
                temp[i] = rem[i];

                if(rem[0] == '0')
                {
                        for(i=0;i<divlen-1;i++)
                                rem[i] = temp[i+1];
                }
                else
                {
                        for(i=0;i<divlen-1;i++)
                                rem[i] = exor(temp[i+1],div[i+1]);
                }

                if(j!=codelen)
                        rem[divlen-1] = data[j];
                else
                        rem[divlen-1] = '\0';
        }

        for(i=0;i<divlen-1;i++)
        data[datalen+i] = rem[i];

        data[codelen] = '\0';


        printf("\nCRC=%s",rem);

        strcpy(rem1,rem);
        for(i=0;i<strlen(rem1);i++)
                if(rem1[i]=='1')
                        return 0;
                return 1;
}


void main()
{

        char data[20],div[20],data1[20];
        char rem[20];

        printf("\nEnter dataword:");
        scanf("%s",data);
        printf("\nEnter divisor:");
        scanf("%s",div);

        int m = crc(data,div);

        printf("\nDataword:%s",data);

        printf("\n-------------Receiver-------------");
        printf("\nEnter received data word:");
        scanf("%s",data1);

        int remainder = crc(data1,div);
        if(remainder==1)
                printf("\nDataword contains no error as CRC has all 0's\n");
        else if (remainder==0)
                printf("\nDataword contains error as CRC has 1's\n");

}
