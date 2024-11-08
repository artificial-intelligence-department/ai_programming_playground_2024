#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int main(){
    int N;
    std::fstream file("text.bat", std::fstream::binary | std::fstream::out);
    std::cin >> N;
    std::vector<std::vector<int>> sudoku(N);
    std::string str;
    for(int i = 0; i < N; i++){
        std::cin >> str;
        for(const char& ch : str) sudoku[i].push_back(ch - '0');
    }
    int Q;
    std::cin >> Q;
    std::vector<std::vector<int>> results(Q);
    for(int i = 0; i < Q; i++){
        int row, col;
        std::cin >> row >> col;
        row--;
        col--;
        std::vector<int> vec(N);
        if(sudoku[row][col] == 0){
            for(int j = 0; j < N; j++){
            if(j == col || sudoku[row][j] == 0) continue;
                vec[sudoku[row][j] - 1] = sudoku[row][j]; 
            }
            for(int j = 0; j < N; j++){
                if(j == row || sudoku[j][col] == 0) continue;
                vec[sudoku[j][col] - 1] = sudoku[j][col]; 
            }

            for(int j = 0; j < N; j++){
                if(vec[j] != j + 1) results[i].push_back(j + 1);
            }
            //if(results[i].size() == 0) results[i].push_back(0);             
        }
        else results[i].push_back(sudoku[row][col]);
        
    }

    for(std::vector<int>& v : results){
        std::cout << v.size() << std::endl;
        for(int& val : v) std:: cout << val << " ";
        std::cout << std::endl << std::endl;
    }
    return 0;
}