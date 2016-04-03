#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
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

vector<ll> A;
bool compare(ll a,ll b)
{
    return a<b;
}

int main()
{
    ll N,X;
    N=getInt();
    X=getInt();
    ll i,j;
    for(i=0;i<N;i++)
    {
        A.push_back(getInt());
    }
    sort(A.begin(),A.end(),compare);
    //cout<<"after sorting we have \n";
    vector<ll>::iterator it=A.begin();
    //cout<<"hi\n";
    /*for(;it!=A.end();it++)
    {
        //cout<<"hj";
        cout<<(*it)<<" ";
    }
    cout<<"\n";*/
    ll sum=0,success=0,halfSum=0,numFailed=0;
    it=A.begin();
    ll num;
    ll count=0;
   while(it!=A.end())
    {
        num=(*it);
        if(sum<X)
        {
            sum+=*it;
            success++;
            if(sum>X and (sum-X)<(sum/2))
            {
                success--;
                numFailed=-1;
            }
         }
         if(halfSum<X)
            halfSum+=((num%2==0)?(num/2):(num/2+1));
         if(halfSum>=X and N-count>0) //i.e there are more than one ways to minimize the number of failures
         {
            break;  
         }   
         count++;  
         it++;
    }
    printn(N-success+numFailed)     ;
    putchar(' ');
    printn(success);
    putchar('\n');
    
    return 0;
   
}
