#include "temperature.h"
#include <stdio.h>
#include <string.h>

// Converts to celsius
float toCelsius(float temp, char scale) {
    if (scale == 'F') return (temp - 32) * 5 / 9;
    if (scale == 'K') return temp - 273.15;
    return temp;
}

// Gets Category
void getCategory(float celsius) {
    printf("That feels ");
    if (celsius < 0) {
        printf("Freezing. Wear a thick jacket.\n");
    }
    else if (celsius < 10) {
        printf("Cold. Wear a jacket.\n");
    }
    else if (celsius < 25) {
        printf("Comfortable. Have a nice day.\n");
    }
    else if (celsius < 35) {
        printf("Hot. Stay hydrated.\n");
    }
    else {
        printf("Extreme Heat. Stay indoors.\n");
    }
}

// Converts non celsius
float convert(float temp, char from, char to) {
    float c = toCelsius(temp, from);
    if (to == 'C') return c;
    if (to == 'F') return c * 9 / 5 + 32;
    if (to == 'K') return c + 273.15;
    return temp;
}

int main() {
    float temp;
    char from, to;

    printf("Enter temperature value: ");
    scanf("%f", &temp);
    printf("Enter original scale (C, F, K): ");
    scanf(" %c", &from);
    printf("Convert to scale (C, F, K): ");
    scanf(" %c", &to);

    if ((from != 'C' && from != 'F' && from != 'K') ||
        (to != 'C' && to != 'F' && to != 'K')) {
        printf("Invalid scale. Use C, F, or K.\n");
        return 1;
    }

    float result = convert(temp, from, to);
    printf("Converted temperature: %.2f %c\n", result, to);
    getCategory(toCelsius(result, to));

    return 0;
}