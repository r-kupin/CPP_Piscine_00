// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //
/*
		Google C++ Style Guide

		Structs vs. Pairs and Tuples

	- Prefer to use a struct instead of a pair or a tuple whenever the
		elements can have meaningful names.
		While using pairs and tuples can avoid the need to define a custom type,
		potentially saving work when writing code, a meaningful field name will
		almost always be much clearer when reading code than .first, .second, or
		std::get<X>. While C++14's introduction of std::get<Type> to access a
		tuple element by type rather than index (when the type is unique) can
		sometimes partially mitigate this, a field name is usually substantially
		clearer and more informative than a type.
		Pairs and tuples may be appropriate in generic code where there are not
		specific meanings for the elements of the pair or tuple. Their use may
		also be required in order to interoperate with existing code or APIs.

		Local variable type deduction

	- For local variables, you can use type deduction to make the code clearer
 		by eliminating type information that is obvious or irrelevant, so that
 		the reader can focus on the meaningful parts of the code:

		std::unique_ptr<WidgetWithBells> widget_ptr =
    					std::make_unique<WidgetWithBells>(arg1, arg2);
		absl::flat_hash_map<std::string,
                    std::unique_ptr<WidgetWithBells>>::const_iterator it =
                    											my_map_.find(key);
		std::array<int, 6> numbers = {4, 8, 15, 16, 23, 42};
						===========================
		auto widget_ptr = std::make_unique<WidgetWithBells>(arg1, arg2);
		auto it = my_map_.find(key);
		std::array numbers = {4, 8, 15, 16, 23, 42};

		Types sometimes contain a mixture of useful information and boilerplate,
		such as it in the example above: it's obvious that the type is an
		iterator, and in many contexts the container type and even the key type
		aren't relevant, but the type of the values is probably useful. In such
		situations, it's often possible to define local variables with explicit
		types that convey the relevant information:

			if (auto it = my_map_.find(key); it != my_map_.end()) {
  				WidgetWithBells& widget = *it->second;
  				// Do stuff with `widget`
			}

		If the type is a template instance, and the parameters are boilerplate
		but the template itself is informative, you can use class template
		argument deduction to suppress the boilerplate. However, cases where
		this actually provides a meaningful benefit are quite rare. Note that
		class template argument deduction is also subject to a separate style rule.

		Do not use decltype(auto) if a simpler option will work, because it's a
		fairly obscure feature, so it has a high cost in code clarity.

		Description

	The underlying madness can be broken down to some principal blocs:
	1. Aliasing
	2. Creating test arrays - first interaction with Account.class
		- $amounts, $d and $w are fof initialization purpouses only as well
			as the _size variables
		- $accounts vector contains instances to test. If you create a data
			structure tat contains objects, this objects are created
			automatically. Here's a description of the particular vector
			constructor:
				@brief  Builds a %vector from a range.
				@param  __first  An input iterator.
				@param  __last  An input iterator.

				Create a %vector consisting of copies of the elements from
				[first,last).

					vector(_InputIterator __first, _InputIterator __last)

				If the iterators are forward, bidirectional, or
				random-access, then this will call the elements' copy
				constructor N times (where N is distance(first,last)) and do
				no memory reallocation.
		- Making iterators for the vector.
			An iterator is an object (like a pointer) that points to an
			element inside the container. We can use iterators to move
			through the contents of the container. They can be visualized as
			something similar to a pointer pointing to some location and we
			can access the content at that particular location using them.
			It is a good practice to use iterators and not pointers, because
			they are integrated in a lot of algorithms of interaction with
			standard data structures. Vector supports Random-Access
			Iterators, which have a maximum access level.
			Later on, they will be used with for_each() loop
			It is convenient to use AUTO type deduction for iterators!
	3. Iterating the vector with for_each() loop which applies a function
		to every element of a sequence.

		  @param  __first  An input iterator.
		  @param  __last   An input iterator.
		  @param  __f      A unary function object.

   		for_each(_InputIterator __first, _InputIterator __last,
   			_Function __f)

		From iterator begin to end. In a code below, we just calling a
		display() function of each account.
		fore_ach() as the last parameter accepts a unary function object.

			template <typename ArgumentType, typename ResultType>
					struct unary_function;

*deprecated* std::unary_function is a base class for creating function objects
		with one argument - which means the object that overrides operator()
		with 1 argument, for example:

		struct less_than_7 : std::unary_function<int, bool> {
   			bool operator()(int i) const { return i < 7; }
		};

*deprecated* std::mem_fun_ref() - Creates a member function wrapper object,
			deducing the target type from the template arguments.
			The wrapper object expects a reference to an object of type T as the
			first parameter to its operator().

			    mem_fun_ref(_Ret (_Tp::*__f)() const);

		Function pointer is passed using &-syntax like in a plain C.
	4. Iterating using the pair object by vectors of Accounts and dep / with int
		vectors.
		Using Pair and Tuple is quite a common practice, see style guide for
		more
*/
#include <vector>
#include <algorithm>
#include <functional>
#include "Account.class.hpp"

int		main() {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator 	acc_begin	= accounts.begin();
	accounts_t::iterator 	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator 	dep_begin	= deposits.begin();
	ints_t::iterator 	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator 	wit_begin	= withdrawals.begin();
	ints_t::iterator 	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
