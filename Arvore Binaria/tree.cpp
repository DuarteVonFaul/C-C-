#include <iostream>
#include "Node.h"

using namespace std;

class Tree{
	
	
	private:
		Node *root;
		
		
	public:
		
		Tree(int e){
			Node n = Node(e);
			root = &n;
		}
		
		Tree(){
			root = NULL;
		}
		
		//addChild Node -----------------------------------
		void addChild(Node* n, Node* child){
			if(n->getElement() < child->getElement()){
				cout << "Direita" << endl;
				if(n->getRight() == NULL){
					cout << "ADD Direita" << endl;
					child->setRoot(n);
					n->setRight(child);
				}else{
					cout << "Continuar" << endl;
					addChild(n->getRight(), child);
					return;
				}
			}else if (n->getElement() > child->getElement()){
				cout << "Esquerda" << endl;
				if(n->getLeft() == NULL){
					cout << "ADD Esquerda" << endl;
					child->setRoot(n);
					n->setLeft(child);	
				}else{
					cout << "Continuar" << endl;
					addChild(n->getLeft(), child);
					return;
				}	
			}else{
				cout << "Elemento já existe na Arvore" << endl;
				return;
			}
		}
		
		void addChild(int e){
			Node n = Node(e);
			if(root != NULL){
				cout << "Elemento: " << n.getElement() << " Elemento Root: " << root->getElement() << endl;
				addChild(root,&n);
			}else{
				cout << "ROOT: " << e << endl;
				this->root = &n;
			}
		}
		
		//Search Node -----------------------------------
		Node* search(Node* n, int e){
			if(n->getElement() < e){
				if(n->getRight() == NULL){
					return NULL;
				}else{
					search(n->getRight(), e);
				}
			}else if (n->getElement() > e){
				if(n->getLeft() == NULL){
					return NULL;
				}else{
					search(n->getLeft(), e);
				}	
			}else{
				return n;
			}
		}
		
		Node* search(int e){
			return search(this->root, e);
		}
		
		//Remove Node -----------------------------------	
		void remove(Node* n){
			if(n->getLeft() != NULL){
				if(n->getRight() != NULL){
					addChild(n->getLeft(), n->getRight());
					if(n->getRoot() != NULL){
						if(n->getRoot()->getElement() > n->getElement() ){
							n->getRoot()->setRight(n->getLeft());
						}else{
							n->getRoot()->setLeft(n->getLeft());
						}
					}else{
						this->root = n->getLeft();
					}
				}
			}else if(n->getRight() != NULL){
				if(n->getRoot() != NULL){
					if(n->getRoot()->getElement() > n->getElement() ){
						n->getRoot()->setRight(n->getRight());
					}else{
						n->getRoot()->setLeft(n->getRight());
					}
				}else{
					this->root = n->getLeft();
				}
			}else{
				if(n->getRoot() != NULL){
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
	
	Tree t = Tree();
	t.addChild(6);
	t.addChild(8);
	t.addChild(7);
	t.addChild(9);
	
	
	
	
	return 0;
}
