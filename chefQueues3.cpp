#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cmath>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <bitset>
#include <stdlib.h>
 
using namespace std;
 
#define FOR(i,a,b) for (int i = int(a); i <= b; i++)
#define INF 1000000000
#define mod 1000000007
#define ll long long int
// #define inp(x) scanf("%d",&x)
#define inchar getchar_unlocked
#define mx 1000010
 
inline void inp( int &n )
{
n=0;
int ch=inchar();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=inchar();}
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=inchar();
n=n*sign;
}
 
typedef pair<int,int> ii;
stack<ii> s;
 
int a;
 
 
int main() {
 
    int n,k;
    inp(n);inp(k);
    
    ll ans = 1;
    FOR(i,1,n)
     {
         inp(a);
        if(s.empty() || a >= s.top().first ) s.push(ii(a,i));
        else
         {
           while(!s.empty() && a < s.top().first)
            {
              ii x = s.top();
              s.pop();
              ans = (ans*((ll)(i-x.second+1)))%mod;
            }            
           s.push(ii(a,i));          
         }    
     }
    printf("%lld\n",ans);
    
    
    //getchar();
    //getchar();
	return 0;
} 
