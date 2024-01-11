#include <bits/stdc++.h>
using namespace std ;

int main() {
    int v[10];
    int X;
    int cont = 0;
    vector<int> pos;

    for(int i = 0; i < 10; i++) {
        cin >> v[i];
    }

    cin >> X;

    for(int i = 0; i < 10; i++) {
        if(v[i] == X) {
            cont++;
            pos.push_back(i);

        }
    }

    if(cont == 0) {
        cout << "Mia x" << endl;
    }
    
    else{
        cout << cont << endl;
        for(int i = 0; i < pos.size(); i++){
            cout << pos[i] << " ";
        }
    }
    return 0;
}

