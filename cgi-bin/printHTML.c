#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printHTML.h"      //Identificação da Biblioteca criada

void impressaoHTML (int numeroResposta){
  FILE *pArquivo;
  char resposta[1000]={'\n'};
  char erro[7] = {' '};

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

        // Se o jogador já tiver conta criada
      case 10:

      pArquivo = fopen("arquivos/letrasErradas.txt","r"); // Abertura do arquivo letras erradas
      fscanf(pArquivo, "%s", erro); // Leitura do arquivo, daddos do arquivo vão para variavel (arquivo -> variavel)

      if(strlen(erro) == 0) // Se o jogador não errou nenhuma vez
        {
          snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman0.png\" id = \"imagemForca\">"  //Imagem da forca
                                              "<form action = \"jogo_forca.cgi\">"
                                              "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                              "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                              "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                              "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                              "</form>");
        }
      else if(strlen(erro) == 1) // Se o jogador errou 1 vez
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman1.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>");
      }
      else if(strlen(erro) == 2) // Se o jogador errou 2 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman2.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>");
      }
      else if(strlen(erro) == 3) // Se o jogador errou 3 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman3.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>");
      }
      else if(strlen(erro) == 4) // Se o jogador errou 4 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman4.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>");
      }
      else if(strlen(erro) == 5) // Se o jogador errou 5 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman5.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>");
      }
      // Caso o jogador erre pela 6 vez a flag 12 é atingga, portanto o jogador perde
      fclose(pArquivo);
      pArquivo = NULL;
        break;
      case 11:
        snprintf(resposta, sizeof resposta, "<div1>Cadastro feito com sucesso... Boa Sorte!<br></div1>"
                                            "<input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"history.go(-1)\">");
        break;

      case 12:
        snprintf(resposta, sizeof resposta, "Derrota <br>");
                                            //"<input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"url\">"
        break;

      case 13:
        snprintf(resposta, sizeof resposta, "Vitoria <br>");
                                            //"<input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"url\">"
        break;
  }

//Código HTML
  printf("%s%c%c\n","Content-Type:text/html;charset=UTF-8",13,10);
  printf("<!DOCTYPE html>");
  printf("<html lang=\"en\">");
  printf("<head>");
  printf("<meta charset=\"utf-8\">");
  printf("<title>Jogo da Forca</title>");
  printf("<center><img src=\"../media/logo.png\"></center>");
  printf("<link href = \"../jogo_forca_css.css\" rel=\"stylesheet\" />");
  printf("</head>");
  printf("<body>");
  printf("<!-- Conteudo da Pagina -->");
  printf("%s", resposta);
  printf("<div id=\"fooster\">");
  printf("Trabalho feito por Amanda Lima Ribeiro e Vanderlei de Brito Junior - UFSCar - CAP 2017/01");
  printf("</div>");
  printf("</body>");
  printf("</html>");
}
