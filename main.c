#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //Biblioteca resposável por cuidar das string


int registro()
{
	char arquivo[41];
	char cpf[41];
	char nome[41];
	char sobrenome[41];
	char cargo[41];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings.
	
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
		printf("\nArquivo não localizado\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
	
}

int deletar()
{
	printf("Você escolheu deletar nomes!\n");
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
		printf("Consultório DR.Japa\n\n");
	
		printf("Escolha a opção desejada do menu.\n\n"); //Inicio do menu.
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema");

		scanf("%d", &opcao);//Armazenando a opção.
	
		system("cls");
	
		switch(opcao) // Estrutura de condição && inicio da seleção.
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
		
			default: // fim da seleção.
			printf("Essa opção não está disponível!\n\ntente outro digito.\n");
			system("pause");
			break;
	
		}
	}
}

