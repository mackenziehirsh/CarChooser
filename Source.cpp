#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <chrono>
using namespace std;

struct Car {
    std::string model;
    int year = 0;
    int price = 0;
    std::string transmission;
    int mileage = 0;
    std::string fuelType;
    int tax = 0;
    float mpg = 0;
    float engineSize = 0;
    void printCar(int number) {
        std::cout << "----------------------------------------------------------------" << std::endl;
        std::cout << "Car #" << number << " is a " << year << model << " listed at $" << price << " with a road tax of $" << tax << " and a current mileage of " << mileage << "." << std::endl;
        std::cout << "It has a(n) " << transmission << " transmission, uses " << fuelType << " fuel, and gets " << mpg << " mpg with an engine size of " << engineSize << " L." << std::endl;
    }
};

void mergePrices(Car* cars, int const left, int const m, int const right) {
   
    int const x1 = m - left + 1;
    int const x2 = right - m;
    Car* X = new Car[x1];
    Car* Y = new Car[x2];

    for (auto i = 0; i < x1; i++) {
        X[i] = (cars[left + i]);
       
    }
    for (auto j = 0; j < x2; j++) {
        Y[j] = (cars[m + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < x1 && j < x2) {
        if (X[i].price < Y[j].price) {
            cars[k] = X[i];
            i++;
        }
        else {
            cars[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < x1) {
        cars[k] = X[i];
        i++;
        k++;
    }

    while (j < x2) {
        cars[k] = Y[j];
        j++;
        k++;
    }
    delete[] X;
    delete[] Y;
}

void mergeSortPrice(Car* cars, int const left, int const right) {
   
    if (left < right) {
        int m = left + (right - left) / 2;
        mergeSortPrice(cars, left, m);
        mergeSortPrice(cars, m + 1, right);
        mergePrices(cars, left, m, right);
    }
}

void mergeMileage(Car* cars, int const left, int const m, int const right) {

    int const x1 = m - left + 1;
    int const x2 = right - m;
    Car* X = new Car[x1];
    Car* Y = new Car[x2];

    for (auto i = 0; i < x1; i++) {
        X[i] = cars[left + i];
    }
    for (auto j = 0; j < x2; j++) {
        Y[j] = cars[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < x1 && j < x2) {
        if (X[i].mileage < Y[j].mileage) {
            cars[k] = X[i];
            i++;
        }
        else {
            cars[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < x1) {
        cars[k] = X[i];
        i++;
        k++;
    }

    while (j < x2) {
        cars[k]= Y[j];
        j++;
        k++;
    }
    delete[] X;
    delete[] Y;
}

void mergeSortMileage(Car* cars, int const left, int const right) {

    if (left < right) {
        int m = left + (right - left) / 2;
        mergeSortMileage(cars, left, m);
        mergeSortMileage(cars, m + 1, right);
        mergeMileage(cars, left, m, right);
    }
}

void mergeMPG(Car* cars, int const left, int const m, int const right) {

    int const x1 = m - left + 1;
    int const x2 = right - m;
    Car* X = new Car[x1];
    Car* Y = new Car[x2];

    for (auto i = 0; i < x1; i++) {
        X[i] = (cars[left + i]);
    }
    for (auto j = 0; j < x2; j++) {
        Y[j] = (cars[m + 1 + j]);
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < x1 && j < x2) {
        if (X[i].mpg >= Y[j].mpg) {
            cars[k] = X[i];
            i++;
        }
        else {
            cars[k] = Y[j];
            j++;
        }
        k++;
    }

    while (i < x1) {
        cars[k] = X[i];
        i++;
        k++;
    }

    while (j < x2) {
        cars[k] = Y[j];
        j++;
        k++;
    }
    delete[] X;
    delete[] Y;
}

void mergeSortMPG(Car* cars, int const left, int const right) {

    if (left < right) {
        int m = left + (right - left) / 2;
        mergeSortMPG(cars, left, m);
        mergeSortMPG(cars, m + 1, right);
        mergeMPG(cars, left, m, right);
    }

}


void heapifyPrice(Car* cars, int size, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && cars[left].price > cars[max].price)
        max = left;
    if (right < size && cars[right].price > cars[max].price)
        max = right;
    if (max != i) {
        std::swap(cars[i], cars[max]);
        heapifyPrice(cars, size, max);
    }
}

void heapSortPrice(Car* cars, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyPrice(cars, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        std::swap(cars[0], cars[i]);
        heapifyPrice(cars, i, 0);
    }
}

void heapifyMileage(Car* cars, int size, int i) {
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && cars[left].mileage > cars[max].mileage)
        max = left;
    if (right < size && cars[right].mileage > cars[max].mileage)
        max = right;
    if (max != i) {
        std::swap(cars[i], cars[max]);
        heapifyMileage(cars, size, max);
    }
}

void heapSortMileage(Car* cars, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyMileage(cars, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        std::swap(cars[0], cars[i]);
        heapifyMileage(cars, i, 0);
    }
}

void heapifyMpg(Car* cars, int size, int i) {
    int min = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && cars[left].mpg < cars[min].mpg)
        min = left;
    if (right < size && cars[right].mpg < cars[min].mpg)
        min = right;
    if (min != i) {
        std::swap(cars[i], cars[min]);
        heapifyMpg(cars, size, min);
    }
}

void heapSortMpg(Car* cars, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapifyMpg(cars, size, i);
    }
    for (int i = size - 1; i > 0; i--) {
        std::swap(cars[0], cars[i]);
        heapifyMpg(cars, i, 0);
    }
}

int main()
{
    std::cout << "********************************************" << std::endl << "************Best Used Car Finder************" << std::endl << "********************************************" << std::endl << std::endl;
    std::cout << "Would you like to search through all cars or for a specific make?" << std::endl;
    std::cout << "1. Search all cars" << std::endl;
    std::cout << "2. Search for a specific make" << std::endl << std::endl;
    int choice;
    std::cin >> choice;
    std::vector<Car> cars;
    std::string line, value;

    if (choice == 1) { //adds all cars
        std::string files[9] = { "audi.csv", "bmw.csv", "ford.csv", "hyundi.csv", "merc.csv", "skoda.csv", "toyota.csv", "vauxhall.csv", "vw.csv" };
        for (int i = 0; i < 9; i++) {
            std::fstream file(files[i], std::ios::in);
            getline(file, line);
            while (getline(file, line)) {
                std::stringstream values(line);
                Car temp;
                getline(values, value, ',');
                temp.model = value;
                getline(values, value, ',');
                temp.year = std::stoi(value);
                getline(values, value, ',');
                temp.price = std::stoi(value);
                getline(values, value, ',');
                temp.transmission = value;
                getline(values, value, ',');
                temp.mileage = std::stoi(value);
                getline(values, value, ',');
                temp.fuelType = value;
                getline(values, value, ',');
                temp.tax = std::stoi(value);
                getline(values, value, ',');
                temp.mpg = std::stof(value);
                getline(values, value, ',');
                temp.engineSize = std::stof(value);
                cars.push_back(temp);
            }
        }
    }

    else if (choice == 2) { //adds 1 make
        std::cout << std::endl << "Please select a make:" << std::endl;
        std::cout << "1. Audi" << std::endl;
        std::cout << "2. BMW" << std::endl;
        std::cout << "3. Ford" << std::endl;
        std::cout << "4. Hyundai" << std::endl;
        std::cout << "5. Merc" << std::endl;
        std::cout << "6. Skoda" << std::endl;
        std::cout << "7. Toyota" << std::endl;
        std::cout << "8. Vauxhall" << std::endl;
        std::cout << "9. Volkswagen" << std::endl << std::endl;
        std::cin >> choice;
        std::string make;
        if (choice == 1)
            make = "audi.csv";
        else if (choice == 2)
            make = "bmw.csv";
        else if (choice == 3)
            make = "ford.csv";
        else if (choice == 4)
            make = "hyundi.csv";
        else if (choice == 5)
            make = "merc.csv";
        else if (choice == 6)
            make = "skoda.csv";
        else if (choice == 7)
            make = "toyota.csv";
        else if (choice == 8)
            make = "vauxhall.csv";
        else if (choice == 9)
            make = "vw.csv";
        else {
            std::cout << "Invalid input! Ending program." << std::endl;
            return 0;
        }
        std::fstream file(make, std::ios::in);
        getline(file, line);
        while (getline(file, line)) {
            std::stringstream values(line);
            Car temp;
            getline(values, value, ',');
            temp.model = value;
            getline(values, value, ',');
            temp.year = std::stoi(value);
            getline(values, value, ',');
            temp.price = std::stoi(value);
            getline(values, value, ',');
            temp.transmission = value;
            getline(values, value, ',');
            temp.mileage = std::stoi(value);
            getline(values, value, ',');
            temp.fuelType = value;
            getline(values, value, ',');
            temp.tax = std::stoi(value);
            getline(values, value, ',');
            temp.mpg = std::stof(value);
            getline(values, value, ',');
            temp.engineSize = std::stof(value);
            cars.push_back(temp);
        }
    }

    else {
        std::cout << "Invalid input! Ending program." << std::endl;
        return 0;
    }

    std::cout << std::endl << cars.size() << " cars loaded!" << std::endl << std::endl;
    std::cout << "Please select the metric you would like to sort cars by:" << std::endl;
    std::cout << "1. Sort cars by lowest price" << std::endl;
    std::cout << "2. Sort cars by lowest mileage" << std::endl;
    std::cout << "3. Sort cars by highest miles per gallon" << std::endl << std::endl;
    std::cin >> choice;
    std::cout << std::endl;

    Car* mergeArray = new Car[cars.size()];
    std::copy(cars.begin(), cars.end(), mergeArray);
    Car* heapArray = new Car[cars.size()];
    std::copy(cars.begin(), cars.end(), heapArray);

    if (choice == 1) {
        //merge sort on price
        auto start = std::chrono::high_resolution_clock::now();
        //call merge sort on mergeArray, mergeArray[i].price to access the ints
        mergeSortPrice(mergeArray,0, cars.size() - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken using merge sort: " << duration.count() << " microseconds" << std::endl;
        //heap sort on price
        start = std::chrono::high_resolution_clock::now();
        heapSortPrice(heapArray, cars.size());
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken using heap sort: " << duration.count() << " microseconds" << std::endl;
    }
    else if (choice == 2) {
        //merge sort on mileage
        auto start = std::chrono::high_resolution_clock::now();
        //call merge sort on mergeArray, mergeArray[i].mileage to access the floats
        mergeSortMileage(mergeArray, 0, cars.size()-1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken using merge sort: " << duration.count() << " microseconds" << std::endl;
        //heap sort on mileage
        start = std::chrono::high_resolution_clock::now();
        heapSortMileage(heapArray, cars.size());
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken using heap sort: " << duration.count() << " microseconds" << std::endl;
    }
    else if (choice == 3) {
        //merge sort on mpg
        auto start = std::chrono::high_resolution_clock::now();
        //call merge sort on mergeArray, mergeArray[i].mpg to access the floats
        mergeSortMPG(mergeArray, 0, cars.size() - 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken using merge sort: " << duration.count() << " microseconds" << std::endl;
        //heap sort on mpg
        start = std::chrono::high_resolution_clock::now();
        heapSortMpg(heapArray, cars.size());
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken using heap sort: " << duration.count() << " microseconds" << std::endl;
    }
    else {
        std::cout << "Invalid input! Ending program." << std::endl;
        return 0;
    }

    std::cout << std::endl << "How many listings would you like to view? Please pick a number from 1-100." << std::endl << std::endl;
    std::cin >> choice;
    if (choice < 1 || choice > 100) {
        std::cout << "Invalid input! Ending program." << std::endl;
        return 0;
    }
    
    cout << "" << endl; 
    cout << "Merge Sort:" << endl;
    
    std::cout << std::endl << "Now printing the top " << choice << " cars sorted by your chosen metric:" << std::endl << std::endl;;
    for (int i = 1; i <= choice; i++) {
        mergeArray[i].printCar(i);
    }
    
    cout << "" << endl; 
    cout << "Merge Sort:" << endl;
    
    for (int i = 1; i <= choice; i++) {
        heapArray[i].printCar(i);
    }
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "Note: ties are not broken in any particular order." << std::endl;
    std::cout << std::endl << "Thank you for using our Used Car Finder!" << std::endl;
    return 0;
}
