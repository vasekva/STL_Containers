#ifndef FT_PAIR
# define FT_PAIR

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

		T1 first;
		T2 second;

        pair() : first(), second() {}

        pair(const T1 &X, const T2 &Y) : first(X), second(Y) {}

        template<class V, class W>
        pair(const pair<V, W> &pr)
			: first(pr.first), second(pr.second) {}

		pair& operator=(pair const& p)
		{
			first = p.first;
			second = p.second;
			return (*this);
		}

        void swap(pair<T1, T2> &pr)
        {
            pair<T1, T2> tmp(pr.first, pr.second);
            pr.first = this->first;
            pr.second = this->second;
            this->first = tmp.first;
            this->second = tmp.second;
        }

    };
		
	template <class T, class U>
	pair<T, U> make_pair(T X, U Y)
	{
		return pair<T, U>(X, Y);
	}
    
	template <class T, class U>
	bool  operator==(const pair<T, U> &X, const pair<T, U> &Y)
    {
		return X.first == Y.first && X.second == Y.second;
	}

	template <class T, class U>
	bool operator!=(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return !(X == Y);
	}

	template <class T, class U>
	bool operator<(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return X.first < Y.first || (!(Y.first < X.first) && X.second < Y.second);
	}

	template <class T, class U>
	bool operator>(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return Y < X;
	}

	template <class T, class U>
	bool operator<=(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return !(Y < X);
	}

	template <class T, class U>
	bool operator>=(const pair<T, U> &X, const pair<T, U> &Y)
    {
	    return !(X < Y);
	}

}

#endif