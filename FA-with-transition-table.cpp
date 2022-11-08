#include <iostream>;
using namespace std;

int main()
{
    string input;
    int len;

    int final_state = 2;
    int transition_table[3][2] = {
        {1, -1},
        {2, 1},
        {-1, -1}};

    int index = 0, col = 0, state = 0;

    cout << "Enter String: ";
    cin >> input;
    len = input.length();

    while (state != -1 && index != len)
    {
        col = (input[index] == 'a' ? 0 : (input[index] == 'b' ? 1 : -1));

        state = (col == -1 ? -1 : transition_table[state][col]);
        index++;
    }

    if (state == -1 && (input[index - 1] != 'a' && input[index - 1] != 'b'))
    {
        cout << "Invalid Character encounterd, " << input[index - 1] << endl;
    }
    else
    {
        cout << (state == final_state ? "Accepted\n" : "Rejected\n");
    }
}