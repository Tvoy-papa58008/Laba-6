#include <string.h>
#include <stdio.h>
#include <ctype.h>
#pragma warning(disable:4996)
 
#define BUFSIZE 256
 
void rsortDigits(char* string) {
    int digits[10] = { 0 };
    char* it;
    for (it = string; *it != '\0'; ++it) {
        if (*it >= '0' && *it <= '9') {
            ++digits[*it - 48];
        }
    }
    int i;
    for (--it, i = 0; it != string - 1; --it) {
        if (*it >= '0' && *it <= '9') {
            while (digits[i] == 0) { ++i; }
            *it = i + 48;
            --digits[i];
        }
    }
}
 
int main()
{
    char buff[BUFSIZE];
    printf("Source: ");
    if (fgets(buff, BUFSIZE, stdin) == NULL) {
        return 1;
    }
    rsortDigits(buff);
    printf("%s", buff);
    return 0;
}