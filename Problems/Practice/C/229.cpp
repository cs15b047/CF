#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n;
	vector<ll> y(n);
	for(int i = 0;i < n;i++)cin >> y[i];
	set<ll> reduced_ele;
	for(auto it: y)
		reduced_ele.insert(it);
	while(true){
		ll mxm_ele = *reduced_ele.rbegin();
		ll tmp = mxm_ele;
		while(tmp != 0){
			if(tmp != mxm_ele && reduced_ele.find(tmp) == reduced_ele.end()){
				reduced_ele.erase(mxm_ele);
				reduced_ele.insert(tmp);
				break;
			} else{
				tmp = tmp / 2;
			}
		}
		// mxm element gets fixed --> so can exit
		if(tmp == 0){
			break;
		}
	}
	for(auto it: reduced_ele)cout << it << " ";cout << endl;
}