#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)
const int maxn = 1e5+10;
int tree[4*maxn],lazy[4*maxn],A[maxn],N,Q;

void build(int node, int start, int end){
	if(start == end){
		tree[node] = A[start];
    }else{
		int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
void update(int node, int start, int end, int l, int r, int val){
	if(lazy[node] != 0){
		tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
			lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end || start > r || end < l)return;
    if(start >= l && end <= r){
		tree[node] += (end - start + 1) * val;
        if(start != end){
			lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
   	update(node*2, start, mid, l, r, val);
    update(node*2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int query(int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l)return 0;
	if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
			lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l && end <= r)return tree[node];
    int mid = (start + end) / 2;
    int p1 = query(node*2, start, mid, l, r);
    int p2 = query(node*2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}
int main(){
	cin >> N >> Q;
	//index start with 1
	forn(i,1,N+1)cin >> A[i];
	build(1,1,N);
	while(Q--){
		char opc; cin >> opc;
		int x,y,c;
		if(opc == 'q'){
			cin >> x >> y;
			cout << query(1,1,N,x,y) << "\n";
		}else{
			cin >> x >> y >> c;
			update(1,1,N,x,y,c);
		}
	}
}

