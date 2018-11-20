#include <vector>
#include <iterator>
#include <iostream>
#include "transform_iterator.h"

template <typename TIterator, typename Tout>
class transform_view {
private:
	TIterator begin_;
	TIterator end_;
	Tout transform_function_;
	TransformIterator<TIterator, Tout> end_iterator_; // end iterator should be unique but begin iterator should be created 
												 // every time from the scratch 
public:
	transform_view(TIterator const & begin, TIterator const & end, Tout transform_function) :
		begin_(begin), end_(end), transform_function_(transform_function) {
		DEBUG_LOG_TRACE("transform_view::Constructor");
		end_iterator_ = TransformIterator<TIterator, Tout>(end_, end_, transform_function_);
	}

	TransformIterator<TIterator, Tout> begin() {

		return TransformIterator<TIterator, Tout>(begin_, end_, transform_function_);
	}

	TransformIterator<TIterator, Tout>& end() {
		return end_iterator_;
	}

	~transform_view() {}
};