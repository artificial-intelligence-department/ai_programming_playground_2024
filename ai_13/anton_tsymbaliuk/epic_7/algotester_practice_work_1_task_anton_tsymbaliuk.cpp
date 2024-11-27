#include <iostream>
#include <unordered_map>
#include <unordered_set>

int n, m;

void checkForLesser(std::unordered_map<int, std::unordered_set<int>>& vertices,  std::unordered_set<int>& vis, int& ver){
    std::unordered_set<int> verticesL = vis;
    std::unordered_map<int, std::unordered_set<int>> checked;
    jumpy:
    for(const int& i : verticesL){                      //BFS
        if( i < ver){
            std::unordered_set<int> visited = {i};
            std::unordered_set<int> neighbors = vertices[i];
            do{
                std::unordered_set<int> newNeighbors;
                for(const int& val : neighbors){
                    if(!visited.count(val)) visited.insert(val);
                    if(checked.count(val)) for(const int& temp : checked[val]) visited.insert(temp);
                    else for(const int& temp : vertices[val]) if(!visited.count(temp) && !newNeighbors.count(temp) && !neighbors.count(temp)) newNeighbors.insert(temp);
                }
                neighbors = newNeighbors;
            } while(neighbors.size() != 0);
            checked[i] = visited;
            if(visited.size() == n) ver = ver > i ? i : ver;
            else {
                for(const int& val : visited) verticesL.erase(val);
                goto jumpy;                  //Алготестер не хоче щоб я змінював сет по якому проходить ітерація в середені самого цикла
            }
            
        }
        else{
            verticesL.erase(i);
            goto jumpy;
        }
        
    }
}

int findStronglyConnected(std::unordered_map<int, std::unordered_set<int>>& vertices){
    int ver = n + 1;
    std::unordered_set<int> verticesL;
    std::unordered_map<int, std::unordered_set<int>> checked;
    for(int i = 1; i<= n; i++) verticesL.insert(i);
    jump:
    for(const int& i : verticesL){                      //BFS
        
        std::unordered_set<int> visited = {i};
        std::unordered_set<int> neighbors = vertices[i];
        do{
            std::unordered_set<int> newNeighbors;
            for(const int& val : neighbors){
                if(!visited.count(val)) visited.insert(val);
                if(checked.count(val)) for(const int& temp : checked[val]) visited.insert(temp);
                else for(const int& temp : vertices[val]) if(!visited.count(temp) && !newNeighbors.count(temp) && !neighbors.count(temp)) newNeighbors.insert(temp);
            }
            neighbors = newNeighbors;
        } while(neighbors.size() != 0);
        checked[i] = visited;
        if(visited.size() == n) { 
            ver = ver > i ? i : ver;
           
        }

        for(const int& val : visited) verticesL.erase(val);
        goto jump;                  //Алготестер не хоче щоб я змінював сет по якому проходить ітерація в середені самого цикла
    }
    return (ver == n + 1 ? -1 : ver);
}

int main(){
    std::cin >> n;
    std::cin >> m;
    std::unordered_map<int, std::unordered_set<int>> vertices;
    int ver1, ver2;
    for(int i = 0; i < m; i++){
        std::cin >> ver1 >> ver2;
        if(ver1 != ver2) vertices[ver1].insert(ver2);
    }
    std::cout << findStronglyConnected(vertices) << std::endl;
    return 0;
}
