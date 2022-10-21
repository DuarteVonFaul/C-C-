#include <iostream>


using namespace std;

//Diferente do FIFO e LIFO o FEFO precisa de parametros mais complexos para definir quem vai sair
//Esses parametros eu coloquei como Prioridade e Posição
//Quem tiver a maior prioridade e a menor posição sai primeiro

class Entity{
	private:
		int priority;
		int pos;
		Entity* next;
		Entity* back;
		int element;
	
	public:
		
		Entity(int p, int e, int pos){
			this->priority = p;
			this->pos	   = pos;
			this->setBack(NULL);
			this->setNext(NULL);
			this->setElement(e);
		}
		
		//getters
			int getPos(){
				return pos;
			}
			
			int getPriority(){
				return priority;
			}
			Entity* getBack()
			{
				return back;
			}
			Entity* getNext()
			{
				return next;
			}
			
			int getElement()
			{
				return element;
			}
		//setters
			int setPos(int p){
				pos = p;
			}
			
			int setPriority(int p){
				priority = p;
			}
			void setBack(Entity* n)
			{
				back = n;
			}
			void setNext(Entity* n)
			{
				next = n;
			}
			
			void setElement(int e)
			{
				element = e;
			}	
};


const int MAX_Entity = 10;

class FEFO{
	private:
		Entity* first;
		Entity* end;
		int len;
	public:
	//Constructor
	
		FEFO(){
			first = NULL;
			end	  = NULL;
			len   = 0;
		}
		FEFO(int e, int p){
			first = new Entity(p,e,1);
			end = first;
			len = 1;	
		}
		
	//FEFO Method's
		void addEntity(int e, int p){//Adicionar Entity do FEFO
			if(!full()){
				Entity* n = new Entity(p, e, len + 1);
				n->setBack(end);
				end->setNext(n);
				end=n;
				len++;
			}else{
				cout << "FIFO está Cheio" << endl;
			}	
		}
		//-------------------------------------------------------------------------
		/*
		Tive um Pequeno proble no desenvolvimento da funcionalidade de remover uma entidade por ela estava muito robusta
		e de alta complexidade então a solução que encontrei foi Dividir para conquistar, assim fiz uma funcionalidade
		que analisa os pesos das entidades e me retorna o que está em maior condição de ser removida e logo em seguida
		uma outra que analisa a situação dela em relação às outras e a remove de uma maneira que não perde conexão das outras
		entidades que ainda esperam a serem removidas
		*/
		void removeEntity(){//Remover Entity do FEFO	
			Entity* entity = this->removeEntity(this->end, this->end->getBack());
			
			if(entity->getNext() == NULL){
				cout << "NULL Next"  << endl;
				entity->getBack()->setNext(NULL);
				end = entity->getBack();

				
				
			}else if(entity->getBack() == NULL){
				cout << "NULL Back"  << endl;
				entity->getNext()->setBack(NULL);
				first = entity->getNext();

				
			}else{
				cout << "Not Null" << endl;
				entity->getBack()->setNext(entity->getNext());
				entity->getNext()->setBack(entity->getBack());

			}
			
			delete entity;
			len--;
			return;
		}
		
		Entity* removeEntity(Entity* entity, Entity* back_entity){//Remover Entity do FEFO	
			if(!empty()){
				if(back_entity != NULL){
					cout << "Aqui" << endl;
					if(entity->getPriority() < back_entity->getPriority()){
						cout << "Priority menor" << endl;	
						this->removeEntity(back_entity,back_entity->getBack());
					}
					else if(entity->getPriority() == back_entity->getPriority()){
						cout << "Priority Igual" << endl;
						if(entity->getPos() > back_entity->getPos()){
							cout << "Pos maior" << endl;
							return this->removeEntity(back_entity,back_entity->getBack());
						}
					}
					return this->removeEntity(entity,back_entity->getBack());
				}
				return entity;
			}
		}
		//-----------------------------------------------------------------------------------
		bool empty(){//Retorna se o FEFO é Vazio
			return (len == 0);
		}
		
		
		bool full(){//Retorna se o FEFO está cheio
			return (len == MAX_Entity);
		}
		
		void printALL(){
			printALL(first);
		}
		
		void printALL(Entity* n){
			if(n == NULL){
				return;
			}else{
				cout << " Elemento: " << n->getElement() 
					 << " Prioridade " << n->getPriority() 
					 << " Posição: " << n->getPos()  
					 << endl;
				printALL(n->getNext());
			}
		}
		
	//setters
		void setFirst(Entity* n){
			first = n;
		}
		void setEnd(Entity* n){
			end = n;
		}
		void setLen(int i){
			len = i;
	}
	//getters
		Entity* getFirst(){
			return first;
		}
		Entity* getEnd(){
			return end;
		}
		int	  getLen(){
			return len;
		}
};


int main(){
	FEFO f = FEFO(1,3);
	f.addEntity(2,4);
	f.addEntity(3,3);
	f.addEntity(4,3);
	f.addEntity(5,4);
	f.printALL();
	cout << "-----------------" << endl;
	f.removeEntity();
	f.printALL();
	cout << "-----------------" << endl;
	f.removeEntity();
	f.printALL();
	cout << "-----------------" << endl;
	f.removeEntity();
	f.printALL();
	cout << "-----------------" << endl;
	
	
	
	
	
	return 1;
}


