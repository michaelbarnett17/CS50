#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void processMessage(string message, string cypher);
void processLowerCaseChar(int currentCharAscii, string cypher);
void processUpperCaseChar(int currentCharAscii, string cypher);
char numberToCypher(int currentCharAscii, string cypher);
bool isKeyValid(string cypher);

int main(int argc, string argv[])
{
    //DEBUG
    //string message = "Hello, World!";
    //string cypher = "VCHPRZGJNTLSKFBDQWAXEUYMOI";
    //printf("%s", argv[1]);

    string message;
    string cypher = argv[1];

    if (argc != 2)
    {
        printf("enter exactly one argument after programe name");
        return true;
    }
    if (isKeyValid(cypher))
    {
        message = get_string("plaintext:");
        processMessage(message, cypher);
        return false;
    }
    else
    {
        return true;
    }
}

void processMessage(string message, string cypher)
{
    printf("ciphertext:");
    for (int i = 0; i < strlen(message); i++)
    {
        char currentCharAscii = (int)message[i];

        if (122 >= currentCharAscii && currentCharAscii >= 97)
        {
            processLowerCaseChar(currentCharAscii, cypher);
        }
        else if ( 90 >= currentCharAscii && currentCharAscii >= 65)
        {
            processUpperCaseChar(currentCharAscii, cypher);
        }
        else
        {
            printf("%c", message[i]);
        }
    }
    printf("\n");
}

void processLowerCaseChar(int currentCharAscii, string cypher)
{
    // a = 1, b = 2, ...
    int shiftLower = 97;

    int shiftedCharacter = currentCharAscii - shiftLower;

    printf("%c", tolower(numberToCypher(shiftedCharacter, cypher)));
}

void processUpperCaseChar(int currentCharAscii, string cypher)
{
    // A = 1, B = 2, ...
    int shiftUpper = 65;

    int shiftedCharacter = currentCharAscii - shiftUpper;

    printf("%c", toupper(numberToCypher(shiftedCharacter, cypher)));
}

char numberToCypher(int shiftedCharacter, string cypher)
{
    return cypher[shiftedCharacter];
}

bool isKeyValid(string cypher)
{
    if (strlen(cypher) != 26)
    {
        return false;
    }

    for (int i = 0; i < strlen(cypher); i++)
    {
        if (((97 > cypher[i]) && (cypher[i] > 90)) || cypher[i] > 122 || cypher[i] < 65)
        {
            return false;
        }

        for (int j = (i + 1); j < 26; j++)
        {
            if (cypher[i] == cypher[j])
            {
                return false;
            }
        }
    }
    return true;
}

