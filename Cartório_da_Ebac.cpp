#include <stdio.h> //biblioteca de interação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das string
#include <string.h>  //biblioteca responsável por cuidar das strings

int registro()  // Função responsável por cadastrar  os usuários no sistema
{
	// início da criação de variáveis/string
	char arquivo[40]; // "char" variável do tipo caractere / "Arquivo" Nome da variável / "[]" Significa que é uma string / "40" Significa quantidade de caracteres
	char cpf[40]; // "char" Variável do tipo caractere / "cpf" Nome da variável / "[]" Siginifica que é uma string / "40" Significa que posso por 40 caractéres
	char nome[40]; // "char" Variável do tipo caractere / "nome" Nome da variável / "[]" Significa que é uma string / "40" Significa que posso por 40 caractéres
	char sobrenome[40]; // "char" Variável do tipo caractere / "sobrenome" Nome da váriavel / "[]" Significa que é uma string / "40" Significa que posso por 40 caracteres
	char cargo[40]; // "char" Variável do tipo caractere / "cargo" Nome da variável / "[]" Significa que é uma string / "40" Significa que posso colocar até 40 caracteres
	// final da criação de variáveis/string
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valor das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável
	fclose(file); // fecha o aqruivo
	
	file = fopen(arquivo, "a"); // file é o nome do arquivo e o "a" Significa edição
	fprintf(file,","); // Salva o valor da variável e o "," adiciona uma vírgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("digite o nome a ser cadastrado: "); // pergunta ao usuário 
	scanf("%s", nome); // Coleta informações do cliente
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,nome); // Salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file, ","); // salva o valor na variável e o "," tem o valor adicionado no arquivo
	fclose(file); // fecha o arquivo
	
	printf("digite o sobrenome a ser cadastrado: "); // pergunta ao usuário
	scanf("%s", sobrenome); // recebe as informações do usuário
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa editar
	fprintf(file,sobrenome); // salva o valor da variáel no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);

	system("pause"); // pausa antes de fechar a tela

}

int consulta() 
{
		setlocale (LC_ALL, "portuguese");//definindo a linguagem

	// Início da criação de variáveis
	char cpf[40];
	char conteudo[200];
	// Fim da criação de variáveis
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("não foi possível abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssa são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");	
	}
	
	system("pause");
	

}

int deletar()
{
	char cpf[40];
		
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0;//Definindo variáveis
	int x=1;
	
	for(x=1;x=10;x++)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese");//Definindo a linguagem 
	
		printf("### Cartório da EBAC ###\n\n"); //início do menu 
		printf("Escolha a opção desejada do menu:\n\n"); 	
		printf("\t1 - Registrar nomes:\n");
		printf("\t2 - Consultar nomes:\n");
		printf("\t3 - Deletar nomes:\n\n");
		printf("\t4 - Sair do programa\n\n");
		printf("opção: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usuário
	
		system("cls"); // Responsável por limpar a tela 
		
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break; // fecha o case1
			
			case 2:
			consulta(); // chamda de funções
			break; // fecha o case2
			
			case 3:
			deletar(); // chamada da função deletar
			break; // fecha o case3
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
			
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause"); // pausa a tela antes de sair
			break; // fecha o default
		}
		
		
		
		
		
	
	}	
}








