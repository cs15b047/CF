#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    ll n; cin >> n;
    vector<pair<ll,ll>> seg(n);
    for(int i=0;i<n;i++)cin >> seg[i].first >> seg[i].second;
    map<ll,pair<ll,ll>> pointInfo;
    vector<ll> ptLoc;
    for(int i=0;i<n;i++){pointInfo[seg[i].first].first++;pointInfo[seg[i].second].second++;}
    for(auto it: pointInfo)ptLoc.push_back(it.first);
    vector<ll> ptCounts(n + 1, 0);
    ll curr = 0;
    for(int i=0;i<ptLoc.size();i++){
        if(i < ptLoc.size() - 1){
            ll pt1 = ptLoc[i], pt2 = ptLoc[i + 1];
            ll strt1 = pointInfo[pt1].first, end1 = pointInfo[pt1].second;
            ptCounts[curr + strt1] += 1;
            ptCounts[curr + strt1 - end1] += (pt2 - pt1 - 1);
            curr += strt1 - end1;
        }
        else{
            ll pt1 = ptLoc[i];
            ll strt1 = pointInfo[pt1].first, end1 = pointInfo[pt1].second;
            ptCounts[curr + strt1] += 1;
        }
    }
    for(int i=1;i <= n;i++){
        cout << ptCounts[i] << " ";
    }
}
