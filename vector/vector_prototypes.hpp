#ifndef     VECTOR_PROTOTYPES
# define    VECTOR_PROTOTYPES

#include <stdlib.h>
#include <memory>
#include "../xutility.hpp"

namespace ft
{

/**
================================
==  TEMPLATE CLASS Vector_val ==
================================
*/
	template <class T, class A>
	class Vector_val
	{
		protected:
			Vector_val(A Al = A()) : Alval(Al) {}
			// TODO: Why is there a std library here??
			// TODO: Replace std::allocator to ft::allocator
			typedef std::allocator<T> allocator_type;
			allocator_type Alval;
	};

/**
================================
==    TEMPLATE CLASS vector   ==
================================
*/
	// TODO: Replace std::allocator to ft::allocator
    template <class T, class Ax = std::allocator<T> >
	class vector : public Vector_val<T, Ax>
    {
		public:
			typedef vector<T, Ax> Myt;
			typedef Vector_val<T, Ax> MyBase;
			typedef typename MyBase::Alty A;
			typedef A allocator_type;
			typedef typename A::size_type	size_type;
			typedef typename A::difference_type	difference_type;
			typedef typename A::pointer			Tptr;
			typedef typename A::const_pointer	Ctptr;
			typedef Tptr pointer;
			typedef Ctptr const_pointer;
			typedef typename A::reference		reference;
			typedef typename A::const_reference	const_reference;
			typedef typename A::value_type		value_type;



//		typedef typename Allocator::value_type		value_type;
//			typedef typename Allocator::allocator_type	allocator_type;
//			typedef typename Allocator::reference		reference;
//			typedef typename Allocator::const_reference	const_reference;
//			typedef typename Allocator::pointer			Tptr;
//			typedef typename Allocator::const_pointer	Ctptr;
//			typedef typename Allocator::difference_type	difference_type;

			/**
			================================
			==         Iterators          ==
			================================
			*/
			// TODO: doesn't have type 'Ptrit' (it's need to do iterators)
			typedef Ptrit<value_type, difference_type,
				Tptr, reference, Tptr, reference> iterator;
			typedef Ptrit<value_type, difference_type,
				Ctptr, const_reference, Tptr, reference> const_iterator;
			// TODO: Replace here and in vector.hpp
			typedef std::reverse_iterator<iterator> reverse_iterator;
			// TODO: Replace here and in vector.hpp
			typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

			/**
			================================
			==        Constructors        ==
			================================
			*/
			vector();
			explicit vector(const A &Al);
			explicit vector(size_type N);
			vector(size_type N, const T &V);
			vector(size_type N, const T &V, const A &Al);
			//TODO: What???
			//TODO vector ?==? Myt
			vector(const Myt &X);
			template <class It>
			vector(It F, It L);
			template <class It>
			vector(It F, It L, const A &Al);

			// TODO: doesn't have type 'Ptrit' (it's need to do iterators)
			template <class It>
			void Construct(It F, It L, Int_iterator_tag);
			template <class It>
			void Construct(It F, It L, input_iterator_tag);

			~vector();

			//TODO vector ?==? Myt
			vector &operator=(const Myt &X);

			/**
			================================
			==           Methods          ==
			================================
			*/
			void reserve(size_type N);
			size_type capacity() const;

			// TODO: doesn't have type 'Ptrit' (it's need to do iterators)
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			void resize(size_type N);
			void resize(size_type N, T X);
			size_type size() const;
			size_type max_size() const;
			bool empty() const;
			A get_allocator() const;

			const_reference at(size_type P) const;
			reference at(size_type P);
			const_reference operator[](size_type P) const;
			reference operator[](size_type P);
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;

			void push_back(const T &X);
			void pop_back();
			template <class It>
			void assign(It F, It L);
			// TODO: doesn't have type 'Ptrit' (it's need to do iterators)
			template <class It>
			void Assign(It F, It L, Int_iterator_tag);
			template <class It>
			void Assign(It F, It L, input_iterator_tag);
			void assign(size_type N, const T &X);
			// TODO: doesn't have type 'Ptrit' (it's need to do iterators)
			iterator insert(iterator P, const T &X);
			void insert(iterator P, size_type M, const T &X);
			template <class It>
			void insert(iterator P, It F, It L);
			template <class It>
			void Insert(iterator P, It F, It L, Int_iterator_tag);
			template <class It>
			void Insert(iterator P, It F, It L, input_iterator_tag);
			template <class It>
			void Insert(iterator P, It F, It L, forward_iterator_tag);

			iterator erase(iterator P);
			iterator erase(iterator F, iterator L);
			void clear();

			//TODO vector ?==? Myt
			bool Eq(const Myt &X) const;
			bool Lt(const Myt &X) const;
			void swap(Myt &X);

		protected:
			bool Buy(size_type N);
			void Clear();
			void Destroy(pointer F, pointer L);
			template <class It>
			pointer Ucopy(It F, It L, pointer Q);
			pointer Ufill(pointer Q, size_type N, const T &X);
			void Xlen() const;
			void Xran() const;
			pointer First, Last, End;
    };

/**
================================
==         Operators          ==
================================
*/

	template <class T, class A> inline
	bool operator==(const vector<T, A> &X, const vector<T, A> &Y);

	template <class T, class A> inline
	bool operator!=(const vector<T, A> &X, const vector<T, A> &Y);

	template <class T, class A> inline
	bool operator<(const vector<T, A> &X, const vector<T, A> &Y);

	template <class T, class A> inline
	bool operator>(const vector<T, A> &X, const vector<T, A> &Y);

	template <class T, class A> inline
	bool operator<=(const vector<T, A> &X, const vector<T, A> &Y);

	template <class T, class A> inline
	bool operator>=(const vector<T, A> &X, const vector<T, A> &Y);

	template <class T, class A> inline
	void swap(const vector<T, A> &X, const vector<T, A> &Y);
}

#endif