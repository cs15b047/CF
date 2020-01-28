#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	ll t; cin >> t;
	for(int w = 1;w <= t;w++){
		ll n, q; cin >> n >> q;	
		string str; cin >> str;
		ll answer = 0;
		vector<vector<ll>> prefix_letter_counts(n + 1, vector<ll>(26, 0));
		for(int i = 0;i < n;i++){
			prefix_letter_counts[i + 1] = prefix_letter_counts[i];
			prefix_letter_counts[i + 1][str[i] - 'A']++;
		}
		for(int j = 1;j <= q; j++){
			ll left, right; cin >> left >> right;
			vector<ll> counts(26, 0);
			for(int i = 0;i < 26;i++){
				counts[i] = prefix_letter_counts[right][i] - prefix_letter_counts[left - 1][i];
			}
			// all even if length even. exactly 1 odd if length odd
			int num_odds = 0;
			for(int i = 0;i < 26;i++){
				if(counts[i] % 2 == 1)num_odds++;
			}
			if((right - left + 1) % 2 == 0 && num_odds == 0)answer++;
			else if((right - left + 1) % 2 == 1 && num_odds == 1)answer++;
		}
		cout << "Case #" << w << ": " << answer << endl;
	}
} 
