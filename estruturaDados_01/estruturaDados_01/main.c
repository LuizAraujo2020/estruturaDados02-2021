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

// Declaracoes de Tipos
struct tAluno {
    int matricula;
    char nome[20];
    int serie;
    char turma;
};


// Prototipos
struct tAluno receberDadosAluno();

int main(int argc, const char * argv[]) {
// Declaracoes
    struct tAluno aluno;
    
    //add aluno
    aluno = receberDadosAluno();
    
    printf("%-5s   %-20s   %s", "MAT", "NOME DO ALUNO", "SERIE/TURMA\n");
    printf("%05d | %-20s | %d%c", aluno.matricula, aluno.nome, aluno.serie, aluno.turma);
    
// Instrucoes
    
    
    
    printf("\n\n\n");
    return 0;
}


// FUncoes

// Factories

struct tAluno receberDadosAluno(){
    
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
    
    return aluno;
}
