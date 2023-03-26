# LLF_Driver

LLF_Driver is a Python-based driver for OpenPLC that interfaces with SequentMicrosystems Home Automation HATs. The driver supports multiple tiers of HATs and reads OPTO input values and relay contact states.

## Features

- Handles multiple tiers of SequentMicrosystems Home Automation HATs
- Reads OPTO input values and relay contact states
- Uses OpenPLC's Python SubModule (PSM) to interface with the hardware

## Configuration

Before using the LLF_Driver, make sure to set the `NUM_TIERS` variable in the `llf-driver-psm.py` file to match the number of HATs that are on your stack. For example, if you have 3 HATs, set `NUM_TIERS = 3`.  The HATs should be configured with the jumpers with ascending stack IDs, e.g, 0, 1, 2...

## Usage

1. Install OpenPLC and its dependencies on your Raspberry Pi.
2. Clone this repository into your desired directory.
3. Copy the LLF_Driver Python PSM code from `./llf-driver-psm.py` and paste it into the Hardware page of OpenPLC as a "Python on Linux (PSM)" OpenPLC Hardware Layer option. Click on "Save Changes".
4. In the OpenPLC web interface, click on the "Programs" tab, then click on "Upload Program" and upload the Structured Text program found in `./build/generated_plc.st`.
5. Run the OpenPLC project.

## Adding Home Automation HATs

To expand the provided Structured Text (ST) code to support more than 2 HATs, you'll need to follow these steps:

1. Add new OPTO input variables and RELAY output variables for the additional HATs. Use the same naming convention as before but increment the second index (e.g., OPTO_20, OPTO_21, ... , RELAY_20, RELAY_21, ... for the third HAT).
2. Increase the iteration count in the FOR loop to accommodate the additional HATs (each HAT has 8 OPTO inputs and 8 relay outputs). For example, if you have 3 HATs, the loop should run from 0 to 23.
3. Add new CASE statements inside the FOR loop to handle the newly added OPTO inputs and RELAY outputs. Make sure to cover all the new OPTO input and RELAY output variables.

Here's an example of how to modify the code to support 3 HATs:

1. Add new OPTO input variables and RELAY output variables for the third HAT:

```st
VAR
    OPTO_20 AT %IX2.0 : BOOL := False;
    ...
    OPTO_27 AT %IX2.7 : BOOL := False;
END_VAR

VAR
    RELAY_20 AT %QX2.0 : BOOL := False;
    ...
    RELAY_27 AT %QX2.7 : BOOL := False;
END_VAR
```

2. Increase the iteration count in the FOR loop:

```st
FOR i := 0 TO 23 DO
    ...
END_FOR;
```

3. Add new CASE statements inside the FOR loop:

```st
CASE i OF
    ...
    16: currentOPTO := OPTO_20;
    17: currentOPTO := OPTO_21;
    ...
    23: currentOPTO := OPTO_27;
END_CASE;

IF currentOPTO AND NOT prevOPTO[i] THEN
    CASE i OF
        ...
        16: RELAY_20 := NOT RELAY_20;
        17: RELAY_21 := NOT RELAY_21;
        ...
        23: RELAY_27 := NOT RELAY_27;
    END_CASE;
END_IF;
```

Make sure to follow these steps for each additional HAT you want to support, adjusting the variable names, loop iteration count, and CASE statements accordingly.

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).
