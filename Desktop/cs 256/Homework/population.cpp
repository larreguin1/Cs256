#include <iostream>
using namespace std;

int main()
{
    /*ss=starting size;
    N = new size;
    P = previous size;
    B = birth rate;
    D = death rate; */
    int y,i;
    float ss, N, B, D, P;

    cout << "The starting size of a population: ";
    cin >> ss;
    cout << "The annual birth rate: ";
    cin >> B;
    cout << "The annual death rate: ";
    cin >> D;
    cout << "The number of years to display: ";
    cin >> y;

    N = ss;

    for(i=0;i<y;i++)
    {
        P = N;
        N = P + (B*P) - (D*P);

        cout << "Population at the end of " << i+1 << " year is " << N << endl;
    }

    return 0;
}
