#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int convertBinaryToDecimal(int binaryValue);

int getIntegerLength(int value);

void extractDigitsFromInt(int value, int length, int *valuesArray);

int
main() {
    int userInputValue, outputValue;
    printf("Introduce un valor binario:");
    scanf("%d", &userInputValue);
    outputValue = convertBinaryToDecimal(userInputValue);
    if (outputValue == -1) {
        printf("Valor binario introducido no valido.");
        return 1;
    }
    printf("Binario (%d) => Decimal: %d", userInputValue, outputValue);
    return 0;
}

int
convertBinaryToDecimal(int binaryValue) {

    int decimalValue = 0, bValueLength = getIntegerLength(binaryValue);


    int bValuesArray[bValueLength];

    extractDigitsFromInt(binaryValue, bValueLength, bValuesArray);


    for (int i = 0; i < bValueLength; i++) {

        if (bValuesArray[i] != 0 && bValuesArray[i] != 1)
            return -1;

        printf("%d * 2^%d = %f => %d\n", bValuesArray[i], bValueLength - 1 - i,
               pow(2, bValueLength - 1 - i),
               (int) ((double) bValuesArray[i] *
                      pow(2, bValueLength - 1 - i)));
        decimalValue += (int) ((double) bValuesArray[i] *
                               pow(2, bValueLength - 1 - i));
    }

    return decimalValue;


}

int
getIntegerLength(int value) {
    int valueLength = 0;
    bool lengthBiggerThanValue;


    do {
        valueLength++;
        lengthBiggerThanValue = pow(10, valueLength) > (double) value;
    } while (!lengthBiggerThanValue);

    return valueLength;

}

void
extractDigitsFromInt(int value, int length, int *valuesArray) {

    for (int i = length - 1; i >= 0; i--) {
        valuesArray[i] = value % 10;
        value /= 10;
    }


}
