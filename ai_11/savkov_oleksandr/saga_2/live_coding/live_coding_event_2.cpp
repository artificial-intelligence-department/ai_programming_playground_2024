#include <iostream>
#include <fstream>




double var = 21;




double function_1() {
    double a,b,f;
    int c,d,e;


    std::cout << "Введіть дійсні числа: ";
    std::cin >> a >> b >>f; // дійсні змінні
    std::cout << "Введіть цілі числа: ";
    std::cin >> c >> d >>e; // цілочисельні змінні

    double pashka[6]  = {a ,b,f,static_cast<double>(c),static_cast<double>(d),static_cast<double>(e)};

    std::sort(pashka, pashka+6);

    double bilshi[3] = {pashka[5],pashka[4],pashka[3]};
    double menshi[3] = {pashka[0],pashka[1], pashka[2]};

    double summMensh = 0;
    double summBilsh = 0;
    double result = 0;

    for(int i = 0; i < 3; i++){
        summBilsh += bilshi[i];
    }
    for(int i = 0; i < 3; i++){
        summMensh += menshi[i];
    }

    if (summBilsh > (summMensh * 4)){    // оператори розгалуження
        result = summMensh + summMensh;
    } else if (summBilsh > (summMensh * 3)){
        result = summMensh/ summMensh;
    } else if (summBilsh > (summMensh * 2)){
        result = summMensh * summMensh;
    }
     result = result / var;
     std::cout << result << std::endl;

 return result;




}

double** function_2(double& x, double **tempMatr){
    
    for(int i=0; i<5; i++){ // цикл фор
       tempMatr[i] = new double[5];
     }

     for(int i=0; i<5; i++){
        for(int j=0; j< 5; j++) {
            tempMatr[i][j] = x;
        }
     }

     for(int i=0; i<5; i++){
        for(int j=0; j< 5; j++) {
            tempMatr[i][j] = (tempMatr[i][j] + var + j -1) * (rand()% 100+1);

        }
     }
     for(int i =0; i<5; i++){
        for(int j=0; j<5; j++ ){
            std::cout << tempMatr[i][j] << " ";

        }
        std::cout << std::endl;
     }
     return tempMatr;
}
// Оголосити одновимірний масив розміром 5 елементів.
// Для кожного стовпця матриці 5x5 знайти найменший елемент.
// Для кожного стовпця матриці 5x5 знайти найменший елемент іншим алгоритмом пошуку.
// Звірити чи результати обох пошуків співпадають та повідомити про це в консоль.
// Записати ці знайдені елементи у створений масив.
// Повернути масив у головну функцію.


double* function_3(double **tempMatr){
    double * returnArr = new double[5];
   
    
    
    double* res1= new double[5]; 
    double* res2= new double[5]; 
    double max = 0;


    // first sposib
    for(int i = 0; i<5; i++){
        double max  = tempMatr[0][i];
        for(int j = 1; j < 5; j++){
            if(tempMatr[j][i] < max){
                max = tempMatr[j][i];
                
                
            }
            res1[i] = max;
        }
    }

    // second sposib

    for(int i = 0; i<5; i++){
        double max  = tempMatr[0][i];
        for(int j = 1; j < 5; j++){
            if(tempMatr[j][i] < max){
                max = std::min(max, tempMatr[j][i]);
                
                
            }
            res2[i] = max;
        }
    }

    for(int i= 0; i< 5; i++){
        std::cout << res1[i] << std::endl;
    }

    std::cout << std::endl;

    for(int i= 0; i< 5; i++){
        std::cout << res2[i] << std::endl;
    }

    for(int i = 0; i<5; i++){
        if(res1[i] != res2[i]) {
            std:: cout << " pomilka";
            break; // використання бреак

        } else{
            returnArr[i] = res1[i];
        }

    }
    


    return returnArr;


}

// Створити двонапрямлений список із 7 структур, кожна з яких представляє студента: ім'я (рядок),прізвище (рядок),кількість грошей на рахунку (дійсне число).
// Рандомно заповнити імена та прізвища студентів.
// Присвоїти значення для грошей за правилами:
// 1-му студенту — найбільше значення з масиву.
// 2–6-м студентам — послідовно суми елементів масиву.
// 7-му студенту — найменше значення з масиву.
// Вивести список у консоль.

