#include "bits/stdc++.h"
#define blank putc_unlocked('\n',stdout)
#define mod 1000000007
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

void printn(long long int n) 
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
unordered_map<int,unordered_set<int> > peers,edges; //Peers store the node numbers of the peers and the edge numbers 
unordered_map<int,int> edgesAndTheirNodes1,edgesAndTheirNodes2;
struct Tree
{
    int u,v,cost;
};
typedef struct Tree node;
node tree[100001]; 
int getWeight(int u,int v)
{
    unordered_set<int>::iterator it;
    for(it=edges[u].begin();it!=edges[u].end();it++)
    {
        if((edgesAndTheirNodes1[*it]==u and edgesAndTheirNodes2[*it]==v) or (edgesAndTheirNodes1[*it]==v and edgesAndTheirNodes2[*it]==u))
        {
            return tree[*it].cost;
        }
    }
}
bool found=false;
long long int findPathLength(int u,int v,unordered_set<int> visitedNodes)
{
    unordered_set<int>::iterator it;
    long long int path=0,p2;
    //cout<<"in findPathLength with u="<<u<<" and v="<<v<<" and peer size is "<<peers[u].size()<<"\n";
    for(it=peers[u].begin();it!=peers[u].end() and found==false;it++)
    {
        //cout<<"next node is "<<(*it)<<"\n";
        if(visitedNodes.find((*it))==visitedNodes.end())//mean the next node has not yet been visited
        {
            visitedNodes.insert(u);
            if(*it==v)
            {
                path=getWeight(u,*it);
                found=true;
                //cout<<"path found returning "<<path<<"\n";
                return path;
            }
            else
            {
                //cout<<"now going from "<<(*it)<<" to "<<v<<"\n";
                p2=getWeight(u,*it);
                //cout<<"getWeight("<<u<<","<<*it<<") returned "<<p2<<"\n";
                path=findPathLength(*it,v,visitedNodes)+getWeight(u,*it);
                //cout<<"in fnc path is "<<path<<"\n";
                visitedNodes.erase(*it);
            }
        }
        //cout<<"found is "<<found<<"\n";
    }
    return path;
}

int main()
{
    int N=getInt(),i,j,u,v, cost,Q,x,y,z;
    unordered_set<int> visitedNodes;
    long long int pathLength;
    for(i=0;i<N-1;i++)
    {
        //cout<<"enter i="<<i<<"\n";
        tree[i].u=getInt();
        tree[i].v=getInt();
        tree[i].cost=getInt();
        peers[tree[i].u].insert(tree[i].v);
        peers[tree[i].v].insert(tree[i].u);
        edges[tree[i].u].insert(i);
        edges[tree[i].v].insert(i);
        edgesAndTheirNodes1[i]=tree[i].u;
        edgesAndTheirNodes2[i]=tree[i].v;
       // cout<<"peers["<<tree[i].u<<"] is "<<peers[tree[i].u].size()<<"\n";
    }
    //now input the queries
    
    Q=getInt();
    //cout<<"Q is "<<Q<<"\n";
    for(i=0;i<Q;i++)
    {
        x=getInt();
        y=getInt();
        z=getInt();
        //cout<<"x is "<<x<<"\n";
        if(x==1)
        {
            //cout<<"changing pathLength \n";
            tree[y-1].cost=z;
        }
        else
        {
            pathLength=findPathLength(y,z,visitedNodes);
            //visitedNodes.clear();
            found=false;
            printn(pathLength);
            blank;
        }
    }   
}
