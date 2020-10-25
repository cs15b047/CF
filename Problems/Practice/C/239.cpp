#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> LIS_opt(vector<ll> arr){
	vector<ll> lis_arr;lis_arr.clear();
	ll sz = arr.size();
	vector<ll> answer(arr.size(), 0);
	answer[0] = 1;
	lis_arr.push_back(arr[0]);
	for(int i = 1;i < sz;i++){
		int idx = upper_bound(lis_arr.begin(), lis_arr.end(), arr[i]) - lis_arr.begin();
		if(idx == lis_arr.size()){
			lis_arr.push_back(arr[i]);
			answer[i] = lis_arr.size();
		} else{
			lis_arr[idx] = arr[i];
			answer[i] = idx + 1;
		}
	}
	return answer;
}

int main(){
	ll len; cin >> len;
	string seq; cin >> seq;

	string copy = seq;
	sort(copy.begin(), copy.end());

	map<char, vector<ll>> positions;
	for(int i = 0;i < len;i++)
		positions[copy[i]].push_back(i);

	vector<ll> posns(len);
	for(int i = len - 1;i >= 0;i--){
		posns[i] = positions[seq[i]].back();
		positions[seq[i]].pop_back();
	}
	// for(auto it: posns)cout << it << " ";cout << endl;
	reverse(posns.begin(), posns.end());
	vector<ll> lis_arr = LIS_opt(posns);
	reverse(lis_arr.begin(), lis_arr.end());

	ll mxm = 1;
	for(auto it:lis_arr)mxm = max(mxm, it);
	cout << mxm << endl;
	for(auto it:lis_arr)cout << it << " ";cout << endl;
}