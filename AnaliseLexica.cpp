#define TKId 1
#define TKVoid 2
#define TKInt 3
#define TKFloat 4
#define TKVirgula 5
#define TKDoisPontos 6
#define TKAbrePar 7
#define TKFechaPar 8
#define TKAtrib 9
#define TKPontoeVirg 10
#define TKAbreChave 11
#define TKFechaChave 12
#define TKSoma 13
#define TKDuploMais 14
#define TKChar 15
#define TKLong 16
#define TKDouble 17
#define TKShort 18
#define TKConst 19
#define TKPrintf 20
#define TKPrivate 21
#define TKPublic 22
#define TKScanf 23
#define TKFflush 24
#define TKStdin 25
#define TKNULL 26
#define TKPerror 27 
#define TKContinue 28
#define TKDo 29 
#define TKWhile 30
#define TKFor 31
#define TKExit 32
#define TKEof 33
#define TKFree 34
#define TKIf 35
#define TKMalloc 36
#define TKReturn 37
#define TKSizeof 38
#define TKStatic 39
#define TKStrlen 40
#define TKUnsigned 41
#define TKPonto 42
#define TKAspaDupla 43
#define TKPontoExclamacao 45
#define TKDiferente 46
#define TKAbreConchete 47 
#define TKFechaConchete 48
#define TKDubloMais 49
#define TKMenos 50
#define TKDuploMenos 51
#define TKMultiplica 52
#define TKDivisao 53
#define TKMaisIgual 54
#define TKMenosIgual 55
#define TKVezesIgual 56
#define TKDivideIgual 57 
#define TKRestoDivisao 58
#define TKMaior 59
#define TKMaiorIgual 60
#define TKMenor 61
#define TKMenorIgual 62
#define TKMenorBinario 63
#define TKMaiorBinario 64
#define TKPontoExclamacaoIgual 65

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int pos = 0;

struct pal_res{char palavra[20]; int tk;};
struct pal_res lista_pal[]={{"void",TKVoid},
                  {"int",TKInt},
                  {"float",TKFloat},
                  {"fimtabela",TKId},
				  {"char",TKChar},
				  {"long",TKLong},
				  {"double",TKDouble},
				  {"short",TKShort},
				  {"const",TKConst},
				  {"printf",TKPrintf},
				  {"private",TKPrivate},
				  {"public",TKPublic},
				  {"scanf",TKScanf},
				  {"fflush",TKFflush},
				  {"stdin",TKStdin},
				  {"NULL",TKNULL},
				  {"perror",TKPerror}, 
				  {"continue",TKContinue},
				  {"do",TKDo}, 
				  {"while",TKWhile},
				  {"for",TKFor},
				  {"exit",TKExit},
				  {"eof",TKEof},
				  {"free",TKFree},
				  {"if",TKIf},
				  {"malloc",TKMalloc},
				  {"return",TKReturn},
				  {"sizeof",TKSizeof},
				  {"static",TKStatic},
				  {"strlen",TKStrlen},
				  {"unsigned",TKUnsigned}};

int palavra_reservada(char lex[]){
int postab=0;
while (strcmp("fimtabela",lista_pal[postab].palavra)!=0)
   {
   if (strcmp(lex,lista_pal[postab].palavra)==0)
      return lista_pal[postab].tk;
   postab++;
   }
return TKId;
}


