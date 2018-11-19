#include <vector>
#include <iterator>
#include <iostream>
#include "transform_iterator.h"

template <typename Tobj, typename TContainer, typename TFilt, typename TFunc, typename Tout>
class transform_view {
private:
	using TIterator = FilterIterator<Tobj, TContainer, TFilt>;
	TIterator begin_;
	TIterator end_;
	TFunc transform_function_;
	TransformIterator<Tobj, TContainer, TFilt, TFunc, Tout> end_iterator_; // end iterator should be unique but begin iterator should be created 
												 // every time from the scratch 
public:
	transform_view(TIterator const & begin, TIterator const & end, TFunc transform_function) :
		begin_(begin), end_(end), transform_function_(transform_function) {
		std::cout << "transform_view::Constructor" << std::endl;
		end_iterator_ = TransformIterator<Tobj, TContainer, TFilt, TFunc, Tout>(end_, end_, transform_function_);
	}

	TransformIterator<Tobj, TContainer, TFilt, TFunc, Tout> begin() {

		return TransformIterator<Tobj, TContainer, TFilt,  TFunc, Tout>(begin_, end_, transform_function_);
	}

	TransformIterator<Tobj, TContainer, TFilt, TFunc, Tout>& end() {
		return end_iterator_;
	}

	~transform_view() {}
};