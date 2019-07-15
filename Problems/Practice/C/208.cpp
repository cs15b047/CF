// C. Petya and File System  CF# 61 - 2
// Build tree of filesystem
// Do DFS to count subfolders/ files in folders etc
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;

class Node{
public:
	string id;
	map<string, Node*> adj;
	ll fold_cnt, file_cnt;
	bool file_or_fold;
	Node(string str){id = str;fold_cnt = 0;file_cnt = 0;file_or_fold = 1;} // 0 --> file 1-> fold
};

void dfs(Node* root){
	if(root->file_or_fold == 0){root->file_cnt = 1;return;}
	for(auto it: root->adj){
		dfs(it.second);
		if(it.second->file_or_fold == 1)root->fold_cnt += it.second->fold_cnt + 1;
		root->file_cnt += it.second->file_cnt;
	}
}

int main(){
	Node* root = new Node("yolo");
	vector<string> paths;string str;while(cin >> str)paths.push_back(str);
	string intmdt;
	
	for(auto it:paths){
		vector<string> folders;
		stringstream check(it);
		while(getline(check, intmdt, '\\'))folders.push_back(intmdt);
		// for(auto it2:folders)cout << it2 << " ";cout << endl;
		Node *curr = root;
		for(auto it2:folders){
			int file = 0;
			if(it2.find(".") != std::string::npos)file = 1;
			if(curr->adj.find(it2) == curr->adj.end()){
				Node *ch = new Node(it2);
				curr->adj[it2] = ch;
			}
			curr = curr->adj[it2];
			if(file == 1)curr->file_or_fold = 0;
		}
	}
	dfs(root);
	ll answer1 = 0, answer2 = 0;
	vector<Node*> vec1, vec2;
	for(auto it:root->adj)vec1.push_back(it.second);
	for(auto it:vec1){
		for(auto it2:it->adj){
			vec2.push_back(it2.second);
		}
	}
	for(auto it:vec2){
		answer1 = max(answer1, it->file_cnt);
		answer2 = max(answer2, it->fold_cnt);
	}
	cout << answer2 << " "<< answer1 << endl;
}