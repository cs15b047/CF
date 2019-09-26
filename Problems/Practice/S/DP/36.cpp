#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll n; cin >> n; string str; cin >> str;
	string str0, str1;for(int i = 0;i < n;i++){if(i%2==0){str0+='0';str1+='1';} else{str0+='1';str1+='0';}}
	ll diff0=0, diff1=0;
	for(int i=0;i<n;i++){
		diff0 += str[i] != str0[i];
		diff1 += str[i] != str1[i];
	}
	cout <<  min(diff0, diff1) << endl;
}