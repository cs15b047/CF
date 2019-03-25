#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main()
{
	ll n;scanf("%lld",&n);
	vector<ll>w(n);
	for(int i=0;i<n;i++)scanf("%lld",&w[i]);
	map<ll,ll> m,m2 ;
	for(int i=0;i<n;i++)m[w[i]]++;	
	m2.clear();
	int flag ;
	while(1){
		flag =1 ;
		for(auto it:m){
			if(it.second != 1){
				flag = 0;
				break ;
			}
		}
		if(flag == 1)break;
		for(auto it: m){
			ll cnt = it.second;
			if(m2.find(it.first) != m2.end())cnt += m2[it.first] ;
			vector<bool> bin ;
			while(cnt != 0){
				bin.push_back(cnt % 2) ;
				cnt = cnt/2 ;
			}
			for(int i=0;i<bin.size();i++){
				if(bin[i]){			
					if(i==0)m2[it.first+i] = 1 ;
					else{
						if(m2.find(it.first+i) != m2.end())m2[it.first+i]+= 1 ;
						else m2[it.first+i] = 1;
					}
				}
				else if(!bin[i] && i==0)m2.erase(it.first) ;
			}
		}
		m = m2 ;m2.clear();
	}
	cout << m.size() <<endl ;


}