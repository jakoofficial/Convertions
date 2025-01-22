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

char *convertDecToHex(char value[]) {
    char *res = malloc(strlen(value) * sizeof(char));
    int quotient = atoi(res);
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
                    char remLetter[10] = "";
                    sprintf(remLetter, "%c", c);

                    strncat(res, remLetter, 1);
                    // return res;
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
    // printf("Dec (%s) -> Hex: %s\n", value, res);
    const char t = res[strlen(res) - 1];

    return t;
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

char convertBinToDec(char value[]) {
    int len = strlen(value);
    int decimal = 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(value[i])) {
            return -1;
        }

        if (value[i] == '1') {
            decimal += 1 << (len - i - 1);
        }
    }
    char res[30];
    sprintf(res, "%d", decimal);

    // return sprintf(res, "%d", decimal);
    return res;
}

void convertBinToHex(char value[]) {
    int len = strlen(value);
    int split_idx = 0;
    char *result = malloc(len * 2 + 1);
    if (len < 4) {
        return;
    } else {
        char tmp[4];
        for (int i = 0; i < len; i++) {
            tmp[split_idx] = value[i];
            split_idx++;

            if (split_idx >= 4) {
                split_idx = 0;
                char decimal[100000];
                // printf("%d", -convertBinToDec(tmp));
                // printf("Decimal (%s)\n", convertDecToHex(convertBinToDec(tmp)));
                // sprintf(decimal, "%d", convertDecToHex(convertBinToDec(tmp)));
                // strncat(result, decimal, strlen(decimal) + 1);
                sprintf(result, "%d", convertBinToDec(tmp));
            }
        }
    }

    printf("hahaha %s\n", result);
}


char *split(char input[], int index) {
    char *convert = malloc(strlen(input) * sizeof(char));
    for (int i = 0; i < strlen(input); i++) {
        if (i > index) {
            convert[i - 2] = input[i];
        }
    }
    return convert;
}

void check_conversion(char input[]) {
    char decider = input[1];
    if (decider == 'd') {
        convertDecToBin(split(input, 1));
        convertDecToHex(split(input, 1));
    } else if (decider == 'x') {
        printf("Hex: %c\n", decider);
    } else if (decider == 'b') {
        printf("%d\n", convertBinToDec(split(input, 1)));
        convertBinToHex(split(input, 1));
    }
}

int main(void) {
    // check_conversion("0b111011");
    // printf("What do you want to convert?\n");
    // // scanf("%s", inputNumber);
    // // for (int i = 0; i < strlen(inputNumber); i++) {
    // //     if (!isdigit(inputNumber[i])) {
    // //         printf("%s, is not a valid number\n", inputNumber);
    // //         return 0;
    // //     }
    // // }
    printf("%d", convertBinToDec("111011"));
    // convertDecToBin("359");
    // convertDecToHex("35631");
    return 0;
}
