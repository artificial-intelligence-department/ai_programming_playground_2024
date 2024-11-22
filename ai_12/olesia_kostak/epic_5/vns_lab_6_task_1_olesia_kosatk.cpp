#include <stdio.h>
#include <string.h>
#include <iostream> 
#include <cctype>

int main()
{
    char myStr[256];
    fgets(myStr, 256, stdin);
    myStr[strcspn(myStr, "\n")] = '\0';
    char nums_str[256] = "";
    char res[256] = "";

    char * token = strtok(myStr, " ");

    while(token != NULL) 
    {
        bool flag = true;

        for(int i = 0; token[i] != '\0'; i++)
            if(isdigit(token[i]))
                flag = false;
        
        if(!flag)
            {
                strcat(nums_str, token);
                strcat(nums_str, " ");
            }
        else
            {
                strcat(res, token);
                strcat(res, " ");
            }
                
        token = strtok(NULL, " ");
    }

    strcat(res, nums_str);
    std::cout << res;

    return 0;
}
