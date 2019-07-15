#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;
	vector<ll> arr(n);for(int i=0;i<n;i++)cin >> arr[i];
	sort(arr.begin(),arr.end());
	
	vector<ll> pos, neg;pos.clear();neg.clear();
	ll zeros = 0;
	for(int i=0;i<n;i++){
		if(arr[i] < 0)neg.push_back(-arr[i]);
		else if(arr[i] > 0)pos.push_back(arr[i]);
		else zeros++;
	}
	reverse(neg.begin(), neg.end());
	ll answer = 0;
	// cout << answer << endl;
	if(!pos.empty()){
		for(int i=0;i<pos.size();i++){
			ll idx = upper_bound(pos.begin(), pos.end(), 2*pos[i]) - pos.begin();idx--;
			if(idx > i)answer += idx - i;
		}
	}

	// cout << answer << endl;
	// for(int i=0;i<neg.size();i++)cout<< neg[i] << " ";cout<< endl;
	if(!neg.empty()){
		for(int i=0;i<neg.size();i++){
			ll idx = upper_bound(neg.begin(), neg.end(), 2*neg[i]) - neg.begin();idx--;
			// cout << idx << endl;
			if(idx > i)answer += idx - i;
		}
	}
	// cout << answer << endl;
	for(int i=0;i<neg.size();i++){
		ll idx1 = lower_bound(pos.begin(), pos.end(), (ll)ceil((double)neg[i]/(double)2)) - pos.begin();
		ll idx2 = upper_bound(pos.begin(), pos.end(), 2*neg[i]) - pos.begin();idx2--;
		if(idx1 != pos.size())answer += (idx2 - idx1) + 1;
	}
	cout << answer << endl;
}