
#include "../vector/vector.hpp"
#include <assert.h>
#include <iostream>

#include "../utility/colors.hpp"

void test_vector()
{

	char ch, carr[] = "abc";

	ft::vector<char>::allocator_type	*p_alloc	= (std::allocator<char> *)0;
	ft::vector<char>::pointer			p_ptr		= (char *)0;
	ft::vector<char>::const_pointer		p_cptr		= (const char *)0;
	ft::vector<char>::reference			p_ref		= ch;
	ft::vector<char>::const_reference	p_cref		= (const char&)ch;
	ft::vector<char>::value_type		*p_val		= (char *)0;
	ft::vector<char>::size_type			*p_size		= (size_t *)0;
	ft::vector<char>::difference_type	*p_diff		= (ptrdiff_t *)0;
	(void) p_cref;
	(void) p_val;
	(void) p_ptr;
	(void) p_diff;
	(void) p_size;
	(void) p_cptr;
	(void) p_alloc;
	(void) p_ref;



	ft::vector<char> v0;
	std::allocator<char> al = v0.get_allocator();

	//конструктор с другим аллокатором
	ft::vector<char> v0a(al);

	assert(v0.empty() && v0.size() == 0);
	assert(v0a.size() == 0 && v0a.get_allocator() == al);

	/* Просто выделили память*/
	ft::vector<char> v1(5);

	/* конструтор с кол вом и и обьектом*/
	ft::vector<char> v1a(6, 'x');

	/* Выделили память и заполнили  и еще задали аллокатор*/
	ft::vector<char> v1b(7, 'y', al);

	assert(v1.size() == 5);

	assert(v1.back() == '\0');

	assert(v1a.size() == 6 && v1a.back() == 'x');
	assert(v1b.size() == 7 && v1b.back() == 'y');

	/* Создали ветор на основе другого вектора */
	ft::vector<char> v2(v1a);
	assert (v2.size() == 6 && v2.front() == 'x');

	/* Создали вектор на итераторов*/
	ft::vector<char> v3(v1a.begin(), v1a.end());
	assert(v3.size() == 6 && v3.front() =='x');

	/* Создали константный вектор на итераторов*/
	const ft::vector<char> v4 (v1a.begin(), v1a.end(), al);
	assert(v4.size() == 6 && v4.back() == 'x');

	/* Приравнивание  opetator=*/
	v0 = v4;
	assert(v0.size() == 6 && v0.at(5) == 'x');
	assert(v0[0] == 'x' && v0.at(5) == 'x');

	/* меняем размер вектора*/
	v0.reserve(12);
	assert(12 <= v0.capacity());

	/* Уменьшаем размер вектора*/
	v0.resize(8);
	assert (v0.size() == 8);
	assert (v0.back() == '\0');

	/* меняем размер вектора*/
	v0.resize(10, 'z');
	assert(v0.size() == 10 && v0.back() == 'z');
	assert(v0.size() <= v0.max_size());

	ft::vector<char>::iterator		 			p_it(v0.begin());
	ft::vector<char>::const_iterator			p_cit(v4.begin());
	ft::vector<char>::reverse_iterator 			p_rit(v0.rbegin());
	ft::vector<char>::const_reverse_iterator 	p_crit(v4.rbegin());

	/* Тест  функций иетраторов */
	assert(*p_it == 'x' && *--(p_it = v0.end()) == 'z');
	assert(*p_cit == 'x' && *--(p_cit = v4.end()) == 'x');

	assert(*p_rit == 'z' && *--(p_rit = v0.rend()) == 'x');
	assert(*p_crit == 'x' && *--(p_crit = v4.rend()) == 'x');

	assert(v0.front() == 'x' && v4.front() == 'x');

	/* смотрим на работу функций*/
	v0.push_back('a');
	assert(v0.back() == 'a');

	v0.pop_back();
	assert(v0.back() == 'z' && v4.back() == 'x');

	v0.assign(v4.begin(), v4.end());
	assert(v0.size() == v4.size());
	assert(v0.front() == v4.front());

	v0.assign(4, 'w');
	assert(v0.size() == 4 && v0.front() == 'w');

	/* Test insert*/

	assert(*v0.insert(v0.begin(), 'a') == 'a');
	assert(v0.front() == 'a' && *++v0.begin() == 'w');
//
	v0.insert(v0.begin(), 2, 'b');
	assert(v0.front() == 'b' && *++v0.begin() == 'b' && *(++(++v0.begin())) == 'a');

	v0.insert(v0.end(), v4.begin(), v4.end());
	assert(v0.back() == v4.back());

	v0.insert(v0.end(), carr, carr + 3);
	assert(v0.back() == 'c');

	v0.erase(v0.begin());
	assert(v0.front() == 'b' && *++v0.begin() == 'a');

	v0.erase(v0.begin(), ++v0.begin());
	assert(v0.front() == 'a');
	v0.clear();
	assert(v0.empty());

	v0.swap(v1);
	assert(!v0.empty() && v1.empty());

	assert(v1 == v1 && v0 > v1);
	assert(v0 != v1 && v1 < v0);
	assert(v0 >= v1 && v1 <= v0 && v1 >= v1 && v0 <= v0);

	ft::vector<ft::pair<int, char>, std::allocator<ft::pair<int, char> > > pair;

	pair.insert(pair.begin(), ft::make_pair(4, 'a'));

	ft::vector<ft::pair<int, char>, std::allocator<ft::pair<int, char> > >::iterator itp(pair.begin());

	assert(itp->first == 4 && itp->second == 'a') ;
//
	try
	{
		pair.at(10);
		std::cerr << "No exception is thrown" << std::endl;
		assert(false);
	}
	catch(...)
	{
		assert(true);
	}
//
	std::cout << GREEN <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;
}


int main()
{
	test_vector();
	std::cout << GREEN <<"SUCCESS testing  <vector>" <<  F_NONE <<std::endl;

	//std::vector<int> v1(8, 10);
	//ft::vector<int> v2(8, 10);
	//ft::vector<int> v3(v2.begin(), v2.end());


	//ft::vector<int> v3(1,2);
	//ft::vector<int> v4(v1.begin(), v1.end());

	return (0);
}