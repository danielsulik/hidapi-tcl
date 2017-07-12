# hidapi-tcl
piogpio port to tcl

Linux
-----

1. Install hidapi first
   git clone git://github.com/signal11/hidapi.git
   sudo apt-get install libudev-dev libusb-1.0-0-dev libfox-1.6-dev
   sudo apt-get install autotools-dev autoconf automake libtool

	./bootstrap
	./configure --enable-testgui --prefix=/usr <- chnage fodler as needed
	                             this will affect if you need to update /etc/ld.so.conf.d/.conf later on
	make
	sudo make install
	
2. then sudo ./build
3. If you hit a problem to load hidapi_libusb.so.0 
   export LD_LIBRARY_PATH=<path to libhidapi_libusb.so.0>:$LD_LIBRARY_PATH
   libhidapi_libusb.so.0 should be installed in /usr/local.lib
   or
   sudo nano /etc/ld.so.conf.d/.conf and add /usr/local/lib
4. Run tclsh hidtest.tcl 

5. Consider adding /etc/udev/rules.d/10-hftlite.rules
   KERNEL="hidraw",SUBSYSTEM="hidraw", MODE="666", GROUP="plugdev"
   
Windows
-------

hidapi_tcl works with 32-bit version of TCL only.
Need 32-bit version of tclXX.lib and hidapi.lib to compile with (active state TCL)
to build type:
tclsh build