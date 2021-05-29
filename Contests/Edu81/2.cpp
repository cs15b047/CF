#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; scanf("%lld",&t);
	for(int q =0;q < t;q++){
		ll n, x; scanf("%lld%lld",&n, &x);
		string str; cin >> str;
		map<ll, ll> prefix_sum_cnts;
		ll pref_sum = 0;

		for(auto ch: str){
			if(ch == '0'){
				pref_sum++;
			} else pref_sum--;
			prefix_sum_cnts[pref_sum]++;
		}

		ll total = pref_sum;
		ll answer = 0;
		if(total == 0){
			if(prefix_sum_cnts.find(x) != prefix_sum_cnts.end()){
				cout << -1 << endl;
			}
		} else{
			if(total < 0){
				if(x > 0){
					for(auto it: prefix_sum_cnts){
						if((it.first == x) || ((it.first > x) && (it.first % (-total) == x % (-total)))){
							answer += it.second;
						}
					}
				} else if(x < 0){
					// negative ka mod??
					ll rhs = ((x - total) % (-total));rhs = (rhs + (-total)) % (-total);
					for(auto it: prefix_sum_cnts){
						ll lhs = (it.first % (-total));lhs = (lhs + (-total)) % (-total);
						if((it.first == x) || ((it.first > x) && (lhs == rhs ) ) ){
							answer += it.second;
						}
					}
				} else{
					for(auto it: prefix_sum_cnts){
						if((it.first == x) || ((it.first > x) && (llabs(it.first) % (-total) == 0) ) ){
							answer += it.second;
						}
					}
					answer++;
				}
			} else{
				if(x > 0){
					for(auto it: prefix_sum_cnts){
						if((it.first == x) || ((it.first < x) && (it.first % (total) == (x % total)))){
							answer += it.second;
							// cout << it.first << " " <<answer << endl;
						}
					}
				} else if(x < 0){
					// negative ka mod??
					ll rhs = x % total;rhs = (rhs + total) % total;
					for(auto it: prefix_sum_cnts){
						ll lhs = (it.first % total);lhs = (lhs + (total)) % (total);
						if((it.first == x) || ((it.first < x) && (lhs == rhs))){
							answer += it.second;
						}
					}
				} else{
					for(auto it: prefix_sum_cnts){
						if((it.first == x) || ((it.first < x) && (llabs(it.first) % (total) == 0) ) ){
							answer += it.second;
						}
					}
					answer++;
				}
			}
			printf("%lld\n",answer);
		}
	}
}