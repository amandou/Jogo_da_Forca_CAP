#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cadastroJogador.h"
#include "printHTML.h"

int main(){
  int i, flag=0;
  int nLinhas=0, tamanhoPalavra=0;
  char caracter;
  char *link, palavra[15]={' '};
    srand(time(NULL));
    FILE *pArquivo;
    link = getenv("QUERY_STRING");

    //Função de Verificadão de Jogadores
      flag = (verificacaoJogador(link));
      if(flag==0){
        flag = (novoJogador(link));
      }

    if((pArquivo=fopen("palavraEscolhida.txt", "r")) == NULL){

      //Contagem de Linhas do Arquivo
        pArquivo=fopen("palavras.txt", "r");
        while(fscanf(pArquivo, "%c", &caracter) != EOF){
          if(caracter == '\n'){
            nLinhas+=1;
          }
        }

      //Escolhendo palavra aleatóriamente
        rewind(pArquivo);
          for(i=0; i<rand()%nLinhas; i++){
            fscanf(pArquivo, "%s\n", &palavra);
          }
          fclose(pArquivo);

      //Gravando palavra escolhida no arquivo
        pArquivo = fopen("palavraEscolhida.txt","w");
        fprintf(pArquivo, "%s", palavra);
        fclose(pArquivo);
    } else {
      fgets(palavra, sizeof(palavra), pArquivo);
      tamanhoPalavra = strlen(palavra);
      fclose(pArquivo); pArquivo = NULL;

    }

  //Função de impressão do HTML
    impressaoHTML(flag);

  return 0;
}
