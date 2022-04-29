#pragma once
#include <graphics/message/domain/thread_domain.hpp>
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
		static void			  post(domain::thread_domain&, system_message&);

		template <typename FilterType> static void post_if(FilterType&&,						 system_message&);
		template <typename FilterType> static void post_if(FilterType&&, domain::thread_domain&, system_message&);

	public:
		typename details::category::type	  operator[](details::category)		;
		typename details::parameter::type	  operator[](details::parameter)	;
		typename details::window_handle::type operator[](details::window_handle);

	private:
		native_message_type __M_message;
	};

	template <typename TranslateTarget, typename SystemMessage>
	std::enable_if_t<std::is_same_v<std::remove_reference_t<SystemMessage>, system_message>, TranslateTarget> 
		message_cast(SystemMessage&&);
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

template <typename FilterType> 
void graphics::window::messaging::system_message::post_if(FilterType&&, system_message& msg)
{
	using filter_type  = typename std::remove_reference_t<FilterType>;
	using filter_range = typename filter_type::range;

	if    (msg.__M_message.message > filter_range::begin 
		&& msg.__M_message.message < filter_range::end)
		return post(msg);
}

template <typename FilterType>
void graphics::window::messaging::system_message::post_if(FilterType&&, domain::thread_domain& domain, system_message& msg)
{
	using filter_type  = typename std::remove_reference_t<FilterType>;
	using filter_range = typename filter_type::range;

	if (!domain) return;
	
	if    (msg.__M_message.message => filter_range::begin 
		&& msg.__M_message.message <= filter_range::end)
		return post(domain, msg);
}