#pragma once
#include <graphics/listener/mouse/mouse.hpp>
#include <future>

namespace graphics::window::listener {
	template <std::uint8_t EventIndex>
	class mouse::event_slot
	{
	public:
		static constexpr std::uint8_t index = EventIndex;
		class receiver
		{
		public:
			receiver(event_slot&);
			receiver();

		private:
			std::future<messaging::system_message> __M_recv_future;
		};
	public:
		
	};
}