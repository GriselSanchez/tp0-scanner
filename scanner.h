enum TOKENS {
	tokenSEP, tokenCAD, tokenFDT
};

int get_token(char *buffer);
int is_separator(int c);
void end_string(char buffer[], int *i);
