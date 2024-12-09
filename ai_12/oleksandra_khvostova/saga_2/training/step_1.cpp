#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    int matrix[5][5] = {
        {1, 1, 4, 2, 3},
        {2, 4, 6, 1, 0},
        {2, 1, 8, 9, 1},
        {3, 7, 8, 6, 1},
        {7, 5, 3, 9, 1},
    };
    int columnsm[5], columnsM[5];
    int rowsm[5], rowsM[5];

    //1
    for (int i=0; i<5; i++){
        int max=0;
    for(int j=0; j<5; j++){
        if(max<matrix[j][i]){
            max=matrix[j][i];
        }
    }
    columnsM[i]=max;
    }

    for(int i=0; i<5; i++){
        cout<<columnsM[i]<<" ";
    }
    cout<<endl;

    //2
    for (int i=0; i<5; i++){
        int min=20;
        for(int j=0; j<5; j++){
            if(min>matrix[j][i]){
                min=matrix[j][i];
            }
        }
        columnsm[i]=min;
    }

    for(int i=0; i<5; i++){
        cout<<columnsm[i]<<" ";
    }
    cout<<endl;

    //3
    for (int i=0; i<5; i++){
        int max=0;
    for(int j=0; j<5; j++){
        if(max<matrix[i][j]){
            max=matrix[i][j];
        }
    }
    rowsM[i]=max;
    }

    for(int i=0; i<5; i++){
        cout<<rowsM[i]<<" ";
    }
    cout<<endl;

    //4
    for (int i=0; i<5; i++){
        int  min=20;
        for(int j=0; j<5; j++){
            if(min>matrix[i][j]){
                min=matrix[i][j];
            }
        }
        rowsm[i]=min;
    }

    for(int i=0; i<5; i++){
        cout<<rowsm[i]<<" ";
    }
    cout<<endl;

    //5
    cout<<endl;
    for(int j=4; j>=0; j--){
        if(j%2==0){
            for(int i=4; i>=0; i--){
                cout<<matrix[i][j]<<" ";
            }
        }
        if(j%2==1){
            for(int i=0; i<5; i++){
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    cout<<endl;

    //6
    cout<<endl;
    for (int i=4; i>=0; --i){
        for (int j=4; j>=0; --j){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //7
    cout<<endl;
    for (int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            int temp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=temp;
        }
    }

    for (int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //8
    cout<<endl;
    int matrix90[5][5]={0};
    for (int j=0; j<5; j++){
        for (int i=4, k=0; i>=0, k<5; i--, k++){
            matrix90[j][k]=matrix[i][j];
        }
    }

    for (int j=0; j<5; j++){
        for (int i=0; i<5; i++){
            cout<<matrix90[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //9
    cout<<endl;
    bool is_symmetric;
    for (int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(matrix[i][j]==matrix[j][i]){
                is_symmetric=true;
            }
            else{
                is_symmetric=false;
            }
        }
    }

    if(is_symmetric){
        cout<<"Matrix is symmetric"<<endl;
    }
    else{
        cout<<"Matrix is not symmetric"<<endl;
    }

    //10
    cout<<endl;
    int Matrix[5][6]={
        {1, 2, 3, 4, 5, 1},
        {2, 3, 4, 3, 2, 4},
        {1, 1, 2, 4, 8, 0},
        {0, 3, 2, 1, 6, 7},
        {1, 1, 1, 1, 1, 1}
    };

    int tMatrix[6][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            tMatrix[j][i]=Matrix[i][j];
        }
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<5; j++){
            cout<<tMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //12
    int Matrix1[5][6]={
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1}
    };

    int MatrixSum[5][6];

    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            MatrixSum[i][j]=Matrix[i][j]+Matrix1[i][j];
        }
    }

    cout<<endl;
    for(int i=0; i<5; i++){
        for(int j=0; j<6; j++){
            cout<<MatrixSum[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    //13
    int m[3][3]={
        {1, 2, 3},
        {2, 1, 1},
        {2, 3, 3}
    };

    int n[3][3]={
        {2, 1, 1},
        {2, 3, 1},
        {3, 1, 2}
    };

    int mult[3][3];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            mult[i][j]=m[i][0]*n[0][j]+m[i][1]*n[1][j]+m[i][2]*n[2][j];
        }
    }


    cout<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<mult[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    //15
    int min=50;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(mult[i][j]<min){
                min=mult[i][j];
            }
        }
    }
    cout<<endl<<"Min = "<<min<<endl;

    int* begin = &mult[0][0];
    int* end = begin+9;
    int Min = *min_element(begin, end);
    cout<<Min<<endl;

    int max=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(mult[i][j]>max){
                max=mult[i][j];
            }
        }
    }
    cout<<"Max = "<<max<<endl;
    int Max = *max_element(begin, end);
    cout<<Max<<endl;

    //17
    int elem=19;
    cout<<endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(mult[i][j]==elem){
                cout<<"found"<<endl;
                cout<<"position: "<<i<<" "<<j<<" "<<endl;
            }
        }
    }

    int* search = find(begin, end, elem);
    if(search!=end){
        int index = distance (begin, search);
        int row = index/3;
        int col = index%3;
        cout<<"position: "<<row<<" "<<col<<" "<<endl;
    }
    else{
        cout<<"not found"<<endl;
    }

    //20
    int sum=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum+=mult[i][j];
        }
    }
    cout<<endl<<"Sum: "<<sum<<endl; 

    sum = accumulate(begin, end, 0); //#include <numeric>
    cout<<"Sum: "<<sum<<endl; 

    //21
    float count=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            count+=1.0;
        }
    }
    float average = sum/count;
    cout<<endl<<"Average: "<<average<<endl;
    
    //22
    cout<<endl<<"Diagonal elements: ";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j){
                cout<<mult[i][j]<<" ";
            }
        }
    }
    cout<<endl;

    //23
    cout<<endl;
    int rows[3] = {0, 0, 0};
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            rows[i]+=mult[i][j];
        }
    }

    max = *max_element(&rows[0], &rows[0]+3);
    cout<<endl<<"Maximal row sum: "<<max<<endl;
    cout<<"Row number: "<<distance(&rows[0], max_element(&rows[0], &rows[0]+3))+1;

    //24
    int countt[10] = {0}; 

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            countt[mult[i][j]]++; 
        }
    }

    int maxCount = 0;
    int mostFrequent = mult[0][0];

    for (int i = 0; i < 10; ++i) {
        if (countt[i] > maxCount) {
            maxCount = countt[i];
            mostFrequent = i;
        }
    }

    cout <<endl<< endl<< "Найбільш повторюване число: " << mostFrequent << endl;

    //25
    int mat[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(mult[i][j]%2==0){
                mat[i][j]=mult[i][j];
            }
            else {
                mat[i][j]=0;}
        }
    }

    cout<<endl<<endl;
    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    return 0;
}