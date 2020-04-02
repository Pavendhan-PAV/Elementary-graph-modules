#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include"module5.h"
#define NINF INT_MIN
using namespace std;



class module3
{


public:

//helper functions
void fillarr(struct Graph *G,int i,int e,int weight=1);
int BFS(struct Graph *G);
void LPUAG(struct Graph *G);
void ts(struct Graph *G,int u,bool visited[],stack<int> &stk);
void LPDAG(struct Graph *G);

//module 3
void BFS_SPATH(struct Graph *G,int flag);
void LPATH(struct Graph *G, int flag);
int MAX_WEIGHT_MST(struct Graph *G);

};
