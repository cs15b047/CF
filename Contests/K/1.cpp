#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll t;cin >> t;
	for(int j=0;j<t;j++){
		ll l;scanf("%lld",&l);
		char s1[51],s2[51];
		scanf("%s%s",s1,s2);
		string A(s1),B(s2);

		map<ll,set<map<char,ll>>> preprocessed;

		for(int len=1;len<=l;len++){
			map<char,ll> cnt ;
			for(int i=0;i<len;i++)cnt[B[i]]++;
			// for(auto it: cnt)cout << it.first << " "<< it.second << endl ;
			preprocessed[len].insert(cnt);
			for(int i=1;i<=l-len;i++){
				cnt[B[i-1]]--;cnt[B[i+len-1]]++;
				if(cnt[B[i-1]]==0)cnt.erase(B[i-1]);
				preprocessed[len].insert(cnt);
				// for(auto it: cnt)cout << it.first << " "<< it.second << endl ;
			}
		}
		ll ans = 0 ;
		for(int len=1;len<=l;len++){
			map<char,ll> cnt ;
			
			for(int i=0;i<len;i++)cnt[A[i]]++;
			// for(auto it: cnt)cout << it.first << " "<< it.second << endl ;
			if(preprocessed[len].find(cnt) != preprocessed[len].end())ans++;
			
			for(int i=1;i<=l-len;i++){
				cnt[A[i-1]]--;cnt[A[i+len-1]]++;
				if(cnt[A[i-1]]==0)cnt.erase(A[i-1]);
				// for(auto it: cnt)cout << it.first << " "<< it.second << endl ;
				if(preprocessed[len].find(cnt) != preprocessed[len].end())ans++;
			}
		}
		// cout << "Case #"<<(j+1)<<": " << ans << endl;
		printf("Case #%d: %lld\n",j+1,ans);
	}
}