.global oneCheck
oneCheck:
  CMP R0, #1
  BLE false

false:
  MOV r0, #0
  BX LR
