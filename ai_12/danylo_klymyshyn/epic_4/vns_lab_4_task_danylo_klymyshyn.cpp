#include <iostream>


void print_stack(int *array, int &top){

    if(top >= 0){
        for(int i = 0; i <= top; ++i){
            std::cout << array[i] << ' ';

        }
        std::cout << '\n';
    }
    else
        std::cout << "Stack is empty." << std::endl;
}


void push(int *array, int value, int &top){

    if(top < 14){
        array[++top] = value;
        std::cout << "Element " << value << " added succesfully.";
        std::cout << '\n';
        print_stack(array, top);
    }
    else{
        std::cout << "No more space left. ";
    }

}


void pop(int *array, int &top){

if(top >= 0){
    std::cout << "Element " << array[top--] << " was deleted.";
    std::cout << '\n';
    print_stack(array, top);
    
}
else{
    std::cout << "Stack is empty";
}
}






int main(){

int array[15];

int top = -1;
push(array, 10, top);
push(array, 20, top);
push(array, 40, top);
push(array, 100, top);
pop(array, top);
pop(array, top);
pop(array, top);



    return 0;
}