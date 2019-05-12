#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll> val;
int main(){
	ll t; cin >> t;
	for(int w = 0; w<t; w++){
		ll n,q; cin >> n >> q;
		val.clear();val.resize(n);for(int i=0;i<n;i++)cin >> val[i];
		vector<ll> old_val;old_val = val;
		sort(val.begin(),val.end());
		// for(auto it:val)cout << it << " "; cout << endl;
		for(int i = 0;i < q;i++){
			ll src, dest; cin >> src >> dest ;src--;dest--;

			// cout << src << " " << dest << endl;
			// for(auto it:old_val)cout << it << " "; cout <<endl;
			ll dist = llabs(old_val[dest] - old_val[src]) + dest - src;
			ll idx1,idx2 ;
			if(src == dest){
				idx1 = 0;idx2 = 0;
			}
			else if(old_val[src] <= old_val[dest]){
				idx1 = lower_bound(val.begin(), val.end(), old_val[src]) - val.begin();
				idx2 = upper_bound(val.begin(), val.end(), old_val[dest]) - val.begin() - 1;
			}
			else if(old_val[src] > old_val[dest]){
				idx1 = upper_bound(val.begin(), val.end(), old_val[src]) - val.begin() - 1;
				idx2 = lower_bound(val.begin(), val.end(), old_val[dest]) - val.begin();
			}
			ll pth_len = llabs(idx2 - idx1) + 1;
			// if(src == dest)pth_len++;
			// cout << idx1  << " " << idx2 << endl;
			cout << dist << " " << pth_len << endl;
		}
	}
}