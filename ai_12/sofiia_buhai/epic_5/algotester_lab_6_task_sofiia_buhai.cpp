#include <iostream>
#include <vector>
#include <set>

typedef std::pair<int, int> intpair;

int main(){
    int N, Q, x, y;
    std::cin >> N;
    int a[N][N];
    std::string given[N];
    for(int i=0; i<N; i++){
        std::cin >> given[i];
        for(int j=0; j<N; j++){
            a[i][j]= given[i][j]-48;
        }
    }
    std::cin >> Q;
    std::vector<int> answer, coor_x, coor_y;
    for(int i=0; i<Q; i++){
        std::cin >> x >> y;
        coor_x.push_back(x-1);
        coor_y.push_back(y-1);
    }

    for(int i=0; i<Q; i++){
        answer.clear();
        for(int p=0; p<N; p++){
            answer.push_back(p+1);
        }
        if(a[coor_x[i]][coor_y[i]]!=0){
            std::cout << "\n" <<1;
            std::cout << "\n" <<a[coor_x[i]][coor_y[i]];
        } else {
            for(int j=0; j<N; j++){
                if(a[coor_x[i]][j]!=0){
                    for(int k=0; k<answer.size(); k++){
                        if(answer[k]==a[coor_x[i]][j]){
                            answer.erase(answer.begin()+k);    
                        }
                    }
                }
            }
            for(int j=0; j<N; j++){
                if(a[j][coor_y[i]]!=0){
                    for(int k=0; k<answer.size(); k++){
                        if(answer[k]==a[j][coor_y[i]]){
                            answer.erase(answer.begin()+k);    
                        }
                    }
                }
            }
            std::cout << "\n" << answer.size() << "\n";
            for(int l : answer){
                std::cout << l << " ";
            }
        }
        
    }
    return 0;
}

