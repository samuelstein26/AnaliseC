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
#define TKElse 69
//Comando Atribuicao
#define TKAtribuicao 13
//Comando Switch-Case
#define TKSwitch 12
#define TKCase 14
#define TKBreak 64
#define TKDefault 65
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
#define TKAspaDupla 68
//contantes numeros
#define TKConstFloat 66
#define TKConstInt 67
//Outros
#define TKConst 48
#define TKPrintf 49
#define TKPrivate 50
#define TKPublic 51
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
int pos = 0, n=0;
int pilha[300];
int auxpilha[300];

struct pal_res {
    char palavra[20];
    int tk;
};
struct pal_res lista_pal[] = {
        {"void", TKVoid},
        {"int", TKInt},
        {"float", TKFloat},
        {"long", TKLong},
        {"double", TKDouble},
        {"short", TKShort},
        {"const", TKConst},
        {"printf", TKPrintf},
        {"private",TKPrivate},
        {"public", TKPublic},
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
        {"stdout", TKStdout},
        {"break", TKBreak},
        {"default", TKDefault},
		{"else", TKElse},
		{"fimtabela", TKId}};

void desempilha(short n){
	int i,j;
	for (i=n+1,j=0; pilha[i]!=999; i++,j++){
		auxpilha[j]= pilha[i];
	}
	auxpilha[j++]= 999;
}

void empilha(short *x){
	int i,j;
	for (i=*x,j=0; auxpilha[j]!=999; i++,j++){
		pilha[i]= auxpilha[j];
	}
	pilha[i++]= 999;
}

