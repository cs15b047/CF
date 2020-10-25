#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll num_people, money;
vector<pair<ll,ll>> ranges;

bool cmp(int idx1, int idx2){
	return ranges[idx1].first < ranges[idx2].first;
}

int check(ll answer){
	vector<ll> lower_idxs, higher_idxs;
	lower_idxs.clear();higher_idxs.clear();

	for(int i = 0;i < num_people;i++){
		if(ranges[i].first <= answer)lower_idxs.push_back(i);
		if(ranges[i].second >= answer)higher_idxs.push_back(i);
	}
	if(lower_idxs.size() < (num_people + 1)/2){
		return 1;
	}
	if(higher_idxs.size() < (num_people + 1)/2){
		return -1;
	}
	sort(lower_idxs.begin(), lower_idxs.end(), cmp);

	ll total = 0;
	for(int i = 0;i < (num_people - 1)/2; i++){
		total += ranges[lower_idxs[i]].first;
	}
	total += (num_people + 1)/2 * answer;
	if(total > money)return -1;

	return 0;
}

int main(){
	ll tests; cin >> tests;
	for(ll t = 0;t < tests;t++){
		cin >> num_people >> money;
		ranges.resize(num_people);

		ll mnm = 1e9, mxm = 0, mid;
		for(int i = 0;i < num_people;++i){
			cin >> ranges[i].first >> ranges[i].second;
			mxm = max(mxm, ranges[i].second);
			mnm = min(mnm, ranges[i].first);
		}

		if(num_people == 1){
			cout << min(money, ranges[0].second) << endl;
		}else{
			while(mnm < mxm){
				mid = (mnm + mxm) / 2;
				// cout << mid << endl;
				int possible = check(mid);
				if(possible == -1){
					mxm = mid - 1;
				} else if(possible == 1){
					mnm = mid + 1;
				} else{
					mnm = mid;
					if((mnm + mxm)/2 == mid)break;
				}
			}
			cout << mnm << endl;
		}

	}
}