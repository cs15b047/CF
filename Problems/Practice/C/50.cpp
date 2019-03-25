#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool cross(set<char>s, char x){
	if((x=='R' && s.find('L') != s.end()) || (x=='L' && s.find('R') != s.end()))return true;
	if((x=='U' && s.find('D') != s.end()) || (x=='D' && s.find('U') != s.end()))return true;
	return false;
}

int main()
{
	ll n;cin>>n;
	char s1[200001];scanf("%s",s1);
	string str(s1);

	set<char> s;
	ll cnt = 0,ans=0;

	while(cnt < n){		
		if(cross(s,str[cnt])){
			ans++;
			s.clear();
			s.insert(str[cnt]);
		}
		else{
			s.insert(str[cnt]);
		}
		cnt++;
	}
	ans++;
	cout << ans << endl ;

	return 0;
}