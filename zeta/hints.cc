#include <array>
using namespace std;

//Boost Multiprecision gives you access to the "cpp_int" type which is an infinite precision integer
//cpp_int x = 10000000;
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

//This header file gives you access to a really fast primality test
//You will have to use your internet search skills to figure out how to use it
#include <boost/multiprecision/miller_rabin.hpp> 

//This is the table from https://en.wikipedia.org/wiki/Prime-counting_function
//Copied into an array so that you can look up the values to speed up your code
//If you can figure out how to use it
const array<cpp_int,21> cache = {
	0,
	4,
	25,
	168,
	1'229,
	9'592,
	78'498,
	664'579,
	5'761'455,
	50'847'534,
	455'052'511,
	4'118'054'813,
	37'607'912'018,
	346'065'536'839,
	3'204'941'750'802,
	29'844'570'422'669,
	279'238'341'033'925,
	2'623'557'157'654'233,
	24'739'954'287'740'860,
	234'057'667'276'344'607,
	2'220'819'602'560'918'840
};
