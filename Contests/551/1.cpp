#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n,t;cin >> n >> t;
	vector<ll> Time(n + 1),s(n + 1),d(n + 1), ans(n + 1);
	for(int i=1;i<=n;i++)cin >> s[i] >> d[i];
	for(int i=1;i<=n;i++){
		ll num = s[i];
		while(num < t)num += d[i];
		ans[i] = num;
	}
	ll arg = 1, answer = ans[1];
	for(int i=2;i<=n;i++){
		if(ans[i] < answer){arg = i;answer = ans[i];}
	}
	cout << arg << endl;
}