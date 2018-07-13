// C programming
//
// Remove trailing blanks and tabs from each line of input, and to delete
// entirely blank lines
//
//  Exercise_1-18
//
//  Created by Louie Shi on 6/30/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char s[], int lim);
void removeTrailingSpaces(char s[]);

// mgetline: read a line into s, return length
// getline code from the c textbook

int mgetline(char s[], int lim)
{
    int c, i;
    
    for(i=0; i < lim - 1 && (c = getchar())!=EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

void removeTrailingSpaces(char s[])
{
    char currChar; //Testing
    
    for(int i = (strlen(s) - 1); i >= 0; --i)
    {
        currChar = s[i];
        if(s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
        {
            s[i + 1] = '\0';
            break;
        }
    }
}

int main(int argc, const char * argv[])
{
    char line[MAXLINE];
    int length = mgetline(line, MAXLINE);
    
    while(length > 1)
    {
        printf("Before: The length of the line: %d \n", length);
        removeTrailingSpaces(line);
        printf("After: The length of the line: %d \n", strlen(line));
        length = mgetline(line, MAXLINE);
    }
    
    return 0;
}
