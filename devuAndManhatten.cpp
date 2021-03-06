#include "bits/stdc++.h"
#define blank putc_unlocked('\n',stdout)
#define mod 1000000007

using namespace std;
typedef long long int ll;
char ch,temp[1<<10];
ll getInt()
{
        ch=getc_unlocked(stdin);
        while(ch<'-')
        {
               ch=getc_unlocked(stdin);
        }

        ll sign=1,num=0;

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
    ll maxIndex,minIndex;
};
struct Node badnode;


typedef struct Node node1;



ll points[100001][2];
ll N,Q;
node1 segmentTreexPlusy[400004],segmentTreexMinusy[400004],segmentTreeminusxPlusy[400004],segmentTreeminusxMinusy[400004];
ll xPlusy[100001],xMinusy[100001],minusxPlusy[100001],minusxMinusy[100001];

void buildSegmentTree(ll i,ll j,ll node, node1 *segArr,ll *arr)
{
    if(i==j)
    {
        segArr[node].maxIndex=i;
        segArr[node].minIndex=i;
        return;
    }
    ll mid=(i+j)/2;
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

void updateSegmentTree(ll i,ll j, ll node,ll indexToBeUpdated,ll value, node1 *segArr,ll *arr)
{
    if(i==j and i==indexToBeUpdated)
    {
        arr[i]=value;
        return;
    }
    ll mid=(i+j)/2;
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

node1 query(ll i,ll j,ll node,ll begin,ll end,node1 *segArr,ll *arr)
{
    //cout<<"i="<<i<<" j="<<j<<" begin="<<begin<<" end = "<<end<<"\n";
    if(i>end or j<begin)
    {
        return badnode;
    }
    if(i>=begin and j<=end)
    {
        return segArr[node];
    }
    ll mid=(i+j)/2;
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
void printR(ll r1,ll r2,ll r3,ll r4)
{
    cout<<"r1 = "<<r1<<" r2= "<<r2<<" r3= "<<r3<<" r4= "<<r4<<"\n";
}


void printArrs()
{
    ll i,j;
    cout<<"the xplus y is \n";
    for(i=1;i<=N;i++)
        cout<<xPlusy[i]<<" ";
    cout<<"\nthe xMinusy is \n";
    for(i=1;i<=N;i++)
        cout<<xMinusy[i]<<" ";
    
     cout<<"\nthe minusxPlusy is \n";
    for(i=1;i<=N;i++)
        cout<<minusxPlusy[i]<<" ";
        
     cout<<"\nthe minusxMinusy is \n";
    for(i=1;i<=N;i++)
        cout<<minusxMinusy[i]<<" ";
        cout<<"\n";
}

void printSegmentTrees()
{
    ll i,j;
    cout<<"the maxindex os xplusy is \n";
    
    for(i=1;i<=8;i++)
    {
        cout<<segmentTreexPlusy[i].maxIndex<<" ";
    }  
    
    cout<<"\nthe minindex os xplusy is \n";
    for(i=1;i<=8;i++)
    {
        cout<<segmentTreexPlusy[i].minIndex<<" ";
    }  
    
    cout<<"\nthe maxindex os xMinusy is \n";
    for(i=1;i<=8;i++)
    {
        cout<<segmentTreexMinusy[i].maxIndex<<" ";
    } 
    cout<<"\nthe minindex os xMinusy is \n";
    for(i=1;i<=8;i++)
    {
        cout<<segmentTreexMinusy[i].minIndex<<" ";
    }   
    
}

int main()
{
    badnode.minIndex=-1;
    badnode.maxIndex=-1;
    N=getInt();
    ll i,j,index,rr1,rr2;
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
    //buildSegmentTree(ll i,ll j,ll node, node *segArr,ll *arr)
    buildSegmentTree(1,N,1,segmentTreexPlusy,xPlusy);
    buildSegmentTree(1,N,1,segmentTreeminusxPlusy,minusxPlusy);
    buildSegmentTree(1,N,1,segmentTreexMinusy,xMinusy);
    buildSegmentTree(1,N,1,segmentTreeminusxMinusy,minusxMinusy);
    //printArrs();
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
            rr1=getInt();
            rr2=getInt();
            points[index][0]=rr1;
            points[index][1]=rr2;
            //updateSegmentTree(ll i,ll j, ll node,ll indexToBeUpdated,ll value, node *segArr,ll *arr)
           // cout<<"rr1 is "<<rr1<<" rr2 is "<<rr2<<"\n";
            updateSegmentTree(1,N,1,index,rr1+rr2,segmentTreexPlusy,xPlusy);
            updateSegmentTree(1,N,1,index,rr1-rr2, segmentTreexMinusy,xMinusy);
            updateSegmentTree(1,N,1,index,-rr1+rr2, segmentTreeminusxPlusy,minusxPlusy);
            updateSegmentTree(1,N,1,index,-rr1-rr2,segmentTreeminusxMinusy,minusxMinusy);
            //printArrs();
            //printSegmentTrees(); 
        }
        else
        {
            rr1=getInt();
            rr2=getInt();
            //Now we query the node that we have to get the range between , remember to add +1 to the range values since we are using index 1 arrays
            rr1++;
            rr2++;
            //Now we have to get the maximum over all possible points and then check them
            //Case 1 : x+y max
            //ll i,ll j,ll begin,ll end,ll node,ll *segArr,ll *arr,bool max)
            //query(ll i,ll j,ll node,ll begin,ll end,node *segArr,ll *arr)
             //cout<<"calling query for xplusy\n";
            node1 f1=query(1,N,1,rr1,rr2,segmentTreexPlusy,xPlusy);
            ll r1=xPlusy[f1.maxIndex]-xPlusy[f1.minIndex];
            
            //Case 2: x+y min
<<<<<<< HEAD
            node1 f2=query(1,N,1,r1,r2,segmentTreexMinusy,xMinusy);
            int r2=xMinusy[f2.maxIndex] - xMinusy[f2.minIndex];
            nexus 5 gyroscope
            node1 f3=query(1,N,1,r1,r2,segmentTreeminusxPlusy,minusxPlusy);
            int r3=minusxPlusy[f3.maxIndex] - minusxPlusy[f3.minIndex];
=======
            //cout<<"calling query for xminusy\n";
            node1 f2=query(1,N,1,rr1,rr2,segmentTreexMinusy,xMinusy);
            ll r2=xMinusy[f2.maxIndex] - xMinusy[f2.minIndex];
            //cout<<"xMinusy[f2.maxIndex] is "<<f2.maxIndex<<"\n";
            
             //cout<<"calling query for minusxPlusy\n";
            node1 f3=query(1,N,1,rr1,rr2,segmentTreeminusxPlusy,minusxPlusy);
            ll r3=minusxPlusy[f3.maxIndex] - minusxPlusy[f3.minIndex];
>>>>>>> 6bd2e3dc1e952e6dd211746964b8fd2ba841e193
            
             //cout<<"calling query for minusxminusy\n";
            node1 f4=query(1,N,1,rr1,rr2,segmentTreeminusxMinusy,minusxMinusy);
            ll r4=minusxMinusy[f4.maxIndex]-minusxMinusy[f4.minIndex];
            
            //case 1 x1+y1 - (x2+y2) ,x1>x2,y1>y2
            ll maxManhattenDistance =INT_MIN,indexOfMax=0;
            //printR(r1,r2,r3,r4);
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
<<<<<<< HEAD

          
            //case 4: x2+nexus 5 gyroscopey2 -(x1+y1) ,x2>x1,y2>y1
=======
            
           
>>>>>>> 6bd2e3dc1e952e6dd211746964b8fd2ba841e193
            
            if(r4>maxManhattenDistance)
            {
                maxManhattenDistance=r4;
                indexOfMax=4;
            }
            
            printf("%lld\n",maxManhattenDistance);
            
        }
    }
}
