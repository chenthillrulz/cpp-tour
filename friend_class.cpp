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
		Node * find_inorder_successor_node (Node *node, Node **parent);
		bool remove_leaf (Node *node, Node *parent);
		bool remove_node_with_one_child (Node *node);
		void in_order_traverse (Node *node, ostream &out);

	public:
		BinaryTree ():root(NULL)
		{
		}

		bool get_data (int key, int *data);
		void insert (int key, int data);
		bool remove (int key);
		~BinaryTree ();

		friend ostream & operator<< (ostream &, BinaryTree *tree);
};


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
	out << "\nDone \n";
}


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

Node * BinaryTree::find_inorder_successor_node (Node *node, Node **parent)
{
	if (node->left == NULL)
		return node;

	*parent = node;
	return find_inorder_successor_node (node->left, parent);
}

bool BinaryTree::remove_leaf (Node *node, Node *parent)
{
	// In case node is a leaf node
	if (node->isLeaf ())
	{
		// its a root node
		if (parent == NULL) 
		{
			root = NULL;
			delete node;
		} else 
		{
			if (parent->left == node)
				parent->left = NULL;
			else
				parent->right = NULL;

			delete node;
		}

		return true;
	}

	return false;
}

bool BinaryTree::remove_node_with_one_child (Node *node)
{
	// In case node has only one child, replace it with the child
	if (node->left == NULL || node->right == NULL)
	{
		Node *repl;

		if (node->left == NULL)
			repl = node->right;
		else
			repl = node->left;
		
		node->key = repl->key;
		node->data = repl->data;
		
		node->left = repl->left;
		node->right = repl->right;

		delete repl;
		
		return true;
	}

	return false;
}

// Ideally we would want to return the node being delete for the users to handle 
// data, key destruction
bool BinaryTree::remove (int key)
{
	Node *parent = NULL;
	Node *node = find_node (root, &parent, key);

	if (node == NULL)
		return false; // or maybe throw an exception

	if (remove_leaf (node, parent))
		return true;
	
	if (remove_node_with_one_child (node))
		return true;

	// In case node has two children, find the inorder successor node and replace it with
	// with the current node. delete the inorder successor node	
	{
		parent = node;
		
		// finds the left most node of node->right
		Node *in_order_suc = find_inorder_successor_node (node->right, &parent); 
		
		node->key = in_order_suc->key;
		node->data = in_order_suc->data;

		if (in_order_suc->isLeaf ())
			remove_leaf (in_order_suc, parent);
		else
			remove_node_with_one_child (in_order_suc);
	}

	return true;
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

	cout << tree;
	
	int temp = a[(rand() % NumElements)];
	cout << "removing " << temp << endl;
	tree->remove (temp);
	cout << tree;

	std::cout << "Demonstrating friend class" << std::endl;
}
