#ifndef COLLECTIONS_XMEMORY_HPP
#define COLLECTIONS_XMEMORY_HPP

#include <new>

#ifndef FARQ

	#define FARQ
	#define PDFT	ptrdiff_t
	#define SIZT	size_t
#endif

namespace ft
{
	template <class T> inline
	T FARQ *Allocate(SIZT N, T FARQ *)
	{
		return ((T FARQ *)operator new(N * sizeof(T)));
	}

	template <class T1, class T2> inline
	void Construct(T1 FARQ *P, const T2 &V)
	{
		new ((void FARQ *)P) T1(V);
	}

	template <class T> inline
	void Destroy(T FARQ *P)
	{
		P->~T();
	}

	template <> inline void Destroy(char FARQ *P) {}
	template <> inline void Destroy(wchar_t FARQ *P) {}

	// TEMPLATE CLASS allocator шаблонный класс allocator
	template <class T>
	class allocator
	{
		public:
			typedef SIZT			size_type;
			typedef PDFT			difference_type;
			typedef T FARQ			*pointer;
			typedef const T FARQ	*const_pointer;
			typedef T FARQ			&reference;
			typedef const T FARQ	&const_reference;
			typedef T				value_type;

			template <class U>
			struct rebind
			{
				typedef allocator<U> other;
			};

			pointer address(reference X) const
			{
				return (&X);
			}

			const_pointer address(const_reference X) const
			{
				return (&X);
			}

			allocator() {}
			allocator(const allocator<T> &) {}

			template <class U>
			allocator(const allocator<U> &) {}

			template <class U>
			allocator<T> &operator=(const allocator<U> &)
			{
				return (*this);
			}

			template <class U>
			pointer allocate(size_type N, const U)
			{
				return (Allocate(N, (pointer)0));
			}

			pointer allocate(size_type N)
			{
				return (Allocate(N, (pointer)0));
			}

			void deallocate(pointer P, size_type)
			{
				operator delete(P);
			}

			void construct(pointer P, const T &V)
			{
				Construct(P, V);
			}

			void destroy(pointer P)
			{
				Destroy(P);
			}

			SIZT max_size() const
			{
				SIZT N = (SIZT) (-1) / sizeof (T);
				return (0 < N ? N : 1);
			}
	};

	// allocator TEMPLATE OPERATORS
	// шаблонные операторы для allocator
	template <class T, class U> inline
	bool operator==(const allocator<T> &, const allocator<U> &)
	{
		return (true);
	}

	template <class T, class U> inline
	bool operator!=(const allocator<T> &, const allocator<U> &)
	{
		return (false);
	}

	// CLASS allocator<void>
	template <>
	class allocator<void>
	{
		public:
			typedef void T;
			typedef T FARQ *pointer;
			typedef const T FARQ *const_pointer;
			typedef T value_type;
			template <class U>
			struct rebind
			{
				typedef allocator<U> other;
			};
			allocator() {}
			allocator(const allocator<T> &) {}
			template<class U>
			allocator(const allocator<U> &) {}
			template<class U>
			allocator<T> &operator=(const allocator<U> &)
			{
				return (*this);
			}
	};
}


#endif //COLLECTIONS_XMEMORY_HPP
