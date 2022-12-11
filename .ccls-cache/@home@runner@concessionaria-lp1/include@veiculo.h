
#ifndef VEICULO_H
#define VEICULO_H
#include <string>
using std::string;

class veiculo{
private:
string concessionaria;
string marca;
int preco;
string chassi;
int anoF;
public:
veiculo();
veiculo(string f, string a, int b, string c, int d); //construtora
void setconcessionaria(string f);
string getconcessionaria();
void setmarca(string a);
string getmarca();
void setpreco(int b);
void setchassi(string c);
int getpreco();
string getchassi();
void setanoF(int d);
int getanoF();
};
	//marca
//preco
//N do chassi
//ano de fabri

//Apenas Automóveis possuem um atributo relativo ao tipo de motor (gasolina ou elétrico); apenas Motos possuem um atributo relativo ao modelo (clássico ou esportivo); apenas Caminhões possuem um atributo relativo ao tipo de carga (comum ou perigosa). Considere que os veículos podem ser ordenados pelos últimos 5 dígitos do número de chassi.



#endif