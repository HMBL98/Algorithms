#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int bit[maxn],bit2[maxn],values[maxn],N,Q;

/*Point updates and range queries
int query(int idx){
	int sum = 0;
	while(idx > 0){
		sum += bit[idx];
		idx -= idx&-idx;
	}
	return sum;
}
int update(int idx,int val){
	while(idx <= N){
		bit[idx] += val;
		idx += idx&-idx;
	}
}
int sum(int idx,int idy){
	return query(idy)-query(idx-1);
}*/

/*Range updates and point queries
//Return A[b]
int query(int idx){
	int sum = 0;
	while(idx > 0){
		sum += bit[idx];
		idx -= idx&-idx;
	}
	return sum+values[idx];
}
//Add v to A[p]
int update(int idx,int val){
	while(idx <= N){
		bit[idx] += val;
		idx += idx&-idx;
	}
}
//Add v to A[idx...idy] 
int update(int idx,int idy,int val){
	update(idx,val);
	update(idy+1,-val);
}*/

//Range updates and Range queries
int query(int opc,int idx){
        int sum = 0;
        while(idx > 0){
		if(opc) sum += bit[idx];
		else sum += bit2[idx];
                idx -= idx&-idx;
        }
        return sum;
}
//Return sum A[1....idx]
int query(int idx){
	return query(1,idx)*idx-query(0,idx);
}
//Return sum A[idx....idy] 
int sum(int idx,int idy){
	return query(idy)-query(idx-1);
}
int _update(int opc,int idx,int val){
        //tener cuidado con N+1
        while(idx < N+1){
		if(opc) bit[idx] += val;
		else bit2[idx] += val;
                idx += idx&-idx;
        }
}
//Add v to A[a...b] 
int update(int idx,int idy,int val){
	_update(1,idx,val);
	_update(1,idy+1,-val);
	_update(0,idx,val*(idx-1));
	_update(0,idy+1,-val*idy);
}
int main(){
	cin >> N >> Q;
	for(int i = 1; i <= N; i++){
		cin >> values[i];
		update(i,i,values[i]);
	}
	while(Q--){
		int opc; cin >> opc;
		if(opc == 1){
			int l,r;
			cin >> l >> r;
			cout << sum(l,r) << "\n";
			//cout << query(r)-query(l-1) << "\n";
			//cout << query(l)<< "\n";
		}else{
			int idx,idy,val; cin >> idx >> idy >> val;
			update(idx,idy,val);
			//updateR(idx,idy,val);
			/*update(idx,-(query(idx)-query(idx-1)));
			update(idx,val);*/
		}
	}
}
