.global check_false
check_false:
  CMP R0, #1
  BLE false

false:
  MOV r0, #0
  BX LR
