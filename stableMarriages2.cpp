#include "bits/stdc++.h"
using namespace std;


int men[501][501];
int women[501][501];
int marriedMen[501];
int numMarriages;
 unordered_map<int,int> womenEnagaedtoMen;
void findStableMarriage()
{
    queue<int> freeMen;
    int i,j,k,m,womanCurrentEnagagedTo;
    for(i=1;i<=numMarriages;i++)
    {
        freeMen.push(i);
    }
    womenEnagaedtoMen.clear();

    int menNum,index1,index2,count;

    while(!freeMen.empty())
    {
        
        menNum=freeMen.front();
        freeMen.pop();
        //cout<<"man num "<<menNum<<"\n";
        for(j=men[menNum][0];j<=numMarriages;j++)
        {
            //We are iterating over all the women to whom the guy has not yet proposed
            //1) CHeck if the current women is fre then engage them
            //cout<<"men["<<menNum<<"]["<<j<<"] is "<<men[menNum][j]<<"\n";
            if(womenEnagaedtoMen.find(men[menNum][j])==womenEnagaedtoMen.end())//ie the women is free
            {
                womenEnagaedtoMen[men[menNum][j]]=menNum;
                marriedMen[menNum]=men[menNum][j];
                men[menNum][0]=j+1;
                //cout<<" assigning man "<<menNum<<" to women "<<men[menNum][j]<<"\n";

                break;
                
            }
            else
            {
             //ie the women that the current man is checking out is enaged to someone else, 
             //then we check if that woman's current partner is of a good preference than this men 
                count=0;
                womanCurrentEnagagedTo=womenEnagaedtoMen[men[menNum][j]];
                //cout<<men[menNum][j]<<" womanCurrentEnagagedTo "<<womanCurrentEnagagedTo<<"\n";
                for(k=1;k<=numMarriages and count<2;k++)
                {
                   if(women[men[menNum][j]][k]==womanCurrentEnagagedTo)
                   {
                       count++;
                       index1=k;
                   }
                   if(women[men[menNum][j]][k]==menNum)
                   {
                       count++;
                       index2=k;
                   }
                   if(count==2) break;
                }   
                //cout<<"index 1 is "<<index1<<" index2 is "<<index2<<"\n";
                if(index1<index2) //i.e. the women to whom she is currently engaed to is happy with that man
                {
                    continue;
                }   
                else
                {
                    //cout<<"pushing "<<womenEnagaedtoMen[men[menNum][j]]<<"\n";
                    freeMen.push(womenEnagaedtoMen[men[menNum][j]]);//insert the old guy back in the free pool
                    womenEnagaedtoMen[men[menNum][j]]=menNum;
                    marriedMen[menNum]=men[menNum][j];
                    men[menNum][0]=j+1;
                    //cout<<" assigning man "<<menNum<<" to women "<<men[menNum][j]<<"\n";
                    break;
                }
                
            }
            
        }

    }
}
void printAll()
{
    cout<<" men are \n";
    int i,j;
    for(i=1;i<=numMarriages;i++)
    {
        for(j=0;j<=numMarriages;j++)
        {
            if(j==0) cout<<i<<" ";
            else
            cout<<men[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    cout<<"\n\nwomen  are \n";

    for(i=1;i<=numMarriages;i++)
    {
        for(j=0;j<=numMarriages;j++)
        {
            if(j==0) cout<<i<<" ";
            else
            cout<<women[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int t,i,j,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&numMarriages);
        for(i=0;i<numMarriages;i++)
        {
            scanf("%d",&num);
            women[num][0]=1;//first position is the starting point for the order of selection of women
            for(j=1;j<=numMarriages;j++)
            {
                scanf("%d",&women[num][j]);
            }
        }
        //Now we have entered the men, now we enter the women
        for(i=0;i<numMarriages;i++)
        {
            scanf("%d",&num);
            men[num][0]=1;//first position is the starting point for the order of selection of women
            for(j=1;j<=numMarriages;j++)
            {
                scanf("%d",&men[num][j]);
            }
        }
        //printAll();
        findStableMarriage();
        //cout<<"now done\n stable marriages are \n";
        for(i=1;i<=numMarriages;i++)
        {
            printf("%d %d\n",i,marriedMen[i]);
        }
    }
    
}
