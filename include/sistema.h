#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "Concessionaria.h"
#include <map>

// Sistema deve concentrar todas as operações
class Sistema {
  private:
		std::map<string, Concessionaria> concessionarias; 
  public:

		/*Encerra o funcionamento do programa.
			@return uma string com a mensagem "Saindo.."
		*/
		std::string quit();

		/* Cria uma concessionaria e retorna uma string de erro/sucesso 
			@param nome o nome da concessionaria
			@return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
		*/
		std::string create_concessionaria (const std::string nome, const std::string cnpj, const int Nveiculos);

		std::string add_car ( const string nome, const string marca, const int valor, const string chassi, const int ano, const string tipomotor);
		
std::string add_truck ( const string nome, const string marca, const int valor, const string chassi, const int ano, const string tipocarga);
		

std::string add_bike ( const string nome, const string marca, const int valor, const string chassi, const int ano, const string modelo);

std::string search_vehicle(const string chassi);


std::string remove_vehicle(const string chassi);


std::string list_concessionaria(const string concessionaria);


std::string raise_price(const string concessionaria, const int aumento);


std::string save_concessionaria(const string concessionaria);

std::string load_concessionaria(const string arquivo);

};
#endif
