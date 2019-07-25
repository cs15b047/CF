#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll t; scanf("%lld",&t);
	for(int q=0;q<t;q++){
		char s[100001]; scanf("%s",s);string str(s);
		vector<ll> ones_pref(str.length(), 0);
		for(int i=0;i<str.length();i++){
			if(i == 0)ones_pref[i] = (str[i] == '1');
			else ones_pref[i] = ones_pref[i - 1] + (str[i] == '1');
		}
		ll ans = 0;
		for(int i=0;i < str.length();i++){
			for(int x = 1; x*(x + 1) <= str.length();x++){
				ll strt = i, end = i + x*(x + 1) - 1;
				if(end >= str.length())break;
				if(ones_pref[end] - ((strt > 0) ? ones_pref[strt - 1]:0) == x){
					ans++;
				}
			}
		}
		printf("%lld\n",ans );
	}
}