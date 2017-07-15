#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "cadastroJogador.h"
#include "printHTML.h"

int main(){
  int i, flag=0, certa=0;
  int nLinhas=0, tamanhoPalavra=0;
  char caracter, caracterEscolhido;
  char* link, palavra[15]={' '}, acerto[15]={' '};
  char letrasErradas[7]={' '}, dados[45];
    srand(time(NULL));
    FILE *pArquivo;
    link = getenv("QUERY_STRING");

    strcpy(dados,link);

    //Função de Verificadão de Jogadores
      flag = (verificacaoJogador(link));
      if(flag==0){
        flag = (novoJogador(link));
      }

      //Se flag for igual a 10, cadastro criado e jogo iniciado
    if(flag == 10){
      if((pArquivo=fopen("arquivos/palavraEscolhida.txt", "r")) == NULL){
        //Contagem de Linhas do Arquivo
          pArquivo=fopen("arquivos/palavras.txt", "r");
          while(fscanf(pArquivo, "%c", &caracter) != EOF){
            if(caracter == '\n'){
              nLinhas+=1;
            }
          }
        //Escolhendo palavra aleatóriamente
          rewind(pArquivo);
            for(i=0; i<rand()%nLinhas+1; i++)
            {
              fscanf(pArquivo, "%s\n", &palavra);
            }
            fclose(pArquivo);

        //Gravando palavra escolhida no arquivo (variavel -> arquivo)
          pArquivo = fopen("arquivos/palavraEscolhida.txt","w");
          fprintf(pArquivo, "%s", palavra);
          fclose(pArquivo);
          pArquivo = fopen("arquivos/tracos.txt", "w");
          for(i=0; i<strlen(palavra); i++){
            fprintf(pArquivo, "_");
          }
          fclose(pArquivo);
          pArquivo = fopen("arquivos/letrasCorretas.txt", "w");
          fclose(pArquivo);
          pArquivo = fopen("arquivos/letrasErradas.txt", "w");
          fclose(pArquivo);

        }
        //Salvar palavra do arquivo na variavel (arquivo -> variavel)
        else {
          fgets(palavra, sizeof(palavra), pArquivo);
          tamanhoPalavra = strlen(palavra);
          fclose(pArquivo);

          //Letra digitada pelo usuario
          sscanf(dados, "nome=XXXX&ra=1234&letra=%c", &caracterEscolhido);
          caracterEscolhido = toupper(caracterEscolhido);

          for(i=0; i<tamanhoPalavra; i++){
            //Se a letra escolhida pertencer a palavra
            if(caracterEscolhido == palavra[i]){

              //Sobrescreve o arquivo dos traços
              pArquivo = fopen("arquivos/tracos.txt", "r");
              fgets(acerto, sizeof(acerto), pArquivo);
              fclose(pArquivo);
              pArquivo = fopen("arquivos/tracos.txt", "w");
              acerto[i] = caracterEscolhido;
              fprintf(pArquivo, "%s", acerto);
              fclose(pArquivo);

              certa+=1;
            }
          }
            //Salva a letra correta no arquivo
           if(certa!=0){
              pArquivo = fopen("arquivos/letrasCorretas.txt", "a");
              fprintf(pArquivo, "%c - ", caracterEscolhido);
              fclose(pArquivo);
            }
            //Se a letra escolhida não estiver no arquivo
            if(certa == 0){
              //Salva a letra errada no arquivo
              pArquivo = fopen("arquivos/letrasErradas.txt", "a");
              fprintf(pArquivo, "%c", caracterEscolhido);
              fclose(pArquivo);
            }
        }
        pArquivo = fopen("arquivos/letrasErradas.txt", "r");
        fgets(letrasErradas, sizeof(letrasErradas), pArquivo);
        //Condição de Derrota
        if(strlen(letrasErradas)==6)
        {
          flag = 12;
          fclose(pArquivo);
        }
        pArquivo = NULL;
        //Condição de Vitoria
        if(strcmp(acerto, palavra)==0)
        {
          flag = 13;
        }
    }


  //Função de impressão do HTML
    impressaoHTML(flag);

  return 0;
}
