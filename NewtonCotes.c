//Universidade Federal do Ceará
//Aluno: Leandro Almeida de Carvalho - 362973
//Implementações Newton Cotes Filosofia Fechada
//Disciplina: Métodos Numéricos 2

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double polinomio(double x) //Polinômio utilizado (x³ + x²) 
{
	return  pow(x,3) + pow(x,2);
}

double integralCalculada (int regra, double pontoInicial, double pontoFinal, int numParticoes, double tamanhoTotal)
{

	int i;
	double Fx0, Fx1, Fx2, Fx3, Fx4, Fx5, resultadoIntegral, tamanhoParticao, pontoAtual;
	pontoAtual = pontoInicial;
	resultadoIntegral=0;

			

	for (i = 0; i < numParticoes; ++i)
	{

		if (regra == 1) //Polinomio de Grau 1 
		{
			tamanhoParticao = tamanhoTotal/numParticoes;
			Fx0 = polinomio(pontoAtual);
			Fx1 = polinomio(pontoAtual + tamanhoParticao);
			pontoAtual = pontoAtual + tamanhoParticao;
			resultadoIntegral = ((tamanhoParticao/2) * (Fx0 + Fx1)) + resultadoIntegral;
		}
			
		
		if (regra == 2) //Polinomio de Grau 2 
		{	
			tamanhoParticao = (tamanhoTotal/2)/numParticoes;
			Fx0 = polinomio(pontoAtual);
			Fx1 = polinomio(pontoAtual + tamanhoParticao);
			Fx2 = polinomio(pontoAtual + 2*tamanhoParticao);
			pontoAtual = pontoAtual + 2*tamanhoParticao;
			resultadoIntegral=((tamanhoParticao/3) * (Fx0 + 4*Fx1 + Fx2)) + resultadoIntegral;
		}

		
		if (regra == 3) //Polinomio de Grau 3 
		{
			tamanhoParticao = (tamanhoTotal/3)/numParticoes;
			Fx0 = polinomio(pontoAtual);
			Fx1 = polinomio(pontoAtual + tamanhoParticao);
			Fx2 = polinomio(pontoAtual + 2*tamanhoParticao);
			Fx3 = polinomio(pontoAtual + 3*tamanhoParticao);
			pontoAtual = pontoAtual + 3*tamanhoParticao;
			resultadoIntegral=((3*tamanhoParticao/8) * (Fx0 + 3*Fx1 + 3*Fx2 + Fx3)) + resultadoIntegral;
		}			
		
		if (regra == 4) //Polinomio de Grau 4
		{
			tamanhoParticao = (tamanhoTotal/4)/numParticoes;
			Fx0 = polinomio(pontoAtual);
			Fx1 = polinomio(pontoAtual + tamanhoParticao);
			Fx2 = polinomio(pontoAtual + 2*tamanhoParticao);
			Fx3 = polinomio(pontoAtual + 3*tamanhoParticao);
			Fx4 = polinomio(pontoAtual + 4*tamanhoParticao);
			pontoAtual = pontoAtual + 4*tamanhoParticao;
			resultadoIntegral=((2*tamanhoParticao/45) * (7*Fx0 + 32*Fx1 + 12*Fx2 + 32*Fx3 + 7*Fx4)) + resultadoIntegral;
		}

		if (regra == 5) //Polinomio de Grau 5
		{
			tamanhoParticao = (tamanhoTotal/5)/numParticoes;
			Fx0 = polinomio(pontoAtual);
			Fx1 = polinomio(pontoAtual + tamanhoParticao);
			Fx2 = polinomio(pontoAtual + 2*tamanhoParticao);
			Fx3 = polinomio(pontoAtual + 3*tamanhoParticao);
			Fx4 = polinomio(pontoAtual + 4*tamanhoParticao);
			Fx5 = polinomio(pontoAtual + 5*tamanhoParticao);
			pontoAtual = pontoAtual + 5*tamanhoParticao;
			resultadoIntegral=((5*tamanhoParticao/288) * (19*Fx0 + 75*Fx1 + 50*Fx2 + 50*Fx3 + 75*Fx4 + 19*Fx5)) + resultadoIntegral;
		}
		
	}
		
	return resultadoIntegral;

}

int main(int argc, char const *argv[])
{

	double limiteInferior, limiteSuperior, tolerancia,resultadoAnterior,resultadoAtual, tamanhoTotal;
	int numParticoes=1;
	int opc;

	printf("\n--- Newton-Cotes Filosofia Fechada ---\n");
	printf("1 - Polinômio de substituição de grau 1\n");
	printf("2 - Polinômio de substituição de grau 2\n");
	printf("3 - Polinômio de substituição de grau 3\n");
	printf("4 - Polinômio de substituição de grau 4\n");
	printf("5 - Polinômio de substituição de grau 5\n");
	printf("Opcao escolhida\n:");
	scanf("%d", &opc);

		
	printf("\nValor do limite inferior: ");
	scanf("%lf", &limiteInferior);
	printf("\nValor do limite superior: ");
	scanf("%lf", &limiteSuperior);
	printf("\nValor da tolerância: ");
	scanf("%lf", &tolerancia);

	tamanhoTotal = limiteSuperior - limiteInferior; 

	do
	{
		resultadoAnterior = integralCalculada(opc,limiteInferior,limiteSuperior,numParticoes,tamanhoTotal);
		numParticoes = numParticoes + 2;
		resultadoAtual = integralCalculada(opc,limiteInferior,limiteSuperior,numParticoes,tamanhoTotal);
	}while((fabs( resultadoAtual - resultadoAnterior) > tolerancia));

	printf("O valor da integral é :%.5f\n",resultadoAtual);
	return 0;

}