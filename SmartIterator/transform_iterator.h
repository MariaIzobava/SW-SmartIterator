#include <iterator>
#include <assert.h> 
#include "filter_view.h"

template <typename TIterator, typename Tout>
class TransformIterator
{
private:
	TIterator begin_;
	TIterator end_;
	Tout transform_function_;
public:

	TransformIterator() {}
	TransformIterator(TIterator const & begin, TIterator const & end, Tout transform_function)
		:begin_(begin), end_(end), transform_function_(transform_function)
	{
		DEBUG_LOG_TRACE("TransformIterator::Constructor");
	}

	TransformIterator(const TransformIterator& s) {
		DEBUG_LOG_TRACE("TransformIterator::Copy constructor");
		begin_ = s.begin_;
		end_ = s.end_;
		transform_function_ = s.transform_function_;
	}


	TransformIterator& operator=(const TransformIterator& s) {
		DEBUG_LOG_TRACE("TransformIterator::Copy operator");
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

	auto operator*() {
		assert(begin_ != end_);
		return transform_function_(*begin_);
	}

	~TransformIterator() {}
};