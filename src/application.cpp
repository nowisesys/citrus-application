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

#include "application.hpp"

namespace Citrus::Application {

        Application::Application(int argc, const char ** argv)
            : options(argc, argv)
        {
        }

        Application::Application(const Options & options)
            : options(options)
        {
        }

        void Application::Start()
        {
                Runtime runtime(this);
                runtime.Execute(options);
        }

        void Application::Setup() const
        {
                if (options.HasOption("-h") || options.HasOption("--help")) {
                        Usage();
                        exit(0);
                }
                if (options.HasOption("-V") || options.HasOption("--version")) {
                        Version();
                        exit(0);
                }
        }

} // namespace Citrus::Application
