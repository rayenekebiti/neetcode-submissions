class DynamicArray {
public:
    int capacity=0;
    int* array;
    int size=0;
    DynamicArray(int capacity):capacity(capacity){
        if(capacity!=0){
        array= new int[capacity];
        }
    }

    int get(int i) {
     return array[i];
    }

    void set(int i, int n) {
     array[i]=n;
    }

    void pushback(int n) {
    if(size==capacity) resize();   
     array[size]=n;
     size++;
    }

    int popback() {   
     if(size>0)
     {
        size--;
     }
     return array[size];
    }

    void resize() {
      (capacity!=0)?capacity*=2:capacity++;
      int* NewArray=new int[capacity];
      for(int i{};i<size;i++)
      {
       NewArray[i]=array[i];
      }
      delete[] array;
      array=NewArray;
    }

    int getSize() {
     return size;
    }

    int getCapacity() {
     return capacity;
    }
    ~DynamicArray()
    {
        delete[] array;
    }
};