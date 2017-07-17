#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastroJogador.h"      //Identificação da Biblioteca criada

//Função para não salvar RA's repetidos
//flag -> varivel que retorna possiveis erros.
int antigoJogador (int ra){
  int raArquivo, flag=0;
  char linha[100];
  FILE *pJogadores;

  pJogadores = fopen("arquivos/jogadores.txt", "r"); // Abertura do arquivo
	if(pJogadores == NULL) // Verificação se arquivo abrui corretamente
	 flag = 1; //Retorna erro na abertura no aquivo ao HTML

  //Percorre a linha do arquivo comparando o RA para verificar se o jogador já existe
  while((fgets(linha, sizeof(linha), pJogadores) != NULL) && (flag==0)){
    sscanf(linha, "RA: %d", &raArquivo);
    if (raArquivo == ra) // Se o RA digitado estiver no arquivo
      flag=10;          // O jogo começa.
  }
  fclose(pJogadores);
  pJogadores = NULL;
  return flag;
}

//Função para validar as informações digitadas
int verificacaoJogador (char* link){
  int flag=0;
  struct jogador{ // Estrutura da struct
      char nome[60];
      int ra, partidas;
  };
  struct jogador jogador; // Declaração da struct
  sscanf(link, "nome=%[^&]&ra=%d", jogador.nome, &jogador.ra); // Leitura do Nome do jogador e o RA
  if (strlen(jogador.nome) == 0)
    flag=2; //Retorna o erro(digite um nome) ao HTML
  else if (jogador.ra <= 0)
    flag=3; //Retorna o erro(digite um RA valido) ao HTML
  else if (antigoJogador(jogador.ra) != 0)
    flag=10; //Nenhum problema encontrado, então pode continuar o jogo

  return flag;
}

//Função para cadastro de novos jogadores
int novoJogador (char* link){
  int flag=11; // Jogador novo
  struct jogador{
      char nome[60];
      int ra, partidas;
  };
  struct jogador jogador;
  FILE *pJogadores;

  if(pJogadores == NULL) // Verificação se arquivo abrui corretamente
    flag=1; //Retorna erro na abertura no aquivo ao HTML
  else{
    sscanf(link, "nome=%[^&]&ra=%d", jogador.nome, &jogador.ra);
    pJogadores = fopen("arquivos/jogadores.txt", "a");
    fprintf(pJogadores, "NOME: %s\n", jogador.nome);
    fprintf(pJogadores, "RA: %d\n\n", jogador.ra);
  }
  fclose(pJogadores);
  pJogadores = NULL;
  return flag;
}
