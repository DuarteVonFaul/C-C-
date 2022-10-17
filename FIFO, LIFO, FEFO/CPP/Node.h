

class Node{
	
	private:
		Node* next;
		int element;
	public:
		//Constructor
		Node(int e)
		{
			this->element = e;
			this->next = NULL;
		}
		
	//getters
		Node* getNext()
		{
			return next;
		}
		
		int getElement()
		{
			return element;
		}
		
	//setters
		void setNext(Node* n)
		{
			next = n;
		}
		
		void setElement(int e)
		{
			element = e;
		}

		
	
	
};
