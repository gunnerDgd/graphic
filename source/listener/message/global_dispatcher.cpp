#include <graphics/listener/message/message.hpp>
#include <graphics/listener/message/global_dispatcher.hpp>

typename graphics::listener::global_dispatcher::message
		 graphics::listener::global_dispatcher::operator()()
{
	message::native_handle_type msg_rcv;
	GetMessage				  (&msg_rcv, 0, 0, 0);

	return message(msg_rcv);
}
std::thread::id graphics::listener::global_dispatcher::current_thread()
{
	return std::this_thread::get_id();
}