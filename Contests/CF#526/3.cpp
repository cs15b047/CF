#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9 + 7;
int main(){
	char s[100001];scanf("%s",s);
	string str(s);
	ll len = str.length();
	ll least_j = -1,nxt_a = -1;
	vector<ll> suffix_sum(len + 1);
	for(int i=0;i<len+1;i++)suffix_sum[i] = -1;

	for(ll itr = len -1;itr >= 0;itr--){
		if(str[itr] == 'b' && nxt_a != -1)least_j = nxt_a;
		if(str[itr] == 'a'){
			if(nxt_a == -1){
				nxt_a = itr ;
				suffix_sum[itr] = 1;
			}
			else{
				ll locl_ans = 1;
				if(least_j != -1)locl_ans = (locl_ans + suffix_sum[least_j]) % mod ;
				suffix_sum[itr] = (suffix_sum[nxt_a] + locl_ans) % mod;
				nxt_a = itr ;
			}
		}
	}
	if(nxt_a == -1){
		cout << 0 << endl ;
	}
	else{
		for(int i=0;i<len+1;i++){
			if(suffix_sum[i] != -1){
				cout << suffix_sum[i] << endl;
				break;
			}
		}
	}

}