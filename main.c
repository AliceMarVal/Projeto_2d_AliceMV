//Alice Martins Valero

#include <stdio.h>
#include <stdlib.h>

#define arv_tam 100
#define stack_tam 100

char w[16];
int  len=0;

typedef struct{
    char producoes[2];
} Producoes;

char stack[stack_tam];
int top = -1;


void push(char symbol) {
    if (top < stack_tam - 1) {
        top++;
        stack[top] = symbol;
    } else {
        printf("Stack overflow!\n");
        exit(1);
    }
}

void pop() {
    if (top >= 0) {
        top--;
    } else {
        printf("Stack underflow!\n");
        exit(1);
    }
}

int main() {
    FILE *fp;
    char token, arv[arv_tam];
    int cont=0, i=0;
    Producoes p[10];

    // Open file
    fp = fopen("../input.txt", "r");
    if (fp == NULL) {
        printf("erro ao abrir o arquivo\n");
        return 1;
    }

    printf("\n i   q   w          d   p              0   1   2   3   4   5   6   7   8   9   10"); //d do delta
    printf("\n === === ========== === ===            === === === === === === === === === === ===");

//inicializa a pilha
    printf("\n %2d   q0  .%7s   d0  -- ", i, w);
    printf("     s[] : ");
    ++i;

    push('E');

    token = fgetc(fp);
    w[len] = token;
    len++;
    w[len] = '\0';
    goto q1;
int k;
q1:
    //d1 | p1
    if (token == '(' && stack[top] == 'E') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d1  p1  ");

        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push(')');
        push('E');
        push('X');
        push('E');
        push('(');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '1';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    //d2| p2
    } else if (token == '0' && stack[top] == 'E') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d2  p2 ");
        printf("    s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('0');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '2';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    //d3
    } else if (token == '1' && stack[top] == 'E') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d3  p3 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('1');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '3';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    //d4
    } else if (token == 'a' && stack[top] == 'E') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d4  p4 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('a');
        token = fgetc(fp);
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '4';
        ++cont;

    //d5
    } else if (token == 'b' && stack[top] == 'E') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d5  p5 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('b');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '5';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    } else if (token == 'c' && stack[top] == 'E') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d6  p6 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('c');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '6';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    } else if (token == '+' && stack[top] == 'X') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d7  p7 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('+');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '7';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    } else if (token == '-' && stack[top] == 'X') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d8  p8 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('-');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '8';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    } else if (token == '*' && stack[top] == 'X') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d9  p9 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('*');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '9';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    } else if (token == '/' && stack[top] == 'X') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d10  p10 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        push('/');
        p[cont].producoes[0] = 'p';
        p[cont].producoes[1] = '-';
        token = fgetc(fp);
        w[len] = token;
        len++;
        w[len] = '\0';
        ++cont;
    } else if (stack[top] == 'a') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d11  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == 'b') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d12  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == 'c') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d13  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == '0') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d14  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == '1') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d15  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == '(') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d16  --");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == ')') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d17  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        
        token = fgetc(fp);
        if (token != EOF) {
			w[len] = token;
			len++;
			w[len] = '\0';
		}
    
    } else if (stack[top] == '+') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d18  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == '-') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d19  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
        
    } else if (stack[top] == '*') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d20  -- ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    } else if (stack[top] == '/') {
        printf("\n %2d   q1  ", i);
        for (k = 0; k<(len-1); k++)   { printf("%c", w[k]); }
        printf(".");
        for (k = (len-1); k<len; k++) { printf("%c", w[k]); }
        for (k =  len   ; k<50; k++)   { printf(" "); }
        printf("   d21  p1 ");

        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        ++i;

        pop();
    //chegou no final do arquivo
    //d6:
    } else if (token == EOF) {
        printf("\n %2d   q1  %7s.       -- ", i, w);
        printf("     s[] : ");
        for (int h=top; h>=0; h--) { printf("%c   ", stack[h]); }
        printf("Palavra Reconhecida \n");
        ++i;
        goto ARV;
    }
    else{
        printf("\n\nPalavra nao reconhecida");
        goto ARV;
    }
    goto q1;
