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


struct Node
{
    int maxIndex,minIndex;
};
struct Node badnode;


typedef struct Node node1;



int points[100001][2];
int N,Q;
node1 segmentTreexPlusy[400004],segmentTreexMinusy[400004],segmentTreeminusxPlusy[400004],segmentTreeminusxMinusy[400004];
int xPlusy[100001],xMinusy[100001],minusxPlusy[100001],minusxMinusy[100001];

void buildSegmentTree(int i,int j,int node, node1 *segArr,int *arr)
{
    if(i==j)
    {
        segArr[node].maxIndex=i;
        segArr[node].minIndex=i;
        return;
    }
    int mid=(i+j)/2;
    buildSegmentTree(i,mid,2*node,segArr,arr);
    buildSegmentTree(mid+1,j,2*node+1,segArr,arr);
    
    //fill the parent node of the segment tree
    if(arr[segArr[2*node].maxIndex]>arr[segArr[2*node+1].maxIndex])
    {
        segArr[node].maxIndex=segArr[2*node].maxIndex;
    }
    else
    {
        segArr[node].maxIndex=segArr[2*node+1].maxIndex;
    }
    
    if(arr[segArr[2*node].minIndex]<arr[segArr[2*node+1].minIndex])
    {
        segArr[node].minIndex=segArr[2*node].minIndex;
    }
    else
    {
        segArr[node].minIndex=segArr[2*node+1].minIndex;
    }
    
}

void updateSegmentTree(int i,int j, int node,int indexToBeUpdated,int value, node1 *segArr,int *arr)
{
    if(i==j and i==indexToBeUpdated)
    {
        arr[i]=value;
        return;
    }
    int mid=(i+j)/2;
    if(mid>=indexToBeUpdated)
        updateSegmentTree(i,mid,2*node,indexToBeUpdated,value,segArr,arr);
    else
        updateSegmentTree(mid+1,j,2*node+1,indexToBeUpdated,value,segArr,arr);
    
    if(arr[segArr[2*node].maxIndex]>arr[segArr[2*node+1].maxIndex])
    {
        segArr[node].maxIndex=segArr[2*node].maxIndex;
    }
    else
    {
        segArr[node].maxIndex=segArr[2*node+1].maxIndex;
    }
    
    if(arr[segArr[2*node].minIndex]<arr[segArr[2*node+1].minIndex])
    {
        segArr[node].minIndex=segArr[2*node].minIndex;
    }
    else
    {
        segArr[node].minIndex=segArr[2*node+1].minIndex;
    }
}

node1 query(int i,int j,int node,int begin,int end,node1 *segArr,int *arr)
{
    if(i>end or j<begin)
    {
        return badnode;
    }
    if(i>=begin and j<=end)
    {
        return segArr[node];
    }
    int mid=(i+j)/2;
    node1 left=query(i,mid,2*node,begin,end,segArr,arr);
    node1 right=query(mid+1,j,2*node+1,begin,end,segArr,arr);
    
    if(left.maxIndex==-1)
        return right;
    
    if(right.maxIndex==-1)
        return left;
    
    node1 newNode;
    if(arr[left.maxIndex]>arr[right.maxIndex])
    {
        newNode.maxIndex=left.maxIndex;
    }
    else
    {
        newNode.maxIndex=right.maxIndex;
    }
    
    if(arr[left.minIndex]<arr[right.minIndex])
    {
        newNode.minIndex=left.minIndex;
    }
    else
    {
        newNode.minIndex=right.minIndex;
    }
    return newNode;
}
int main()
{
    badnode.minIndex=-1;
    badnode.maxIndex=-1;
    N=getInt();
    int i,j,index,r1,r2;
    char ch2;
    for(i=1;i<=N;i++)
    {
        points[i][0]=getInt();
        points[i][1]=getInt();
        xPlusy[i]=points[i][0]+points[i][1];
        xMinusy[i]=points[i][0]-points[i][1];
        minusxPlusy[i]=-points[i][0]+points[i][1];
        minusxMinusy[i]=-points[i][0]-points[i][1];
    }
    //buildSegmentTree(int i,int j,int node, node *segArr,int *arr)
    buildSegmentTree(1,N,1,segmentTreexPlusy,xPlusy);
    buildSegmentTree(1,N,1,segmentTreeminusxPlusy,minusxPlusy);
    buildSegmentTree(1,N,1,segmentTreexMinusy,xMinusy);
    buildSegmentTree(1,N,1,segmentTreeminusxMinusy,minusxMinusy);
     
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
            //updateSegmentTree(int i,int j, int node,int indexToBeUpdated,int value, node *segArr,int *arr)
            updateSegmentTree(1,N,1,index,r1+r1,segmentTreexPlusy,xPlusy);
            updateSegmentTree(1,N,1,index,r1-r2, segmentTreexMinusy,xMinusy);
            updateSegmentTree(1,N,1,index,-r1+r2, segmentTreeminusxPlusy,minusxPlusy);
            updateSegmentTree(1,N,1,index,-r1-r2,segmentTreeminusxMinusy,minusxMinusy);
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
            //query(int i,int j,int node,int begin,int end,node *segArr,int *arr)
            
            node1 f1=query(1,N,1,r1,r2,segmentTreexPlusy,xPlusy);
            int r1=xPlusy[f1.maxIndex]-xPlusy[f1.minIndex];
            
            //Case 2: x+y min
            node1 f2=query(1,N,1,r1,r2,segmentTreexMinusy,xMinusy);
            int r2=xMinusy[f2.maxIndex] - xMinusy[f2.minIndex];
            
            node1 f3=query(1,N,1,r1,r2,segmentTreeminusxPlusy,minusxPlusy);
            int r3=minusxPlusy[f3.maxIndex] - minusxPlusy[f3.minIndex];
            
            node1 f4=query(1,N,1,r1,r2,segmentTreeminusxMinusy,minusxMinusy);
            int r4=minusxMinusy[f4.maxIndex]-minusxMinusy[f4.minIndex];
            
            //case 1 x1+y1 - (x2+y2) ,x1>x2,y1>y2
            int maxManhattenDistance =INT_MIN,indexOfMax=0;
            
            if(r1>maxManhattenDistance)
            {
                maxManhattenDistance=r1;
                indexOfMax=1;
            }
            if(r2>maxManhattenDistance)
            {
                maxManhattenDistance=r2;
                indexOfMax=2;
            }
            
            //case 4: x2+y2 -(x1+y1) ,x2>x1,y2>y1
            
            if(r3>maxManhattenDistance)
            {
                maxManhattenDistance=r3;
                indexOfMax=3;
            }
            
            
            
            
          
            //case 4: x2+y2 -(x1+y1) ,x2>x1,y2>y1
            
            if(r4>maxManhattenDistance)
            {
                maxManhattenDistance=r4;
                indexOfMax=4;
            }
            
            printf("%d\n",maxManhattenDistance);
            
        }
    }
}
