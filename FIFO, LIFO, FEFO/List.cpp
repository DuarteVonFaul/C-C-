#include "Node.h"
#include <iostream>

using namespace std;



//Pensando em como funciona uma Lista em liguagens como Python, Java, Dentre outras
//Pretendo fazer com que essa classe seja mais robusta que as anteriores
class List{
	private:
		
		Node* first;
		Node* end;
		int len;
		//Method's ADD private
		void addFirst(Node* n);
		void addEnd(Node* n);
		//Method's Remove private
		void removeFirst();
		void removeEnd();
		
	public:
		//Cosntructor
			List(){
				this->len = 0;
				this->first = NULL;
				this->end = NULL;
			}
		//List Method's
			
			//Adicionar item pela posição
			void addPos(int pos , Node* n){
				if(pos == 1){
					addFirst(n);
				}else if(pos >= len + 1){
					addEnd(n);
				}else{
					
				}
			}
			//Remover Item por posição
			void remove(int pos){
				if(pos == 1){
					removeFirst();
				}else if(pos >= len + 1){
					removeEnd();
				}else{
					
				}
			}
			
			void remove(Node* n);{}
			void search(int pos);
			void search(Node* n);
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
			int getLen(){
				return len;
			}
};
