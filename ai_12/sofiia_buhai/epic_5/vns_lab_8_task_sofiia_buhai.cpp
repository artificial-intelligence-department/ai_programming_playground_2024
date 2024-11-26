// 13. Структура "Спортивна команда":
// - назва;
// - місто;
// - кількість гравців;
// - кількість набраних очків.
// Знищити всі елементи з кількістю очків менше заданого, додати 2 елементи на
// початок файлу.

#include <stdio.h>
#include <string.h>
#include <cctype>
#include <stdlib.h>
#include <iostream>


struct SportTeam {
    char name[51];
    char city[51];
    int num_of_players;
    int points;
};

void Print(){
    FILE* f = fopen("teams.txt", "rb");
    if(f==0){
        std::cerr << "Failed to open the file";
        return;
    }
    SportTeam team;
    int i=1;
    while(fread(&team, sizeof(SportTeam), 1, f)!=0){
        printf("\nHere is the information about team №%d : ", i);
        printf("\nName : %s", team.name);
        printf("\nCity : %s", team.city);
        printf("\nNumber of players : %i", team.num_of_players);
        printf("\nName : %i", team.points);
        i++;
    }
    fclose(f);
}

void AddTwo(int n){
    printf("\n\nWith two elements added before :\n");
    FILE* f = fopen("teams.txt", "rb");
    FILE* nf = fopen("NewTeams.txt", "wb");
    if(!f){
        std::cerr << "Failed to open the file";
        return;
    }
    SportTeam team[2] = 
    {
        {"Dandandan", "Japan", 11, 10},
        {"Oleya", "Gergi", 8,  6}
    };
    for (int i = 0; i < 2; i++) {
        if (fwrite(&team[i], sizeof(SportTeam), 1, nf) != 1) {
            std::cerr << "Error writing.\n";
            fclose(f);
            fclose(nf);
            return;
        }
    }
    SportTeam neew;
    while(fread(&neew, sizeof(SportTeam), 1, f)) {
        if (fwrite(&neew, sizeof(SportTeam), 1, nf) != 1) {
            std::cerr << "Error writing.\n";
            fclose(f);
            fclose(nf);
            return;
        }
    }
    fclose(f);
    fclose(nf);
    remove("teams.txt");
    rename("NewTeams.txt", "teams.txt");
    Print();
}

void CreateTeam(SportTeam* team, int n){
    FILE* f = fopen("teams.txt", "wb");
    if(f==0){
        std::cerr << "Failed to open the file";
        return;
    }
    for(int i=0; i<n; i++){
        printf("\nEnter the information about team №%d :", i+1);
        printf("\nThe name of team : ");
        fgets(team[i].name, sizeof(team[i].name), stdin);
        team[i].name[strcspn(team[i].name, "\n")] = 0;
        printf("Type the city : ");
        fgets(team[i].city, sizeof(team[i].city), stdin);
        team[i].city[strcspn(team[i].city, "\n")] = 0;
        printf("The number of players : ");
        scanf("%d", &team[i].num_of_players);
        printf("The number of points : ");
        scanf("%d", &team[i].points);
        while(getchar() != '\n');
    }
    fwrite(team, sizeof(SportTeam), n, f);
    fclose(f);
    Print();
}

void DeleteTeam(const char* Name){
    FILE* f = fopen("teams.txt", "rb");
    if(!f){
        std::cerr << "Failed to open the file";
        return;
    }
    int count=0;
    SportTeam* T = NULL;
    SportTeam teams;
    while (fread(&teams, sizeof(SportTeam), 1, f)){
        if ((strcmp(teams.name, Name)) != 0){
            SportTeam* neew = (SportTeam*)realloc(T, (count + 1) * sizeof(SportTeam));
            T = neew;
            T[count] = teams;
            count++;
        }
    }
    fclose(f);
    FILE* nf = fopen("teams.txt", "wb");
    if(f==0){
        std::cerr << "Failed to open the file";
        return;
    }
    fwrite(T, sizeof(SportTeam), count, nf);
    fclose(nf);
    printf("\n\nWithout team %s :\n", Name);
    Print();
}


void DeleteUnder(int k){
    FILE* f = fopen("teams.txt", "rb");
    if(f==0){
        std::cerr << "Failed to open the file";
        return;
    }
    int count=0;
    SportTeam* T = NULL;
    SportTeam teams;
    while (fread(&teams, sizeof(SportTeam), 1, f)){
        if (teams.points >= k){
            SportTeam* neew = (SportTeam*)realloc(T, (count + 1) * sizeof(SportTeam));
            T = neew;
            T[count] = teams;
            count++;
        }
    }
    fclose(f);
    FILE* nf = fopen("teams.txt", "wb");
    if(f==0){
        std::cerr << "Failed to open the file";
        return;
    }
    fwrite(T, sizeof(SportTeam), count, nf);
    fclose(nf);
    printf("\n\nWith teams above %i points :\n", k);
    Print();
}



int main(){
    int n=1, k=8;
    char Name[]="Answer";
    SportTeam* team = new SportTeam[n];
    CreateTeam(team, n);
    AddTwo(n);
    DeleteUnder(k);
    DeleteTeam(Name);
    delete[] team;
    return 0;
}