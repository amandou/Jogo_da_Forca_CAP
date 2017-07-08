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
  else if(sscanf(pLink, "nome=%[^&]&ra=%d", jog.nome, &jog.ra)){
    if(jog.ra <= 0)
      snprintf(resposta, sizeof resposta, "Digite um RA válido! %d", jog.ra);
    else if(strlen(jog.nome) == 0)
      snprintf(resposta, sizeof resposta, "Digite um nome!");
    else
      pJogadores = fopen("jogadores.txt", "a");
      fprintf(pJogadores, "Nome: %s\n", jog.nome);
      fprintf(pJogadores, "RA: %d\nPartidas: %d\n\n", jog.ra, jog.partidas=0);
  }

  printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);
  printf("<!DOCTYPE html>");
  printf("<html lang=\"en\">");
  printf("<head>");
  printf("<meta charset=\"utf-8\">");
  printf("<title>Jogo da Forca</title>");
  printf("</head>");
  printf("<body>");
  printf("<!-- page content -->");
  printf("%s", resposta);
  printf("</body>");
  printf("</html>");
}
