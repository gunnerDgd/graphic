#pragma once
#include <Windows.h>
#include <type_traits>

namespace graphics::window::messaging::domain {
	class thread_domain
	{
		struct __null_domain {};
	public:
		using						   native_handle_type = HANDLE;
		using						   domain_identifier  = std::uint32_t;
		static constexpr __null_domain null_domain {};
	public:
		thread_domain();
		thread_domain(__null_domain);
	public:
		bool operator==	  (thread_domain&);
		bool operator!=	  (thread_domain&);
			 operator bool()			  ;

		domain_identifier identifier();

	private:
		native_handle_type __M_tdomain_handle;
		domain_identifier  __M_tdomain_identifier;
	};
}