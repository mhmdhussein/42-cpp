#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
	private:
		T * _data;
		size_t _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array & other);
		Array & operator=(const Array & other);
		~Array();

		T & operator[](size_t index);
		const T & operator[](size_t index) const;

		size_t size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

#include "Array.tpp"

#endif
