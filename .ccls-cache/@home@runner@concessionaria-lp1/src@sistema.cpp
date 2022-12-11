#include "sistema.h"
#include "Concessionaria.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include "veiculo.h"
#include "carro.h"
#include "caminhao.h"
#include "moto.h"
#include <numeric>
#include <string.h>
#include <fstream>
using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

//através do comando insert, é inserido no container map que armazena as concessionárias a key correspondente ao nome da concessionária e o objeto concessionaria é preenchido com os dados do cnpj e Nveiculos
string Sistema::create_concessionaria (const string nome, const string cnpj, const int Nveiculos) {

	
concessionarias.insert(std::pair<string, Concessionaria>(nome, Concessionaria(cnpj, Nveiculos)));

return "Concessionaria criada.";
}

//o objeto da classe carro é criado e é preenchido com os dados através da construtora, em seguida utilizo um loop com o it pra percorrer todas as concessionarias cadastradas e utilizo de outro iterador para receber o valor do find que irá percorrer todos os objetos carro no map e utilizo de um if para comparar se esse valor recebido é != de .end(), que é sintax devolvida pelo find caso não encontre nada. Caso em algum momento do loop seja encontrada nas concessionarias algum chassi igual ao inserido pelo usuário, a variável x irá receber o valor 1. Dessa forma, utilizo mais um if fora do loop para averiguar se não existe repetição e assim utilizar o .insert para adicionar o veículo garantido que não acontecerá uma repetição.
string Sistema::add_car ( const string nome, const string marca, const int valor, const string chassi, const int ano, const string tipomotor){
	map<string, Concessionaria>::iterator it;
	map<string, carro>::iterator ITcarro;
	int x = 0;
	string comparar;
	carro car;
	car = carro(nome, marca, valor, chassi, ano, tipomotor);
		for(it = concessionarias.begin(); it != concessionarias.end(); it++){
		ITcarro = it->second.Lcarro.find(chassi);
			if(ITcarro != it->second.Lcarro.end()){
				x = 1;
				comparar = it->first;
			 }
	 }
	 if(x != 1 ){ 
		 concessionarias.at(nome).Lcarro.insert({chassi, car});
				cout << "Carro adicionado ao sistema." << endl;
	  }
			else{
				cout << 
			"ERRO - Veículo" << chassi << " já adicionado à " << comparar <<  endl;
			}
	return "";
}
//O processo é o mesmo do add_car
string Sistema::add_truck ( const string nome, const string marca, const int valor, const string chassi, const int ano, const string tipocarga){
	map<string, Concessionaria>::iterator it;
	map<string, caminhao>::iterator ITcaminhao;
	int x = 0;
	string comparar;
	caminhao truck;
	truck = caminhao(nome, marca, valor, chassi, ano, tipocarga);
		for(it = concessionarias.begin(); it != concessionarias.end(); it++){
		ITcaminhao = it->second.Lcaminhao.find(chassi);
			if(ITcaminhao != it->second.Lcaminhao.end()){
				x = 1;
				comparar = it->first;
			 }
	 }
	 if(x != 1 ){ 
		 concessionarias.at(nome).Lcaminhao.insert({chassi, truck});
				cout << "Caminhão adicionado ao sistema." << endl;
	  }
			else{
				cout << 
			"ERRO - Veículo" << chassi << " já adicionado à " << comparar <<  endl;
			}
	return "";
}

//O processo é o mesmo do add_car
string Sistema::add_bike ( const string nome, const string marca, const int valor, const string chassi, const int ano, const string modelo){
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto;
	int x = 0;
	string comparar;
	moto bike;
	bike = moto(nome, marca, valor, chassi, ano, modelo);
		for(it = concessionarias.begin(); it != concessionarias.end(); it++){
		ITmoto = it->second.Lmoto.find(chassi);
			if(ITmoto != it->second.Lmoto.end()){
				x = 1;
				comparar = it->first;
			 }
	 }
	 if(x != 1 ){ 
		 concessionarias.at(nome).Lmoto.insert({chassi, bike});
				cout << "Moto adicionado ao sistema." << endl;
	  }
			else{
				cout << 
			"ERRO - Veículo" << chassi << " já adicionado à " << comparar <<  endl;
			}
	return "";
}


