#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll n;cin>>n;
	vector<ll>a(n);
	map<ll,ll> m;
	set<ll>s1,s2;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]++;
	}
	for(auto it:m){
		if(it.second == 1)s1.insert(it.first);
		else if(it.second == 2)s2.insert(it.first);
	}
	if(s1.size()==0){
		cout << "YES"<<endl;
		string str ="";
		for(auto it:a)str+='A';
		cout << str << endl;
	}

	else if(s1.size() % 2 == 0){
		cout << "YES"<<endl;
		ll curr=0;
		string str="";
		for(auto it:a)
		{
			if(curr < s1.size()/2 && s1.find(it) != s1.end()){str+='B';curr++;}
			else{str += 'A';}
		}
		cout << str << endl;
	}
	else if((s1.size() % 2 == 1) && (s1.size() + 2*s2.size() < n)){
		cout << "YES"<<endl;
		ll curr=0;
		string str="";
		map<int,int> mymap;
		for(auto it: s1){
			if(curr < (s1.size() -1)/ 2){mymap[it] = 2;curr++;}
			else {
				mymap[it] = 1;
			}
		}
		for(auto it:a)
		{
			if(mymap.find(it) != mymap.end()){
				if(mymap[it] == 1)str+='A';
				else str +='B';
			}
			else if(curr == (s1.size()-1)/2 && s1.find(it)==s1.end() && s2.find(it)==s2.end()){str+='B';curr++;}
			else str+='A';
		}	
		cout << str << endl;
	}
	else{
		cout << "NO"<<endl;
	}
	
	return 0;
}