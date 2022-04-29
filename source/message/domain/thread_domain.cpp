#include <graphics/message/domain/thread_domain.hpp>

graphics::window::messaging::domain::thread_domain::thread_domain()
	: __M_tdomain_handle	(GetCurrentThread  ()),
	  __M_tdomain_identifier(GetCurrentThreadId()) {  }

graphics::window::messaging::domain::thread_domain::thread_domain(__null_domain)
	: __M_tdomain_handle	(NULL),
	  __M_tdomain_identifier(0)   {  }

bool graphics::window::messaging::domain::thread_domain::operator==(thread_domain& rhs)
{
	return __M_tdomain_identifier == rhs.__M_tdomain_identifier;
}

bool graphics::window::messaging::domain::thread_domain::operator!=(thread_domain& rhs)
{
	return __M_tdomain_identifier != rhs.__M_tdomain_identifier;
}

graphics::window::messaging::domain::thread_domain::operator bool()
{
	return __M_tdomain_identifier != 0;
}

typename graphics::window::messaging::domain::thread_domain::domain_identifier 
		 graphics::window::messaging::domain::thread_domain::identifier()
{
	return __M_tdomain_identifier;
}