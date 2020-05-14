#include <iostream>
#include <cmath>

const int TL = 11;
const int NN = 50;

double WSP[TL];
double TS[NN];
double HS[NN];
int n;

using namespace std;

double metodaSimpsona(double, double, int);
void tworzenieWielomianu();
double wielomian(double);

int main()
{
	int zestawy = 0;
	double epsilon = 0.0000001;
	cin >> zestawy;
	for (int i = 0; i < zestawy; i++)
	{
		int przedzialy;
		tworzenieWielomianu();
		cin >> przedzialy;
		for (int j = 0; j < przedzialy; j++)
		{
			double a, b;
			cin >> a >> b;
			printf("%f\n", metodaSimpsona(a,b,10000));
		}
	}
	return 0;
}

double metodaSimpsona(double a, double b, int n)
{
	int N = 2 * n;
	double H = (b - a) / N;
	double ret = 0;
	for (int i = 1; i < N; i += 2)
	{
		double x = a + i * H;
		ret += 4 * abs(wielomian(x));
	}
	for (int i = 2; i < N - 1; i += 2)
	{
		double x = a + i * H;
		ret += 2 * abs(wielomian(x));
	}
	return (1.0 / 3.0) * H * ((wielomian(a) + wielomian(b)) + ret);
}

void tworzenieWielomianu()
{
	cin >> n;
	for (int i = 0; i < n + 1; i++)
	{
		cin >> WSP[i];
	}
}

double wielomian(double x)
{
	double wynik = 0;

	for (int i = n; i >= 0; i--)
	{
		wynik = wynik * x + WSP[i];
	}
	return wynik;
}