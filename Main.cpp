#include<iostream>
#include"RedBlackTree.h"
#include "RedBlackTree.cpp"
using namespace std;

int main()
{
	
	RedBlackTree<string> tree;
	string strings[5] = { "HARRY", "ZAC", "ADRIAN", "JEESE", "JASMINE" };
	for (string& s : strings)
	{
		tree.add(s);
	}
	string name = "TOM";
	string name2 = "TIM";
	tree.add(name);
	tree.add(name2);
	cout << tree.size() << endl;
	vector<string>* vec = tree.inOrder();
	for (auto iter = vec->begin(); iter != vec->end(); iter++)
	{
		cout << *iter << endl;
	}
	

	cout << "\nintegers\n\n";
	RedBlackTree<int> tree2;
	int nums[5] = {132,324,523,5,32487};
	for (int& s : nums)
	{
		tree2.add(s);
	}

	vector<int>* vec2 = tree2.inOrder();
	for (auto iter = vec2->begin(); iter != vec2->end(); iter++)
	{
		cout << *iter << endl;
	}

}