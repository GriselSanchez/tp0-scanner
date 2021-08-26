#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "scanner.h"

int get_token(char buffer[]) {
	int i = 0;
	int currentChar = getchar();

	if (is_separator(currentChar)) {
		buffer[i++] = currentChar;
		end_string(buffer, i);
		return tokenSEP;
	}

	if (isspace(currentChar)) {
		return -1;
	}

	while (1) {
		if (is_separator(currentChar) || isspace(currentChar)) {
			ungetc(currentChar, stdin);
			end_string(buffer, i);
			return tokenCAD;
		}

		if (currentChar == EOF) {
			end_string(buffer, 0);
			return tokenFDT;
		}

		buffer[i++] = currentChar;
		currentChar = getchar();
	}
}

int is_separator(int c) {
	char *separators = { "," };

	for (int i = 0; i <= sizeof(separators); i++) {
		if (separators[i] == c) {
			return 1;
		}
	}

	return 0;
}

void end_string(char buffer[], int pos) {
	buffer[pos] = '\0';
}

