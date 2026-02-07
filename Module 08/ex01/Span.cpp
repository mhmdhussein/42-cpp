#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span & other)
	: _maxSize(other._maxSize), _numbers(other._numbers) {}

Span & Span::operator=(const Span & other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(value);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());

	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < tmp.size(); i++)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

const char * Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

const char * Span::NoSpanException::what() const throw()
{
	return "Not enough numbers to find a span";
}
