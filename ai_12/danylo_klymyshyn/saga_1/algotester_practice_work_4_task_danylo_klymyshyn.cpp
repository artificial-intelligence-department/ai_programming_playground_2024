#include <iostream>
#include <vector>
#include <algorithm>

int calculate_damage(int damage, int interval, int time){
    return damage*(time/interval + 1);
}


int main() {
    int a1, b1, a2, b2, a3, b3, x;
    std::cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> x;

    int damage1 = calculate_damage(a1, b1, x);
    int damage2 = calculate_damage(a2, b2, x);
    int damage3 = calculate_damage(a3, b3, x);

    std::vector<std::pair<int, int>> damages = {{damage1, 1}, {damage2, 2}, {damage3, 3}};
    auto best_gun = max_element(damages.begin(), damages.end());

    std::cout << best_gun->second << std::endl;

    return 0;
}
