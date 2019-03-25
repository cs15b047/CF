//B. New Year Permutation good bye 2014
// take in 1 component and sort
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

map<ll,bool> visited;
map<ll,set<ll>> groups;
map<ll,ll> membership;
vector<vector<ll>> adj;

void dfs(int curr, int root){
    groups[root].insert(curr);
    visited[curr] = true;
    membership[curr] = root;

    for(auto it:adj[curr]){
        if(visited.find(it) == visited.end()){
            dfs(it,root);
        }
    }
}

int main(){
    ll perm_size;cin>> perm_size;
    vector<ll> perm(perm_size);for(int i=0;i<perm_size;i++)scanf("%lld",&perm[i]);

    vector<string> A(perm_size);
    for(int i=0;i<perm_size;i++)cin >> A[i];

    adj.resize(perm_size);
    for(int i=0;i<perm_size;i++){
        for(int j=0;j<perm_size;j++){
            if(A[i][j] == '1')adj[i].push_back(j);
        }
    }
    visited.clear();
    for(int i=0;i<perm_size;i++){
        if(visited.find(i) == visited.end())            
            dfs(i, i);
    }
    map<ll,set<ll>> group_ele;
    // convert to elements
    for(auto it: groups){
        for(auto &it2: it.second){
            group_ele[it.first].insert(perm[it2]);
        }
    }
    for(auto it:membership){
        ll element = *(group_ele[it.second].begin());
        group_ele[it.second].erase(element);
        cout << element << " ";
    }
}