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

bool compare(pair<int,int> a,pair<int,int> b)
{
    return a.second < b.second ;
}
int main()
{
    vector<pair<int,int> > v1;
    int t=getInt(),n,i,x,y;
    int bombCount;
    while(t--)
    {
        n=getInt();
        bombCount=1;
        for(i=0;i<n;i++)
        {
            x=getInt();y=getInt();
            v1.push_back(make_pair(x,y));
        }
        sort(v1.begin(),v1.end(),compare);
        //cout<<" after sorting the data is\n";
         vector<pair<int,int> >:: iterator it;
        /* for(it=v1.begin();it!=v1.end();it++)
         {
            cout<<it->first<<"  "<<it->second<<"\n";
         }*/
         
         it=v1.begin();
          x=it->first;
            y=it->second;
        for(it=v1.begin()+1;it!=v1.end();it++)
        {   
            //cout<<"x is "<<x<<" y is "<<y<<"\n";
           if(it->first >y) //i.e the intervals are overlapping 
           {
                bombCount++;
               
                   
                y=it->second;
               
           }
           
            
        }
        printf("%d\n",bombCount);
        v1.clear();
    }
    return 0;
}