//processo semelhante ao anterior ao utilizar um loop com iteradores e com find para localizar o chassi no container, com um iterador que irá apontar para os objetos veículos correspohndentes ao chassi no map para imprimir seus dados a partir de gets.
string Sistema::search_vehicle(const string chassi){
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto; 
	map<string, carro>::iterator ITcarro;
	map<string, caminhao>::iterator ITcaminhao;
	for(it = concessionarias.begin(); it != concessionarias.end(); it++){
		ITmoto = it->second.Lmoto.find(chassi);
		ITcarro = it->second.Lcarro.find(chassi);
		ITcaminhao = it->second.Lcaminhao.find(chassi);
		if( ITmoto != it->second.Lmoto.end()){
			cout << "Concessionaria:" << it-> first << endl;;
			cout << "Marca: " << ITmoto-> second.getmarca() << endl;;
			cout << "Preço: " << ITmoto-> second.getpreco() << endl;
			cout << "Chassi: " << ITmoto-> second.getchassi() << endl;
			cout << "Ano: " << ITmoto-> second.getanoF() << endl;
			cout << "Modelo: " << ITmoto-> second.getModelo() << endl;
	}
	else if( ITcarro != it->second.Lcarro.end()){
			cout << "Concessionaria:" << it-> first << endl;;
			cout << "Marca: " << ITcarro-> second.getmarca() << endl;;
			cout << "Preço: " << ITcarro-> second.getpreco() << endl;
			cout << "Chassi: " << ITcarro-> second.getchassi() << endl;
			cout << "Ano: " << ITcarro-> second.getanoF() << endl;
			cout << "Tipo de motor: " << ITcarro-> second.getcarro() << endl;
	}
		else if( ITcaminhao != it->second.Lcaminhao.end()){
			cout << "Concessionaria:" << it-> first << endl;;
			cout << "Marca: " << ITcaminhao-> second.getmarca() << endl;;
			cout << "Preço: " << ITcaminhao-> second.getpreco() << endl;
			cout << "Chassi: " << ITcaminhao-> second.getchassi() << endl;
			cout << "Ano: " << ITcaminhao-> second.getanoF() << endl;
			cout << "Tipo de carga: " << ITcaminhao-> second.getcaminhao() << endl;
	}
		else if(ITmoto == it->second.Lmoto.end()){
			cout << "Veículo não encontrado" <<endl;
		}
		else if(ITcarro == it->second.Lcarro.end()){
			cout << "Veículo não encontrado" <<endl;
		}
		else if(ITcaminhao == it->second.Lcaminhao.end()){
			cout << "Veículo não encontrado" <<endl;
		}
	}
	return "";
}	

//mesma lógica de loop usando iteradores, agora com o comando erase//
string Sistema::remove_vehicle(const string chassi){
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto; 
	map<string, carro>::iterator ITcarro; 
	map<string, caminhao>::iterator ITcaminhao; 
	for(it = concessionarias.begin(); it != concessionarias.end(); it++){
		ITmoto = it->second.Lmoto.find(chassi);
		ITcarro = it->second.Lcarro.find(chassi);
		ITcaminhao = it->second.Lcaminhao.find(chassi);
		if( ITmoto != it->second.Lmoto.end()){
		 it->second.Lmoto.erase(ITmoto);
			cout << "Veículo " << chassi << " removido da concessionária"  << it->first << endl;
	}
		else if( ITcarro != it->second.Lcarro.end()){
			 it->second.Lcarro.erase(ITcarro);
				cout << "Veículo " << chassi << " removido da concessionária"  << it->first << endl;
	}
		else if( ITcaminhao != it->second.Lcaminhao.end()){
			 it->second.Lcaminhao.erase(ITcaminhao);
				cout << "Veículo " << chassi << " removido da concessionária"  << it->first << endl;
	}
		else{
			cout << "Veículo não encontrado" <<endl;
		}
}
		return "";
}

