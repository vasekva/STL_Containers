#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "../set/set.hpp"

#include "../colors.hpp"

#define LINE 	std::cout << "- - - - - - - - - - - - -" << std::endl;
class B
{
public:
	int i;
	char *l;

	B()
		:l(nullptr), i(1)
	{

	};

	B(const int &ex)
	{
		this->i = ex;
		this->l = new char('a');
	};

	B(const B& copy)
	{
		this->l = new char(*(copy.l));
		this->i = copy.i;
	}

	virtual ~B()
	{
		delete this->l;
		this->l = nullptr;
	};

	bool operator < (B &ex) {
		return(this->i < ex.i);
	}

	bool operator < (B *ex) {
		return(this->i < ex->i);
	}
};

class A : public B
{
public:
	A():B(){
	};

	A(const A& copy){
		this->l = new char(*(copy.l));
		this->i = copy.i;
	}

	A(const B* ex){
		this->l = new char(*(ex->l));
		this->i = ex->i;
//		if (ex->i == -1)
//		{
//			throw "Nooo!!\n";
//		}
	};

	A(const B ex){
		this->l = new char(*(ex.l));
		this->i = ex.i;
		if (ex.i == -1)
		{
			throw "Nooo!!\n";
		}
	};

	~A(){
		delete this->l;
		this->l = nullptr;
	};

	bool compare(const A &one, const A& two){
		return (one.i < two.i);
	}

	bool operator < (A &ex) {
		return(this->i < ex.i);
	}

	bool operator < (A *ex) {
		return(this->i < ex->i);
	}

	bool operator < (B *ex) {
		return(this->i < ex->i);
	}

	bool operator<(B &ex) {
		return(this->i < ex.i);
	}
};

bool operator < (const A& one, const A& two){
	return (one.i < two.i);
}


void foo(){
	B* k  = new B(1);
	B* k1 = new B(2);
	B* k2 = new B(3);
	B* k3 = new B(4);
	B* k4 = new B(-1);
	B* k5 = new B(5);


	ft::set<A> v;
	ft::set<B*> v1;
	ft::set<B*>::iterator it;

	v1.insert(k);
	v1.insert(k1);
	v1.insert(k2);
	v1.insert(k3);
	v1.insert(k4);
	v1.insert(k5);

	ft::set<B*>::iterator it2 = v1.begin();
	while (it2 != v1.end())
	{
		std::cout << (*it2)->i << std::endl;
		it2++;
	}
	std::cout << "========================\n" << std::endl;

	std::set<B*> origSet;
	std::set<B*> origSet_v2;

	origSet.insert(k2);
	origSet.insert(k3);
	origSet.insert(k4);
	std::set<B*>::iterator origIter = origSet.begin();
	while (origIter != origSet.end())
	{
		std::cout << (*origIter)->i << std::endl;
		origIter++;
	}

	try {
		origSet_v2.insert(origSet.begin(), origSet.end());
		std::cout << "Гуд" << std::endl;
	}
	catch (...) {
		std::cerr << "Упс" << std::endl;
		//std::cerr << e << std::endl;
	}

	try {
		v.insert(v1.begin(), v1.end());
		std::cout << "Гуд" << std::endl;
	}
	catch (...) {
		std::cerr << "Упс" << std::endl;
		//std::cerr << e << std::endl;
	}

	delete k ;
	delete k1;
	delete k2;
	delete k3;
	delete k4;
	delete k5;
}

