#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node{
	Node *left, *right;
	multiset<ll> values;
};

void print_multiset(multiset<ll>val){
	for(auto it:val)cout << it << " ";cout << endl;
}

void populate_tree(Node* root, ll pwr){
	// print_multiset(root->values);
	multiset<ll> left, right;
	for(auto it: root->values){
		if((it / (ll)pow(2, pwr)) % 2 == 1){
			right.insert(it);
		} else left.insert(it);
	}
	// print_multiset(left);print_multiset(right);
	if(!left.empty()){
		root->left = new Node();
		root->left->values = left;
		if(pwr > 0)populate_tree(root->left, pwr - 1);
	}
	if(!right.empty()){
		root->right = new Node();
		root->right->values = right;
		if(pwr > 0)populate_tree(root->right, pwr - 1);
	}
}

vector<ll> get_bit_repr(ll tmp){
	vector<ll>bit_repr(31, 0);
	for(int i = 0;i <= 30;i++){
		bit_repr[i] = tmp % 2;
		tmp = tmp / 2;
	}
	return bit_repr;
}

void del(Node* root, ll num){
	Node* curr = root;
	vector<ll> bit_repr = get_bit_repr(num);
	for(int i = 30;i >=0;i--){
		curr->values.erase(num);
		if(bit_repr[i] == 1){
			curr = curr->right;
		} else{
			curr = curr->left;
		}
	}
}

ll delete_similar(Node* root, ll number){
	ll tmp =  number;
	ll ans;
	// cout << number << endl;
	vector<ll> bit_repr = get_bit_repr(number);
	Node *curr = root;
	for(int i = 30;i >= 0; i--){
		if(curr->values.size() == 1){
			ans = *curr->values.begin();
			break;
		}
		if(bit_repr[i] == 1){
			if(curr->right == NULL || curr->right->values.empty()){
				curr = curr->left;
			} else{
				curr = curr-> right;
			}
		} else{
			if(curr->left == NULL || curr->left->values.empty()){
				curr = curr->right;
			} else{
				curr = curr-> left;
			}
		}
	}
	
	del(root, ans);
	return ans;
}


int main(){
	ll n; cin >> n;
	vector<ll>msg(n), keys(n);
	for(int i = 0;i<n;i++)scanf("%lld",&msg[i]);
	for(int i = 0;i<n;i++)scanf("%lld",&keys[i]);

	Node *root = new Node();
	for(int i = 0;i < n;i++){
		root->values.insert(keys[i]);
	}
	populate_tree(root, 30);
	// cout << "1: Done" << endl;

	for(int i = 0;i < n;i++){
		ll ele = delete_similar(root, msg[i]);
		printf("%lld ",ele ^ msg[i] );
	}
	printf("\n");
}