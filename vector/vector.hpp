#ifndef COLLECTIONS_VECTOR_HPP
#define COLLECTIONS_VECTOR_HPP

#include <stdexcept>

#include "../algorithm/algorithm.hpp"
#include "../iterators/iterator.hpp"

namespace ft
{
	template<class T, class A>
	class Vector_val
	{
		protected:

			Vector_val(A Al = A()) : Alval(Al) {

			}

			typedef typename A::template
			   rebind<T>::other Alty;
			Alty Alval;

//			typedef std::allocator<T> allocator_type;
//			allocator_type Alval;

			/*  Use function :
			**  Alval.allocate / Alval.deallocate
			**  Alval.destroy
			**  Alval.max_size
			*/

	};

	template<class T, class Alloc = std::allocator <T> >
	class vector : public Vector_val<T, Alloc>
	{
		public:
			typedef Alloc					allocator_type;
			typedef Vector_val<T, Alloc>	_base;
			typedef vector<T, Alloc>		Myt;

			typedef typename Alloc::const_reference		const_reference;
			typedef typename Alloc::reference			reference;
			typedef typename Alloc::const_pointer		const_pointer;
			typedef typename Alloc::pointer				pointer;
			typedef typename Alloc::difference_type		difference_type;
			typedef typename Alloc::size_type			size_type;
			typedef typename Alloc::value_type			value_type;

			typedef pointer			Tptr;
			typedef const_pointer	Ctptr;

			typedef random_access_iterator <value_type, difference_type, Tptr, reference, Tptr, reference>
					iterator;

			typedef random_access_iterator <value_type, difference_type, Ctptr, const_reference, Tptr, reference>
					const_iterator;

			typedef ft::reverse_iterator<iterator>
					reverse_iterator;

			typedef ft::reverse_iterator<const_iterator>
					const_reverse_iterator;

			vector(): _base()
			{
				Allocate_zero(0);
			}

			explicit vector(const allocator_type &Al): _base(Al)
			{
				Allocate_zero(0);
			}

			explicit vector(size_type N) : _base()
			{
				if (Allocate_zero(N))
					Last = Call_construct(First, N, T());
			}

			vector(size_type N, const T &V): _base()
			{
				if (Allocate_zero(N))
					Last = Call_construct(First, N, V);
			}

			vector(size_type N, const T &V, const allocator_type& Al) : _base(Al)
			{
				if (Allocate_zero(N))
					Last = Call_construct(First, N, V);
			}

			vector(const vector& X): _base(X.Alval)
			{
				if (Allocate_zero(X.size()))
					Last = ItCopy(X.begin(), X.end(), First);
			}

			template<class It>
			vector(It First, It Last): _base()
			{
				Construct(First, Last, ft::Iter_cat(First));
			}

			template<class It>
			vector(It First, It Last, const allocator_type& Al) : _base(Al)
			{
				Construct(First, Last, ft::Iter_cat(First));
			}

			template <class It>
			void Construct(It F, It L, Int_iterator_tag)
			{
				size_type N = (size_type)F;
				if (Allocate_zero(N))
					Last = Call_construct(First, N, (T)L);
			}

			template <class It>
			void Construct(It F, It L, input_iterator_tag)
			{
				Allocate_zero(0);
				insert(begin(), F, L);
			}

			~vector()
			{
				Clear();
			}

			Myt &operator=(const vector& X)
			{
				if (this == &X)
					;
				else if (X.size() == 0)
				{
					Clear();
				}
				else if (X.size() <= size())
				{
					Clear();

					pointer Q = ItCopy(X.begin(), X.end(), First);

					Destroy(Q, Last);
					Last = First + X.size();
				}
				else
				{
					Destroy(First, Last);

					_base::Alval.deallocate(First, End - First);

					if (Allocate_zero(X.size()))
					{
						Last = ItCopy(X.begin(), X.end(), First);
					}
				}
				return (*this);
			}

			void reserve(size_type N)
			{
				if (max_size() < N)
					Xlen();
				else if (capacity() < N)
				{
					pointer Q = _base::Alval.allocate(N, (void *)0);

					try
					{
						ItCopy(begin(), end(), Q);
					}
					catch (...)
					{
						_base::Alval.deallocate(Q, N);
						throw ;
					}
					if (First != 0)
					{
						Destroy(First, Last);
						_base::Alval.deallocate(First, End - First);
					}
					End = Q + N;
					Last = Q + size();
					First = Q;
				}
			}

			size_type capacity() const
			{
				if (First == 0)
					return (0);
				return (End - First);
			}

			iterator				begin() { return (iterator(First)); }
			const_iterator			begin() const { return (const_iterator(First)); }

			iterator				end() { return (iterator(Last)); }
			const_iterator			end() const { return (const_iterator(Last)); }

