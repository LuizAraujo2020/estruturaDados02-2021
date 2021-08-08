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


//##############################################################################
//MARK: - Declarações de Tipos
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


//##############################################################################
//MARK: - Protótipos

char menuPrincipal(void);

struct tAluno receberDadosAluno(struct tNo *inicio);
void listarAluno(struct tAluno, char);
// Entradas com validações
int atribuirMatricula(struct tNo *inicio);
char receberValidarNome(void);


// Utils
struct tNo* retornarPrimeiroNo(struct tNo *inicio);
struct tNo* retornarUltimoNo(struct tNo *inicio);

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
                printf("\n## CADASTRAR ALUNO\n");
                
                //add aluno
                aluno = receberDadosAluno(lista);
                
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
    
    /*
     Liberar as alocações
     */
    if(lista != NULL){                  // Checa se a lista não está vazia
        struct tNo *aux;
        p = lista;
        do{
            aux = p;
            p = p->prox;
            free(aux);
        }while(p != NULL);              /// Checa se o novo local é NULL
    }
    
    
    printf("\n\n\n");
    return 0;
}

//##############################################################################
//MARK: - FUNÇÕES







/*
 Menus
 */

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




//##############################
//MARK: - Factories
/*
 Alunos
 */
struct tAluno receberDadosAluno(struct tNo *inicio) {
    char ok = 's';
    
    struct tAluno aluno;
    
    if(inicio == NULL){
        aluno.matricula = 0;
    } else {
        aluno.matricula = atribuirMatricula(inicio);
    }
    
//    strcpy(aluno.nome, receberValidarNome());
    
    do{
        printf("\nNOME : ");
        fflush(stdin);
        gets(aluno.nome);
        
        if((strcmp(aluno.nome, " ") == 0) || (strcmp(aluno.nome, "") == 0) || (strlen(aluno.nome) < 3)){
            printf("\nNome invalido!\n");
            ok = 'n';
        } else {
            ok = 's';
        }
        
    }while(ok != 's');
    
    printf("\nSERIE: ");
    scanf("%d", &aluno.serie);
    
    printf("TURMA: ");
    fflush(stdin);
    scanf("%c", &aluno.turma);
    aluno.turma = toupper(aluno.turma);
    
    return aluno;
}

/*
 Entradas & validações
 */

int atribuirMatricula(struct tNo *inicio) {
    int novaMatricula = 1;
    
    struct tNo *aux = inicio;
    
    while(aux->prox != NULL){
        aux = aux->prox;
        novaMatricula++;// Tive que fazer incrementando baseado na qtd de elementos porque não estava passando da mat. 1
//        printf("\n\nDentro matricula: %d\n\n", novaMatricula);
    };
    
    return novaMatricula;
}

char receberValidarNome(void){
    char nome[20], ok = 's';
    
    do{
        printf("\nNOME : ");
        fflush(stdin);
        gets(nome);
        
        if((strcmp(nome, " ") == 0) || (strcmp(nome, "") == 0) || (strlen(nome) < 3)){
            printf("\nNome invalido!\n");
            ok = 'n';
        }
        
    }while(ok != 's');
    
    return nome;
}




// Fim Factories
//##############################


//##############################
//MARK: - Utils

//Achar o primeiro nó. inicio = ponteiro para o primeiro nó
struct tNo* retornarPrimeiroNo(struct tNo *inicio) {
    struct tNo *no;
    
    no = inicio;
    
    return no;
}

//Achar o último nó
struct tNo* retornarUltimoNo(struct tNo *inicio) {
    struct tNo *p = inicio;
    
    printf("\n\nMatricula dentro do while: %d", p->dado.matricula);
    printf("\nNome dentro do while: %s\n\n", p->dado.nome);
    while(p->prox != NULL){
        printf("\n\nMatricula dentro do while: %d", p->dado.matricula);
        printf("\nNome dentro do while: %s\n\n", p->dado.nome);
        p = p->prox;
    };
    
    printf("\n\nUltimo nó matricula: %d\n\n", p->dado.matricula);
    
    return p;
}

//Achar a última matrícula
//int ultimaMatrícula(void) {
//    int ultimaMatrícula;
//    struct tNo ultimoNo = ultimoNo();
//
//
//
//    return ultimaMatrícula;
//}



void listarAluno(struct tAluno aluno, char formatoLista){
    
    if(formatoLista == 's') {
        printf("\n%05d   %-20s   %d%c", aluno.matricula, aluno.nome, aluno.serie, aluno.turma);
    } else {
        printf("\nMAT. : %05d", aluno.matricula);
        printf("\nNOME : %-20s", aluno.nome);
        printf("\nTURMA: %d%c", aluno.serie, aluno.turma);
    }
}
