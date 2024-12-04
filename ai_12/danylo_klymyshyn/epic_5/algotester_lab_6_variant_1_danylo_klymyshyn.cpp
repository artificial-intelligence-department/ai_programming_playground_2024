#include <iostream>
#include <vector>


enum figures{
    O,
    P,
    R,
    N,
    B,
    K,
    Q
};

void fillArray(figures array[8][8]){
    char temp;
    for(int i = 0; i < 8; ++i)
    for(int j = 0; j < 8; ++j){
        std::cin >> temp;
        switch(temp){
            case 'O': array[i][j] = figures::O; break;
            case 'P': array[i][j] = figures::P; break;
            case 'R': array[i][j] = figures::R; break;
            case 'N': array[i][j] = figures::N; break;
            case 'B': array[i][j] = figures::B; break;
            case 'K': array[i][j] = figures::K; break;
            case 'Q': array[i][j] = figures::Q; break;
            }
    }
}


bool pishak(figures array[8][8], int x, int y) {

    if (x - 1 >= 0 && y - 1 >= 0 && array[x - 1][y - 1] == figures::P){
        return true;
    }
    if (x - 1 >= 0 && y + 1 < 8 && array[x - 1][y + 1] == figures::P){
        return true;
        }
    return false;
}




bool tura(figures array[8][8], int x, int y){
    for(int j = 0; j < 8; ++j){
        if(array[x][j] == figures::R){
            return true;
        
        }
    }
    for(int i = 0 ; i < 8; ++i){
        if(array[i][y] == figures::R)
            return true;
    }
return false;
}

bool horse(figures array[8][8], int x, int y) {
    if (x + 2 < 8 && y + 1 < 8 && array[x+2][y+1] == figures::N)
        return true;
    if (x + 2 < 8 && y - 1 >= 0 && array[x+2][y-1] == figures::N)
        return true;
    if (x - 2 >= 0 && y + 1 < 8 && array[x-2][y+1] == figures::N)
        return true;
    if (x - 2 >= 0 && y - 1 >= 0 && array[x-2][y-1] == figures::N)
        return true;
    if (x - 1 >= 0 && y + 2 < 8 && array[x-1][y+2] == figures::N)
        return true;
    if (x - 1 >= 0 && y - 2 >= 0 && array[x-1][y-2] == figures::N)
        return true;
    if (x + 1 < 8 && y + 2 < 8 && array[x+1][y+2] == figures::N)
        return true;
    if (x + 1 < 8 && y - 2 >= 0 && array[x+1][y-2] == figures::N)
        return true;
    return false;
}

bool elephant(figures array[8][8], int x, int y) {
    for (int n = 1; n < 8; ++n) {
        if (x - n >= 0 && y - n >= 0 && array[x-n][y-n] == figures::B)
            return true;
        if (x - n >= 0 && y + n < 8 && array[x-n][y+n] == figures::B)
            return true;
        if (x + n < 8 && y - n >= 0 && array[x+n][y-n] == figures::B)
            return true;
        if (x + n < 8 && y + n < 8 && array[x+n][y+n] == figures::B)
            return true;
    }
    return false;
}

bool king(figures array[8][8], int x, int y) {
    if (x + 1 < 8 && y - 1 >= 0 && array[x+1][y-1] == figures::K) {
        return true;
    }
    if (x + 1 < 8 && y < 8 && array[x+1][y] == figures::K) {
        return true;
    }
    if (x + 1 < 8 && y + 1 < 8 && array[x+1][y+1] == figures::K) {
        return true;
    }
    if (x - 1 >= 0 && y + 1 < 8 && array[x-1][y+1] == figures::K) {
        return true;
    }
    if (x - 1 >= 0 && y < 8 && array[x-1][y] == figures::K) {
        return true;
    }
    if (x - 1 >= 0 && y - 1 >= 0 && array[x-1][y-1] == figures::K) {
        return true;
    }
    if (x < 8 && y + 1 < 8 && array[x][y+1] == figures::K) {
        return true;
    }
    if (x >= 0 && y - 1 >= 0 && array[x][y-1] == figures::K) {
        return true;
    }
    return false;
}





bool queen(figures array[8][8], int x, int y){
    for (int n = 1; n < 8; ++n) {
        if (x - n >= 0 && y - n >= 0 && array[x-n][y-n] == figures::Q)
            return true;
        if (x - n >= 0 && y + n < 8 && array[x-n][y+n] == figures::Q)
            return true;
        if (x + n < 8 && y - n >= 0 && array[x+n][y-n] == figures::Q)
            return true;
        if (x + n < 8 && y + n < 8 && array[x+n][y+n] == figures::Q)
            return true;
    }
    for(int j = 0; j < 8; ++j){
        if(array[x][j] == figures::Q){
            return true;
        
        }
    }
    for(int i = 0 ; i < 8; ++i){
        if(array[i][y] == figures::Q)
            return true;
    }
    return false;
}


void func(figures array[8][8]){
    int Q, x, y;
    bool check;
    std::cin >> Q;
    std::vector<std::pair<int, int>> coord(Q);
    std::vector<char> results;
    for(int i = 0; i < Q; ++i){
        check = true;
    std::cout << '\n';
        std::cin >> coord[i].first;
        std::cin >> coord[i].second;

        coord[i].first -=1;
        coord[i].second -=1;
                
            if(array[coord[i].first][coord[i].second] != figures::O){
                results.push_back('X');
                check = false;
            } 
            else{ 
                
            if(elephant(array, coord[i].first, coord[i].second)){
                results.push_back('B');
                check = false;
            }
            
            if(king(array, coord[i].first, coord[i].second)){
                results.push_back('K');
                check = false;
            }

            if(horse(array, coord[i].first, coord[i].second)){
                results.push_back('N');
                check = false;
            }       

            if(pishak(array, coord[i].first, coord[i].second)){
            results.push_back('P');
            check = false;
            }

            if(queen(array, coord[i].first, coord[i].second)){
                results.push_back('Q');
                check = false;
            }

            if(tura(array, coord[i].first, coord[i].second)){
                results.push_back('R');
                check = false;
            }
            if(check)
                results.push_back('O');
        }    
    for(auto &el : results){
            std::cout << el;
    }
    results.clear();
    }

}

int main(){

figures array[8][8];
fillArray(array);

func(array);

    return 0;
}