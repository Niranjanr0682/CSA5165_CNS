#include <stdio.h>
#include <ctype.h>

#define CIPHERTEXT "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;"

void decrypt(const char* text, const char* key) {
    for (int i = 0; text[i]; i++) {
        char c = text[i];
        putchar(isalnum(c) ? key[c] : c);
    }
    putchar('\n');
}

int main() {
    char key[128] = {0};
    key['‡'] = 'e'; key['*'] = 't'; key['4'] = 'h'; key[';'] = 'a';
    key['8'] = 'o'; key['6'] = 'n'; key['5'] = 'r'; key['3'] = 'c';
    key[')'] = 's'; key['('] = 'i'; key['†'] = 'd'; key['¶'] = 'l';
    key['?'] = 'u'; key[':'] = 'm'; key[']'] = 'y'; key['9'] = 'f';
    key['.'] = 'g'; key['2'] = 'p'; key['1'] = 'w'; key['—'] = 'b';

    printf("Decrypted message:\n");
    decrypt(CIPHERTEXT, key);
    return 0;
}
