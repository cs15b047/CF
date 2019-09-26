#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bool cmp(string str1, string str2){
	return (str1 + str2) < (str2 + str1);
}

int main(){
	ll n; scanf("%lld",&n);
	vector<string> strs(n);
	for(int i =0;i < n;i++){
		char s[60];scanf("%s",s);string str(s);strs[i] = str;
	}
	sort(strs.begin(),strs.end(), cmp);
	for(int i = 0;i < n;i++)cout << strs[i];cout<< endl;
}