//utilizo iteradores para a partir de uma concessionaria espécifica percorrer todos os containers de carros, caminhões e motos para obter o seus precos e armazeno esses valores com um push_back em um vetor para cada tipo de veiculo, em seguida utilizo o accumulate para somar todos esses valores de cada vetor e o .size() para saber quantos veiculos existem em cada um dos containers respectivos.//
string Sistema::list_concessionaria(const string concessionaria){
	vector<int>valoresMoto;
	vector<int>valoresCarro;
	vector<int>valoresCaminhao;
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto;
	map<string, carro>::iterator ITcarro;
	map<string, caminhao>::iterator ITcaminhao;
		for(ITmoto = concessionarias.at(concessionaria).Lmoto.begin(); ITmoto != concessionarias.at(concessionaria).Lmoto.end(); ITmoto++){
			valoresMoto.push_back(ITmoto->second.getpreco());
		}
		for(ITcarro = concessionarias.at(concessionaria).Lcarro.begin(); ITcarro != concessionarias.at(concessionaria).Lcarro.end(); ITcarro++){
			valoresCarro.push_back(ITcarro->second.getpreco());
		}
		for(ITcaminhao = concessionarias.at(concessionaria).Lcaminhao.begin(); ITcaminhao != concessionarias.at(concessionaria).Lcaminhao.end(); ITcaminhao++){
			valoresCaminhao.push_back(ITcaminhao->second.getpreco());
		}
	int somaMoto = accumulate(valoresMoto.begin(), valoresMoto.end(), 0);
	int somaCarro = accumulate(valoresCarro.begin(), valoresCarro.end(), 0);
	int somaCaminhao = accumulate(valoresCaminhao.begin(), valoresCaminhao.end(), 0);
	int somatotal = somaMoto + somaCarro + somaCaminhao;
	cout << "Concessionaria " << concessionaria << endl;
	cout << "Total de Automóveis: " << concessionarias.at(concessionaria).Lcarro.size() << "; Valor total: R$: " << somaCarro << endl;
	cout << "Total de Motos: " << concessionarias.at(concessionaria).Lmoto.size() << ". Valor total: R$: " << somaMoto << endl;
	cout << "Total de Caminhões: " << concessionarias.at(concessionaria).Lcaminhao.size() << ". Valor total: R$: " << somaCaminhao << endl;
	cout << "Valor Total da frota: R$ " << somatotal << endl;
	return "";
	}

	
//loop com iterador que percorre o container de cada tipo de veiculo, recebendo seu valor em uma variável e usando outra variável para fazer a operação matemática, assim utilizando novamente o iterador para redefinir com set o valor do veículo para o novo valor.
string Sistema::raise_price(const string concessionaria, const int aumento){
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto;
	map<string, carro>::iterator ITcarro;
	map<string, caminhao>::iterator ITcaminhao;
	int b, c;
		//cout << ITmoto-> second.Lmoto.size() <<  endl;
		for(ITmoto = concessionarias.at(concessionaria).Lmoto.begin(); ITmoto != concessionarias.at(concessionaria).Lmoto.end(); ITmoto++){
			 b = ITmoto->second.getpreco();
			 c = (b *20)/100 + b;
			ITmoto->second.setpreco(c);
		}
		for(ITcarro = concessionarias.at(concessionaria).Lcarro.begin(); ITcarro != concessionarias.at(concessionaria).Lcarro.end(); ITcarro++){
			 b = ITcarro->second.getpreco();
			 c = (b *10)/100 + b;
			ITcarro->second.setpreco(c);
		}
		for(ITcaminhao = concessionarias.at(concessionaria).Lcaminhao.begin(); ITcaminhao != concessionarias.at(concessionaria).Lcaminhao.end(); ITcaminhao++){
			 b = ITcaminhao->second.getpreco();
			 c = (b * 30)/100 + b;
			ITcaminhao->second.setpreco(c);
		}
	cout << "Aumento de 10% nos preços de automóveis da Concessionária " << concessionaria << " realizado." << endl;
	cout << "Aumento de 20% nos preços de motos da Concessionária " << concessionaria << " realizado." << endl;
	cout << "Aumento de 30% nos preços de caminhões da Concessionária " << concessionaria << " realizado." << endl;
		return "";
	}

