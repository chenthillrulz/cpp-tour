#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Use const instead of macros
const int NumElements = 27;
const int dataLimit = 97;

// In future I can add a parent pointer for optimization without affecting the users of BinarySearchTree
class Node 
{
	private: 
		int data;
		int key;

		Node *left;
		Node *right;
		
		Node ():left(NULL), right (NULL), data(0), key(0)
		{
		}
		
		Node (int ckey, int cdata):left(NULL), right (NULL), data(cdata), key(ckey)
		{
		}

		Node (Node &cnode)
		{
			data = cnode.data;
			key = cnode.key;
		}
		
		bool isLeaf ()
		{
			if (left == NULL && right == NULL)
				return true;
			else 
				return false;
		}

		friend class BinaryTree; // class BinaryTree can now access data directly
};

class BinaryTree
{
	private:
		Node *root;

		Node * find_suitable_parent (Node *parent, int key);
		Node * find_node (Node *node, Node **parent, int key);
		void in_order_traverse (Node *node, ostream &out);

	public:
		BinaryTree ():root(NULL)
		{
		}

		bool get_data (int key, int *data);
		void insert (int key, int data);
		~BinaryTree ();

		friend ostream & operator<< (ostream &, BinaryTree *tree);
		BinaryTree  operator+ (int key);
};


Node * BinaryTree::find_suitable_parent (Node *parent, int key)
{
	if (key < parent->key)
	{
		if (parent->left == NULL)
			return parent;
		else
			return find_suitable_parent (parent->left, key);
	}
	
	if (key >= parent->key)
	{
		if (parent->right == NULL)
			return parent;
		else
			return find_suitable_parent (parent->right, key);
	}
}

void BinaryTree::insert (int key, int data)
{
	if (root == NULL)
	{
		root = new Node (key, data);
		return;
	}

	Node *parent = find_suitable_parent (root, key);
	if (key >= parent->key)
		parent->right = new Node (key, data);
	else
		parent->left = new Node (key, data);
}

Node * BinaryTree::find_node (Node *node, Node **parent, int key)
{
	if (node->key == key)
		return node;
	else if (node->isLeaf ())
		return NULL;

	*parent = node;
	if (node->left && key < node->key)
		return find_node (node->left, parent, key);

	if (node->right && key >= node->key)
		return find_node (node->right, parent, key);

	return NULL;
}

bool BinaryTree::get_data (int key, int *data)
{
	Node *parent = NULL;
	Node *node = find_node (root, &parent, key);

	if (node)
	{
		*data = node->data;
		return true;
	}

	return false;
}

BinaryTree::~BinaryTree ()
{
	
}

BinaryTree  BinaryTree::operator+ (int key)
{
	insert(key, 1234);

	return *this;
}

void BinaryTree::in_order_traverse (Node *node, ostream &out)
{
	if (node && node->left)
		in_order_traverse (node->left, out);
	out << node->key << " ";
	if (node && node->right)
		in_order_traverse (node->right, out);
}

// 
ostream & operator<< (ostream &out, BinaryTree *tree)
{
	out << "Printing Binary Tree InOrder \n";
	tree->in_order_traverse (tree->root, out);
	out << "\n\n";
}


int main ()
{
	BinaryTree *tree = new BinaryTree ();
	int a[NumElements];

	// Initialize random seed
	srand(time(NULL));
	
	for (int i = 0; i < NumElements; i++)
		a[i] = 0;

	for (int i = 1; i < NumElements; i++) {
		a[i] = rand () % dataLimit;
		tree->insert (a[i], 799);
	} 
	
	//Tree with data inserted
	cout << tree;

	// Inserting an element using a fancy overloaded operator
	cout << "Inserting 799 using our fancy overloaded operator for fun ;) \n" << endl;
	(*tree) + 799;
	cout << tree;

	std::cout << "Demonstrating friend class and friend functions" << std::endl;
}
