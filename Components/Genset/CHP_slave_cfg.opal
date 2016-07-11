OPAL-1.0 Object
MODBUS::Block {
  name=Modbus_device
  device=modbus_slv
}
MODBUS::Slave {
  name=modbus_slv
  proto_name=TCP
  slave_id=17
  ip=192.168.10.30
  port=1050
  verbose=0
  nb_bits=1
  nb_input_bits=1
  nb_registers=2002
  nb_input_registers=5
  pinout {
		incoming_bits {
			pins {
				item {
					addr=0
				}
			}
	   }
	   	incoming_input_bits {
			pins {
				item {
					addr=0
				}
			}
	   }
	   	incoming_registers {
			pins {
				item {
					addr=0
				}
			}
	   }
	   	incoming_input_registers {
			pins {
				item {
					addr=0
				}
				item {
					addr=1
				}
				item {
					addr=2
				}
				item {
					addr=3
				}
				item {
					addr=4
				}
			}
	   }
	   	outgoing_bits {
			pins {
				item {
					addr=0
				}
			}
	   }
	   	outgoing_registers{
			pins {
				item {
					addr=2000
				}
				item {
					addr=2001
				}
			}
	   }
  }
  tasks {
    MODBUS::Task {
      type=mailbox
      deadline=100
    }
  }
}