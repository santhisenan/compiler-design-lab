#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class stack
{
  public:
    char s[10];
    int top;
    stack()
    {
        top = 0;
    }

    void push(char ch)
    {
        s[top] = ch;
        top++;
    }

    char pop()
    {
        top--;
        return s[top];
    }
    char to()
    {
        return s[top - 1];
    }

    int size()
    {
        return top;
    }
    void display();
};

void stack::display()
{
    for (int i = 0; i < top; i++)
        cout << s[i];
    cout << "\t";
}

int main()
{
    stack s;
    int ip = 0;
    char i[20], cur;
    // clrscr();
    cout << "\nEnter the input string";
    cin >> i;
    strcat(i, "$");
    s.push('$');
    while (1)
    {
        if (i[ip] != '$')
        {
            s.push(i[ip]);
            s.display();
            for (int f = ip; f < strlen(i); f++)
                cout << i[f];
            cout << "\tshift\n\n";
            ip++;
            if (s.to() == 'i')
            {
                s.pop();
                s.push('E');
                s.display();
                for (int f = ip; f < strlen(i); f++)
                    cout << i[f];
                cout << "\tReduction\n\n";
            }
        }
        else
        {
            if (s.size() == 2)
            {
                if ((s.to() + 1) != ' ')
                {
                    if (s.to() == 'E')
                    {
                        cout << "\taccept";
                        getchar();
                        exit(0);
                    }
                }

                else
                    cout << "\tError:";
                getchar();
                exit(0);
            }
            else
            {
                if (s.pop() == 'E')
                {
                    cur = s.pop();
                    if (cur == '+' || cur == '*' || cur == '-' || cur == '/')
                    {
                        if (s.pop() == 'E')
                        {
                            s.push('E');
                            s.display();
                            for (int f = ip; f < strlen(i); f++)
                                cout << i[f];
                            cout << "\tReduce\n\n";
                        }
                        else
                        {
                            cout << "\nError";
                            getchar();
                            exit(0);
                        }
                    }
                }
            }
        }
    }
    return 0;
}