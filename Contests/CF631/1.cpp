#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll tests;cin >> tests;
	for(int t = 0;t < tests;t++){
		ll n, x;cin >> n >> x;
		vector<ll> arr(301, 0);for(int i =0;i < n;i++){ll val; cin >> val;arr[val] = 1;}
		vector<ll> pr_arr(301, 0);
		pr_arr[0] = 0;
		ll answer = 1;
		for(int i = 1;i <= 300;i++){
			if(arr[i] == 0){
				if(pr_arr[i - 1] == x){answer = i - 1;break;}
				pr_arr[i] = pr_arr[i - 1] + 1;
			} else{
				pr_arr[i] = pr_arr[i - 1];
			}
		}
		cout << answer << endl;
	}

}