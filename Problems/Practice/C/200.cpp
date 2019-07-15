// D. One-Dimensional Battle Ships  CF# Pi - 2
// Calculate and update number of ships that can be present based on number and length of cts segments present
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,k,a,m;cin >> n >> k >> a >> m;
	vector<ll> shots(m);for(int i=0;i<m;i++)cin >> shots[i];
	set<ll> openings, closings;
	openings.insert(1);closings.insert(n);
	ll possible = (n + 1) /(a+1) ;
	int flag = 0;
	for(int i=0;i<m;i++){
		ll pos = shots[i];
		openings.insert(pos + 1);closings.insert(pos - 1);
		auto it1 = openings.find(pos + 1);it1--;auto it2 = closings.find(pos - 1);it2++;
		ll p1 = *it1, p2 = *it2;
		ll earlier = (p2 - p1 + 2) /(a + 1);
		ll later = (pos - p1 + 1) / (a + 1) + (p2 - pos + 1) / (a + 1) ;
		possible = possible - (earlier - later);
		if(possible < k){flag =1;cout << i + 1 << endl;break;}
	}
	if(flag == 0)cout << -1 << endl;
}