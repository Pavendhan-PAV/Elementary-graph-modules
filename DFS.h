struct Graph
{
	int g[50][50];
	int n;
	int source;
	int destination;
	int graphtype;
	int longestpath_length;
	int l_from;
	int l_to;
	int l;
	int v[50];
	int count;
};

class dfs
{
	private:
	public:
		int DFS(Graph G);
		int DFS(Graph G,int s);
		void DFS(Graph G,int s,int t);
};
