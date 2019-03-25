#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
int main(){
	char s[10001];scanf("%s",s);
	string str(s);
	int n = (int)str.length();
	vector<set<string>> answer(n);
	for(auto &it:answer)it.clear();
	if(str.length()<=6)cout << "0"<<endl;
	else if(str.length()==7)cout << "1\n"<<str.substr(n-2,2)<<endl ;
	else{
		answer[n-2].insert(str.substr(n-2,2));
		answer[n-3].insert(str.substr(n-3,3));
		for(int i=n-4;i>=5;i--){
			string str2 = str.substr(i,2), str3 = str.substr(i,3);
			if(!answer[i+2].empty() && !((answer[i+2].size() == 1) && (*answer[i+2].begin() == str2)))answer[i].insert(str2);
			if((!answer[i+3].empty()) && !((answer[i+3].size() == 1) && (*answer[i+3].begin() == str3)))answer[i].insert(str3);
		}
		set<string> final;
		for(auto st: answer){
			for(auto it: st){
				final.insert(it);
			}
		}
		cout << final.size() << endl ;
		for(auto it:final)cout << it << endl;
	}
}