			reverse_iterator		rbegin() { return (reverse_iterator(end())); }
			const_reverse_iterator	rbegin() const { return (const_reverse_iterator(end())); }

			reverse_iterator		rend() { return (reverse_iterator(begin())); }
			const_reverse_iterator	rend() const { return (const_reverse_iterator(begin())); }

			void resize(size_type N) { resize(N, T()); }

			void resize(size_type N, T X)
			{
				if (size() < N)
					insert(end(), N - size(), X);
				else if (N < size())
					erase(begin() + N, end());
			}

			size_type size() const
			{
				if (First == 0)
					return (0);
				return (Last - First);
			}

			size_type		max_size() const { return (_base::Alval.max_size()); }
			bool			empty() const { return (size() == 0); }
			allocator_type	get_allocator() const { return (_base::Alval); }

			const_reference at(size_type N) const
			{
				if (size() <= N)
					Xran();
				return (*(begin() + N));
			}

			reference at(size_type N)
			{
				if (size() <= N)
					Xran();
				return (*(begin() + N));
			}

			const_reference		operator[](size_type N) const { return (*(begin() + N)); }
			reference			operator[](size_type N) { return (*(begin() + N)); }

			reference			front() { return(*begin()); }
			const_reference		front() const { return(*begin()); }

			pointer 			data() { return First; };
			const_pointer		data() const { return First; };

			reference			back() { return(*(end() - 1)); }
			const_reference		back() const { return(*(end() - 1)); }

			void 				push_back(const T& X) { insert(end(), X); }
			void 				pop_back() { erase(end() -1); }

			template <class It>
			void assign(It F, It L)
			{
				Assign(F, L, ft::Iter_cat(F));
			}

			template <class It>
			void Assign(It F, It L, Int_iterator_tag)
			{
				assign((size_type)F, (T)L);
			}

			template <class It>
			void Assign(It F, It L, input_iterator_tag)
			{
				erase(begin(), end());
				insert(begin(), F, L);
			}

			void assign(size_type N, const T& X)
			{
				T Tx = X;

				erase(begin(), end());
				insert(begin(), N, Tx);
			}

			iterator insert(iterator P, const T& X)
			{
				size_type Off;
				if (size() == 0)
					Off = 0;
				else
					Off = P - begin();
				insert(P, (size_type)1, X);
				return (begin() + Off);
			}

			void insert(iterator P, size_type count, const T& X)
			{
				T Tx = X;
				size_type N = capacity();

				if (count == 0)
					;
				else if (max_size() - size() < count)
				{
					Xlen();
				}
				else if (N < size() + count)
				{
					if ((max_size() - N / 2) < N)
						N = 0;
					else
						N = N + N / 2;
					if (N < size() + count)
						N = size() + count;

					//TODO: has been changed from (void *)0 to ...
					pointer S = _base::Alval.allocate(N);
					pointer Q;
					try
					{
						Q = ItCopy(begin(), P, S);
						Q = Call_construct(Q, count, Tx);
						ItCopy(P, end(), Q);
					}
					catch (...)
					{
						Destroy(S, Q);
						_base::Alval.deallocate(S, N);
						throw ;
					}
					if (First != 0)
					{
						Destroy(First, Last);
						_base::Alval.deallocate(First, End - First);
					}
					End = S + N;
					Last = S + size() + count;
					First = S;
				}
				else if ((size_type)(end() - P) < count)
				{
					ItCopy(P, end(), P.base() + count);
					try
					{
						Call_construct(Last, count - (end() - P), Tx);
					}
					catch (...)
					{
						Destroy(P.base() + count, Last + count);
						throw;
					}
					Last += count;
					ft::fill(P, end() - count, Tx);
				}
				else
				{
					iterator Oend = end();
					Last = ItCopy(Oend - count, Oend, Last);
					ft::copy_backward(P, Oend - count, Oend);
					ft::fill(P, P + count, Tx);
				}
			}

			template <class It>
			void insert(iterator Position, It First, It Last)
			{
				Insert(Position, First, Last, ft::Iter_cat(First));
			}

			template <class It>
			void Insert(iterator P, It F, It L, Int_iterator_tag)
			{
				insert(P, (size_type)F, (T)L);
			}

			template <class It>
			void Insert(iterator P, It F, It L, input_iterator_tag)
			{
				for (; F != L; ++F, ++P)
				{
					P = insert(P, *F);
				}
			}

