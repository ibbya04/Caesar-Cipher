#include <stdio.h>
#include <ctype.h>

int caesar_encrypt(FILE *plain, FILE *encrypted, int s)
{
    if (plain == NULL || encrypted == NULL)
    {
        printf("Error: file pointers null\n");
        return 0;
    }

    int c;
    while ((c = getc(plain)) != EOF)
    {
        if (isalpha(c))
        {
            char b = c + s;
            putc(b, encrypted);
        }
        else
        {
            putc(c, encrypted);
        }
    }
    printf("plain.txt has been Caesar encrypted\n");
    return 1;
}

int caesar_decrypt(FILE *encrypted, FILE *decrypted, int s)
{
    if (decrypted == NULL || encrypted == NULL)
    {
        printf("Error: file pointers null\n");
        return 0;
    }

    int c;
    while ((c = getc(encrypted)) != EOF)
    {
        if (isalpha(c))
        {
            char b = c - s;
            putc(b, decrypted);
        }
        else
        {
            putc(c, decrypted);
        }
    }
    printf("encrypted.txt has been Caesar decrypted\n");
    return 1;
}

int main()
{

    int choice;
    while (choice > 2 || choice < 1)
    {
        printf("Choose an encryption type;\n1 = Encrpt\n2 = Decrypt\n");
        scanf("%d", &choice);
    }

    FILE *plain = fopen("plain.txt", "r");
    FILE *encrypted = fopen("encrypted.txt", "r+");
    FILE *decrypted = fopen("decrypted.txt", "r+");

    if (plain == NULL || encrypted == NULL || decrypted == NULL)
        printf("Could not open file/s\n");

    else
    {
        if (choice == 1){
            int shift;
            while (shift < 1 || shift > 25)
            {
                printf("Choose the amount of character shift\n");
                scanf("%d", &shift);
            }
            caesar_encrypt(plain, encrypted, shift);
        }
        else{
            int shift;
            while (shift < 1 || shift > 25)
            {
                printf("Choose the amount of character shift\n");
                scanf("%d", &shift);
            }
            caesar_decrypt(encrypted, decrypted, shift);
        }
        fclose(plain);
        fclose(encrypted);
    }
}