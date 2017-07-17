#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printHTML.h"      //Identificação da Biblioteca criada
                    // numeroResposta recebe flag
void impressaoHTML (int numeroResposta){
  FILE *pArquivo;
  char resposta[1000]={'\n'};
  char erro[7] = {' '},palavraEscolhida[15] = {' '},tracos[15] = {' '};

  switch(numeroResposta){
      case 1: // equivalente a flag 01
        snprintf(resposta, sizeof resposta, "Erro na abertura dos arquivos!");
        break;
      case 2: // equivalente a flag 02
        snprintf(resposta, sizeof resposta, "<div1>Digite um nome!</div1>");
        break;
      case 3: // equivalente a flag 03
        snprintf(resposta, sizeof resposta, "<div1>Digite um RA válido!</div1>");
        break;

      // Se o jogador já tiver conta criada equivalente a flag 10
      case 10:

      pArquivo = fopen("arquivos/letrasErradas.txt","r"); // Abertura do arquivo letras erradas
      if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
        printf("ERRO! 10.1");

      fscanf(pArquivo, "%s", erro); // Leitura do arquivo letrasErradas, dados do arquivo vão para variavel erro (arquivo -> variavel)
      fclose(pArquivo);

      pArquivo = fopen("arquivos/tracos.txt","r");
      if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
        printf("ERRO! 10.2");
      fscanf(pArquivo,"%s", tracos); // Leitura do arquivo tracos, dados do arquivo vão para variavel tracos

      //Verificação se o jogador errou uma vez  e se o erro é uma letra valida
      if(strlen(erro) == 1 && (erro[0]>='A' && erro[0]<='Z'))
        {
        snprintf(resposta, sizeof resposta, "<br><div3> Letras Erradas: </div3> <div4> %s </div4>"
                                            "<img src=\"../media/hangman0.png\" id = \"imagemForca\"><br>"  //Imagem da forca
                                            "<br><div2> %s </div2>"
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>", erro, tracos);
        }
      /*
      Se não tiver apenas um erro, entra na outra condição e verifica o tamanho da string erro
      */
      else {
        snprintf(resposta, sizeof resposta, "<br><div3> Letras Erradas: </div3> <div4> %s </div4>"
                                            "<img src=\"../media/hangman%d.png\" id = \"imagemForca\"><br>"  //Imagem da forca
                                            "<br><div2> %s </div2>"
                                            "<form action = \"jogo_forca.cgi\">"
                                            "<input type=\"hidden\" name=\"nome\" value=\"XXXX\">"
                                            "<input type=\"hidden\" name=\"ra\" value=\"1234\">"
                                            "<div1> <label> TENTATIVA: <input name=\"letra\" size=\"2\"> </label> </div1>"   // Criação do formulario para o usuário digitar a letra
                                            "<input type = \"submit\" id=\"botaoEscrever\" value=\"\">" //Botão de tentativa
                                            "</form>", erro,strlen(erro), tracos);

      }
      // Caso o jogador erre pela 6 vez a flag 12 é atingga, portanto o jogador perde
      fclose(pArquivo);
      pArquivo = NULL;
        break;

      case 11: //Novo cadastro, equivalente a flag 11
        snprintf(resposta, sizeof resposta, "<div1>Cadastro feito com sucesso... Boa Sorte!<br></div1>"
                                            "<input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"history.go(-1)\">");
        break;

        // Se o jogador Perdeu, equivalente a flag 12
      case 12:
        pArquivo = fopen("arquivos/palavraEscolhida.txt","r"); // Abertura do arquivo da palavra escolhida randomicamente
        if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
          printf("ERRO! 12");
        fscanf(pArquivo, "%s", &palavraEscolhida); // leitura da palavra escolhida
        snprintf(resposta, sizeof resposta, "<divderrota> Derrota! </divderrota><br>"
                                            "<br><div1> A palavra era: %s </div1>" //Apresentação da palavra sorteado aleatoriamente
                                            "<br><input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"parent.location=\'http://cap.dc.ufscar.br/~743504/jogo_forca_html.html\'\">", palavraEscolhida); //Botão de voltare
        fclose(pArquivo);
        //Fechamento dos arquivos
        remove("arquivos/tracos.txt");
        remove("arquivos/letrasErradas.txt");
        remove("arquivos/letrasCorretas.txt");
        remove("arquivos/palavraEscolhida.txt");
        pArquivo = NULL;
        break;

        // Se o jogador ganhou
      case 13:
        pArquivo = fopen("arquivos/palavraEscolhida.txt","r"); // Abertura do arquivo da palavra escolhida randomicamente
        if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
          printf("ERRO! 13");
        fscanf(pArquivo, "%s", &palavraEscolhida); // leitura da palavra escolhida
        snprintf(resposta, sizeof resposta, "<divvitoria> Vitoria! </divvitoria><br>"
                                            "<br><div1> A palavra era: %s </div1>" // Apresnetação da palavra sorteada aleatoriamente
                                            "<br><input type = \"submit\" id=\"botaoVoltar\" value=\"\" onClick=\"parent.location=\'http://cap.dc.ufscar.br/~743504/jogo_forca_html.html\'\">", palavraEscolhida); //Botão de voltar
        fclose(pArquivo);
        //Fechamento dos arquivos
        remove("arquivos/tracos.txt");
        remove("arquivos/letrasErradas.txt");
        remove("arquivos/letrasCorretas.txt");
        remove("arquivos/palavraEscolhida.txt");
        pArquivo = NULL;
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
  printf("<div id=\"footer\">");
  printf("Trabalho feito por Amanda Lima Ribeiro e Vanderlei de Brito Junior - UFSCar - CAP 2017/01");
  printf("</div>");
  printf("</body>");
  printf("</html>");
}
