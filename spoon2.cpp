
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstring>
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>
#include <iomanip>
 
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
 
#include <bitset>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
 
using namespace std;
 
#define null 0
#define MOD 1000000007
 
#define s(a)        scanf("%d",&a)
#define sc(a)       scanf("%c",&a)
#define sl(a)       scanf("%lld",&a)
#define sf(a)       scanf("%f",&a)
#define sd(a)       scanf("%lf",&a)
#define ss(a)       scanf("%s",a)
 
#define p(a)        printf("%d",a)
#define pc(a)       printf("%c",a)
#define pl(a)       printf("%lld",a)
#define pd(a)       printf("%lf",a)
#define ps(a)       printf("%s",a)
 
#define nl        printf("\n");
#define sp        printf(" ");
#define mx	100000
 
typedef long long ll;
 
ll arr[]={1ll,0ll,2ll,3ll,6ll,10ll,20ll,35ll,70ll,126ll,252ll,462ll,924ll,1716ll,3432ll,6435ll,12870ll,24310ll,48620ll,92378ll,184756ll,352716ll,705432ll,1352078ll,2704156ll,5200300ll,10400600ll,20058300ll,40116600ll,77558760ll,155117520ll,300540195ll,601080390ll,1166803110ll,2333606220ll,4537567650ll,9075135300ll,17672631900ll,35345263800ll,68923264410ll,137846528820ll,269128937220ll,538257874440ll,1052049481860ll,2104098963720ll,4116715363800ll,8233430727600ll,16123801841550ll,32247603683100ll,63205303218876ll,126410606437752ll,247959266474052ll,495918532948104ll,973469712824056ll,1946939425648112ll,3824345300380220ll,7648690600760440ll,15033633249770520ll,30067266499541040ll,59132290782430712ll,118264581564861424ll,232714176627630544ll,465428353255261088ll,916312070471295267ll,1832624140942590534ll,3609714217008132870ll,7219428434016265740ll};
 
int main()
{
	int t;
	s(t);
	while (t--) {
		ll num;
		sl(num);
		int i;
		for (i=2; arr[i]<num; i++);
		p(i);
		nl;
	}
	return 0;
} 

