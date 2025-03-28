#include "football.h"
#include <stdio.h>

// Prints all possible score combinations
void printCombinations(int score) {
    if (score < 2) {
        printf("Invalid score. Must be 2 or higher.\n");
        return;
    }

    printf("Possible combinations of scoring plays for %d points:\n", score);
    for (int td = 0; td <= score / 6; td++) {
        for (int fg = 0; fg <= score / 3; fg++) {
            for (int safety = 0; safety <= score / 2; safety++) {
                int total = td * 6 + fg * 3 + safety * 2;
                if (total == score) {
                    printf("%d TDs, %d FGs, %d Safeties\n", td, fg, safety);
                }
            }
        }
    }
}

int main() {
    int score;
    printf("Enter the NFL score (2 or higher): ");
    scanf("%d", &score);
    printCombinations(score);
    return 0;
}
