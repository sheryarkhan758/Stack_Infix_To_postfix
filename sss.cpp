#include <iostream>

#define SIZE 5


using namespace std;

void dispstack(int stack[], int top) {
    if (top == -1) {
        cout << "stack empty\n";
        return;

    }
    cout << "Stack : ";
    for (int i = top; i >= 0; i--) {

        cout << stack[i] << " ";


    }
    cout << endl << top+1 << " spaces of the stack have been used and " << SIZE - 1 -top << " spaces remain\n";


}



void push(int stack[], int& top, int item) {

    if (top == SIZE-1) {
        cout << "Stack full\n";
        return;
    }
    else
    {
        top++;
        stack[top] = item;
    }


    dispstack(stack, top);



}




int pop(int stack[], int& top) {
    if (top == -1) {
        cout << "stack empty\n";
        return 0;
    }


    else {

        int item = stack[top];

        top--;
        cout << item << " has been removed from staxk\n";
        dispstack(stack, top);
        return item;


    }

}


int main()
{
    int top = -1;
    int stack[SIZE];
    bool exit= false;
    int item=0;
    int choice=0;


    do {
        cout << "Stack Menu\n";
        cout << "1.push\n2.pop\n3.display stack\n4.exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the item to push(numeric)\n";
            cin >> item;
            push(stack, top, item);
            break;
        case 2:
            item = pop(stack, top);
            break;
        case 3:
            dispstack(stack, top);
            break;

        case 4:
            exit = true;
            break;

        default:
            break;
        }

    } while (exit == false);
   
}