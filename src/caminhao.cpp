#include "caminhao.h"

caminhao::caminhao(){};

caminhao::caminhao(string concessionaria, string marca, int p, string cha, int ano, string tipocarga ){
	setconcessionaria(concessionaria);
	setmarca(marca);
	setpreco(p);
	setchassi(cha);
	setanoF(ano);
	setcaminhao(tipocarga);
}

void caminhao::setcaminhao(string a){
	tipoCarga = a;
};

string caminhao::getcaminhao(){
	return tipoCarga;
}
