/* Change Graphtype and flag according to the function before executing
   Graphtype: undirected(0) directed(1)
   Flag: unweighted(0) weighted(0)     
*/



#include<iostream>     

//GRAPH MODULES

#include"module3.h"




void print_graph(struct Graph G)                 //Function To Print Graph
{
cout<<"\nGRAPH:\n  ";
	for(int i=0;i<G.n;i++)
		cout<<i<<" ";
	cout<<"\n";
	for(int i=0;i<G.n;i++)
	{
		cout<<i<<" ";
		for(int j=0;j<G.n;j++)
			cout<<G.g[i][j]<<" ";
		
		cout<<"\n";
	}
}

void reset_visit(struct Graph G)                 //Function to clear visited history
{

  for(int i=0;i<G.n;i++)

{

G.v[i]=0;

}

}



//-----------------------------------------------------------------------------------

int main()
{
struct Graph G;
int T[50][50];
	int i=0,j,c=0,a=0,w;
	cout<<"\nIs the Graph Undirected (Enter 0) or Directed (Enter 1) : ";
	cin>>G.graphtype;
	cout<<"\nEnter number of elements: ";
	cin>>G.n;
	for(i=0;i<G.n;i++)
	{
		G.v[i]=0;
		for(j=0;j<G.n;j++)
				G.g[i][j]=0;
	}
	for(int i=0;i<G.n;i++)
 	for(int j=0;j<G.n;j++)
 	T[i][j]=G.g[i][j];

	cout<<"\nEnter number of links: ";
	cin>>G.l;
	
	cout<<"\nEnter the links and weight of the links present (l_from,l_to,weight) : ";
	while(a<G.l)
	{
		scanf("%d%d%d",&i,&j,&w);
		G.g[i][j]=w;
		G.g[j][i]=w;
		a++;
	}
	

//Module1:------------------------------------------------------------------------------------

dfs D;
int count;
cout<<"\n----------\n";
cout<<"DFS:\n";
count=D.DFS(G);

//cout<<"\n"<<count;

reset_visit(G);//

cout<<"\nEnter DFS source vertex:";

int source;

cin>>source;

D.DFS(G,source);

reset_visit(G);//

cout<<"\nEnter Destination vertex:";

int destination;

cin>>destination;

D.DFS(G,source,destination);

reset_visit(G);//

//Module 2:--------------------------------------------------------------------------

bfs B;
cout<<"\n----------\n";
cout<<"BFS:\n";
B.BFS(G);

reset_visit(G);//

cout<<"\n\nEnter BFS source vertex:";

cin>>source;

B.BFS(G,source);

reset_visit(G);//

cout<<"\n\nEnter Destination vertex:";

cin>>destination;

B.BFS(G,source,destination);

reset_visit(G);//
cout<<"\n----------\n";

//Module 4:--------------------------------------------------------------------------

tests M4;

M4.Test_bipartite(G) ? cout<<"\n\nG is Bipartite\n" : cout<<"\n\nG isn't Bipartite\n";

reset_visit(G);
cout<<"\n----------\n";

M4.Test_articulationpoints(G);

reset_visit(G);
cout<<"\n----------\n";

M4.Test_bridges(G);

reset_visit(G);
cout<<"\n----------\n";

//Module 5:--------------------------------------------------------------------------

MST M5;

//(M5.checkcycle(G.g,G.v,G.n)==1)?(cout<<"\nThis Graph contains cycle.\n"):(cout<<"\nThis Graph doesn't contain cycle.\n");
//reset_visit(G);
M5.MST_youralgo(G);

M5.MST_Prim(&G);//TREE contains the MST

M5.MST_Kruskal(&G);

//Module 3:-------------------------------------------------------------------------

cout<<"\n----------\n";
module3 M3;

cout<<"\nEnter Flag: ";

int flag;

cin>>flag;

cout<<"\nEnter the source and destination to check the shortest path between them: ";

cin>>G.source;

cin>>G.destination;

M3.BFS_SPATH(&G,flag);

cout<<"\n----------\n";

M3.LPATH(&G,flag);

cout<<"Longest path is from:"<<G.l_from<<" to "<<G.l_to;
cout<<"\n----------\n";

int Max_Weight=M3.MAX_WEIGHT_MST(&G);

cout<<"\nMAX WEIGHT OF MST:"<<Max_Weight;
cout<<"\n----------\n";

}


//----------------------------------E N d---------------------------------------------//

