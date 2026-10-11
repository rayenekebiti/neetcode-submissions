struct node
{
    int data=0;
    node* next=nullptr;
};
class LinkedList {
public:
    int size=0;
    node* head=nullptr;
    node* tail=nullptr;
    LinkedList()=default;
    int get(int index) {
    if(index>=size||size==0) return -1;     
    node* temp=head;    
    for(int i{};i<index;i++)
    {
     if(temp->next==nullptr) break;   
     temp=temp->next;
    }
    return temp->data;
    }

    void insertHead(int val) {
     node* temp= new node{val,head};
     if(head==nullptr) tail=temp;
     head=temp;
     size++;
     }
    void insertTail(int val) {
     node* temp=new node{val,nullptr};
     if(size==0){
        head=temp;
        tail=temp;
        size++;
        return;
        }
     tail->next=temp;
     tail=temp;
     size++;
    }

    bool remove(int index) {
        if(index>=size||index<0) return false;
        if(index==0) 
        {
        node* temp=head;    
        head=head->next;    
        delete temp;
        if(size==1) tail=nullptr;
        size--;
        return true;
        }
        node* temp=head->next;
        node* relink=head;
        for(int i=1;i<size;i++){
            if(i==index)
            {
             relink->next=temp->next;
             delete temp;
             if(i==size-1) tail=relink;
             size--;
             break;
            }
            relink=relink->next;
            temp=temp->next;
        }
        return true;
    }

    vector<int> getValues() {
        vector<int> vals;
        node* temp=head;
        for(int i{};i<size;i++)
        {
         vals.push_back(temp->data);
         temp=temp->next;
        }
        return vals;
    }
};
