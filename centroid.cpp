#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mod ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 1e5+10;
int dead[maxn],sz[maxn],n,nn;
vi graph[maxn],tree[maxn];

void dfs1(int u,int p){
	sz[u] = 1;
	nn++;
	for(auto &v : graph[u])
		if(v != p && !dead[v]){
			dfs1(v,u);
			sz[u] += sz[v];
		}
}
int dfs2(int u,int p){
	for(auto &v : graph[u]){
		if(v != p && !dead[v] && sz[v] > nn/2)return dfs2(v,u);
	}
	return u;
}
int decompose(int root){
	nn = 0;
	dfs1(root,root);
	int c = dfs2(root,root);
	//cout << c+1 << "\n";
	dead[c] = 1;
	for(auto &v : graph[c])if(!dead[v]){
		int cs = decompose(v);
		//tree[c].pb(cs);
		//tree[cs].pb(c);
		cout << c+1 << " " << cs+1 << "\n";
	}
	dead[c] = 0;
	return c;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> n;
        forn(i,0,n-1){
                int u,v; cin >> u >> v;
                u--; v--;
                graph[u].pb(v);
                graph[v].pb(u);
        }
        decompose(0);
        return 0;
}
