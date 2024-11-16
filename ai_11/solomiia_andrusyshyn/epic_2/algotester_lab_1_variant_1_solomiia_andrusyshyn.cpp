#include <cstdio> 

int main() {
    long long H, M;
    scanf("%lld %lld", &H, &M); 

    int isLose = 0; 

    for (int i = 0; i < 3; i++) {
        long long h_i, m_i;
        scanf("%lld %lld", &h_i, &m_i); 

        if (h_i > 0 && m_i > 0) {
            isLose = 1; 
            break;      
        }

        if (h_i > 0) {
            H -= h_i;
        }
        
        if (m_i > 0) {
            M -= m_i; 
        }
    }

    if (isLose || H <= 0 || M <= 0) {
        printf("NO\n"); 
    } else {
        printf("YES\n"); 
    }

    return 0;
}
