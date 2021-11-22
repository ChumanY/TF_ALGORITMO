#include "Libreria.hpp"
template<typename T1, typename T2>
class HashEntidad {
private:	
	T1 key;
	T2 value;
public:
	HashEntidad(T1 key, T2 value): key(key), value(value){}
    T1 getKey() { return key; }
	T2& getValue() { return value; }
};

template<typename T1, typename T2>
class HashTable{
    int capacidad;
	HashEntidad<T1,T2>** ht;
    public:
    HashTable(int capacidad = 100)  
	{
        this->capacidad=capacidad;
        ht = new HashEntidad<T1, T2>* [capacidad];
        for (int i = 0; i < capacidad; ++i) {
			ht[i] = nullptr;
		}

	}
	// TRANSFORMACION DEL NOMBRE EN BIN PARA LA BUSQUEDA
	long long Key_Name(string word){
		long long key=0;
		for(int i=0;i<word.size();i++){
			key+=int(word.at(i));
		}
		return key;
	}
	// INSERTAR EN EL HASH TABLE Y EN UN TXT
    void insertar(T1 key, T2 value) 
	{
		ofstream Esc;
		int base, step, hash;
		base = Key_Name(key) % capacidad;
		hash = base;
		step = 0;
		while (ht[hash] != nullptr)
		{
			hash = (base + step) % capacidad;
		}
        ht[hash] = new HashEntidad<T1, T2>(key, value);
		cout<<ht[hash]->getValue();
		insertarUsuario(Esc,ht[hash]->getValue().GetNombre(),ht[hash]->getValue().GetApellido(),ht[hash]->getValue().GetMonto());
    }
	// BUSCAR DENTRO DEL HASH
    void buscarUsuario(string key){ 
		int base, step, hash;
		base = Key_Name(key) % capacidad;
		hash = base;
		step = 0;
		
		// while (ht[hash] != nullptr)
		// {
		// 	cout<<base;
		// 	hash = (base + step) % capacidad;
		// }
		
		cout<<hash;
		HashEntidad<T1, T2>* elemento=ht[hash];
		cout<<elemento->getValue();
	}
	
	// *************************** REGISTRO DE USUARIOS  *************************** //
	
	// VERIFICACION DE USUARIO REGISTRADO
    bool usuario_registrado(string nombre, string apellido) {
		ifstream leer("Personas.txt", ios::in);
		string nombreU, apellidoU;
		leer >> nombreU;
		while (!leer.eof()) {
			leer >> apellidoU;
			if(nombreU==nombre && apellidoU ==apellido){
				leer.close();
				cout << "Usuario ya registrado"<<endl;	
				return false;
			}
			leer >> nombreU;
		}
		return true;
	}
    // REGISTRO DE USUARIO EN UN TXT
	void insertarUsuario(ofstream &es,string nombre, string apellido, int monto){
        es.open("Personas.txt", ios::out | ios::app);
        if(usuario_registrado(nombre, apellido)==1)
			es << nombre << " " << apellido <<" "<<monto<<" "<<endl;
		es.close();
    }
	// LECTURA DE USUARIOS DEL TXT
    void registro_usuarios(ifstream &lec) {
		system("cls");
		string nombre, apellido;
        string monto;
		lec.open("Personas.txt", ios::in);
		cout << "-------------Personas registradas-------------"<<endl<<endl;
		//lec >> nombre;
		while (!lec.eof()) {
			lec >> apellido;
            lec>>monto;
			cout << "Nombre---------------------" << nombre << endl;
			cout << "Apellido-------------------" << apellido << endl;
            cout<<  "Monto----------------------" <<monto<<endl;
			cout << endl;
			lec >> nombre;
		}	
		lec.close();
	}
	// IMPRESION DE LOS USUARIOS REGISTRADOS
    void imprimirUsuarios() 
    {
		ifstream Lec;
		registro_usuarios(Lec);

	}
	
	// ***************************************************************************** //
    
	void Transaccion(int modificacion){
		int monto;
		char v;
		cout<<"Desea hacer una transaccion: (s/n) ";
		cin>>v;
		if(v=='s'){
			monto=ht->getValue().GetMonto();	
			monto-=modificacion;
			cout<<ht->getValue().SetMonto();	
		}
		
			
	}


};
