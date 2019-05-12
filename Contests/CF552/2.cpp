#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n; cin >> n;
	vector<ll> bits;ll tmp = n;while(tmp != 0){bits.push_back(tmp % 2);tmp = tmp / 2;}
	bool cond = true;
	for(auto it:bits){if(it == 0)cond = false;}
	ll answer = 0;
	vector<ll> ans_vec;ans_vec.clear();
	while(!cond){
		ll idx = -1,idx2=-1;
		for(int i=bits.size()-1;i>=0;i--){
			if(bits[i] == 0){idx = i; ans_vec.push_back(idx + 1); break;}
		}
		for(int i=idx;i>=0;i--)bits[i] = 1 - bits[i];
		answer++;
		cond = true;
		for(auto it:bits){if(it == 0)cond = false;}
		if(cond)break;
		for(int i=0;i<bits.size();i++){
			if(bits[i] == 0){bits[i] = 1;idx2 = i;break;}
			else bits[i] = 0;
		}
		answer++;
		cond = true;
		for(auto it:bits){if(it == 0)cond = false;}
	}
	cout << answer << endl;
	for(auto it:ans_vec)cout << it << " " ;cout << endl;
}