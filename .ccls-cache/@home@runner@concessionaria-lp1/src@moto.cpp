#include "moto.h"
#include "veiculo.h"
#include <string>

moto::moto(){};

moto::moto(string concessionaria, string marca, int p, string cha, int ano, string Modelo){
	setconcessionaria(concessionaria);
	setmarca(marca);
	setpreco(p);
	setchassi(cha);
	setanoF(ano);
	setModelo(Modelo);
}

void moto::setModelo(string a){
	Modelo = a;
};

string moto::getModelo(){
	return Modelo;
};


