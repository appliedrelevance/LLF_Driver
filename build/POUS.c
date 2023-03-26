void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void DRIVER_init__(DRIVER *data__, BOOL retain) {
  
  {
    static const __ARRAY_OF_BOOL_16 temp = {{__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE),__BOOL_LITERAL(FALSE)}};
    __SET_VAR(data__->,PREVOPTO,,temp);
  }__INIT_VAR(data__->I,0,retain)
  __INIT_VAR(data__->OPTO_00,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_01,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_02,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_03,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_04,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_05,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_06,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_07,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_10,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_11,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_12,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_13,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_14,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_15,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_16,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTO_17,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CURRENTOPTO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_00,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_01,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_02,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_03,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_04,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_05,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_06,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_07,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_10,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_11,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_12,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_13,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_14,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_15,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_16,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELAY_17,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void DRIVER_body__(DRIVER *data__) {
  // Initialise TEMP variables

  /* FOR ... */
  __SET_VAR(data__->,I,,0);
  while( __GET_VAR(data__->I,) <= 15 ) {
    {
      INT __case_expression = __GET_VAR(data__->I,);
      if ((__case_expression == 0)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_00,));
      }
      else if ((__case_expression == 1)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_01,));
      }
      else if ((__case_expression == 2)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_02,));
      }
      else if ((__case_expression == 3)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_03,));
      }
      else if ((__case_expression == 4)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_04,));
      }
      else if ((__case_expression == 5)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_05,));
      }
      else if ((__case_expression == 6)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_06,));
      }
      else if ((__case_expression == 7)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_07,));
      }
      else if ((__case_expression == 8)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_10,));
      }
      else if ((__case_expression == 9)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_11,));
      }
      else if ((__case_expression == 10)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_12,));
      }
      else if ((__case_expression == 11)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_13,));
      }
      else if ((__case_expression == 12)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_14,));
      }
      else if ((__case_expression == 13)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_15,));
      }
      else if ((__case_expression == 14)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_16,));
      }
      else if ((__case_expression == 15)) {
        __SET_VAR(data__->,CURRENTOPTO,,__GET_VAR(data__->OPTO_17,));
      }
    };
    if ((__GET_VAR(data__->CURRENTOPTO,) && !(__GET_VAR(data__->PREVOPTO,.table[(__GET_VAR(data__->I,)) - (0)])))) {
      {
        INT __case_expression = __GET_VAR(data__->I,);
        if ((__case_expression == 0)) {
          __SET_VAR(data__->,RELAY_00,,!(__GET_VAR(data__->RELAY_00,)));
        }
        else if ((__case_expression == 1)) {
          __SET_VAR(data__->,RELAY_01,,!(__GET_VAR(data__->RELAY_01,)));
        }
        else if ((__case_expression == 2)) {
          __SET_VAR(data__->,RELAY_02,,!(__GET_VAR(data__->RELAY_02,)));
        }
        else if ((__case_expression == 3)) {
          __SET_VAR(data__->,RELAY_03,,!(__GET_VAR(data__->RELAY_03,)));
        }
        else if ((__case_expression == 4)) {
          __SET_VAR(data__->,RELAY_04,,!(__GET_VAR(data__->RELAY_04,)));
        }
        else if ((__case_expression == 5)) {
          __SET_VAR(data__->,RELAY_05,,!(__GET_VAR(data__->RELAY_05,)));
        }
        else if ((__case_expression == 6)) {
          __SET_VAR(data__->,RELAY_06,,!(__GET_VAR(data__->RELAY_06,)));
        }
        else if ((__case_expression == 7)) {
          __SET_VAR(data__->,RELAY_07,,!(__GET_VAR(data__->RELAY_07,)));
        }
        else if ((__case_expression == 8)) {
          __SET_VAR(data__->,RELAY_10,,!(__GET_VAR(data__->RELAY_10,)));
        }
        else if ((__case_expression == 9)) {
          __SET_VAR(data__->,RELAY_11,,!(__GET_VAR(data__->RELAY_11,)));
        }
        else if ((__case_expression == 10)) {
          __SET_VAR(data__->,RELAY_12,,!(__GET_VAR(data__->RELAY_12,)));
        }
        else if ((__case_expression == 11)) {
          __SET_VAR(data__->,RELAY_13,,!(__GET_VAR(data__->RELAY_13,)));
        }
        else if ((__case_expression == 12)) {
          __SET_VAR(data__->,RELAY_14,,!(__GET_VAR(data__->RELAY_14,)));
        }
        else if ((__case_expression == 13)) {
          __SET_VAR(data__->,RELAY_15,,!(__GET_VAR(data__->RELAY_15,)));
        }
        else if ((__case_expression == 14)) {
          __SET_VAR(data__->,RELAY_16,,!(__GET_VAR(data__->RELAY_16,)));
        }
        else if ((__case_expression == 15)) {
          __SET_VAR(data__->,RELAY_17,,!(__GET_VAR(data__->RELAY_17,)));
        }
      };
    };
    __SET_VAR(data__->,PREVOPTO,.table[(__GET_VAR(data__->I,)) - (0)],__GET_VAR(data__->CURRENTOPTO,));
    /* BY ... (of FOR loop) */
    __SET_VAR(data__->,I,,(__GET_VAR(data__->I,) + 1));
  } /* END_FOR */;

  goto __end;

__end:
  return;
} // DRIVER_body__() 