struct Node{
    std::string name;
    std::string surname;
    double money;
    Node* poper;
    Node* next;

    Node(std::string name,std::string surname, double money, Node* poper=nullptr, Node* next = nullptr): name(name), surname(surname), money(money), poper(poper), next(next)  {}

};

class Creating {
    private: 
        Node* poch;
        Node* kin;

    public: Creating(): poch(nullptr), kin(nullptr) {}
    ~Creating(){
        while(poch){
            Node* temp = poch;
            poch = poch->next;
            delete temp;
        }
    }

    void addEl(const std::string& name,const std::string& surname, double money ){
        Node* tempNode = new Node(name, surname, money);
        if(!poch){
            poch = kin = tempNode;
        } else {
            kin->next = tempNode;
            tempNode->poper = kin;
            kin = tempNode;
        }
    }

    void printNode(){
        Node* temp = poch;
while (temp) {
    std::cout << temp->name << " " << temp->surname << " " << temp->money << std::endl;
    temp = temp->next; 
}
    }

    Node* returnNead() const {
        return poch;

    }
    Node* returnEnd() const{
        return kin;
        
    }

     
};


Creating function_4(double* tempArr){
    Creating students;
    std::string surnames[] = {"Stolar", "Bordyn", "Sebastyan", "Bolia", "Stas", "Nimirov", " VsCode"};
    std::string names[] = {"Max", "Andrii", "Andriana", "Nastia", "Anna", "Sasha", " Vladimir"};

    for(int i = 0; i< 7;i++){
        if(i ==0){
            students.addEl(names[i], surnames[i], tempArr[4]);
        } else if(i == 6){
            students.addEl(names[i], surnames[i], tempArr[0]);
        } else {
            students.addEl(names[i], surnames[i], tempArr[i-1]);
        }
    }

    return students;
}







// Node* function_4(double *tempArr){

//     std::string surnames[] = {"Stolar", "Bordyn", "Sebastyan", "Bolia", "Stas", "Nimirov", " VsCode"};
//     std::string names[] = {"Max", "Andrii", "Andriana", "Nastia", "Anna", "Sasha", " Vladimir"};









// }
void help_for_function_5(std::ofstream& file, const Creating& students, bool reverse) {
    if (reverse) {
        // Задом наперед
        Node* tempKin = students.returnEnd();
        while (tempKin) {
            file << tempKin->name << " " << tempKin->surname << " " << tempKin->money << std::endl;
            tempKin = tempKin->poper; // Переходимо до попереднього вузла
        }
    } else {
        // У прямому порядку
        Node* tempHead = students.returnNead();
        while (tempHead) {
            file << tempHead->name << " " << tempHead->surname << " " << tempHead->money << std::endl;
            tempHead = tempHead->next; // Переходимо до наступного вузла
        }
    }
}


void function_5(const Creating& students ){
    int var2 = 21;
    std::ofstream file("Studensts.txt");
    if(!file.is_open()){
        std::cout << "Error";
        return;
    }
    if( var2 % 2 == 0){ 
        help_for_function_5(file, students, true);
    } else {
         help_for_function_5(file, students, false);
    }
    file.close();
}

void function_6() {
    std::ifstream file("Students.txt");
    if (!file.is_open()) {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

    


int main(){

    double x = function_1();

    double** matr = new double*[5]; //двовимірний масив
    std::cout << std::endl;

    double** tower = function_2(x, matr);
    std::cout << std::endl;
    
    double *masiv = function_3(tower);
    std::cout << std::endl;
    std::sort(masiv,masiv+5);

    Creating studenst = function_4(masiv);
    studenst.printNode();
    std::cout << std::endl;

    function_5(studenst);
    std::cout << std::endl;
    function_6();

    for (int i = 0; i < 5; i++) delete[] tower[i];
    delete[] tower;
    delete[] masiv;





    return 0;
}