#include <iostream>

using namespace std;

class Account{
public:
    Account(){
        cout << "Calling constructor\n";
    }

    ~Account(){
        cout << "Calling destructor\n";
    }
};

int main() {
    Account *account = new Account();
    delete account;
    return 0;
}