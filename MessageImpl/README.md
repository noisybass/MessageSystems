# C++ Message Systems 1: Introduction. What is an event?

Games are event-driven, and what does this mean? One example that we can find in almost every game is a collision between two objects. This collision is an event, and when it happens we may notify the objects involved in the collision and this objects may have a response to this event. And that's it. Our games are full of this events, so we need to have a mechanism to communicate our game objects. We need to be able to send a message when a event has ocurred, and we need to take that information and react properly, that's what we call 'handle' a message.

## How to Represent a Message

What do we need to know about an event? Its **type** and its **arguments**, no more. Maybe we want to know also who has send the event, but this information can be stored in the arguments. So let's focus on each of these components

### The Message Type

First and easier option, using an enum to represent the type:

```
enum MessageType
{
    MESSAGE_TYPE_DEFAULT,
    MESSAGE_TYPE_INPUT,
    MESSAGE_TYPE_COLLISION,
    // ...
}
```

This implementation is simple and efficient, but it isn't so much flexible. We need to know all the event types of our game before running it. The types are hard-coded, so we can't define new types in runtime.

A way more flexible is using strings for the types. This allows to create new types easily, but comparing strings its more expensive than comparing ints, and it increases memory requirements. Furthermore, we have to be careful with name conflicts. 

The correct way to do this it's using hashed strings, this resolve memory and cost problems. This approach it's much more flexible, but as we can see it's more complex to implement.

For simplicity, I'm going to use the enum approach for the next examples. 

### The Message Arguments

One simple way it's having a base Message class, and a derived class for each type of event, with its specific arguments hard-coded. But we want to keep our subclasses the most generic as possible, if not we could find us having a ton of event classes, and that would make our code less mantainable.

```
class Message
{
public:
	MessageType type;

	virtual ~Message();
protected:
	Message() : type(MessageType::DEFAULT) {}
	Message(MessageType t) : type(t) {}
};

class ExampleMessage : Message
{
public:
	std::string stringArg;

	ExampleMessage() : Message(MessageType::EXAMPLE) {}
	ExampleMessage(std::string s) : Message(MessageType::EXAMPLE), stringArg(s) {}
};
```

Another approach, more flexible but also more complex is to use a variant to represent each argument. I'm goin to use the Boost library variant implementation for this:

```
typedef boost::variant<float, bool, std::string> MessageArg;
```

Then we can have a small array, with fixed size to store this arguments.

```
struct Message
{
public:
	const unsigned int MAX_ARGS = 8;

	MessageType type;
	unsigned int numArgs;
	MessageArg args[MAX_ARGS];

	Message() : type(MessageType::DEFAULT) {}
	Message(MessageType t) : type(t) {}

	// ...
};
```

If we want more flexibility we can use a std::vector, but it incurs the cost of dynamic allocation.

But this approach has a problem. How do we know what each argument represents? Using an array or a std::vector means that we have order dependency, and we don't want to know the order of the arguments for each type of event that we have. That would be really crazy. 
We can fix this representing arguments as a key-value pair, having something like this:

```
struct Message
{
	typedef boost::variant<float, bool, std::string> MessageArg;
public:
	MessageType type;
	std::unordered_map<std::string, MessageArg> args;

	Message() : type(MessageType::DEFAULT) {}
	Message(MessageType t) : type(t) {}

	// ...
};
```

Again, this is better if we use hashed strings. Also, if you use this implementation you're going to need some basic functions to interact with the map of arguments:

```
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
```