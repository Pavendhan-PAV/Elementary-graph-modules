#include<iostream>
#include"DFS.h"
using namespace std;

struct stack
{
	int a[50];
	int top;
};

stack S;

void push(int x)
{
	S.top++;
	S.a[S.top]=x;
}

int pop()
{
	int x;
	if(S.top==-1)
		return -1;
	else
	{
		x=S.a[S.top];
		S.top--;
		return x;
	}
}

int dfs::DFS(Graph G)
{
 	int count=0;
	S.top=-1;
	int i=0,j,k=0;                                                                                                      
	
	while(G.v[i]!=0 && i<G.n)
		i++;

	G.v[i]=1;
	cout<<i;
	for(j=0;j<G.n;j++)
	{
		if(G.g[i][j]!=0)
			push(j);
	}
	while(S.top!=-1)
	{
		i=pop();
		
		if(G.v[i]==0)
		{
			G.v[i]=1;
			cout<<"->"<<i;
		}
		for(j=0;j<G.n;j++)
		{
			if(G.g[i][j]!=0)
			{
				if(G.v[j]==0)
					push(j);
			}
		}
	}
	cout<<"\n";
	for(i=0;i<G.n;i++)
	{
		if(G.v[i]==0)
		{
			count++;
			DFS(G,i);
			G.v[i]=1;
			for(j=0;j<G.n;j++)
			{
				if(G.g[i][j]!=0)
				G.v[j]=1;
			}
		}
	}
	return count;	
}

int dfs::DFS(Graph G,int s)
{   
	int l;
 	G.count++;
	S.top=-1; 
	int i=s,j,k=0;                                                                                                      
	G.v[i]=1;
	cout<<i;
	for(j=0;j<G.n;j++)
	{
		if(G.g[i][j]!=0)
			push(j);
	}
	while(S.top!=-1)
	{
		i=pop();
		
		if(G.v[i]==0)
		{
			G.v[i]=1;
			cout<<"->"<<i;
		}
		for(j=0;j<G.n;j++)
		{
			if(G.g[i][j]!=0)
			{
				if(G.v[j]==0)
					push(j);
			}
		}
	}
	cout<<"\n";
	for(i=0;i<G.n;i++)
		if(G.v[i]==0)
		{
			G.count=G.count+DFS(G,i);
			G.v[i]=1;
			for(j=0;j<G.n;j++)
			{
				if(G.g[i][j]!=0)
				{
					G.v[j]=1;			
					l=j;
					for(int k=0;k<G.n;k++)
						if(G.g[l][k]!=0)
							G.v[k]=1;
				}
				
			}
		}
	return G.count;
}

void dfs::DFS(Graph G,int s,int t)
{
	S.top=-1;
	int i=s,j,k=0,f=0;                                                                                                       
	
	G.v[i]=1;
	for(j=0;j<G.n;j++)
	{
		if(G.g[i][j]!=0)
			push(j);
	}
	while(S.top!=-1)
	{
		i=pop();
		if(i==t)
		{
			cout<<t<<" can be reached from "<<s<<"\n";
			f=1;
			break;
		}
		
		if(G.v[i]==0)
			G.v[i]=1;
		for(j=0;j<G.n;j++)
		{
			if(G.g[i][j]!=0)
			{
				if(G.v[j]==0)
					push(j);
			}
		}
	}
	if(f==0)
		cout<<t<<" cannot be reached from "<<s<<"\n";
}

