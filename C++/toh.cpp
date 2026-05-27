#include <iostream>

using namespace std;

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "moving disk 1 from " << from << " to " << to << "." << endl;
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    cout << "moving disk " << n << " from " << from << " to " << to << "." << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{

    towerOfHanoi(4, 'A', 'B', 'C');

    return 0;
}