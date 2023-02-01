#include<iostream>
#include"RedBlackTree.h"

using namespace std;

int main()
{
	RedBlackTree<int>* tree1 = new RedBlackTree<int>();
	cout << tree1->size();
	/*for (int i = 0; i < 500; i++)
	{
		int* temp = new int(i);
		tree1->add(*temp); 
	}
	for (int i = 0; i > -500; i--)
	{
		int* temp = new int(i);
		tree1->add(*temp);
	}
	
	cout << boolalpha << tree1->contains(900) << endl;
	tree1->remove(273);
	
	cout <<  tree1->contains(273);
	cout << boolalpha << tree1->contains(0) << endl;
		vector<int>* vec = tree1->inOrder();
		for (auto iter = vec->begin(); iter != vec->end(); iter++)
		{
			cout << *iter << endl;
		}*/
		
}