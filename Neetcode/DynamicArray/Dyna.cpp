class DynamicArray {
private:
    int* arr;
    int length;
    int capacity;

public:
    // Constructor to initialize the dynamic array
    DynamicArray(int capacity) : capacity(capacity), length(0) {
        arr = new int[capacity];
    }

    // Get value at the i-th index
    int get(int i) {
        return arr[i];
    }

    // Set value n at the i-th index
    void set(int i, int n) {
        arr[i] = n;
    }

    // Insert n in the last position of the array
    void pushback(int n) {
        if (length == capacity) {
            resize();
        }
        arr[length] = n;
        length++;
    }

    // Remove the last element in the array
    int popback() {
        if (length > 0) {
            // soft delete the last element
            length--;
        }
        return arr[length];
    }

    // Resize the array
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    // Get the size of the array
    int getSize() {
        return length;
    }

    // Get the capacity of the array
    int getCapacity() {
        return capacity;
    }
};