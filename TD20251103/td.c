#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	// petit exercice sur les operateurs arithmetiques
	// entrer un nombre
	int n;
	printf("enter a number: ");
	scanf("%d", &n);

	// afficher le nombre de digits
	int count = 0;
	int w = n;
	if (w == 0)
	{
		count = 1;
	}
	else
	{
		while (w != 0)
		{
			w /= 10;
			count++;
		}
	}
	printf("Number of digits in %d is: %d\n", n, count);

	int digit[count];
	int count_mem = count;
	//inversion des digites avec do while 
	do {
		digit[count - 1] = n % 10;
		n = n / 10;
		count--;
	}while(count > 0);
	
	printf("Digits in reverse order: ");
	for (int i = count_mem-1; i >= 0; i--) {
		printf("%d", digit[i]);}
	
	printf("\n");
	
	return 0;
}