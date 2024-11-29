#include <iostream>
#include <vector>
using namespace std;

struct Buyer{
    char fullName[66];
    char homeAddress[66];
    int mobilePhoneNumber;
    int creditCardNumber;
};

void createFile(const char *filename){
    FILE* f;
    f = fopen(filename, "wb");

    if(f==NULL){
        cout<<"Error opening the file";
        exit(1);
    }

    int number;
    cout<<"Enter number of buyers: ";
    cin>>number;

    Buyer b; 

    for (int i=0; i<number; i++){
        cout<<"Enter fullname: ";
        cin>>b.fullName;

        cout<<"Enter address: ";
        cin>>b.homeAddress;

        cout<<"Enter phone number: ";
        cin>>b.mobilePhoneNumber;

        cout<<"Enter credit card number: ";
        cin>>b.creditCardNumber;

        fwrite(&b, sizeof(Buyer), 1, f);

        if(ferror(f)){
            cout<<"Error writing data to the file";
            exit(2);
        }
    }
    fclose(f);
}

void printFile(const char *filename){
    FILE* f;
    f = fopen(filename, "rb");

    if(f==NULL){
        cout<<"Error opening the file";
        exit(1);
    }

    Buyer b;

    cout<<endl<< "File: "<<endl;

    while (fread(&b, sizeof(Buyer), 1, f)) {
        cout<<"Fullname: "<<b.fullName<<endl;
        cout<< "Home address: "<<b.homeAddress<<endl;
        cout<< "Phone number: " <<b.mobilePhoneNumber<<endl;
        cout<<"Credit card number: "<<b.creditCardNumber<<endl;
        }
    fclose(f);
}    

void deleteBuyerData(const char *filename){
    FILE* f;
    f = fopen(filename, "rb");

    if(f==NULL){
        cout<<"Error opening the file";
        exit(1);
    }

    vector<Buyer> buyers;
    Buyer b;
    int count = 0;

    while (fread(&b, sizeof(Buyer), 1, f)){
        if(count>=3){
            buyers.push_back(b);
        }
        count++;
    }
    fclose(f);

    f = fopen(filename, "wb");

    if(f==NULL){
        cout<<"Error opening the file";
        exit(1);
    }

    for (const auto& buyer : buyers) {
        fwrite(&buyer, sizeof(Buyer), 1, f);
    }

    if(ferror(f)){
        cout<<"Error writing data to the file";
        exit(2);
    }
    fclose(f);
}

void addBuyerData(const char *filename){
    FILE* f;
    f = fopen(filename, "rb");

    if(f==NULL){
        cout<<"Error opening the file";
        exit(1);
    }

    vector<Buyer> buyers;
    Buyer b;
    int count = 0;

    while (fread(&b, sizeof(Buyer), 1, f)){
        buyers.push_back(b);
    }

    for (int i=0; i<3; i++){
        cout<<"Enter fullname: ";
        cin>>b.fullName;

        cout<<"Enter address: ";
        cin>>b.homeAddress;

        cout<<"Enter phone number: ";
        cin>>b.mobilePhoneNumber;

        cout<<"Enter credit card number: ";
        cin>>b.creditCardNumber;

        buyers.push_back(b);
    }
    fclose(f);

    f = fopen(filename, "wb");

    if(f==NULL){
        cout<<"Error opening the file";
        exit(1);
    }

    for (const auto& buyer : buyers) {
        fwrite(&buyer, sizeof(Buyer), 1, f);
    }
    
    if(ferror(f)){
        cout<<"Error writing data to the file";
        exit(2);
    }
    fclose(f);
}


int main(){
    const char* fileName = "buyerdata.dat";

    createFile(fileName);
    printFile(fileName);
    deleteBuyerData(fileName);
    printFile(fileName);
    addBuyerData(fileName);
    printFile(fileName);

    return 0;
}



