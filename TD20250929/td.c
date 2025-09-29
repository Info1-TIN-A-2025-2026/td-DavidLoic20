#include <stdio.h>

int main(int argc, const char *argv[])
{
	int s;
	// variables pour le calcul
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

	// demande de la valeur en secondes
	printf("Number of seconds: ");
	scanf("%d", &s);

	// condition pour afficher le message d'erreur ou le temps au format hh:mm:ss
	if (s < 0)
	{
		puts("Error");
	}
	else if (s >= 86400)
	{
		puts("Overflow");
	}
	else
	{
		// calcul du temps en heures, minutes et secondes
		hours = s / 3600;
		minutes = (s % 3600) / 60;
		seconds = s % 60;

		printf("%02u:%02u:%02u\n", hours, minutes, seconds);
	}
}