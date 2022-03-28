#include "ft_containers-unit-test/sources/system/system_methods.ipp"
#include UTILITIES"utility.hpp"
#include VECTOR"vector.hpp"

bool iterator_traits_test() {
	std::vector<string> res;
	std::vector<string> res2;
	g_start1 = g_end1 = timer();

//	res.push_back(typeid(std::vector<int>::iterator::iterator_category).name()); // -
//	res.push_back(typeid(std::vector<int>::iterator::iterator_type).name()); // - Pi
	res.push_back(typeid(std::vector<int>::iterator::value_type).name()); // 👍
	res.push_back(typeid(std::vector<int>::iterator::difference_type).name()); // l 👍
	res.push_back(typeid(std::vector<int>::iterator::pointer).name()); // 👍
	res.push_back(typeid(std::vector<int>::iterator::reference).name()); // 👍

//	std::cout << *--res.end() << " ";
//	res.push_back(typeid(std::vector<int>::reverse_iterator::iterator_category).name()); // -
	res.push_back(typeid(std::vector<int>::reverse_iterator::value_type).name()); // 👍
	res.push_back(typeid(std::vector<int>::reverse_iterator::difference_type).name()); // 👍
	res.push_back(typeid(std::vector<int>::reverse_iterator::pointer).name()); // 👍
	res.push_back(typeid(std::vector<int>::reverse_iterator::reference).name()); // 👍



//	res2.push_back(typeid(_vector<int>::iterator::iterator_category).name()); // -
//	res2.push_back(typeid(_vector<int>::iterator::iterator_type).name()); // - i
	res2.push_back(typeid(_vector<int>::iterator::value_type).name()); // 👍
	res2.push_back(typeid(_vector<int>::iterator::difference_type).name()); // i 👍
	res2.push_back(typeid(_vector<int>::iterator::pointer).name()); // 👍
	res2.push_back(typeid(_vector<int>::iterator::reference).name()); // 👍

//	std::cout << *--res.end() << std::endl;
//	res2.push_back(typeid(_vector<int>::reverse_iterator::iterator_category).name()); // -
	res2.push_back(typeid(_vector<int>::reverse_iterator::value_type).name()); // 👍
	res2.push_back(typeid(_vector<int>::reverse_iterator::difference_type).name()); // 👍
	res2.push_back(typeid(_vector<int>::reverse_iterator::pointer).name()); // 👍
	res2.push_back(typeid(_vector<int>::reverse_iterator::reference).name()); // 👍

	return res == res2;
}

int main() {

	exit(run_bool_unit_test("iterators_traits", iterator_traits_test));
}
