#include<iostream>
#include <math.h>
#include <array>
#include <vector>

#define lineLength(x1, Y1, x2, y2) sqrt((x2-x1)*(x2-x1) + (y2 - Y1)*(y2 - Y1)) 

double square(std::array<int, 2> p1, std::array<int, 2> p2,  std::array<int, 2> p3){
    double l1 = lineLength(p1[0], p1[1], p2[0], p2[1]);
    double l2 = lineLength(p1[0], p1[1], p3[0], p3[1]);
    double l3 = lineLength(p2[0], p2[1], p3[0], p3[1]);
    double p = (l1 + l2 + l3) / 2;
    return sqrt(p * (p - l1) * (p - l2) * (p - l3));
}

double square1(std::vector<std::array<int, 2>> list){
    if(list.size() < 3) return 0;
    std::array<int, 2> p1, p2, p3;
    double maxLen = 0;
    for(int i = 0; i < list.size() - 1; i++){
        for(int j = i + 1; j < list.size(); j++){
            double l = lineLength(int(list[i][0]), int(list[i][1]), int(list[j][0]), int(list[j][1]));
            if(l > maxLen){
                maxLen = l;
                p1 = {list[i][0], list[i][1]};
                p2 = {list[j][0], list[j][1]};
            }
            else p3 = {list[j][0], list[j][1]};
        }
    }
    return square(p1, p2, p3);
}

int main(){
    std::vector<std::array<int, 2>> points =  {
        {0, 0}, {1, 3}, {2, 2}, {4, 4}, {1, 5}, {5, 0}, {3, 1}, {2, 6}, {6, 3}, {4, 5}
    };
    std::cout << "Area of triangel : " << square1(points) << std::endl;
    while(true){
        points.clear();
        std::cout << "Two exit loop enter 2 same points in row\n";
        while(true){
            std::array<int, 2> arr;
            std::cin >> arr[0] >> arr[1];
            if(points.size() != 0) if(points[points.size() - 1] == arr) break;
            points.push_back(arr);
        }
        std::cout << "Area of triangel : " << square1(points) << std::endl;
    }
    return 0;
}