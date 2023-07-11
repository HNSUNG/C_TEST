#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void init(Stack* stack) {
    stack->top = NULL;
}

int is_empty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, char item) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack vacant error.\n");
        exit(1);
    }

    char item = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return item;
}

char peek(Stack* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack vacant error.\n");
        exit(1);
    }

    return stack->top->data;
}

int check_matching(char* in) {
    Stack stack;
    init(&stack);

    for (int i = 0; in[i] != '\0'; i++) {
        char ch = in[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                push(&stack, ch);
                break;
            case ')':
                if (is_empty(&stack) || peek(&stack) != '(')
                    return 0;
                else
                    pop(&stack);
                break;
            case '}':
                if (is_empty(&stack) || peek(&stack) != '{')
                    return 0;
                else
                    pop(&stack);
                break;
            case ']':
                if (is_empty(&stack) || peek(&stack) != '[')
                    return 0;
                else
                    pop(&stack);
                break;
        }
    }

    return is_empty(&stack);
}

int main() {
    char input[100];
    printf("괄호를 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    if (check_matching(input))
        printf("괄호의 짝이 맞습니다.\n");
    else
        printf("괄호의 짝이 맞지 않습니다.\n");

    return 0;
}

