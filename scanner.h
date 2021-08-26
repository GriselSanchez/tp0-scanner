enum TOKENS {
	tokenFDT, tokenSEP, tokenCAD
};

int get_token(char buffer[]);
int is_separator(int c);
void end_string(char buffer[], int i);
