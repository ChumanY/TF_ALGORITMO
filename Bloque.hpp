#include "Juego.hpp"
class Bloque {
private:
	string hash;
	Juego value;
public:
	Bloque(string hash, Juego value): hash(hash), value(value) {}
	Bloque(){ }
	string getHash() { return hash; }
	Juego& getValue() { return value; }
	// SOBRECARGA DE OPERADORES
	bool operator<(const Bloque& b) {
		return this->hash < b.hash;
	}
	bool operator>=(const Bloque& b) {
		return this->value >= b.value;
	}
	bool operator>(const Bloque& b) {
		return this->hash > b.hash;
	}
    bool operator==(const Bloque& b) {
		return this->hash == b.hash;
	}
	
	friend ostream& operator << (ostream& s, const Bloque& b){
        s<<b.hash<<" "<<b.value;
        return s;
    }

};

