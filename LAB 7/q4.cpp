// String processing to remove '+' and the immediate left non-'+' symbol using Stack ADT

#include "stack.h"
#include <cstdio>
#include <cstring>

// function to process the input string
void processString(char*, char*);

int main() {
    char input[100], output[100];

    // ***** (Taking Input) *****
    printf("Enter a string with '+': ");
    scanf("%s", input);

    // ***** (Processing String) *****
    processString(input, output);

    // ***** (Displaying Output) *****
    printf("Processed string: %s\n", output);

    return 0;
}

// function to process the input string
void processString(char* input, char* output) {
    Stack s;
    int i, j = 0;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '+') {
            if (!s.isEmpty())
                s.pop(); // remove the immediate left non-'+' symbol
        }
        else
            s.push(input[i]); // push valid characters onto the stack
    }

    // store the remaining characters from the stack into output
    while (!s.isEmpty())
        output[j++] = s.pop();

    output[j] = '\0';

    // reverse the output to maintain original order
    int start = 0, end = j - 1;
    while (start < end) {
        char temp = output[start];
        output[start++] = output[end];
        output[end--] = temp;
    }
}
