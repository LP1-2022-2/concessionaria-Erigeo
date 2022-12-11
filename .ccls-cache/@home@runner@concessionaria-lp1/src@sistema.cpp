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


//cria uma concessionaria e retorna uma string de erro ou "Concessionaria criada"
//comando
string Sistema::create_concessionaria (const string nome, const string cnpj, const int Nveiculos) {

	
concessionarias.insert(std::pair<string, Concessionaria>(nome, Concessionaria(cnpj, Nveiculos)));//armazena a concessionaria criada em um map de key correspondente ao nome e value o objeto concessionária, chamando a construtora para preencher os dados dessa Concessionaria.

return "Concessionaria criada.";
}


string Sistema::add_car ( const string nome, const string marca, const int valor, const string chassi, const int ano, const string tipomotor){
	map<string, Concessionaria>::iterator it; //iterador para percorrer os objetos Concessionaria
	map<string, carro>::iterator ITcarro; //iterador para percorrer os objetos carro
	int x = 0;  //variavel que ira sofrer mudança de valor;
	string comparar;
	carro car; //crio objeto carro
	car = carro(nome, marca, valor, chassi, ano, tipomotor); //chamo a construtora para que o objeto carro receba as variáveis
		for(it = concessionarias.begin(); it != concessionarias.end(); it++){ //loop com iterador que percorre as concessionarias armazenadas no container Concessionarias.
		ITcarro = it->second.Lcarro.find(chassi); //iterador carro recebe valor de retorno do find que busca o chassi inserido pelo usuário.
			if(ITcarro != it->second.Lcarro.end()){ //caso o find não encontre o chassi na key do map de carro, ele irá retornar "example".end(). ser != significa que encontrou o chassi.
				x = 1; //caso aconteça de encontrar a variágvel muda seu valor para 1;
				comparar = it->first; //a string recebe a key do map Concessionarias, no qual informa em qual Concessionaria foi encontrado um véiculo com o mesmo chassi.
			 }
	 }
	 if(x != 1 ){ //caso o X não mude de valor, significa que apos a busca não foi encontrado o chassi dentro dos containers.
		 concessionarias.at(nome).Lcarro.insert({chassi, car}); //comando insert para inserir o chassi e o objeto carro preenchido com as variáveis no map que armazena a key chassi e os objetos carro.
				cout << "Carro adicionado ao sistema." << endl;
	  }
			else{
				cout << 
			"ERRO - Veículo" << chassi << " já adicionado à " << comparar <<  endl;
			}
	return "";
}

//cria um objeto caminhao e o armazenena em um map de objeto caminhão dentro de um objeto concessionaria que está armazenado em um map de concessionarias.
//mesma estrutura do add-car
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

//cria um objeto moto e o armazenena em um map de objeto moto dentro de um objeto concessionaria que está armazenado em um map de concessionarias.
//mesma estrutura do add-car
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


