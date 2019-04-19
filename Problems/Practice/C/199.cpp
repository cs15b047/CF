#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n;vector<ll>arr(n);for(int i=0;i<n;i++)cin >>arr[i];
	vector<ll> lists;
	lists.push_back(arr[0]);
	for(int i=1;i<n;i++){
		auto it = upper_bound(lists.begin(),lists.end(),arr[i]);
		if(it != lists.end())*it = arr[i];
		else lists.push_back(arr[i]);
	}
	cout << lists.size() << endl;
}