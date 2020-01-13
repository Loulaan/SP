#pragma once
#include <iostream>
#include <iterator>
#include <ostream>


template <class _Ty, unsigned int N = 1, class _Elem = char>
class nIterator : public std::iterator<std::output_iterator_tag, _Ty> {
public:
	using char_type = _Elem;
	using ostream_type = std::ostream;

	nIterator(ostream_type& _Ostr, const _Elem* const _Delim = nullptr)
		: _Mydelim(_Delim), _Myostr(std::addressof(_Ostr)), i(0), first(true) { // construct from output stream and delimiter
	}

	nIterator& operator=(const _Ty& _Val) { // insert value into output stream, followed by delimiter
		if ((i) % N == 0) {
			if (!first) {
				if (_Mydelim) {
					*_Myostr << _Mydelim;
				}
			}
			else {
				first = !first;
			}
			*_Myostr << _Val;
		}
		++i;
		return *this;
	}

	nIterator& operator*() { // pretend to return designated value
		return *this;
	}

	nIterator& operator++() { // pretend to preincrement
		return *this;
	}

	nIterator& operator++(int) { // pretend to postincrement
		return *this;
	}

protected:
	const _Elem* _Mydelim; // pointer to delimiter string (NB: not freed)
	ostream_type* _Myostr; // pointer to output stream
	unsigned int i; // integer variable to output N-th element 
	bool first; // bool for ouptut the first element
};