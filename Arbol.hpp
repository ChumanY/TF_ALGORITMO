#include "Libreria.hpp"
#include "Bloque.hpp"
template <class T>
class Nodo {
public:
	T elemento;
	Nodo<T>* izq;
	Nodo<T>* der;
  Nodo(T elemento){
      this->elemento=elemento;
      izq=der=nullptr;

  }
	Nodo(){  }
};


template <class T>
class ArbolB {	
	Nodo<T>* raiz;	

private:
	// PRIMER ARBOL INDEXADO CON EL VALOR DEL HASH
	void _insertar(Nodo<T>*& nodo, T e) {
		if (nodo == nullptr) {
			nodo = new Nodo<T>(e);
		}
		else if (e < nodo->elemento) {
			 _insertar(nodo->izq, e);
		}
		else if (e >= nodo->elemento) {
			 _insertar(nodo->der, e);
		}
	}
	// SEGUNDO ARBOL INDEXADO CON EL VALOR DEL NOMBRE
	void _insertar1(Nodo<T>*& nodo, T e) {
	if (nodo == nullptr) {
		nodo = new Nodo<T>(e);
	}
	else if (e.getValue().getName().compare(nodo->elemento.getValue().getName())<0) { 
		 _insertar1(nodo->izq, e);
	}
	else 
	{
		 _insertar1(nodo->der, e);
	}
	}
	// TERCER ARBOL INDEXADO CON EL VALOR DEL AÑO
	void _insertar2(Nodo<T>*& nodo, T e) {
		if (nodo == nullptr) {
			nodo = new Nodo<T>(e);
		}
		else if (e.getValue().getYear() < nodo->elemento.getValue().getYear()) {
			 _insertar2(nodo->izq, e);
		}
		else 
		{
			 _insertar2(nodo->der, e);
		}
	}
	void _enOrden(Nodo<T>* nodo,Nodo<T>* padre) {
		if (nodo == nullptr) return;
		_enOrden(nodo->izq,nodo);
		cout<<"Hash Previo: "<<padre->elemento.getHash()<<endl;
		cout<<"Hash Actual: "<<nodo->elemento.getHash()<<"    "<<"Valor: "<<nodo->elemento.getValue()<<" "<<endl;
		_enOrden(nodo->der,nodo);
		
	}
	int _altura(Nodo<T>* nodo){
		if(nodo==nullptr)
			return 0;
		else{
			int izq,der;
			izq=1+_altura(nodo->izq);
			der=1+_altura(nodo->der);
			return max(izq,der);
		}
	}

	//FILTROS
	void _igualA(Nodo<T>* nodo,string letra ) {// O(14)
		if (nodo == nullptr) return; // 1
		_igualA(nodo->izq,letra);  //1
		if(letra.compare(nodo->elemento.getValue().getName())==0) // 3 + 8
		{
			cout<<"Hash Actual: "<<nodo->elemento.getHash()<<"    "<<"Valor: "<<nodo->elemento.getValue()<<" "<<endl; //8
		}
		_igualA(nodo->der,letra); //1
	}
	void _iniciaCon(Nodo<T>* nodo ,string letra){//O(17)
		if (nodo == nullptr) return; //1
		_iniciaCon(nodo->izq,letra); //1
		string cadena =nodo->elemento.getValue().getName(); //1 + 2

		if(letra.compare(cadena.substr(0,letra.length()))==0) // 3+8
			// cout<< cadena<<endl;
			cout<<"Hash Actual: "<<nodo->elemento.getHash()<<"    "<<"Valor: "<<nodo->elemento.getValue()<<" "<<endl; //8
		
		_iniciaCon(nodo->der,letra); //1

	}
	void _finalizaCon(Nodo<T>* nodo, string letra){//O(17)
		if (nodo == nullptr) return; //1
		_finalizaCon(nodo->izq,letra);//1
		string cadena =nodo->elemento.getValue().getName();//1+2

		if(letra.compare(cadena.substr(cadena.length()-letra.length(),letra.length()))==0)//3 +8
			// cout<< cadena<<endl;
			cout<<"Hash Actual: "<<nodo->elemento.getHash()<<"    "<<"Valor: "<<nodo->elemento.getValue()<<" "<<endl;//8
		
		_finalizaCon(nodo->der,letra);//1
	}
	void _estaContenido(Nodo<T>* nodo, string letra){//O(18)
		if (nodo == nullptr) return;//1
		_estaContenido(nodo->izq,letra);//1
		string cadena =nodo->elemento.getValue().getName();//1+2
		int n=cadena.find(letra);//2
		if(n<cadena.length())//2+8
			// cout<< cadena<<endl;
			cout<<"Hash Actual: "<<nodo->elemento.getHash()<<"    "<<"Valor: "<<nodo->elemento.getValue()<<" "<<endl;//8
		
		_estaContenido(nodo->der,letra);//1

	}
	void _NoEstaContenido(Nodo<T>* nodo, string letra){//O(18)
		if (nodo == nullptr) return;//1
		_NoEstaContenido(nodo->izq,letra);//1
		string cadena =nodo->elemento.getValue().getName();//1+2
		int n=cadena.find(letra);//2
		if(n>cadena.length())//2+8
			// cout<< cadena<<endl;
			cout<<"Hash Actual: "<<nodo->elemento.getHash()<<"    "<<"Valor: "<<nodo->elemento.getValue()<<" "<<endl;//8
		
		_NoEstaContenido(nodo->der,letra);//1

	}

public:
	ArbolB() {
		raiz = nullptr;
	}
	void insertar(T e) {
		 _insertar(raiz, e);
	}
	void insertar1(T e) {
		 _insertar1(raiz, e);
	}
	void insertar2(T e) {
		 _insertar2(raiz, e);
	}
	void enOrden() {
		_enOrden(raiz,raiz);
  	}

	int altura() {
		return _altura(raiz);
	}
	
	//FILTROS
	void IgualA(){
		string name;
		cin.get();
		cout<<"Ingrese el nombre: "<<endl;
		getline(cin,name);
		_igualA(raiz,name);

	}
	void IniciaCon(){
		string name;
		cout<<"Ingrese el nombre: "<<endl;
		getline(cin,name);
		_iniciaCon(raiz,name);

	}
	void FinalizaCon(){
		string name;
		cout<<"Ingrese el nombre: "<<endl;
		getline(cin,name);
		_finalizaCon(raiz,name);

	}
	void EstaContenido(){
		string name;
		cout<<"Ingrese el nombre: "<<endl;
		getline(cin,name);
		_estaContenido(raiz,name);
	}
	void NoEstaContenido(){
		string name;
		cout<<"Ingrese el nombre: "<<endl;
		getline(cin,name);
		_NoEstaContenido(raiz,name);
	}

	//CAMBIO DE VALORES DEL BLOQUE
	void cambio(int Rank){
		Nodo<T>* raiz;	
		int nuevo_valor;
		int valor =raiz->elemento.getValue().getRank();
		if(valor== Rank)
		{
			cout<<"Ingrese el ranking en que lo desee meter:";
			cin>>nuevo_valor;
			raiz->elemento.getValue().setRank(nuevo_valor);
			enOrden();
		}
	}
};

	
