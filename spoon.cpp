#include "bits/stdc++.h"
#define blank putc_unlocked('\n',stdout)
using namespace std;
typedef long long int ll;
typedef long  double ll2;

char ch,temp[1<<10];
ll getInt()
{
        ch=getc_unlocked(stdin);
        while(ch<'-')
        {
               ch=getc_unlocked(stdin);
        }

        ll sign=1,num=0;

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
ll2 combinotorics[65];

ll2 find_nCn_2(ll n)
{
    ll2 r=(n%2==0)?(n/2):((n+1)/2);
    ll i;
    ll2 res=1;
    for(i=1;i<=r;i++)
    {
        res*=n;
        res/=i;
        n--;
        //cout<<"Res is "<<res<<"\n";
    }
    return res;
}
void maxCityCapacity()
{
    combinotorics[0]=0;
    combinotorics[1]=0;
    combinotorics[2]=2;
    int i;
    for(i=3;i<65;i++)
    {
        combinotorics[i]=find_nCn_2(i);
    }
    
}

void printn(ll n) 
{
	char *ptr=temp+30;
	*ptr--='\0';
	ll flag=1;
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



int main()
{
    ll T,N;
    int i;
    
    T=getInt();
    maxCityCapacity();
    /*for(i=2;i<=65;i++)
    {
        cout<<"i= "<<i<<" "<<combinotorics[i]<<"\n";
    }*/
    while(T--)
    {
        N=getInt();
        //cout<<"N is "<<N<<"\n";
        for(i=2;combinotorics[i]<N;i++)
        {
           // cout<<"i is "<<i<<"\n";
        }
        printn(i);
        blank;
    }
}