//
string Sistema::search_vehicle(const string chassi){
	map<string, Concessionaria>::iterator it; //iterador para percorrer objetos Concessionaria
	map<string, moto>::iterator ITmoto; //iterador para percorrer objetos moto
	map<string, carro>::iterator ITcarro; //iterador para percorrer objetos carro
	map<string, caminhao>::iterator ITcaminhao; //iterador para percorrer objetos caminhao
	for(it = concessionarias.begin(); it != concessionarias.end(); it++){//loop de iterador para percorrer todos os objetos Concessionaria armazenados no container de Concessionarias.
		ITmoto = it->second.Lmoto.find(chassi); //iterador recebendo o valor do find, no qual faz uma busca no map de objetos moto pela Key que armazena o chassi.
		ITcarro = it->second.Lcarro.find(chassi);
		ITcaminhao = it->second.Lcaminhao.find(chassi);
		if( ITmoto != it->second.Lmoto.end()){ //caso o find não encontre o chassi na key do map de carro, ele irá retornar "example".end(). ser != significa que encontrou o chassi.
			cout << "Concessionaria:" << it-> first << endl; //o iterador vai apontar para o first, no qual vai corresponder a key de Concessionarias, que é o nome da Concessionaria.
			cout << "Marca: " << ITmoto-> second.getmarca() << endl;; //iterador de objetos moto vai apontar para o value do map de objetos moto e vai acessar as funções gets existentes nesses objetos.
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
		else if(ITmoto == it->second.Lmoto.end()){ //caso o find devolva "example".end(), significa que não será possível fazer uma busca do veículo, uma vez que ele não está cadastrado.
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

//remove um veículo a partir do input com o chassi do veículo.
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
		 it->second.Lmoto.erase(ITmoto);//comando erase que irá remover o objeto moto do container map, caso o find tenha achado o chassi com o .find
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

//lista os dados da concessionária, além da quantidade de veículos existentes e seus valores.
string Sistema::list_concessionaria(const string concessionaria){
	vector<int>valoresMoto; //vetor para armazenar os valores de cada objeto moto
	vector<int>valoresCarro; //vetor para armazenar os valores de cada objeto carro
	vector<int>valoresCaminhao; //vetor para armazenar os valores de cada objeto caminhao
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto;
	map<string, carro>::iterator ITcarro;
	map<string, caminhao>::iterator ITcaminhao;
		for(ITmoto = concessionarias.at(concessionaria).Lmoto.begin(); ITmoto != concessionarias.at(concessionaria).Lmoto.end(); ITmoto++){//loop com interador que percorre objetos moto, no qual irá percorrer em uma concessionaria espécifica(usando o .at), todos os objetos motos existentes nesse container.
			valoresMoto.push_back(ITmoto->second.getpreco());//comando push_back para armazenar no vetor o valor acessado quando esse iterador moto aponta para o value do map de objetos moto e acessa a função getpreco() existente em cada objeto moto.
		}
		for(ITcarro = concessionarias.at(concessionaria).Lcarro.begin(); ITcarro != concessionarias.at(concessionaria).Lcarro.end(); ITcarro++){
			valoresCarro.push_back(ITcarro->second.getpreco());
		}
		for(ITcaminhao = concessionarias.at(concessionaria).Lcaminhao.begin(); ITcaminhao != concessionarias.at(concessionaria).Lcaminhao.end(); ITcaminhao++){
			valoresCaminhao.push_back(ITcaminhao->second.getpreco());
		}
	int somaMoto = accumulate(valoresMoto.begin(), valoresMoto.end(), 0); //variável inteira recebendo a soma de todos os valores existentes no vetor de valores_moto, através do comando accumulate.
	int somaCarro = accumulate(valoresCarro.begin(), valoresCarro.end(), 0);
	int somaCaminhao = accumulate(valoresCaminhao.begin(), valoresCaminhao.end(), 0);
	int somatotal = somaMoto + somaCarro + somaCaminhao; //soma de todos os valores encontrados
	cout << "Concessionaria " << concessionaria << endl;
	cout << "Total de Automóveis: " << concessionarias.at(concessionaria).Lcarro.size() << "; Valor total: R$: " << somaCarro << endl; //uso do comando .size(), para sabermos o tamanho do container que armazena os veículos carro, dessa forma sabemos quantos veículos carro existem em nossa concessionaria específica.
	cout << "Total de Motos: " << concessionarias.at(concessionaria).Lmoto.size() << ". Valor total: R$: " << somaMoto << endl;
	cout << "Total de Caminhões: " << concessionarias.at(concessionaria).Lcaminhao.size() << ". Valor total: R$: " << somaCaminhao << endl;
	cout << "Valor Total da frota: R$ " << somatotal << endl;
	return "";
	}

//aumenta o valor de todos os veículos em uma porcentagem inserida pelo usuario, possui pesos específicos para cada tipo de veículo.
string Sistema::raise_price(const string concessionaria, const int aumento){
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto;
	map<string, carro>::iterator ITcarro;
	map<string, caminhao>::iterator ITcaminhao;
	int b, c;
		for(ITmoto = concessionarias.at(concessionaria).Lmoto.begin(); ITmoto != concessionarias.at(concessionaria).Lmoto.end(); ITmoto++){//loop com interador que percorre objetos moto, no qual irá percorrer em uma concessionaria espécifica(usando o .at), todos os objetos motos existentes nesse container.
			 b = ITmoto->second.getpreco(); //variável inteira "b", recebe o valor do getpreco(), no qual é acessado pelo iterador de objetos moto que aponta para o value do container map e acessa a função getpreco() existente nos objetos moto.
			 c = (b *20)/100 + b; //variável c recebe o resultado da operação que aumenta em 20% o valor de b.
			ITmoto->second.setpreco(c); //iterador de moto acessa o value dos objetos moto e chama a função set, para redefinir a variavel preco para o valor de c.
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

//salva os dados de uma concessionaria, incluindo seus veículos em um arquivo.txt
string Sistema::save_concessionaria(const string concessionaria){
	map<string, Concessionaria>::iterator it;
	map<string, moto>::iterator ITmoto;
	map<string, carro>::iterator ITcarro;
	map<string, caminhao>::iterator ITcaminhao;
	string a;
	string filename = concessionaria; //recebe o nome do arquivo inserido pelo usuário.
	filename.append(".txt");//adiciona .txt ao final do nome do arquivo;
	
	
	it = concessionarias.find(concessionaria); //find para o it acessar a concessionária específica
	ofstream myfile; //cria o arquivo
	myfile.open(filename); //abre o arquivo
	myfile << (it->first) << "," << (it->second).getcnpj()<< "," <<(it->second).getNveiculos() << endl; //usa iterador de objetos concessionaria para armazenar na primeira linha do arquivo os desse objeto separados por ",". 
	for(ITmoto = concessionarias.at(concessionaria).Lmoto.begin(); ITmoto != concessionarias.at(concessionaria).Lmoto.end(); ITmoto++){//loop com interador que percorre objetos moto, no qual irá percorrer em uma concessionaria espécifica(usando o .at), todos os objetos motos existentes nesse container.
		myfile << ITmoto->second.tipo << "," <<ITmoto->second.getmarca() << "," << ITmoto->second.getpreco() << "," << ITmoto->first << "," << ITmoto->second.getanoF() << "," <<  ITmoto->second.getModelo() << endl; //cada linha do arquivo irá corresponder aos dados de um objeto específico separados por vírgula.
		}
	
		for(ITcarro = concessionarias.at(concessionaria).Lcarro.begin(); ITcarro != concessionarias.at(concessionaria).Lcarro.end(); ITcarro++){
			 myfile << ITcarro->second.tipo << "," <<ITcarro->second.getmarca() << "," << ITcarro->second.getpreco() << "," << ITcarro->first << "," << ITcarro->second.getanoF() << "," << ITcarro->second.getcarro() << endl;
		}
	
		for(ITcaminhao = concessionarias.at(concessionaria).Lcaminhao.begin(); ITcaminhao != concessionarias.at(concessionaria).Lcaminhao.end(); ITcaminhao++){
			 myfile << ITcaminhao->second.tipo << "," << ITcaminhao->second.getmarca() << "," << ITcaminhao->second.getpreco() << "," << ITcaminhao->first << "," << ITcaminhao->second.getanoF() << "," << ITcaminhao->second.getcaminhao() << endl;
		}
	
	myfile.close(); //fecha arquivo;
	cout << "Arquivo " << filename << " criado com sucesso" << endl; 
	return "";
}

//lê um arquivo.txt e cria uma concessionaria com os dados existentes nesse arquivo.
string Sistema::load_concessionaria(const string arquivo){
	istringstream s;
	vector<string> v_concessionaria; //vetor para armazenar dados que serão recolhidos do arquivo.txt
	int i = 0;
	string concessionaria;
	string mytext, line, word;
	string cnpj, Nveiculos, nome;
	string tipo, nome1, marca, preco, chassi, ano, diferencial;
	ifstream readfile(arquivo); //abre o arquivo para leitura
	readfile >> mytext; //tudo existente no arquivo a ser lido, é copiado para essa string
	s.str(mytext); //separa o conteúdo da string em substrings
	while(getline(s, concessionaria, ',')){//loop para ler a primeira linha, no qual tem como limitador a ","
		v_concessionaria.push_back(concessionaria); //cada string coletada é armazenada em um vetor de strings
	}
	//como sei que a quantidade de dados em cada linha do arquivo, e que a primeira linha corresponde apenas aos dados da concessionaria, uso da ordem criada para armazenar esses dados em cada variável correspondente
	nome = v_concessionaria[0];
	cnpj = v_concessionaria[1];
	Nveiculos = v_concessionaria[2];
	create_concessionaria(nome, cnpj, stoi(Nveiculos)); //com as variáveis preenchidas, chamo a função create para criar a concessionaria.
	v_concessionaria.erase(v_concessionaria.begin(), v_concessionaria.end()); //pretendo utilizar o mesmo vector, como os dados já estão devidamente armazenados agora em variáveis, removo tudo que existe no vetor com o .erase(...,...);

	while(readfile >> mytext){//loop que irá se encerrar quando o >> encontrar o EOF
s.clear();
s.str(mytext); //separa as strings do arquivo em substrings
while(getline(s, word, ',')){ //a partir da segunda linha,  irá adicionar linha por linha ao vetor as substrings separadas pelo delimitador ","
	v_concessionaria.push_back(word); 
	if(i == 5){//como é sabido a quantidade de substrings existnte em cada linha, apenas quando acontecer 5 push_backs que será possível esse if acontecer
	if(v_concessionaria[0] == "moto"){ //no arquivo, a primeira substrings sempre será especificando qual o tipo de veículo
	add_bike(nome, v_concessionaria[1], stoi(v_concessionaria[2]), v_concessionaria[3], stoi(v_concessionaria[4]), (v_concessionaria[5]));//funcao de adicionar veículo invocada utilizando como dados a ordem de dados armazenados no vetor
	v_concessionaria.erase(v_concessionaria.begin(), v_concessionaria.end());//dados do vetor apagados para serem reutilizados utilizando .erase(...,...)
		i = -1; //variável reiniciada
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
	
	readfile.close(); //fecha o arquivo
	cout << "Concessionaria " << nome << " criada com sucesso" << endl;
	return "";
	}