#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include<vector>
using namespace std;

template <typename T>
class Node
{
	const T* data;
	char color; // red: r, black: b
	Node<T>* right;
	Node<T>* left;
	Node() : data(nullptr), right(nullptr),
		left(nullptr), color('r') {};
	Node(const T& element) : data(&element),
		right(nullptr), left(nullptr), color('r') {};
	~Node() {};
	template <typename T>
	friend class RedBlackTree;
};

template <typename T>
class RedBlackTree
{
public:
	RedBlackTree() : totalNodes(0), rootNode(nullptr) {};
	RedBlackTree(const T& data) : totalNodes(1),
		rootNode(new Node<T>(data)) {};
	bool contains(const T&);
	bool add(const T&);
	bool remove(const T&);
	T max();
	T min();
	int size();
	vector<T>* inOrder();

private:
	int totalNodes;
	Node<T>* rootNode;
	Node<T>* insert(Node<T>*, const T&);
	Node<T>* recolor(Node<T>*);
	Node<T>* inOrderSuccessor(Node<T>*);
	Node<T>* detach(Node<T>*, const T&);
	Node<T>* balance(Node<T>*, const T&);
	Node<T>* singleRight(Node<T>*);
	Node<T>* singleLeft(Node<T>*);
	Node<T>* doubleRightLeft(Node<T>*);
	Node<T>* doubleLeftRight(Node<T>*);
	Node<T>* rotateRecolor(Node<T>*,Node<T>*, Node<T>*);
	void inOrderTraversal(const Node<T>*, vector<T>&);
};
#endif