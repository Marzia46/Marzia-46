#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pat[100];
    int i, j, n, m, lps[100];

    printf("Enter text: ");
    scanf("%s", text);

    printf("Enter pattern: ");
    scanf("%s", pat);

    n = strlen(text);
    m = strlen(pat);

    // LPS Array Construction
    lps[0] = 0;
    j = 0;

    for(i = 1; i < m; i++) {

        while(j > 0 && pat[i] != pat[j])
            j = lps[j-1];

        if(pat[i] == pat[j])
            j++;

        lps[i] = j;
    }

    // Pattern Searching
    j = 0;

    for(i = 0; i < n; i++) {

        while(j > 0 && text[i] != pat[j])
            j = lps[j-1];

        if(text[i] == pat[j])
            j++;

        if(j == m) {
            printf("Pattern found at index %d\n", i-m+1);

            j = lps[j-1];
        }
    }

    return 0;
}