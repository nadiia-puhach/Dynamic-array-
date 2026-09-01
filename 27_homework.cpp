#include <iostream>

class indexError{

} ;
template <typename T>
class vector {
    private:

    size_t size = 0;
    T* dinamycArray = nullptr;
    size_t capacity = 0;
    public: 

    vector(size_t sizeOfArray){
        size = sizeOfArray;
        dinamycArray = new T[size];
        capacity = sizeOfArray;
    }
    vector(const vector& other){
        size = other.size;
        dinamycArray = new T [other.size];
        for (size_t i = 0; i < size; ++i){
            dinamycArray[i] = other.dinamycArray[i];
        }
        capacity = other.capacity;
    }
    ~vector(){
        delete[] dinamycArray;
    }
    vector& operator=(const vector& other) {
    if (this == &other) return *this;
    if (capacity < other.size) {
        T* newArray = new T[other.size];
        delete[] dinamycArray;
        dinamycArray = newArray;
        capacity = other.size;
    }
    size = other.size;
    for (size_t i = 0; i < size; ++i) {
        dinamycArray[i] = other.dinamycArray[i];
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

    void resize(){
        size_t NewCapacity = (capacity == 0)? 1 : capacity*2;
        T* NewArray = new T[NewCapacity];
        for (size_t i = 0; i < size; ++i){
            NewArray[i] = dinamycArray[i];
        }
        delete[] dinamycArray;
        dinamycArray = NewArray;
        capacity = NewCapacity;
    }

    void push_back (T value)
    {
        if (size == capacity){
            resize();
        }
        dinamycArray[size] = value ;
        ++size;
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
    friend std::ostream& operator<<(std::ostream& out, const vector& vector){
        out << "[";
        for ( size_t i =0; i < vector.size; ++i){
            out << vector.dinamycArray[i];
            if( i + 1 < vector.size)
            {
                out << ",";
            }
        }
        out << "]";
        return out;
    }
    friend std::istream& operator>>(std::istream& in, vector& vector){
        size_t count = 0;
        in >> count;

        for ( size_t i =0; i < count;++i)
        {
            T value;
            in >> value ;
            vector.push_back(value);
        }
        return in;
    }
};
int main(){
    vector<int> v(0);       
    std::cout << "Enter size and then all values: ";
    std::cin >> v;             

    std::cout << "You entered: " << v << "\n";
    std::cout << "Size: " << v.getSize() << "\n";

    return 0;
}