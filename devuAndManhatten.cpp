#include "bits/stdc++.h"
#define blank putc_unlocked('\n',stdout)
#define mod 1000000007
using namespace std;

char ch,temp[1<<10];
int getInt()
{
        ch=getc_unlocked(stdin);
        while(ch<'-')
        {
               ch=getc_unlocked(stdin);
        }

        int sign=1,num=0;

        if(ch=='-')
        {
               sign=-1;
               ch=getc_unlocked(stdin);

        }
        while(isdigit(ch))
        {
                num=num*10+ch-'0';
                ch=getc_unlocked(stdin);
        }
    return sign*num;
}

void printn(int n) 
{
	char *ptr=temp+30;
	*ptr--='\0';
	int flag=1;
	if(n)
	{
		if(n<0) n*=-1,flag=-1;
			
		while(n>0)
		{
			*ptr--=(n%10) +'0';
			n/=10;
		}
		if(flag==-1) *ptr--='-';
		
	}
	else {*ptr='0';putc_unlocked('0',stdout);return;}
	ptr++;
	while(*ptr!='\0')
	{
		putc_unlocked(*ptr++,stdout);
	}
}
int N,Q;
int points[100001][2];
int main()
{
    N=getInt();
    int i,j,index,r1,r2;
    char ch2;
    for(i=0;i<N;i++)
    {
        points[i][0]=getInt();
        points[i][1]=getInt();
    }
    Q=getInt();
    for(i=0;i<Q;i++)
    {
        scanf("%c",&ch2);
        if(ch2=='U')
        {
            index=getInt();
            r1=getInt();
            r2=getInt();
        }
        else
        {
            r1=getInt();
            r2=getInt();
        }
    }
}
