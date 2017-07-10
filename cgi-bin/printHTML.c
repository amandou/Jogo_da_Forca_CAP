#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printHTML.h"      //Identificação da Biblioteca criada

void impressaoHTML (int numeroResposta){
  char resposta[1000]={'\n'};

  switch(numeroResposta){
      case 1:
        snprintf(resposta, sizeof resposta, "Erro na abertura dos arquivos!");
        break;
      case 2:
        snprintf(resposta, sizeof resposta, "Digite um nome!");
        break;
      case 3:
        snprintf(resposta, sizeof resposta, "Digite um RA válido!");
        break;
      default:
        snprintf(resposta, sizeof resposta, "Tudo certo até o momento");
  }

//Código HTML
  printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);
  printf("<!DOCTYPE html>");
  printf("<html lang=\"en\">");

  printf("<head>");
  printf("<meta charset=\"utf-8\">");
  printf("<title>Jogo da Forca</title>");
  printf("<link href = "jogo_forca_css.css" rel="stylesheet" /> "); // colocar o css aqui???
  printf("</head>");

  printf("<body>");
  printf("<!-- page content -->");
  printf("%s", resposta);
  printf("</body>");
  printf("</html>");
}
