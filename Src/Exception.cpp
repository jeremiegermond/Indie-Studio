/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-romain.leemans
** File description:
** Exception
*/

#include "Exception.hpp"

namespace bomberman {
    Exception::Exception(const std::string &msg, const char* file_path, int line_nb) noexcept
    {
        file = (std::string)file_path;
        line = line_nb;
        message = msg;
    }

    std::string Exception::prefix() const
    {
        std::string prefix = "From '" + file + "' at line " + std::to_string(line) + ": ";
        return prefix;
    }

    void Exception::display() const
    {
        std::cerr << prefix() << "\n\tError: " << message << std::endl;
    }

    const char* Exception::what() const noexcept
    {
        return message.c_str();
    }
}