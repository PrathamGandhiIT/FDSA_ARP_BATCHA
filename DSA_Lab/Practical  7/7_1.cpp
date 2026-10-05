#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;

    int queue[100];

    int front = -1;
    int rear = -1;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for(int i = 0; i < operations; i++)
    {
        int choice;

        cout << "\n1. Join";
        cout << "\n2. Serve";
        cout << "\nEnter operation: ";
        cin >> choice;

        if(choice == 1)
        {
            int token;
            cout << "Enter token: ";
            cin >> token;

            if((rear + 1) % n == front)
            {
                cout << "Queue is full." << endl;
            }
            else
            {
                if(front == -1)
                {
                    front = 0;
                }

                rear = (rear + 1) % n;
                queue[rear] = token;

                cout << "Front token: " << queue[front] << endl;
            }
        }

        else if(choice == 2)
        {
            if(front == -1)
            {
                cout << "Queue is empty." << endl;
            }
            else
            {
                cout << "Served token: " << queue[front] << endl;

                if(front == rear)
                {
                    front = -1;
                    rear = -1;
                }
                else
                {
                    front = (front + 1) % n;
                }

                if(front != -1)
                    cout << "Front token: " << queue[front] << endl;
            }
        }

        else
        {
            cout << "Invalid operation." << endl;
        }
    }

    return 0;
}