ARV:
    arv[0] = 'S';
    for(int j=0; j<cont; j++){
        //armazena na arvore aSb
        if(p[j].producoes[1] == '1'){
            arv[j] = 'p';
        }else if(p[j].producoes[1] == '2'){
            arv[j] = '0';
        }else if(p[j].producoes[1] == '3'){
            arv[j] = '1';
        }else if(p[j].producoes[1] == '4'){
            arv[j] = 'a'; 
        }else if(p[j].producoes[1] == '5'){
            arv[j] = 'b';
        }else if(p[j].producoes[1] == '6'){
            arv[j] = 'c';
        }else if(p[j].producoes[1] == '7'){
            arv[j] = '+';
        }else if(p[j].producoes[1] == '8'){
            arv[j] = '-';
        }else if(p[j].producoes[1] == '9'){
            arv[j] = '*';
        }else if(p[j].producoes[1] == '-'){
            arv[j] = '/';
        }

    }
    //print da arvore
    printf("\n\n=== ARVORE DE ANALISE SINTATICA ===\n\n");
    printf("                E\n");
    if(arv[0] == 'p'){
        printf("     /    /     |     \\     \\ ");
        printf("\n    (    E      X      E      )\n");
    }

    if(arv[1] == 'p'){
            printf("     / / | \\ \\  |  / / | \\ \\ \n");
            printf("    ( E  X  E ) %c ( E  X  E )\n",arv[5]);
            printf("      |  |  |       |  |  |\n");
            printf("      %c  %c  %c       %c  %c  %c\n",arv[2],arv[3],arv[4],arv[7],arv[8],arv[9]);

    }
    else{
        printf("         |      |      |\n");
        printf("         %c      %c      %c\n",arv[1],arv[2],arv[3]);
    }
    if(arv[2] == '+' || arv[2] == '-' || arv[2] == '*' || arv[2] == '/'){
        printf("\n     %c\n",arv[2]);
        printf("\n   %c  %c\n",arv[1],arv[3]);
    }
    else{
        for(int i = 0; i < cont; i++){
            if(arv[(i*5)] == '+' || arv[(i*5)] == '-' || arv[(i*5)] == '*' || arv[(i*5)] == '/'){
                printf("\n\n          %c\n",arv[i*5]);
                printf("         / \\ \n");
                printf("         %c %c\n",arv[i*3],arv[i*8]);
                int j;
                for(j = i; j < cont; j++){
                    if(j == i*3){
                        printf("       / \\  / \\\n");
                        printf("      %c  %c  %c  %c\n",arv[j-1],arv[j+1],arv[(i*8)-1],arv[(i*8)+1]);
                    }
                }
            }
    }
    }
    char opr[20];
    int pos = 0;
    int control = 0;

    for (int j = 0; j < cont; j++)
    {
        if (arv[j] == 'p')
        {
            continue;
        }
        else if (arv[j + 1] == '+' || arv[j + 1] == '-' || arv[j + 1] == '*' || arv[j + 1] == '/')
        {
            if (arv[j - 1] == 'p')
            {
                push(arv[j]);
                push(arv[j+2]);
                push(arv[j+1]);
                control++;
                for(int i = 2; i >= 0; i--){
                    if(stack[top-i] =='a'){
                        printf("LOD 0 3\n");
                    }else if(stack[top-i] =='b'){
                        printf("LOD 0 4\n");
                    } else if(stack[top-i] =='c'){
                        printf("LOD 0 5\n");
                    } else if(stack[top-i] =='0'){
                        printf("LIT 0 0\n");
                    } else if(stack[top-i] =='1'){
                        printf("LIT 0 1\n");
                    } else if(stack[top-i] == '+'){
                        printf("OPR 0 2\n");
                    } else if(stack[top-i] == '-'){
                        printf("OPR 0 3\n");
                    } else if(stack[top-i] == '*'){
                        printf("OPR 0 4\n");
                    } else if(stack[top-i] == '/'){
                        printf("OPR 0 5\n");
                    }
                    
                }
                pop();
                pop();
                pop();
            }
            else if (arv[j + 2] == 'p')
            {
                opr[pos] = arv[j + 1];
                pos++;
            }
            if (control == 2)
            {
                if(opr[pos - 1] == '+'){
                    printf("OPR 0 2\n");
                } else if(opr[pos - 1] == '-'){
                    printf("OPR 0 3\n");
                } else if(opr[pos - 1] == '*'){
                    printf("OPR 0 4\n");
                } else if(opr[pos - 1] == '/'){
                    printf("OPR 0 5\n");
                }
            }
        }
    }


    printf("\n\n");
    fclose(fp);
    return 0;
}
