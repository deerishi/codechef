#include "bits/stdc++.h"

using namespace std;
char ch,temp[1<<10];


int main()
{

   
    char str[100005];
    scanf("%s",str);
    int len=strlen(str);
    int i=0,numDs=0;
    int arr[100005];
    vector<int> list;
    //cout<<"len is "<<len<<"\n";
    for(i=1;i<=len+1;i++)
    {
        list.push_back(i); //added all the numbers to the list
    }
    int flag=0;
    for(i=len-1;i>=0;i--)
    {
        if(str[i]=='D')
        {
            flag=1;
            arr[i]=0;
            numDs++;
        }
        else if(str[i]=='I' and flag==1)
        {
            flag=0;
            arr[i]=1;
        }
        else if(str[i]=='I' and i!=(len-1) and arr[i+1]>0)
        {
            arr[i]=arr[i+1]+1;
        }
        else
        {
            arr[i]=0;
        }
    }
    /*cout<<"the preprocesses aray is  \n";
    for(i=0;i<len;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"numDs is "<<numDs<<"\n";*/
    vector<int>::iterator it=list.begin();
    vector<int> output;
    for(i=0;i<len;i++)
    {
        
        if(str[i]=='D')
        {
            output.push_back(list.back());
            list.pop_back();
        }
        else if(str[i]=='I' and arr[i]>0)
        {
            it=list.begin()+(list.size()-arr[i]-1);
            output.push_back(*it);
            list.erase(it);
        }
        else
        {
            it=list.begin();
            output.push_back(*it);
            list.erase(it);
            
        }
    }
    it=list.begin();
    output.push_back(*it);
    //cout<<"\n the lexographically longest string is \n";
    for(it=output.begin();it!=output.end();it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}
