
#ifndef CARRO_H
#define CARRO_H
#include <string>
#include "veiculo.h"
using std::string;

class carro : public veiculo{ //heranca
private:
string tipoMotor;
public:
string tipo = "carro";
carro();
carro(string concessionaria, string marca, int p, string cha, int ano, string tipomotor); //construtora
void setcarro(string tipomotor);
string getcarro();

};


#endif