#include <iostream>
#include "Node.h"

using namespace std;

class Tree{
	
	
	private:
		Node *root;
		
		
	public:
		
		Tree(int e){
			Node* n = new Node(e);
			root = n;
		}
		//-----------------------addChild Node-----------------------------
		void addChild(int e){
			Node* n = new Node(e);
			addChild(getRoot(), n);
		}
		
		void addChild(Node* n, Node* Child){
			cout << "___APPEND___" << endl;
			cout << "ROOT " << n->getElement() << " CHILD " << Child->getElement() << endl;
			if(n->getElement() < Child->getElement()){
				cout << "Entrou Esquerda" <<endl;
				if(n->getLeft() == NULL){
					cout <<"Add Esquerda" <<endl;
					Child->setRoot(n);
					n->setLeft(Child);
				}else{
					cout << "Continua" << endl;
					addChild(n->getLeft(), Child);
				}
			}
			else if(n->getElement() > Child->getElement()){
				cout << "Entrou Direita" <<endl;
				if(n->getRight() == NULL){
					cout <<"Add Direita" <<endl;
					Child->setRoot(n);
					n->setRight(Child);
				}else{
					cout << "Continua" << endl;
					addChild(n->getRight(), Child);
				}
			}
			else{
				cout << "Elemento já existe" <<endl;
				return;
			}
		}
		//----------------------------------------Search Node -----------------------------------
		Node* search(Node* n, int e){
			cout << "___BUSCA___" << endl;
			if(n->getElement() > e){
				cout << "Entrei direita" << endl;
				if(n->getRight() == NULL){
					cout << "Element não existe" << endl;
					return NULL;
				}else{
					cout << "Continuar" << endl;
					search(n->getRight(), e);
				}
			}else if (n->getElement() < e){
				cout << ("Entrei esquerda") << endl;
				if(n->getLeft() == NULL){
					cout << "Element não existe" << endl;
					return NULL;
				}else{
					cout << "Continuar" << endl;
					search(n->getLeft(), e);
				}	
			}else{
				cout << "Encontrei " << n->getElement() << endl;
				return n;
			}
		}
		
		Node* search(int e){
			return search(this->root, e);
		}
		
		//--------------------------------------Remove Node -----------------------------------	
		void remove(Node* n){
			cout << "___REMOVE___" << endl;
			if(n->getLeft() != NULL){
				cout << "EXIST ESQUERDA" << endl;
				if(n->getRight() != NULL){
					cout << "EXIST DIREITA" << endl;
					addChild(n->getLeft(), n->getRight());
					if(n->getRoot() != NULL){
						cout << "EXIST ROOT" << endl;
						if(n->getRoot()->getElement() > n->getElement() ){
							n->getRoot()->setRight(n->getLeft());
						}else{
							n->getRoot()->setLeft(n->getLeft());
						}
					}else{
						cout << "NOT EXIST ROOT" << endl;
						this->root = n->getLeft();
					}
				}else{
					cout << "NOT EXIST DIREITA" << endl;
					if(n->getRoot() != NULL){
						cout << "EXIST ROOT" << endl;
						if(n->getRoot()->getElement() > n->getElement() ){
							n->getRoot()->setRight(n->getLeft());
						}else{
							n->getRoot()->setLeft(n->getLeft());
						}
					}else{
						cout << "NOT EXIST ROOT" << endl;
						this->root = n->getLeft();
					}
				}
			}else if(n->getRight() != NULL){
				cout << "NOT EXIST ESQUERDA" << endl;
				cout << "EXIST DIREITA" << endl;
				if(n->getRoot() != NULL){
					cout << "EXIST ROOT" << endl;
					if(n->getRoot()->getElement() > n->getElement() ){
						n->getRoot()->setRight(n->getRight());
					}else{
						n->getRoot()->setLeft(n->getRight());
					}
				}else{
					cout << "NOT EXIST ROOT" << endl;
					this->root = n->getLeft();
				}
			}else{
				cout << "NOT EXIST ESQUERDA" << endl;
				cout << "NOT EXIST DIREITA" << endl;
				if(n->getRoot() != NULL){
					cout << "EXIST ROOT" << endl;
					if(n->getRoot()->getElement() > n->getElement() ){
						n->getRoot()->setRight(NULL);
					}else{
						n->getRoot()->setLeft(NULL);
					}
				}
			}
		}
		
		void remove(int e){
			Node* n = search(e);
			if(n!= NULL){
				remove(n);
			}else{
				cout << "Elemento não existe" << endl;
			}
		}
		//------------------------------------------------
		//Getters
			Node* getRoot(){
				return this->root;
			}
		//Setters
			Node* setRoot(Node* n){
				this->root = n;
			}
};




int main(){
	
	Tree t = Tree(6);
	cout << t.getRoot()->getElement() << endl;
	cout << "------SOLICITACAO-------" << endl;
	t.addChild(8);
	cout << "------SOLICITACAO-------" << endl;
	t.addChild(7);
	cout << "------SOLICITACAO-------" << endl;
	t.addChild(9);
	cout << "------SOLICITACAO-------" << endl;
	t.remove(8);
	cout << "------SOLICITACAO-------" << endl;
	t.addChild(8);
	
	
	
	
	return 0;
}
