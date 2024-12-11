#include <iostream>

int main(){
//Ініціалізація матриці: Заповнення статичного двовимірного масиву.
    int big_array[5][5] = {
        {1,    2,   3,   4,   5}, 
        {20,   44,  12,  3,   4}, 
        {99,   5,   0,  -12,  3}, 
        {-20,  33,  32,  55,  1}, 
        {-10, -3,  -22,  103, 2}
    };
    int max_in_rows[5], max_in_col[5], min_in_rows[5], min_in_col[5];
    
//знайти найбільший елемент стовбців і записати в масив з 5 елементів + вивести результат
    std::cout << "Максимальні елементи стовбців : ";
    for(int col=0; col<5; col++){
        int max_el = big_array[0][col];
        for(int i=1; i<5; i++){
            if(max_el < big_array[i][col]){
                max_el = big_array[i][col];
            }
        }
        max_in_col[col] = max_el;
    }
    for(int i=0; i<5; i++){
        std::cout << max_in_col[i] << " ";
    }

    std::cout << "\n";

//знайти найменший елемент стовбців і записати в масив з 5 елементів + вивести результат
    std::cout << "Мінімальні елементи стовбців : ";
    for(int col=0; col<5; col++){
        int min_el = big_array[0][col];
        for(int i=1; i<5; i++){
            if(min_el > big_array[i][col]){
                min_el = big_array[i][col];
            }
        }
        min_in_col[col] = min_el;
    }
    for(int i=0; i<5; i++){
        std::cout << min_in_col[i] << " ";
    }

    std::cout << "\n";

//знайти найбільший елемент стрічок і записати в масив з 5 елементів + вивести результат
    std::cout << "Максимальні елементи стрічок : ";
    for(int row=0; row<5; row++){
        int max_el = big_array[row][0];
        for(int i=1; i<5; i++){
            if(max_el < big_array[row][i]){
                max_el = big_array[row][i];
            }
        }
        max_in_rows[row] = max_el;
    }
    for(int i=0; i<5; i++){
        std::cout << max_in_rows[i] << " ";
    }

    std::cout << "\n";

//знайти найменший елемент стрічок і записати в масив з 5 елементів + вивести результат
    std::cout << "Мінімальні елементи стрічок : ";
    for(int row=0; row<5; row++){
        int min_el = big_array[row][0];
        for(int i=1; i<5; i++){
            if(min_el > big_array[row][i]){
                min_el = big_array[row][i];
            }
        }
        min_in_rows[row] = min_el;
    }
    for(int i=0; i<5; i++){
        std::cout << min_in_rows[i] << " ";
    }

    std::cout << "\n\n";

//вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
    bool up=1;
    int col = 4;

    std::cout << "Вивід матриці з нижнього правого кута вверх і вниз по стовпцях : \n";
    while(col>-1){
        if(up){
            for(int i=4; i>-1; i--){
                std::cout << big_array[i][col] << " ";
            }
            std::cout << "\n";
            col--;
            up=0;
        } else {
            for(int i=0; i<5; i++){
                std::cout << big_array[i][col] << " ";
            }
            std::cout << "\n";
            col--;
            up=1;
        }
    }
    std::cout << "\n\n";

//обернути значення матриці відносно якоїсь діагоналі (так щоб цифри помінялись місцями)
    bool diag = 1;
    if(diag){
        for(int i=0; i<5; i++){
            for(int j=i; j<5; j++){
                int k = big_array[i][j];
                big_array[i][j] = big_array[j][i];
                big_array[j][i] = k;
            }
        }
    } else {
        for(int i=0; i<5; i++){
            for(int j=0; j<5-i; j++){
                int k = big_array[i][j];
                big_array[i][j] = big_array[4-j][4-i];
                big_array[4-j][4-i] = k;
            }
        }
    }

    if(diag){
        std::cout << "Обернена матриця відносно головної діагоналі : \n";  
    } else {
        std::cout << "Обернена матриця відносно антидіагоналі : \n";  
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            std::cout << big_array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

//зробити поворот матриці на 90 градусів
    for(int i=0; i < 3; i++){
        for(int j=i; j<=4-i-1; j++){
            int k = big_array[i][j];
            big_array[i][j]=big_array[j][4-i];
            big_array[j][4-i]=big_array[4-i][4-j];
            big_array[4-i][4-j]=big_array[4-j][i];
            big_array[4-j][i] = k;
        }
    }

    std::cout << "Матриця, обернена на 90 градусів : \n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            std::cout << big_array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

//перевірити чи матриця симетрична
    bool is_sym = 1;
    for(int i=0; i<3; i++){
        for(int j=i; j<3; j++){
            if(big_array[i][j]!=big_array[j][i]){
                is_sym = 0;
                break;
            }
        }
    }

    std::cout << "Чи є матриця симетричною? : " 
    << ( is_sym ? "Так" : "Ні") 
    << "\n\n";

//далі взяти матрицю 5*6 і спробувати її транспонувати та вивести результати до і після
    int before[5][6] = {
        {1,   3,   12, 5,  33,  6},
        {22,  3,  -6,  76, 78,  9},
        {19, -44, -8,  0,  1,   32},
        {0,   1,   23, 92, 49,  3},
        {-4, -10,  30, 22, 73,  4}
    };
    int after[6][5];

    std::cout << "Матриця перед транспонуванням : \n";
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            std::cout << before[i][j] << " ";
        }
        std::cout << "\n";
    }

    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            after[j][i]=before[i][j];
        }
    }

    std::cout << "\nМатриця після транспонування : \n";
    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            std::cout << after[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";


//Додавання двох матриць: Елемент за елементом додаються елементи двох матриць.
    int array[5][5] = {
        {1,    2,   3,   4,   5}, 
        {20,   44,  12,  3,   4}, 
        {99,   5,   0,  -12,  3}, 
        {-20,  33,  32,  55,  1}, 
        {-10, -3,  -22,  103, 2}
    };
    int array_for_adding[5][5] = {
        {5,    4,   3,   2,   1}, 
        {-9,  -77,  34,  12,  4}, 
        {1,    0,   77, -65,  8}, 
        {90,   5,   76, -44,  6}, 
        {8,   -90,  66,  12,  7}
    };
    int add_arrays[5][5], mult_arrays[5][5] = {{0}}, det_of_array=0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            add_arrays[i][j]=array[i][j]+array_for_adding[i][j];
        }
    }

    std::cout << "\nСума двох матриць : \n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            std::cout << add_arrays[i][j] << " ";
        }
        std::cout << "\n";
    }

