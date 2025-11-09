#include <stdio.h>
#include <string.h>

int main() {
    char text[1000], find[100], replace[100];
    char result[2000] = "";
    char *pos;
    int findLen, replaceLen;


    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;

    printf("Enter the word to find: ");
    scanf("%s", find);

    printf("Enter the word to replace with: ");
    scanf("%s", replace);

    findLen = strlen(find);
    replaceLen = strlen(replace);

    
    while ((pos = strstr(text, find)) != NULL) {
        strncat(result, text, pos - text);  
        strcat(result, replace);           
        text[0] = '\0';                     
        strcpy(text, pos + findLen);       
    }

    strcat(result, text);

    printf("\nUpdated Text:\n%s\n", result);

    return 0;
}
