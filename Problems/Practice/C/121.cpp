//C. Number of Ways -- #266 -2
// prefix sum[i] = suffix sum[j] = total /3 ,i < j
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n;
	vector<ll> a(n+1);for(int i=1;i<=n;i++)cin >> a[i];
	vector<ll>prefix(n+1),suffix(n+1);
	prefix[1] = a[1]; suffix[n] = a[n];
	for(int i=2;i<=n;i++){
		prefix[i] = prefix[i-1] + a[i];
		suffix[n + 1 - i] = suffix[n + 2 - i] + a[n + 1 -i];
	}
	if(prefix[n] % 3 != 0)cout << 0 << endl;
	else{
		ll tot = prefix[n] / 3;
		vector<ll>prefix_index,suffix_index;
		for(int i=1;i<=n;i++){
			if(prefix[i] == tot){
				prefix_index.push_back(i);
			}
			if(suffix[i] == tot){
				suffix_index.push_back(i);
				// cout << i << " uo" << endl;
			}
		}
		// for(auto it:suffix)cout << it << " ";cout << endl;
		// for(auto it:suffix_index)cout << it << " ";cout << endl;
		ll p_s = prefix_index.size();
		// cout << p_s << endl ;
		ll answer = 0;
		for(int i=0;i<p_s;i++){
			ll i1 = prefix_index[i];
			if(i1 <= n -2){
				ll i2 = upper_bound(suffix_index.begin(), suffix_index.end(), i1) - suffix_index.begin();			
				// cout << i1 << " " << suffix_index[i2] << endl ;
				if(i1 < suffix_index[i2] - 1){
					answer += (suffix_index.size() - i2) ;
				}
				else{
					i2++;
					answer += (suffix_index.size() - i2) ;
				}
			}
		}
		cout << answer << endl ;
	}
}