#pragma once
#include <stdexcept>
#include <string>

class DequeException : public std::runtime_error {
public:
    explicit DequeException(const std::string& message) : std::runtime_error(message) {}
};
