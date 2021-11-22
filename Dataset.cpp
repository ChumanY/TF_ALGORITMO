#include "Arbol.hpp"
#include "HashTable.hpp"
#include "Usuario.hpp"
class Dataset {

    ArbolB<Bloque> bloques;
    ArbolB<Bloque> arbol1;
    ArbolB<Bloque> arbol2;

public:
	
    
    Dataset() {
		readTSV("vgsales.csv");
	}
    // SOBRECARGA DE LOS VALORES DE DATASET A LOS ARBOLES 1, 2 Y 3
    void readTSV(string name = "", bool header = true) {
		ifstream file(name);
		string reg,HashTotal;
	    int Rank,Year;
        string Name, Platform, Genre, Publisher;
        float NA_Sales, EU_Sales, JP_Sales, Other_Sales, Global_Sales;
        string cadena;
        string r,y,na,eu,jp,other,global;
		if (header)
			getline(file, reg);
        
		while (getline(file, cadena)) {     
            stringstream archMemoria(cadena);
            getline(archMemoria,r,','); 
            getline(archMemoria,Name,',');
            getline(archMemoria,Platform,',');
            getline(archMemoria,y,','); 
            getline(archMemoria,Genre,','); 
            getline(archMemoria,Publisher,','); 
            getline(archMemoria,na,','); 
            getline(archMemoria,eu,','); 
            getline(archMemoria,jp,','); 
            getline(archMemoria,other,','); 
            getline(archMemoria,global); 

            Rank=stoi(r);
            Year=stoi(y);
            EU_Sales=stof(eu);NA_Sales=stof(na);
            JP_Sales=stof(jp);Other_Sales=stof(other);
            Global_Sales=stof(global);
            
            HashTotal=  crearHash(y) + crearHash(r);
            // cout<<HashTotal;
            Bloque e= Bloque(HashTotal, Juego(Rank,Name,Platform,Year,Genre,Publisher,NA_Sales,EU_Sales,JP_Sales,Other_Sales,Global_Sales));

            bloques.insertar(e);
            arbol1.insertar1(e);
            arbol2.insertar2(e);
  
		}
	}
    // CREACION FUNCION DE ENCRIPTACION
    string  crearHash(string dato){
        string abc="1234567890abcdefghijklmnopqrstuvwxyz";
        int cif=7;
        int longitud=dato.length();
        for (int i = 0; i < longitud; i++)
            for (int k = 0; k < 26; k++)
            {
                if(dato[i]==abc[k]){
                    if((k+cif)>25)
                        dato+=abc[k+cif-26];
                    else
                        dato+=abc[k+cif];
                    }
            }

        return dato;
            
    }
    // IMPRESION DEL ARBOL 1
	void print() {
		bloques.enOrden();
	}
    // IMPRESION DEL ARBOL 2 Y3 
    void criterios(){
        arbol1.enOrden();
        system("CLS");
        arbol2.enOrden();

    }
    
    void menu()
    {
        Dataset ds;
        HashTable<int,Usuario> *ht=new HashTable<int,Usuario>(100);	
		int seleccion;
		bool terminar =false;
		do  //garantizamos que al menos se ejecute una vez nuestro código
	    {
		cout<<endl<<"*********************** MENU ***********************"<<endl;
		cout << "(1) REGISTRO DE USUARIO" << endl;
        cout << "(2) VER USUARIOS REGISTRADOS" << endl;
        cout << "(3) REGISTRO BLOCKCHAIN" << endl;
        cout << "(4) FILTROS" << endl;
        cout << "(5) BUSQUEDA EN HASHTABLE" << endl;
        cout << "(6) 2AB CRITERIOS" << endl;
        cout << "(7) VERIFICACION HASH" << endl;
		cout << "(0) Salir" << endl;
		cin >> seleccion;
		system ("cls");
		switch (seleccion) {
		case 1:{
            HashTable<string,Usuario> *ht=new HashTable<string,Usuario>(100);
            string nombre, apellido;
            int monto;
            cout<<"Ingrese sus datos (Nombre Apellido ): "<<endl;
            getline(cin,nombre);
            getline(cin,apellido);
            cout<<"Ingrese su monto: "<<endl;
            cin>>monto;
            int cont=0;
            ht->insertar(nombre,Usuario(nombre,apellido,monto));
            cont++;
			break;
		}
        case 2: {
			ht->imprimirUsuarios();
			break;
		}
        case 3: {
			ds.print();
			break;
		}
        case 4: {
            int seleccion1;
            bool terminar1=false;
            do
            {
                cout<<endl<<"*********************** FILTROS ***********************"<<endl;
		        cout << "(1) IGUAL A" << endl;
                cout << "(2) INICIA CON" << endl;
                cout << "(3) FINALIZA CON" << endl;
                cout << "(4) ESTA CONTENIDO EN" << endl;
                cout << "(5) NO ESTA CONTENIDO EN" << endl;
                cout << "(0) Salir" << endl;
                cin >> seleccion1;
		        system ("cls");
                switch (seleccion1) {
                case 1: {
                    cin.get();
                    bloques.IgualA();
                    break;
		        }
                case 2: {
                    cin.get();
                    bloques.IniciaCon();
                    break;
		        }
                case 3: {
                    cin.get();
                    bloques.FinalizaCon();
                    break;
		        }
                case 4: {
                    cin.get();
                    bloques.EstaContenido();
                    break;
		        }
                case 5: {
                    cin.get();
                    bloques.NoEstaContenido();
                    break;
		        }
                case 0: {
			        terminar1 = true;
			        break;
		        }
		        default: {
			        cout << "Opción no válida, vuelve a intentarlo" << endl;
			        break;
		        }
                }

            }while(not terminar1);
            break;
            
		}
        case 5: {
            string name;
            cout<<"Ingrese el nombre a buscar"<<endl;
            cin.get();
            getline(cin,name);
            cout<<name;
            ht->buscarUsuario(name);
			break;
		}
        case 6: {
            criterios();
			break;
		}
        case 7: {
            int num;
            cout<<"Ingrese el valor a buscar:";
            cin>>num;
            bloques.cambio(num);
			break;
		}
		case 0: {
			terminar = true;
			break;
		}
		default: {
			cout << "Opción no válida, vuelve a intentarlo" << endl;
			break;
		}
		} //Fin de switch
	} //fin de do
	while (not terminar); //Repite el ciclo hasta presionar 0	
	}

};


auto run=[](Dataset ds){ds.menu();};

int main() {
	Dataset ds;
    run(ds);
    return 0;
  
}
