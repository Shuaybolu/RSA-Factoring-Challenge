#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(unsigned long n) {
    unsigned long i;
    
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

void factorize_rsa(unsigned long n) {
    unsigned long i;
    
    if (n % 2 == 0) {
        printf("%lu=%lu*%lu\n", n, n/2, 2L);
        return;
    }
    
    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            if (is_prime(i) && is_prime(n/i)) {
                printf("%lu=%lu*%lu\n", n, n/i, i);
                return;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    unsigned long num;

    if (argc != 2) {
        printf("Usage: rsa <file>\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: can't open file %s\n", argv[1]);
        return 1;
    }

    if (fgets(line, sizeof(line), file)) {
        num = strtoul(line, NULL, 10);
        if (num > 1) {
            factorize_rsa(num);
        }
    }

    fclose(file);
    return 0;
}
