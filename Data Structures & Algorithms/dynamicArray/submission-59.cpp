class DynamicArray {
public:
    int* arr;
    int size=0;
    int cap=0;
    DynamicArray(int capacity):cap(capacity) {
    if (cap>0){    
    arr=new int[cap];  
    }
    }
    ~DynamicArray()
    {
      delete[] arr;
    }

    int get(int i) {
     return arr[i];
    }

    void set(int i, int n) {
     arr[i]=n;
    }

    void pushback(int n) {
     if(cap>size)
     {
        arr[size]=n;
     }
     else
     {
        resize();
        arr[size]=n;
     }   
     size+=1;
    }

    int popback() {
    size--;
    return arr[size];    
    }

    void resize() {
     cap*=2;
     int* temp=new int[cap];
     for(int i{};i<(cap/2);i++)
     {
      temp[i]=arr[i];
     }
     delete[] arr;
     arr=temp;
    }

    int getSize() {
    return size; 
    }

    int getCapacity() {
     return cap;
    }
};
