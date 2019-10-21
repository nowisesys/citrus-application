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

        Runtime::Runtime(Application * application)
            : application(application)
        {
                application->OnInitialize();
        }

        Runtime::~Runtime()
        {
                application->OnCleanup();
        }

        void Runtime::Execute(const Options & options)
        {
                application->Setup();
                application->OnStarting();
                application->Run(options);
                application->OnFinished();
        }

} // namespace Citrus::Application
