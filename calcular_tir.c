#include <math.h>

#define TAXA_MAXIMA 0.20
#define MAX_ITERACAO 1000
#define PRECISAO 0.00000001

double calcularTIR(double fc[], int numFluxos, float tma)
{
   int i = 0;
   int j = 0;
   double antigo = 0.00;
   double novo = 0.00;
   double taxaNova = tma;
   double taxa = tma;
   double taxaMinima = tma;
   double taxaMaxima = TAXA_MAXIMA;
   double vpl = 0.0;
   double denom = 0.0;

   for (i=0; i<MAX_ITERACAO; i++) {
      vpl = 0.0;

      for (j=0; j<numFluxos; j++) {
         denom = pow((1 + taxa),j);
         vpl = vpl + (fc[j]/denom);
      }

      if ((vpl > 0) && (vpl < PRECISAO))
         break;
      if (antigo == 0)
         antigo = vpl;
      else
         antigo = novo;

      novo = vpl;
      if (i > 0) {
         if (antigo < novo) {
            if (antigo < 0 && novo < 0)
               taxaMaxima = taxaNova;
            else
               taxaMinima = taxaNova;
         }
         else {
            if (antigo > 0 && novo > 0)
               taxaMinima = taxaNova;
            else
               taxaMaxima = taxaNova;
         }
      }
      taxa = (taxaMinima + taxaMaxima) / 2;
      taxaNova = taxa;
   }
   return taxa;
}

