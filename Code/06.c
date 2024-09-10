//  Write a C program for ciphertext has been generated with an affine cipher. 
//  The most frequent letter of the ciphertext is "B," and the second most frequent 
//  letter of the ciphertext is "U."Break this code.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26
#define MAX_TEXT_LENGTH 1000  // Adjust as needed for your input size

int main() {
    char ciphertext[MAX_TEXT_LENGTH];
    
    // Get the ciphertext from the user
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // Remove newline character if present
    size_t length = strlen(ciphertext);
    if (length > 0 && ciphertext[length - 1] == '\n') {
        ciphertext[length - 1] = '\0';
    }

    // Most frequent letter in ciphertext is 'B' (position 1) 
    // Second most frequent letter in ciphertext is 'U' (position 20)
    int freq1 = 'B' - 'A';  
    int freq2 = 'U' - 'A';  

    // Assume the most frequent letter in plaintext is 'E' (position 4)
    // and the second most frequent is 'T' (position 19)
    int expectedMostFrequent = 4;  
    int expectedSecondMostFrequent = 19;  

    // Calculate deltaC and deltaP
    int deltaC = (freq2 - freq1 + ALPHABET_SIZE) % ALPHABET_SIZE;
    int deltaP = (expectedSecondMostFrequent - expectedMostFrequent + ALPHABET_SIZE) % ALPHABET_SIZE;

    // Find modular inverse of deltaP (brute force method)
    int a_inv = -1;
    for (int i = 1; i < ALPHABET_SIZE; i++) {
        if ((deltaP * i) % ALPHABET_SIZE == 1) {
            a_inv = i;
            break;
        }
    }

    if (a_inv == -1) {
        printf("No modular inverse found for deltaP = %d\n", deltaP);
        return 1;
    }

    // Calculate a and b
    int a = (deltaC * a_inv) % ALPHABET_SIZE;
    int b = (freq1 - a * expectedMostFrequent + ALPHABET_SIZE) % ALPHABET_SIZE;

    // Print the values of a and b
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    // Decrypt the ciphertext
    printf("Decrypted text:\n");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            char decrypted_char = (a_inv * (ciphertext[i] - base - b + ALPHABET_SIZE)) % ALPHABET_SIZE + base;
            printf("%c", decrypted_char);
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");

    return 0;
}
