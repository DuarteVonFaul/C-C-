

class Node{
	
	private:
		Node* next;
		Node* back;
		int element;
	public:
		//Constructor
		Node(int e)
		{
			this->element = e;
			this->next = NULL;
			this->back = NULL;
		}
		
	//getters
		Node* getBack()
		{
			return back;
		}
		Node* getNext()
		{
			return next;
		}
		
		int getElement()
		{
			return element;
		}
		
	//setters
		void setBack(Node* n)
		{
			back = n;
		}
		void setNext(Node* n)
		{
			next = n;
		}
		
		void setElement(int e)
		{
			element = e;
		}

		
	
	
};
