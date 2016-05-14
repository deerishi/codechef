#include "bits/stdc++.h"
#define blank putc_unlocked('\n',stdout)
#define mod 1000000007

using namespace std;
char ch,temp[1<<10];


typedef long long int ll;

struct Node
{
    int dp1,dp2;
};
typedef struct Node node;
int N;
int triangularBoard[505][505];
ll dp1[505][505],dp2[505][505],dp3[505][505],dp4[505][505];
int maxVal;

void PrintArray(ll dp[505][505])
{
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
ll PoNoDiagonal()
{
    dp1[1][1]=triangularBoard[1][1];
    int i,j,cutOffRow;
    (N%2==0)?(cutOffRow=N/2+1):(cutOffRow=(N+1)/2);
    for(i=2;i<cutOffRow;i++)
    {
        for(j=1;i<=i;j++)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal< dp1[i-1][j+1])
            {
                maxVal=dp1[i-1][j+1];
            }       
            if(j-1 >=i-1 and maxVal<dp1[i-1][j-1])
            {
                maxVal=dp1[i-1][j-1];
            }
            if(j<=i-1 and  maxVal<dp1[i-1][j])
            {
                maxVal=dp1[i-1][j];
            }
            dp1[i][j]=triangularBoard[i][j]+maxVal;
        }
    }
    
    for(i=cutOffRow;i<=N;i++)
    {
        for(j=1;j<=N-i;j++)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal< dp1[i-1][j+1])
            {
                maxVal=dp1[i-1][j+1];
            }       
            if(j-1 >=1 and maxVal<dp1[i-1][j-1])
            {
                maxVal=dp1[i-1][j-1];
            }
            if(j<=i-1 and maxVal<dp1[i-1][j])
            {
                maxVal=dp1[i-1][j];
            }
            dp1[i][j]=triangularBoard[i][j]+maxVal;
        }
    }
    return dp1[N-1][1];
}

ll MantisDiagonal()
{
    dp2[N][N]=triangularBoard[N][N];
    int i,j,k,cutOffCol;
    (N%2==0)?(cutOffCol=N/2):(cutOffCol=(N+1)/2);
    
    for(j=N-1;j>cutOffCol;j--)
    {
        for(i=N;i>=j;i--)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal<dp2[i-1][j+1])
            {
                maxVal=dp2[i-1][j+1];
            }
            
            if(i+1<=N and maxVal<dp2[i+1][j+1])
            {
                maxVal=dp2[i+1][j+1];
            }
            
            if(j+1<=i and maxVal<dp2[i][j+1])
            {
                maxVal=dp2[i][j+1];
            }
            dp2[i][j]=triangularBoard[i][j]+maxVal;
        }
        
    }
    
    for(j=cutOffCol;j>=1;j--)
    {
        for(i=N;i>N-j;i--)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal<dp2[i-1][j+1])
            {
                maxVal=dp2[i-1][j+1];
            }
            
            if(i+1<=N and maxVal<dp2[i+1][j+1])
            {
                maxVal=dp2[i+1][j+1];
            }
            
            if(j+1<=i and maxVal<dp2[i][j+1])
            {
                maxVal=dp2[i][j+1];
            }
            dp2[i][j]=triangularBoard[i][j]+maxVal;
             //coutCollect the Chocolate Chips <<"MantisDiagonal dp2["<<i<<"]["<<j<<"]"<<" is "<<dp2[i][j]<<"\n";
        }
        
       
    }

    return dp2[N][1];
}

ll PoDiagonal()
{

    dp3[1][1]=triangularBoard[1][1];
    int i,j,cutOffRow;
    (N%2==0)?(cutOffRow=N/2+1):(cutOffRow=(N+1)/2);
    for(i=2;i<cutOffRow;i++)
    {
        for(j=1;i<=i;j++)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal< dp3[i-1][j+1])
            {
                maxVal=dp3[i-1][j+1];
            }       
            if(j-1 >=i-1 and maxVal<dp3[i-1][j-1])
            {
                maxVal=dp3[i-1][j-1];
            }
            if(j<=i-1 and  maxVal<dp3[i-1][j])
            {
                maxVal=dp3[i-1][j];
            }
            dp3[i][j]=triangularBoard[i][j]+maxVal;
        }
    }
    
    for(i=cutOffRow;i<=N;i++)
    {
        for(j=1;j<=N-i+1;j++)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal< dp3[i-1][j+1])
            {
                maxVal=dp3[i-1][j+1];
            }       
            if(j-1 >=1 and maxVal<dp3[i-1][j-1])
            {
                maxVal=dp3[i-1][j-1];
            }
            if(j<=i-1 and maxVal<dp3[i-1][j])
            {
                maxVal=dp3[i-1][j];
            }
            dp3[i][j]=triangularBoard[i][j]+maxVal;
        }
    }
    return dp3[N][1];
    
}

ll mantisNoDiagonal()
{
    dp4[N][N]=triangularBoard[N][N];
    int i,j,k,cutOffCol;
    (N%2==0)?(cutOffCol=N/2):(cutOffCol=(N+1)/2);
    
    for(j=N-1;j>cutOffCol;j--)
    {
        for(i=N;i>=j;i--)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal<dp4[i-1][j+1])
            {
                maxVal=dp4[i-1][j+1];
            }
            
            if(i+1<=N and maxVal<dp4[i+1][j+1])
            {
                maxVal=dp4[i+1][j+1];
            }
            
            if(j+1<=i and maxVal<dp4[i][j+1])
            {
                maxVal=dp4[i][j+1];
            }
            dp4[i][j]=triangularBoard[i][j]+maxVal;
        }
        
    }
    
    for(j=cutOffCol;j>=1;j--)
    {
        for(i=N;i>N-j+1;i--)
        {
            maxVal=INT_MIN;
            if(j+1<=i-1 and maxVal<dp4[i-1][j+1])
            {
                maxVal=dp4[i-1][j+1];
            }
            
            if(i+1<=N and maxVal<dp4[i+1][j+1])
            {
                maxVal=dp4[i+1][j+1];
            }
        
            if(j+1<=i and maxVal<dp4[i][j+1])
            {
                maxVal=dp4[i][j+1];
            }
            dp4[i][j]=triangularBoard[i][j]+maxVal;
        }
        
    }
    
    return dp4[N][2];
}
int main()
{
    int t,i,j;
    ll res1,res2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=i;j++)
            {
                scanf("%d",&triangularBoard[i][j]);
            }
        }
        res1=PoDiagonal()+mantisNoDiagonal();
        res2=MantisDiagonal()+PoNoDiagonal();
        //cout<<"PoNoDiagnal is \n";PrintArray(dp1);cout<<"\n";
        //cout<<"MantisDiagonal is \n";PrintArray(dp2);cout<<"\n";
        //cout<<"PoDiagonal is \n";PrintArray(dp3);cout<<"\n";
        //cout<<"MantisNoDiagonal is \n";PrintArray(dp4);cout<<"\n";
        printf("%lld\n",max(res1,res2));
    }
}

