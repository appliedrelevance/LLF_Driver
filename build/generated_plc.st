PROGRAM Driver
  VAR
    prevOPTO : ARRAY [0..15] OF BOOL;
    i : INT;
  END_VAR
  VAR
    OPTO_00 AT %IX0.0 : BOOL := False;
    OPTO_01 AT %IX0.1 : BOOL := False;
    OPTO_02 AT %IX0.2 : BOOL := False;
    OPTO_03 AT %IX0.3 : BOOL := False;
    OPTO_04 AT %IX0.4 : BOOL := False;
    OPTO_05 AT %IX0.5 : BOOL := False;
    OPTO_06 AT %IX0.6 : BOOL := False;
    OPTO_07 AT %IX0.7 : BOOL := False;
    OPTO_10 AT %IX1.0 : BOOL := False;
    OPTO_11 AT %IX1.1 : BOOL := False;
    OPTO_12 AT %IX1.2 : BOOL := False;
    OPTO_13 AT %IX1.3 : BOOL := False;
    OPTO_14 AT %IX1.4 : BOOL := False;
    OPTO_15 AT %IX1.5 : BOOL := False;
    OPTO_16 AT %IX1.6 : BOOL := False;
    OPTO_17 AT %IX1.7 : BOOL := False;
  END_VAR
  VAR
    currentOPTO : BOOL := False;
  END_VAR
  VAR
    RELAY_00 AT %QX0.0 : BOOL := False;
    RELAY_01 AT %QX0.1 : BOOL := False;
    RELAY_02 AT %QX0.2 : BOOL := False;
    RELAY_03 AT %QX0.3 : BOOL := False;
    RELAY_04 AT %QX0.4 : BOOL := False;
    RELAY_05 AT %QX0.5 : BOOL := False;
    RELAY_06 AT %QX0.6 : BOOL := False;
    RELAY_07 AT %QX0.7 : BOOL := False;
    RELAY_10 AT %QX1.0 : BOOL := False;
    RELAY_11 AT %QX1.1 : BOOL := False;
    RELAY_12 AT %QX1.2 : BOOL := False;
    RELAY_13 AT %QX1.3 : BOOL := False;
    RELAY_14 AT %QX1.4 : BOOL := False;
    RELAY_15 AT %QX1.5 : BOOL := False;
    RELAY_16 AT %QX1.6 : BOOL := False;
    RELAY_17 AT %QX1.7 : BOOL := False;
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
