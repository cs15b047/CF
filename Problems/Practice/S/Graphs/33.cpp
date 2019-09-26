#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node
{
	public:
		Node *left, *right;
		string val;
	Node(string str){val = str;left = NULL;right = NULL;}
};

void inorder(Node *node){
	if(node != NULL){
		if(node->val == "int")cout << "int";
		else {
			cout << "pair";
			cout << "<";
			inorder(node->left);
			cout << ",";
			inorder(node->right);
			cout << ">";
		}
	}
}

int main(){
	ll n; cin >> n;
	vector<string> inp;int j = 0;string str;while(cin >> str){inp.push_back(str);j++;}
	if(inp[0] == "int" && n == 1 && inp.size() == 1)cout << "int" << endl;
	else if(inp[0] == "int")cout << "Error occurred" << endl;
	else if(inp[0] == "pair"){
		stack<Node*> st;
		Node *root = new Node("pair");
		st.push(root);
		bool right = true;
		ll cnt = 0;
		for(int i = 1;i < inp.size();i++){
			while(!st.empty() && st.top()->right != NULL)st.pop();
			if(st.empty()){
				right = false;
				break;
			}
			Node *top = st.top();
			if(top->left == NULL){
				Node *node = new Node(inp[i]);
				top->left = node;
				if(inp[i] == "pair")st.push(node);
				else cnt++;
			} else if(top->right == NULL){
				Node *node = new Node(inp[i]);
				top->right = node;
				if(inp[i] == "pair")st.push(node);
				else cnt++;
			}
		}
		while(!st.empty() && st.top()->right != NULL)st.pop();
		if(!st.empty())right = false;
		right = right && (cnt == n);
		if(!right)cout << "Error occurred" << endl;
		else {
			inorder(root);
		}
	}
}