#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], find[100], replace[100];
    char result[2000] = "";
    char *pos;
    int findLen, replaceLen;

    // Input text
    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    // Input word to find and replace
    printf("Enter the word to find: ");
    scanf("%s", find);

    printf("Enter the word to replace with: ");
    scanf("%s", replace);

    findLen = strlen(find);
    replaceLen = strlen(replace);

    // Find and replace logic
    while ((pos = strstr(text, find)) != NULL) {
        strncat(result, text, pos - text);  // Copy part before found word
        strcat(result, replace);            // Add replacement word
        text[0] = '\0';                     // Clear text
        strcpy(text, pos + findLen);        // Copy remaining text into text
    }

    // Add remaining part
    strcat(result, text);

    printf("\nUpdated Text:\n%s\n", result);

    return 0;
}
