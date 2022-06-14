/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-romain.leemans
** File description:
** Exception
*/

#include <exception>
#include <string>
#include <iostream>

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

namespace bomberman {
    class Exception : public std::exception
    {
        private:
            std::string message;
            std::string file;
            int line;
        public:
            Exception(const std::string &message, const char* file, int line) noexcept;
            virtual ~Exception() {}
            const char *what() const noexcept override;
            std::string prefix() const;
            void display() const;
    };

    class RuntimeError : public Exception {
        public :
            RuntimeError(const std::string &message, const char* file, int line) : Exception("RuntimeError :" + message, file, line) {};
            virtual ~RuntimeError() {}
    };

    class BuildError : public Exception {
        public :
            BuildError(const std::string &message, const char* file, int line) : Exception("Build Error :" + message, file, line) {};
            virtual ~BuildError() {}
    };

    class InputError : public Exception {
        public :
            InputError(const std::string &message, const char* file, int line) : Exception("Input Error :" + message, file, line) {};
            virtual ~InputError() {}
    };

    class CriticalError : public Exception {
        public :
            CriticalError(const std::string &message, const char* file, int line) : Exception("Critical Error :" + message, file, line) {};
            virtual ~CriticalError() {}
    };
}

#endif /* !MYERRORS_HPP_ */
