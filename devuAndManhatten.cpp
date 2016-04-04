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

void buildSegmentTree(int i,int j,int node,node1 *segArr,int *arr)
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
    
    //since in this version of the code the segment tree stores both the max and the min value 
    
    if(arr[segArr[2*node].maxIndex] > arr[segArr[2*node+1].maxIndex])
    {
        segArr[node].maxIndex=segArr[2*node].maxIndex;
    }
    else
    {
        segArr[node].maxIndex=segArr[2*node+1].maxIndex;
    }
    
    if(arr[segArr[2*node].minIndex] < arr[segArr[2*node+1].minIndex])
    {
        segArr[node].minIndex=segArr[2*node].minIndex;
    }
    else
    {
        segArr[node].minIndex=segArr[2*node+1].minIndex;
    }
    
}

void updateSegmentTree(int i,int j,int node,int value,int indexToBeUpdated,node1 *segArr,int *arr)
{
    //cout<<"in up node="<<node<<" and  indexToBeUpdated "<<indexToBeUpdated<<"\n";
    if(i==j and i==indexToBeUpdated)
    {
        arr[indexToBeUpdated]=value;
        return;
    }
    int mid=(i+j)/2;
    //cout<<"in up node="<<node<<" and  indexToBeUpdated "<<indexToBeUpdated<<" mid is "<<mid<<"\n";
    if(mid >= indexToBeUpdated)
    {
        updateSegmentTree(i,mid,2*node,value,indexToBeUpdated,segArr,arr);
    }
    else
    {
        updateSegmentTree(mid+1,j,2*node+1,value,indexToBeUpdated,segArr,arr);
    }

    
    
    if(arr[segArr[2*node].maxIndex] > arr[segArr[2*node+1].maxIndex])
    {
        segArr[node].maxIndex=segArr[2*node].maxIndex;
    }
    else
    {
        segArr[node].maxIndex=segArr[2*node+1].maxIndex;
    }
    
    if(arr[segArr[2*node].minIndex] < arr[segArr[2*node+1].minIndex])
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
    if(j<begin or i>end)
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
    
    if(arr[left.maxIndex] > arr[right.maxIndex])
    {
        newNode.maxIndex=left.maxIndex;
    }
    else
    {
        newNode.maxIndex=right.maxIndex;
    }
    
    if(arr[left.minIndex] > arr[right.minIndex])
    {
        newNode.minIndex=right.minIndex;
    }
    else
    {
        newNode.minIndex=left.minIndex;
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
    //Now we have stored the arrays x+y,x-y,-x+y,x-y
    //Now we need to build  a segmentTree out of it
    //Build 4 segment trees 
    //1) segment tree for x+y max
    buildSegmentTree(1,N,1,segmentTreexPlusy,xPlusy);
     //cout<<"after summax\n";
    //printSegmentTrees();
    //2)segmentTree for x-y max
    buildSegmentTree(1,N,1,segmentTreexMinusy,xMinusy);
    //cout<<"after submax\n";
    //printSegmentTrees();
    //3)segmentTree for x+y min
    buildSegmentTree(1,N,1,segmentTreeminusxPlusy,minusxPlusy);
    //cout<<"after summin\n";
    //printSegmentTrees();
    //4)segmentTree for x-y min
    buildSegmentTree(1,N,1,segmentTreeminusxMinusy,minusxMinusy);
    //cout<<"after submin\n";
    //now we have built the segment trees
    //printManArrays();
    //printSegmentTrees();
    //cout<<"hi\n";
    
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
            //cout<<"qw\n";
            updateSegmentTree(1,N,1,r1+r2,index, segmentTreexPlusy,xPlusy);
            //cout<<"hi2\n";
            //2)update segmentTreeSubMax
            updateSegmentTree(1,N,1,-r1+r2,index, segmentTreeminusxPlusy,minusxPlusy);
            
            //3)update segmentTreeSumMin
            updateSegmentTree(1,N,1,r1-r2,index, segmentTreexMinusy,xMinusy);
            
            //4)update segmentTreeSubMin
            updateSegmentTree(1,N,1,-r1-r2,index, segmentTreeminusxMinusy,minusxMinusy);
            //int i,int j,int node,int indexToBeUpdated,int value,int *segArr,int *arr,bool max)
            //now we need to update the sum and the subtract arrays, and consequently the segment trees
            //nt i,int j,int node,int indexToBeUpdated,int value,int *segArr,int *arr,bool max)
            //cout<<"hi3\n";
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
            int sumMax=xPlusy[f1.maxIndex]-xPlusy[f1.minIndex];
            
            //Case 2: x+y min
            node1 f3=query(1,N,1,r1,r2,segmentTreexMinusy,xMinusy);
            int sumMin=xMinusy[f3.maxIndex] - xMinusy[f3.minIndex];
            
            //case 3: x-y max
            node1 f2=query(1,N,1,r1,r2,segmentTreeminusxPlusy,minusxPlusy);
            int subMax=minusxPlusy[f2.maxIndex]-minusxPlusy[f2.minIndex];
            
            //case 4: x-y min
            node1 f4=query(1,N,1,r1,r2,segmentTreeminusxMinusy,minusxMinusy);
            int subMin=minusxMinusy[f4.maxIndex]-minusxMinusy[f4.minIndex];
            
            //Each of the above query operations take O(log(n))
            int maxManhattenDistance=INT_MIN,indexOfMax;
            
            //case 1 x1+y1 - (x2+y2) ,x1>x2,y1>y2
            int res1=sumMax;
            
            if(res1>maxManhattenDistance)
            {
                maxManhattenDistance=res1;
                indexOfMax=1;
            }
            
            //case 2 x1-y1 -(x2-y2) ,x1>x2,y2>y1
            int res2= sumMin;
            if(res2>maxManhattenDistance)
            {
                maxManhattenDistance=res2;
                indexOfMax=2;
            }
            
            //case 3 : x2-y2 -(x1+y1) , x2>x1,y1>y2
            int res3=subMax;
            if(res3>maxManhattenDistance)
            {
                maxManhattenDistance=res3;
                indexOfMax=3;
            }
            
            //case 4: x2+y2 -(x1+y1) ,x2>x1,y2>y1
            int res4=subMin;
            if(res3>maxManhattenDistance)
            {
                maxManhattenDistance=res4;
                indexOfMax=4;
            }
            
            printf("%d\n",maxManhattenDistance);
            
        }
    }
}
