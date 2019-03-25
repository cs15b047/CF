#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n, k; cin >> n >> k;
	vector<ll> a(n);for(int i=0;i<n;i++)cin >> a[i];
	vector<ll> sol_id(k, 1e18), test_num(k, -1), remn_time(k, -1);
	if(0){}
	else{
		for(int i=0;i<min(k,n);i++){
			sol_id[i] = i;
			test_num[i] = 1;
			remn_time[i] = a[i];
		}
		ll processed = 0, curr = k;
		ll answer = 0;
		ll tim = 0;
		map<ll,ll> interesting;
		interesting.clear();

		while(processed < n){
			
			ll mnm = 1e18,arg_mnm = -1;
			for(int i=0;i<k;i++){
				if(sol_id[i] != 1e18){
					if(remn_time[i] < mnm){
						mnm = remn_time[i]; arg_mnm = i;
					}
				}
			}
			// cout << mnm << " " << arg_mnm << endl;

			float percent = 100.0*(float)processed/(float)n + 0.5;
			ll proc = (ll)percent;
			
			// cout << proc << endl;
			// for(int i=0;i<k;i++)cout << sol_id[i] << " " << test_num[i] << " "<<remn_time[i] << endl;

			for(int i=0;i<k;i++){
				if(sol_id[i] != 1e18 && proc >= test_num[i] && mnm > proc - test_num[i]){
					interesting[sol_id[i]] = 1;
				}
			}

			for(int i=0;i<k;i++){
				if(remn_time[i] == mnm && curr < n){
					processed++;
					sol_id[i] = curr;
					test_num[i] = 1;
					remn_time[i] = a[curr];
					curr++;
				}
				else if(remn_time[i] == mnm && curr >= n){
					processed++;
					sol_id[i] = 1e18;
				}
				else{
					remn_time[i] -= mnm;
					test_num[i] += mnm;
				}
			}
			tim += mnm;
		}
		cout << interesting.size() << endl;
	}
}