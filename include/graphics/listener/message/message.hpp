#pragma once
#include <graphics/listener/message/message_filter.hpp>

namespace graphics::listener {
	class global_dispatcher::message
	{
		friend class global_dispatcher;
		using		 native_handle_type = MSG;

	private:
		message(native_handle_type);
		native_handle_type __M_message_handle;
	};
}