int analisesintatica(int tk){
	printf("Numero: %d Token: %d Pilha: %d\n", n, tk, pilha[n]);
	short x;
	if (pilha[n] > 0){
        //SIGNIFICA QUE É TERMINAL

		//para terminais utlizar a variavel tk
		//para não terminais utilizar a variavel pilha[n]

        if (tk == 47){ //é ponto e virgula, então zera n e a pilha
            desempilha(n);
            n= 0;
            x = 1;
            empilha(&x);
            return 0;
        } 

		/**************************************   Comando IF **********************************************/
		if (tk == 11){ //token if
			//funçao para obter os dados da pilha da posicao até o fim
			desempilha(n);
			pilha[n]= 11;
			pilha[n+1]= 15;
			pilha[n+2]= -1;
			pilha[n+3]= 16;
			pilha[n+4]= -2;
			pilha[n+5]= -3;
			x=n + 6;
			//funçao para empilhar novamente
			empilha(&x);
            return 0;
		}

		/**************************************   Comando FOR **********************************************/
		if (tk == 10){ //token for
			desempilha(n);
			pilha[n]= 10;
			pilha[n+1]= 15;
			pilha[n+2]= -1;
			pilha[n+3]= 47;
			pilha[n+4]= -1;
			pilha[n+5]= 47;
			pilha[n+6]= -1;
			pilha[n+7]= 16;
			pilha[n+8]= -2;
			x=n + 9;
			empilha(&x);
            return 0;
		}

		/**************************************   Comando While **********************************************/
		if (tk == 8){
			desempilha(n);
			pilha[n]= 8;
			pilha[n+1]= 15;
			pilha[n+2]= -1;
			pilha[n+3]= 16;
			pilha[n+4]= -2;
			x=n + 5;
			empilha(&x);
            return 0;
		}

		/**************************************   Comando Do While **********************************************/
		if (tk == 9){
			desempilha(n);
			pilha[n]= 9;
			pilha[n+1]= -2;
			pilha[n+2]= 8;
			pilha[n+3]= 15;
			pilha[n+4]= -1;
			pilha[n+5]= 16;
			x=n + 6;
			empilha(&x);
			//analisesintatica(tk);
            return 0;
		}

		/**************************************   Comando Switch Case **********************************************/
		if (tk == 12){
			desempilha(n);
			pilha[n]= 12;
			pilha[n+1]= 15;
			pilha[n+2]= -1;
			pilha[n+3]= 16;
			pilha[n+4]= 19;
			pilha[n+5]= -9;
			pilha[n+6]= 20;
			x=n + 7;
			empilha(&x);
            return 0;
		}

	}else if (pilha[n] < 0){
        //SIGNIFICA QUE NÃO É TERMINAL
        if (pilha[n] == -1){ //nao terminal Comandos
            desempilha(n);
            pilha[n]=  -12;
            pilha[n+1]= -5;
            x=n + 2;
            empilha(&x);
            analisesintatica(tk);
            return 0;
        }

        if (pilha[n] == -2){ //nao terminal Jogo Chave
            if (tk == 19){ //se é {
                desempilha(n);
                pilha[n]= 19;
                pilha[n+1]= -10;
                pilha[n+2]= 20;
                x=n + 3;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else if (tk == 47){
            	desempilha(n);
            	pilha[n]= 47;
            	pilha[n+1]= -10;
            	x=n + 2;
            	empilha(&x);
            	analisesintatica(tk);
            }else{
                desempilha(n);
                pilha[n]= -10;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
        }

        if (pilha[n] == -3){ //nao terminal comando else
            if (tk == 69){
                desempilha(n);
                pilha[n]= 69;
                pilha[n+1]= -8;
                x=n + 2;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else{
            	n++;
            	analisesintatica(tk);
            	return 0;
            }
        }

        if (pilha[n] == -5){ //nao terminal OPComple1
            if ((tk >= 21 && tk <= 35) || (tk >= 40 && tk <= 43) || tk == 66 || tk == 63 || tk == 13){ //todos os Sinais
                desempilha(n);
                pilha[n]=  -6;
                pilha[n+1]= -12;
                pilha[n+2]= -7;
                x=n + 3;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else{
            	n++;
            	analisesintatica(tk);
            	return 0;
            }
        }

        if (pilha[n] == -6){ //não terminal Sinal
            if (tk == 13){
                desempilha(n);
                pilha[n]= 13;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 25){
                desempilha(n);
                pilha[n]= 25;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 26){
                desempilha(n);
                pilha[n]= 26;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 27){
                desempilha(n);
                pilha[n]= 27;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 23){
                desempilha(n);
                pilha[n]= 23;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 21){
                desempilha(n);
                pilha[n]= 21;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 28){
                desempilha(n);
                pilha[n]= 28;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 31){
                desempilha(n);
                pilha[n]= 31;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 29){
                desempilha(n);
                pilha[n]= 29;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 30){
                desempilha(n);
                pilha[n]= 30;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 63){
                desempilha(n);
                pilha[n]= 63;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 34){
                desempilha(n);
                pilha[n]= 34;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 38){
                desempilha(n);
                pilha[n]= 38;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 39){
                desempilha(n);
                pilha[n]= 39;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 38){
                desempilha(n);
                pilha[n]= 38;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 39){
                desempilha(n);
                pilha[n]= 39;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 24){
                desempilha(n);
                pilha[n]= 24;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            if (tk == 22){
                desempilha(n);
                pilha[n]= 22;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
            n++;
            analisesintatica(tk);
            return 0;
        }

        if (pilha[n] == -7){ //nao terminal OPComple2
            if (tk == 38 || tk == 39){
				if (tk == 38){//se é AND
					desempilha(n);
					pilha[n]= 38;
					pilha[n+1]= -1;
					x=n + 2;
					empilha(&x);
					analisesintatica(tk);
					return 0;
				}
				if (tk == 39){//se é OR
					desempilha(n);
					pilha[n]= 39;
					pilha[n+1]= -1;
					x=n + 2;
					empilha(&x);
					analisesintatica(tk);
					return 0;
				}
            }else{
            	n++;
            	analisesintatica(tk);
            	return 0;
            }
        }

        if (pilha[n] == -8){ //nao terminal OPCompeComandoElse
            if (tk == 19){
                desempilha(n);
                pilha[n]= -2;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else{
                desempilha(n);
                pilha[n]= -10;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }
        }
        if (pilha[n] == -9){ //nao terminal Comando Case
            desempilha(n);
            pilha[n]= 14;
            pilha[n+1]= -12;
            pilha[n+2]= 46;
            pilha[n+3]= -2;
            pilha[n+4]= -11;
            x=n + 5;
            empilha(&x);
            analisesintatica(tk);
            return 0;
        }

        if (pilha[n] == -10){ //não terminal Estado Inicial
            if ((tk == 11) || (tk == 10) || (tk == 8) || (tk == 12)){
                if (tk == 11){ //comando if
                    desempilha(n);
                    pilha[n]= 11;
                    pilha[n+1]= -10;
                    x=n + 2;
                    empilha(&x);
                    analisesintatica(tk);
                    return 0;
                }
                if (tk == 10){ //comando for
                    desempilha(n);
                    pilha[n]= 10;
                    pilha[n+1]= -10;
                    x=n + 2;
                    empilha(&x);
                    analisesintatica(tk);
                    return 0;
                }
                if (tk == 8){ //comando while
                    desempilha(n);
                    pilha[n]= 8;
                    pilha[n+1]= -10;
                    x=n + 2;
                    empilha(&x);
                    analisesintatica(tk);
                    return 0;
                }
                if (tk == 12){ //camando switch
                    desempilha(n);
                    pilha[n]= 12;
                    pilha[n+1]= -10;
                    x=n + 2;
                    empilha(&x);
                    analisesintatica(tk);
                    return 0;
                }
            }else if (tk == 9 || tk == 64 || ((tk == 66) || (tk == 67) || (tk == 1))){
                if (tk == 9){ //comando Do
                    desempilha(n);
                    pilha[n]= 9;
                    pilha[n+1]= 47;
                    pilha[n+2]= -10;
                    x=n + 3;
                    empilha(&x);
                    analisesintatica(tk);
                    return 0;
                }
                if (tk == 64){ //comando Break
                    desempilha(n);
                    pilha[n]= 64;
                    pilha[n+1]= 47;
                    pilha[n+2]= -10;
                    x=n + 3;
                    empilha(&x);
                    analisesintatica(tk);
                    return 0;
                }
                if ((tk == 66) || (tk == 67) || (tk == 1)){ //comando int, float e id
                    desempilha(n);
                    pilha[n]= -12;
                    pilha[n+1]= -6;
                    pilha[n+2]= -12;
                    pilha[n+3]= -13;
                    pilha[n+4]= 47;
                    pilha[n+5]= -10;
                    x=n + 6;
                    empilha(&x);
                    analisesintatica(tk);
                    return 0;
                }
            }else{
            	n++;
            	analisesintatica(tk);
                return 0;
            }
        }

        if (pilha[n] == -11){ //nao terminal RestSwitch
            if (tk == 64){
                desempilha(n);
                pilha[n]= -10;
                pilha[n+1]= 14;
                pilha[n+2]= -12;
                pilha[n+3]= 46;
                pilha[n+4]= -2;
                pilha[n+5]= -11;
                x=n + 6;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else{
            	n++;
            	analisesintatica(tk);
            	return 0;
            }
        }

        if (pilha[n] == -12){ //terminal ID
            if (tk == 66){ //comando float
                desempilha(n);
                pilha[n]= 66;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else if (tk == 67){ //comando int
                desempilha(n);
                pilha[n]= 67;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else if (tk == 1){
                desempilha(n); //comando id
                pilha[n]= 1;
                x=n + 1;
                empilha(&x);
                analisesintatica(tk);
                return 0;
            }else {
            	n++;
            	analisesintatica(tk);
            	return 0;
            }
        }

        if (pilha[n] == -13){ //não terminal RestSeq
            desempilha(n); //comando id
            pilha[n]= -6;
            pilha[n+1]= -12;
            pilha[n+2]= -13;
            x=n + 3;
            empilha(&x);
            analisesintatica(tk);
            return 0;
        }
    }
	return 0;
}

int palavra_reservada(char lex[]) {
    int postab = 0;
    while (strcmp("fimtabela", lista_pal[postab].palavra) != 0) {
        if (strcmp(lex, lista_pal[postab].palavra) == 0)
            return lista_pal[postab].tk;
        postab++;
    }
    return TKId;
}

int rec_equ(char st[], char lex[], short *op, short *numeroEspaco) {
    int estado = 0, fim = 0, posl = 0, ponto=0;
    if (*op == 1){
        pos=0;
        *op=0;
    }
    while (!fim) {
        char c = st[pos];
        lex[posl++] = c;
        switch (estado) {
        case 0:
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') {
                pos++;
                estado = 1;
                break;
            }

            if  (c >= '0' && c <= '9'){
                c = st[++pos];
                estado = 2;
                break;
            }

            if (c == '.'){
                c = st[++pos];
                if (c >= '0' && c<='9'){
                     lex[posl++] = c;
                     estado = 2;
                     ponto = 1;
                     break;
                }else{
                	lex[posl] = '\0';
                	pos++;
                	return TKPonto;
                }
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
            if (c == '"') {
                lex[posl] = '\0';
                pos++;
                return TKAspaDupla;
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
                if (c >= '0' && c<='9'){
                 	estado= 2;
                	break;
           	    }
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
            if (c == ' ' || c == '\n' || c == '\t') {
                *numeroEspaco += 1;
                pos++;
                posl--;
                break;
            }
            if (c == '\0')
                return -1;
            pos++;
            lex[posl] = '\0';
            return -50;
            break;
        case 1: //PALAVRA RESERVADA
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_')) {
                pos++;
                break;
            }
            lex[--posl] = '\0';
            return palavra_reservada(lex);
            break;
        case 2: //NUMERAL
        	if (c == 'E') {
        		lex[posl] = '\0';
        		pos++;
        		break;
        	}
        	if (c >= '0' && c<='9'){
        	    lex[posl] = '\0';
        	   	pos++;
        	   	break;
        	}
        	if (c == '.' && ponto == 0) {
        		lex[posl] = '\0';
        		pos++;
        	  	ponto=1;
        	  	break;
        	}
        	if (ponto == 1){
        		return TKConstFloat;
        	}else if (ponto == 0){
        		return TKConstInt;
        	}
        } //switch
    } // while
} // função

int main() {
    FILE *arquivoLeitura;
    int tk;
    char exp1[500], lex[20];
    char local[200] = "";
    setbuf(stdout, NULL);
    short opcao, op;
    int errorCode;

    //montando as duas primeiras posições
    pilha[0]= -10;
    pilha[1]= 999;

    printf("Analisador Lexico da Linguagem C\n");
    printf("1 - Digitar codigo-fonte.\n");
    printf("2 - Abrir arquivo que contenha o codigo-fonte.\n");
    printf("3 - Sair\n");
    do{
        printf("Opcao: ");
        scanf("%hd", &opcao);
        fflush(stdin);
    }while(opcao < 1 || opcao > 3);

    switch(opcao){
    case 1:{
        printf("Digite o programa a ser analisado (ex: void main(){int a,b,c;a=b+c;}\n");
        gets(exp1);
    }break;
    case 2:{
        printf("\nDigite o local do arquivo + nome + extensao.\n");
        printf("Exemplo: C:/User/Desktop/arquivo.c\n");
        printf("Local: ");
        scanf("%s", local);
        fflush(stdin);
        arquivoLeitura = fopen(local, "r+");
        if (arquivoLeitura == NULL){
            printf("Erro: Arquivo nao encontrado ou nao existe.");
            exit(1);
        }

    }break;
    case 3: exit(1);
    }

    FILE *arquivoGravacao = fopen("Saida.lex", "w+");
    short numeroLinha=0, numeroColuna=0, numeroEspaco=0;

    do{
        if (opcao == 2){
            strcpy(exp1, "");
            fgets(exp1, 100, arquivoLeitura);
            op= 1;
            numeroLinha++;
            numeroColuna= 0;
            numeroEspaco= 0;
        }

        while ((tk = rec_equ(exp1, lex, &op, &numeroEspaco)) != -1){
            numeroColuna += numeroEspaco;

            //tk é o int da posicao
            errorCode = analisesintatica(tk);
            n++;

            if (tk == -50){
                fprintf(arquivoGravacao, "Erro lexico: encontrou o caracter %s na linha %hd e posicao %hd\n", lex, numeroLinha, numeroColuna);
            }else{
                fprintf(arquivoGravacao, "Token:%d Lexema:%s Linha:%hd Coluna:%hd\n", tk, lex, numeroLinha, numeroColuna);
            }
            numeroColuna += strlen(lex);
            numeroEspaco = 0;
        }
    }while(opcao == 2 && !feof(arquivoLeitura));
    printf("\nArquivo Saida.lex criado com sucesso.\n");
    //system("PAUSE");
    fclose(arquivoGravacao);
    return EXIT_SUCCESS;
}
