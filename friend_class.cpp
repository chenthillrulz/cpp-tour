#include <iostream>

class Node 
{
	private: 
	int data;
	int key;

	Node *left;
	Node *right;

	friend class BinaryTree; // class BinaryTree can now access data directly
};

class BinaryTree
{
	private:
	Node *root;

	public:
	int 	find(int key);
	void insert (int key);
	bool remove (int key);
};

int BinaryTree::find(int key)
{
    // check root for NULL...
    if(root->key == key)
    {
        // no need to go through an accessor function
        return root->data;
    }
    // perform rest of find
}


int main ()
{
	std::cout << "Demonstrating friend class" << std::endl;
}
