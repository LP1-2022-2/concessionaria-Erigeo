
# Identificação

* Nome: Georg Herison Maia Nunes

* Matrícula: 20210053829
  
# Compilação  

# Compilando  

* Para compilar o programa Concessionaria, basta utilizar o comando "make". Dessa forma, as Flags são definidas automaticamente para o usuário.
* O executável pode ser encontrado na pasta build/

# Valgrind
* Para verificar se está acontecendo algum vazamento de memória, remova no arquivo Makefile o -"fsanitize=address".
* Execute o programa inserindo a palavra valgrind antes do nome do executável.
	Exemplo: valgrind ./build/programa
* Insira os comandos, após isso finalize com quit
* Aguarde o relatório do valgrind.


# Instruções de execução do programa.
* Comandos:
  
1) create-concessionaria

		Exemplo:
		create-concessionaria IMD_SA 11.111.111/0001-11 0
  
Recebe do usuário o nome da Concessionária, CNPJ e o número de veículos para criar uma Concessionária e armazená-la no programa.

2) add-car
   
		Exemplo:
		add-car IMD_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
	
Insira após o comando o nome da Concessionaria previamente criada, a marca do veículo, o seu valor, chassi, ano de fabricação e o tipo de motor.

3) add-truck
   
		Exemplo:
		add-truck IMD_SA Scania 700000 7BRBLQHEXG0208811 2010 perigosa
	
Insira após o comando o nome da Concessionaria previamente criada, a marca do veículo, o seu valor, chassi, ano de fabricação e o tipo de carga.

4) add-bike
   
		Exemplo:
		add-bike IMD_SA YAMAHA 35000 7BRBLQHEXG02878811 2010 mobilete
	
Insira após o comando o nome da Concessionaria previamente criada, a marca do veículo, o seu valor, chassi, ano de fabricação e o modelo.

5) remove-vehicle

É possível remover algum veículo cadastrado a partir do seu chassi.

		Exemplo:
		remove-vehicle 9BRBLWHEXG0107721
	
Insira após o comando o chassi do veículo ao qual quer remover.

6) search-vehicle

Utilize esse comando para a partir de um chassi ter acesso as informações sobre um veículo.

		Exemplo:
		search-vehicle 9BRBLWHEXG0107721
   
Insira após o comando o chassi do veículo ao qual quer procurar.

7) list-concessionaria

O comando devolve o total de veículos da concessionaria escolhida, junto com seus respectivos valores e o total da frota.

 		Exemplo:
		list-concessionaria IMD_SA
  
Insira após o comando o nome da concessionária.

 8) raise-price

A partir desse comando é possivel aumentar todos os valores dos veículos seguindo uma proporção 	de uma concessionária específica.

		Exemplo:
		raise-price IMD_SA 10
		
Insira após o comando o nome da concessionária e a porcentagem(sem %).

9) save-concessionaria

Permite salvar uma concessionária em um arquivo.txt

		Exemplo:
		save-concessionaria IMD_SA
	
Insira o nome da concessionária apos o comando

10) load-concessionaria

Recupera os dados de uma concessionaria a partir de um arquivo.txt previamente existente

		Exemplo:
		load-concessionaria IMD_SA.txt

Insira apos o comando o nome do arquivo.txt

11) quit
   
Comando utilizado para finalizar o programa.

		Exemplo:
		quit

	 
# Limitações

* A principal limitação do código é que ele é feito especificamente pra lidar apenas com carros, motos e caminhões. Sendo assim, seguindo a estrutura e lógica do código, caso o usuário quisesse por exemplo adicionar a categoria "Jetski", seria necessário criar uma classe e adicionar mais um container map na classe Concessionária e adaptar o restante do código.
* Além disso, inicialmente senti muita dificuldade em visualizar qual tipo de container usar e em qual classe estaria esse container de veículos, chegando a conclusão baseado nos exemplos de comandos deixados no github que seria mais prático aderir ao uso de um container(map) para cada tipo de veículo ao invés de um único container com todos.
* Contudo, também tive dificuldade nas primeiras tentativas -e que ainda me confude um pouco quando tenho que fazer alguma implementação no código- é em relação ao uso de iteradores, aos quais ainda tenho pouca familiaridade e sentia confusão ao utilizar-los para percorrer um map da lista de veículos que estava inserido em uma classe Concessionaria armazenada no map de Concessionarias, sendo necessário uma leitura com calma para me situar.
* Todavia, tenho dúvidas em relação ao desempenho do código e em relação a memória, se a quantidade de containers utilizados pode comprometer algo, uma vez que só no comando $raise-prices utilizei 3 vetores(um pra cada tipo de veículo) para armazenar os preços, sendo assim, imagino que caso houvessem mais implementações acabaria reutilizando esse método que não me parece tão saudável a longo prazo.
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | **10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **10 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **15 / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **30 / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **10 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **15 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **150 / 150 ** pontos (sem bônus)
 
 **150 / 200 ** pontos (com bônus)
