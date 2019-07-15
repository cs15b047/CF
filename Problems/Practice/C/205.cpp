// B. Cards Sorting  CF# 424 - 1
// 1 Round through deck : All cards of minm val are removed for sure. Some of 2nd minm can also get removed, but if all of 2nd minm get removed, start removing 3rd minm and so on....
// Simulate this faster by keeping all positions for a given value and count iterations
// Also count total removed till previous iteration to count total present in every iteration
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; scanf("%lld",&n);
	vector<ll> a(n);for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	map<ll, vector<ll>> indices;for(int i=0;i<n;i++)indices[a[i]].push_back(i);
	vector<ll> done_indices;
	ll seen = 0;

	while(done_indices.size() < n){
		ll sz = (ll)done_indices.size();
		ll last = -1;
		bool done = false;

		while(!done && !indices.empty()){
			auto it = indices.begin();
			ll tmp_last = *(it->second.rbegin());
			// cout << tmp_last << endl;
			// for(auto it2:it->second)cout << it2 << " ";cout << endl;

			vector<ll> tmp_ind;tmp_ind.clear();
			for(auto it2 = upper_bound(it->second.begin(), it->second.end(), last);it2 != it->second.end();it2++)tmp_ind.push_back(*it2);
			// cout << tmp_ind.size() << endl;
			for(int i=0;i<tmp_ind.size();i++)it->second.pop_back();
			// cout << "yo"<< endl;

			last = max(last, tmp_last);
			done = !it->second.empty();
			if(it->second.empty())indices.erase(it->first);
			for(auto it2:tmp_ind)done_indices.push_back(it2);
		}
		seen += (n - sz) ;
	}
	printf("%lld\n",seen );
}