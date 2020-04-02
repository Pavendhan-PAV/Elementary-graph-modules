#include"BFS.h"
#include<iostream>
using namespace std;

struct queue
{
	int a[50];
	int rear,front;
};

queue q;

void enqueue(int x)
{
	if(q.front==-1)
	{
		q.rear++;
		q.front++;
	}
	else
	q.rear++;
	q.a[q.rear]=x;
}

void dequeue()
{
	int x;
	if(q.front==-1)
		return;
	else if(q.rear==q.front)
	{
		x=q.a[q.front];
		q.rear=-1;
		q.front=-1;
		cout<<"\n"<<x;
	}
	else
	{
		x=q.a[q.front];
		q.front++;
		cout<<"\n"<<x;
	}	
}

void bfs::BFS(struct Graph G)
{
	q.rear=-1;
	q.front=-1;
	int s=0,count=0;
	G.v[s]=1;
	count++;
	enqueue(s);
	int j=0;
	while(j<G.n)
	{
	for(int i=0;i<G.n;i++)
	{
		if(j>=1)
			s=q.a[q.front];
		if(i==s)
		i++;
		if(i==G.n)
		break;	
		if(G.g[s][i]!=0)
		 {
		 	if(G.v[i]==1)
		 	{
		 	 if(count%2!=0)
		 	 continue;
			}
			count++;
		  	G.v[i]=1;
		  	enqueue(i);
		 }
	}
	j++;
    dequeue();
	}	
}
void bfs::BFS(struct Graph G,int s)
{
	q.rear=-1;
	q.front=-1;
	G.v[s]=1;
	enqueue(s);
	int j=0;
	while(j<G.n)
	{
	for(int i=0;i<G.n;i++)
	{
		if(j>=1)
			s=q.a[q.front];
		if(i==s)
		i++;
		if(i==G.n)
		break;	
		if(G.g[s][i]!=0)
		 {
		 	if(G.v[i]==1)
		 	continue;
		  	G.v[i]=1;
		  	enqueue(i);
		 }
	}
	j++;
	dequeue();
	}	
}

void bfs::BFS(struct Graph G,int s, int t)
{
	q.rear=-1;
	q.front=-1;
	G.v[s]=1;
	int x=s;
	enqueue(s);
	int j=0,flag=0;
	while(j<G.n)
	{
	for(int i=0;i<G.n;i++)
	{
		if(j>=1)
			s=q.a[q.front];
		if(i==s)
		i++;
		if(i==G.n)
		break;
		if(G.g[s][i]!=0)
		 {
		 	if(t==i)
		 	flag=1;
		 	if(G.v[i]==1)
		 	continue;
		  	G.v[i]=1;
		  	enqueue(i);
		 }
	}
	j++;
	dequeue();
	}
	if(flag==1)
	cout<<"\n\n"<<t<<" is reachable from "<<x;
	else
	cout<<"\n\n"<<t<<" is not reachable from "<<x;	
}
