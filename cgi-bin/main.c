#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastroJogador.h"
#include "printHTML.h"

int main(){
  int flag=0;
  char *link;

    link = getenv("QUERY_STRING");

  //Função de Verificadão de Jogadores
    flag = (verificacaoJogador(link));
    if (flag==0)
      flag = (novoJogador(link));

  //Função de impressão do HTML
    impressaoHTML(flag);

  return 0;
}
