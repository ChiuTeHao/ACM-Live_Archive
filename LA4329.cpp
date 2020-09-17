#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int MAXNODE=100000,MAXPLAYER=20000;
int lowbit(int x){return x&(-x);}
int sum(int idx,int tree[])
{
    int ret=0;
    while(idx>0)
    {
        ret+=tree[idx];
        idx-=lowbit(idx);
    }
    return ret;
}
void add(int idx,int val,int tree[],int n)
{
    while(idx<=n)
    {
        tree[idx]+=val;
        idx+=lowbit(idx);
    }
}
int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        int tree[MAXNODE+1]={};
        int preless[MAXPLAYER+1],backless[MAXPLAYER+1];
        int n,num[MAXPLAYER+1];
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            add(num[i],1,tree,MAXNODE);
            preless[i]=sum(num[i],tree)-1;
        }
        for(int i=1;i<=n;i++)
        {
            add(num[i],-1,tree,MAXNODE);
            backless[i]=sum(num[i],tree);
        }
        
        long long int game=0;
        for(int i=1;i<=n;i++)
        {
            game+=preless[i]*(n-i-backless[i])+(i-1-preless[i])*backless[i];
        }
        printf("%lld\n",game);
    }
}
