#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca respos�vel por cuidar das string


int registro()
{
	char arquivo[41];
	char cpf[41];
	char nome[41];
	char sobrenome[41];
	char cargo[41];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings.
	
	FILE *file; //cria o arquivo 
	file =fopen(arquivo, "w"); //cria o arquivo 
	fprintf(file,cpf); //salvo o valor da varialvel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s" ,sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Dados registrados!\n\n");
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nArquivo n�o localizado\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
}

int deletar()
{
	printf("Voc� escolheu deletar nomes!\n");
	system("pause"); 
}


int main()
	{
	
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
		printf("Consult�rio DR.Japa\n\n");
	
		printf("Escolha a op��o desejada do menu.\n\n"); //Inicio do menu.
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema");

		scanf("%d", &opcao);//Armazenando a op��o.
	
		system("cls");
	
		switch(opcao) // Estrutura de condi��o && inicio da sele��o.
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema.\n");
			return 0;
			break;
		
			default: // fim da sele��o.
			printf("Essa op��o n�o est� dispon�vel!\n\ntente outro digito.\n");
			system("pause");
			break;
	
		}
	}
}

