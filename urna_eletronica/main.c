// ANGELA MAHLKE RANOFF & GUSTAVO CHAVES - Turma 11.

#include <stdio.h>

int main(void) {
  int v;
  int c1 = 0;
  int c2 = 0;
  int c3 = 0;
  int c4 = 0;
  int c5 = 0;
  int total;
  int bn;
  float percentual;
  

while(1) {
printf("1 - Candidato 1\n2 - Candidato 2\n3 - Candidato 3\n4 - Voto em Branco\n5 - Voto nulo\n-1 - Sair da Urna Eletrônica.\n\n");
  printf("Insira seu voto: \n");
  scanf("%d", &v);
  if (v > 5 || v < 1 && v != -1) printf("Voto inválido. Tente novamente.\n");
  else {
    if (v == 1) {
      c1+=1;
      printf("O candidato 1 tem %d voto(s).\n", c1);
    }
    if (v == 2) {
      c2+=1;
      printf("O candidato 2 tem %d voto(s).\n",c2);
    }
    if (v == 3) {
      c3+=1;
      printf("O candidato 3 tem %d voto(s).\n",c3);
    }
    if (v == 4) {
      c4+=1;
      printf("Existem %d votos em branco.\n",c4);
    }
    if (v == 5) {
      c5+=1;
      printf("Existem %d voto(s) nulo(s). \n",c5);
    }
  }
  if (v == -1) {
    printf("\n\n-------------- Programa encerrado.\n\n");
    break;
    }
}

    if (c1 == c3 && c1 > c2 && c3 > c2){
      printf("Candidatos 1 e 3 somaram o mesmo número de votos. Total de %d.\n\n", c1);
      printf("Candidato 2 somou %d voto(s). \n", c2);
      printf("Houve %d voto(s) em branco. \n", c4);
      printf("E %d voto(s) nulos. \n", c5);
      }
  
    if (c1 == c2 && c1 > c3 && c2 > c3){
      printf("Candidatos 1 e 2 somaram o mesmo número de votos. Total de %d.\n\n", c1);
      printf("Candidato 3 somou %d voto(s). \n", c3);
      printf("Houve %d voto(s) em branco. \n", c4);
      printf("E %d voto(s) nulos. \n", c5);
         }
  
    if (c2 == c3 && c2 > c1 && c3 > c1){
      printf("Candidatos 2 e 3 somaram o mesmo número de votos. Total de %d.\n\n", c2);
      printf("Candidato 1 somou %d voto(s). \n", c1);
      printf("Houve %d voto(s) em branco. \n", c4);
      printf("E %d voto(s) nulo(s). \n", c5);
  
  }

  if (c1 == c2 && c2 == c3) {
    printf("Todos os candidatos somaram o mesmo número de votos. Total de %d.\n\n", c1);
    printf("Houve %d voto(s) em branco.\n", c4);
    printf("Houve %d voto(s) nulo(s).\n", c5);
  }
  
  if (c1 > c2 && c1 > c3 ){
    printf("Candidato 1 ganhou a eleição com %d voto(s).\n", c1);
    printf("Candidato 2 somou %d voto(s). \n", c2);
    printf("Candidato 3 somou %d voto(s). \n", c3);
    printf("Houve %d voto(s) em branco. \n", c4);
    printf("E %d voto(s) nulos. \n", c5);
  }
  else if(c2 > c1 && c2 > c3){
    printf("Candidato 2 ganhou a eleição com %d voto(s).\n", 
    c2);
    printf("Candidato 1 somou %d voto(s). \n", c1);
    printf("Candidato 3 somou %d voto(s).\n", c3);
    printf("Houve %d voto(s) em branco. \n", c4);
    printf("E %d voto(s) nulos. \n", c5);
  }
  else if (c3 > c1 && c3 > c2) {
    printf ("Candidato 3 ganhou a eleição com %d voto(s).\n", c3);
    printf("Candidato 1 somou %d voto(s). \n", c1); 
    printf("Candidato 2 somou %d voto(s).\n", c2);
    printf("Houve %d voto(s) em branco. \n", c4);
    printf("E %d voto(s) nulo(s). \n", c5);
    }


  
  total = c1 + c2 + c3 + c4 + c5;
  bn = c4 + c5;

  percentual = (bn * 100) / total * 1.0;
  
  
  printf("Os votos brancos e nulos ocuparam um percentual de %.1f do total de votos", percentual);
  
  return 0;
}