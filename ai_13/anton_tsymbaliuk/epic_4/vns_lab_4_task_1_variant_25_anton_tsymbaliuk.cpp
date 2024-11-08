#include <iostream>

class ringArray{
    int* arr;
    int* ptr;
    int size;

    public:
    
    ringArray(int size){
        this->size = size;
        arr = new int[size];
        std::cout << "Enter elements: ";
        for(int i = 0; i < size; i++) std::cin >> arr[i]; 
        ptr = &arr[size - 1];
    }

    void sort(){
        for(int i = 1; i < size; i++){
            if(arr[i - 1] > arr[i]){
                std::swap(arr[i-1], arr[i]);
                for(int j = i - 1; j  > 0; j--){
                    if(arr[j - 1] > arr[j]) std::swap(arr[j-1], arr[j]);
                    else break;
                }
            }
        }
    }

    void showArr(int start = -1){
        if(start >= size || start < 0) start = size - 1;
        int i = start + 1;
        do{
            std::cout << ptr[-size+i] << " ";
            i--;
            if(i <= 0) i = size;
        }while(i != start + 1);
        std::cout << std::endl;
    }

    void deleteOddElements(){
        int* newArr;
        int counter = 0;
        for(int i = 0; i < size;i++) if(arr[i] % 2 == 0) counter++;
        newArr = new int[counter];
        int j = 0;
        for(int i = 0; i < size; i++) if(arr[i] % 2 == 0) newArr[j++] = arr[i];
        delete[] arr;
        size = counter;
        arr = newArr;
        ptr = &arr[size - 1];
    }

    ~ringArray(){
        delete[] arr;
    }
};

int main(){
    int size = 10;
    ringArray arr(size);
    arr.showArr(size / 2);
    arr.sort();
    arr.showArr(size);      //вивід за умовою з ліва на право, тому виводиться масив ніби від більшого до меншого
    arr.deleteOddElements();
    arr.showArr();
    return 0;
}