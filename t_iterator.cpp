#include <iostream>
//#include "../STL/utility/utility.hpp"
#include "utility.hpp"
#include "xutility.hpp"

#include <assert.h>

//#include "../STL/iterator/iterator.hpp"
typedef char *PtrIt;

// Тестирование основынх свойств
void takes_ran_tag_stl()
{
	std::random_access_iterator_tag *ran_tag_s	= (std::random_access_iterator_tag *)0;

	std::bidirectional_iterator_tag	*bid_tag_s	= (std::bidirectional_iterator_tag *)0;

	std::forward_iterator_tag 		*fwd_tag_s	= (std::random_access_iterator_tag *)0;

	std::input_iterator_tag 		*in_tag_s	= (std::input_iterator_tag *)0;

	std::output_iterator_tag 		*p_out_tag_s	= (std::output_iterator_tag *)0;

	/* Делаем сокращенное имя */
	typedef std::iterator<std::input_iterator_tag, float, short, float*, float &> Iter;
	
	float f1;

	Iter::iterator_category *it_tag 	= (std::input_iterator_tag *)0;
	Iter::value_type 		*it_vals 	= (float*)0;
	Iter::difference_type	*it_dists 	= (short*)0;
	Iter::pointer			it_ptrs		= (float*)0;
	Iter::reference			it_refs		= f1;

	typedef std::iterator_traits<Iter> Traits;

	Traits::iterator_category	*tr_tags = (std::input_iterator_tag *)0;
	Traits::value_type 			*tr_vals = (float *)0;
	Traits::difference_type		*tr_dists = (short*)0;
	Traits::pointer				tr_ptrs = (float *)0;
	Traits::reference			tr_refs = f1;

	typedef std::iterator_traits<PtrIt> Ptraits;
	char chs;
	Ptraits::value_type 		*ptr_val = (char*)0;
	Ptraits::difference_type 	*ptr_dist = (std::ptrdiff_t *)0;
	Ptraits::pointer 			ptr_ptr = (char*)0;
	Ptraits::reference 			ptr_ref = chs;

	const char *pc = "abcdefg";
	std::advance(pc, 4);
	assert(*pc == 'e');
	std::advance(pc, -1);
	assert(*pc == 'd');

	assert(std::distance(pc, pc + 3) == 3);
}

void takes_ran_tag_ft()
{
	ft::random_access_iterator_tag *ran_tag_s	= (ft::random_access_iterator_tag *)0;
	ft::bidirectional_iterator_tag	*bid_tag_s	= (ft::bidirectional_iterator_tag *)0;
	ft::forward_iterator_tag 		*fwd_tag_s	= (ft::random_access_iterator_tag *)0;
	ft::input_iterator_tag 			*in_tag_s	= (ft::input_iterator_tag *)0;
	ft::output_iterator_tag 		*p_out_tag_s= (ft::output_iterator_tag *)0;

	/* Делаем сокращенное имя */
	typedef ft::iterator<ft::input_iterator_tag, float, short, float*, float &> Iter;
	
	float f1;

	Iter::iterator_category *it_tag 	= (ft::input_iterator_tag *)0;
	Iter::value_type 		*it_vals 	= (float*)0;
	Iter::difference_type	*it_dists 	= (short*)0;
	Iter::pointer			it_ptrs		= (float*)0;
	Iter::reference			it_refs		= f1;

	typedef ft::iterator_traits<Iter> Traits;

	Traits::iterator_category	*tr_tags = (ft::input_iterator_tag *)0;
	Traits::value_type 			*tr_vals = (float *)0;
	Traits::difference_type		*tr_dists = (short*)0;
	Traits::pointer				tr_ptrs = (float *)0;
	Traits::reference			tr_refs = f1;

	typedef ft::iterator_traits<PtrIt> Ptraits;
	char chs;
	Ptraits::value_type 		*ptr_val = (char*)0;
	Ptraits::difference_type 	*ptr_dist = (ptrdiff_t *)0;
	Ptraits::pointer 			ptr_ptr = (char*)0;
	Ptraits::reference 			ptr_ref = chs;
	
	const char *pc = "abcdefg";
	/* Сдвигаем итератор */
	ft::advance(pc, 4);
	assert(*pc == 'e');
	ft::advance(pc, -1);
	assert(*pc == 'd');

	assert(ft::distance(pc, pc + 3) == 3);

}

typedef ft::reverse_iterator<PtrIt> RevIt;
class MyrevIt : public RevIt
{
public:
	MyrevIt (RevIt::iterator_type p) : RevIt(p)
	{

	}

	RevIt::iterator_type get_current() const 
	{
		return (current);
	};

};

void test_revit_ft()
{ 
	char *pc = (char*)"abcdefg" + 3;
	PtrIt pcit(pc);
	RevIt::iterator_type *p_iter = (PtrIt *)0;
	

	RevIt rit0;
	
	/*  Создаем итератор на основе другого итератора */
	RevIt rit(pcit);

	assert(rit.base() == pcit);
	assert(*rit == 'c');
	assert(*++rit == 'b');
	
	assert(*rit++ == 'b' && *rit == 'a');
	assert(*--rit == 'b');
	assert(*rit-- == 'b' && *rit == 'c');
	
	assert(*(rit +=2) == 'a');
	assert(*(rit -= 2) == 'c');
	assert(*(rit + 2) == 'a' && *rit == 'c');
	assert(*(rit - 2) == 'e' && *rit == 'c');
	assert(rit[2] == 'a');
	assert(rit == rit);
	assert(!(rit < rit) && rit < rit + 1);
	assert((rit + 2) - rit == 2);

	MyrevIt myrit(pc);
	assert(myrit.get_current() == pcit);

}

void test_iterator()
{
	takes_ran_tag_ft();
	test_revit_ft();
}

int main()
{

	test_iterator();
	std::cout << GREEN <<"SUCCESS testing  <iterator>" <<  F_NONE <<std::endl;
	return (0);
};