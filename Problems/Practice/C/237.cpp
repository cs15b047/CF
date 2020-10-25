#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll tests; cin >> tests;
	for(ll t = 0;t < tests;t++){
		ll seq_len; cin >> seq_len;seq_len--;
		string comparison_str; cin >> comparison_str;
		
		vector<ll> answer1(seq_len + 1, -1), answer2(seq_len + 1, -1);
		vector<ll> remn1;
		vector<pair<ll,ll>> incr_seq_locns;
		for(ll i = 1;i <= seq_len + 1; i++)remn1.push_back(i);
		
		// get increasing locations
		for(int i = 0;i < seq_len;){
			if(comparison_str[i] == '<'){
				ll strt = i;
				while(i < seq_len && comparison_str[i] == '<')i++;
				incr_seq_locns.push_back(make_pair(strt, i));
			} else i++;
		}
		// take last position into account if < present at end
		if(!incr_seq_locns.empty() && incr_seq_locns.back().second == seq_len)
			incr_seq_locns.back() = make_pair(incr_seq_locns.back().first, incr_seq_locns.back().second + 1);
		/////////////////////////////

		// 2 pointers assign values: for > --> from greatest---> smallest, for < --> max ans: in increasing order from smallest
		ll ptr11 = 0, ptr12, ptr2 = seq_len;
		for(int i = 0;i < seq_len; i++){
			if(comparison_str[i] == '>'){
				ll high = remn1[ptr2];
				answer1[i] = high;
				answer2[i] = high;
				ptr2--;
			}
			else if(comparison_str[i] == '<'){
				ll low = remn1[ptr11];
				answer1[i] = low;
				ptr11++;
			}
		}

		// last ele in case 1
		answer1.back() = remn1[ptr2];
		// take care of last position
		if(comparison_str.back() == '>')answer2.back() = remn1[0];

		// Assign ele for < in min len LIS.
		ptr12 = ptr2;
		for(int i = 0;i < (ll)(incr_seq_locns.size()); i++){
			for(int j = incr_seq_locns[i].second - 1;j >= incr_seq_locns[i].first;j--){
				answer2[j] = remn1[ptr12];
				ptr12--;
			}
		}
		for(auto it: answer2)cout << it << " "; cout << endl;
		for(auto it: answer1)cout << it << " "; cout << endl;
	}
}