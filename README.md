This project is updated to BB10 Gold SDK

When trying to use the OAuth stuff with your project you need to know these things:
* Copy the oauth directory into your src folder
* Add ../src/oauth/*.cpp to the SOURCES line and ../src/oauth/*.h to your HEADERS line in your .pro file
* Put QT += network under your HEADERS line in your .pro file

Note: If you don't have internet permissions in your bar-descriptor, thats ok, it still works.  I'm sure its a bug
so for good practice and future compatibility add this.



kylefowler wrote:

twitter-bb10
============

This is a sample application for authorizing a users Twitter account with your BlackBerry 10 application.
Please note that some of the code needs clean up and improvement. It all works though, just some things that could be done better.
