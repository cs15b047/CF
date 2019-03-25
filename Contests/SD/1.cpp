#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9+7;
int main(){
	string s1="2010",s2="2015",s3="2016",s4="2017",s5="2019";
	ll t;cin>>t;
	for (int i = 0; i < t; ++i)
	{
		ll n;cin>>n;
		string c = to_string(n);
		if(c==s1 || c==s2 || c==s3 || c==s4 || c==s5)cout <<"HOSTED"<<endl;
		else cout <<"NOT HOSTED"<<endl;
	}
}