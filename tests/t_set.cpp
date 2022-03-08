
#include <assert.h>
#include <iostream>
//#include "../set.hpp"
#include "../set/set.hpp"
#include "../iterators/iterator.hpp"
#include "../utility/colors.hpp"


using namespace std;

void test_set()
{
	typedef allocator<char> Myal;
	typedef less<char> Mypred;
	typedef ft::set<char, Mypred, Myal> Mycont;
	char ch, str1[] = "abc", carr2[] = "def";

	Mycont::key_type        *p_key = (char *)0;
	Mycont::key_compare     *p_komp = (Mypred *)0;
	Mycont::value_type      *p_val = (char *)0;
	Mycont::value_compare   *p_vcomp = (Mypred *)0;
	Mycont::allocator_type  *p_alloc = (Myal *)0;
	Mycont::pointer         p_ptr = (char *)0;
	Mycont::const_pointer   p_cptr = (const char *)0;
	Mycont::reference       p_ref = ch;
	Mycont::const_reference p_cref = (const char &)ch;
	Mycont::size_type       *p_size = (size_t *)0;
	Mycont::difference_type *p_diff = (ptrdiff_t *)0;

    Mycont v0;
    Myal al = v0.get_allocator();
	Mypred pred;
	Mycont v0a(pred), v0b(pred, al);

	assert(v0.empty() && v0.size() == 0);
	assert(v0a.size() == 0 && v0a.get_allocator() == al);
	assert(v0b.size() == 0 && v0b.get_allocator() == al);

	Mycont v1(str1, str1 + 3);
	assert(v1.size() == 3 && *v1.begin() == 'a');

	Mycont v2(str1, str1 + 3, pred);
	assert(v2.size() == 3 && *v2.begin() == 'a');

	Mycont v3(str1, str1 + 3, pred, al);
	assert(v3.size() == 3 && *v3.begin() == 'a');
//
	const Mycont v4(str1, str1 + 3);
	v0 = v4;
	assert(v0.size() == 3 && *v0.begin() == 'a');

//	Mycont::iterator p_it(v1.begin());
//	Mycont::const_iterator p_cit(v4.begin());
//	Mycont::reverse_iterator p_rit(v1.begin());
//	Mycont::const_reverse_iterator p_crit(v4.begin());
//
//	assert(*p_it == 'a' && *--(p_it = v1.end()) == 'c');
//	assert(*p_cit == 'a' && *--(p_cit = v4.end()) == 'c');
//	assert(*p_rit == 'c' && *--(p_rit = v1.rend()) == 'a');
//	assert(*p_crit == 'c' && *--(p_crit = v1.rend()) == 'a');




	cout << GREEN"SUCCESS" << NORM << endl;

}

int main()
{
	test_set();
}