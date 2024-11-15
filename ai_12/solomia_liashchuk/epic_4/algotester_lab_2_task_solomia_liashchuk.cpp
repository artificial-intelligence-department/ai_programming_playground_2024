#include <iostream>

int main()
{
    int N;
    std::cin >> N;
    int arr[N];

    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    int left_pos = 0, right_pos = N - 1;
    
    for(int i = 0; i < N; i++)
    {
        if(left_pos == right_pos)
        {
            std::cout << left_pos + 1 << " " << right_pos + 1 << std::endl;
            std::cout << "Collision";
            break;
        }   
        if(left_pos > right_pos)
        {
            std::cout << left_pos + 1<< " " << right_pos + 1 << std::endl;
            std::cout << "Miss";
            break;
        }
        if((right_pos - left_pos) == 1)
        {
            std::cout << left_pos + 1 << " " << right_pos + 1 << std::endl;
            std::cout << "Stopped";
            break;
        }

        left_pos += arr[left_pos];
        right_pos -= arr[right_pos];
    }

    return 0;
}