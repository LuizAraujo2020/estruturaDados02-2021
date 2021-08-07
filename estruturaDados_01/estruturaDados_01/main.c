//
//  main.c
//  estruturaDados_01
//
//   Lista de alunos:
//    ESCOLA DA VIDA
//
//  Created by Luiz Carlos da Silva Araujo on 07/08/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declarações de Tipos
struct tAluno {
    int matricula;
    char nome[20];
    int serie;
    char turma;
};

struct tNo {
    struct tAluno dado;
    struct tNo *prox;
};


// Protótipos

char menuPrincipal(void);

struct tAluno receberDadosAluno(void);
void listarAluno(struct tAluno, char);

int main(int argc, const char * argv[]) {
// Declarações
    char opcaoMenuPrincipal = '1';
    
    
    struct tAluno aluno;
    
    // início da lista
    struct tNo *lista = NULL;
    
    // elemento/ponteiro auxiliar
    struct tNo *p;
    
    
    
// Instruções
    do{
        opcaoMenuPrincipal = menuPrincipal();
        
        switch (opcaoMenuPrincipal) {
            case '1':
                printf("\n## CADASTRAR ALUNO");
                
                //add aluno
                aluno = receberDadosAluno();
                
                
                
                //lista encadeada de alunos
                p = malloc(sizeof(struct tNo));
                
                p->dado = aluno;                 // p recebe os dados do aluno atual
                p->prox = lista;                 // p passa a apontar para onde a lista estava apontando, início anterior
                lista = p;
                
                
                
                
                break;
            case '2':
                if(lista != NULL) {
                    printf("\n## LISTAR ALUNO ##\n");
                    printf("\n%-5s   %-20s   %s", "MAT", "NOME DO ALUNO", "SERIE/TURMA");
                    
                    struct tNo *aux = lista;
                    listarAluno(p->dado, 's');
                    while(aux->prox != NULL){
                        aux = aux->prox;
                        listarAluno(aux->dado, 's');
//                        listarAluno(p->dado, 'n');
//                        aux = aux->prox;
                    };
                    printf("\n\n");
                    
                } else {
                    printf("\n## NENHUM ALUNO CADASTRADO!\n");
                }
                break;
            case 's':
            case 'S':
                printf("\n## ENCERRANDO PROGRAMA");
                
                
                break;
        }
        
        
    
    }while(opcaoMenuPrincipal != 's' && opcaoMenuPrincipal != 'S');
    
    //free pointers
    
    struct tNo *aux = lista;
    
    if(lista != NULL){
        do{
            p = aux;
            free(p);
            aux = aux->prox;
        }while(aux->prox != NULL);
    }
    printf("\n\n\n");
        
    return 0;
}


// Funções
char menuPrincipal(){
    char opcao = '1';
    
    printf("\n### MENU PRINCIPAL ###\n");
    do{
        printf("\n1) Cadastrar aluno;");
        printf("\n2) Listar alunos;");
        printf("\nS) Encerrar");
        printf("\nOPCAO: ");
        fflush(stdin);
        scanf("%c", &opcao);
        if(opcao != '1' && opcao != '2' && opcao != 's' && opcao != 'S'){
            printf("\nOpcao invalida!");
        }
    }while(opcao != '1' && opcao != '2' && opcao != 's' && opcao != 'S');
    
    return opcao;
}




// Factories

struct tAluno receberDadosAluno(void){
    
    struct tAluno aluno;
    
    printf("### INCLUIR ALUNO ###\n");
    
    printf("\nMAT. : ");
    scanf("%d", &aluno.matricula);
    
    printf("NOME : ");
    fflush(stdin);
    gets(aluno.nome);
    
    printf("\nSERIE: ");
    scanf("%d", &aluno.serie);
    
    printf("TURMA: ");
    fflush(stdin);
    scanf("%c", &aluno.turma);
    aluno.turma = toupper(aluno.turma);
    
    return aluno;
}

void listarAluno(struct tAluno aluno, char formatoLista){
    
    if(formatoLista == 's') {
        printf("\n%05d   %-20s   %d%c", aluno.matricula, aluno.nome, aluno.serie, aluno.turma);
    } else {
        printf("\nMAT. : %05d", aluno.matricula);
        printf("\nNOME : %-20s", aluno.nome);
        printf("\nTURMA: %d%c", aluno.serie, aluno.turma);
    }
}
