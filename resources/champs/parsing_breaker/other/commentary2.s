;00000000:  [38;2;155;89;182m00 ea 83 f3 [38;2;241;196;15m5a 6f 72 6b  23 00 00 00 00 00 00 00 [0m [38;2;155;89;182m....[38;2;241;196;15mZork#.......[0m
;00000010:  [38;2;241;196;15m00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00 [0m [38;2;241;196;15m................[0m
;*
;00000080:  [38;2;241;196;15m00 00 00 00 [0m00 00 00 00  [38;2;46;204;113m00 00 00 16 [38;2;52;152;240m23 48 65 6c [0m [38;2;241;196;15m....[0m....[38;2;46;204;113m....[38;2;52;152;240m#Hel[0m
;00000090:  [38;2;52;152;240m6c 6f 2c 0a 69 27 6d 20  23 20 5a 6f 72 6b 0a 23 [0m [38;2;52;152;240mlo,.i'm # Zork.#[0m
;000000a0:  [38;2;52;152;240m00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00 [0m [38;2;52;152;240m................[0m
;*
;00000890:  [38;2;231;76;60m0b 68 01 00 0e 00 01 02  90 00 00 00 00 10 01 00 [0m [38;2;231;76;60m.h..............[0m
;000008a0:  [38;2;231;76;60m00 00 01 09 ff fb [0m                                [38;2;231;76;60m......[0m

 .name "Zork#"#end
.comment "#Hello,
i'm # Zork
#"#""

sti r1,%:live,%1           
ld %0, r16
live: #sti r1,%:live,%1           
live %1
zjmp %:live
