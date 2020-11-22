#include <stdio.h>

double calcularTIR(double fc[], int numFluxos, float tma);

int main(void)
{
   double fc[30];
   double tir = 0.00;
   float tma;
   int numFluxos, i;

   printf("Bem-vindo a calculadora de TIR (Taxa Interna de Retorno).\n\n");
   printf("Digite a TMA (Taxa Miníma de Atratividade) (Ex: 0.11 para 11%%): ");
   scanf("%f", &tma);

   printf("Digite o período de tempo: ");
   scanf("%d", &numFluxos);

   for (i = 0; i < numFluxos; i++) {
      if (i == 0) {
         printf("Investimento Inicial (Ex: -325000): ");
      }
      else {
         printf("Fluxo de Caixa para Período (Ano) %d: ", i);
      }
      scanf("%lf", &fc[i]);
   }
   tir = calcularTIR(fc, numFluxos, tma);

   printf("\nValor final da TIR: %.2f%%\n", tir*100);

   return 0;
}

