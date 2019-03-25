#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, l, r; cin >> n >> l >> r ;

	ll ht = 1,tmp = n;
	vector<ll> nums;
	nums.push_back(tmp);
	while(tmp != 1){
		tmp /= 2;
		ht++;
		nums.push_back(tmp);
	}
	reverse(nums.begin(),nums.end());
	ll total = (ll)pow(2,ht) - 1 ;

	stack<ll> st;
	ll tmp_ht = ht,tl = l;
	while(tl != 0){
		if(tl < (ll)pow(2,tmp_ht-1))st.push(make_pair(nums[tmp_ht], 0));
		else if(tl == (ll)pow(2,tmp_ht-1)){
			st.push(make_pair(nums[tmp_ht], 0));
			tl = 0;
		}
		else if(tl > (ll)pow(2,tmp_ht-1)){
			st.push(make_pair(nums[tmp_ht], 1));
			tl -= (ll)pow(2,tmp_ht-1);
		}
		tmp_ht--;
	}

	ll cnter = l;

	while(cnter <= r){
		while
	}



}