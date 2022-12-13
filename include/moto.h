
#ifndef MOTO_H
#define MOTO_H
#include <string>
#include "veiculo.h"
using std::string;
class moto :  public veiculo{ //heranca
private:
string Modelo;
public:
string tipo = "moto";
moto();
moto(string concessionaria, string marca, int p, string cha, int ano, string Modelo); //construtora
void setModelo(string a);
string getModelo();

};


#endif
//por apenas construtoras nas classes pai e na filha puxar todas as informações e chamar o pusback para armazenar em um vetor de consseionaria