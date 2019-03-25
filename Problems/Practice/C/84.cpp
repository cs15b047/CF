#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
vector<ll>skills;

bool comp(ll i1, ll i2){
	return skills[i1] > skills[i2];
}

int main(){
	ll n;cin>>n;
	skills.resize(n);for(int i=0;i<n;i++)scanf("%lld",&skills[i]);
	vector<ll>indices(n);for(int i=0;i<n;i++)indices[i]=i;
	sort(indices.begin(),indices.end(), comp);

	ll sum1=0,sum2=0;
	vector<ll>team1,team2;
	for(int i=0;i<n;i++){
		if(i%2==0){
			sum1+=skills[indices[i]];
			team1.push_back(indices[i] + 1);
		}
		else{
			sum2+=skills[indices[i]];
			team2.push_back(indices[i] + 1);
		}
	}
	cout << team1.size() << endl;
	for(auto it: team1)cout << it << " ";
	cout << endl;
	cout << team2.size() << endl;
	for(auto it: team2)cout << it << " ";
	cout << endl;

}