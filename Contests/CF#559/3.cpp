#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, m; cin >> n >> m;
	vector<ll> b(n), g(m);for(int i=0;i<n;i++)cin >> b[i];for(int i=0;i<m;i++)cin >> g[i];
	sort(b.begin(), b.end(), greater<ll>());sort(g.begin(), g.end(), greater<ll>());

	ll p1 = 0, p2 = 0;
	if(b[0] <= g[m - 1]){
		if((n == 1 && g[m - 1] > b[0]) || (m == 1 && g[m - 1] > b[0])){
			cout << -1 << endl;
		}
		else{
			ll answer = 0;
			ll sm1 = 0,sm2 = 0;for(int i=0;i<m;i++)sm2 += g[i];
			for(int i=0;i<n;i++)sm1 += b[i];
			if(b[0] == g[m - 1]){
				answer = sm2 + (sm1 - b[0]) * m ;
			}
			else{
				answer = (sm2 - g[0] + b[0]) + g[0] + (sm1 - b[0]) * m - b[1] ;
			}
			cout << answer << endl;
		}
	}
	else cout << -1 << endl;

}