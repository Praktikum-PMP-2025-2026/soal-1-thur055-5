/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4
 *   Hari dan Tanggal    : 05/05/2026
 *    (NIM)          : Arthur (13224055)
 *    File           : soal1.c
 *   Deskripsi           : pengecekan tutup kurung
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SegelNode
{
    struct SegelNode* Prev;
    char Segel;
    struct SegelNode* Next;
} SegelNode ;

typedef struct SegelStack{
    SegelNode *head;
    SegelNode *last;
} SegelStack;

void init_stack(SegelStack *S){
    S->head = NULL;
    S->last = NULL;
}

void push (SegelStack *S, char A){
    SegelNode *N = (SegelNode*)malloc(sizeof(SegelNode));
    N->Segel = A;
    if(S->head == NULL){
        N->Prev = NULL;
        N->Next = NULL;
        S->head = N;
        S->last = N;
    }
    else{
        S->last->Next = N;
        N->Prev = S->last;
        S->last = N;
        N->Next = NULL;
    }
}

void pop (SegelStack *S, char *A){
    SegelNode *N = (SegelNode*)malloc(sizeof(SegelNode));
    if(S->head == NULL){
       // printf("Stack Kosong\n");
    }
    else{
        if(S->last->Prev ==NULL){
            S->head = NULL;
        }
        int i = 0;
        N = S->last;
        *A = N->Segel;
        S->last = S->last->Prev;
        i++;
        
    }
}

int main (){
    char str[100];
    char strseg[100];
    char strhuruf[100];
    SegelStack S;
    init_stack(&S);
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++){
        push(&S, str[i]);
    }
    //pop(&S, strout);
    /*
    for (int i = 0; i < strlen(strout); i++){
        printf("%c ", strout[i]);
    }
    */
    int count9 = 0;
    int countP = 0;
    int countO = 0;
    int counthuruf = 0;
    for (int i = 0; i < strlen(str); i++){
        char temp;
        pop(&S, &temp);
        //printf("%c ", temp);
        if (strcmp(&temp, ")") == 0){
            count9++;
        }
        else if (strcmp(&temp, "]") == 0)
        {
            countP++;
        }
        else if (strcmp(&temp, "}") == 0){
            countO++;
        }
        else if (strcmp(&temp, "(") == 0&& count9 % 2 == 1){
            count9++;
        }
        else if (strcmp(&temp, "[") == 0 && countP % 2 == 1){
            countP++;
        }
        else if (strcmp(&temp, "{") == 0 && countO % 2 == 1){
            countO++;
        }
        else{
            if (S.head == NULL){
                break;
            }
            counthuruf++;
        }
        
    }
    if ((count9 % 2 == 0) && (countP % 2 == 0) && (countO % 2 == 0)){
        printf("VALID");
        //printf("%d %d %d\n", count9, countO, countP);
    }
    else{
        printf("INVALID");
        //printf("%d %d %d\n", count9, countO, countP);
    }

}

