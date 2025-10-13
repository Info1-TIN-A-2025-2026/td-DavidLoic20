#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	char a = 'a';

	unsigned char num_student = 23;
	unsigned char num_chairs = 32;

	short delta = num_student - num_chairs; // différence entre le nombre d'étudiants et de chaises

	bool sw1 = true; // lampe prof allumée
	bool sw2 = true; // lampe salle allumée
	unsigned char state = (sw2 << 4) + sw1;

	printf("le nombre d'étudiants est %u le nombre de chaises est %d\n", num_student, num_chairs);
	printf("la différence est %hd\n", delta);
	printf("le caractère est %c\n", a);
	printf("l'état des lampes est %x\n", state);

	return 0;
}