			template <class It>
			void Insert(iterator P, It F, It L, forward_iterator_tag)
			{
				size_type M = 0;

				ft::Distance(F, L, M);
				size_type N = capacity();

				if (M == 0)
					;
				else if (max_size() - size() < M)
				{
					Xlen();
				}
				else if (N < size() + M)
				{
					if ((max_size() - N / 2) < N)
						N = 0;
					else
						N = N + N / 2;

					if (N < size() + M)
						N = size() + M;

					pointer S = _base::Alval.allocate(N, (void *) 0);
					pointer Q;
					try
					{
						Q = ItCopy(begin(), P, S);
						Q = ItCopy(F, L, Q);
						ItCopy(P, end(), Q);
					}
					catch (...)
					{
						Destroy(S, Q);
						_base::Alval.deallocate(S, N);
						throw ;
					}
					if (First != 0)
					{
						Destroy(First, Last);
						_base::Alval.deallocate(First, End - First);
					}
					End = S + N;
					Last = S + size() + M;
					First = S;
				}
				else if ((size_type)(end() - P) < M)
				{
					ItCopy(P, end(), P.base() + M);
					It Mid = F;
					ft::advance(Mid, end() - P);

					try
					{
						ItCopy(Mid, L, Last);
					}
					catch (...)
					{
						Destroy(P.base() + M, Last + M);
						throw;
					}
					Last += M;
					ft::copy(F, Mid, P);
				}
				else if (0 < M)
				{
					iterator Oend = end();
					Last = ItCopy(Oend - M, Oend, Last);
					ft::copy_backward(P, Oend - M, Oend);
					ft::copy(F, L, P);
				}
			}

			iterator erase(iterator P)
			{
				ft::copy(P + 1, end(), P);
				Destroy(Last - 1, Last);
				--Last;
				return (P);
			}

			iterator erase(iterator F, iterator L)
			{
				if (F != L)
				{
					pointer S  = ft::copy(L, end(), F.base());
					Destroy(S, Last);
					Last = S;
				}
				return (F);
			}

			void clear()
			{
				erase(begin(), end());
			}

			void swap(vector &X)
			{
				if (_base::Alval == X.Alval)
				{
					//TODO
					// ДОДЕЛАТЬ! - Fanzil'
					ft::swap(First, X.First);
					ft::swap(Last, X.Last);
					ft::swap(End, X.End);
				}
				else
				{
					vector Tmp = *this;
					*this = X, X = Tmp;
				}
			}
		protected:
			bool Allocate_zero(size_type N)
			{
				First = 0, Last = 0, End = 0;
				if (N == 0)
					return (false);
				else
				{
					//TODO:: has been changed from (N, nullptr) to...
					First = _base::Alval.allocate(N);
					Last = First;
					End = First + N;
					return (true);
				}
			}

			pointer Call_construct(pointer Q, size_type N, const T& X)
			{
				pointer Qs = Q;
				try
				{
					for(; 0 < N; --N, ++Q)
						_base::Alval.construct(Q, X);
				}
				catch (...)
				{
					Destroy(Qs, Q);
					throw;
				}
				return (Q);
			}

			template<class It>
			pointer ItCopy(It First, It Last, pointer Ptr)
			{
				pointer CopyPtr = Ptr;

				try
				{
					for(; First != Last; ++Ptr, ++First)
					{
						_base::Alval.construct(Ptr, *First);
					}
				}
				catch (...)
				{
					Destroy(CopyPtr, Ptr);
					throw;
				}
				return (Ptr);
			}

			void Destroy(pointer F, pointer L)
			{
				for(; F != L; ++F)
					_base::Alval.destroy(F);
			}

			void Clear()
			{
				if (First != 0)
				{
					Destroy(First, Last);
					_base::Alval.deallocate(First, End - First);
				}
				First = 0, Last = 0, End = 0;
			}

			void Xlen() const
			{
				throw std::length_error("vector<T> too long");
			}

			void Xran() const
			{
				throw std::out_of_range("vector<T> subscript");
			}

			pointer First, Last, End;
	};

	template <class T, class allocator_type> inline
	bool operator==(const vector<T, allocator_type> &X, const vector<T, allocator_type> &Y)
	{
		return (X.size() == Y.size() && ft::equal(X.begin(), X.end(), Y.begin()));
	}

	template <class T, class allocator_type> inline
	bool operator!=(const vector<T, allocator_type> &X, const vector<T, allocator_type> &Y)
	{
		return (!(X == Y));
	}

	template <class T, class allocator_type> inline
	bool operator<(const vector<T, allocator_type> &X, const vector<T, allocator_type> &Y)
	{
		return (ft::lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end()));
	}

	template <class T, class allocator_type> inline
	bool operator>(const vector<T, allocator_type> &X, const vector<T, allocator_type> &Y)
	{
		return (Y < X);
	}

	template <class T, class allocator_type> inline
	bool operator>=(const vector<T, allocator_type> &X, const vector<T, allocator_type> &Y)
	{
		return (!(X < Y));
	}

	template <class T, class allocator_type> inline
	bool operator<=(const vector<T, allocator_type> &X, const vector<T, allocator_type> &Y)
	{
		return (!(Y < X));
	}

	template <class T, class allocator_type> inline
	void swap(vector<T, allocator_type> &X, vector<T, allocator_type> &Y)
	{
		X.swap(Y);
	}
}

#endif
