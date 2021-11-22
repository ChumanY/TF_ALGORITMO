#include "Libreria.hpp"
class Usuario
{
    string nombre, apellido;
    int monto;
public:
    Usuario(string nombre="",string apellido="",int monto=0):nombre(nombre),apellido(apellido),monto(monto){}
 
    friend ostream& operator << (ostream& s, const Usuario& u){
        s<<u.nombre<<" "<<u.apellido<<" "<<u.monto<<endl;
        return s;
    }
    bool operator<(const Usuario& u) {
		return this->monto < u.monto;
	}
    bool operator>=(const Usuario& u) {
		return this->monto >= u.monto;
	}
	bool operator>(const Usuario& u) {
		return this->monto > u.monto;
	}
    bool operator==(const Usuario& u) {
		return this->monto == u.monto;
	}
  
    string GetNombre(){return nombre;}
    string GetApellido(){return apellido;}
    int GetMonto(){return monto;}

    string SetNombre(string nombre){return this->nombre=nombre;}
    string SetApellido(string apellido){return this->apellido=apellido;}
    int SetMonto(int monto){return this->monto=monto;}

};