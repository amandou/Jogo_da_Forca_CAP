#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "cadastroJogador.h" //
#include "printHTML.h"

int main(){
  int i, flag=0, certa=0;
  int nLinhas=0, tamanhoPalavra=0;
  char caracter, caracterEscolhido;
  char* link;
  char palavra[15]={' '}, acerto[15]={' '};
  char letrasErradas[7]={' '}, dados[45];

/*        -----Exĺicação das variaveis-----
nLinhas = numero de linhas

*/



    srand(time(NULL)); // Faz com que a função rand() sorteie valores aleatorios
    FILE *pArquivo;
    link = getenv("QUERY_STRING"); // Recebe o link

    strcpy(dados,link); // Copia o que esta no link para a variavel dados

    //Função de Verificadão de Jogadores
      flag = (verificacaoJogador(link)); //Passagem por referencia do ponteiro link
      if(flag==0){
        flag = (novoJogador(link));
      }

      //Se flag for igual a 10, cadastro criado e jogo iniciado
      if(flag == 10){
        /*
        Verifica se o arquivo palavraescolhida já existe, caso não existe então ele
        será criado na condição abaixo.
        */
        if((pArquivo=fopen("arquivos/palavraEscolhida.txt", "r")) == NULL){
        //Contagem de Linhas do Arquivo
          pArquivo=fopen("arquivos/palavras.txt", "r");
          while(fscanf(pArquivo, "%c", &caracter) != EOF){ // le cada carater até o final do arquivo
            if(caracter == '\n') // Verifica se o caracter é um \n
            {
              nLinhas+=1; // Se o caracter for um \n é a adicionada +1 a variavel nLinhas;
            }
          }
        //Escolhendo palavra aleatóriamente
          rewind(pArquivo); // Retorna o ponteiro na posição inicial do arquivo
            for(i=0; i<rand()%nLinhas+1; i++)
            {
              fscanf(pArquivo, "%s\n", &palavra); // leitura da palavra escolhida aleatoriamente
            }
            fclose(pArquivo);

        //Gravando palavra escolhida no arquivo (variavel -> arquivo)
      pArquivo = fopen("arquivos/palavraEscolhida.txt","w");
		    if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			    printf("Erro 00");
      fprintf(pArquivo, "%s", palavra);
          fclose(pArquivo);
      pArquivo = fopen("arquivos/tracos.txt", "w");
		   if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			    printf("Erro 01");
      // Coloca _ de acordo com o tamanho da palavra escolhida aleatoriamente
      for(i=0; i<strlen(palavra); i++){
            fprintf(pArquivo, "_");
          }
          fclose(pArquivo);
  pArquivo = fopen("arquivos/letrasCorretas.txt", "w"); // Criação do arquivo letrasCorretas
		if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			printf("Erro 02");
	     fclose(pArquivo);
  pArquivo = fopen("arquivos/letrasErradas.txt", "w"); //Criação do arquivo letrasErradas
		if(pArquivo == NULL)
			printf("Erro 03");
  fclose(pArquivo);

        }
        /*
        O arquivo já existe então, então a palavra do arquivo
        é salva em uma vairvavel auxiliar ( palavra )(arquivo -> variavel)
        */
        else {
          // recebe a string que está dentro do arquivo
          fgets(palavra, sizeof(palavra), pArquivo);
          tamanhoPalavra = strlen(palavra);
          fclose(pArquivo);

          //Letra digitada pelo usuario
          sscanf(dados, "nome=XXXX&ra=1234&letra=%c", &caracterEscolhido);
          // transforma o caracter digitado pelo usuario em maiusculo
          caracterEscolhido = toupper(caracterEscolhido);

          /*
          Laço que faz a comparação com o caracter
          digitado com cada caracter  que tem na palavra escolhida aleatoriamente
          */
          for(i=0; i<tamanhoPalavra; i++){
            //Se a letra escolhida pertencer a palavra
            if(caracterEscolhido == palavra[i]){

              //Sobrescreve o arquivo dos traços
              pArquivo = fopen("arquivos/tracos.txt", "r");
		             if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			              printf("Erro 04");
              // Recebe a string que esta dentro do aquivo(os traços) tracos.txt e salva na variavel acertos
              fgets(acerto, sizeof(acerto), pArquivo);
              fclose(pArquivo);
              pArquivo = fopen("arquivos/tracos.txt", "w");
		            if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			             printf("Erro 05");
              acerto[i] = caracterEscolhido;
              fprintf(pArquivo, "%s", acerto);
              fclose(pArquivo);

              certa+=1; // conta quantos caracteres acertou
            }
          }
            //Salva a letra correta no arquivo
      if(certa!=0){ // Se o jogador acertou pelo menos um caracter...
        pArquivo = fopen("arquivos/letrasCorretas.txt", "a"); // Abre o aquivo letrasCorretas.txt
			     if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			         printf("Erro 06");
      //Impressão do caracter correto dentro do arquivo
      fprintf(pArquivo, "%c - ", caracterEscolhido);
      fclose(pArquivo);
            }
          //Se a letra escolhida não estiver no arquivo
            else{
              //Salva a letra errada no arquivo letrasErradas.txt
              pArquivo = fopen("arquivos/letrasErradas.txt", "a");
			if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			printf("Erro 07");
        //Imprime no arquivo o caracter escolhido dentro do arquivo letras erradas
              fprintf(pArquivo, "%c", caracterEscolhido);
              fclose(pArquivo);
            }
        }
      pArquivo = fopen("arquivos/letrasErradas.txt", "r");
		    if(pArquivo == NULL) // Verificar se a abertura do arquivo foi feita com sucesso
			     printf("Erro 08");
      //Recebe a string que esta dentro do arquivo letrasErradas.txt e coloca na varaivel letrasErradas
        fgets(letrasErradas, sizeof(letrasErradas), pArquivo);
        //Condição de Derrota
        if(strlen(letrasErradas)==6)
        {
          flag = 12; // Condição de Derrota
          fclose(pArquivo);
        }
        pArquivo = NULL;
        //Condição de Vitoria
        if(strcmp(acerto, palavra)==0)
        {
          flag = 13; // Condição de Vitoria
        }
    }


  //Função de impressão do HTML
    impressaoHTML(flag);

  return 0;
}
