#pragma once
#include <graphics/message/system_message.hpp>
#include <graphics/message/domain/thread_domain.hpp>
#include <graphics/message/filter/filter.hpp>

namespace graphics::window::details {
	class dispatch_slot
	{
	public:
		dispatch_slot();
		template <typename Dispatchable>
		void							  operator= (Dispatchable&&);
		messaging::domain::thread_domain& domain    ();

	private:
		messaging::domain::thread_domain __M_slot_domain;
	};
}

template <typename Dispatchable>
void graphics::window::details::dispatch_slot::operator= (Dispatchable&& disp)
{
	__M_slot_domain = disp.current_domain();
}