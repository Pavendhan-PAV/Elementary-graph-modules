#include<iostream>
#include <bits/stdc++.h> 
#include"mod4.h"

using namespace std;
dfs D;

void tests::Test_articulationpoints(Graph G)
{
 int T[50][50],x,f=0;
 for(int i=0;i<G.n;i++)
 for(int j=0;j<G.n;j++)
 T[i][j]=G.g[i][j];
 
 for(int c=0;c<G.n;c++)
 {   
    for(int i=0;i<G.n;i++)
 	G.g[c][i]=G.g[i][c]=0;
 	
 	G.count=0;
 	x=D.DFS(G,c);
 	
 	if(x>3)
 	{
 		cout<<c<<" is a Articulation point."<<"\n" 	 ;
 		f=1;
 	}	
      for(int i=0;i<G.n;i++)
	  for(int j=0;j<G.n;j++)
 	  G.g[i][j]=T[i][j]; 
 }
  if(f==0)
  cout<<"\nNo Articulation points.\n";
}

void tests::Test_bridges(Graph G)
{
 int T[50][50],x,f=0,a[G.n],l=-1;
 for(int i=0;i<G.n;i++)
 for(int j=0;j<G.n;j++)
 T[i][j]=G.g[i][j];
 
 for(int c=0;c<G.n;c++)
 { 
    if(c>0)
 	for(int k=0;k<G.n;k++)
 	if(c==a[k])
 	goto s;
 	
 	 a[++l]=c;	
 	for(int i=0;i<G.n;i++)
 	{     	 
 		if(G.g[c][i]!=0)
 		{
 			a[++l]=i;
 			G.g[c][i]=G.g[i][c]=0;
 			x=D.DFS(G);
 		 	if(x>=1)
 		 	{
 				cout<<c<<"-----"<<i<<" is a bridge\n"<<"\n";
 				f=1;
 			}	
 		}
 	 	 for(int i=0;i<G.n;i++)
		 for(int j=0;j<G.n;j++)
		 G.g[i][j]=T[i][j];	 
 	}
 	s:continue;
 }	
 if(f==0)
 cout<<"\nNo bridges.\n";
}

//-------------------------------------------------------------

//const int V = 4; 
  
// This function returns true if  
// graph G[V][V] is Bipartite, else false 
bool isBipartiteUtil(int G[][50],int V, int src, int colorArr[]) 
{ 
    colorArr[src] = 1; 
  
    // Create a queue (FIFO) of vertex numbers a 
    // nd enqueue source vertex for BFS traversal 
    queue <int> q; 
    q.push(src); 
  
    // Run while there are vertices in queue (Similar to BFS) 
    while (!q.empty()) 
    { 
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 ) 
        int u = q.front(); 
        q.pop(); 
  
        // Return false if there is a self-loop  
        if (G[u][u] == 1) 
        return false;  
  
        // Find all non-colored adjacent vertices 
        for (int v = 0; v < V; ++v) 
        { 
            // An edge from u to v exists and 
            // destination v is not colored 
            if (G[u][v] && colorArr[v] == -1) 
            { 
                // Assign alternate color to this 
                // adjacent v of u 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            // An edge from u to v exists and destination 
            // v is colored with same color as u 
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    } 
  
    // If we reach here, then all adjacent vertices can 
    // be colored with alternate color 
    return true; 
} 
  
// Returns true if G[][] is Bipartite, else false 
bool tests::Test_bipartite(Graph G) 
{ 
    // Create a color array to store colors assigned to all 
    // veritces. Vertex/ number is used as index in this 
    // array. The value '-1' of colorArr[i] is used to 
    // ndicate that no color is assigned to vertex 'i'. 
    // The value 1 is used to indicate first color is 
    // assigned and value 0 indicates second color is 
    // assigned. 
    int colorArr[G.n];
    for (int i = 0; i < G.n; ++i) 
        colorArr[i] = -1; 
  
    // This code is to handle disconnected graoh 
    for (int i = 0; i < G.n; i++) 
    if (colorArr[i] == -1) 
        if (isBipartiteUtil(G.g, G.n, i, colorArr) == false) 
        return false; 
  
    return true; 
} 
