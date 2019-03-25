#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

long double dist(pair<long double,long double> v, pair<long double,long double> w){
	return pow((pow((v.first-w.first),2) + pow((v.second-w.second),2)), 0.5);
}

pair<long double,long double> a,b,t;
vector<pair<long double,long double>> pos;
bool comp1(int c, int d){
	return (dist(a, pos[c]) - dist(t,pos[c])) < (dist(a, pos[d]) - dist(t,pos[d]));
}
bool comp2(int c, int d){
	return (dist(b, pos[c]) - dist(t,pos[c])) < (dist(b, pos[d]) - dist(t,pos[d]));
}

int main()
{
	long double ax,ay,bx,by,tx,ty;cin>>ax>>ay>>bx>>by>>tx>>ty;
	a = make_pair(ax,ay);b = make_pair(bx,by);t = make_pair(tx,ty);
	ll n;cin>>n;
	pos.resize(n);
	for(int i=0;i<n;i++)cin>>pos[i].first>>pos[i].second;

	long double tot = 0.0;
	for(int i=0;i<n;i++)tot += 2.0*dist(pos[i],t);
	// cout << tot <<endl;

	vector<int> d1(n),d2(n);
	vector<long double> dist1(n),dist2(n);
	for(int i=0;i<n;i++){d1[i]=i;d2[i]=i;}
	sort(d1.begin(),d1.end(),comp1);
	sort(d2.begin(),d2.end(),comp2);

	for(int i=0;i<n;i++){
		int idx1 = d1[i],idx2 = d2[i];
		dist1[i] = dist(a,pos[idx1]) - dist(t,pos[idx1]);
		dist2[i] = dist(b,pos[idx2]) - dist(t,pos[idx2]);
	}

	// for(auto it:d1)cout<< it<< " ";
	// cout << endl;
	// for(auto it:d2)cout<< it<< " ";
	// cout << endl;
	// for(auto it:dist1)cout<< it<< " ";
	// cout << endl;
	// for(auto it:dist2)cout<< it<< " ";
	// cout << endl;

	if(n == 1){
		tot += min(dist1[0],dist2[0]);
	}
	else{
		if(d1[0] == d2[0]){
			if(dist1[1] < 0 && dist2[1] < 0 )tot += min(dist1[0]+dist2[1], dist1[1]+dist2[0]);			
			else if(dist1[1] < 0) tot += min(dist1[0], dist1[1]+dist2[0]);
			else if(dist2[d2[1]] < 0) tot += min(dist1[0]+dist2[1],dist2[0]);
			else tot += min(dist1[0],dist2[0]);			
		}
		else{
			if(dist1[0] < dist2[0]){
				tot += dist1[0];
				long double maybe = dist2[0];
				if(maybe < 0)tot += maybe ;
			}
			else{
				tot += dist2[0];
				long double maybe = dist1[0];
				if(maybe < 0)tot += maybe ;
			}
		}
	}
	printf("%.7Lf\n",tot );


	return 0;
}