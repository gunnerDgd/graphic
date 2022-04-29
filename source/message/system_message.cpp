#include <graphics/message/system_message.hpp>

graphics::window::messaging::system_message::system_message(native_message_type& msg)
	: __M_message(msg) {  }

typename graphics::window::messaging::system_message 
		 graphics::window::messaging::system_message::get()
{
	native_message_type   msg_recv;
	::GetMessage        (&msg_recv, 0, 0, 0);

	return system_message(msg_recv);
}

typename graphics::window::messaging::details::category::type	  
		 graphics::window::messaging::system_message::operator[](details::category)
{
	return __M_message.message;
}

typename graphics::window::messaging::details::parameter::type
		 graphics::window::messaging::system_message::operator[](details::parameter)
{
	details::parameter::type msg_param;
							 msg_param.l_param = __M_message.lParam;
							 msg_param.w_param = __M_message.wParam;

	return					 msg_param;
}

typename graphics::window::messaging::details::window_handle::type
		 graphics::window::messaging::system_message::operator[](details::window_handle)
{
	return __M_message.hwnd;
}

void    graphics::window::messaging::system_message::post(system_message& msg)
{
	PostMessage(msg.__M_message.hwnd   ,
			    msg.__M_message.message,
				msg.__M_message.wParam ,
			    msg.__M_message.lParam);
}

void    graphics::window::messaging::system_message::post(domain::thread_domain& domain, system_message& msg)
{
	if (!domain) return;
	PostThreadMessage(domain.identifier(), msg.__M_message.message,
										   msg.__M_message.wParam , 
										   msg.__M_message.lParam);
}