#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
		
int registro()// funcao responsavel por cadastrar os usuarios no sistema
{
	// inicio de criacao de variaveis-Strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criacao das variaveis-strings
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");// coletando informacao do usuario
	scanf("%s",nome);// refere-se a string
	
	file = fopen(arquivo, "a"); //criar arquivo e o "a" significa atualizar para incluir dados
	fprintf(file,nome);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//coletando informacao do usuario
	scanf("%s",sobrenome);// %s refere-se a string
	
	file = fopen(arquivo, "a");//criar arquivo e o "a" significa atualizar para incluir dados
	fprintf(file,sobrenome);//salvo o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//coletando informacao do usuario
	scanf("%s",cargo);// %s refere-se a string
		
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
    }
	

int consulta()// funcao responsavel por consultar um usuario no sistema
{
	   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	    
	  // inicio de criacao de variaveis-Strings  
	char cpf[40];
	char conteudo[200];
	// final da criacao das variaveis
	
    printf("Digite o CPF a ser consultado: "); ///coletando informacao do usuario
    scanf("%s",cpf); //coletando informacao do usuario
  	
    FILE *file;// cria o arquivo
    file = fopen(cpf,"r");// cria o arquivo e o "r" significa ler
  	
    if(file == NULL)
{
	printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
}
	
    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\n Essas sao as informacoes do usuario: ");
	printf("%s", conteudo);// %s refere-se a string
		printf("\n\n");// gera espacamento
}
  	
system ("pause");
}


int deletar()//funcao responsavel por deletar os usuarios no sistema
{
	// inicio de criacao de variaveis-Strings  
	char cpf[40];
	// final da criacao das variaveis-strings
	
	printf("Digite o CPF do usuario a ser deletado:");//coletando informacao do usuario
	scanf ("%s", cpf); // %s refere-se a string
	
	remove(cpf);//remove o CPF do sistema
	
	FILE *file;// Criar arquivo
	file = fopen(cpf,"r");//cria o arquivo e o "r" significa ler
	
	if(file==NULL)
	{
		printf("usuario deletado com sucesso.\n");
		system("pause");
	}
}
	
int main()
{

	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");// responsavel por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opcao desejada do menu: \n\n");// escolha da opcao no menu
		printf("\t1 - Registrar nomes\n");//registrar nomes no sistema
		printf("\t2 - Consultar nomes\n");//consultar nomes no sistema
		printf("\t3 - Deletar nomes\n\n");//deletar nomes no sistema
		printf("\t4 - Sair do arquivo\n\n");//Sair do arquivo
		printf("Opcao: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuario
		
		system("cls");// responsavel por limpar a tela
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro();//chamada de funcoes
			break;
			
			case 2:
			consulta();//chamada das funcoes
			break;
		
			case 3:
			deletar();//chamada das funcoes
			break;

			case 4:
			Printf("Obrigada por utilizar o nosso sistema");// sair do sistema
			return 0;
			break;	
		
			default:
			printf("Essa opcao nao está disponivel!\n");
			system("pause");
			break;
		} //fim da seleção
			
	}	
}
