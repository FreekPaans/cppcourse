#include <string>
#include <numeric>

#include "linked_list.h"

LinkedList::LinkedList(const LinkedList& from)
{
	std::accumulate(
		from.begin(), from.end(),
		std::ref(mFront),
		[](std::unique_ptr<Link>& output, const std::string& item) -> std::unique_ptr<Link>&
		{
			output.reset(new Link { item, {} });
			return output->mNext;
		});
}

LinkedList& LinkedList::operator=(const LinkedList& from)
{
	LinkedList copy{from};
	mFront = std::move(copy.mFront);
	return *this;
}

LinkedList::size_type LinkedList::size() const
{
	return std::distance(begin(), end());
}

static void push_at(std::unique_ptr<LinkedList::Link>& link, const std::string& str)
{
	std::unique_ptr<LinkedList::Link> newLink{new LinkedList::Link { str, {} }};

	newLink->mNext = std::move(link);
	link = std::move(newLink);
}

void LinkedList::push_front(const std::string& str)
{
	push_at(mFront, str);
}

void LinkedList::pop_front()
{
	mFront = std::move(mFront->mNext);
}

const std::string& LinkedList::front() const
{
	return mFront->mValue;
}

const std::string& LinkedList::at(size_type index) const
{
	return *std::next(begin(), index);
}

static std::unique_ptr<LinkedList::Link>& find_link(std::unique_ptr<LinkedList::Link>& from,
													LinkedList::size_type index)
{
	std::unique_ptr<LinkedList::Link>* link = &from;

	while(index-- > 0)
	{
		link = &link->get()->mNext;
	}

	return *link;
}

void LinkedList::insert_at(LinkedList::size_type index, const std::string& str)
{
	push_at(find_link(mFront, index), str);
}
