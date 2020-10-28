#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define forn(i,a,b) for(int i = a; i < b; i++)
#define forr(i,a,b) for(int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int maxn = 1e5+10;
const int mod = 1e9+7;

ll fac[maxn],caf[maxn]; 

ll deg(ll x,ll d){
	d %= mod - 1;
    if(d < 0)d += mod - 1;
    ll y = 1;
    while(d){
		if (d & 1) y *= x, y %= mod;
        x *= x, x %= mod;
        d /= 2;
    }
    return y;
}
ll coeff(int n,int k){
	return fac[n] * caf[k] % mod * caf[n - k] % mod;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	fac[0] = caf[0] = 1;
	forn(i,1,maxn)fac[i] = i * fac[i - 1] % mod, caf[i] = deg(fac[i], -1);
	int n,k; cin >> n >> k;
	cout << coeff(n,k) << "\n";
}
