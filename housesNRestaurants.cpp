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
class hnR
{
    public:
    int x1,y1,cost;
    
    hnR(int x1,int y1,int cost): x1(x1),y1(y1),cost(cost){} 
    bool operator<(hnR other)
    {
        return this->cost < other.cost;
    }
};
hnR createNode(int x1,int y1,int cost)
{
    hnR temp(x1,y1,cost);
    return temp;
}
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=a;
}
string currentString;
int main()
{
    std::ios_base::sync_with_stdio(false);
    ll T=getInt();
    ll N,M;
    int i,j,k,x1,y1,cost;
    vector<hnR> edges;
    char ch;
    while(T--)
    {
        N=getInt();
        M=getInt();
        edges.clear();
        cout<<"enter string\n";
        
        cin.getline(currentString);
        //scanf("%s",str); 
        cout<<"the string is "<<currentString<<"\n";
        for(i=0;i<M;i++)
        {
            x1=getInt();
            y1=getInt();
            cost=getInt();
            edges.push_back(createNode(x1,y1,cost));
        }
        
    }
    
}
