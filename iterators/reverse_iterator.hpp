#ifndef FT_REVERSE_ITERATOR
# define FT_REVERSE_ITERATOR

#include "iterator.hpp"

namespace ft
{
	template<class RanIt>
	class reverse_iterator : public iterator<
		typename ft::iterator_traits<RanIt>::iterator_category,
		typename ft::iterator_traits<RanIt>::value_type,
		typename ft::iterator_traits<RanIt>::difference_type,
		typename ft::iterator_traits<RanIt>::pointer,
		typename ft::iterator_traits<RanIt>::reference>
	{
		public:
			typedef reverse_iterator<RanIt> 												Myt;
			typedef RanIt                                                					iterator_type;
			typedef typename iterator_traits<RanIt>::difference_type     					difference_type;
			typedef typename iterator_traits<RanIt>::value_type         					value_type;
			typedef typename iterator_traits<RanIt>::reference           					reference;
			typedef typename iterator_traits<RanIt>::pointer             					pointer;
			typedef typename iterator_traits<RanIt>::iterator_category  					iterator_category;

			reverse_iterator() {};
			explicit reverse_iterator(RanIt x) : current(x) {}

			template <class U>
			reverse_iterator(const reverse_iterator<U> &x)
				: current(x.base()) {}

			RanIt base() const { return (current); }
			reverse_iterator	&operator=(const reverse_iterator &obj)
			{
				if (this != &obj)
					this->current = obj.current;
				return (*this);
			}
			reference operator*() const { RanIt tmp = current; return (*--tmp); }
			pointer operator->() const { return (&**this); }
			Myt &operator++() { --current; return (*this); }
			Myt &operator--() { ++current; return (*this); }
			Myt operator++(int) { Myt tmp = *this; --current; return (tmp); }
			Myt operator--(int) { Myt tmp = *this; ++current; return (tmp); }
			Myt operator+(difference_type N) const { return (Myt(current - N)); }
			Myt operator-(difference_type N) const { return (Myt(current + N)); }
			Myt &operator+=(difference_type N) { current -= N; return (*this); }
			Myt &operator-=(difference_type N) { current += N; return (*this); }
			reference operator[](difference_type N) const { return (*(*this + N)); }

		protected:
			RanIt current;
	};

	template <class RanIt, class RanIt1> inline
	typename reverse_iterator<RanIt>::difference_type operator-(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (Y.base() - X.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator==(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (X.base() == Y.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator!=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (!(X ==Y));
	}

	template <class RanIt, class RanIt1> inline
	bool operator<(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (Y.base() < X.base());
	}

	template <class RanIt, class RanIt1> inline
	bool operator>(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (Y < X);
	}

	template <class RanIt, class RanIt1> inline
	bool operator<=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (!(Y < X));
	}

	template <class RanIt, class RanIt1> inline
	bool operator>=(const reverse_iterator<RanIt> &X, const reverse_iterator<RanIt1> &Y)
	{
		return (!(X < Y));
	}

}

#endif