#include <stdio.h>	//biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco na memoria
#include <locale.h> //biblioteca de alocacao de texto por registro
#include <string.h> //biblioteca responsavel para cuidadar das strings


int registro() // funcao responsavel por cadastrar os usuarios no sistema 
{
	setlocale(LC_ALL, "Portuguese"); // definido a linguagem
	// inicio da criacao das variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criacao das variaveis/string
	
	printf("Digite o CPF a ser cadastrado:  "); // colocar as informacoes do usuario
	scanf("%s",cpf); //%s referece a string 
	
	strcpy(arquivo,cpf);// cara responsavel por copiar os valores da string
	
	FILE *file; // cria o arquivo no banco de dados  
	file = fopen(arquivo,"w");// cria o arquivo re escreve esse arquivo, "w" para criar um arquivo
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file); // aqui fecha o arquivo
	
	file = fopen(arquivo,"a");// abrir o arquivo, "a" para atualizar o arquivo
	fprintf(file, ", ");// para acrecentar a ","
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); // nome a ser cadastrado 
	scanf("%s" , nome); // %s referece a string
	
	file = fopen(arquivo, "a"); // abrir o arquivo, "a" para atualizar o arquivo
	fprintf(file, nome);// salvar o valor da variavel no arquivo 
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo,"a");// abrir o arquivo, "a" para atualizar o arquivo
	fprintf(file, ", ");// para acrecentar a ","
	fclose(file);//fechar o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado: "); // Sobrenome a ser cadastrado 
	scanf("%s", sobrenome);// %s referece a string
	
	file = fopen(arquivo, "a");// abrir o arquivo, "a" para atualizar o arquivo
	fprintf(file, sobrenome);// salvar o valor da variavel no arquivo 
	fclose(file);
	
	file = fopen(arquivo, "a");// abrir o arquivo, "a" para atualizar o arquivo
	fprintf(file, ", ");// para acrecentar a ","
	fclose(file);//fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  // cargo a ser cadastrado
	scanf("%s", cargo);// salvar o valor da variavel no arquivo 
	
	file = fopen(arquivo, "a");// abrir o arquivo, "a" para atualizar o arquivo
	fprintf(file, cargo);// salvar o valor da variavel no arquivo 
	fclose(file);//fechar o arquivo

	
	system("pause"); //dar uma pausa 
}
int consulta(){
	setlocale(LC_ALL, "Portuguese"); // definido a linguagem
	//inicio das variaveis/string
	char cpf[40];
	char conteudo[200];
	//inicio das variaveis/string	
	
	printf("Digite o cpf a ser consultado: ");// digitar o cpf para fazer a consulta
	scanf("%s", cpf);// armazena na variavel
	
	
	FILE *file; //consultar o arquivo
	file = fopen(cpf, "r"); // abrir o arquivo, "r" serva para LER o arquivo 
	
	if(file == NULL){// file ta pedindo para ler o arquivo e o if faz a validacao dele
		printf("Não foi possivel abrir o arquivo, não localizado!. \n ");
	}
	while(fgets(conteudo, 200,file)!= NULL)// enquanto tiver conteudo nesse arquivo ele vai armazendado nessa vaviavel conteudo 
	{
		printf("\n Essa são as informações do usuario: ");// mostra as informacoes do usuario
		printf("%s", conteudo);
		printf("\n \n ");
	}
	system("pause");
	fclose(file);
}

int deletar(){
	char cpf[40];  // criamos a variavel cpf
	
	printf("Digite o CPF do usuario ser deletado: "); //digita o cpf que deseja deletar
	scanf("%s",cpf); // escaniar e armazena o cpf na variavel cpf
	
	remove(cpf); // remover o cpf
	FILE *file;
	file = fopen(cpf, "r");// "r" serve para revisar o arquivo
	
	if(file == NULL){ // validando caso nao encontre o cpf no sistema 
		printf("O usuario não se encontra no sistema!. \n ");
		system("pause");
	}
 	if(file != NULL){
 		printf("\t usuario deletado com sucesso! ");
 		fclose(file);
 		system("pause");
	 }
}


int main()
{
	int opcao = 0; // defininco as variaveis
	int laco = 1;
	for(laco=1;laco=1;){
	
		system("cls");
		setlocale(LC_ALL, "Portuguese"); // definido a linguagem
		
		printf("\t ### Cartório da EBAC ### \n \n "); // inicio do menu
		printf("Escolha a opção desejada no menu: \n \n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consutar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\n Opcao : ");// final do menu
		scanf("%d", &opcao);// armazenando a escolha do usuario 
		
		system("cls");// responsavel por limpa a tela
		
		switch(opcao){ //inicio da selecao do menu
			case 1:
			registro(); // chama a funcao
			break; 
			
			case 2:
			consulta(); // chama a funcao
			break;
			
			case 3:
			deletar(); // chama a funcao
			break;
			
			default:
			printf("\t -- Erro, essa opção não esta disponivel -- \n");
			system("pause");
			break;
		}
	}
}
