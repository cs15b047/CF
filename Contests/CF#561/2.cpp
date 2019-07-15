#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

int main(){
	ll k; cin >> k;
	vector<ll> factors;for(int i=2;i<=k;i++)if(k % i == 0)factors.push_back(i);
	ll first = -1, second = -1;
	for(auto it: factors){
		if(it >= 5 && k / it >= 5){
			first = it;second = k / first;
		}
	}
	if(first == -1)cout << -1 << endl;
	else{
		string str = "";for(int i=0;i<second;i++)str+='a';
		vector<string> op(first);
		op[0] = "aeiou";for(int i=5;i<second;i++)op[0].push_back('a');
		op[1] = "eioua";for(int i=5;i<second;i++)op[1].push_back('e');
		op[2] = "iouae";for(int i=5;i<second;i++)op[2].push_back('i');
		op[3] = "ouaei";for(int i=5;i<second;i++)op[3].push_back('o');
		op[4] = "uaeio";for(int i=5;i<second;i++)op[4].push_back('u');
		for(int i=5;i<first;i++)op[i] = str ;
		for(int i=5;i<first;i++){
			op[i][0] = 'a';
			op[i][1] = 'e';
			op[i][2] = 'i';
			op[i][3] = 'o';
			op[i][4] = 'u';
		}
		for(int i=0;i<first;i++)cout << op[i];
		cout << endl;
	}
}