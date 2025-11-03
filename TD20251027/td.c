#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	// petit exercice sur les operateurs arithmetiques
	// nous avons un  tableau de résqultats sur excel ou nous avons tous
	// pleins de cas de figure et ce programme permet de regarder comment le compilateur réajit.
	int a;
	int b;

	printf("enter a number: ");
	scanf("%d", &a);
	printf("enter b number: ");
	scanf("%d", &b);

	printf("a / b = %d\n", a / b);

	printf("a %% b = %d\n", a % b);

	a = 10;
	// post incrémentation
	printf("%d \n", a++);

	a = 10;
	// aprés incrémentation
	printf("%d \n", ++a);

	int cpt;
	for (cpt = 1; cpt <= 5; cpt++)
	{
		printf("cpt = %d\n", cpt);
	}

		return 0;
}