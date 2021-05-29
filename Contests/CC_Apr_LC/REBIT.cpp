#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Node{
public:
	vector<ll> probs;
	char op;
	Node *left, *right;

	Node(){
		this->left = NULL;
		this->right = NULL;
		probs.resize(4);
	}
};

Node* parse_expr(string &expr){
	ll len = expr.length();
	stack<char> stk;
	string postfix = "";
	for(int i = 0;i < len;i++){
		if(expr[i] == '(')stk.push(expr[i]);
		else if(expr[i] == '#')postfix += expr[i];
		else if(expr[i] == '&' || expr[i] == '^' || expr[i] == '|')stk.push(expr[i]);
		else if(expr[i] == ')'){
			while(stk.top() != '('){
				postfix += stk.top();
				stk.pop();
			}
			// if(stk.top() != '('){cout << "yo!!";exit(0);}
			stk.pop();
		}
	}
	assert(stk.empty());

	// cout << postfix << endl;

	ll len_post = postfix.length();
	stack<Node*> stk_node;
	for(int i = 0;i < len_post;i++){
		if(postfix[i] == '#'){
			Node *node = new Node();
			node->op = '#';
			stk_node.push(node);
		} else if((postfix[i] == '&') || (postfix[i] == '^') || (postfix[i] == '|')){
			Node *node1, *node2;
			node2 = stk_node.top();stk_node.pop();
			node1 = stk_node.top();stk_node.pop();
			Node *node = new Node();
			node->op = postfix[i]; node->left = node1; node->right = node2;
			stk_node.push(node);
		}
	}
	Node *root = stk_node.top();stk_node.pop();
	assert(stk_node.empty());
	return root;
}

ll mod = 998244353;

ll pwr(ll base, ll idx){
	if(idx == 0)return 1;
	ll tmp = pwr(base, idx/2);
	ll intmdt = (tmp * tmp) % mod;
	if(idx % 2 == 0)return intmdt;
	return (intmdt * base) % mod;
}

ll inv(ll num){
	return pwr(num, mod - 2);
}


vector<ll> apply_rules(const vector<ll> &child1, const vector<ll> &child2, char op){
	vector<ll> ans(4, 0);
	if(op == '&'){
		// p1 + q1 - p1*q1 + p3*q4 + p4*q3
		ll exp1 = (child1[0] + child2[0]) % mod, exp2 = ((child1[0]* child2[0]) % mod);
		ans[0] = ((exp1 - exp2  + mod) % mod + ((child1[2] * child2[3]) % mod) + ((child1[3] * child2[2]) % mod)) % mod;
		ans[1] = (child1[1] * child2[1]) % mod;
		ans[2] = (((child1[2] * child2[2]) % mod) + ((child1[1] * child2[2]) % mod) + ((child1[2] * child2[1]) % mod)) % mod;
		ans[3] = (((child1[3] * child2[3]) % mod) + ((child1[1] * child2[3]) % mod) + ((child1[3] * child2[1]) % mod)) % mod;
	} else if(op == '|'){
		ll exp1 = (child1[1] + child2[1]) % mod, exp2 = ((child1[1] * child2[1]) % mod);
		ans[0] = (child1[0] * child2[0]) % mod;
		ans[1] = ((exp1 - exp2 + mod) % mod + ((child1[2] * child2[3]) % mod) + ((child1[3] * child2[2]) % mod)) % mod;
		ans[2] = (((child1[0] * child2[2]) % mod) + ((child1[2] * child2[0]) % mod) + ((child1[2]*child2[2])% mod)) % mod;
		ans[3] = (((child1[0] * child2[3]) % mod) + ((child1[3] * child2[0]) % mod) + ((child1[3]*child2[3])% mod)) % mod;
	} else if(op == '^'){
		ans[0] = ((child1[0] * child2[0]) % mod + (child1[1] * child2[1]) % mod + (child1[2] * child2[2]) % mod + (child1[3] * child2[3]) % mod) % mod;
		ans[1] = ((child1[0] * child2[1]) % mod + (child1[1] * child2[0]) % mod + (child1[2] * child2[3]) % mod + (child1[3] * child2[2]) % mod) % mod;
		ans[2] = ((child1[2] * child2[0]) % mod + (child1[0] * child2[2]) % mod + (child1[3] * child2[1]) % mod + (child1[1] * child2[3]) % mod) % mod;
		ans[3] = ((child1[3] * child2[0]) % mod + (child1[0] * child2[3]) % mod + (child1[2] * child2[1]) % mod + (child1[1] * child2[2]) % mod) % mod;
	}
	return ans;
}

// Posn-> meaning: 0 -> 0, 1 -> 1, 2 -> a, 3 -> A
void calc_ans(Node *root){
	if(root->op == '#' && root->left == NULL && root->right == NULL){
		ll rend_p = inv(4);
		root->probs[0] = rend_p; root->probs[1] = rend_p; root->probs[2] = rend_p; root->probs[3] = rend_p;
	} else{
		calc_ans(root->left);calc_ans(root->right);
		root->probs = apply_rules(root->left->probs, root->right->probs, root->op);
	}
}
char str[100002];
int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	ll tests; scanf("%lld",&tests);
	for(int t = 0;t < tests;t++){
		scanf("%s",str);
		string expr(str);
		Node *root = parse_expr(expr);
		calc_ans(root);

		for(int i = 0;i < 4;i++){
			printf("%lld ", root->probs[i]);
		}
		printf("\n");
	}
}