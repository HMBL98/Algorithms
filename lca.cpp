#include <bits/stdc++.h>
using namespace std;


const int maxn = 1e5+10;
const int logn = 30;

typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> graph;

int dist[maxn],depth[maxn],parent[logn][maxn],weigth[logn][maxn],N,M,Q;

void dfs(int u,int p){
	for(auto &v : graph[u]){
		if(p != v.first){
			parent[0][v.first] = u;
			weigth[0][v.first] = v.second;
			depth[v.first] = depth[u]+1;
			dist[v.first] = dist[u]+v.second;
			dfs(v.first,u);
		}
	}
}
void pre(){
	// Checar que solo es una cmponente
	dfs(0,-1);
	for(int i = 1; i < logn; i++){
		for(int j = 0; j < N; j++){
			parent[i][j] = parent[i-1][parent[i-1][j]];
			weigth[i][j] = max(weigth[i-1][j],weigth[i-1][parent[i-1][j]]);
		}
	}
}
int getParent(int u,int k,int &maxi){
	for(int i = 0; i < logn; i++){
		if(k&1){
			maxi = max(maxi,weigth[i][u]);
			u = parent[i][u];
		}
		k >>= 1;
	}
	return u;
}
int lca(int u,int v){
	int maxi = 0;
	if(depth[v] > depth[u])swap(u,v);
	u = getParent(u,depth[u]-depth[v],maxi);
	if(u == v)return u;
	//if(u == v)return maxi;
	for(int i = logn-1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			maxi = max(maxi,max(weigth[i][u],weigth[i][v]));
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
	//maxi = max(max(weigth[0][u],maxi),weigth[0][v]);
	//return maxi;
}
int main(){
	cin >> N;
	graph.assign(N,vii());
	for(int i = 0; i < N-1; i++){
		int x,y,c; cin >> x >> y >> c;
		x--; y--;
		graph[x].push_back({y,c});
		graph[y].push_back({x,c});
	}
	pre();
	cin >> Q;
	while(Q--){
		int u,v;
		cin >> u >> v;
	    u--; v--;
		cout << lca(u,v)+1 << "\n";
	}
}

