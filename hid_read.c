_wrap_hid_read(ClientData clientData SWIGUNUSED, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
  hid_device *arg1 = (hid_device *) 0 ;
  unsigned int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  unsigned int val3 ;
  int ecode3 = 0 ;
  int result;

  unsigned char *rxBuf = NULL;

  if (SWIG_GetArgs(interp, objc, objv,"oo:hid_read device count ",(void *)0,(void *)0) == TCL_ERROR) SWIG_fail;
  res1 = SWIG_ConvertPtr(objv[1], &argp1,SWIGTYPE_p_hid_device, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "hid_read" "', argument " "1"" of type '" "hid_device *""'");
  }
  arg1 = (hid_device *)(argp1);
  ecode3 = SWIG_AsVal_unsigned_SS_int SWIG_TCL_CALL_ARGS_2(objv[2], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "hid_read" "', argument " "3"" of type '" "unsigned int""'");
  }
  arg3 = (unsigned int)(val3);
  /*
   * Allocate buffer for reading
   */
  rxBuf = (unsigned char*) Tcl_Alloc (sizeof(char) * arg3);
  if (NULL == rxBuf)
  {
      SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "hid_read" "', can't allocate read buffer");
  }
  result = (int)hid_read(arg1,rxBuf,arg3);
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