//Множення двох матриць: Класичний алгоритм множення матриць.
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                mult_arrays[i][j]+=array[i][k]*array_for_adding[k][j];
            }
        }
    }

    std::cout << "\nДобуток двох матриць : \n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            std::cout << mult_arrays[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";


//Обчислення детермінанта (для квадратних матриць).
    int det_array[3][3] = {
        {2, 4, 0},
        {3, 0, 1},
        {1, 1, 1}
    };
    int det=0, Minor[2][2];;
    for(int col=0; col<3; col++){
        for(int i=1; i<3; i++){
            int sub=0;
            for(int j=0; j<3; j++){
                if(j!=col){
                    Minor[i-1][sub++]=det_array[i][j];
                }
            }
            
        }
        det+=((col % 2 == 0) ? 1 : -1)*det_array[0][col]*(Minor[0][0]*Minor[1][1]-Minor[1][0]*Minor[0][1]);
    }

    std::cout << "Визначник такої матриці : \n";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cout << det_array[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "pівний " << det << "\n\n";


    //Пошук числа, що повторюється найбільше
    int count=0, number=det_array[0][0];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int that = det_array[i][j];
            int sum=0;
            for(int row=0; row<3; row++){
                for(int coll=0; coll<3; coll++){
                    if(det_array[row][coll]==that){
                        sum++;
                    }
                }
            }
            if(sum>count){
                count = sum;
                number = that;
            }
        }
    }
    std::cout << "Найбільше повторюється число " << number << "\n\n";




    return 0;
}