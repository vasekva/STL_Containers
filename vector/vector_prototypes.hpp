#ifndef     VECTOR_PROTOTYPES
# define    VECTOR_PROTOTYPES

#include <stdlib.h>
#include <memory>

namespace ft
{
    template<class T, class Allocator = std::allocator<T> >
    class vector
    {
        typedef typename Allocator::value_type		value_type;
        typedef typename Allocator::allocator_type	allocator_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::difference_type	difference_type;
		typedef typename Allocator::size_type		size_type;

    };
}

#endif