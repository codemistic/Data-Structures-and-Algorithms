#include <bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, char from_rod, char aux_rod, char to_rod)
{


	if (n == 1)
		cout << "Move a rod from the top of " << from_rod << " to the top of " << to_rod << '\n';
	else
	{
		tower_of_hanoi(n - 1, from_rod, to_rod, aux_rod);
		tower_of_hanoi(1, from_rod, aux_rod, to_rod);
		tower_of_hanoi(n - 1, aux_rod, from_rod, to_rod);
	}
}

int main()
{

	int n;
	cin >> n;				
	tower_of_hanoi(n, 'A', 'B', 'C');

	return 0;
}