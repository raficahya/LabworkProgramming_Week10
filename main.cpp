#include <iostream>
using namespace std;

void sortData(int id[], string name[], int score[], int n){
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (id[j] < id[i]){
                int temp1 = id[i];
                id[i] = id[j];
                id[j] = temp1;

                string temp2 = name[i];
                name[i] = name[j];
                name[j] = temp2;

                int temp3 = score[i];
                score[i] = score[j];
                score[j] = temp3;
            }
        }
    }
}

void binarySearch(int id[], string name[], int score[], int x, int n){
    int l = 0;
    int r = n;
    bool found = false;
    int index = 0;

    while(!found && l<=r){
        int mid = (l+r)/2;
        if (id[mid] == x){
            index = mid;
            found =  true;
        } else if (id[mid] < x){
            l = mid + 1;
        } else if (id[mid] > x) {
            r = mid - 1;
        }
    }

    if (found) {
        cout << "ID : " << id[index] << endl;
        cout << "Name : " << name[index] << endl;
        cout << "Score : " << score[index] << endl;
    } else {
        cout << "Data not found";
    }
}



int main(){
    int id[12] = {408599,
            403189,
            405462,
            406703,
            400324,
            404342,
            409504,
            401339,
            405509,
            400522,
            404878,
            403536,
    };

    string name[12] = {
            "Cecilio Schubart",
            "Desiri Chalker",
            "Falkner Carder",
            "Delainey Ruckhard",
            "Colette Abramovic",
            "Irwinn Bussey",
            "Terrie Whitaker",
            "Gary Binestead",
            "Ferris Fulbrook",
            "Diane Bissill",
            "Ricoriki Jiroutka",
            "Reidar Putten"

    };

    int score[12] = {
            93,
            90,
            75,
            89,
            92,
            81,
            83,
            77,
            91,
            77,
            93,
            89,

    };

    int arraySize  = sizeof(id)/sizeof(id[0]);

    sortData(id, name, score, arraySize);

    int x;
    cout << "Input the Student ID!";
    cin >> x;

    binarySearch(id, name, score, x, arraySize);

}