#define TKId 1
//Formatos
#define TKVoid 2
#define TKInt 3
#define TKFloat 4
#define TKLong 5
#define TKDouble 6
#define TKShort 7
//Comando While
#define TKWhile 8
//Comando Do
#define TKDo 9
//Comando For
#define TKFor 10
//Comando If
#define TKIf 11
//Comando Atribuicao
#define TKAtribuicao 12
//Comando Switch-Case
#define TKSwitch 13
#define TKCase 14
//Expressoes
#define TKAbreParentese 15
#define TKFechaParentese 16
#define TKAbreConchete 17
#define TKFechaConchete 18
#define TKAbreChave 19
#define TKFechaChave 20
#define TKMenos 21
#define TKDuploMenos 22
#define TKMais 23
#define TKDuploMais 24
#define TKMultiplica 25
#define TKDivisao 26
#define TKRestoDivisao 27
#define TKMaior 28
#define TKMaiorIgual 29
#define TKMenor 30
#define TKMenorIgual 31
#define TKMenorBinario 32
#define TKMaiorBinario 33
#define TKPontoExclamacaoIgual 34
#define TKPontoExclamacao 35
#define TKAnd 36
#define TKOr 37
#define TKDuploAnd 38
#define TKDuploOr 39
#define TKMaisIgual 40
#define TKMenosIgual 41
#define TKVezesIgual 42
#define TKDivideIgual 43
#define TKPonto 44
#define TKVirgula 45
#define TKDoisPontos 46
#define TKPontoeVirg 47
#define TKDuploIgual 63
//Outros
#define TKConst 48
#define TKPrintf 49
#define TKPrivate 50
#define TKPublic 51
#define TKScanf 52
#define TKFflush 53
#define TKStdin 54
#define TKNULL 55
#define TKContinue 56
#define TKExit 57
#define TKReturn 58
#define TKSizeof 59
#define TKStatic 60
#define TKUnsigned 61
#define TKStdout 62

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int pos = 0;

struct pal_res {
	char palavra[20];
	int tk;
};
struct pal_res lista_pal[] = {
		{"void", TKVoid},
		{"int", TKInt},
		{"float", TKFloat},
		{"fimtabela", TKId},
		{"long", TKLong},
		{"double", TKDouble},
		{"short", TKShort},
		{"const", TKConst},
		{"printf", TKPrintf},
		{"private",TKPrivate},
		{"public", TKPublic},
		{"scanf", TKScanf},
		{"fflush", TKFflush},
		{"stdin", TKStdin},
		{"NULL", TKNULL},
		{"continue", TKContinue},
		{"do", TKDo},
		{"while", TKWhile},
		{"for", TKFor},
		{"exit", TKExit},
		{"switch", TKSwitch},
		{"case", TKCase},
		{"if", TKIf},
		{"return", TKReturn},
		{"sizeof", TKSizeof},
		{"static", TKStatic},
		{"unsigned",TKUnsigned},
		{"stdout", TKStdout}};

int palavra_reservada(char lex[]) {
	int postab = 0;
	while (strcmp("fimtabela", lista_pal[postab].palavra) != 0) {
		if (strcmp(lex, lista_pal[postab].palavra) == 0)
			return lista_pal[postab].tk;
		postab++;
	}
	return TKId;
}

