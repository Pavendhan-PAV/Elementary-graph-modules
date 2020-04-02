#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<climits>
#include"module3.h"

#define NINF INT_MIN
using namespace std;

bool bfs(struct Graph *G,int pred[],int distance[])
{
list<int> queue;
bool visited[G->n];
for(int i=0;i<G->n;i++)
{
 visited[i]=false;
distance[i]=INT_MAX;
pred[i]=-1;
}
visited[G->source]=true;
distance[G->source]=0;
queue.push_back(G->source);

while(!queue.empty())
{
int u=queue.front();
queue.front();
queue.pop_front();
for(int i=0;i<G->n;i++)
{
if(G->g[u][i]!=0)
{
if(visited[i]==false)
{
visited[i]=true;
distance[i]=distance[u]+1;
pred[i]=u;
queue.push_back(i);

if(i==G->destination)
return true;
}
}
}
}
return false;
}



void  fun(struct Graph *G)
{
int pred[G->n],distance[G->n];
if(bfs(G,pred,distance)==false )
{
cout<<"\n Not possible:";
return;
}
vector<int> path;
int crawl=G->destination;
path.push_back(crawl);
while(pred[crawl]!=-1)
{
path.push_back(pred[crawl]);
crawl=pred[crawl];
}
cout<<"Path Length:"<<distance[G->destination];
cout<<"\nPath:";
for(int i=path.size()-1;i>=0;i--)
cout<<path[i]<<" ";

}





void module3::fillarr(struct Graph *G,int i,int e,int weight)
{
G->g[i][e]=weight;

if(G->graphtype==0)
G->g[e][i]=weight;


}


int module3::BFS(struct Graph *G)
{

vector<bool> visited(G->n,false);
vector<int> queue;
vector<int> tree;
queue.push_back(G->source);

visited[G->source]=true;

int v;
while(!queue.empty())

{
v=queue[0];
tree.push_back(v);
queue.erase(queue.begin());

for(int i=0;i<G->n;i++)
{
if((!visited[i]) && G->g[v][i]==1) 
{

queue.push_back(i);
visited[i]=true;

}//if

}//for


}//while

return tree.back();

}//bfs

void module3::ts(struct Graph *G,int u,bool visited[],stack<int> &stk)
{
visited[u]=true;
for(int v=0;v<G->n;v++)
{
if(G->g[u][v]!=0)
{
if(!visited[v])
ts(G,v,visited,stk);
}
}
stk.push(u);
}

void module3::LPDAG(struct Graph *G)
{
stack<int> stk;
int distance[G->n];
bool visited[G->n];

for(int i=0;i<G->n;i++)
visited[i]=false;

for(int i=0;i<G->n;i++)
if(!visited[i])
ts(G,i,visited,stk);

for(int i=0;i<G->n;i++)
distance[i]=NINF;

distance[G->source]=0;

while(!stk.empty())
{
 int nv=stk.top();
stk.pop();

if(distance[nv]!=NINF)
{
for(int v=0;v<G->n;v++)
{
if(G->g[nv][v] && (G->g[nv][v])!=NINF)
{
if(distance[v]<distance[nv]+G->g[nv][v])
distance[v]=distance[nv]+G->g[nv][v];

}
}
}
}
int max=distance[0];
int index;
for(int i=1;i<G->n;i++)
{
if(distance[i]>max)
{
max=distance[i];
index=i;
}
}

if(G->longestpath_length<max)
{
G->longestpath_length=max;
G->l_from=G->source;
G->l_to=index;
}
}
void module3::LPUAG(struct Graph *G)
{

G->l_to=BFS(G);
G->source=G->l_to;
G->l_from=BFS(G);

}

int print(int dist[],int size)
{
cout<<"The shortest distance possible to all vertices from the given source vertex:\n";
for(int i=0;i<size;i++)
cout<<"Vertex "<<i<<":"<<dist[i]<<"\n";

}

int min_index(int dist[],bool sptset[],int size)
{
int min=INT_MAX,index;

for(int v=0;v<size;v++)
  if(sptset[v]==false && dist[v]<=min)
	{
min=dist[v] ;
index=v;
}
 
return index;

}

void dijkstra(struct Graph *G)
{
int distance[G->n];
bool sd[G->n];

for(int i=0;i<G->n;i++)
{
distance[i]=INT_MAX;
sd[i]=false;
}
distance[G->source]=0;

for(int i=0;i<(G->n)-1;i++)
{
int u=min_index(distance,sd,G->n);
sd[u]=true;
for(int j=0;j<G->n;j++)
{
if(!sd[j] && G->g[u][j] && distance[u]!=INT_MAX && distance[j]>distance[u] + G->g[u][j])
distance[j]=distance[u]+G->g[u][j];

}
}
print(distance,G->n);

}

void module3::LPATH(struct Graph *G,int flag)
{
if(flag==0)
{
LPUAG(G);

}
else
{
for(int i=0;i<G->n;i++)
{
G->source=i;
LPDAG(G);
}

}

}

void module3::BFS_SPATH(struct Graph *G,int flag)
{
if(flag==0)
{
dijkstra(G);
}
else
fun(G);
}

int module3::MAX_WEIGHT_MST(struct Graph *G)
{
MST m5;
struct mst tree=m5.MST_Kruskal(G);

int maxweight=NINF;

for(int i=0;i<G->n;i++)
{
for(int j=0;j<G->n;j++)
{ 
if(tree.g[i][j]!=0)
if(maxweight<G->g[i][j])
maxweight=G->g[i][j];

}
}
return maxweight;

}


