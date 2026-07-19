#include <iostream>

class vector {
    private:

    unsigned int size = 0;
    int* dinamycArray = nullptr;

    public: 

    vector(int sizeOfArray){
        size = sizeOfArray;
        dinamycArray = new int[size];
    }

    void resize(int newSize){
        int* NewArray = new int[newSize];
        unsigned int elementsToCopy = (newSize < size) ? newSize : size;
        for (unsigned int i = 0; i < elementsToCopy; ++i){
            NewArray[i] = dinamycArray[i];
        }
        delete[] dinamycArray;
        dinamycArray = NewArray;
        size = newSize;
    }

    void set(int index, int newValue) { 
        dinamycArray[index] = newValue;
    }

    int get(int index) const{ 
        return dinamycArray[index];
    }

    ~vector(){
        delete[] dinamycArray;
    }

};

int main(){
    int size = 0;
    int value = 0;

    std::cout << "How many elements are in your array? ";
    std::cin >> size;
    vector arr(size);

    std::cout << "\nEnter your array: ";
    for (int i = 0;i < size ; ++i){
        std::cin >> value;
        arr.set(i,value);
    }
    std::cout << "How much do you want to increase the array size?";
    int newSize = 0;
    std::cin >> newSize;
    arr.resize(newSize);
    if (newSize > size){
        std::cout << "Enter new elements:";
        for (int i = size; i < newSize; ++i){
            std::cin >> value;
            arr.set(i,value);
        }
    }
    std::cout << "This is your new array: ";
    for (int i = 0; i < newSize; ++i){
        std::cout << arr.get(i) << " ";
    }
    return 0;
}