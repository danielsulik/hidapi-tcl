package require hidapi_tcl 1.0

proc Usage { } {
    puts "Usage [lindex $::argv 0] <options>"
    puts "  led  - run led test over USB HID (L152-EVAL board, hid example) "
    puts "  loop - loop back test (hid-loopback examnple)"
    puts "  help - this help"
}

set ledtest  0
set looptest 0

if { $::argc > 0 } {
    foreach arg $::argv {
        if { $arg == "led" } {
            set ledtest 1
        }
        if { $arg == "loop" } {
            set looptest 1
        }
        if { $arg == "help" } {
            Usage
            return 0
        }
    }
} else {
    Usage
    return -1
}


set HID_BUFFER_RAW_SIZE 64 

set d [hid_open 0x483 0x5750 NULL]
if { $d == "NULL"}  {
    puts "Can't access device"
    return -1  
}

set ll [hid_enumerate 0 0]
foreach l $ll {
    puts "------------------------"
    foreach i $l {
        puts $i
    }
}

puts "Manufacturer: [hid_get_manufacturer_string $d]"
puts "Product:      [hid_get_product_string $d]"
puts "Serial no.:   [hid_get_serial_number_string $d]"

hid_set_nonblocking $d 1

set cnt 0

if { $ledtest } {
    while { $cnt != 16} {
        if {[expr $cnt & 1]} {set b0 01 } else { set b0 00}
        if {[expr $cnt & 2]} {set b1 01 } else { set b1 00}
        if {[expr $cnt & 4]} {set b2 01 } else { set b2 00}
        if {[expr $cnt & 8]} {set b3 01 } else { set b3 00}
        set data 0001$b0$b1$b2$b3
        append data 0708090A0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f40
        set data [binary format H* $data ]
        hid_write $d $data 65
        after 250
        incr cnt
    }   
}

if { $looptest } {
    after 1000
    while { 0 != [lindex [hid_read $d $HID_BUFFER_RAW_SIZE] 0] } { ; } 

    set data [binary format H* 000102030405060708090A0b0c0d0e0f101112131415161718191a1b1c1d1e1f202122232425262728292a2b2c2d2e2f303132333435363738393a3b3c3d3e3f40]
    for {set i 0 } { $i < [expr 3600 * 12] } { incr i } {
        set T1 [clock seconds]
        set Err  0 
        set rcnt 0
        set tcnt [hid_write $d $data [expr $HID_BUFFER_RAW_SIZE + 1]]
        while { 1 } {
            set res [hid_read $d $HID_BUFFER_RAW_SIZE]
            if { [lindex  $res 0 ] > 0 } {
                set rcnt [expr $rcnt + [lindex $res 0] ]
                if  { [lindex $res 1] != [string range $data 1 end]} {
                    incr Err
                    puts "ERROR: RXD data:"
                    for {set b 0 } { $b < 50 } { incr b } {
                       binary scan [lindex $res 1] H* x
                       puts $x
                    }
                }
                set tcnt [expr $tcnt + [hid_write $d $data [expr $HID_BUFFER_RAW_SIZE + 1]]]
            }
            if { [expr [clock seconds] - $T1] > 0 } {
                break
            }
        }
        puts "Run: $i"
        puts "Write throughput: $tcnt B/s"
        puts "Read  throughput: $rcnt B/s"
        puts "Aggregate throughput: [expr $tcnt + $rcnt] B/s"
        puts "Errors : $Err"
    }
}
hid_close $d
