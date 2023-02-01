#include "RedBlackTree.h"

template <class T>
Node<T>* RedBlackTree<T>::balance(Node<T>* node)
{
	// parent is red
		// parent has no sibling
		// parent sibling is black
		// parent sibling is red
	return rootNode;
}

template <class T>
bool RedBlackTree<T>::add(const T& data)
{
	int oldAmount = totalNodes;
	rootNode = insert(rootNode, data);
	return oldAmount != totalNodes;
}

template <class T>
Node<T>* RedBlackTree<T>::insert(Node<T>* current, const T& data)
{
	if (current == nullptr)
	{
		totalNodes++;
		return new Node<T>(data);
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

template <class T>
bool RedBlackTree<T>::remove(const T& data)
{
	int oldAmount = totalNodes;
	rootNode = detach(rootNode, data);
	return oldAmount != totalNodes;
}

template <class T>
Node<T>* RedBlackTree<T>::inOrderSuccessor(Node<T>* current)
{
	current = current->right;
	while (current->left != nullptr)
		current = current->left;
	return current;
}
/*
template <class T>
Node<T>* RedBlackTree<T>::detach(Node<T>* current, const T& data)
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
		else if (current->right)
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
}*/

template <class T>
T RedBlackTree<T>::max()
{
	if (rootNode == nullptr) return 0; // maybe throw exception or return nullptr

	Node* current = rootNode;
	while (current->right != nullptr)
		current = current->right;
	return *current->data;
}

template <class T>
T RedBlackTree<T>::min()
{
	if (rootNode == nullptr) return 0;  // maybe throw exception or return nullptr

	Node* current = rootNode;
	while (current->left != nullptr)
		current = current->left;
	return *current->data;
}

template <class T>
bool RedBlackTree<T>::contains(const T& data)
{
	Node<T>* current = rootNode;
	while (current != nullptr && *current->data != data)
		current = *current->data > data ?
		current->left : current->right;

	return current != nullptr;
}

template <class T>
vector<T>* RedBlackTree<T>::inOrder()
{
	vector<T>* orderedData = new vector<int>();
	inOrderTraversal(rootNode, *orderedData);
	return orderedData;
}

template <class T>
void RedBlackTree<T>::inOrderTraversal(const Node<T>* current, vector<T>& vec)
{
	if (current == nullptr) return;
	inOrderTraversal(current->left, vec);
	vec.push_back(*current->data);
	inOrderTraversal(current->right, vec);
}
template <class T>
int RedBlackTree<T>::size() { return totalNodes; }


