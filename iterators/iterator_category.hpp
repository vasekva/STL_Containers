#ifndef FT_ITERATOR_CATEGORY_HPP
# define FT_ITERATOR_CATEGORY_HPP

#include "iterator.hpp"

namespace ft
{
	template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {
     	typedef _Category		iterator_category;
    	typedef _Tp       		value_type;
		typedef _Distance		difference_type;
      	typedef _Pointer		pointer;
      	typedef _Reference		reference;
		typedef _Tp				iterator_type;
    };

	template  <class T, class D, class Pt, class Rt>
	struct Bidit: public iterator<bidirectional_iterator_tag, T, D, Pt, Rt>
	{

	};

	template  <class T, class D, class Pt, class Rt>
	struct Ranit: public iterator<random_access_iterator_tag, T, D, Pt, Rt> 
	{

	};

    struct Outit: public iterator<output_iterator_tag, void ,void ,void ,void>
    {

    };

};

#endif