string Sistema::save_concessionaria(const string concessionaria){
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto;
	map<string, carro>::iterator ITcarro;
	map<string, caminhao>::iterator ITcaminhao;
	string a;
	string filename = concessionaria;
	filename.append(".txt");
	
	
	it = concessionarias.find(concessionaria);
	ofstream myfile;
	myfile.open(filename);
	myfile << (it->first) << "," << (it->second).getcnpj()<< "," <<(it->second).getNveiculos() << endl;
	for(ITmoto = concessionarias.at(concessionaria).Lmoto.begin(); ITmoto != concessionarias.at(concessionaria).Lmoto.end(); ITmoto++){
		myfile << ITmoto->second.tipo << "," <<ITmoto->second.getmarca() << "," << ITmoto->second.getpreco() << "," << ITmoto->first << "," << ITmoto->second.getanoF() << "," <<  ITmoto->second.getModelo() << endl;
		}
	
		for(ITcarro = concessionarias.at(concessionaria).Lcarro.begin(); ITcarro != concessionarias.at(concessionaria).Lcarro.end(); ITcarro++){
			 myfile << ITcarro->second.tipo << "," <<ITcarro->second.getmarca() << "," << ITcarro->second.getpreco() << "," << ITcarro->first << "," << ITcarro->second.getanoF() << "," << ITcarro->second.getcarro() << endl;
		}
	
		for(ITcaminhao = concessionarias.at(concessionaria).Lcaminhao.begin(); ITcaminhao != concessionarias.at(concessionaria).Lcaminhao.end(); ITcaminhao++){
			 myfile << ITcaminhao->second.tipo << "," << ITcaminhao->second.getmarca() << "," << ITcaminhao->second.getpreco() << "," << ITcaminhao->first << "," << ITcaminhao->second.getanoF() << "," << ITcaminhao->second.getcaminhao() << endl;
		}
	
	myfile.close();
	cout << "Concessionaria " << concessionaria << " criada com sucesso." << endl;
	return "";
}

string Sistema::load_concessionaria(const string arquivo){
	istringstream s;
	vector<string> v_concessionaria;
	int i = 0;
	string concessionaria;
	string mytext, line, word;
	string cnpj, Nveiculos, nome;
	string tipo, nome1, marca, preco, chassi, ano, diferencial;
	ifstream readfile(arquivo);
	readfile >> mytext;
	cout << mytext << endl;
	s.str(mytext);
	while(getline(s, concessionaria, ',')){
		v_concessionaria.push_back(concessionaria);
	}
	nome = v_concessionaria[0];
	cnpj = v_concessionaria[1];
	Nveiculos = v_concessionaria[2];
	create_concessionaria(nome, cnpj, stoi(Nveiculos));
	v_concessionaria.erase(v_concessionaria.begin(), v_concessionaria.end());

	while(readfile >> mytext){
s.clear();
s.str(mytext);
while(getline(s, word, ',')){
	v_concessionaria.push_back(word);
	if(i == 5){
	if(v_concessionaria[0] == "moto"){
	cout << "a" << v_concessionaria[5] << endl;
	add_bike(nome, v_concessionaria[1], stoi(v_concessionaria[2]), v_concessionaria[3], stoi(v_concessionaria[4]), (v_concessionaria[5]));
	v_concessionaria.erase(v_concessionaria.begin(), v_concessionaria.end());
		i = -1;
	}
	else if(v_concessionaria[0] == "carro"){
	add_car(nome, v_concessionaria[1], stoi(v_concessionaria[2]), (v_concessionaria[3]), stoi(v_concessionaria[4]), v_concessionaria[5]);
	v_concessionaria.erase(v_concessionaria.begin(), v_concessionaria.end());
		i = -1;
	}
	else if(v_concessionaria[0] == "caminhao"){
	add_truck(nome, v_concessionaria[1], stoi(v_concessionaria[2]), (v_concessionaria[3]), stoi(v_concessionaria[4]), v_concessionaria[5]);
	v_concessionaria.erase(v_concessionaria.begin(), v_concessionaria.end());
		i = -1;
	}
	}
			i++;
	}
}
	
	
	
	readfile.close();
	return "";
	}