#include <iostream>
using namespace std;

int main() {
    long long H, M; // long long бо межі 1e12 
    cin >> H >> M;
    
    if (H < 1 || H > 1e12 || M < 1 || M > 1e12) // перевірка умови
        return 1;
    // заповнення значень
    for (int i = 0; i < 3; i++) {
        long long hi, mi;
        cin >> hi >> mi;
    // перевірка умови чи не виходидь за межі необхідна кількість ресурсів на заклинання
        if (hi < 0 || hi > 1e12 || mi < 0 || mi > 1e12) 
            return 1;
    // якщо витрачається одразу два показника то програш
        if (hi > 0 && mi > 0) {  
            cout << "NO" << endl;
            return 0;
        }
        // віднімання ресурсів після заклинання
        if (hi > 0) {
            H -= hi; 
        } else if (mi > 0) {
            M -= mi;
        }
    // перевірка на кількість ресурсів
        if (H <= 0 || M <= 0) {  
            cout << "NO" << endl;
            return 0;
        }
    }

   
    cout << "YES" << endl;
    return 0;
}
