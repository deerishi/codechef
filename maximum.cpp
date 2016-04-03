#include "bits/stdc++.h"

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
int m;
int maximum(int n)
{
    
}
int main()
{
    int t,n,res;
    t=getInt();
    m=getInt();
    while(t--)
    {
        n=getInt();
            
    }
    cout<<"t= "<<t<<"\n";
    return 0;
}
