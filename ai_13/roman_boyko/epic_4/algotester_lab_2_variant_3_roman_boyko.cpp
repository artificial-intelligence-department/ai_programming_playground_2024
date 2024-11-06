#include <iostream>
using namespace std;
void Drones(int n, int arr[]);
int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 1; i < N + 1; i++)
    {
        cin >> arr[i];
    }
    Drones(N, arr);
}
void Drones(int n, int arr[])
{
    int leftDrone = 1;
    int rightDrone = n;
    while (true)
    {
        if (leftDrone == rightDrone)
        {
            cout << leftDrone << " " << rightDrone << endl;
            cout << "Collision" << endl;
            return;
        }
        else if (leftDrone + 1 == rightDrone)
        {
            cout << leftDrone << " " << rightDrone << endl;
            cout << "Stopped" << endl;
            return;
        }
        else if (leftDrone > rightDrone)
        {
            cout << leftDrone << " " << rightDrone << endl;
            cout << "Miss" << endl;
            return;
        }
        leftDrone += arr[leftDrone];
        rightDrone -= arr[rightDrone];
    }
}