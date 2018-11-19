#include <vector>
#include <iterator>
#include <iostream>
#include "filter_iterator.h"

template <typename Tobj, typename TContainer, typename TFunc>
class filter_view {
private:
	typename TContainer::iterator begin_;
	typename TContainer::iterator end_;
	TFunc filter_function_;
	FilterIterator<Tobj, TContainer, TFunc> end_iterator_; // end iterator should be unique but begin iterator should be created 
												           // every time from the scratch 
public:
	filter_view(typename TContainer::iterator const & begin, typename TContainer::iterator const & end, TFunc filter_function) :
		begin_(begin), end_(end), filter_function_(filter_function) {
		end_iterator_ = FilterIterator<Tobj, TContainer, TFunc>(end_, end_, filter_function_);
	}

	FilterIterator<Tobj, TContainer, TFunc> begin() {
		std::cout << "FilterIterator::begin()" << std::endl;
		return FilterIterator<Tobj, TContainer, TFunc>(begin_, end_, filter_function_);
	}

	FilterIterator<Tobj, TContainer, TFunc>& end() {
		std::cout << "FilterIterator::end()" << std::endl;
		return end_iterator_;
	}
	
	~filter_view() {}
};