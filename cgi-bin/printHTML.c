#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printHTML.h"      //Identificação da Biblioteca criada

void impressaoHTML (int numeroResposta){
  FILE *pArquivo;
  char resposta[1000]={'\n'};
  char erro[7] = {' '},palavraEscolhida[15] = {' '},tracos[15] = {' '};

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
      if(pArquivo == NULL)
        printf("ERRO! 10.1");

      fscanf(pArquivo, "%s", erro); // Leitura do arquivo, daddos do arquivo vão para variavel (arquivo -> variavel)
      fclose(pArquivo);

      pArquivo = fopen("arquivos/tracos.txt","r");
      if(pArquivo == NULL)
        printf("ERRO! 10.2");

      fscanf(pArquivo,"%s", tracos);
      if(strlen(erro) == 0 ) // Se o jogador não errou nenhuma vez
        {
          snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman0.png\" id = \"imagemForca\">"  //Imagem da forca
                                              "<div1> %s </div1>"
                                              "<form action = \"jogo_forca.cgi\">"
                                              "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                              "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                              "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                              "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                              "</form>",tracos);
        }
      else if(strlen(erro) == 1) // Se o jogador errou 1 vez
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman1.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<div1>%s  </div1>"
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>",tracos);
      }
      else if(strlen(erro) == 2) // Se o jogador errou 2 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman2.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<div1> %s  </div1>"
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>",tracos);
      }
      else if(strlen(erro) == 3) // Se o jogador errou 3 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman3.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<div1>%s </div1>"
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>",tracos);
      }
      else if(strlen(erro) == 4) // Se o jogador errou 4 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman4.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<div1> %s  </div1>"
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>",tracos);
      }
      else if(strlen(erro) == 5) // Se o jogador errou 5 vezes
      {
        snprintf(resposta, sizeof resposta, "<img src=\"../media/hangman5.png\" id = \"imagemForca\">"  //Imagem da forca
                                            "<div1> %s </div1>"
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>",tracos);
      }
      // Caso o jogador erre pela 6 vez a flag 12 é atingga, portanto o jogador perde
      fclose(pArquivo);
      pArquivo = NULL;
        break;
      case 11:
        snprintf(resposta, sizeof resposta, "<div1>Cadastro feito com sucesso... Boa Sorte!<br></div1>"
                                            "<input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"history.go(-1)\">");
        break;

        // Se o jogador Perdeu
      case 12:
        pArquivo = fopen("arquivos/palavraEscolhida.txt","r"); // Abertura do arquivo da palavra escolhida randomicamente
        if(pArquivo == NULL)
          printf("ERRO! 12");
        fscanf(pArquivo, "%s", &palavraEscolhida); // leitura da palavra escolhida
        snprintf(resposta, sizeof resposta, "<divderrota> Derrota! </divderrota>"
                                            "<input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"parent.location=\'http://cap.dc.ufscar.br/~636932/jogo_forca_html.html\'\">"
                                            "<div1> A palavra era: %s </div1>", palavraEscolhida);
        fclose(pArquivo);
        remove("arquivos/tracos.txt");
        remove("arquivos/letrasErradas.txt");
        remove("arquivos/letrasCorretas.txt");
        remove("arquivos/palavraEscolhida.txt");
        pArquivo = NULL;

        break;

        // Se o jogador ganhou
      case 13:
        snprintf(resposta, sizeof resposta, "<divvitoria> Vitoria! </divvitoria>"
                                            "<input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"parent.location=\'http://cap.dc.ufscar.br/~636932/jogo_forca_html.html\'\">");
        remove("arquivos/tracos.txt");
        remove("arquivos/letrasErradas.txt");
        remove("arquivos/letrasCorretas.txt");
        remove("arquivos/palavraEscolhida.txt");

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
