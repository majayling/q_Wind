#ifndef __WINDEVENT_H__
#define __WINDEVENT_H__
#pragma comment(lib, "WindQuantData.lib")

#include <ios>
#include "WindQuantAPI.h"

namespace Wind {

	struct Event : ::WQEvent {
		explicit Event(::WQEvent const& event);
		explicit Event(::WQEvent& event);	//NOTE: Takes over data ownership!
		~Event() throw();
		void clear();
		::WQEvent release();
		K parse() const throw();
	};
	static_assert(sizeof(Event) == sizeof(::WQEvent),
		"Invalid WQEvent wrapper! Check Wind API for changes.");

	template <typename Char, typename Traits>
	std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& os, ::WQEvent const& event);

}//namespace Wind

#include "WindEvent.inl"

#endif//__WQEVENTPARSER_H__