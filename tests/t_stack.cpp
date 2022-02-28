#include <assert.h>
#include <iostream>
#include <deque>
#include <list>
#include <stack>
#include <vector>

#include "../stack/stack_realization.hpp"

using namespace std;

int main()
{
	typedef allocator<char> Myal;
	typedef deque<char, Myal>	Myimpl;
	typedef list<char, Myal>	Myimpl2;
	typedef vector<char, Myal>	Myimpl3;

	typedef ft::stack<char, Myimpl> Mycont;
	typedef ft::stack<char, Myimpl2> Mycont2;
	typedef ft::stack<char, Myimpl3> Mycont3;

	Mycont::container_type *p_cont = (Myimpl *)0;
	Mycont::value_type *p_val = (char *)0;
	Mycont::size_type *p_size = (size_t *)0;

	Mycont v0(Myimpl(3, 'x')), v0a;
	Mycont2 v1;
	Mycont3 v2;
	assert(v0.size() == 3 && v0.top() == 'x');
	assert(v0a.empty());
	v0 = v0a;
	v0.push('a');
	assert(v0.size() == 1 && v0.top() == 'a');
	v0.push('b');
	assert(v0.size() == 2 && v0.top() == 'b');
	v0.push('c');
	assert(v0.size() == 3 && v0.top() == 'c');
	assert(v0 == v0 && v0a < v0);
	assert(v0 != v0a && v0 > v0a);
	assert(v0a <= v0 && v0 >= v0a);
	v0.pop();
	assert(v0.top() == 'b');
	v0.pop();
	assert(v0.top() == 'a');
	v0.pop();
	assert(v0.empty());

	ft::stack<int> stack;
	ft::stack<int> stack1;

	assert(stack1.empty());
	for (int i = 0; i < 30; i++)
		stack1.push(i);
	assert(!stack1.empty());
	assert(stack1.size() == 30);
	stack.swap(stack1);
	assert(stack1.empty());

	while (!stack.empty()) {
		std::cout << stack.top() << " ";
		stack.pop();
	}
	assert(stack.empty());
	std::cout << std::endl;

	cout << "SUCCESS testing <stack>" << endl;
	return (0);
}