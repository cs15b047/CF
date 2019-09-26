#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, k; cin >> n >> k;
	vector<ll> arr(n);for(int i=0;i<n;i++)cin >> arr[i];
	sort(arr.begin(), arr.end());
	map<ll,ll> cnt;for(int i=(n - 1)/2;i<n;i++)cnt[arr[i]]++;

	ll remn = k;
	ll ans = 0;
	while(true){
		if(cnt.size() == 1){
			ans = cnt.begin()->first + (remn / ((n + 1)/2));
			break;
		} else{
			auto it = cnt.begin(), it2 = it;it2++;
			if(remn < (it2->first - it->first)*it->second){
				ans = it->first + remn / it->second;
				break;
			} else{
				remn = remn - (it2->first - it->first)*it->second ;
				it2->second += it->second;
				cnt.erase(it);
			}
		}
	}
	cout << ans << endl;

}