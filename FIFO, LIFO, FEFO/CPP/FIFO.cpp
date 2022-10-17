#include <iostream>
#include "Node.h"

using namespace std;

const int MAX_NODE = 10;

class FIFO{
	private:
		Node* first;
		Node* end;
		int len;
	public:
	//Constructor
	
		FIFO(){
			first = NULL;
			end	  = NULL;
			len   = 0;
		}
		FIFO(int e){
			first = new Node(e);
			end = first;
			len = 1;	
		}
		
	//FIFO Method's
		void addNode(int e){//Adicionar Node ao FIFO
			if(!full()){
				Node* n = new Node(e);
				end->setNext(n);
				end=n;
				len++;
			}else{
				cout << "FIFO está Cheio" << endl;
			}	
		}
		
		void removeNode(){//Remover Node ao FIFO	
			if(!empty()){
				Node* aux = first;
				first = first->getNext();
				delete aux;
				len--;
			}
		}
		
		bool empty(){//Retorna se o FIFO é Vazio
			return (len == 0);
		}
		
		
		bool full(){//Retorna se o FIFO está cheio
			return (len == MAX_NODE);
		}
		
		void printALL(){
			printALL(first);
		}
		
		void printALL(Node* n){
			if(n == NULL){
				return;
			}else{
				cout << "Elemento: " << n->getElement() << endl;
				printALL(n->getNext());
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
	FIFO fila = FIFO(1);
	fila.addNode(2);
	fila.addNode(3);
	fila.addNode(4);
	fila.addNode(5);
	fila.addNode(6);
	fila.addNode(7);
	fila.addNode(8);
	fila.addNode(9);
	fila.addNode(10);
	fila.addNode(11);
	fila.printALL();
	cout << "-------------------" << endl;
	fila.removeNode();
	fila.removeNode();
	fila.removeNode();
	fila.addNode(11);
	fila.addNode(12);
	fila.addNode(13);
	fila.addNode(14);
	fila.printALL();
	
	
	return 1;
}
	

