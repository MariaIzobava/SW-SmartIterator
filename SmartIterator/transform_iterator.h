#include <iterator>
#include <assert.h> 
#include "filter_view.h"

template <typename Tobj, typename TContainer, typename TFilt, typename TFunc, typename Tout>
class TransformIterator : public std::iterator <std::random_access_iterator_tag, Tobj>
{
private:
	using TIterator = FilterIterator<Tobj, TContainer, TFilt>;
	TIterator begin_;
	TIterator end_;
	TFunc transform_function_;
public:

	TransformIterator() {}
	TransformIterator(TIterator const & begin, TIterator const & end, TFunc transform_function)
		:begin_(begin), end_(end), transform_function_(transform_function)
	{
		std::cout << "TransformIterator::Constructor" << std::endl;
	}

	TransformIterator(const TransformIterator& s) {
		std::cout << "TransformIterator::Copy constructor" << std::endl;
		begin_ = s.begin_;
		end_ = s.end_;
		transform_function_ = s.transform_function_;
	}


	TransformIterator& operator=(const TransformIterator& s) {
		std::cout << "TransformIterator::Copy operator" << std::endl;
		begin_ = s.begin_;
		end_ = s.end_;
		transform_function_ = s.transform_function_;
		return *this;
	}

	TransformIterator& operator++() {
		assert(begin_ != end_);
		++begin_;
		return *this;
	}

	bool operator==(const TransformIterator& s) const {
		return begin_ == s.begin_;
	}

	bool operator!=(const TransformIterator& s) const {
		return begin_ != s.begin_;
	}

	Tout operator*() {
		assert(begin_ != end_);
		return transform_function_(*begin_);
	}

	~TransformIterator() {}
};