#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char value_to_hexchar(int val) {
    if (val >= 0 && val <= 9) return '0' + val;
    if (val >= 10 && val <= 15) return 'A' + (val - 10);
    return '?';
}

int needed_mod7(int sum) {
    int rem = sum % 7;
    if (rem < 0) rem += 7;
    return (7 - rem) % 7;
}

int main(void) {
    srand((unsigned int)time(NULL));

    int length = 8;
    int sum = 0;
    char key[9];

    printf("Generating a key of %d characters with sum %% 7 == 0\n", length);

    for (int i = 0; i < length - 1; i++) {
        int val = rand() % 16;
        key[i] = value_to_hexchar(val);
        sum += val;
        printf("Char %d: %c, partial sum = %d\n", i + 1, key[i], sum);
    }

    int last_val = needed_mod7(sum);
    if (last_val > 15) last_val = 15;
    key[length - 1] = value_to_hexchar(last_val);
    sum += last_val;

    key[length] = '\0';

    printf("Last char: %c, final sum = %d\n", key[length - 1], sum);
    printf("Generated key: %s\n", key);
    printf("Validation: sum %% 7 = %d\n", sum % 7);

    return 0;
}