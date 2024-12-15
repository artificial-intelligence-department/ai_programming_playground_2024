#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int* generate_id(string username){
    int* result = new int[50];
    int n = username.length();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(username[j] > username[j+1]){
                char temp = username[j];
                username[j] = username[j+1];
                username[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++){
        result[i] = username[i] * 0.4;
    }

    return result;
}

float files(string measurmentSystem, float distanceValue){
    double convert;
    double converter;
    if(measurmentSystem == "meter"){
        ifstream file_m("price_per_meter.txt");
        if(!file_m.is_open()){
            cerr << "File can`t be opened" << endl;
            exit(1);
        }
        while(file_m >> convert){
            converter = convert;
        }
        file_m.close();
    }    

    else if(measurmentSystem == "mile"){
        ifstream file_mil("price_per_mile.txt");
        if(!file_mil.is_open()){
            cerr << "File can`t be opened" << endl;
            exit(1);
        }
        while(file_mil >> convert){
            converter = convert;
        }
        file_mil.close();
    }
        
    else if(measurmentSystem == "mile_us"){ 
        ifstream file_mil_us("price_per_mile_us.txt");
        if(!file_mil_us.is_open()){
            cerr << "File can`t be opened" << endl;
            exit(1);
        }
        while(file_mil_us >> convert){
            converter = convert;
        }
        file_mil_us.close();
    }
    else{
        cout << "Invalid input: " << endl;
        return 0;
    }

    
    
    float DistanceValue = distanceValue * convert;
    return DistanceValue;
}

void input_file(int* result, float DistanceValue){
    ofstream file("collected_distance.txt");
    if (!file.is_open()) {
        cerr << "Error" << endl;
        exit(1);
    }
    file << "ID: " << result << endl;
    file << "Distance: " << DistanceValue << "m" << endl;
    file.close();
}

void isPallindrome(float &DistanceValue){
    int distance = DistanceValue;
    bool isPallindrome = true;
    string distanceStr = to_string(distance);
    int len = distanceStr.length();
    for(int i = 0; i < len / 2; i++){
        if(distanceStr[i] != distanceStr[len - i - 1]){
            isPallindrome = false;
        }
    }
    if(isPallindrome == false){
        cout << "No discount" << endl;
    }
    else{
        cout << "Is discount" << endl;
    }
}
int main(){
    string username;
    cout << "Enter name: " << endl;
    getline(cin, username);


    string measurmentSystem;
    cout << "Enter measurement system(meter/mile/mile_us): " << endl;
    getline(cin, measurmentSystem);

    float distanceValue;
    cout << "Enter distance: " << endl;
    cin >> distanceValue;



    float DistanceValue = files(measurmentSystem, distanceValue);
    cout << DistanceValue << "m" << endl;
    int n = username.length();
    int* result = new int[50];
    result = generate_id(username);
    for(int i = 0; i < n; i++){
        cout << result[i];
    }

    input_file(result, DistanceValue);

    isPallindrome(DistanceValue);
    delete[] result;
    return 0;
}
