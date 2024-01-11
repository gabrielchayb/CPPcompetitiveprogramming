#include <bits/stdc++.h>
using namespace std ;

int main() {
    int N;
    int cont = 0;
    cin >> N; 
    
    vector<char> gab;
    vector<char> resp;

    for(int i = 0; i < N; i++){
        char aux; 
        cin >> aux; 
        gab.push_back(aux);
    }

    for(int i = 0; i < N; i++){
        char aux;
        cin >> aux;
        resp.push_back(aux);
    }

    for(int i = 0; i < N; i++){
        if(gab[i] == resp[i]){
            cont++;
        }
    }
    cout << cont << endl;
}

