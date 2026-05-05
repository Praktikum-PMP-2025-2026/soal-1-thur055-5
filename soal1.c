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
        printf("Stack Kosong\n");
    }
    else{
        int i = 0;
        N = S->last;
        *A = N->Segel;
        S->last = S->last->Prev;
        i++;
        if(S->last->Prev ==NULL){
            S->head = NULL;
        }
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
    for (int i = 0; i < strlen(str) - 1; i++){
        char temp;
        pop(&S, &temp);

        if (strcmp(&temp, "(") == 0){
            count9++;
        }
        else if (strcmp(&temp, "[") == 0)
        {
            countP++;
        }
        else if (strcmp(&temp, "{") == 0){
            countO++;
        }
        else if (strcmp(&temp, ")") == 0&& count9 % 2 == 1){
            count9++;
        }
        else if (strcmp(&temp, "]") == 0 && countP % 2 == 1){
            countP++;
        }
        else if (strcmp(&temp, "}") == 0 && countO % 2 == 1){
            countO++;
        }
        else{
            continue;
        }
        
    }
    if (count9 % 2 == 0 && countP % 2 == 0 && countO % 2 == 0){
        printf("VALID");
    }
    else{
        printf("INVALID");
    }

}

