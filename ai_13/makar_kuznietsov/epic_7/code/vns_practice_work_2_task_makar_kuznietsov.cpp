// variant 20
#include <algorithm>
#include <iostream>
#include <vector>
void mostPoints(std::vector<int> &quads, std::vector<int> &x_coords, std::vector<int> &y_coords);
int main()
{
    std::vector<int> x_coords = {-39, 4, 57, 61, -49, 54, -89, 30, 58, -50};
    std::vector<int> y_coords = {-67, 99, -45, -30, 53, 41, -88, 60, 28, 14};
    std::vector<int> quads = {0, 0, 0, 0};
    mostPoints(quads, x_coords, y_coords);
    auto it = std::find(quads.begin(), quads.end(), *std::max_element(quads.begin(), quads.end()));
    std::cout << "most point are in " << it - quads.begin() + 1 << " quad";
}

void mostPoints(std::vector<int> &quads, std::vector<int> &x_coords, std::vector<int> &y_coords)
{
    for (int i = 0; i < 10; i++)
    {
        if (x_coords[i] > 0)
        {
            if (y_coords[i] > 0)
            {
                quads[0]++;
            }
            else
            {
                quads[3]++;
            }
        }
        else
        {
            if (y_coords[i] > 0)
            {
                quads[1]++;
            }
            else
            {
                quads[2]++;
            }
        }
    }
}
