#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>
// bs_call.c
// Compilation: gcc -std=c99 -O2 -lm -o bs_call bs_call.c
// Usage (interactive): ./bs_call

// constantes globales
#define RISK_FREE_RATE 0.015 // 1.5% annual
#define VOLATILITY 0.274	 // 27.4% annual

// Abramowitz & Stegun approximation for standard normal CDF
// Returns Phi(x)
double normalCDF(double x)
{
	// constants
	const double p = 0.2316419;
	const double b1 = 0.319381530;
	const double b2 = -0.356563782;
	const double b3 = 1.781477937;
	const double b4 = -1.821255978;
	const double b5 = 1.330274429;

	double absx = fabs(x);
	double t = 1.0 / (1.0 + p * absx);
	double phi = exp(-0.5 * absx * absx) / sqrt(2.0 * M_PI);

	double poly = ((((b5 * t + b4) * t + b3) * t + b2) * t + b1) * t;
	double approx = 1.0 - phi * poly;

	if (x >= 0.0)
	{
		return approx;
	}
	else
	{
		return 1.0 - approx;
	}
}

// Black-Scholes calcule du prix d'un CALL européen
// S = prix actuel de l'action
// K = prix d'exercice (strike)
// T = temps jusqu'à l'expiration (en années)
// r = taux d'intérêt sans risque (annualisé, décimal)
// sigma = volatilité de l'action (annualisée, décimal)
// Retourne le prix du CALL, ou NAN en cas d'erreur
double bs_call_price(double S, double K, double T, double r, double sigma)
{
	if (T > 0.0 && S > 0.0 && K > 0.0)
	{
		double sqrtT = sqrt(T);
		double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrtT);
		double d2 = d1 - sigma * sqrtT;
		double Nd1 = normalCDF(d1);
		double Nd2 = normalCDF(d2);
		return S * Nd1 - K * exp(-r * T) * Nd2;
	}
	else
	{
		return NAN; // Not a Number to indicate error
	}
}

int main(int argc, char *argv[])
{
	// variable locales
	double S, K, Tval;
	int scanned;

	printf("Calcul prix CALL (Black-Scholes)\n");
	printf("Taux sans risque = %.4f, volatilite = %.4f\n", RISK_FREE_RATE, VOLATILITY);
	// lecture interactive
	printf("Entrez prix actuel de l'action S (>0): ");
	scanned = scanf("%lf", &S);
	if (scanned != 1 || S <= 0.0)
	{
		fprintf(stderr, "Erreur: valeur de S invalide.\n");
		return 1;
	}

	printf("Entrez prix du strike K (>0): ");
	scanned = scanf("%lf", &K);
	if (scanned != 1 || K <= 0.0)
	{
		fprintf(stderr, "Erreur: valeur de K invalide.\n");
		return 1;
	}

	printf("Entrez temps restant (en jours) : ");
	scanned = scanf("%lf", &Tval);
	if (scanned != 1 || Tval <= 0.0)
	{
		fprintf(stderr, "Erreur: valeur du temps invalide.\n");
		return 1;
	}
	// temps en jours
	//  conversion en années

	double T; // en annees
	T = Tval / 365.0;

	if (T <= 0.0)
	{
		fprintf(stderr, "Erreur : T doit etre > 0 apres conversion.\n");
		return 1;
	}

	double price = bs_call_price(S, K, T, RISK_FREE_RATE, VOLATILITY);

	 if (isnan(price))
	{
		fprintf(stderr, "Erreur calcul prix.\n");
		return 1;
	}

	printf("\nRésultat :\n");
	printf("S = %.2f, K = %.2f, T = %.6f (années)\n", S, K, T);
	printf("Prix CALL (Black-Scholes) = %.6f\n", price);

	return 0;
}
