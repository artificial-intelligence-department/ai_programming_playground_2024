#include <iostream>
using namespace std;
int main(){
   int packs, cookies;
   
   long long set = 0;
   cin >> packs;
   for (long long i = 0; i < packs; i++)
   {
    cin >> cookies;
    cookies = cookies - 1;
    set += cookies;
   }
   cout << set;
   return 0;
}
