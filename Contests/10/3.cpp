#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

char s[100001];
int main(){
	ll n;cin>>n;
	scanf("%s",s);
	string str(s);
	map<char,ll> cnt;
	for(int i=0;i<str.length();i++)cnt[str[i]]++;
	string ans = "";
	for(auto it:cnt){
		char c = it.first;for(int j=0;j<it.second;j++)ans += c;
	}
	cout << ans << endl ;
}