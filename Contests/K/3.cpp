#include <bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

int main(){
	ll t;cin>>t;
	for(int i=0;i<t;i++){
		ll l,n,k;cin>l>>n>>k;
		int flag=0;
		int len = 1;
		for(;len<=n;len++){
			if(k > (ll)pow(l,(len+1)/2))k -= (ll)pow(l,(len+1)/2) ;
			else if(k == (ll)pow(l,(len+1)/2)){
				for(int j=0;j<len;j++)cout<<('a'+l-1);
				flag=1;
				break;
			}
			else break;
		}
		if(!flag){
			for(int )
		}

	}	
}