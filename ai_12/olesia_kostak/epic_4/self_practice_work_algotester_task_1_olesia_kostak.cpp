#include <iostream>
#include <string>

int main(){
    int N;
    std::cin >> N;
    int res = 0;
    std::cin.ignore();

    for(int i = 0; i < N; i++)
    {
        std::string str;
        std::getline (std::cin, str);
        int len = str.length();
        for(int j = 0; j < len; j++)
        {
            if(str[j] == '#')
                if(j == 0)
                    res++;
                else if(str[j] == '#' && str[j - 1] != '#')
                    res++;
        }
    }
    std::cout << res;

    return 0;
}