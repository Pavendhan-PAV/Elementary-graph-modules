#include<iostream>
#include<climits>
#include"module5.h"
using namespace std;

struct stack
{
	int a[50];
	int top;
};

stack ST;

void pushs(int x)
{
	ST.top++;
	ST.a[ST.top]=x;
}

int pops()
{
	int x;
	if(ST.top==-1)
		return -1;
	else
	{
		x=ST.a[ST.top];
		ST.top--;
		return x;
	}
}

void merge_sort(edge a[],int beg,int end)
{
	if(beg==end)
		return;
	else
	{
		merge_sort(a,beg,(beg+end)/2);
		merge_sort(a,((beg+end)/2)+1,end);
		edge b[20];
		int i=beg,j=((beg+end)/2)+1,k=beg;
		
		while(i<=(beg+end)/2 && j<=end)
		{
			if(a[i].weight<a[j].weight)
			{
				b[k]=a[i];
				i++;
				k++;
			}
			else
			{
				b[k]=a[j];
				j++;
				k++;
			}
		}
		if(i<=(beg+end)/2)
		{
			while(i<=(beg+end)/2)
			{
				b[k]=a[i];
				i++;
				k++;
			}
		}
		else
		{
			while(j<=end)
			{
				b[k]=a[j];
				j++;
				k++;
			}
		}
		for(i=beg;i<=end;i++)
			a[i]=b[i];
	}
}

int MST::checkcycle(int a[50][50],int v[],int m)
{
	int i,j,k=0,p=0;
	ST.top=-1;	
	for(i=0;i<m;i++)
		if(v[i]==0)
		{
			v[i]=1;
			break;
		}
		
	for(j=0;j<m;j++)
	{
		if(a[i][j]!=0)
			pushs(j);
	}
	while(ST.top!=-1)
	{
		p=i;
		i=pops();
		if(v[i]==0)
			v[i]=1;
		else
			return 1;
			
		for(j=0;j<m;j++)
		{
			if(a[i][j]!=0)
			{
				if(v[j]==0)
					pushs(j);
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(v[i]==0)
			p=checkcycle(a,v,m);
	}
	return 0;
}

int minKey(struct Graph *G,int key[], bool mstSet[])  
{  
    
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < G->n; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  

void printMST(int parent[], struct Graph *G)  
{  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < G->n; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<G->g[i][parent[i]]<<" \n";  
}  

void MST::MST_Prim(struct Graph *G)  
{  
    int parent[G->n];  
   
    int key[G->n];  
      
   
    bool mstSet[G->n];  
  
    
    for (int i = 0; i < G->n; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
     
    key[0] = 0;  
    parent[0] = -1; 
  
    for (int count = 0; count < (G->n) - 1; count++) 
    {  
     
        int u = minKey(G,key, mstSet);  
  
        mstSet[u] = true;  
  
        for (int v = 0; v < G->n; v++)  
  
            if (G->g[u][v] && mstSet[v] == false && G->g[u][v] < key[v])  
                parent[v] = u, key[v] = G->g[u][v];  
    }  
  
    
    printMST(parent, G);  
}  

struct mst MST::MST_Kruskal(struct Graph *G)
{
	edge e[G->n];
struct mst tree;
	int i,j,k=0,c=0,ins_edges=0,x[50],p;
	
	for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++)
			tree.g[i][j]=0;
	
	for(i=0;i<G->n-1;i++)
		for(j=i+1;j<G->n;j++)
		{
			if(G->g[i][j]!=0)
			{
				e[k].u=i;
				e[k].v=j;
				e[k].weight=G->g[i][j];
				k++;
			}
		}

	merge_sort(e,0,k-1);
	
	tree.g[e[0].u][e[0].v]=e[0].weight;
	tree.g[e[0].v][e[0].u]=e[0].weight;
	ins_edges++;
	tree.g[e[1].u][e[1].v]=e[1].weight;
	tree.g[e[1].v][e[1].u]=e[1].weight;
	ins_edges++;

	i=2;
	while(ins_edges<G->n-1)
	{
		tree.g[e[i].u][e[i].v]=e[i].weight;
		tree.g[e[i].v][e[i].u]=e[i].weight;

		for(j=0;j<G->n;j++)
			x[j]=0;

		c=checkcycle(tree.g,x,G->n);
		
		if(c==1)
		{
			tree.g[e[i].u][e[i].v]=0;
			tree.g[e[i].v][e[i].u]=0;
		}
		else
			ins_edges++;
		i++;
	}
	
	cout<<"\nMST(Kruskal):\n  ";
	for(i=0;i<G->n;i++)
		cout<<i<<" ";
	cout<<"\n";
	for(i=0;i<G->n;i++)
	{
		cout<<i<<" ";
		for(j=0;j<G->n;j++)
			cout<<tree.g[i][j]<<" ";
		
		cout<<"\n";
	}
return tree;
}
//-------------


int isconnected(struct Graph G)
{
	int count=0;
	for(int i=0;i<G.n;i++)
	for(int j=i;j<G.n;j++)
 	{
 		if(G.g[i][j]!=0)
			count++;
	}
	if(count>=(G.n-1))	
		return 1;
	else
		return 0;
}

int sort(int a[],int n)
{
 int t;
 
 for(int i=0;i<n;++i)
 for(int j=0;j<n-1-i;j++)
 {
  if(a[j]>a[j+1])
  {
   t=a[j];
   a[j]=a[j+1];
   a[j+1]=t;
  }
 }
}

void MST::MST_youralgo(struct Graph G)
{
 int a[100],k=0,x;
  
 for(int i=0;i<G.n;i++)
 for(int j=0;j<G.n;j++)
 	a[k++]=G.g[i][j];
 
 sort(a,k);	
 for(int i=k;i>=0;i--)
 {
 	for(int l=0;l<G.n;l++)
 	for(int j=l;j<G.n;j++)
 	{
 		if(G.g[l][j]==a[i])
 		{
 			G.g[l][j]=G.g[j][l]=0;
 			x=isconnected(G);
 			if(x==0)
 				G.g[l][j]=G.g[j][l]=a[i];
 		}		
 	}
 }
 cout<<"\nMST: ";
 for(int i=0;i<G.n;i++)
 for(int j=i;j<G.n;j++)
 {
 	if(G.g[i][j]!=0)
 		cout<<i<<"->"<<j<<"\t";
 }
}

