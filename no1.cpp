//
// Created by ASUS on 11/21/2022.
//

#include "no1.h"
#include <iostream>
using namespace std;

struct record{
    int id;
    string name;
    int score;
};

void displayStruct(struct record data[], int n){
    for (int i=0; i<n; i++){
        cout << "ID \t : " << data[i].id << endl;
        cout << "Name \t : " << data[i].name << endl;
        cout << "Score \t : " << data[i].score << endl;
        cout << "--------------------------------------" << endl;
    }
}

bool binarySearch(struct record data[], int x){
    int l = 0;
    int r = sizeof(data);
    int mid = (l+r)/2;
    bool found = false;

    while(!found && l<=r){
        if (data[mid].id == x){
            found =  true;
        } else if (data[mid].id < x){
            l = mid + 1;
        } else if (data[mid].id > x) {
            r = mid - 1;
        }
    }
    return found;
}


int main() {

    struct record data[12] = {
            {408599, "Cecilio Schubart", 93},
            {403189, "Desiri Chalker", 90},
            {405462, "Falkner Carder", 75},
            {406703, "Delainey Ruckhard", 89},
            {400324, "Colette Abramovic", 92},
            {404342, "Irwinn Bussey", 81},
            {409504, "Terrie Whitaker", 83},
            {401339, "Gary Binestead", 77},
            {405509, "Ferris Fulbrook", 91},
            {400522, "Diane Bissill", 77},
            {404878, "Ricoriki Jiroutka", 93},
            {403536, "Reidar Putten", 89},
    };

    for (int i=0; i<12; i++){
        for (int j=i+1; j<12; j++){
            if (data[j].id < data[i].id){
                int temp1 = data[i].id;
                data[i].id = data[j].id;
                data[j].id = temp1;

                string temp2 = data[i].name;
                data[i].name = data[j].name;
                data[j].name = temp2;

                int temp3 = data[i].score;
                data[i].score = data[j].score;
                data[j].score = temp3;
            }
        }
    }

    int id;
    cout << "input id :";
    cin >> id;

    if(binarySearch(data, id)){
        cout << "yes";
    } else {
        cout << "no";
    }




}