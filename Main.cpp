#include<iostream>
#include"RedBlackTree.h"
#include "RedBlackTree.cpp"
using namespace std;

int main()
{
	RedBlackTree<int> tree;
	int nums[] = {4,7,12,15,3,5,14,18,16,17};
	//int nums[] = { 56, 12, 35, 50,39,75};
	for (int& i : nums)
	{
		tree.add(i);
		cout << i << endl;
	}

	cout << endl;
	
}