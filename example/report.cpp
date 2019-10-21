// Copyright (C) 2019 Anders Lövgren (Nowise Systems)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "application.hpp"
#include <iostream>

using namespace Citrus::Application;

class MyApplication : public Application
{
    public:
        MyApplication(int argc, const char ** argv)
            : Application(argc, argv)
        {
        }

    protected:
        void Run(const Options & options) override
        {
                std::cout << "Running\n";
        }

        void OnInitialize() override
        {
                std::cout << "Initialize\n";
        }

        void OnStarting() override
        {
                std::cout << "Starting\n";
        }

        void OnFinished() override
        {
                std::cout << "Finished\n";
        }

        void OnCleanup() override
        {
                std::cout << "Cleanup\n";
        }

        void Usage() const override
        {
                std::cout << "Usage: " << options.GetProgram() << " [...options]\n"
                          << "Options: \n"
                          << "    -h, --help:    This casual help\n"
                          << "    -V, --version: Show version information\n";
        }

        void Version() const override
        {
                std::cout << options.GetProgram() << " v1.0\n";
        }
};

int main(int argc, const char ** argv)
{
        // Application * app = new MyApplication(argc, argv);
        // app->Start();

        MyApplication app(argc, argv);
        app.Start();

        return 0;
}
