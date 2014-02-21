#include <iostream>
#include <memory>
#include <cstring>
#include <type_traits>
#include <boost/timer/timer.hpp>

using namespace std;

namespace nonOptimized
{
	template<typename T1, typename T2>
	inline T2 copy (T1 first, T1 last, T2 out)
	{
		while (first != last)
		{
			*out = *first;
			++out;
			++first;
		}

		return out;
	}
}

namespace optimized
{
	template<bool b>
	struct copier
	{
		template <typename T1, typename T2>
		static T2 do_copy (T1 first, T1 last, T2 out)
		{
			while (first != last)
			{
				*out = *first;
				++out;
				++first;
			}

			return out;
		}
	};


	template<>
	struct copier<true>
	{
		template<typename T1, typename T2>
		static T2* do_copy (T1 *first, T1 *last, T2 *out)
		{
			memcpy (out, first, (last-first)*sizeof(T2));
			return out+(last-first);
		}
	};

	template<typename T1, typename T2>
	inline T2 copy (T1 first, T1 last, T2 out)
	{
		typedef typename remove_cv<typename iterator_traits<T1>::value_type>::type t1_type;
		typedef typename remove_cv<typename iterator_traits<T2>::value_type>::type t2_type;

		static const bool use_optimized = is_same<t1_type,t2_type>::value &&
						is_pointer<T1>::value && is_pointer<T2>::value
						&& is_trivial<t1_type>::value;
		return copier<use_optimized>::do_copy(first, last, out);
	}
}

// Test data
const int arraySize = 1000;
int iArray_[arraySize] = {0,};
const int ciArray_[arraySize] = {0,};

// since arrays aren't iterators we define a set of pointer
// aliases into the arrays (otherwise the compiler is entitled
// to deduce the type passed to the template functions as
// T (&)[N] rather than T*).
int* iArray = iArray_;
const int* ciArray = ciArray_;

const int iterCount = 1000000;

int 
main ()
{
	// cache load:
	optimized::copy(ciArray, ciArray + arraySize, iArray);
	
	cout << "Measuring time using non optimized copy" << endl;
	// Time take for optimized copy
	{
		boost::timer::auto_cpu_timer t;
		
		for(int i = 0; i < iterCount; ++i)
			nonOptimized::copy(ciArray, ciArray + arraySize, iArray);
	}
	
	// cache load:
	optimized::copy(ciArray, ciArray + arraySize, iArray);

	cout << "Measuring time using optimized copy" << endl;
	// Time take for nonOptimized copy
	{
		boost::timer::auto_cpu_timer t;
		
		for(int i = 0; i < iterCount; ++i)
			optimized::copy(ciArray, ciArray + arraySize, iArray);
	}

	return 0;	
}
