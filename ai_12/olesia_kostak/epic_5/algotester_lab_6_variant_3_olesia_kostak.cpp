#include <iostream>
#include <vector>
#include <string>

int main()
{
    int N;
    std::cin >> N;
    int arr[N][N];

    for(int i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        for(int j = 0; j < N; j++)
            arr[i][j] = str[j] - 48;
    }
    int Q;
    std::cin >> Q;
    std::vector<std::pair<int, int>> arrQ(Q);
    for(int i = 0; i < Q; i++)
    {
        int x, y;
        std::cin >> x >> y;
        x--; y--;
        arrQ[i].first = x;
        arrQ[i].second = y;
    }

    for(int m = 0; m < Q; m++)
    {
        std::vector<int> res(N);
        for(int k = 1; k <= N; k++)
            res[k - 1] = k;   

        int x = arrQ[m].first;
        int y = arrQ[m].second;
            
        if (arr[x][y] != 0)
        {
            std::cout << 1 << std::endl;
            std::cout << arr[x][y] << std::endl;
        }
        else
        {
            for(int j = 0; j < N; j++)
            {
                for(int k = 0; k < res.size(); k++)
                        if(res[k] == arr[x][j])
                            res.erase(res.begin() + k);    
            }
            
            for(int i = 0; i < N; i++)
            {
                for(int k = 0; k < res.size(); k++)
                        if(res[k] == arr[i][y])
                            res.erase(res.begin() + k);  
            }  
            std::cout << res.size() << std::endl;
            for(int i = 0; i < res.size(); i++)
                std::cout << res[i] << " "; 
            std::cout << std::endl << std::endl;
            
        }   
        

    }


    return 0;
}

