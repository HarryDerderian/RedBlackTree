#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include<vector>
using namespace std;

class Node 
{
public:
	const int* data;
	Node* right;
	Node* left;
	char color; // red: 1, black: 0
	Node() : data(nullptr), right(nullptr),
		left(nullptr), color(1) {};
	Node(const int& element) : data(&element), 
		right(nullptr), left(nullptr), color(1) {};

	~Node() {};
};

class RedBlackTree
{
public:
	RedBlackTree() : totalNodes(0), rootNode(nullptr) {};
	RedBlackTree(const int& data) : totalNodes(1), 
				rootNode(new Node(data)) {};
	bool contains(const int&);
	bool add(const int&);
	bool remove(const int&);
	int max();
	int min();
	int size();
	vector<int>* inOrder();

private:
	int totalNodes;
	Node* rootNode;
	Node* insert(Node*, const int&);
	void inOrderTraversal(const Node*, vector<int>&);
	Node* inOrderSuccessor(Node*);
	Node* detach(Node*, const int&);
	Node* balance(Node*);
};
#endif
