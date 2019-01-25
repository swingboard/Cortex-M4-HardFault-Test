This is a hardfault test @ ARM cortex-M4, test based on STM32F4 board. It mainly shows the five parts now.

# Debug(printf) Viewer
- use the keil's debug viewer to shows the core register need dumpped.
- it need enable the "Trace Setting" and set the "Core" as 168MHz
- when enter into debug mode, select "View"->"Serial Window"->"Debug(printf) Viewer"

# Test Project using the ARMCC
- its compiled file is the *.axf
- convert it into asembly file by add script in "After Build/Rebuild"
```
fromelf.exe  -a -d -c -e -g -r -s -t -y -z "#L" -o "$L@L.txt"
```
- HardFault.txt will in the "Object" folder

# Test cases
- Div '0'
- Invalid address access
- Undefined instruction
- Data access violation
# Hard Fault doc references
- analyzing HardFaults on Cortex-M CPU
- Atollic_CortexM_crash_analysis_whitepaper
- cortex-m4 devices generic user guide
- Developing a Generic Hard Fault handler for ARM
- HardFault的诊断
- M3 Guide
- Using Cortex-M3M4M7 Fault Exceptions apnt209