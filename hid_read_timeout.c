_wrap_hid_read_timeout(ClientData clientData SWIGUNUSED, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
  hid_device *arg1 = (hid_device *) 0 ;
  unsigned int arg3 ;
  int arg4 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  unsigned int val3 ;
  int ecode3 = 0 ;
  int val4 ;
  int ecode4 = 0 ;
  int result;

  unsigned char *rxBuf = NULL;

  if (SWIG_GetArgs(interp, objc, objv,"ooo:hid_read_timeout dev count milliseconds ",(void *)0,(void *)0,(void *)0) == TCL_ERROR) SWIG_fail;
  res1 = SWIG_ConvertPtr(objv[1], &argp1,SWIGTYPE_p_hid_device, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "hid_read_timeout" "', argument " "1"" of type '" "hid_device *""'");
  }
  arg1 = (hid_device *)(argp1);
  ecode3 = SWIG_AsVal_unsigned_SS_int SWIG_TCL_CALL_ARGS_2(objv[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "hid_read_timeout" "', argument " "3"" of type '" "unsigned int""'");
  }
  arg3 = (unsigned int)(val3);
  ecode4 = SWIG_AsVal_int SWIG_TCL_CALL_ARGS_2(objv[3], &val4);
  if (!SWIG_IsOK(ecode4)) {
    SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "hid_read_timeout" "', argument " "4"" of type '" "int""'");
  }
  arg4 = (int)(val4);
  /*
   * Allocate buffer for reading
   */
  rxBuf = (unsigned char*) Tcl_Alloc (sizeof(char) * arg4);
  if (NULL == rxBuf)
  {
      SWIG_exception_fail(SWIG_ArgError(ecode4), "in method '" "hid_read_timeout" "', can't allocate read buffer");
  }
  result = (int)hid_read_timeout(arg1,rxBuf,arg3,arg4);

  Tcl_SetObjResult(interp,SWIG_From_int((int)(result)));
  {
    Tcl_Obj *o = Tcl_NewByteArrayObj (rxBuf,arg3);
    Tcl_ListObjAppendElement(interp,(Tcl_GetObjResult(interp)),o);
  }
  if (rxBuf) Tcl_Free ((char*)rxBuf);
  return TCL_OK;
fail:
  if (rxBuf) Tcl_Free ((char*)rxBuf);
  return TCL_ERROR;
}

