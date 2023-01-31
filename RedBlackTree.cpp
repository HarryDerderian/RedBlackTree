#include "RedBlackTree.h"

Node* balance(Node* node)
{
	// parent is red
		// parent has no sibling
		// parent sibling is black
		// parent sibling is red
}

bool RedBlackTree::add(const int& data) 
{
	int oldAmount = totalNodes;
	rootNode = insert(rootNode, data);
	return oldAmount != totalNodes;
}

Node* RedBlackTree::insert(Node* current, const int& data)
{
	if (current == nullptr)
	{
		totalNodes++;
		return new Node(data);
	}
	else if (*current->data < data)
	{
		current->right = insert(current->right, data);
	}
	else if (*current->data > data)
	{
		current->left = insert(current->left, data);
	}
	return current;
}

bool RedBlackTree::remove(const int& data) 
{
	int oldAmount = totalNodes;
	rootNode = detach(rootNode, data);
	return oldAmount != totalNodes;
}

Node* RedBlackTree::inOrderSuccessor(Node* current)
{
	current = current->right;
	while (current->left != nullptr)
		current = current->left;
	return current;
}

Node* RedBlackTree::detach(Node* current, const int& data) 
{
	if (current == nullptr) return nullptr;
	else if (*current->data > data)
	{
		current->left = detach(current->left, data);
	}
	else if (*current->data < data)
	{
		current->right = detach(current->right, data);
	}
	else
	{   
		if (current->left && current->right)
		{
			current->data = inOrderSuccessor(current)->data;
			detach(current->right, *current->data);
		}
		else if (current->left)
		{
			totalNodes--;
			Node* temp = current;
			current = current->left;
			delete temp;
		}
		else if(current->right)
		{
			totalNodes--;
			Node* temp = current;
			current = current->right;
			delete temp;
		}
		else
		{
			totalNodes--;
			delete current;
			current = nullptr;
		}
	}

	return current;
}

int RedBlackTree::max() 
{
	if (rootNode == nullptr) return 0;

	Node* current = rootNode;
	while (current->right != nullptr)
		current = current->right;
	return *current->data;
}

int RedBlackTree::min() 
{
	if (rootNode == nullptr) return 0;

	Node* current = rootNode;
	while (current->left != nullptr)
		current = current->left;
	return *current->data;
}

bool RedBlackTree::contains(const int& data)
{
	Node* current = rootNode;
	while (current != nullptr && *current->data != data)
		current = *current->data > data ?
		current->left : current->right;

	return current != nullptr;
}

vector<int>* RedBlackTree::inOrder()
{
	vector<int>* orderedData = new vector<int>();
	inOrderTraversal(rootNode, *orderedData);
	return orderedData;
}

void RedBlackTree::inOrderTraversal(const Node* current, vector<int>& vec)
{
	if (current == nullptr) return;
	inOrderTraversal(current->left, vec);
	vec.push_back(*current->data);
	inOrderTraversal(current->right, vec);
}

int RedBlackTree::size() { return totalNodes; }