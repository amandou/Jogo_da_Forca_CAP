#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastroJogador.h"      //Identificação da Biblioteca criada

//Função para não salvar RA's repetidos
int antigoJogador (int ra){
  int raArquivo, flag=0;
  char linha[100];
  FILE *pJogadores;

  pJogadores = fopen("jogadores.txt", "r");
  while((fgets(linha, sizeof(linha), pJogadores) != NULL) && (flag==0)){
    sscanf(linha, "RA: %d", &raArquivo);
    if (raArquivo == ra)
      flag=10;
  }
  return flag;
}

//Função para validar as informações
int verificacaoJogador (char* link){
  int flag=0;
  struct jogador{
      char nome[60];
      int ra, partidas;
  };
  struct jogador jogador;
  sscanf(link, "nome=%[^&]&ra=%d", jogador.nome, &jogador.ra);
  if (strlen(jogador.nome) == 0)
    flag=2;
  else if (jogador.ra <= 0)
    flag=3;
  else if (antigoJogador(jogador.ra) != 0)
    flag=10;

  return flag;
}

//Função para cadastro de novos jogadores
int novoJogador (char* link){
  int flag=0;
  struct jogador{
      char nome[60];
      int ra, partidas;
  };
  struct jogador jogador;
  FILE *pJogadores;

  if(pJogadores == NULL)
    flag=1;
  else{
    sscanf(link, "nome=%[^&]&ra=%d", jogador.nome, &jogador.ra);
    pJogadores = fopen("jogadores.txt", "a");
    fprintf(pJogadores, "NOME: %s\n", jogador.nome);
    fprintf(pJogadores, "RA: %d\nPARTIDAS: %d\n\n", jogador.ra, jogador.partidas=0);
  }
  fclose(pJogadores); pJogadores = NULL;
  return flag;
}
