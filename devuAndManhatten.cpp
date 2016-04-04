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
int N,Q;
int segmentTreeSumMax[400004],segmentTreeSumMin[400004],segmentTreeSubMax[400004],segmentTreeSubMin[400004];
int sum[100001],sub[100001];

void buildSegmentTree(int i, int j ,int node, int *segArr,int *arr,bool max)
{
    //Here segArr is the segment tree array and arr is the array we would compare to
    //Segment tree takes O(n) to build
    //Note Segment tree stores the indexes not the value
    if(i==j)
    {
        segArr[node]=i;
        return;
    }    
    
    int mid=(i+j)/2;
    buildSegmentTree(i,mid,2*node,segArr,arr,max);
    buildSegmentTree(mid+1,j,2*node+1,segArr,arr,max);
    
    if(max)
    {
        // That is we want to store the maximum value sin the intervals
        //Each node in the segment tree stores the maximum value in the intervals
        //cout<<"checking max arr[segArr[2*node]]>arr[segArr[2*node+1]] "<<arr[segArr[2*node]]<<" and "<<arr[segArr[2*node+1]]<<"\n";
        if(arr[segArr[2*node]]>arr[segArr[2*node+1]])
        {
            segArr[node]=segArr[2*node];   
        }
        else
        {
            segArr[node]=segArr[2*node+1];
        }
    }
    else
    {
        if(arr[segArr[2*node]]<=arr[segArr[2*node+1]])
        {
            segArr[node]=segArr[2*node];   
        }
        else
        {
            segArr[node]=segArr[2*node+1];
        }
        
    }
    
}
void updateSegmentTree(int i,int j,int node,int indexToBeUpdated,int value,int *segArr,int *arr,bool max)
{
    //cout<<"\nin update\n";
    if(i==j and i==indexToBeUpdated)
    {
        arr[i]=value;
        return;
    }
    //Now we need to check if the segment tree has changed or not
    int mid=(i+j)/2;
    if(indexToBeUpdated >mid)
    {
        updateSegmentTree(mid+1,j,2*node+1,indexToBeUpdated,value,segArr,arr,max);
    }
    else
    {
        updateSegmentTree(i,mid,2*node,indexToBeUpdated,value,segArr,arr,max);
    }
    if(max)
    {
        if(arr[segArr[2*node]]>arr[segArr[2*node+1]])
        {
            segArr[node]=segArr[2*node];   
        }
        else
        {
            segArr[node]=segArr[2*node+1];
        }
    }
    else
    {
        if(arr[segArr[2*node]]<=arr[segArr[2*node+1]])
        {
            segArr[node]=segArr[2*node];   
        }
        else
        {
            segArr[node]=segArr[2*node+1];
        }
        
    }
}
void printSegmentTrees()
{
    int i,j;
    cout<<"segmentTreeSumMax\n";
    for(i=1;i<20;i++)
    {
        cout<<segmentTreeSumMax[i]<<" ";
    }
    cout<<"\n";
    cout<<"segmentTreeSubMax\n";
    for(i=1;i<20;i++)
    {
        cout<<segmentTreeSubMax[i]<<" ";
    }
    cout<<"\n";
    cout<<"segmentTreeSumMin\n";
    for(i=1;i<20;i++)
    {
        cout<<segmentTreeSumMin[i]<<" ";
    }
    cout<<"\n";
    cout<<"segmentTreeSubMin\n";
    for(i=1;i<20;i++)
    {
        cout<<segmentTreeSubMin[i]<<" ";
    }
    cout<<"\n";
}
void printManArrays()
{
    int i,j;
    cout<<"sum\n";
    for(i=1;i<20;i++)
    {
        cout<<sum[i]<<" ";
    }
    cout<<"\n";
    cout<<"sub is\n";
    for(i=1;i<20;i++)
    {
        cout<<sub[i]<<" ";
    }
    cout<<"\n";
   
}
int query(int i,int j,int begin,int end,int node,int *segArr,int *arr,bool max)
{
    if(i>=begin and j<=end)
    {
        return segArr[node];
    }
    if(j<begin or i>end)
    {
        return -1;
    }
    int mid=(i+j)/2;
    int left=query(i,mid,begin,end,2*node,segArr,arr,max);
    int right=query(mid+1,j,begin,end,2*node+1,segArr,arr,max);
    
    if(left==-1)
        return right;
    
    else if(right==-1)
        return left;
    
    if(max)
    {
        if(arr[left]>arr[right])
            return left;
        else
            return right;
    }
    else
    {
        if(arr[left]>arr[right])
            return right;
        else
            return left;
    }
}
int points[100001][2];
int main()
{
    N=getInt();
    int i,j,index,r1,r2;
    char ch2;
    for(i=1;i<=N;i++)
    {
        points[i][0]=getInt();
        points[i][1]=getInt();
        sum[i]=points[i][0]+points[i][1];
        sub[i]=points[i][0]-points[i][1];
        
    }
    //Now we have stired the arrays subtract(x-y) and sum(x+y)
    //Now we need to build  a segmentTree out of it
    //Build 4 segment trees 
    //1) segment tree for x+y max
    buildSegmentTree(1,N,1,segmentTreeSumMax,sum,true);
    //cout<<"after summax\n";
    //printSegmentTrees();
    //2)segmentTree for x-y max
    buildSegmentTree(1,N,1,segmentTreeSubMax,sub,true);
    //cout<<"after submax\n";
    //printSegmentTrees();
    //3)segmentTree for x+y min
    buildSegmentTree(1,N,1,segmentTreeSumMin,sum,false);
    //cout<<"after summin\n";
    //printSegmentTrees();
    //4)segmentTree for x-y min
    buildSegmentTree(1,N,1,segmentTreeSubMin,sub,false);
    //cout<<"after submin\n";
    //now we have built the segment trees
    //printManArrays();
    //printSegmentTrees();
    
    Q=getInt();
    for(i=0;i<Q;i++)
    {
        scanf("%c",&ch2);
        //cout<<"ch2 is "<<ch2<<"\n";
        if(ch2=='U')
        {
            index=getInt();
            index++;
            r1=getInt();
            r2=getInt();
            points[index][0]=r1;
            points[index][1]=r2;
            //1)update segmentTreeSumMax
            updateSegmentTree(1,N,1,index,r1+r2, segmentTreeSumMax,sum,true);
            
            //2)update segmentTreeSubMax
            updateSegmentTree(1,N,1,index,r1-r2, segmentTreeSubMax,sub,true);
            
            //3)update segmentTreeSumMin
            updateSegmentTree(1,N,1,index,r1+r2, segmentTreeSumMin,sum,false);
            
            //4)update segmentTreeSubMin
            updateSegmentTree(1,N,1,index,r1-r2, segmentTreeSubMin,sub,false);
            //int i,int j,int node,int indexToBeUpdated,int value,int *segArr,int *arr,bool max)
            //now we need to update the sum and the subtract arrays, and consequently the segment trees
            //nt i,int j,int node,int indexToBeUpdated,int value,int *segArr,int *arr,bool max)
        }
        else
        {
            r1=getInt();
            r2=getInt();
            //Now we query the node that we have to get the range between , remember to add +1 to the range values since we are using index 1 arrays
            r1++;
            r2++;
            //Now we have to get the maximum over all possible points and then check them
            //Case 1 : x+y max
            //int i,int j,int begin,int end,int node,int *segArr,int *arr,bool max)
            int sumMax=query(1,N,r1,r2,1,segmentTreeSumMax,sum,true);
            
            //Case 2: x+y min
            int sumMin=query(1,N,r1,r2,1,segmentTreeSumMin,sum,false);
            
            //case 3: x-y max
            int subMax=query(1,N,r1,r2,1,segmentTreeSubMax,sub,true);
            
            //case 4: x-y min
            int subMin=query(1,N,r1,r2,1,segmentTreeSubMin,sub,false);
            
            //Each of the above query operations take O(log(n))
            int maxManhattenDistance=INT_MIN,indexOfMax;
            
            //case 1 x1+y1 - (x2+y2) ,x1>x2,y1>y2
            int res1=sum[sumMax]-sum[sumMin];
            
            if(res1>maxManhattenDistance)
            {
                maxManhattenDistance=res1;
                indexOfMax=1;
            }
            
            //case 2 x1-y1 -(x2-y2) ,x1>x2,y2>y1
            int res2= sub[subMax]-sub[subMin];
            if(res2>maxManhattenDistance)
            {
                maxManhattenDistance=res2;
                indexOfMax=2;
            }
            
            //case 3 : x2-y2 -(x1+y1) , x2>x1,y1>y2
            int res3=sub[subMax]-sum[sumMin] ;
            if(res3>maxManhattenDistance)
            {
                maxManhattenDistance=res3;
                indexOfMax=3;
            }
            
            //case 4: x2+y2 -(x1+y1) ,x2>x1,y2>y1
            int res4=sum[sumMax]-sum[sumMin];
            if(res3>maxManhattenDistance)
            {
                maxManhattenDistance=res4;
                indexOfMax=4;
            }
            
            printf("%d\n",maxManhattenDistance);
            
        }
    }
    //cout<<"\n\n now\n\n";
    //printManArrays();
    //printSegmentTrees();
}
