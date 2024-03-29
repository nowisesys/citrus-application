# Citrus C++

## Application executor and monitor for C++ (citrus-application)

Provides an OOP approach for running applications. The application core is implemented as an derived class providing protected methods to handle lifetime events. An optional monitor can be applied on the running process.

Command line parsing is handled premature by the base class so that the programmer can focus on the essential part, like implementing the business logic instead. An minimal implementation needs to at least define the abstract Run() method.

## Example

```c++
#include <iostream>
#include <citrus/application.hpp>

class MyApplication : public Application 
{
        public:
                MyApplication(int argc, const char **argv)
                        : Application(argc, argv)
                {}

        protected:
                void Run(const Options & options) override 
                {
                        // Application code goes here
                }

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
        MyApplication app(argc, argv);
        app.Start();

        return 0;
}
```

### Lifetime methods

The base class provides protected lifetime methods that can be overridden to alter default behavior, for example trap standard exceptions.

```c++
class MyApplication : public Application
{
    protected:
                ...

        void OnInitialize() override
        {
                // Allocate resources
        }

        void OnCleanup() override
        {
                // Release resources
        }

        void OnException(const std::exception & exception)
        {
                // Suggested: log, wait and restart application
        }
};
```

Please examine the header [application.hpp](src/application.hpp) for all virtual methods who's behavior can be overridden.

## Requirements

Command line parsing is handled by citrus-options and should be installed as a pre-requisite.

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