#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e5+10;
#define forn(i,a,b) for(int i = a; i < b; i++)
typedef vector<int> vi;
vector<vi> graph;

int low[maxn],num[maxn],p[maxn],articulationVertex[maxn],counter,root,rootChildren;

void dfs(int u){
	low[u] = num[u] = counter++;
	forn(i,0,(int)graph[u].size()){
		int v = graph[u][i];
		if(num[v] == -1){
			p[v] = u;
			if(u == root) rootChildren++;
			dfs(v);
			if(low[v] >= num[u]) articulationVertex[u] = true;
			if(low[v] > num[u]) cout << "Edge " << u << " " << v << " is a bridge\n";
			low[u] = min(low[u],num[v]);
		}else if(v != p[u]) low[u] = min(low[u],num[v]);
	}
}

int main(){
	int n,m; cin >> n >> m;
	graph.assign(n,vi());
	counter = 0;
	forn(i,0,n){
		num[i] = -1;
		low[i] = 0;
		p[i] = -1;
		articulationVertex[i] = 0;
	}
	while(m--){
		int x,y; cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	forn(i,0,n)
		if(num[i] == -1){
			root = i; rootChildren = 0;
			dfs(i);
			articulationVertex[i] = (rootChildren > 1);
		}
	cout << "Articulation points\n";
	forn(i,0,n)if(articulationVertex[i]) cout << i << "\n";
}
