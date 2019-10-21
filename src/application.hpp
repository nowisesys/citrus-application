// Copyright (C) 2019 Anders Lövgren (Nowise Systems)
//
// This library is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this library. If not, see <http://www.gnu.org/licenses/>.

#ifndef LIBCITRUS_APPLICATION_HPP
#define LIBCITRUS_APPLICATION_HPP

// #include <map>
// #include <string>
// #include <vector>

#include "options.hpp"

#if defined(WIN32) || defined(_WINDOWS) || defined(__CYGWIN__)
/* Define LIBCITRUS_EXPORTS when building library on windows. */
#if defined(LIBCITRUS_EXPORTS)
#if defined(__GNUC__)
#define LIBCITRUS_API_PUBLIC __attribute__((dllexport))
#else
/* Note: GCC seems to support this syntax too. */
#define LIBCITRUS_API_PUBLIC __declspec(dllexport)
#endif
#else
#if defined(__GNUC__)
#define LIBCITRUS_API_PUBLIC __attribute__((dllimport))
#else
/* Note: actually gcc seems to also supports this syntax. */
#define LIBCITRUS_API_PUBLIC __declspec(dllimport)
#endif
#endif
#define LIBCITRUS_API_HIDDEN
#else
#if __GNUC__ >= 4
#define LIBCITRUS_API_PUBLIC __attribute__((visibility("default")))
#define LIBCITRUS_API_HIDDEN __attribute__((visibility("hidden")))
#else
#define LIBCITRUS_API_PUBLIC
#define LIBCITRUS_API_HIDDEN
#endif
#endif

namespace Citrus::Application {

        using Options = Citrus::Options;

        class LIBCITRUS_API_PUBLIC ConsoleApplication
        {
            public:
                void Start() const;

            protected:
                void Main(int argc, const char ** argv);

                virtual void Run(const Options & options) const = 0;

            private:
                Options options;
        };

} // namespace Citrus::Application

#endif // LIBCITRUS_APPLICATION_HPP