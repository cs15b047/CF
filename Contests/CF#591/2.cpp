#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
	ll q; cin >> q;
	for(int w = 0;w < q;w++){
		string str1, str2; cin >> str1 >> str2;
		vector<bool>cnt1(26, false), cnt2(26, false);
		for(auto it: str1)cnt1[it - 'a'] = true;
		for(auto it: str2)cnt2[it - 'a'] = true;
		bool done = false;
		for(int i = 0;i < 26;i++){
			if(cnt1[i] && cnt2[i]){
				done = true;
				break;
			}
		}
		if(done){
			cout << "YES" << endl;
		} else{
			cout << "NO" << endl;
		}
	}
}