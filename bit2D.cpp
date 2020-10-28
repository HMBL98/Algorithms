#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int bit[maxn][maxn],N,M,Q;

int query(int idx,int idy){
	int sum = 0;
	while(idx > 0){
		while(idy > 0){
			sum += bit[idx][idy];
			idy -= idy&-idy;
		}
		idx -= idx&-idx;
	}
	return sum;
}
int update(int idx,int idy,int val){
	while(idx <= N){
		while(idy <= M){
			bit[idx][idy] += val;
			idy += idy&-idy;
		}
		idx += idx&-idx;
	}
}
int sum(int x1,int y1,int x2,int y2){
	return query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
}
int main(){
	cin >> N >> M >> Q;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			int tmp; cin >> tmp;
			int v1 = query(i,j);
			int v2 = query(i,j-1);
			int v3 = query(i-1,j-1);
			int v4 = query(i-1,j);
			update(i,j,tmp-(v1-v2-v4+v3));
		}
	}
	while(Q--){
		int opc; cin >> opc;
		if(opc == 1){
			int x1,y1,x2,y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x1,y1,x2,y2) << "\n";
		}else{
			int x1,y1,val; cin >> x1 >> y1 >> val;
			update(x1,y1,-sum(x1,y1,x1,y1));
			update(x1,y1,val);
		}
	}
}

