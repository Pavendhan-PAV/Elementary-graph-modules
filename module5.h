#include<vector>
#include"mod4.h"
struct edge
{
	int u;
	int v;
	int weight;
};

struct mst
{
int n;
int g[50][50];
};

class MST
{
	private:
	public:
		void MST_Prim(struct Graph *G);
		struct mst MST_Kruskal(struct Graph *G);
		int checkcycle(int a[50][50],int v[],int m);
		void MST_youralgo(struct Graph G);
};
