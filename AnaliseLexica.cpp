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
        {"default", TKDefault}};

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
//                     pos+=2;
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
//                	lex[posl++] = c;
//                	pos+=2;
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
            return -2;
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
            if (tk == -2){
                fprintf(arquivoGravacao, "Erro lexico: encontrou o caracter %s na linha %hd e posicao %hd\n", lex, numeroLinha, numeroColuna);
            }else{
                fprintf(arquivoGravacao, "Token:%d Lexema:%s Linha:%hd Coluna:%hd\n", tk, lex, numeroLinha, numeroColuna);
            }
            numeroColuna += strlen(lex);
            numeroEspaco = 0;
        }
    }while(opcao == 2 && !feof(arquivoLeitura));
    printf("Arquivo Saida.lex criado com sucesso.\n");
    system("PAUSE");
    fclose(arquivoGravacao);
    return EXIT_SUCCESS;
}


