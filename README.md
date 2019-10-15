# Citrus C++

## Application launcher for C++ (citrus-application)

Provides an OOP approach for running applications. The application is implemented as an class providing lifetime methods to handle events. An optional monitor can be applied on the running process.

Command line parsing is handled premature to starting the application so that the programmer can focus on essential task, like implementing the business logic instead. 

## Example

```c++
#include <iostream>
#include <citrus/application.hpp>

class Application : public ConsoleApplication 
{
        public:
                Application(int argc, const char **argv)
                        : ConsoleApplication(argc, argv)
                {}

                void Run(const Options &option) 
                {
                        // Application code goes here
                }

        protected:
                void Usage() const override 
                {
                        // Show usage information
                }

                void Version() const override 
                {
                        // Show application version
                }
};

int main(int argc, const char **argv)
{
        Application app(argc, argv);
        app.Start();

        return 0;
}
```
Please examine the header [application.hpp](src/application.hpp) for all virtual methods who's behavior can be overridden.

## Requirements

Command line parsing is handled by citrus-options that should be installed.

## Building

A standard installation into /usr/local:

```bash
bash$> ./autogen.sh
bash$> ./configure
bash$> make && make install
```

Pass --prefix=path to configure or use DESTDIR for make install to install in non-standard locations.

## Getting started

See the examples directory for complete code ready to be run.

## License

This library is released under LGPL-3.0 and can be linked and used with commercial applications.

## Bug report & suggestions

Please see the AUTHORS file for contact information. Feel free to submit bug reports, patches and suggestions.