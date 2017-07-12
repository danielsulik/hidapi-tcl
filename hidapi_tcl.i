%module hidapi_tcl
%include "typemaps.i"

%typemap(in, numinputs=0) char *rxBuf {
    /* ignore rxBuf parameter */
}

%typemap(in, numinputs=0) void *rxBuf {
    /* ignore rxBuf parameter */
}

%typemap(argout) (char *rxBuf, unsigned count) {
    Tcl_Obj *o = Tcl_NewByteArrayObj ($1,$2);
    Tcl_ListObjAppendElement(interp,$result,o);
}

%typemap(in, numinputs=0) wchar_t *string {
    /* ignore string parameter */
}

%typemap(in, numinputs=0) size_t *maxlen {
    /* ignore maxlen parameter */
}

%typemap(argout) (wchar_t *string, size_t maxlen) {
    /* add your code */
}

%apply unsigned char  { uint8_t };
%apply unsigned short { uint16_t };
%apply unsigned int   { uint32_t };

%init {
}

%{
#include "hidapi.h"
%}

extern int     hid_init(void);
extern int     hid_exit(void);
extern struct  hid_device_info  *  hid_enumerate(unsigned short vendor_id, unsigned short product_id);
extern  hid_device *  hid_open(unsigned short vendor_id, unsigned short product_id, wchar_t *serial_number);
extern  hid_device *  hid_open_path(const char *path);
extern int    hid_write(hid_device *device, char *txBuf, unsigned count);
extern int    hid_read_timeout(hid_device *dev, char *rxBuf, unsigned count, int milliseconds);
extern int    hid_read(hid_device *device, char *rxBuf, unsigned count);
extern int    hid_set_nonblocking(hid_device *device, int nonblock);
extern int    hid_send_feature_report(hid_device *device, char *txBuf, unsigned count);
extern int    hid_get_feature_report(hid_device *device, char *rxBuf, unsigned count);
extern void   hid_close(hid_device *device);
extern int    hid_get_manufacturer_string(hid_device *device, wchar_t *string, size_t maxlen);
extern int    hid_get_product_string(hid_device *device, wchar_t *string, size_t maxlen);
extern int    hid_get_serial_number_string(hid_device *device, wchar_t *string, size_t maxlen);
extern  const wchar_t*  hid_error(hid_device *device);

%inline %{
%}
