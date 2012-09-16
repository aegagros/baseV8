#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>
#include <string>

namespace base {

#define MAX_MESSAGE_BUFFER 255

	/**
	 * @brief A generic exception class.
	 *
	 * This class can provide additional information about an exception
	 * such as a message, a type, as well as additional parameters.
	 */
	class Exception : std::exception {
	private:
		std::string	m_msg;

	public:
		/**
		 * @brief Create an exception with a message string.
		 * @param msg A string message describing the exception.
		 */
		Exception(const char* msg) : m_msg(msg) {};

		const char* what() const throw() {
			return m_msg.c_str();
		}

		//! Destructor.
		virtual ~Exception(void) throw() {};
	};


	class ContextError : public Exception {
	public:
		ContextError(const char* class_name)
		: Exception("must be in a context to define prototype for a class") {};
	};

	class UndefinedClassError : public Exception {
	public:
		UndefinedClassError(const char* class_name)
		: Exception("must be in a context to define prototype for a class") {};
	};

};

#endif // EXCEPTION_H_
