#include <iostream>
#include <fstream>

using namespace std;

void getData(float [][4]);
void printHeader();
void printData(float [][4]);

int main() {

    float sales[5][4] = {0.0};

    getData(sales);

    printHeader();

    printData(sales);

    return 0;
}

void getData(float sales[][4]){

    int salesperson;
    int product;
    float value;
    string temp;

    ifstream myFile("c:/users/patry/documents/oop/sales.txt");

    if(myFile.is_open()){
        while(myFile >> salesperson >> product >> value){
            sales[salesperson - 1][product - 1] += value;
        }
    }

    myFile.close();

}

void printHeader(){
    cout << "\nAt the end of each row we display a total\n" <<
         "amount of money earned by each salesperson.\n" <<
         "At the end of each column we display a total\n" <<
         "amount of money earned on each product.\n\n";
    cout << "Person";
    printf("%22s", "Products\n");
    printf("%11d%8d%9d%8d%9s\n", 1, 2, 3, 4, "Total");
}

void printData(float sales[][4]){

    float totalValue;
    float productValues[4]; //to display total amount of money earned by selling each product

    for(int i = 0; i < 5; ++i){
        totalValue = 0.0;
        printf("%3d   ", i + 1);

        for(int j = 0; j < 4; ++j){
            totalValue += sales[i][j];
            productValues[j] += sales[i][j];
            printf("%8.2f", sales[i][j]);
        }

        printf("%8.2f\n", totalValue);
    }

    cout << "Total:";

    for (float productValue : productValues)
        printf("%8.2f", productValue);

    cout << endl;
}