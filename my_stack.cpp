#include<iostream>
using namespace std;

class Stack{
    private:
        int top = -1;
        int arr[5];

    public:
    Stack(){
        for(int i = 0; i<5; i++){
            arr[i]=0;
        }
    }

    bool is_empty(){
        if (top == -1){
            return true;
        }else{
            return false;
        }
    }

    int is_full(){
        if(top == 4)
            return true;
        else
            return false; 
    }

    void push(int value){
        if (is_full()){
            cout<<"OVERFLOW, full stack cannot add into it"<<endl;
        }else{
            arr[top+1] = value;
            top = top+1;
        }      
    }

    int pop(){
        if(is_empty()){
            cout<<"UNDERFLOW, cannot take away an element from an empty stack"<<endl;
            return 0;
        }
        else{
            int copy = arr[top];
            arr[top] = 0;
            top = top -1;
            return copy;
        }
    }

    int peek(int position){
        if (is_empty()){
            cout<<"UNDERFLOW, no element to peek in an empty stack "<<endl;
            return 0;
        }else if (arr[position] == 0)
        {
            cout<<"empty element , no element to peek at the position you specified "<<endl;
            return 0;
        }
        else
            return arr[position];
    }

    int count(){
        return top+1; // count how many elements in the stack. 
    }

    void change(int value, int position){
        if(is_empty()){
            cout<<" UNDERFLOW, cannot change an element because this element does not exist, it's an empty stack"<<endl;
        }else{
            if(arr[position] == 0)
                cout<<" empty element at position: , " <<position<<" the position has no element in the stack"<<endl;
            else
            arr[position] = value;
        }


    }

    void display(){
        for(int i = 4; i>=0; i--){
            cout<<arr[i]<<endl;
        }
    }

};



int main()
{
    Stack s1;
    int option, position, value;
    do
    {
        cout<<" enter an operation you want to perform, select an operation number, enter 0 to exit"<<endl;
        cout<<" 1  push()"<<endl;
        cout<<" 2  pop()"<<endl;
        cout<<" 3  is_empty()"<<endl;
        cout<<" 4  is_full()"<<endl;
        cout<<" 5  peek()"<<endl;
        cout<<" 6  count()"<<endl;
        cout<<" 7  change()"<<endl;
        cout<<" 8  display()"<<endl;
        cout<<" 9  clear screen"<<endl;

        cin>>option;
        switch(option){
            case 1:
                cout<< " enter a value to push in "<<endl;
                cin>>value;
                s1.push(value);
                break;

            case 2:
                cout<< " pop "<<endl;
                cout<< "print out what it popped "<<s1.pop()<<endl;
                break;

            case 3:
                if(s1.is_empty())
                    cout<<"Yes, stack is empty"<<endl;
                else
                    cout<<"No, stack is not empty"<<endl;
                break;                

            case 4:
                if(s1.is_full())
                    cout<<"Yes, stack is full"<<endl;
                else
                    cout<<"No, stack is not full"<<endl;
                break;  

            case 5:
                cout<< " peek "<<endl;
                cout<<"enter at which position(0 to 4) you want to peak: ";
                cin>>position;
                cout<<"element at position : "<<position<<"  is "<<s1.peek(position)<<endl;
                break;

            case 6:
                cout<< " count "<<endl;
                cout<<"number of elements in the stack is : "<<s1.count()<<endl;
                break;  

            case 7:
                cout<< " change "<<endl;
                cout<<"enter a value to change to: "<<endl;
                cin>>value;
                cout<<"enter a position at which the value will be changed : ";
                cin>>position;
                s1.change(value, position);
                break;

            case 8:
                cout<< " display "<<endl;
                s1.display();
                break;

            case 9:
                system("cls");
                break;                  
            default:
                cout<<"enter correct option number"<<endl;

        }
        
    }while(option != 0);
    
    return 0;
}
