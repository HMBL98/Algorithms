#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,b) for(int i = a; i < b; i++)

const int maxn = 1e5+10;
int tree[4*maxn],A[maxn],N,Q;

void build(int node, int start, int end){
	if(start == end){
		// Leaf node will have a single element
        tree[node] = A[start];
    }else{
		int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
void update(int node, int start, int end, int idx, int val){
	if(start > idx || end < idx)return;
	if(start == idx && end == idx){
		// Leaf node
        A[idx] = val;
        tree[node] = val;
		return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, idx, val);
    update(2*node+1, mid+1, end, idx, val);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
int query(int node, int start, int end, int l, int r){
	if(r < start or end < l){
		// range represented by a node is completely outside the given range
        return 1<<20;
    }
    if(l <= start and end <= r){
		// range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
	return min(p1,p2);
}
int main(){
	cin >> N >> Q;
	forn(i,1,N+1)cin >> A[i];
	build(1,1,N);
	while(Q--){
		char opc;int x,y; cin >> opc;
		if(opc == 'q'){
			cin >> x >> y;
			cout << query(1,1,N,x,y) << "\n";
		}else{
			cin >> x >> y;
			update(1,1,N,x,y);
		}
	}
}

