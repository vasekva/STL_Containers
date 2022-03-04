
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Sum
{
	int sum;

	void operator()(int n)
	{
		sum += n;
	}
};

int main()
{
	cout << "123" << endl;
	std::vector<int> v = {1, 2, 3, 4, 5};
	Sum s = std::for_each(v.be, 4, 5);
	cout << s.sum << endl;
}