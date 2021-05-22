#include <iostream>
#include <exception>

using namespace std;

int main() {
    int x;
    bool aux = true;
    cin.exceptions(istream::failbit);

    while(true){
        cout << "PLEASE INSERT VALUE:" << endl;
        try {
            cin >> x;
            break;
        }
        catch (ios_base::failure &fail) {
            cout << "PLEASE INSERT A VALID OPTION." << endl;
            cin.clear();
            string tmp;
            getline(cin, tmp);
            continue;
        }
    }
    cout << "fim";
}