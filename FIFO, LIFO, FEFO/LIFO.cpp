#include <iostream>
#include "Node.h"

using namespace std;

const int MAX_NODE = 10;

class LIFO{
	private:
		Node* first;
		Node* end;
		int len;
	public:
	//Constructor
	
		LIFO(){
			first = NULL;
			end	  = NULL;
			len   = 0;
		}
		LIFO(int e){
			first = new Node(e);
			end = first;
			len = 1;	
		}
		
	//LIFO Method's
		void addNode(int e){//Adicionar Node ao LIFO
			if(!full()){
				Node* n = new Node(e);
				n->setBack(end);
				end=n;
				len++;
			}else{
				cout << "FIFO está Cheio" << endl;
			}	
		}
		
		void removeNode(){//Remover Node ao LIFO	
			if(!empty()){
				Node* aux = end;
				end = end->getBack();
				delete aux;
				len--;
			}
		}
		
		bool empty(){//Retorna se o LIFO é Vazio
			return (len == 0);
		}
		
		
		bool full(){//Retorna se o LIFO está cheio
			return (len == MAX_NODE);
		}
		
		void printALL(){
			printALL(end);
		}
		
		void printALL(Node* n){
			if(n == NULL){
				return;
			}else{
				cout << "Elemento: " << n->getElement() << endl;
				printALL(n->getBack());
			}
		}
		
	//setters
		void setFirst(Node* n){
			first = n;
		}
		void setEnd(Node* n){
			end = n;
		}
		void setLen(int i){
			len = i;
	}
	//getters
		Node* getFirst(){
			return first;
		}
		Node* getEnd(){
			return end;
		}
		int	  getLen(){
			return len;
		}
};

int main(){
	LIFO Pilha = LIFO(1);
	Pilha.addNode(2);
	Pilha.addNode(3);
	Pilha.addNode(4);
	Pilha.addNode(5);
	Pilha.addNode(6);
	Pilha.addNode(7);
	Pilha.addNode(8);
	Pilha.addNode(9);
	Pilha.addNode(10);
	Pilha.addNode(11);
	Pilha.printALL();
	cout << "-------------------" << endl;
	Pilha.removeNode();
	Pilha.removeNode();
	Pilha.removeNode();
	Pilha.addNode(11);
	Pilha.addNode(12);
	Pilha.addNode(13);
	Pilha.addNode(14);
	Pilha.printALL();
	
	
	return 1;
}
