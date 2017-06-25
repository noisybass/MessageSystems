# Message Systems

This project explores different message systems implementations.

## Dependencies

 - **[CMake > 2.8](https://cmake.org/)** as buildsystem.
 - **[Boost > 1.64.0](https://www.boost.org/)** for the header-only library *Boost.Variant*

## How to build the project

First of all you need to have installed CMake if you want to build the project. It's also necessary to have the Boost library, version 1.64.0. It has to be located in a /Libs folder inside the project. You can download it from [here][boost]

### Windows - Visual Studio 12
For building or cleaning the project execute <code> ./windowsBuild.bat </code> or <code> ./windowsClean.bat </code> in the root.

### Linux - GCC
For building or cleaning the project execute <code> sh ./linuxBuild.sh </code> or <code> sh ./linuxClean.sh </code> in the root.

### OS X - XCode
For building or cleaning the project execute <code> sh ./macBuild.sh </code> or <code> sh ./macClean.sh </code> in the root.



## License

Message Systems is license under the MIT license. See LICENSE for details.

[boost]: http://www.boost.org/users/download/