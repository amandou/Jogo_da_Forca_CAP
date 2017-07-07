#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct jogador{
  char nome[50];
  int ra, partidas;
};

int main(){

  struct jogador jog;
  char *pLink;
  char resposta[1000] = {'\n'};
  FILE *pJogadores;

  pLink = getenv("QUERY_STRING");
  if (pLink == NULL)
    snprintf(resposta, sizeof resposta, "Ocorreu um erro!\n");
  else if(sscanf(pLink, "nome=%[^\n]&ra=%d", jog.nome, &jog.ra)){
    if(jog.ra <= 0)
      snprintf(resposta, sizeof resposta, "Digite um RA válido!");
    else if(strlen(jog.nome) == 0)
      snprintf(resposta, sizeof resposta, "Digite um nome!");
    else
      pJogadores = fopen("jogadores.txt", "a");
      fprintf(pJogadores, "Nome: %s\n", jog.nome);
      fprintf(pJogadores, "RA: %d\nPartidas: %d", jog.ra, jog.partidas=0);
  }

  return 0;
}
