_wrap_hid_send_feature_report(ClientData clientData SWIGUNUSED, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
  hid_device *arg1 = (hid_device *) 0 ;
  unsigned int arg3 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int res2 ;
  char *buf2 = 0 ;
  int alloc2 = 0 ;
  unsigned int val3 ;
  int ecode3 = 0 ;
  int result;

  if (SWIG_GetArgs(interp, objc, objv,"ooo:hid_send_feature_report device txBuf count ",(void *)0,(void *)0,(void *)0) == TCL_ERROR) SWIG_fail;
  res1 = SWIG_ConvertPtr(objv[1], &argp1,SWIGTYPE_p_hid_device, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "hid_send_feature_report" "', argument " "1"" of type '" "hid_device *""'");
  }
  arg1 = (hid_device *)(argp1);
  res2 = SWIG_AsCharPtrAndSize(objv[2], &buf2, NULL, &alloc2);
  if (!SWIG_IsOK(res2)) {
    SWIG_exception_fail(SWIG_ArgError(res2), "in method '" "hid_send_feature_report" "', argument " "2"" of type '" "char *""'");
  }
  ecode3 = SWIG_AsVal_unsigned_SS_int SWIG_TCL_CALL_ARGS_2(objv[3], &val3);
  if (!SWIG_IsOK(ecode3)) {
    SWIG_exception_fail(SWIG_ArgError(ecode3), "in method '" "hid_send_feature_report" "', argument " "3"" of type '" "unsigned int""'");
  }
  arg3 = (unsigned int)(val3);
  const unsigned char *txBuf = Tcl_GetByteArrayFromObj (objv[2], (int*) &val3);
  result = (int)hid_send_feature_report(arg1,txBuf,arg3);
  Tcl_SetObjResult(interp,SWIG_From_int((int)(result)));
  if (alloc2 == SWIG_NEWOBJ) free((char*)buf2);
  return TCL_OK;
fail:
  if (alloc2 == SWIG_NEWOBJ) free((char*)buf2);
  return TCL_ERROR;
}
