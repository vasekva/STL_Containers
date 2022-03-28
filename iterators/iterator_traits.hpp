#ifndef FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

#include "iterator.hpp"

namespace ft
{
	template <class It>
	struct iterator_traits
	{
		typedef typename It::iterator_category	iterator_category;
		typedef typename It::value_type 		value_type;
		typedef typename It::difference_type 	difference_type;
		typedef typename It::pointer 			pointer;
		typedef typename It::reference 			reference;
	};

	template<class T>
	struct iterator_traits<T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef T 							*pointer;
		typedef const T						*const_pointer;
		typedef T                           &reference;
		typedef const T                     &const_reference;

	};

	template<class T>
	struct iterator_traits<const T *>
	{
		typedef random_access_iterator_tag	iterator_category;
		typedef T 							value_type;
		typedef ptrdiff_t 					difference_type;
		typedef T 							*pointer;
		typedef const T						*const_pointer;
		typedef T                           &reference;
		typedef const T                     &const_reference;
	};
}

#endif