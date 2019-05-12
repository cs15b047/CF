#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,m,r;cin >> n >> m >> r;
	vector<ll> buy(n);for(int i=0;i<n;i++)cin >> buy[i];vector<ll> sell(m);for(int i=0;i<m;i++)cin >> sell[i];
	ll cp = buy[0], sp = sell[0];for(int i=0;i<n;i++)cp = min(cp, buy[i]);for(int i=0;i<m;i++)sp = max(sp, sell[i]);
	ll answer = (r / cp) * max(sp - cp, (ll)0) + r;
	cout << answer << endl;
}