int rec_equ(char st[], char lex[]) {
	int estado = 0, fim = 0, posl = 0;
	while (!fim) {
		char c = st[pos];
//printf("%s\n",st);
//printf("char=%c pos=%d\n",c,pos);
		lex[posl++] = c;
		switch (estado) {
		case 0:
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
				pos++;
				estado = 1;
				break;
			}
			if (c == '=') {
				c = st[++pos];
				if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
				return TKDuploIgual;
				}else {
					lex[posl] = '\0';
					return TKAtribuicao;
				}
			}
			if (c == '+') {
				c = st[++pos];
				if (c == '+') {
					lex[posl++] = '+';
					lex[posl] = '\0';
					pos++;
					return TKDuploMais;
				} else if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
					return TKMaisIgual;
				} else {
					lex[posl] = '\0';
					return TKMais;
				}
			}
			if (c == '(') {
				lex[posl] = '\0';
				pos++;
				return TKAbreParentese;
			}
			if (c == ')') {
				lex[posl] = '\0';
				pos++;
				return TKFechaParentese;
			}
			if (c == '{') {
				lex[posl] = '\0';
				pos++;
				return TKAbreChave;
			}
			if (c == '}') {
				lex[posl] = '\0';
				pos++;
				return TKFechaChave;
			}
			if (c == ',') {
				lex[posl] = '\0';
				pos++;
				return TKVirgula;
			}
			if (c == ';') {
				lex[posl] = '\0';
				pos++;
				return TKPontoeVirg;
			}
			if (c == ':') {
				lex[posl] = '\0';
				pos++;
				return TKDoisPontos;
			}
			if (c == '.') {
				lex[posl] = '\0';
				pos++;
				return TKPonto;
			}
			if (c == '!') {
				c = st[++pos];
				if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
					return TKPontoExclamacaoIgual;
				} else {
					lex[posl] = '\0';
					return TKPontoExclamacao;
				}
			}
			if (c == '[') {
				lex[posl] = '\0';
				pos++;
				return TKAbreConchete;
			}
			if (c == ']') {
				lex[posl] = '\0';
				pos++;
				return TKFechaConchete;
			}
			if (c == '-') {
				c = st[++pos];
				if (c == '-') {
					lex[posl++] = '-';
					lex[posl] = '\0';
					pos++;
					return TKDuploMenos;
				} else if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
					return TKMenosIgual;
				} else {
					lex[posl] = '\0';
					return TKMenos;
				}
			}
			if (c == '*') {
				c = st[++pos];
				if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
					return TKVezesIgual;
				} else {
					lex[posl] = '\0';
					return TKMultiplica;
				}
			}
			if (c == '/') {
				c = st[++pos];
				if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
					return TKDivideIgual;
				} else {
					lex[posl] = '\0';
					return TKDivisao;
				}
			}
			if (c == '%') {
				lex[posl] = '\0';
				pos++;
				return TKRestoDivisao;
			}
			if (c == '>') {
				c = st[++pos];
				if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
					return TKMaiorIgual;
				} else if (c == '>') {
					lex[posl++] = '>';
					lex[posl] = '\0';
					pos++;
					return TKMaiorBinario;
				} else {
					lex[posl] = '\0';
					return TKMaior;
				}
			}
			if (c == '<') {
				c = st[++pos];
				if (c == '=') {
					lex[posl++] = '=';
					lex[posl] = '\0';
					pos++;
					return TKMenorIgual;
				} else if (c == '<') {
					lex[posl++] = '<';
					lex[posl] = '\0';
					pos++;
					return TKMenorBinario;
				} else {
					lex[posl] = '\0';
					return TKMenor;
				}
			}
			if (c == '&') {
				c = st[++pos];
				if (c == '&') {
					lex[posl++] = '&';
					lex[posl] = '\0';
					pos++;
					return TKDuploAnd;
				}else {
					lex[posl] = '\0';
					return TKAnd;
				}
			}
			if (c == '|') {
				c = st[++pos];
				if (c == '|') {
					lex[posl++] = '|';
					lex[posl] = '\0';
					pos++;
					return TKDuploOr;
				}else {
					lex[posl] = '\0';
					return TKOr;
				}
			}
			if (c == ' ' || c == '\n') {
				pos++;
				posl--;
				break;
			}
			if (c == '\0')
				return -1;
			printf("Erro léxico: encontrou o caracter %c na posição %d", c,
					pos);
			break;
		case 1:
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_') || (c >= '0' && c <= '9')) {
				pos++;
				break;
			}
			lex[--posl] = '\0';
			return palavra_reservada(lex);
		} //switch
	} // while
} // função

int main() {
	int tk;
	char exp1[200], lex[20];
	printf("Digite o programa a ser analisado (ex: void main(){int a,b,c;a=b+c;}\n");
	gets(exp1);
	while ((tk = rec_equ(exp1, lex)) != -1)
		printf("%d %s\n", tk, lex);
//system("pause");
}
