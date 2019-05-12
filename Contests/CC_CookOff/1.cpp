#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll t; cin >> t;
	for(int q =0;q<t;q++){
		ll n; cin >> n;
		vector<string> str(n);for(int i=0;i<n;i++)cin >> str[i] ;
		vector<ll> counts(26, 0);
		for(int i=0;i<n;i++){
			for(int j = 0;j < str[i].length();j++)counts[str[i][j]-'a']++;
		}
		ll ans1,ans2,ans3;
		ans1 = min(counts[4]/2, counts[2]/2);ans2 = min(counts[3], counts[5]);ans3 = min(counts[7], counts[14]);
		// cout << ans1 << " " << ans2 << " " << ans3 << endl;
		ll answ = min(ans1, ans2);answ = min(answ, ans3);
		cout << answ << endl;
	}
}