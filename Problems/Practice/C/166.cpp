#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

bool calc_ans(string s1, string s2){
	if(s1.length()!=s2.length())return 0;
	if(s1 == s2)return 1;
	else{
		if((s1.length() % 2 == 0) && (s2.length() % 2 == 0))
			return (calc_ans(s1.substr(0,s1.length()/2), s2.substr(s2.length()/2,s2.length()/2)) && calc_ans(s1.substr(s1.length()/2,s1.length()/2), s2.substr(0,s2.length()/2))) || (calc_ans(s1.substr(0,s1.length()/2), s2.substr(0,s2.length()/2)) && calc_ans(s1.substr(s1.length()/2,s1.length()/2), s2.substr(s2.length()/2,s2.length()/2)) ) ;
		return 0;
	}
	return 0;
}

int main(){
	string s1,s2; cin >> s1 >> s2;
	if(calc_ans(s1, s2))cout << "YES"<<endl;
	else cout << "NO"<<endl;
}