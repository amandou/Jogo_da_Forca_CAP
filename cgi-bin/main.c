#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastroJogador.h"
#include "printHTML.h"

int main(){
  int flag=0;
  char *link;


  // abrir o arquivo que contem as palavras a serem sorteadoas
    char *parq = fopen("palavras.txt","r");
    int nlinha;
    char ch,palavra;

    link = getenv("QUERY_STRING");

  //Função de Verificação de Jogadores
    flag = (verificacaoJogador(link));
    if (flag==0)
      flag = (novoJogador(link));

  //Função de impressão do HTML
    impressaoHTML(flag);


/*    //Sorteio das palavras

    //1. contar o numero de linhas do arquivo
        while ((ch=fgetc(arq))!= EOF )
            if(ch == '\n')
                nlinha++;
    //2. usar a função rand para escolher a palavra
*/
  return 0;
}
