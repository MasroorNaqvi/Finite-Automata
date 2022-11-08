#include <iostream>
using namespace std;

void State_S1(string input, int index, int len);
void State_S2(string input, int index, int len);
void State_S3(string input, int index, int len);

int main()
{
    string input;
    int len;

    while (true)
    {
        cout << "\nEnter String: ";
        cin >> input;

        if (input == "QUIT")
            break;

        len = input.length();
        State_S1(input, 0, len);
    }
}

void State_S1(string input, int index, int len)
{
    if (index == len)
    {
        cout << "Rejected\n";
    }
    else if (input[index] != 'a' && input[index] != 'b')
    {
        cout << "Rejected\n";
    }
    else
    {
        if (input[index] == 'a')
        {
            index++;
            State_S2(input, index, len);
        }
        else if (input[index] == 'b')
        {
            index++;
            State_S3(input, index, len);
        }
    }
}

void State_S2(string input, int index, int len)
{
    if (index == len)
    {
        cout << "Rejected\n";
    }
    else
    {
        if (input[index] == 'a' || input[index] == 'b')
        {
            index++;
            State_S2(input, index, len);
        }
        else
        {
            cout << "Rejected\n";
        }
    }
}

void State_S3(string input, int index, int len)
{
    if (index == len)
    {
        cout << "Accepted\n";
    }
    else
    {
        if (input[index] == 'a' || input[index] == 'b')
        {
            index++;
            State_S3(input, index, len);
        }
        else
        {
            cout << "Rejected\n";
        }
    }
}