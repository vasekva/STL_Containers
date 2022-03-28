#ifndef FT_MIN_HPP
# define FT_MIN_HPP

namespace ft
{
	template <class T> inline
	const T &min(const T &X, const T &Y)
	{
		return (Y < X ? Y : X);
	}

	template <class T, class Pr> inline
	const T &min(const T &X, const T &Y, Pr P)
	{
		return (P(Y,X) ? Y : X);
	}
};

#endif