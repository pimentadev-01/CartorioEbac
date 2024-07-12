#include <stdio.h> //biblioteca de intera��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string
#include <string.h>  //biblioteca respons�vel por cuidar das strings

int registro()  // Fun��o respons�vel por cadastrar  os usu�rios no sistema
{
	// in�cio da cria��o de vari�veis/string
	char arquivo[40]; // "char" vari�vel do tipo caractere / "Arquivo" Nome da vari�vel / "[]" Significa que � uma string / "40" Significa quantidade de caracteres
	char cpf[40]; // "char" Vari�vel do tipo caractere / "cpf" Nome da vari�vel / "[]" Siginifica que � uma string / "40" Significa que posso por 40 caract�res
	char nome[40]; // "char" Vari�vel do tipo caractere / "nome" Nome da vari�vel / "[]" Significa que � uma string / "40" Significa que posso por 40 caract�res
	char sobrenome[40]; // "char" Vari�vel do tipo caractere / "sobrenome" Nome da v�riavel / "[]" Significa que � uma string / "40" Significa que posso por 40 caracteres
	char cargo[40]; // "char" Vari�vel do tipo caractere / "cargo" Nome da vari�vel / "[]" Significa que � uma string / "40" Significa que posso colocar at� 40 caracteres
	// final da cria��o de vari�veis/string
	
	printf("Digite o cpf a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valor das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel
	fclose(file); // fecha o aqruivo
	
	file = fopen(arquivo, "a"); // file � o nome do arquivo e o "a" Significa edi��o
	fprintf(file,","); // Salva o valor da vari�vel e o "," adiciona uma v�rgula no arquivo
	fclose(file); // fecha o arquivo
	
	printf("digite o nome a ser cadastrado: "); // pergunta ao usu�rio 
	scanf("%s", nome); // Coleta informa��es do cliente
	
	file = fopen(arquivo, "a"); // abre o arquivo
	fprintf(file,nome); // Salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo
	fprintf(file, ","); // salva o valor na vari�vel e o "," tem o valor adicionado no arquivo
	fclose(file); // fecha o arquivo
	
	printf("digite o sobrenome a ser cadastrado: "); // pergunta ao usu�rio
	scanf("%s", sobrenome); // recebe as informa��es do usu�rio
	
	file = fopen(arquivo, "a"); // abre o arquivo e o "a" significa editar
	fprintf(file,sobrenome); // salva o valor da vari�el no arquivo
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

	// In�cio da cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	// Fim da cria��o de vari�veis
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("n�o foi poss�vel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssa s�o as informa��es do usu�rio:");
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
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0;//Definindo vari�veis
	int x=1;
	
	for(x=1;x=10;x++)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "portuguese");//Definindo a linguagem 
	
		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu 
		printf("Escolha a op��o desejada do menu:\n\n"); 	
		printf("\t1 - Registrar nomes:\n");
		printf("\t2 - Consultar nomes:\n");
		printf("\t3 - Deletar nomes:\n\n");
		printf("\t4 - Sair do programa\n\n");
		printf("op��o: ");//Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio
	
		system("cls"); // Respons�vel por limpar a tela 
		
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); // chamada de fun��es
			break; // fecha o case1
			
			case 2:
			consulta(); // chamda de fun��es
			break; // fecha o case2
			
			case 3:
			deletar(); // chamada da fun��o deletar
			break; // fecha o case3
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
			
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause"); // pausa a tela antes de sair
			break; // fecha o default
		}
		
		
		
		
		
	
	}	
}








