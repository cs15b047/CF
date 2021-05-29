#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll tests; cin >> tests;
	for(int t = 0;t < tests;t++){
		ll n; cin >> n;
		vector<ll> a(n), b(n);
		for(int i =0;i<n;i++)cin>> a[i];
		for(int i =0;i<n;i++)cin>> b[i];

		bool poss = true;
		vector<bool> pos(n), neg(n);
		pos[0] = (a[0] > 0);
		neg[0] = (a[0] < 0);
		for(int i = 1;i < n;i++){
			pos[i] = pos[i - 1] || (a[i] > 0);
			neg[i] = neg[i - 1] || (a[i] < 0);
		}
		for(int i = n - 1;i > 0;i--){
			if(a[i] != b[i]){
				if(b[i] - a[i] > 0 && pos[i - 1] == 0){
					poss = false;
					break;
				}
				else if(b[i] - a[i] < 0 && neg[i - 1] == 0){
					poss = false;
					break;
				}
			} else{
				continue;
			}
		}
		poss = (poss && (a[0] == b[0]));

		if(poss){
			cout <<"YES" << endl;
		} else cout << "NO" << endl;
	}

}