int main (void){


	foo();
	ft::set<int> set;
	ft::set<int> new_set;

	for (int i = 0; i < 10; i++)
		set.insert(i);

	// set.print_graph();
	new_set.insert(set.begin(), set.end());

	// std::cout << RED "<---Graph set--->" RESETCOLOR << std::endl;
	// set.print_graph();
	// std::cout << RED "<---Graph set--->" RESETCOLOR << std::endl;

	ft::set<int>::iterator it = set.begin();


	for (;it != set.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	set.clear();
	LINE
	if (set.empty()) {
		std::cout << "Empty!" << std::endl;
		std::cout << "Size == " << set.size() << std::endl;
	}
	LINE
	it = new_set.find(4);
	ft::set<int>::iterator it1 = new_set.find(6);

	std::cout << new_set.size() << std::endl;
	ft::set<int>::size_type size_check = new_set.erase(1);

	std::cout << size_check << std::endl;

	it = new_set.erase(it, it1);

	// std::cout << RED "<---Graph new_set--->" RESETCOLOR << std::endl;
	// new_set.print_graph();

	std::cout << *it << std::endl;

	it = new_set.find(2);

	new_set.erase(it);

	// new_set.print_graph();
	// std::cout << RED "<---Graph new_set--->" RESETCOLOR << std::endl;

	std::cout << "ft::max_size()  " << new_set.max_size() << std::endl;

	std::set<int> sset;

	std::set<int>::allocator_type al(sset.get_allocator());

	std::cout << "std::max_size() " << sset.max_size() << std::endl;
//
//
	ft::set<int>::const_pointer		c_ptr;
	ft::set<int>::allocator_type	alloc(set.get_allocator());
	ft::set<int>::size_type			size;
	ft::set<int>::value_type		value;
	ft::set<int>::const_reference	c_ref = value;
	ft::set<int>::difference_type	dif_t;
	ft::set<int>::key_compare		k_comp;
	ft::set<int>::key_type			key_type;
	ft::set<int>::pointer			pointer;
	ft::set<int>::reference			ref = value;
	ft::set<int>::value_compare		value_compare;

	for (int i = 0; i < 20; i++)
		set.insert(i);

	ft::set<int>::reverse_iterator rit(set.rbegin());
	ft::set<int>::const_reverse_iterator crit(set.rbegin());

	std::cout << GREEN "reverse_iterator" << std::endl;
	for (; rit != set.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << NORM << std::endl;

	std::cout << YELLOW "const_reverse_iterator" << std::endl;
	for (; crit != set.rend(); crit++)
		std::cout << *crit << " ";
	std::cout << NORM << std::endl;

	set.swap(new_set);

	it = set.begin();
	std::cout << YELLOW "After swap" << std::endl;
	for (; it != set.end(); it++)
		std::cout << *it << " ";
	std::cout << NORM << std::endl;

	it = new_set.begin();

	while (it != new_set.end())
		new_set.erase(it++);

	size = set.count(2);
	std::cout << size << std::endl;
	size = set.count(3);
	std::cout << size << std::endl;
	it = set.begin();

	set.erase(9);
	set.insert(11);
	set.insert(23);

	for (; it != set.end(); it++)
		sset.insert(*it);

	std::set<int>::iterator std_it;



	std_it = sset.upper_bound(21);
	it = set.upper_bound(21);
//
//
//	 set.print_graph();
	std::cout << *it << std::endl;
	std::cout << *std_it << std::endl;
//
	std_it = sset.lower_bound(8);
	it = set.lower_bound(8);

	std::cout << *it << std::endl;
	std::cout << *std_it << std::endl;

	std::pair<std::set<int>::iterator, std::set<int>:: iterator> pair_it;
	ft::pair<ft::set<int>::iterator, ft::set<int>:: iterator> pair_ftit;
	pair_it = sset.equal_range(3);

	pair_ftit = set.equal_range(3);

	std::cout << *(pair_it.first) <<  "<--first second--> " << *(pair_it.second)  << std::endl;
	std::cout << *(pair_ftit.first) <<  "<--first second--> " << *(pair_ftit.second)  << std::endl;

	if (set.key_comp()(4, 6))
		std::cout << "!! Yes !!!" << std::endl;

	if (set.value_comp()(4, 6))
		std::cout << "!! Yes !!!" << std::endl;

	ft::set<int> set_n(set.begin(), set.end());
	ft::set<int> set_n1;

	it = set.begin();
	for (; it != set.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
	it = set.begin();
	for (; it != set.end(); it++ )
		set_n1.insert(*it);
//
	// set_n1.print_graph();
//
	// set_n.print_graph();
//

	ft::set<int> n_set(set);

	for (int i = 0; i < 30; i++)
		n_set.insert(i);

	for (int i = -6; i < 0; i++)
		n_set.insert(i);

	for (int i = 4; i < 20; i++)
		n_set.erase(i);
//
//
//	 n_set.print_graph();
//
	it = n_set.begin();
	for (; it != n_set.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	ft::set<int> ex;

	ex = n_set;
	std::set<int> l;

	// ex.print_graph();

	if (ex <=  n_set)
		std::cout << "Yes" << std::endl;
	return (0);


}