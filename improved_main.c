#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_DIGITS 9
#define MAX_CATEGORY_NAME_LENGTH 15

// Enum to represent categories
typedef enum {
    MILLION,
    THOUSAND,
    HUNDRED
} Category;

// Function prototypes
int getNumberDigits(int num);
void reverseDigits(int ar[], int size);
void printCategory(int digits[], Category category);
void printNumber(int num);

// Arrays of category names
const char* categoryNames[] = {
    "ekatommyria", "xiliades", "ekato"
};

const char* digitNames[][11] = {
    {"", "ena", "dio", "tria", "tesera", "pente", "eksi", "epta", "okto", "ennia", ""},
    {"", "deka", "enteka", "dodeka", "dekatria", "dekatessera", "dekapente", "dekaeksi", "dekaepta", "dekaokto", "dekaennia"},
    {"", "eikosi", "trianta", "saranta", "peninta", "eksinta", "ebdominta", "ogdonta", "eneninta", ""}
};

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative numbers
    if (num < 0) {
        printf("meion\n");
        num = -num;
    }

    // Print the number in words
    printNumber(num);

    return 0;
}

// Get the number of digits in a number
int getNumberDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// Reverse the order of digits in an array
void reverseDigits(int ar[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = ar[i];
        ar[i] = ar[size - i - 1];
        ar[size - i - 1] = temp;
    }
}

// Print a given category of digits
void printCategory(int digits[], Category category) {
    int size = getNumberDigits(digits[0]);
    reverseDigits(digits, size);

    // Print million, thousand, hundred
    if (digits[0] != 0) {
        printf("%s ", categoryNames[category]);
        for (int i = 0; i < size; i++) {
            printf("%s ", digitNames[category][digits[i]]);
        }
        printf("\n");
    }
}

// Print the number in words
void printNumber(int num) {
    int digits[MAX_DIGITS] = {0};
    int size = getNumberDigits(num);
    for (int i = 0; i < size; i++) {
        digits[i] = num % 10;
        num /= 10;
    }

    // Print million, thousand, hundred
    printCategory(&digits[6], MILLION);
    printCategory(&digits[3], THOUSAND);
    printCategory(&digits[0], HUNDRED);
}
