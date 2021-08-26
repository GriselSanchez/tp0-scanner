#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

int main(void) {
	typedef enum TOKENS Result;
	Result result;

	char *names[sizeof(Result)] = { "Separador", "Cadena", "Fin De Texto" };
	char buffer[BUFSIZ];

	do {
		result = get_token(buffer);

		if (result != -1) {
			printf("%s: %s \n", names[result], buffer);
		}

	} while (result != tokenFDT);

	return EXIT_SUCCESS;
}

