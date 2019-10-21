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
    protected:
        void Run(const Options & options) override
        {
                std::cout << "Throwed\n";
                throw std::runtime_error("Oops ;-)");
        }

        void OnException(const std::exception & exception) override
        {
                std::cout << "Trapped: " << exception.what() << "\n";
        }
};

int main(int argc, const char ** argv)
{
        MyApplication app;
        app.Start();

        return 0;
}
