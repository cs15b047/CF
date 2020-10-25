#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll len; cin >> len;
	string seq; cin >> seq;

	// Test for answer existence
	bool possible = true;
	vector<ll> lds(len, 0);
	for(int i = 0;i < len;i++){
		for(int j = 0;j < i;j++){
			if(seq[j] > seq[i]){
				lds[i] = max(lds[i], lds[j]);
			}
		}
		lds[i]++;
	}
	ll longest = 1;
	for(int i = 0;i < len;i++)
		longest = max(longest, lds[i]);
	if(longest > 2){
		possible = false;
	}

	if(possible){
		vector<ll> color(len, -1);
		for(int i = len - 1;i >= 0;i--){
			if(color[i] == -1){
				color[i] = 0;
				for(int j = 0;j < i;j++){
					if(seq[j] > seq[i]){
						color[i] = 1;
					}
				}
			}
		}
		cout << "YES" << endl;
		for(auto it:color)cout << it;cout <<  endl;
	} else{
		cout << "NO" << endl;
	}
}