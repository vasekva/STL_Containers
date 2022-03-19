#include <assert.h>
#include <iostream>
#include <vector>
//#include "../set.hpp"
#include "../map/map.hpp"
#include "../iterators/iterator.hpp"
#include "colors.hpp"


using namespace std;

void test_map()
{
	typedef std::less<char>						Mypred;
	typedef ft::pair<const char, int>			Myval;
	typedef std::allocator<Myval>				Myal;
	typedef ft::map<char, int, Mypred, Myal>	Mycont;


	Myval x, xarr[3], xarr2[3];

	for (int i = 0; i < 3; ++i)
	{
		new (&xarr[i])Myval('a' + i, 1 + i);
		new (&xarr2[i])Myval('d' + i, 4 + i);
	}

	Mycont::key_type		*p_key = (char *)0;
	Mycont::mapped_type		*p_mapped = (int *)0;
	Mycont::key_compare		*p_kcomp = (Mypred *)0;
	Mycont::allocator_type  *p_alloc = (Myal *)0;
	Mycont::value_type      *p_val = (Myval *)0;
	Mycont::value_compare	*p_vcomp = 0;
	Mycont::pointer			p_ptr = (Myval *)0;
	Mycont::const_pointer	p_cptr = (const Myval *)0;
	Mycont::reference		p_ref = x;
	Mycont::const_reference p_cref = (const Myval &)x;
	Mycont::size_type       *p_size = (size_t *)0;
	Mycont::difference_type *p_diff = (ptrdiff_t *)0;

	Mycont v0;
	Myal al = v0.get_allocator();
	Mypred pred;
	Mycont v0a(pred), v0b(pred, al);

	assert(v0.empty() && v0.size() == 0);
	assert(v0a.size() == 0 && v0a.get_allocator() == al);
	assert(v0b.size() == 0 && v0b.get_allocator() == al);

	Mycont v1(xarr, xarr + 3);
	assert(v1.size() == 3 && (*v1.begin()).first == 'a');

	Mycont v2(xarr, xarr + 3, pred);
	assert(v2.size() == 3 && (*v2.begin()).first == 'a');

	Mycont v3(xarr, xarr + 3, pred, al);
	assert(v3.size() == 3 && (*v3.begin()).first == 'a');

	const Mycont v4(xarr, xarr + 3);
	assert(v4.size() == 3 && (*v4.begin()).first == 'a');
	v0 = v4;
	assert(v0.size() == 3 && (*v0.begin()).first == 'a');

	assert(v0.size() <= v0.max_size());

	Mycont::iterator p_it(v1.begin());
	Mycont::const_iterator p_cit(v4.begin());
	Mycont::reverse_iterator p_rit(v1.rbegin());
	Mycont::const_reverse_iterator p_crit(v4.rbegin());
	assert((*p_it).first == 'a' && (*p_it).second == 1
		&& (*--(p_it = v1.end())).first == 'c');

	assert((*p_cit).first == 'a'
		&& (*--(p_cit = v4.end())).first == 'c');

	assert((*p_rit).first == 'c' && (*p_rit).second == 3
		&& (*--(p_rit = v1.rend())).first == 'a');

	assert((*p_crit).first == 'c'
		&& (*--(p_crit = v4.rend())).first == 'a');

	v0.clear();
	ft::pair<Mycont::iterator, bool> pib = v0.insert(Myval('d', 4));
	assert((*pib.first).first == 'd' && pib.second);
	assert((*--v0.end()).first == 'd');
	pib = v0.insert(Myval('d', 5));
	assert((*pib.first).first == 'd'
		&& (*pib.first).second == 4 && !pib.second);
	assert((*v0.insert(v0.begin(), Myval('e', 5))).first == 'e');

	v0.insert(xarr, xarr + 3);
	assert(v0.size() == 5 && (*v0.begin()).first == 'a');

	v0.insert(xarr2, xarr2 + 3);
	assert(v0.size() == 6 && (*--v0.end()).first == 'f');
	assert(v0['c'] == 3);

	assert((*v0.erase(v0.begin())).first == 'b'
		&& v0.size() == 5);
	assert((*v0.erase(v0.begin(), ++v0.begin())).first == 'c'
		   && v0.size() == 4);
	assert(v0.erase('x') == 0 && v0.erase('e') == 1);

	v0.clear();
	assert(v0.empty());
	v0.swap(v1);
	assert(!v0.empty() && v1.empty());
	ft::swap(v0, v1);
	assert(v0.empty() && !v1.empty());
	assert(v1 == v1 && v0 < v1);
	assert(v0 != v1 && v1 > v0);
	assert(v0 <= v1 && v1 >= v0);

	assert(v0.key_comp()('a', 'c') && !v0.key_comp()('a', 'a'));
	assert(v0.value_comp()(Myval ('a', 0), Myval('e', 0))
		&& !v0.value_comp()(Myval ('a', 0), Myval('a', 1)));
	assert((*v4.find('b')).first == 'b');
	assert(v4.count('x') == 0 && v4.count('b') == 1);
	assert((*v4.lower_bound('a')).first == 'a');
	assert((*v4.upper_bound('a')).first == 'b');
	ft::pair<Mycont::const_iterator, Mycont::const_iterator> pcc
		= v4.equal_range('a');
	assert((*pcc.first).first == 'a' && (*pcc.second).first == 'b');

}

int main()
{
	test_map();
	cout << GREEN << "SUCCESS" << NORM << endl;
}