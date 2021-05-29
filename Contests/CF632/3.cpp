#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n; cin >> n;
	vector<ll> arr(n);for(int i = 0;i < n;i++)cin >> arr[i];
	vector<ll> prefix_sum(n , arr[0]);
	for(int i = 1;i < n;i++)prefix_sum[i] = prefix_sum[i - 1] + arr[i];

	ll ptr1 = 0, ptr2 = 0;
	set<ll> uniq_sums;
	
	ll answer = 0;
	while(ptr1 < n || ptr2 < n){
		while((ptr2 < n) && (arr[ptr2] != 0) && !(prefix_sum[ptr2] == 0 && ptr1 == 0) && (uniq_sums.find(prefix_sum[ptr2] - prefix_sum[ptr1] + arr[ptr1]) == uniq_sums.end())){
			uniq_sums.insert(prefix_sum[ptr2]);
			ptr2++;
		}
		cout << ptr1 << " " << ptr2 << endl;
		for(auto it: uniq_sums)cout << it << " ";cout << endl;
		if(prefix_sum[ptr2] == 0 && ptr1 == 0){
			cout << "yalal";
			answer += (ptr2 - ptr1);
			while(ptr1 < ptr2){
				uniq_sums.erase(prefix_sum[ptr1]);
				ptr1++;
			}

		}
		else if(ptr2 < n && arr[ptr2] != 0){
			while(uniq_sums.find(prefix_sum[ptr2]) != uniq_sums.end()){
				uniq_sums.erase(prefix_sum[ptr1]);
				answer += (ptr2 - ptr1);
				ptr1++;
			}
		} else if(ptr2 == n){
			ll len = ptr2 - ptr1;
			answer += (len * (len + 1))/ 2;
			break;
		}
		else if(arr[ptr2] == 0){
			ll len = ptr2 - ptr1;
			answer += (len * (len + 1))/ 2;
			ptr2++;
			ptr1 = ptr2;
		}
	}
	cout << answer << endl;
}