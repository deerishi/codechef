#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = (LL)1e19;
const int MOD = (int)1e9+7;
 
void multiply(vector < vector < int > > &A , vector < vector < int > > &B, int N)
{
	int i , j  , k ;	
	int C[N+1][N+1];
	memset(C,0,sizeof(C));
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			for(k=0;k<N;++k)
				C[i][j] = (C[i][j] + A[i][k] * 1LL * B[k][j])%MOD;
	
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			A[i][j] = C[i][j];
 
}
 
void display(vector < vector < int > > R , int N)
{
    
    int i,j;
	for(i=0;i<N;i++)
	{
	    for(j=0;j<N;j++)
	    {
	        cout<<R[i][j]<<" ";
	    }
	    cout<<"\n";
	}
}
void power(vector < vector < int > > A , int N, vector < vector < int > > &R , int expo)
{
	int i , j;
 
	for(i=0;i<N;++i)
		for(j=0;j<N;++j)
			if(i-j)
				R[i][j] = 0;
			else
				R[i][j] = 1;
    cout<<"R is \n";
	display(R,N);
	while(expo)
	{
		if(expo&1)
			multiply(R,A,N);
        cout<<"in expo\n";
		multiply(A,A,N);
		expo/=2;
	}
	
}
 
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(;T;--T)
	{
		int N , M , i , j   , k;
		cin>>N>>M;
		--N;
		vector < vector < int > > Odd(M,vector < int >(M,0) );
		vector < vector < int > > Even(M,vector < int >(M,0) );
		vector < vector < int > > R(M,vector < int >(M,0) );
		if(M!=1)
			Odd[0][1]     = 1;
		if(M>=2)
			Odd[M-1][M-2] = 1;
		
		for(i=1;i<M-1;++i)
			Odd[i][i-1] = Odd[i][i+1] = 1;
		
		if(M!=1)
			Even[0][1] = Even[0][0]  = 1;
		
		if(M>=2)
			Even[M-1][M-1] = Even[M-1][M-2] = 1;
		
		for(i=1;i<M-1;++i)
			Even[i][i] = Even[i][i-1] = Even[i][i+1]= 1;
		
		cout<<"even  is \n";
	    display(Even,M);
	    cout<<"odd  is \n";
	    display(Odd,M);
		multiply(Even,Odd,M);
		cout<<"after multiplying even is \n";
		display(Even,M);
		power(Even,M,R,N/2);
		if(N&1)
			multiply(R,Odd,M);
		int ans = 0;
 
		for(i=0;i<M;++i)
			for(j=0;j<M;++j)
				ans=(ans+R[i][j])%MOD;
		cout<<ans<<endl;
	}
    return 0;
}
