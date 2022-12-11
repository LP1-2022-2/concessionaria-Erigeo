#include "carro.h"

carro::carro(){};

carro::carro(string concessionaria, string marca, int p, string cha, int ano, string tipomotor ){
	setconcessionaria(concessionaria);
	setmarca(marca);
	setpreco(p);
	setchassi(cha);
	setanoF(ano);
	setcarro(tipomotor);
};

void carro::setcarro(string a){
	tipoMotor = a;
};

string carro::getcarro(){
	return tipoMotor;
};