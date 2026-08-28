#include <iostream>

class indexError{

} ;
template <typename T>
class vector {
    private:

    size_t size = 0;
    T* dinamycArray = nullptr;

    public: 

    vector(size_t sizeOfArray){
        size = sizeOfArray;
        dinamycArray = new T[size];
    }
    vector(const vector& other){
        size = other.size;
        dinamycArray = new T [other.size];
        for (size_t i = 0; i < size; ++i){
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
            for (size_t i = 0; i < size; ++i){
            dinamycArray[i] = other.dinamycArray[i];
            }
        }
        else {
            this->resize(other.size);
            for (size_t i = 0; i < size; ++i){
            dinamycArray[i] = other.dinamycArray[i];
            }
        }
        return *this;
    }
    
    T operator[](size_t index) const {

        if(dinamycArray && index < size){
            return dinamycArray[index];
        }

        else {
            throw indexError();
        }
        return 0;
    }
    
    T& operator[](size_t index){
        if(dinamycArray && index < size){
            return dinamycArray[index];
        }
        throw indexError();
    }

    bool operator== ( const vector& other)const {
        if (size != other.size)
            return false;
        for (size_t i = 0; i < size; ++i){
            if (dinamycArray[i] != other.dinamycArray[i])
            return false;
        }
        return true;
    }
    bool operator!= (const vector& other) const {
        return !operator==(other);

    }
    explicit operator bool() const {//contextual conversion to bool
        if(size==0){
            return false;
        }
        return true;
    }

    void resize(size_t newSize){
        T* NewArray = new T[newSize];
        size_t elementsToCopy = (newSize < size) ? newSize : size;
        for (size_t i = 0; i < elementsToCopy; ++i){
            NewArray[i] = dinamycArray[i];
        }
        delete[] dinamycArray;
        dinamycArray = NewArray;
        size = newSize;
    }

    void set(size_t index, const T& newValue) { 
        dinamycArray[index] = newValue;
    }

    T get(size_t index) const{ 
        return dinamycArray[index];
    }
   
    size_t getSize() const {
        return size;
    }
};

int main(){
    vector<int> vint(5);
    vector<double> vdoub(3);


    std::cout << "vint size: " << vint.getSize() << "\n";
    std::cout << "vdoub size: " << vdoub.getSize() << "\n";
    
    return 0;
}