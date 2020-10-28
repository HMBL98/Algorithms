#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

typedef long long ll;
typedef vector<int> vi;
int values[maxn],seen[maxn],low[maxn],num[maxn],n,m,counter;
vi graph[maxn],s;

void dfs(int u){
	seen[u] = 1;
	low[u] = num[u] = ++counter;
	s.push_back(u);
	for(int i = 0; i < (int)graph[u].size(); i++){
		int v = graph[u][i];
		if(!num[v]) dfs(v);
		if(seen[v]) low[u] = min(low[u],low[v]);
	}
	if(low[u] == num[u]){
		while(1){
			int v = s.back(); s.pop_back(); seen[v] = 0;
			cout << v << " ";
			if(u == v)break;
		}
		cout << "\n";
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		graph[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
		if(!num[i]) dfs(i);
	}
}
