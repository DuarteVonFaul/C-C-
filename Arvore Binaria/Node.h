#include <iostream>

class Node{
	
	private:
		Node* root;
		Node* left;
		Node* right;
		int element;
	public:
		//Constructor
		Node(int e)
		{
			this->element = e;
			this->root    = NULL;
			this->left    = NULL;
			this->right   = NULL;
		}
		
	//getters
		Node* getLeft()
		{
			return this->left;
		}
		Node* getRight()
		{
			return this->right;
		}
		
		Node* getRoot()
		{
			return this->root;
		}
		
		int getElement()
		{
			return this->element;
		}
		
	//setters
		void setLeft(Node* n)
		{
			this->left = n;
		}
		void setRight(Node* n)
		{
			this->right = n;
		}
		
		Node* setRoot(Node* n)
		{
			this->root = n;
		}
		
		void setElement(int e)
		{
			this->element = e;
		}

		
	
	
};
