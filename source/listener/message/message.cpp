#include <graphics/listener/message/message.hpp>

typename graphics::window::listener::message::index::category_t::type
		 graphics::window::listener::message::operator[](index::category_t)
{
	return __M_message_handle.message;
}

typename graphics::window::listener::message::index::operation_code_t::type 
		 graphics::window::listener::message::operator[](index::operation_code_t)
{
	index::operation_code_t::type msg_opcode;
								  msg_opcode.__M_lparam = __M_message_handle.lParam;
								  msg_opcode.__M_wparam = __M_message_handle.wParam;

	return						  msg_opcode;
}