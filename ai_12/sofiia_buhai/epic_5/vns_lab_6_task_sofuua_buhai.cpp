#include <stdio.h>
#include <string.h>
#include <cctype>
#include <stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int max = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] > array[max])
        max = i;
    }
    swap(&array[max], &array[step]);
  }
}


int main(){
// Перетворити рядок таким чином, щоб цифри кожного слова в ньому були відсортовані за спаданням
    char str[] = "Many th1i3ng5s tha2t s4e7em th18re5ate2ning in the dark b1ec53ome we9lco351mi2ng when we sh51ine l7ig13ht on th54e3m.",
    answer[256]="";
    char *token = strtok(str, " ");
    while (token != NULL) {
        int count=0;
        for(int i=0; token[i]!='\0'; i++){
            if(isdigit(token[i])){
                count++;
            }
        }
        if(count!=0){
            int num[count];
            int j=0;
            for(int i=0; i<count; i++){
                for(; token[j]!=NULL; j++){
                    if(isdigit(token[j])){
                        num[i]=token[j]-48;
                        j++;
                        break;
                    }
                }
            }
            selectionSort(num, count);
            j=0;
            for(int i=0; token[i]!=NULL; i++){
                if(isdigit(token[i])){
                    token[i]=(num[j]+48);
                    j++;    
                }
            }
        }
        strcat(answer, token);
        strcat(answer, " ");
        token = strtok(NULL, " ");
    }
    puts(answer);

    return 0;
}