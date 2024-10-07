#include <stdio.h>
#include <stdlib.h>

void factorize(unsigned long n) {
    unsigned long i;
    
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            printf("%lu=%lu*%lu\n", n, n/i, i);
            return;
        }
    }
    printf("%lu=%lu*1\n", n, n);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    unsigned long num;

    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: can't open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        num = strtoul(line, NULL, 10);
        if (num > 1) {
            factorize(num);
        }
    }

    fclose(file);
    return 0;
}
