//https://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
//https://www.geeksforgeeks.org/space-and-time-efficient-binomial-coefficient/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
const int mod = 1e9+7;


typedef long long ll;

ll gcdE(ll a,ll b,ll *x, ll *y){
	if(a == 0){
		*x = 0, *y = 1;
		return b;
	}
	ll x1,y1;
	ll gcd = gcdE(b%a,a,&x1,&y1);
	*x = y1-(b/a)*x1;
	*y = x1;
	return gcd;
}
ll modInverse(ll b,ll m){
	ll x,y;
	ll g = gcdE(b,m,&x,&y);
	if(g != 1) return -1;
	return (x%mod+mod)%mod;
}
ll modDivide(ll a,ll b){
	a = a%mod;
	ll inv = modInverse(b,mod);
	if(inv == -1) return -1;
	return (inv*a)%mod;
}
ll binomialCoeff(int n,int k){
	ll res = 1;
	if(k > n-k) k = n-k;
	for(int i = 0; i < k; i++){
		// da overflow cambiar a mul(a,b)
		res = (res%mod*(n-i)%mod)%mod;
		res = modDivide(res,i+1);
	}
	return res;
}
int n,k;

int main(){
	cin >> n >> k;
	ll res = binomialCoeff(n,k);
	cout << res << "\n";
}

