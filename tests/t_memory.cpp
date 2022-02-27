#include <iostream>
#include "../xmemory.hpp"

static size_t cnt;

class MyInt
{
	public:
		MyInt(int x): val(x)
		{
			++cnt;
		}

		MyInt(const MyInt &x) : val(x.val)
		{
			++cnt;
		}

		~MyInt()
		{
			--cnt;
		}

		int get_val() const
		{
			return val;
		}
	private:
		int val;
};

typedef ft::allocator<float> Myal;

Myal get_al()
{
	return Myal();
}

void test_alloc()
{
	float f1;
	Myal::size_type *p_size = (size_t *)0;
	Myal::difference_type *p_val = (ptrdiff_t *)0;
	Myal::pointer *p_ptr = (float **)0;
	Myal::const_pointer *p_cptr = (const float **)0;
	Myal::reference  p_ref = f1;
	Myal::const_reference p_cref = (const float &)f1;
	Myal::value_type *p_dist = (float *)0;
	Myal::rebind<int>::other::pointer *p_iptr = (int **)0;
	Myal al0 = get_al();
	Myal al(al0);

	Myal::allocator<void>::pointer *pv_ptr = (void **)0;
	Myal::allocator<void>::const_pointer *pv_cptr = (const void **)0;
	Myal::rebind<int>::other::pointer *pv_iptr = (int **)0;

	ft::allocator<void> alv0,alv(alv0);
	alv = alv0;

	float *pf1 = al0.address(f1);
	assert(pf1 == &f1);

	pf1 = al.allocate(3, 0);
	al.construct(&pf1[2], 2.0F);
	assert(pf1[2] == 2.0F);

	al.destroy(pf1);

	al.deallocate(pf1,1);

	assert(0 < al0.max_size());
	assert(al0 == al);
//	al0.deallocate(pf1,1);
//	al0.destroy(pf1);
}

int main()
{
	test_alloc();
	std::cout  <<"Success testing <memory> \n";

	return (0);
}