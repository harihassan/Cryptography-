#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + shift) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + shift) % 26;
        }
    }
}

int main() {
    char message[100];
    int shift;

    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    return 0;
}

