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
stack<pair<int,int> >chefs;
int main()
{
    int N=getInt(),K=getInt(),i,j,c;
    long long int prod=1;
    for(i=1;i<=N;i++)
    {
        c=getInt();
        if(chefs.empty())
        {
            chefs.push(make_pair(c,i));
        }
        else
        {
            while(!chefs.empty() and c< chefs.top().first)
            {
                prod=(prod*(i-chefs.top().second+1))%mod;
                chefs.pop();
            }
            chefs.push(make_pair(c,i));
        }
    }
    //cout<<"prod is "<<prod<<"\n";
    printf("%lld\n",prod);
    //blank;
    return 0;
}
