
#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include <string>
#include <map>
#include "moto.h"
#include "caminhao.h"
#include "carro.h"

using std::string;
class Concessionaria{
private:
string nome;
string cnpj;
int Nveiculos;


public:
std::map<string, moto> Lmoto; //container que armazena na key o chassi e no value os objetos moto
std::map<string, caminhao> Lcaminhao; //container semelhante ao de moto, mas que armazena objetos caminhao
std::map<string, carro> Lcarro; //mesma coisa do de cima
Concessionaria();
Concessionaria( string a, int b); //construtora
void setcnpj(string b);
void setNveiculos(int c);
std::string getcnpj();
int getNveiculos();
};


#endif