#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inputNumber[30];

enum ConvertionType {
    DECIMAL,
    HEXADECIMAL,
    BINARY,
};

char types[3][30] = {"Decimal", "Hexadecimal", "Binary"};

void ClearScreen() {
    printf("\x1B[2J\x1B[H");
}

int convertInput;

int power(int value, int exponent) {
    int valOri = value;
    for (int i = 1; i < exponent; i++) {
        value *= valOri;
    }
    return value;
}

char val[] = "1000";

void reverse(char res[]) {
    // Reverse char array
    int l = 0;
    int r = strlen(res) - 1;
    char t;

    while (l < r) {
        // Swap characters
        t = res[l];
        res[l] = res[r];
        res[r] = t;

        // Move pointers towards each other
        l++;
        r--;
    }
}

void convertBinToDec(char value[]) {
    int len = strlen(value);
    int decimal = 0;
    for (int i = 0; i < len; i++) {
        if (value[i] == '1') {
            decimal += 1 << (len - i - 1);
        }
    }
    printf("Binary (%s) -> Decimal: %d\n", value, decimal);
}

void convertDecToHex(char value[]) {
    char res[30];
    int quotient = atoi(value);
    int remainder = 0;

    while (quotient != 0) {
        remainder = quotient % 16;
        quotient = quotient / 16;

        int rest = 0;
        if (remainder > 9) {
            rest = remainder - 10;
            char c;
            int i = 0;
            // Converts the rest of the remainder into the corresponding Hex Character
            for (c = 'A'; c <= 'F'; c++) {
                if (i == rest) {
                    // printf("%c", c);
                    char remLetter[10] = "";
                    sprintf(remLetter, "%c", c);

                    strncat(res, remLetter, 1);
                    break;
                }
                i++;
            }
        } else {
            char rem[1];
            sprintf(rem, "%d", remainder);
            strncat(res, rem, 1);
        }
    }

    printf("Hexadecimal: %s\n", res);
}

void convertDecToBin(char value[]) {
    char res[30] = "";
    int quotient = atoi(value);
    int remain = 0;

    char remainderString[30];
    while (quotient > 0) {
        remain = quotient % 2;
        quotient = quotient / 2;
        sprintf(remainderString, "%d", remain);
        strncat(res, remainderString, strlen(remainderString));
    }

    reverse(res);
    // Print the final binary
    printf("Dec (%s) -> Bin: %s\n", value, res);
}

int main(void) {
    // printf("What do you want to convert?\n");
    // // scanf("%s", inputNumber);
    // // for (int i = 0; i < strlen(inputNumber); i++) {
    // //     if (!isdigit(inputNumber[i])) {
    // //         printf("%s, is not a valid number\n", inputNumber);
    // //         return 0;
    // //     }
    // // }

    convertDecToBin("359");
    // convertDecToHex("35631");
    return 0;
}
