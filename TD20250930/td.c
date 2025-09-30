#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	int log10Unit;
	double masse_1, masse_2, distance, force;
	double G = 6.67430e-11; // Constante gravitationnelle en m^3 kg^-1 s^-2

	printf("insérer la première masse :(notation ingénieur):");
	scanf("%lf", &masse_1);

	// test que la valeur est utilisable
	if (masse_1 <= 0)
	{
		printf("Erreur: la masse doit être un nombre positif.\n");
		return 1; // Quitter le programme avec un code d'erreur
	}
	if (isnan(masse_1) || isinf(masse_1))
	{
		printf("Erreur: la masse doit être un nombre valide.\n");
		return 1; // Quitter le programme avec un code d'erreur
	}

	printf("insérer la deuxième masse (notation ingénieur):");
	scanf("%lf", &masse_2);

	if (masse_2 <= 0)
	{
		printf("Erreur: la masse doit être un nombre positif.\n");
		return 1; // Quitter le programme avec un code d'erreur
	}
	if (isnan(masse_2) || isinf(masse_2))
	{
		printf("Erreur: la masse doit être un nombre valide.\n");
		return 1; // Quitter le programme avec un code d'erreur
	}

	printf("insérer la distance entre les deux masses (en kg):");
	scanf("%lf", &distance);

	if (distance <= 0)
	{
		printf("Erreur: la masse doit être un nombre positif.\n");
		return 1; // Quitter le programme avec un code d'erreur
	}
	if (isnan(distance) || isinf(distance))
	{
		printf("Erreur: la masse doit être un nombre valide.\n");
		return 1; // Quitter le programme avec un code d'erreur
	}

	force = G * (masse_1 * masse_2) / (distance * distance);

	// calcul pour écrire l'unité SI de la force
	log10Unit = floor(log10(force));
	// affichage de la force avec l'unité SI adaptée
	if (log10Unit >= 3 && log10Unit < 6)
		printf("La force gravitationnelle entre les deux masses est : %f kN\n", force / 1e3);
	else if (log10Unit >= 6 && log10Unit < 9)
		printf("La force gravitationnelle entre les deux masses est : %f MN\n", force / 1e6);
	else if (log10Unit >= 9 && log10Unit < 12)
		printf("La force gravitationnelle entre les deux masses est : %f GN\n", force / 1e9);
	else if (log10Unit >= 12 && log10Unit < 15)
		printf("La force gravitationnelle entre les deux masses est : %f TN\n", force / 1e12);
	else if (log10Unit >= 15 && log10Unit < 18)
		printf("La force gravitationnelle entre les deux masses est : %f PN\n", force / 1e15);
	else if (log10Unit >= 18 && log10Unit < 21)
		printf("La force gravitationnelle entre les deux masses est : %f EN\n", force / 1e18);
	else if (log10Unit >= 21 && log10Unit < 24)
		printf("La force gravitationnelle entre les deux masses est : %f ZN\n", force / 1e21);
	else if (log10Unit >= 24)
		printf("La force gravitationnelle entre les deux masses est : %f YN\n	", force / 1e24);
	else if (log10Unit < 0 && log10Unit > -3)
		printf("La force gravitationnelle entre les deux masses est : %f mN\n", force * 1e3);
	else if (log10Unit <= -3 && log10Unit > -6)
		printf("La force gravitationnelle entre les deux masses est : %f µN\n", force * 1e6);
	else if (log10Unit <= -6)
		printf("La force gravitationnelle entre les deux masses est : %f nN\n", force * 1e9);
	else
		printf("La force gravitationnelle entre les deux masses est : %f N\n", force);

	return 0;
}