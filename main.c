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
    // Print the final binary
    printf("Dec (%s) -> bin: %s\n", value, res);
}

int main(void) {
    printf("What do you want to convert?\n");
    scanf("%s", inputNumber);
    for (int i = 0; i < strlen(inputNumber); i++) {
        if (!isdigit(inputNumber[i])) {
            printf("%s, is not a valid number\n", inputNumber);
            return 0;
        }
    }

    ClearScreen();
    convertDecToBin(inputNumber);
    convertBinToDec(inputNumber);
    // printf("Remainder %s\n", convertDecToBin("13"));
    // printf("Result: %d", convertBinToDec(val));
    // printf("Enter the value you'd like to convert\n"
    //        "(Decimal '0d+yours' | Hexadecimal '0x'+yours | Binary '0b+yours')\n: ");
    //
    // for (int i = 0; i < sizeof(types) / sizeof(types[0]) ; i++) {
    //     printf("%d) %s\n", i+1, types[i]);
    // }
    // printf("Which type you'd like to convert: ");
    // scanf("%d", &convertInput);
    //
    // ClearScreen();
    return 0;
}
