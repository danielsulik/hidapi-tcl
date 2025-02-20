_wrap_hid_get_product_string(ClientData clientData SWIGUNUSED, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
  hid_device *arg1 = (hid_device *) 0 ;
  void *argp1 = 0 ;
  int res1 = 0 ;
  int result;

  if (SWIG_GetArgs(interp, objc, objv,"o:hid_get_product_string device ",(void *)0) == TCL_ERROR) SWIG_fail;
  res1 = SWIG_ConvertPtr(objv[1], &argp1,SWIGTYPE_p_hid_device, 0 |  0 );
  if (!SWIG_IsOK(res1)) {
    SWIG_exception_fail(SWIG_ArgError(res1), "in method '" "hid_get_product_string" "', argument " "1"" of type '" "hid_device *""'");
  }
  arg1 = (hid_device *)(argp1);

  wchar_t TmpStr1[128];
  char TmpStr2[4096];
  char * res = (char*) Tcl_Alloc (128);
  res[0] = 0;
  Tcl_SetResult  (interp, res, TCL_DYNAMIC);

  result = (int)hid_get_product_string(arg1, TmpStr1, sizeof(TmpStr1)/sizeof(wchar_t));
  if ( result < 0 ) SWIG_fail;
  snprintf (TmpStr2, sizeof(TmpStr2), "%ls", TmpStr1);
  Tcl_AppendResult (interp, TmpStr2, NULL);
  return TCL_OK;
fail:
  return TCL_ERROR;
}
