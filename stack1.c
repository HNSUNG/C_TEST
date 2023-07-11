#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef char element;

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType* stack) {
    stack->top = -1;
}

int is_empty(StackType* stack) {
    return stack->top == -1;
}

int is_full(StackType* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(StackType* stack, element item) {
    if (is_full(stack)) {
        fprintf(stderr, "Stack overflow error.\n");
        return;
    }
    else {
        stack->stack[++(stack->top)] = item;
    }
}

element pop(StackType* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack vacant error.\n");
        exit(1);
    }
    else {
        return stack->stack[(stack->top)--];
    }
}

element peek(StackType* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack vacant error.\n");
        exit(1);
    }
    else {
        return stack->stack[stack->top];
    }
}

int check_matching(char* in) {
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);
    init(&s);

    for (i = 0; i < n; i++) {
        ch = in[i];
        switch (ch) {
            case '(':
            case '{':
            case '[':
                push(&s, ch);
                break;
            case ')':
            case '}':
            case ']':
                if (is_empty(&s))
                    return 0;
                else {
                    open_ch = pop(&s);
                    if ((open_ch == '(' && ch != ')') ||
                        (open_ch == '{' && ch != '}') ||
                        (open_ch == '[' && ch != ']')) {
                        return 0;
                    }
                    break;
                }
        }
    }

    if (!is_empty(&s))
        return 0;
    return 1;
}

int main() {
    char input[MAX_STRING];
    printf("괄호를 입력하세요: ");
    fgets(input, MAX_STRING, stdin);

    // 개행 문자 제거
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';

    if (check_matching(input))
        printf("괄호의 짝이 맞습니다.\n");
    else
        printf("괄호의 짝이 맞지 않습니다.\n");

    return 0;
}

