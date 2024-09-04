// Write a C program for generalization of the Caesar cipher. known as the affine
// Caesar cipher, has the following form: For each plaintext letter p, substitute 
// the ciphertext letter C: C = E([a,b],p) = (ap + b) mod 26 A basic requirement of 
// any encryption algorithm is that it be one-to-one. That is, if p q, then E(k, p) E(k, q).
// Otherwise, decryption is impossible, because more than one plaintext character 
// maps into the same ciphertext character. The affine Caesar cipher is not one-to-one 
// for all values of a. For example, for a = 2 and b = 3, then E([a,b],0) = E([a,b],13) = 3.
// a. Are there any limitations on the value of b?
// b. Detemiine which values of a are not allowed.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char plaintext[100], ciphertext[100];
    int a, b;
    int i, a_inv;

    // Input the values of 'a' and 'b'
    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter the value of 'b': ");
    scanf("%d", &b);
    getchar();  // Clear the newline from the buffer

    // Input the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  // Remove newline character

    // Calculate modular inverse of 'a' under mod 26
    a_inv = -1;
    for (i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }

    if (a_inv == -1) {
        printf("Invalid 'a' value; it must be coprime with 26.\n");
        return 1;
    }

    // Encrypt the plaintext
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            ciphertext[i] = (a * (plaintext[i] - base) + b) % 26 + base;
        } else {
            ciphertext[i] = plaintext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0';  // Null-terminate the ciphertext string

    // Output the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            plaintext[i] = (a_inv * (ciphertext[i] - base - b + 26)) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i];  // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[i] = '\0';  // Null-terminate the plaintext string

    // Output the decrypted text
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
