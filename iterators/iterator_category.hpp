#ifndef FT_ITERATOR_CATEGORY
# define FT_ITERATOR_CATEGORY

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
    };

//	template <class T>
//	struct iterator
//	{
//		typedef T											iterator_type;
//		typedef typename	iterator_traits<iterator_type>::value_type					value_type;
//		typedef typename	iterator_traits<iterator_type>::pointer					pointer;
//		typedef typename	iterator_traits<iterator_type>::const_pointer					const_pointer;
//		typedef typename	iterator_traits<iterator_type>::reference					reference;
//		typedef typename	iterator_traits<iterator_type>::const_reference				const_reference;
//		typedef typename	iterator_traits<iterator_type>::difference_type				difference_type;
//		typedef typename 	iterator_traits<iterator_type>::iterator_category				iterator_category;
//	};

//	template <typename T>
//	struct iterator_traits<T *>
//	{
//		public:
//			typedef T											value_type;
//			typedef T*											pointer;
//			typedef const T*										const_pointer;
//			typedef T&											reference;
//			typedef const T&										const_reference;
//			typedef ptrdiff_t										difference_type;
//			typedef std::random_access_iterator_tag								iterator_category;
//	};
//
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