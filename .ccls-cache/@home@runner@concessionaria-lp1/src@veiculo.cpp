#include "veiculo.h"

veiculo::veiculo(){};

veiculo::veiculo(string f, string a, int b, string c, int d) : concessionaria(f), marca(a), preco(b), chassi(c), anoF(d){};

void veiculo::setconcessionaria(string f){
	concessionaria = f;
}

string veiculo::getconcessionaria(){
	return concessionaria;
}

void veiculo::setmarca(string a){
	marca = a;
}

void veiculo::setpreco(int b){
	preco = b;
}

void veiculo::setchassi(string c){
	chassi = c;
}

void veiculo::setanoF(int d){
	anoF = d;
}

string veiculo::getmarca(){
	return marca;
}

int veiculo::getpreco(){
	return preco;
}

string veiculo::getchassi(){
	return chassi;
}

int veiculo::getanoF(){
	return anoF;
}

