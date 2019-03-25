//B2. EKG #ABBYY CUP 3.0
// calc all separate lists, and put all their sizes (except one containing x) together, then dp: 
//Dp[i] = Sets of Sums which are obtainable using 1st i numbers
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll n, x; cin >> n >> x ;
	vector<ll> a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin >> a[i];
	for(int i=1;i<=n;i++){
		if(a[i] != 0)b[a[i]] = i;
	}
	map<ll,ll> counts;
	ll set_num,set_cnt,offset = 0;
	for(int i=1;i<=n;i++){
		if(a[i] == 0){
			ll start = i,cnt = 1,reqd = 0;
			// cout << start << endl ;
			if(start == x){reqd = 1;offset =1;}
			while(b[start] != 0){
				start = b[start];
				cnt++;
				if(start == x){reqd = 1;offset = cnt;}
			}
			counts[i] = cnt;
			if(reqd == 1){
				set_num = i;set_cnt = cnt;
			}
		}
	}
	// cout << set_num << " " << set_cnt << " " << offset << endl;

	vector<ll> cont;
	for(auto it:counts){
		if(it.first != set_num)cont.push_back(it.second);
	}
	// for(auto it:cont)cout << it << " " ; cout << endl;
	vector<set<ll>>dp(2);
	dp[0].insert(0);
	for(int i=0;i<cont.size();i++){
		if(i == 0){dp[i%2].insert(cont[i]);}
		else{
			dp[i%2] = dp[(i-1)%2];
			for(auto it:dp[(i-1)%2])dp[i%2].insert(it + cont[i]);
		}
	}
	if(cont.empty())cout << offset << endl ;
	else{
		for(auto it:dp[(cont.size() - 1) % 2]){
			printf("%lld\n",it + offset );
		}
	}
}