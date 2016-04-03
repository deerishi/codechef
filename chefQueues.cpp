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
vector<int> chefs2;
int main()
{
    int N=getInt(),K=getInt(),j;
    for(j=0;j<N;j++)
    {
        chefs2.push_back(getInt());
    }
    vector<int>::iterator it=chefs2.begin();
    chefs.push(make_pair(*it,N));
    int prod=1;
    int i=N-1;
    for(it=chefs2.begin()+1;it!=chefs2.end();it++)
    {
        cout<<"*it is "<<*it<<"\n";
        while(!chefs.empty() and *it < chefs.top().first)
        {
            cout<<"multiplying "<<chefs.top().second - i + 1<<"\n";
            prod=((prod)*(chefs.top().second - i + 1))%mod;
            chefs.pop();
        }
        chefs.push(make_pair(*it,i));
        i--;
    }
    cout<<"the prod is \n";
    printn(prod);
    blank;  
    
    
    
}
