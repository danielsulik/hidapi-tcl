_wrap_hid_enumerate(ClientData clientData SWIGUNUSED, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) {
  unsigned short arg1 ;
  unsigned short arg2 ;
  unsigned short val1 ;
  int ecode1 = 0 ;
  unsigned short val2 ;
  int ecode2 = 0 ;
  struct hid_device_info *result = 0, *pr = NULL;

  if (SWIG_GetArgs(interp, objc, objv,"oo:hid_enumerate vendor_id product_id ",(void *)0,(void *)0) == TCL_ERROR) SWIG_fail;
  ecode1 = SWIG_AsVal_unsigned_SS_short SWIG_TCL_CALL_ARGS_2(objv[1], &val1);
  if (!SWIG_IsOK(ecode1)) {
    SWIG_exception_fail(SWIG_ArgError(ecode1), "in method '" "hid_enumerate" "', argument " "1"" of type '" "unsigned short""'");
  }
  arg1 = (unsigned short)(val1);
  ecode2 = SWIG_AsVal_unsigned_SS_short SWIG_TCL_CALL_ARGS_2(objv[2], &val2);
  if (!SWIG_IsOK(ecode2)) {
    SWIG_exception_fail(SWIG_ArgError(ecode2), "in method '" "hid_enumerate" "', argument " "2"" of type '" "unsigned short""'");
  }
  arg2   = (unsigned short)(val2);
  result = (struct hid_device_info *) hid_enumerate(arg1,arg2);
  pr     = result;

  char * res = (char*) Tcl_Alloc (128);
  res[0] = 0;
  Tcl_SetResult  (interp, res, TCL_DYNAMIC);

  if (result != NULL)
  {
      do
      {
          Tcl_AppendResult (interp, "{path:", result->path, NULL);
          char TmpStr[128];
          snprintf (TmpStr, sizeof(TmpStr), " vid:0x%04X ", result->vendor_id);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "pid:0x%04X ", result->product_id);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "serial:%ls ", result->serial_number);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "release:0x%04X ", result->release_number);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "usagep:0x%04X ", result->usage_page);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "usage:0x%04X ", result->usage);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "interface num:0x%04X ", result->interface_number);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "\"manufacturer:%ls\" ", result->manufacturer_string);
          Tcl_AppendResult (interp, TmpStr, NULL);
          snprintf (TmpStr, sizeof(TmpStr), "\"product:%ls\"}", result->product_string);
          Tcl_AppendResult (interp, TmpStr, NULL);

          result = result->next;
          if (result == NULL)
          {
              break;
          }
          Tcl_AppendResult (interp, " ", NULL);
      } while (1);
  }
  if (pr) hid_free_enumeration (pr);

  return TCL_OK;
fail:
  if (pr) hid_free_enumeration (pr);
  return TCL_ERROR;
}
