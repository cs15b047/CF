#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n, mod;
vector<ll> ele;

bool possible(ll answer, vector<ll> arr){
	for(int i = 0;i < arr.size();i++){
		if(i == 0){
			if(mod - arr[0] <= answer)
				arr[0] = 0;
		} else {
			if(arr[i] < arr[i - 1]){
				if(arr[i - 1] - arr[i] <= answer)
					arr[i] = arr[i - 1];
			} else {
				if(mod - arr[i] + arr[i - 1] <= answer)arr[i] = arr[i - 1];
			}
			if(arr[i] < arr[i - 1])return false;
		}
	}
	return true;
}

int main(){
	cin >> n >> mod;
	ele.resize(n); for(int i = 0;i < n;i++)cin >> ele[i];
	ll answer, left = 0, right = mod;
	vector<ll> cpy = ele;
	
	while(left < right){
		answer = (left + right)/2;
		bool poss = possible(answer, cpy);
		if(poss){
			right = answer;
		} else {
			left = answer + 1;
		}
	}
	cout << left << endl;

	


}