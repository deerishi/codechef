#include "bits/stdc++.h"
#define Mod 1000000007
#define blank putc_unlocked('\n',stdout)
using namespace std;
//typedef long long int int;
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
void printDP(int dp[2][32],int m)
{
    int i,j;
    for(i=0;i<=1;i++)
    {
        for(j=1;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int findSol(int N,int m)
{
    int i,j,k;
    int dp[2][32];
    int M=(m%2==0)?(m/2):((m+1)/2);
    for(i=1;i<=M;i++)
    {
        dp[0][i]=1;
        dp[0][m-i+1]=1;
    }
    int count=0;
    
    for(i=2;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            if(i%2==0)
            {
                 dp[1][j]=0;
                for(k=j-1;k<=j+1;k+=2)
                {
                   
                    if(k>=1 and k<=m)
                    {
                        dp[1][j]+=(dp[0][k]%Mod);
                        dp[1][j]=dp[1][j]%Mod;
                    }
                    
                }
                dp[1][m-j+1]=dp[1][j];
            }
            else
            {
                dp[0][j]=0;
                for(k=j-1;k<=j+1;k++)
                {
                    if(k>=1 and k<=m)
                    {
                        dp[0][j]+=(dp[1][k]%Mod);
                        dp[0][j]=dp[0][j]%Mod;
                    }
                }
                dp[0][m-j+1]=dp[0][j];
            }   
        }
       //cout<<"DP is \n";
        //printDP(dp,m);
    }
    int sum=0;
    int m2=(M%2==0)?(M):M-1;
    if(N%2==0)
    {
        
        for(i=1;i<=m2;i++)
        {
            sum=(sum+dp[1][i])%Mod;
        }
        sum=(sum%Mod+sum%Mod)%Mod;
        if(M%2==1)
        {
            sum=(sum+dp[1][M])%Mod;
        }
        
        
    }
    else
    {
        for(i=1;i<=m2;i++)
        {
            sum=(sum+dp[0][i])%Mod;
        }
        sum=(sum%Mod+sum%Mod)%Mod;
        if(M%2==1)
        {
            sum=(sum%Mod+dp[0][M]%Mod)%Mod;
        }
        
    }
    return sum;
}
int main()
{
    int t=getInt();
    int N,M;
    int i,j;
    int res;
    while(t--)
    {
        N=getInt();
        M=getInt();
        res=findSol(N,M);
        //cout<<"\n the solution is \n";
        printn(res);
        blank;
        
        
    }
}
