#include <iostream>
#include <bits/stdc++.h>
using namespace std;


float buublesort(float** &&tower, int n, int l){
    bool swapped; // для перевірки, чи закінчилась перестановка
  
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (tower[j][l] > tower[j+1][l]) {
                swap(tower[j+1][l], tower[l][j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return tower[0][l];
}

void sort(float** &&tower, int n, int l){
    for (int i = 0; i < n - 1; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (tower[j][l] < tower[smallestIndex][l])
				smallestIndex = j;
		}
		swap(tower[i][l], tower[smallestIndex][l]);
	}
}



float function_1(){
    int n=6;
    int a, b;
    float c, d, e, ans;
    double f, max[3], min[3], sum_max=0, sum_min=0;
    std::cin >> a >> b >> c >> d >> e >> f;
    double numbers[] = {(double)a, (double)b, c, d, e, f};
    for (int i = 0; i < n - 1; i++)
	{
		int smallestIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (numbers[j] < numbers[smallestIndex])
				smallestIndex = j;
		}
		swap(numbers[i], numbers[smallestIndex]);
	}
    while(n>3){
        sum_max+=numbers[n-1];
        n--;
    }
    do{
        sum_min+=numbers[n-1];
        n--;
    }while(n>0);

    if(sum_max > sum_min*2){
        ans = sum_max*sum_min;
    }
    if(sum_max > sum_min*3){
        if(sum_min!=0){
            ans = sum_max/sum_min;
        } else {
            ans = 0;
        }
    }
    if(sum_max > sum_min*4){
        ans = sum_max+sum_min;
    }

    const float x = ans/32;

    return x;
}

float** function_2(float &x){
    const int n=5;
    float** array = new float*[n];
    for(int i =0; i<n; i++){
        array[i] = new float[n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            array[i][j]=x;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            array[i][j] = (array[i][j]+32+(double)j-(double)i)*(double)(rand()% 100 + 1);
            std::cout << array[i][j];
        }
    }
    return array;
}


float function_3(float** tower){
    float arr[5];
    for(int l=0; l<5; l++){
        float min_bub = buublesort(tower, 5, l);
    }
}





int main(){
    float x = function_1();
    float** tower = function_2(x);
    return 0;
}