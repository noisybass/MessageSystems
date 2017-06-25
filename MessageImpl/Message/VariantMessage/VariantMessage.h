#ifndef VARIANT_MESSAGE_H
#define VARIANT_MESSAGE_H

#include "Message/MessageType.h"

#include <string>
#include <unordered_map>

#include <boost/variant/variant.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/variant/get.hpp>

namespace MessageSystems
{

	struct VariantMessage
	{
		typedef boost::variant<float, bool, std::string> MessageArg;

	public:
		MessageType type;
		// Using strings as ids is not the best way. It would be better using hashed strings.
		std::unordered_map<std::string, MessageArg> args;

		VariantMessage() : type(MessageType::DEFAULT) {}
		VariantMessage(MessageType t) : type(t) {}

		// Basic functions to interact with the map of arguments
		template<typename T>
		T getArg(const std::string& id) const
		{
			return boost::get<T>(args.at(id));
		}

		template<typename T>
		void setArg(const std::string& id, const T& value)
		{
			args.emplace(std::make_pair(id, value));
		}

		bool existArg(const std::string& id) const
		{
			return args.find(id) != args.end();
		}
		
	}; // struct VariantMessage

} // namespace MessageSystems

#endif // VARIANT_MESSAGE_H