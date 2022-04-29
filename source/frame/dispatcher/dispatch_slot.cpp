#include <graphics/frame/dispatcher/dispatch_slot.hpp>

graphics::window::details::dispatch_slot::dispatch_slot()
	: __M_slot_domain(messaging::domain::thread_domain::null_domain) {  }

graphics::window::messaging::domain::thread_domain& 
graphics::window::details::dispatch_slot::domain()					 { return __M_slot_domain; }