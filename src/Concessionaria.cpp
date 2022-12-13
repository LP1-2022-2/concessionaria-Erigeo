#include "Concessionaria.h"

Concessionaria::Concessionaria(){};

Concessionaria::Concessionaria( std::string b, int c) :  cnpj(b), Nveiculos(c){}; 



void Concessionaria::setcnpj(string a){
	cnpj = a;
}


void Concessionaria::setNveiculos(int a){
	Nveiculos = a;
}

int Concessionaria::getNveiculos(){
	return Nveiculos;
}




std::string Concessionaria::getcnpj(){
	return cnpj;
};