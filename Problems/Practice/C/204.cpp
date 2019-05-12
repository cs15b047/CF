#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
ll mod = 1e9 + 7;

ll pwr(ll base, ll idx){
	if(idx == 0)return 1;
	else{
		ll tmp = pwr(base, idx/2);
		if(idx % 2 == 1)return (((tmp * tmp) % mod) * base) % mod;
		return (tmp * tmp) % mod;
	}
	return 1;
}

int main(){
	ll n, m, k;cin >> n >> m >> k;

	vector<ll> starts(n + 1), ends(n + 1);
	for(ll i = 1;i <= n;i++){
		starts[i] = max((ll)1, i - (n - k));
		ends[i] = min(i, k);
	}
	// for(int i=1;i<=n;i++)cout << i << " " << starts[i] << " " << ends[i] << endl;
	vector<ll> visited(n + 1, 0);
	ll ans = 1;
	for(int i=1;i<=n;){
		while(i <= n && visited[i] == 1)i++;
		if(i <= n){
			ll comp_sz = 0;visited[i] = 1;
			queue<ll> q;q.push(i);

			while(!q.empty()){
				ll top = q.front();q.pop();comp_sz++;
				// cout << top << " ";
				for(int j = starts[top];j <= ends[top];j++){
					if(!visited[top + (k - 2*j + 1)]){
						ll idx = top + (k - 2*j + 1);
						visited[idx] = 1;
						q.push(idx);
						// cout << idx << " ";
					}
				}
			}
			// cout << endl;
			ans = (ans * m) % mod;
			// cout << ans << endl;
		}
	}
	cout << ans << endl;
}