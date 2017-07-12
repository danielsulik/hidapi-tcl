# hidapi-tcl
hidapi port to tcl

Linux
-----

1. Install hidapi first
2.  git clone git://github.com/signal11/hidapi.git
3.  sudo apt-get install libudev-dev libusb-1.0-0-dev libfox-1.6-dev
4.  sudo apt-get install autotools-dev autoconf automake libtool
5.  ./bootstrap
6    ./configure --enable-testgui --prefix=/usr    
7.   make
8.   sudo make install
9.   sudo apt-get install tcl
10.  sudo apt-get install tcl-dev
11.  sudo apt-get install swig
12.   sudo ./build

   If you hit a problem to load hidapi_libusb.so.0 
   export LD_LIBRARY_PATH=<path to libhidapi_libusb.so.0>:$LD_LIBRARY_PATH
   libhidapi_libusb.so.0 should be installed in /usr/local.lib
   or
   sudo nano /etc/ld.so.conf.d/.conf and add /usr/local/lib
   
14. Run tclsh hidtest.tcl 

15. Consider adding /etc/udev/rules.d/10-hftlite.rules
    KERNEL="hidraw",SUBSYSTEM="hidraw", MODE="666", GROUP="plugdev"
   
Windows
-------

hidapi_tcl works with 32-bit version of TCL only.
Need 32-bit version of tclXX.lib and hidapi.lib to compile with (active state TCL)
to build type:
tclsh build
