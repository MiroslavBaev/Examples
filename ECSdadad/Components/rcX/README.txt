Installation:
1. Get and install Python 2.7 from http://www.python.org

2. Get and install pywin32 from http://sourceforge.net/projects/pywin32/

3. Get and install waf 1.6.11 from http://code.google.com/p/waf/

4. Get and install Codesourcery lite compiler (ARM-EABI 2011.03-42) from http://www.mentor.com
    (http://www.mentor.com/embedded-software/sourcery-tools/sourcery-codebench/editions/lite-edition/arm-eabi)

Getting Started:
With the help of a console, you can now call the commands
  "waf --help"                          to get the help of the command
  "waf configure"                       to configure build environment
  "waf build"                           rebuild the rcX libraries from source
  "waf clean"                           clean up build tree
  "waf configure clean build install"   for a complete rebuild

You may pass "--conditions=debug" for a debug build