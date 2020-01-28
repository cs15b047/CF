#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int get_parity(int num){
	int answer = 0;
	while(num > 0){
		answer += (num % 2 == 1);
		num = num >> 1;
	}
	return (answer % 2);
}

int main(){
	ll t; cin >> t;
	for(int w = 0;w < t;w++){
		ll n, q; cin >> n >> q;
		vector<int> arr(n);for(int i = 0;i < n;i++)cin >> arr[i];
		vector<int> parity(n);
		for(int i = 0;i < n;i++)parity[i] = get_parity(arr[i]);

		set<int> odd_parity_idxs;
		for(int j = 0;j < parity.size();j++)
			if(parity[j] == 1)
				odd_parity_idxs.insert(j);

		int whole_parity = 0;
		for(int i = 0;i < n;i++)whole_parity = (whole_parity + parity[i]) % 2;

		cout << "Case #" << w + 1 << ": " ;
		for(int i =0;i < q;i++){
			int idx, ele; cin >> idx >> ele;
			int p = get_parity(ele);
			whole_parity = (whole_parity + (p != parity[idx])) % 2;
			if(odd_parity_idxs.find(idx) != odd_parity_idxs.end())odd_parity_idxs.erase(idx);
			if(p == 1)odd_parity_idxs.insert(idx);
			parity[idx] = p;
			int ans = n;
			if(whole_parity == 1){
				int idx1 = *odd_parity_idxs.begin(), idx2 = *odd_parity_idxs.rbegin();
				ans = max(n - 1 - (ll)idx1, (ll)idx2);
			} else ans = n;
			cout << ans << " ";
		}
		cout << endl;
	}
}