int rec_equ(char st[],char lex[])
{
int estado=0,
    fim=0,
    posl=0;
while (!fim)
   {
   char c=st[pos];
//printf("%s\n",st);
//printf("char=%c pos=%d\n",c,pos);
   lex[posl++]=c;
   switch(estado){
      case 0:if (c>='a' && c<='z' || c>='A' && c<='Z' || c=='_'){
				pos++;
				estado=1;
				break;}
             if (c=='='){
				 lex[posl]='\0';
				 pos++;
				 return TKAtrib;
             }
             if (c=='+')
			    {
			    c=st[++pos];
			    if (c=='+')
			       {
				   lex[posl++]='+';
     			   lex[posl]='\0';
				   pos++;
				   return TKDuploMais;
				   }
				else if (c=='='){
					lex[posl++]='=';
					lex[posl]='\0';
					pos++;
					return TKMaisIgual;
				}else{
	               lex[posl]='\0';
				   return TKSoma;
				   }
			    }
             if (c=='('){lex[posl]='\0';pos++;return TKAbrePar;}
             if (c==')'){lex[posl]='\0';pos++;return TKFechaPar;}
             if (c=='{'){lex[posl]='\0';pos++;return TKAbreChave;}
             if (c=='}'){lex[posl]='\0';pos++;return TKFechaChave;}
             if (c==','){lex[posl]='\0';pos++;return TKVirgula;}
             if (c==';'){lex[posl]='\0';pos++;return TKPontoeVirg;}
             if (c==':'){lex[posl]='\0';pos++;return TKDoisPontos;}
			 if (c=='.'){lex[posl]='\0';pos++;return TKPonto;}
			 if (c=='"'){lex[posl]='\0';pos++;return TKAspaDupla;}
			 if (c=='!'){
			    c=st[++pos];
			    if (c=='='){
				   lex[posl++]='=';
     			   lex[posl]='\0';
				   pos++;
				   return TKPontoExclamacaoIgual;
				   }else{
	               lex[posl]='\0';
				   return TKPontoExclamacao;
				   }
			    }
			 if (c=='['){lex[posl]='\0';pos++;return TKAbreConchete;}
			 if (c==']'){lex[posl]='\0';pos++;return TKFechaConchete;}
			 if (c=='-')
			    {
			    c=st[++pos];
			    if (c=='-')
			       {
				   lex[posl++]='-';
     			   lex[posl]='\0';
				   pos++;
				   return TKDuploMenos;
				   }
				else if (c=='='){
					lex[posl++]='=';
					lex[posl]='\0';
					pos++;
					return TKMenosIgual;
				}else{
	               lex[posl]='\0';
				   return TKMenos;
				   }
			    }
			 if (c=='*'){
				 c=st[++pos];
			    if (c=='='){
				   lex[posl++]='=';
     			   lex[posl]='\0';
				   pos++;
				   return TKVezesIgual;
				   }else{
	               lex[posl]='\0';
				   return TKMultiplica;
				   }
			    }
			 if (c=='/'){
				 c=st[++pos];
			    if (c=='='){
				   lex[posl++]='=';
     			   lex[posl]='\0';
				   pos++;
				   return TKDivideIgual;
				   }else{
	               lex[posl]='\0';
				   return TKDivisao;
				   }
			    }
			 if (c=='%'){lex[posl]='\0';pos++;return TKRestoDivisao;}
			 if (c=='>'){
				  c=st[++pos];
			    if (c=='=')
			       {
				   lex[posl++]='=';
     			   lex[posl]='\0';
				   pos++;
				   return TKMaiorIgual;
				   }
				else if (c=='>'){
					lex[posl++]='>';
					lex[posl]='\0';
					pos++;
					return TKMaiorBinario;
				}else{
	               lex[posl]='\0';
				   return TKMaior;
				   }
			    }
			 if (c=='<'){
				 c=st[++pos];
			    if (c=='=')
			       {
				   lex[posl++]='=';
     			   lex[posl]='\0';
				   pos++;
				   return TKMenorIgual;
				   }
				else if (c=='<'){
					lex[posl++]='<';
					lex[posl]='\0';
					pos++;
					return TKMenorBinario;
				}else{
	               lex[posl]='\0';
				   return TKMenor;
				   }
			    }
             if (c==' ' || c=='\n') {pos++;posl--;break;}
             if (c=='\0') return -1;
             printf("Erro léxico: encontrou o caracter %c na posição %d",c,pos);
             break;
      case 1:if (c>='a' && c<='z' || c>='A' && c<='Z' || c=='_' || c>='0' && c<='9') {pos++;break;}
             lex[--posl]='\0';
             return palavra_reservada(lex);
      } //switch
   }// while
}// função

int main()
{
int tk;
char exp1[200],lex[20];
printf("Digite o programa a ser analisado (ex: void main(){int a,b,c;a=b+c;}\n");
gets(exp1);
while ((tk=rec_equ(exp1,lex))!=-1)
   printf("%d %s\n",tk,lex);
//system("pause");
}
