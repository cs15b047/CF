#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 998244353 ;
int main(){
	ll n; cin >> n ;
	char s[200001];scanf("%s",s);string str(s);
	ll st=0,end= n - 1;
	ll i=0,j=n-1,flag = 0;
	while(str[i] == str[st])i++;
	while(str[j] == str[end])j--;
	if(str[0] == str[n - 1])flag = 1;

	if(flag == 0){
		cout << ((i + 1) + (n - j) - 1) % mod << endl;
	}
	else{
		cout << ((i+1) * (n - j)) % mod << endl ;
	}
}