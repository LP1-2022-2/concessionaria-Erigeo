#include "executor.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

// Função de apoio que recebe um istringstream e
// le todo texto restante até o fim da linha
//ele le ate chegar em um espaco
string restoDe(istringstream &ss) {
  string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar
  }
  return resto;
}

// Construtor. Recebe uma referência ao sistema que vai operar
// Guarda o seu endereço para executar as operações.
Executor::Executor(Sistema &sistema) {
  this->sair = false;
  this->sistema = &sistema;
}

// Inicia o processamento dos comentarios.
// Esse método recebe por exemplo o "cin" e o "cout" no main
// Dessa forma ele faz o necessário para ler 1 comando por linha e
// o processar corretamente, colocando no stream de saída o resultado de cada um.
void Executor::iniciar(istream &inputStream, ostream &outputStream) {
  string linha, saida;
  this->sair = false;
  while (! this->sair)
  {
    if (std::getline(inputStream, linha)) {
      saida = processarLinha(linha);
      outputStream << saida << endl;
    }
  }
}

// Método responsável por processar cada linha, capturando o nome do comando
// e seus parâmetros em variáveis e executar o método correspondente no sistema
string Executor::processarLinha(string linha) {
  istringstream buf(linha);
  string nomeComando;
  buf >> nomeComando;

  if (nomeComando.empty()) {
    return "Comando Inválido <vazio>";
  }

  else if (nomeComando == "quit" ) {
    this->sair = true;
    return sistema->quit();
  }
  else if (nomeComando == "create-concessionaria") {
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string nome, cnpj;
		int Nveiculos;
		buf >> nome;
		buf >> cnpj;
		buf >> Nveiculos;
		return sistema->create_concessionaria(nome, cnpj, Nveiculos);
  }
	else if (nomeComando == "add-car"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string nome, marca, chassi, tipomotor;
		int valor, ano;
		buf >> nome;
		buf >> marca;
		buf >> valor;
		buf >> chassi;
		buf >> ano;
		buf >> tipomotor;
		return sistema->add_car(nome, marca, valor, chassi, ano, tipomotor);
	}
	else if (nomeComando == "add-truck"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string nome, marca, chassi, tipocarga;
		int valor, ano;
		buf >> nome;
		buf >> marca;
		buf >> valor;
		buf >> chassi;
		buf >> ano;
		buf >> tipocarga;
		return sistema->add_truck(nome, marca, valor, chassi, ano, tipocarga);
	}
	else if (nomeComando == "add-bike"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string nome, marca, chassi, modelo;
		int valor, ano;
		buf >> nome;
		buf >> marca;
		buf >> valor;
		buf >> chassi;
		buf >> ano;
		buf >> modelo;
		return sistema->add_bike(nome, marca, valor, chassi, ano, modelo);
	}
	else if (nomeComando == "search-vehicle"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string chassi;
		
		buf >> chassi;
		
		return sistema->search_vehicle(chassi);
	}
	else if (nomeComando == "remove-vehicle"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string chassi;
		
		buf >> chassi;
		
		return sistema->remove_vehicle(chassi);
	}
	else if (nomeComando == "list-concessionaria"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string concessionaria;
		
		buf >> concessionaria;
		
		return sistema->list_concessionaria(concessionaria);
	}
	else if (nomeComando == "raise-price"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string concessionaria;
		int aumento;
		buf >> concessionaria;
		buf >> aumento;
		return sistema->raise_price(concessionaria, aumento);
	}
	else if (nomeComando == "save-concessionaria"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string concessionaria;
		buf >> concessionaria;
		return sistema->save_concessionaria(concessionaria);
	}
	else if (nomeComando == "load-concessionaria"){
		string linha;
		linha = restoDe(buf);
		buf.clear();
		buf.str(linha);
		string arquivo;
		buf >> arquivo;
		return sistema->load_concessionaria(arquivo);
	}

	
  return "Erro";	

	

	
}

//usar map, relaciona o nome atraves da key a concessionaria hehe


