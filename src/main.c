#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef int64_t Sharte_integer; 

typedef enum {
SHARTE_TAG_INTEGER = 0x01,
SHARTE_TAG_SYMBOL  = 0x10,
} Sharte_tag;

typedef uintptr_t Sharte_object;

size_t
fskip(FILE *input, int (*pred)(int))
{
    char c;
    size_t n = 0;

    while (pred(c = fgetc(input))) {
        n++;
    }
    ungetc(c, input);
    return n;
}

Sharte_tag
sharte_tag(Sharte_object obj)
{
    return obj & 0x3;
}

Sharte_integer
sharte_integer(Sharte_object obj)
{
    return (Sharte_integer)(obj >> 2);
}

Sharte_object
sharte_read(FILE *input)
{
    char c;

    fskip(input, isspace);
    while ((c = fgetc(input)) != EOF) {
        printf("%c ", c);
    }
    printf("\n");
    return 0;
}

Sharte_object
sharte_eval(Sharte_object input)
{
    return input;
}

char *
sharte_print(Sharte_object input)
{
    (void)input;
    return "freakybob";
}

int
main(void)
{
    printf("%s\n", sharte_print(sharte_eval(sharte_read(stdin))));
}
