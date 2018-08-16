#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
/*STRUCT de cadastro*/
typedef struct cadastro
{
	char nome[40], telefone[14], email[25];
    int idade;
    
}cadastro;
/* VARIAVEIS GLOBAIS */
	cadastro agenda[100];
	int opc, i=0, tamanho, aux=0, contador=0;
	char sair, voltar, busca[40];

/*CADASTRAR PESSOAS*/
int cadastrar_pessoa()
{
	if(contador !=100)// se o CONTADOR for diferente de 4 vai cadastrar uma nova pessoa!
	{
		for(i=aux;i<100;i++) // repeti��o para cadastrar usu�rios, quantos forem necess�rios at� cadastrar o total (ele pode casdastrar somente 5, 20, 27 etc) e n�o necessariamente 100 usu�rios.
		{
			tamanho = (strlen(agenda[i].nome));
				if((tamanho == 0) && (agenda[i].nome != '\0') && (contador != 100)) // verifica��o para saber se h� espa�o no "agenda[i].nome" se tive o cadastro � liberado.
				{
					printf("Informe o nome: ");
					scanf("%s",agenda[i].nome);
					printf("Informe o telefone: ");
					scanf("%s",agenda[i].telefone); 
					printf("Informe o email: ");
					scanf("%s",agenda[i].email); 
					printf("Informe a idade: ");
					scanf("%d",&agenda[i].idade);
					contador = contador + 1;
					printf("Deseja voltar ao menu principal? (S/N): ");
					fflush(stdin);
					scanf("%c",&voltar);
						if(voltar =='s') // se desejar voltar ao menu a variavel AUX guarda o valor que ele parou +1 para quando desejar voltar ao cadastro n�o sobrescrever o ultimo cadastro.
						{
							aux = i+1;
							system("cls");
							break;
						}
						
							if((voltar == 'n') && (*agenda[3].nome != 0))//Se chegar no fim do vetor de cadastro um usu�rio ele exige que volte ao menu, pois n�o ter� como adicionar mais pessoas.
							{
								while(voltar =='n') // enquanto n�o voltar ao menu fa�a....
								{
									system("cls");
									printf("A agenda est� cheia, digite (S) para voltar ao menu ");
									fflush(stdin);
									scanf("%c",&voltar);
									system("cls");
								}
							}
				}
		}
	}	
	else if (contador == 100) // senao se o contador for IGUAL a 4 o cadastro est� cheio!
	{
		printf("O cadastro est� cheio!\n");		
	}
}
/*PESQUISAR PELO NOME (exibir todas informa��es do usu�rio)*/
int pesquisar_pessoa()
{
	int teste = 0;
	i=0;
	printf("Digite o nome de quem deseja procurar: ");
	scanf("%s",busca);
		while (i<100) // procurar por toda agenda.
		{
			if(strcmp(busca,agenda[i].nome) ==0) // comparar se o que est� sendo procurado se encontra no vetor j� cadastrado.
			{
				system("cls");
				printf("Informa��es buscadas: \n");
				printf("Nome: %s\n", agenda[i].nome);
				printf("Telefone: %s\n", agenda[i].telefone);
				printf("Email: %s\n", agenda[i].email);
				printf("Idade: %d\n", agenda[i].idade);	
				teste = 1;
				printf("Deseja voltar ao menu principal? (S/N): ");
				fflush(stdin);
				scanf("%c",&voltar);
				if(voltar == 'n')
				{
					system("cls");
					pesquisar_pessoa();
				}
				else
				{
					system("cls");
					break;
				}
			}
			teste = teste + 1;
			i++;
		}
			if(teste == 100) // se chegar ao fim do vetor e nada for encontrado (busca = agenda[i].nome) essa pessoa n�o existe no cadastro.
			{
				printf("Essa pessoa n�o existe!\n");
				printf("Deseja voltar ao menu principal? (S/N): ");
				fflush(stdin);
				scanf("%c",&voltar);
					while (voltar != 's' && voltar !='n')
					{
						system("cls");
						printf("Informe (S/N)...\n");
						fflush(stdin);
						scanf("%c",&voltar);
					}
						if(voltar == 'n')
						{
							system("cls");
							pesquisar_pessoa();	
						}
						else if (voltar == 's')
						{
								system("cls");
						}
			}
}
/*EXIBIR TODAS INFORMA��ES DOS CADASTRADOS NA AGENDA*/
int exibir_pessoa()
{
	for(i=0;i<aux;i++)
	{
		printf("Nome: %s\n Telefone: %s\n Email: %s\n Idade: %d\n", agenda[i].nome, agenda[i].telefone, agenda[i].email, agenda[i].idade);
	}
}

int remover_pessoa()
{
	char nomeRemover[40];
	int resp, j=0;
	// 	char nome[40], telefone[14], email[25];
   // int idade;
	printf("Deseja remover 1 ou TODAS da lista?(1 ou 2): ");
	scanf("%d", &resp);
	
	if(resp == 1)
	{
		printf("Informe o nome completo da pessoa: ");
		scanf("%s", nomeRemover);
		for(i=0; i<4; i++)
		{
			if(strcmp(nomeRemover,agenda[i].nome) ==0)
			{
					for(j=i; j<4-1; j++)
					{
						strcpy(agenda[j].nome, agenda[j+1].nome);
						strcpy(agenda[j].telefone, agenda[j+1].telefone);
						strcpy(agenda[j].email, agenda[j+1].email);
						agenda[j].idade = agenda[j+1].idade;
					}
			    printf("Deseja voltar ao menu principal? (S/N): ");
				fflush(stdin);
				scanf("%c",&voltar);
				if(voltar == 'n')
				{
					remover_pessoa();
					system("cls");
				}
				else
				{
					system("cls");
					break;
				}
			}
			else if(i == 3)
			{
				strcpy(agenda[i].nome, NULL);
			    strcpy(agenda[i].telefone, NULL);
				strcpy(agenda[i].email, NULL);
				agenda[i].idade = NULL;
			}
		}
	}
}
/*PROGRAMA PRINCIPAL*/
int main()
{
	setlocale(LC_ALL, "Portuguese");
	voltar = 's';
while(voltar == 's') // Maneira que encontrei de deixar o programa rodando at� que ele seja fechado ou que a pessoa aperte a op��o de SAIR.
{
	printf("=======================\n");
	printf("AGENDA ELETR�NICA\n");
	printf("=======================\n");
	
	printf("1. ADICIONAR\n");
	printf("2. PESQUISAR\n");
	printf("3. EXIBIR\n");
	printf("4. REMOVER\n");
	printf("5. SAIR\n");
	printf("\nAcesso: ");
	scanf("%d",&opc);
	switch(opc)
        {
            case 1:
            	system("cls");
                	cadastrar_pessoa();
                break;
            case 2:
                system("cls");
                printf("Bem vindo ao menu de pesquisar um aluno! \n\n");
                pesquisar_pessoa();
                break;
            case 3:
                system("cls");
                printf("Bem vindo ao menu de exibir um aluno! \n\n");
                exibir_pessoa();
                break;
            case 4:
				system("cls");
	           	printf("Bem vindo ao menu de remover pessoa ! \n\n");
	           	remover_pessoa();
	           	break;
	        case 5:
                system("cls");
                printf("\nDeseja mesmo sair do programa? (s/n)");
                fflush(stdin);
                scanf("%c",&sair);
                if(sair == 's')
                {
                    printf("Pressione qualquer tecla para sair.\n");
                    exit(0);
                }
                else
                	system("cls");
                break;
            default:
                system("cls");
                printf("Digite um comando valido!\n\n");
    	}
}
return 0;
}
