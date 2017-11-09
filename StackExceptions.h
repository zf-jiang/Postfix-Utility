#ifndef STACK_EXCEPTIONS_H
#define STACK_EXCEPTIONS_H

#include <string>
#include "RuntimeException.h"


class StackEmpty : public RuntimeException {
public:
	StackEmpty(const std::string& err) : RuntimeException(err) {}
};

#endif // STACKEXCEPTIONS_H
