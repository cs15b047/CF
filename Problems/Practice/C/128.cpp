#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll>a(n),ptr(n),dp(n);
	for(int i=0;i<n;i++)cin >> a[i];

	map<ll,vector<ll>> ele_locns;
	for(int i=0;i<n;i++)ele_locns[a[i]].push_back(i);

	dp[0] = 1;ptr[0] = -1;
	for(int i=1;i<n;i++){
		if(ele_locns.find(a[i] -1) == ele_locns.end()){
			dp[i] = 1;ptr[i] = -1;
		}
		else{
			ll index = upper_bound(ele_locns[a[i] -1].begin(), ele_locns[a[i] -1].end(), i) - ele_locns[a[i] -1].begin();
			index--;
			if(index >= 0){
				ll ind = ele_locns[a[i] -1][index];
				dp[i] = dp[ind] + 1;
				ptr[i] = ind ;
			}
			else{
				dp[i] = 1;
				ptr[i] = -1;	
			}
		}
	}



	ll ans=0, ans_ind;
	for(int i=0;i<n;i++){
		if(ans < dp[i]){
			ans_ind = i;
			ans = dp[i];
		}
	}
	cout << ans << endl;
	vector<ll>ind_seq;
	ll ind = ans_ind;
	while(ind != -1){
		ind_seq.push_back(ind);
		ind = ptr[ind];
	}
	reverse(ind_seq.begin(),ind_seq.end());
	for(auto it:ind_seq)cout << (it + 1) << " "; cout << endl ;
}