TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM Driver
  VAR
    prevOPTO : ARRAY [0..15] OF BOOL;
    i : INT;
  END_VAR
  VAR
    OPTO_00 : BOOL := False;
    OPTO_01 : BOOL := False;
    OPTO_02 : BOOL := False;
    OPTO_03 : BOOL := False;
    OPTO_04 : BOOL := False;
    OPTO_05 : BOOL := False;
    OPTO_06 : BOOL := False;
    OPTO_07 : BOOL := False;
    OPTO_10 : BOOL := False;
    OPTO_11 : BOOL := False;
    OPTO_12 : BOOL := False;
    OPTO_13 : BOOL := False;
    OPTO_14 : BOOL := False;
    OPTO_15 : BOOL := False;
    OPTO_16 : BOOL := False;
    OPTO_17 : BOOL := False;
  END_VAR
  VAR
    currentOPTO : BOOL := False;
  END_VAR
  VAR
    RELAY_00 : BOOL := False;
    RELAY_01 : BOOL := False;
    RELAY_02 : BOOL := False;
    RELAY_03 : BOOL := False;
    RELAY_04 : BOOL := False;
    RELAY_05 : BOOL := False;
    RELAY_06 : BOOL := False;
    RELAY_07 : BOOL := False;
    RELAY_10 : BOOL := False;
    RELAY_11 : BOOL := False;
    RELAY_12 : BOOL := False;
    RELAY_13 : BOOL := False;
    RELAY_14 : BOOL := False;
    RELAY_15 : BOOL := False;
    RELAY_16 : BOOL := False;
    RELAY_17 : BOOL := False;
  END_VAR

  FOR i := 0 TO 15 DO
      CASE i OF
          0: currentOPTO := OPTO_00;
          1: currentOPTO := OPTO_01;
          2: currentOPTO := OPTO_02;
          3: currentOPTO := OPTO_03;
          4: currentOPTO := OPTO_04;
          5: currentOPTO := OPTO_05;
          6: currentOPTO := OPTO_06;
          7: currentOPTO := OPTO_07;
          8: currentOPTO := OPTO_10;
          9: currentOPTO := OPTO_11;
          10: currentOPTO := OPTO_12;
          11: currentOPTO := OPTO_13;
          12: currentOPTO := OPTO_14;
          13: currentOPTO := OPTO_15;
          14: currentOPTO := OPTO_16;
          15: currentOPTO := OPTO_17;
      END_CASE;

      IF currentOPTO AND NOT prevOPTO[i] THEN
          CASE i OF
              0: RELAY_00 := NOT RELAY_00;
              1: RELAY_01 := NOT RELAY_01;
              2: RELAY_02 := NOT RELAY_02;
              3: RELAY_03 := NOT RELAY_03;
              4: RELAY_04 := NOT RELAY_04;
              5: RELAY_05 := NOT RELAY_05;
              6: RELAY_06 := NOT RELAY_06;
              7: RELAY_07 := NOT RELAY_07;
              8: RELAY_10 := NOT RELAY_10;
              9: RELAY_11 := NOT RELAY_11;
              10: RELAY_12 := NOT RELAY_12;
              11: RELAY_13 := NOT RELAY_13;
              12: RELAY_14 := NOT RELAY_14;
              13: RELAY_15 := NOT RELAY_15;
              14: RELAY_16 := NOT RELAY_16;
              15: RELAY_17 := NOT RELAY_17;
          END_CASE;
      END_IF;

      prevOPTO[i] := currentOPTO;
  END_FOR;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 : Driver;
  END_RESOURCE
END_CONFIGURATION
