#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tests;
ll n, lt, rt;

vector<ll> boundaries, ans;

void take_input(){
	scanf("%lld%lld%lld", &n, &lt, &rt);
}
void init(){
	boundaries.clear();
	ans.clear();
	boundaries.push_back(0);
	for(ll i = n - 1;i >= 1;i--){
		boundaries.push_back(boundaries.back() + 2 * i);
	}
}
void calc_ans(){
	for(ll num = lt - 1;num <= rt - 1; num++){
		ll curr;
		if(num == n *(n - 1))curr = 1;
		else{
			ll idx = upper_bound(boundaries.begin(), boundaries.end(), num) - boundaries.begin();idx--;
			ll offset = num - boundaries[idx];
			// cout << idx << " " << offset << endl;
			if(offset % 2 == 0) curr = idx + 1;
			else{
				curr = (idx + 1) + (offset + 1)/2;
			}
		}
		ans.push_back(curr);
	}
}

int main(){
	scanf("%lld", &tests);
	for(int t = 0;t < tests;t++){
		take_input();
		init();
		calc_ans();
		for(auto it: ans)cout << it << " ";cout << endl;
	}

	return 0;
}