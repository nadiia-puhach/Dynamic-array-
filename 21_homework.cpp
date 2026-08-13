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
    vector(const vector& other){
        size = other.size;
        dinamycArray = new int[size];
        for (unsigned int i = 0; i < size; ++i){
            dinamycArray[i] = other.dinamycArray[i];
        }
    }
    ~vector(){
        delete[] dinamycArray;
    }
    vector& operator= (const vector& other){
        if (this == &other){
            return *this;
        }
        else if (size == other.size){
            for (unsigned int i = 0; i < size; ++i){
            dinamycArray[i] = other.dinamycArray[i];
            }
        }
        else {
            this->resize(other.size);
            for (unsigned int i = 0; i < size; ++i){
            dinamycArray[i] = other.dinamycArray[i];
            }
        }
        return *this;
    }
    
    int operator[](unsigned index) const {

        if(dinamycArray && index < size){
            return dinamycArray[index];
        }

        else {
            std::cout << "Error! No such element" << std::endl;
        }
        return 0;
    }
    
    int& operator[](unsigned index){
        if(dinamycArray && index < size){
            return dinamycArray[index];
        }
    }

    bool operator== ( const vector& other)const {
        if (size != other.size)
            return false;
        for (int i = 0; i < size; ++i){
            if (dinamycArray[i] != other.dinamycArray[i])
            return false;
        }
        return true;
    }
    bool operator!= (const vector& other) const {
        return !operator==(other);

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
   
    int getSize() const {
        return size;
    }
};

int main(){
    int size = 0;
    int value = 0;

    std::cout << "How many elements are in your array? ";
    std::cin >> size;
    vector first(size);

    std::cout << "\nEnter your array: ";
    for (int i = 0;i < first.getSize() ; ++i){
        std::cin >> value;
        first.set(i,value);
    }
    std::cout << "How much do you want to increase the array size? ";
    int newSize = 0;
    std::cin >> newSize;
    first.resize(newSize);
    if (newSize > size){
        std::cout << "Enter new elements: ";
        for (int i = size; i < newSize; ++i){
            std::cin >> value;
            first.set(i,value);
        }
    }
    std::cout << "\nThis is your new array: ";
    for (int i = 0; i < first.getSize(); ++i){
        std::cout << first.get(i) << " ";
    }

    vector second(first);
    std::cout << "\n(second (first)) \nThis is your second array: ";
    for (int i = 0; i < second.getSize(); ++i){
        std::cout << second.get(i) << " ";
    }

    std::cout << "\nHow many elements are in your THIRD array? ";
    std::cin >> size;
    vector third(size);

    std::cout << "\nEnter your array: ";
    for (int i = 0;i < third.getSize() ; ++i){
        std::cin >> value;
        third.set(i,value);
    }
    std::cout << "\nThis is your third array: ";
    for (int i = 0; i <  third.getSize(); ++i){
        std::cout << third.get(i) << " ";
    }
    third = second;
    std::cout << "\n(third=second)\nThis is your third array after changing: ";
    for (int i = 0; i <  third.getSize(); ++i){
        std::cout << third.get(i) << " ";
    }
    std::cout << "\nFifth element in third array is: " << third[5] << std::endl;
    std::cout << "\nIs second array = third array ?" << ((second == third)? " True" : " False" )<< std::endl;
    return 0;
}