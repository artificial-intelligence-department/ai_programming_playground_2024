#include<iostream>
#include<algorithm>
const double taskN = 40; // Варіант

double function_1()
{
    double a,b;
    float c, d, e;
    double f;
    std::cin >> a >> b;
    std::cin >> c >> d >> e;
    std::cin >> f;
    double nums[] = {a , b , c , d ,e , f};
    int n = sizeof(nums) / sizeof(nums[0]); 
    std::sort(nums, nums + n);

    double greaterNumsSum = 0 , lessNumsSum = 0;
    lessNumsSum = greaterNumsSum + nums[0] + nums[1] + nums[2];
    greaterNumsSum = lessNumsSum + nums[3] + nums[4] + nums[5];
    double result;
    if(greaterNumsSum > (lessNumsSum * 4))
    {
        result = lessNumsSum = greaterNumsSum;
    } else if (greaterNumsSum > (lessNumsSum * 3))
    {
        result = greaterNumsSum / lessNumsSum;
    } else if(greaterNumsSum > (lessNumsSum * 2))
    {
        result = greaterNumsSum * lessNumsSum;
    }

    result /= taskN;
    std::cout << "Result: " << result; 
    return result;

    
}


void printMatrixConsole(double** matrix)
{
    std::cout << std::endl;
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
}


double** function_2(double& val)
{
    //Memmory allocation (Dynamic)
    double** matrix = new double*[5];
    for (int i = 0; i < 5; i++)
    {
        matrix[i] = new double[5];
    }

    
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = val;
        }
    }

    //Separate code block ;)
    srand(time(nullptr));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = (matrix[i][j] + taskN + j + i ) * (rand() % 101 + 1); // Not including 101 precisely
        }
    }

    printMatrixConsole(matrix);

    return matrix;
}


//Find min (each row // HERE // )
double minEl(double* array)
{

}




void function_3(double** tower)
{
    double* oneDimenArray = new double[5];
    double resultMinEl1[5] , resultMinEl2[5];
    for (int i = 0; i < 5; i++)
    {
        double minElementRow = tower[0][i];
        for (int j = 1; j < 5; j++)
        {
            if (tower[j][i] < minElementRow)
                minElementRow = tower[j][i];
        }
        resultMinEl1[i] = minElementRow;
    }


    for (int i = 0; i < 5; i++)
    {
        double columnArray[5];
        for (int j = 0; j < 5; j++)
        {
            columnArray[j] = tower[j][i];
        }
        
    }
    

    delete oneDimenArray;
    
}




int main(void)
{
    //Test for function_1
    double resXF1 = function_1();

    //Test for function_2
    double** tower = function_2(resXF1);
    

    for (size_t i = 0; i < 5; i++)
    {
        delete[] tower[i];
    }
    delete tower;
     
    return 0;
}