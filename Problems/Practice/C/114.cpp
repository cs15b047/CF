// C. Hard Process -- Edu round 11
// Calculate length possible from particular locn i, by keeping prefix count of zeros and mapping prefix_cnt -->max index (for cts ones)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, k; cin >> n >> k ;
	vector<ll>a(n),prefix(n);for(int i=0;i<n;i++)cin >> a[i] ;
	prefix[0] = (a[0] == 0);
	for(int i=1;i<n;i++)prefix[i] = prefix[i-1] + (a[i] == 0);
	map<ll,ll> prefix_sum_to_index;
	for(int i=0;i<n;i++)prefix_sum_to_index[prefix[i]] = i;
	if(k != 0){		
		ll answer = 0, ans_s, ans_e;
		for(ll start=0;start<n;start++){
			ll end;
			if(start == 0){
				if(prefix_sum_to_index.find(k) == prefix_sum_to_index.end())end = n - 1;
				else end = prefix_sum_to_index[k] ;
			}
			else{
				if(prefix_sum_to_index.find(prefix[start - 1] + k) == prefix_sum_to_index.end())end = n - 1;
				else
					end = prefix_sum_to_index[prefix[start - 1] + k] ;
			}
			if(answer < (end - start + 1)){
				ans_s = start; ans_e = end;
				answer = end - start + 1;
			}
		}
		cout << answer << endl ;
		for(int i=0;i<n;i++){
			if(i >= ans_s && i <= ans_e)cout << 1 << " ";
			else cout << a[i] << " ";
		}
		cout << endl ;
	}
	else{
		int start = 0;
		ll answer = 0;
		while(start < n){
			if(a[start] == 1){
				int itr = start ;
				while(itr < n && a[itr] == 1)itr++;
				answer = max(answer, (ll)(itr - start));
				start = itr;
			}
			else start++;
		}
		cout << answer << endl;
		for(auto it:a)cout << it << " ";
		cout << endl;
	}
}