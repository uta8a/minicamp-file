// reference: https://www.youtube.com/watch?v=CzcwHBQWVXM CでRPN電卓を作る
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  int value;
  struct Stack *next;
};

struct Stack *push(int value, struct Stack *stack) {
  struct Stack *new_stack = malloc(sizeof(struct Stack));
  new_stack->value = value;
  new_stack->next = stack;
  return new_stack;
}

struct Stack *pop(struct Stack *stack) {
  return stack->next;
}

int peek(struct Stack *stack) { return stack->value; }

struct Stack *eval(char *tok, struct Stack *stack) {
  if (strcmp(tok, "+") == 0) {
    int y = peek(stack);
    stack = pop(stack);
    int x = peek(stack);
    stack = pop(stack);
    // 足し算
    printf("  pop rdi\n");
    printf("  pop rax\n");
    printf("  add rax, rdi\n");
    printf("  push rax\n");
    return push(x + y, stack);
  }
  if (strcmp(tok, "-") == 0) {
    int y = peek(stack);
    stack = pop(stack);
    int x = peek(stack);
    stack = pop(stack);
    // 1-2.1 ここを埋めてください
    // 引き算

    return push(x - y, stack);
  }
  if (strcmp(tok, "*") == 0) {
    int y = peek(stack);
    stack = pop(stack);
    int x = peek(stack);
    stack = pop(stack);
    // 1-2.2 ここを埋めてください
    // 掛け算

    return push(x * y, stack);
  }
  if (strcmp(tok, "/") == 0) {
    int y = peek(stack);
    stack = pop(stack);
    int x = peek(stack);
    stack = pop(stack);
    // 1-2.3 ここを埋めてください
    // 割り算

    return push(x / y, stack);
  }
  if (stack == NULL) {
    printf(".intel_syntax noprefix\n");
    printf(".globl main\n");
    printf("main:\n");
  }
  printf("  push %d\n", atoi(tok));
  return push(atoi(tok), stack);
}
int main(void) {
  const int buf_max_len = 256;
  char buf[buf_max_len];

  char *source = calloc(buf_max_len, sizeof(char));

  while (fgets(buf, buf_max_len, stdin) != NULL) {
    source = realloc(source, (strlen(source) + strlen(buf) + 1) * sizeof(char)); // null char 1byte
    strcat(source, buf);
  }

  char *tok = strtok(source, " \t\r\n");
  if (tok == NULL) {
    return 1;
  }
  struct Stack *stack = eval(tok, NULL);

  while ((tok = strtok(NULL, " \t\r\n")) != NULL) {
    stack = eval(tok, stack);
  }
  printf("  pop rax\n");
  printf("  ret\n");
  fprintf(stderr, "[");
  for (struct Stack *current = stack; current != NULL;
       current = current->next) {
    fprintf(stderr, "%d", current->value);
    if (current->next) {
      fprintf(stderr, " ");
    } else {
      fprintf(stderr, "]\n");
    }
  }
}
