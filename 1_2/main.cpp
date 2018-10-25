#include <iostream>
#include <string.h>
#include <stdio.h>
#define MAXINPUT 100

using namespace std;

int isValid(char input[]){
    int length = strlen(input);
    if(input[0] == '-'){
        cout << "Provide a positive number!\n";
        return 0;
    }
    for (int i = 0; i < length; ++i)
        if (!isdigit(input[i]))
        {
            return 0;
        }
    return 1;
}

void sieve(int n, int m){
    bool prime[n + 1];

    //at the beginning set all numbers as prime
    for(int i = 0; i < n + 1; ++i)
        prime[i] = true;

    // x = 2 as 2 is the first prime number
    // outer loop to go through all elements
    for(int x = 2; x * x <= n; ++x){
        // if x = prime number, then delete all its multiples
        if(prime[x]){
            for(int i = x * 2; i <= n; i += x)
                prime[i] = false;
        }
    }

    cout << "Prime numbers: ";
    for(int i = m; i <= n; ++i)
        if(prime[i])
            cout << i << ", ";
}

int main() {
    int n, m;

    char input[MAXINPUT] = "";

    cout << "Provide a lower limit: \n";

    scanf("%s", input);
    if(isValid(input) == 1){
        sscanf(input, "%d", &m);
        //printf("%d", m);
    }
    else{   //input is not valid
        while(isValid(input) == 0) {
            printf("Provide a number!\n");
            scanf("%s", input);
        }
        sscanf(input, "%d", &m);
    }

    cout << "Provide an upper limit: \n";

    scanf("%s", input);
    if(isValid(input) == 1){
        sscanf(input, "%d", &n);
        //printf("%d", n);
    }
    else{   //input is not valid
        while(isValid(input) == 0) {
            printf("Provide a number!\n");
            scanf("%s", input);
        }
        sscanf(input, "%d", &n);
    }

    if(n < m) {
        cout << "Upper limit is lower than lower limit!";
        exit(1);
    }

    sieve(n, m);

    return 0;
}