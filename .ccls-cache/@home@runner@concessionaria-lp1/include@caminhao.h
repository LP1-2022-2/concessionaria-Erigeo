#ifndef CAMINHAO_H
#define CAMINHAO_H
#include "veiculo.h"
#include <string>
using std::string;

class caminhao : public veiculo{ //heranca
private:
string tipoCarga;
public:
string tipo = "caminhao";
caminhao();
caminhao(string conssesionaria, string marca, int p, string cha, int ano, string tipocarga); //construtora
void setcaminhao(string a);
string getcaminhao();

};


#endif