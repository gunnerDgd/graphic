#pragma once
#include <graphics/message/message_index.hpp>
#include <thread>

namespace graphics::window::messaging {
	class system_message
	{
	public:
		using		   native_message_type = MSG;
		system_message(native_message_type&);
	public:
		template <typename FilterType>
		static system_message get (FilterType&&);
		static system_message get ();
		
		static void			  post(system_message&);
		static void			  post(std::thread&, system_message&);

	public:
		typename details::category::type	  operator[](details::category)		;
		typename details::parameter::type	  operator[](details::parameter)	;
		typename details::window_handle::type operator[](details::window_handle);

	private:
		native_message_type __M_message;
	};
}

template <typename FilterType>
typename graphics::window::messaging::system_message 
		 graphics::window::messaging::system_message::get(FilterType&& flt)
{
	using filter_type  = typename std::remove_reference_t<FilterType>;
	using filter_range = typename filter_type::range;

	native_message_type msg_recv;
	::GetMessage	  (&msg_recv, flt.window_handle, filter_range::begin, filter_range::end);

	return system_message(msg_recv);
}