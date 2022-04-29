#pragma once
#include <future>
#include <graphics/listener/message/message.hpp>

namespace graphics::window::listener::details {
	class message_slot
	{
		friend class mouse;
		using		 event_type = std::promise<MSG>;
					 event_type __M_msgslot_event;

	public:
		template <typename MouseReceiver>
		void operator=(MouseReceiver&&);
	};
}