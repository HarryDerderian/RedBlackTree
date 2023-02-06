#include "RedBlackTree.h"
// Harry Derderian (O.C.C.)

template <typename T>
Node<T>* RedBlackTree<T>::recolor(Node<T>* parent)
{
	parent->color = 'b';
	parent->right->color = 'r';
	parent->left->color = 'r';
	return parent;
}

template <typename T>
Node<T>* RedBlackTree<T>::singleRight(Node<T>* root)
{
	Node<T>* temp = root->left;
	root->left = temp->right; 
	temp->right = root;
	return temp;
}

template <typename T>
Node<T>* RedBlackTree<T>::singleLeft(Node<T>* root)
{
	Node<T>* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}

template <typename T>
Node<T>* RedBlackTree<T>::doubleRightLeft(Node<T>* root)
{
	root->right = singleRight(root->right);
	return singleLeft(root);
}

template <typename T>
Node<T>* RedBlackTree<T>::doubleLeftRight(Node<T>* root)
{
	root->left = singleLeft(root->left);
	return singleRight(root);
}

template <typename T>
Node<T>* RedBlackTree<T>::rotateRecolor(Node<T>* grandParent,
										Node<T>* parent, Node<T>* child) 
{
	if (*grandParent->data < *child->data)  // right leaning 
		return *parent->data < *child->data ?
			recolor(singleLeft(grandParent)) : recolor(doubleRightLeft(grandParent));
	
	else // left leaning
		return *parent->data > *child->data ?
			recolor(singleRight(grandParent)) : recolor(doubleLeftRight(grandParent));
}

template <typename T>
Node<T>* RedBlackTree<T>::balance(Node<T>* grandParent, const T& data)
{
	Node<T>* parent = nullptr;
	Node<T>* siblingOfParent = nullptr;
	if (*grandParent->data > data) {
		parent = grandParent->left;
		siblingOfParent = grandParent->right;
	}
	else {
		parent = grandParent->right;
		siblingOfParent = grandParent->left;
	}
	const T& parentData = *parent->data;
	if (parent->color == 'r' && parentData != data){
		Node<T>* child = parentData > data ? parent->left : parent->right;
		if (child->color == 'r'){
			if (siblingOfParent == nullptr || siblingOfParent->color == 'b') 
				grandParent = rotateRecolor(grandParent,parent,child);
			else {
				if (grandParent != rootNode) grandParent->color = 'r';
				parent->color = 'b';
				siblingOfParent->color = 'b';
			}
		}
	} return grandParent;
}

template <typename T>
bool RedBlackTree<T>::add(const T& data)
{
	if (rootNode == nullptr) {
		rootNode = new Node<T>(data);
		rootNode->color = 'b';
		totalNodes++;
		return true;
	}
	int oldAmount = totalNodes;
	rootNode = insert(rootNode, data);
	return oldAmount != totalNodes;
}

template <typename T>
Node<T>* RedBlackTree<T>::insert(Node<T>* current, const T& data)
{
	if (current == nullptr){
		totalNodes++;
		return new Node<T>(data);
	} else if (*current->data < data){
		current->right = insert(current->right, data);
	} else if (*current->data > data){
		current->left = insert(current->left, data);
	}
	return current->color == 'b' ? balance(current, data) : current;
}

template <typename T>
bool RedBlackTree<T>::remove(const T& data)
{
	int oldAmount = totalNodes;
	rootNode = detach(rootNode, data);
	return oldAmount != totalNodes;
}

template <typename T>
Node<T>* RedBlackTree<T>::inOrderSuccessor(Node<T>* current)
{
	current = current->right;
	while (current->left != nullptr)
		current = current->left;
	return current;
}

template <typename T>
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
			Node<T>* temp = current;
			current = current->left;
			delete temp;
		}
		else if (current->right)
		{
			totalNodes--;
			Node<T>* temp = current;
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

template <typename T>
T RedBlackTree<T>::max(){
	if (rootNode == nullptr) return 0; // maybe throw exception or return nullptr

	Node<T>* current = rootNode;
	while (current->right != nullptr)
		current = current->right;
	return *current->data;
}

template <typename T>
T RedBlackTree<T>::min(){
	if (rootNode == nullptr) return 0;  // maybe throw exception or return nullptr

	Node<T>* current = rootNode;
	while (current->left != nullptr)
		current = current->left;
	return *current->data;
}

template <typename T>
bool RedBlackTree<T>::contains(const T& data){
	Node<T>* current = rootNode;
	while (current != nullptr && *current->data != data)
	current = *current->data > data ? current->left : current->right;

	return current != nullptr;
}

template <typename T>
vector<T>* RedBlackTree<T>::inOrder(){
	vector<T>* orderedData = new vector<T>();
	inOrderTraversal(rootNode, *orderedData);
	return orderedData;
}

template <typename T>
void RedBlackTree<T>::inOrderTraversal(const Node<T>* current, 
												vector<T>& vec){
	if (current == nullptr) return;
	inOrderTraversal(current->left, vec);
	vec.push_back(*current->data);
	inOrderTraversal(current->right, vec);
}
template <typename T>
int RedBlackTree<T>::size() { return totalNodes; }