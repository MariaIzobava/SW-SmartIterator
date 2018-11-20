#include <iterator>
#include <assert.h> 

#define DEBUG false
#define FUNC(s) std::cerr << s << std::endl;
#define DEBUG_LOG_TRACE(s) \
        if (DEBUG)\
		FUNC(s) \

template <typename Tobj, typename TContainer, typename TFunc>
class FilterIterator: public std::iterator <std::random_access_iterator_tag, Tobj> 
{
private:
	typename TContainer::iterator begin_;
	typename TContainer::iterator end_;
	TFunc filter_function_;
public:

	FilterIterator() {}
	FilterIterator(typename TContainer::iterator const & begin, typename TContainer::iterator const & end, TFunc filter_function) {
		DEBUG_LOG_TRACE("FilterIterator::Constructor");
		begin_ = begin;
		end_ = end;
		filter_function_ = filter_function;
		while (begin_ != end_ && !filter_function_(*begin_)) {
			begin_++;
		}
	}

	FilterIterator(const FilterIterator& s) {
		DEBUG_LOG_TRACE("FilterIterator::Copy constructor");
		begin_ = s.begin_;
		end_ = s.end_;
		filter_function_ = s.filter_function_;
	}


	FilterIterator& operator=(const FilterIterator& s) {
		DEBUG_LOG_TRACE("FilterIterator::Copy operator");
		begin_ = s.begin_;
		end_ = s.end_;
		filter_function_ = s.filter_function_;
		return *this;
	}

	FilterIterator& operator++() {
		DEBUG_LOG_TRACE("FilterIterator::operator ++");
		assert(begin_ != end_);
		begin_++;
		while (begin_ != end_ && !filter_function_(*begin_)) {
			begin_++;
		}
		return *this;
	}

	bool operator==(const FilterIterator& s) const {
		DEBUG_LOG_TRACE("FilterIterator::operator ==");
		return begin_ == s.begin_;
	}

	bool operator!=(const FilterIterator& s) const {
		DEBUG_LOG_TRACE("FilterIterator::operator !=");
		return begin_ != s.begin_;
	}

	const Tobj& operator*() {
		DEBUG_LOG_TRACE("FilterIterator::operator *");
		assert(begin_ != end_);
		return *begin_;
	}
	
	~FilterIterator() {}
};