#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int i = 0; i < t; i++){
		string pass, hash; cin >> pass >> hash;
		ll sz = pass.size(), sz_h = hash.size();
		vector<ll> cnts(26, 0);
		for(int j = 0;j < sz;j++){
			cnts[pass[j] - 'a']++;
		}
		vector<ll> sliding_cnt(26, 0);
		bool match = false;
		for(int j = 0; j < sz_h - sz + 1; j++){
			if(j == 0){
				for(int k = 0; k < sz;k++){
					sliding_cnt[hash[k] - 'a']++;
				}
			} else {
				sliding_cnt[hash[j - 1] - 'a']--;
				sliding_cnt[hash[j + sz - 1] - 'a']++;
			}
			bool equal = true;
			for(int k = 0; k < 26;k++){
				if(sliding_cnt[k] != cnts[k]){
					equal = false;
					break;
				}
			}
			if(equal){
				match = true;
				break;
			}
		}
		if(match){
			cout << "YES" << endl;
		} else{
			cout << "NO" << endl;
		}
	}
}