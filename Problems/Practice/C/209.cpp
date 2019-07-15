// C. Cd and pwd commands CF# VK Cup Qual round 1
// No idea. Just implement whatever is given
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	vector<string> pth;pth.clear();
	ll n; cin >> n;
	for(int i=0;i<n;i++){
		string str1, str2;
		cin >> str1;
		if(str1 == "cd"){
			cin >> str2 ;
			stringstream check(str2);string intmdt="";

			if(str2[0] == '/')pth.clear();
			while(getline(check, intmdt, '/')){
				if(intmdt == "..")pth.pop_back();
				else pth.push_back(intmdt);
				// cout << intmdt << endl;
			}
		}
		else if(str1 == "pwd"){
			for(auto it:pth){
				if(it != "")cout << "/" << it;
			}
			cout << "/" << endl;
		}
	}
}