# include <stdio.h>
# include "stackImpl.h"

int main(void) {
    char str[] = "Forza Ferrari";
    int i;
    stack s;
    reset(&s);
    printf("Stringa: %s\n", str);

    for (i=0; str[i]!='\0'; i++) {
        if (!full(&s))
            push(str[i], &s);
    }
    printf("Estrazione dallo stack\n");
    printf("Size = %d\n", size(&s));

    while (!isEmpty(&s)) {
        putchar(pop(&s));
    }
    putchar('\n');
    return 0;
}
