Resident data ends at 4d8c, program starts at 4f24, file ends at 1a7a6

Starting analysis pass at address 4d8c

End of analysis pass, low address = 4d8c, high address = 17d33

[Start of code]

Routine R0001, 1 local (0000)

       RANDOM          #64 -> -(SP)
       JG              L00,(SP)+ [TRUE] RTRUE
       RFALSE          

Routine R0002, 1 local (0000)

       LOADW           L00,#00 -> -(SP)
       RANDOM          (SP)+ -> -(SP)
       LOADW           L00,(SP)+ -> -(SP)
       RET_POPPED      

Routine R0003, 3 locals (0000, 0000, 0000)

       CALL            R0005 (L00,#01) -> L02
       STOREW          L02,#01,L01
       RET             L02

Routine R0004, 3 locals (0000, 0000, 0000)

       CALL            R0005 (L00) -> L02
       STOREW          L02,#01,L01
       RET             L02

Routine R0005, 5 locals (0000, 0000, 0000, 0000, 0000)

       ADD             Gbd,#012c -> L02
       ADD             Gbd,Gbb -> L03
L0001: JE              L03,L02 [FALSE] L0003
       SUB             Gbb,#06 -> Gbb
       JZ              L01 [TRUE] L0002
       SUB             Gbc,#06 -> Gbc
L0002: ADD             Gbd,Gbb -> L04
       STOREW          L04,#02,L00
       RET             L04
L0003: LOADW           L03,#02 -> -(SP)
       JE              (SP)+,L00 [FALSE] L0004
       RET             L03
L0004: ADD             L03,#06 -> L03
       JUMP            L0001

Routine R0006, 4 locals (0000, 0000, 0000, 0000)

       JZ              Gba [TRUE] L0001
       STORE           Gba,#00
       RFALSE          
L0001: INC             G76
       JG              G76,#04af [FALSE] L0002
       PRINT           "Chief Inspector Klutz walks up to you, seemingly from
out of nowhere. "I'm sorry, Inspector, but your time is up here. I'm sorry that
you didn't have any more time to investigate the case. Maybe next time..." He
escorts you to a waiting police car, in which  you go off into the sunset."
       NEW_LINE        
       QUIT            
L0002: INC_CHK         G02,#3b [FALSE] L0003
       STORE           G02,#00
       INC_CHK         G01,#17 [FALSE] L0003
       STORE           G01,#00
L0003: JZ              Gb9 [TRUE] L0004
       PUSH            Gbb
       JUMP            L0005
L0004: PUSH            Gbc
L0005: ADD             Gbd,(SP)+ -> L00
       ADD             Gbd,#012c -> L01
L0006: JE              L00,L01 [FALSE] L0007
       RET             L03
L0007: LOADW           L00,#00 -> -(SP)
       JZ              (SP)+ [TRUE] L0009
       LOADW           L00,#01 -> L02
       JZ              L02 [FALSE] L0008
       JUMP            L0009
L0008: SUB             L02,#01 -> -(SP)
       STOREW          L00,#01,(SP)+
       JG              L02,#01 [TRUE] L0009
       LOADW           L00,#02 -> -(SP)
       CALL            (SP)+ -> -(SP)
       JZ              (SP)+ [TRUE] L0009
       STORE           L03,#01
L0009: ADD             L00,#06 -> L00
       JUMP            L0006

Main routine R0007, 0 locals ()

L0001: STORE           G87,#01
       STORE           G01,#08
       STORE           Ga8,#a0
       STORE           G00,#f9
       STORE           Ga3,G00
       STORE           Ga4,#00
       STORE           Gb8,#97
       STORE           Gb7,#dd
       TEST_ATTR       G00,#1e [TRUE] L0002
       RANDOM          #28 -> -(SP)
       ADD             #af,(SP)+ -> -(SP)
       CALL            R0004 (#73fc,(SP)+) -> -(SP)
       STOREW          (SP)+,#00,#01
       RANDOM          #3c -> -(SP)
       ADD             #46,(SP)+ -> -(SP)
       CALL            R0004 (#72a3,(SP)+) -> -(SP)
       STOREW          (SP)+,#00,#01
       RANDOM          #0a -> -(SP)
       ADD             #3c,(SP)+ -> -(SP)
       CALL            R0004 (#7c4d,(SP)+) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#a59b,#73) -> -(SP)
       STOREW          (SP)+,#00,#01
       RANDOM          #05 -> -(SP)
       ADD             #e6,(SP)+ -> -(SP)
       CALL            R0004 (#a5dd,(SP)+) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0451 -> -(SP)
       CALL            R0066 -> -(SP)
       NEW_LINE        
L0002: INSERT_OBJ      Ga8,G00
       CALL            R0052 -> -(SP)
       CALL            R0008 -> -(SP)
       JUMP            L0001

Routine R0008, 11 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000,
                          0000, 0000)

L0001: STORE           L03,#00
       STORE           L04,#00
       STORE           L07,#01
       CALL            R0011 -> Gb9
       JZ              Gb9 [TRUE] L0029
       LOADW           G91,G8d -> L00
       LOADW           G92,G8d -> L01
       JZ              L01 [FALSE] L0002
       PUSH            L01
       JUMP            L0007
L0002: JG              L01,#01 [FALSE] L0005
       STORE           L05,G92
       JZ              L00 [FALSE] L0003
       STORE           L04,#00
       JUMP            L0004
L0003: LOADW           G91,#01 -> L04
L0004: PUSH            L01
       JUMP            L0007
L0005: JG              L00,#01 [FALSE] L0006
       STORE           L07,#00
       STORE           L05,G91
       LOADW           G92,#01 -> L04
       PUSH            L00
       JUMP            L0007
L0006: PUSH            #01
L0007: STORE           L02,(SP)+
       JE              G79,G00 [TRUE] L0008
       STORE           G7a,#00
L0008: JZ              L04 [FALSE] L0009
       JE              L00,#01 [FALSE] L0009
       LOADW           G91,#01 -> L04
L0009: JE              Gb1,#82 [FALSE] L0010
       CALL            R0010 (Gb1,Gaf) -> L06
       JUMP            L0028
L0010: JZ              L02 [FALSE] L0014
       LOADB           Gac,#00 -> -(SP)
       AND             (SP)+,#03 -> -(SP)
       JZ              (SP)+ [FALSE] L0011
       CALL            R0010 (Gb1) -> L06
       STORE           Gaf,#00
       JUMP            L0028
L0011: PRINT           "There isn't anything to "
       LOADW           G9d,#01 -> L09
       JZ              Ga2 [TRUE] L0012
       LOADW           L09,#00 -> -(SP)
       PRINT_ADDR      (SP)+
       JUMP            L0013
L0012: LOADB           L09,#02 -> L0a
       LOADB           L09,#03 -> -(SP)
       CALL            R0017 (L0a,(SP)+) -> -(SP)
L0013: PRINT           "!"
       NEW_LINE        
       STORE           L06,#00
       JUMP            L0028
L0014: JZ              L07 [TRUE] L0015
       JE              L02,#02 [FALSE] L0015
       JE              Gb1,#14 [FALSE] L0015
       CALL            R0010 (Gb1,#34) -> L06
       JUMP            L0028
L0015: INC_CHK         L03,L02 [FALSE] L0016
       JUMP            L0028
L0016: JZ              L07 [TRUE] L0017
       LOADW           G92,L03 -> L08
       JUMP            L0018
L0017: LOADW           G91,L03 -> L08
L0018: JG              L02,#01 [FALSE] L0021
       JE              L08,#a0 [FALSE] L0019
       JUMP            L0015
L0019: TEST_ATTR       L08,#0e [FALSE] L0020
       JUMP            L0015
L0020: PRINT_OBJ       L08
       PRINT           ": "
L0021: JZ              L07 [TRUE] L0022
       PUSH            L08
       JUMP            L0023
L0022: PUSH            L04
L0023: CALL            R0009 ((SP)+) -> L06
       JZ              L07 [TRUE] L0024
       PUSH            L08
       JUMP            L0025
L0024: PUSH            L04
L0025: STORE           L0a,(SP)+
       JZ              L07 [TRUE] L0026
       PUSH            L04
       JUMP            L0027
L0026: PUSH            L08
L0027: CALL            R0010 (Gb1,L0a,(SP)+) -> L06
       JE              L06,#02 [FALSE] L0015
L0028: JE              L06,#02 [FALSE] L0030
       STORE           Ga5,#00
       JUMP            L0030
L0029: STORE           Ga5,#00
L0030: JZ              Gb9 [TRUE] L0001
       JE              Gb1,#03,#02 [TRUE] L0001
       JE              Gb1,#0a,#06,#0d [TRUE] L0001
       JE              Gb1,#01,#00,#17 [FALSE] L0031
       JUMP            L0001
L0031: CALL            R0006 -> L06
       JUMP            L0001

Routine R0009, 1 local (0000)

       JZ              G7a [TRUE] RFALSE
       JIN             G7a,G00 [FALSE] RFALSE
       JE              G79,G00 [FALSE] RFALSE
       JE              Ga8,#a0 [FALSE] RFALSE
       JE              Gb1,#87 [TRUE] L0002
       JE              Gb1,#32 [TRUE] L0002
       JE              Gb1,#72 [FALSE] L0001
       JE              L00,#a0 [TRUE] L0002
L0001: JE              Gb1,#69 [FALSE] RFALSE
       JE              L00,#a0 [FALSE] RFALSE
L0002: STORE           Ga8,G7a
       PRINT           "(said to "
       PRINT_OBJ       G7a
       PRINT_RET       ")"

Routine R0010, 7 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000)

       STORE           L04,Gb1
       STORE           L05,Gaf
       STORE           L06,Gb0
       STORE           Gb1,L00
       JE              #fb,L02,L01 [FALSE] L0001
       JE              Ga3,G00 [TRUE] L0001
       PRINT           "I don't see what you are referring to."
       NEW_LINE        
       RET             #02
L0001: JE              #fa,L02,L01 [FALSE] L0003
       JE              Gb7,G00 [TRUE] L0003
       GET_PROP        Gb8,#07 -> -(SP)
       LOADW           G05,(SP)+ -> L03
       JE              #fa,L01 [FALSE] L0002
       STORE           L01,L03
       JUMP            L0003
L0002: JE              #fa,L02 [FALSE] L0003
       STORE           L02,L03
L0003: JE              L01,#fb [FALSE] L0004
       STORE           L01,Ga4
       JUMP            L0005
L0004: JE              L01,#fa [FALSE] L0005
       STORE           L01,Gb8
L0005: JE              L02,#fb [FALSE] L0006
       STORE           L02,Ga4
       JUMP            L0007
L0006: JE              L02,#fa [FALSE] L0007
       STORE           L02,Gb8
L0007: STORE           Gaf,L01
       JZ              Gaf [TRUE] L0009
       JE              Gb1,#82 [TRUE] L0009
       TEST_ATTR       Gaf,#14 [FALSE] L0008
       STORE           Gb8,Gaf
       STORE           Gb7,G00
       JUMP            L0009
L0008: STORE           Ga4,Gaf
       STORE           Ga3,G00
L0009: STORE           Gb0,L02
       JE              L00,#0f [TRUE] L0012
       STORE           Gb6,L00
       JE              L00,#82 [FALSE] L0010
       STORE           Gb5,#00
       JUMP            L0011
L0010: STORE           Gb5,L01
L0011: STORE           Gb4,L02
L0012: GET_PROP        Ga8,#12 -> -(SP)
       CALL            (SP)+ -> L03
       JZ              L03 [TRUE] L0013
       JUMP            L0018
L0013: GET_PARENT      Ga8 -> -(SP)
       GET_PROP        (SP)+,#12 -> -(SP)
       CALL            (SP)+ (#01) -> L03
       JZ              L03 [TRUE] L0014
       JUMP            L0018
L0014: LOADW           Gc4,L00 -> -(SP)
       CALL            (SP)+ -> L03
       JZ              L03 [TRUE] L0015
       JUMP            L0018
L0015: JZ              L02 [TRUE] L0016
       GET_PROP        L02,#12 -> -(SP)
       CALL            (SP)+ -> L03
       JZ              L03 [TRUE] L0016
       JUMP            L0018
L0016: JZ              L01 [TRUE] L0017
       JE              L00,#82 [TRUE] L0017
       GET_PROP        L01,#12 -> -(SP)
       CALL            (SP)+ -> L03
       JZ              L03 [TRUE] L0017
       JUMP            L0018
L0017: LOADW           Gc3,L00 -> -(SP)
       CALL            (SP)+ -> L03
       JZ              L03 [TRUE] L0018
L0018: JE              L03,#02 [TRUE] L0019
       GET_PARENT      Ga8 -> -(SP)
       GET_PROP        (SP)+,#12 -> -(SP)
       CALL            (SP)+ (#00) -> L03
L0019: STORE           Gb1,L04
       STORE           Gaf,L05
       STORE           Gb0,L06
       RET             L03

Routine R0011, 11 locals (0001, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000,
                          0000, ffff)

L0001: INC_CHK         L0a,#09 [FALSE] L0002
       JUMP            L0003
L0002: STOREW          G9d,L0a,#00
       JUMP            L0001
L0003: STORE           G54,#00
       STORE           Ga1,#00
       STOREW          G92,G8d,#00
       STOREW          G91,G8d,#00
       STOREW          G90,G8d,#00
       JZ              G99 [FALSE] L0004
       JE              Ga8,#a0 [TRUE] L0004
       STORE           Ga8,#a0
       GET_PARENT      Ga8 -> -(SP)
       TEST_ATTR       (SP)+,#0c [TRUE] L0004
       GET_PARENT      Ga8 -> G00
L0004: JZ              Ga5 [TRUE] L0005
       STORE           L00,Ga5
       STORE           Ga5,#00
       JE              Gb1,#17 [TRUE] L0010
       NEW_LINE        
       JUMP            L0010
L0005: STORE           Ga8,#a0
       STORE           G99,#00
       GET_PARENT      Ga8 -> -(SP)
       TEST_ATTR       (SP)+,#0c [TRUE] L0006
       GET_PARENT      Ga8 -> G00
L0006: STORE           L09,G75
L0007: DEC_CHK         L09,#00 [FALSE] L0008
       JUMP            L0009
L0008: NEW_LINE        
       JUMP            L0007
L0009: PRINT           ">"
       READ            Ga6,Ga7
L0010: LOADB           Ga7,#01 -> Gaa
       JZ              Gaa [FALSE] L0011
       PRINT           "What?"
       NEW_LINE        
       RFALSE          
L0011: LOADW           Ga7,L00 -> L01
       JE              L01,"why","how","when" [TRUE] L0012
       JE              L01,"is","did","are" [FALSE] L0013
L0012: PRINT           "Detectives are expected to know how to conduct an
interrogation; please re-read your casebook for remedial instruction. Remember
that the documentary evidence enclosed contains the answers to all of the
important questions which cannot be asked directly."
       NEW_LINE        
       RFALSE          
L0013: STORE           L04,Gaa
       STORE           Ga9,#00
       STORE           G9a,#00
       STORE           G8c,#00
L0014: DEC_CHK         Gaa,#00 [FALSE] L0015
       STORE           G99,#00
       JUMP            L0046
L0015: LOADW           Ga7,L00 -> L01
       JZ              L01 [FALSE] L0016
       CALL            R0014 (L00) -> L01
       JZ              L01 [TRUE] L0044
L0016: JE              L01,"to" [FALSE] L0017
       JE              L03,#ed,#a1 [FALSE] L0017
       STORE           L01,"""
       JUMP            L0018
L0017: JE              L01,"then" [FALSE] L0018
       JZ              L03 [FALSE] L0018
       STOREW          G9d,#00,#ed
       STOREW          G9d,#01,#00
       STORE           L01,"""
L0018: JE              L01,"." [FALSE] L0019
       JE              L07,"mrs","mr","ms" [FALSE] L0019
       STORE           L07,#00
       JUMP            L0045
L0019: JE              L01,"then","." [TRUE] L0020
       JE              L01,""" [FALSE] L0024
L0020: JE              L01,""" [FALSE] L0022
       JZ              G99 [TRUE] L0021
       STORE           G99,#00
       JUMP            L0022
L0021: STORE           G99,#01
L0022: JZ              Gaa [TRUE] L0023
       ADD             L00,#02 -> Ga5
L0023: STOREB          Ga7,#01,Gaa
       JUMP            L0046
L0024: CALL            R0012 (L01,#10,#03) -> L02
       JZ              L02 [TRUE] L0031
       JE              L04,#01 [TRUE] L0029
       JE              L04,#02 [FALSE] L0025
       JE              L03,#f7 [TRUE] L0029
L0025: ADD             L00,#02 -> -(SP)
       LOADW           Ga7,(SP)+ -> L06
       JE              L06,"then",""" [FALSE] L0026
       JG              L04,#02 [TRUE] L0029
L0026: JE              L06,"." [FALSE] L0027
       JG              L04,#01 [TRUE] L0029
L0027: JZ              G99 [TRUE] L0028
       JE              L04,#02 [FALSE] L0028
       JE              L06,""" [TRUE] L0029
L0028: JG              L04,#02 [FALSE] L0031
       JE              L06,",","and" [FALSE] L0031
L0029: STORE           L05,L02
       JE              L06,",","and" [FALSE] L0030
       ADD             L00,#02 -> -(SP)
       STOREW          Ga7,(SP)+,"then"
L0030: JG              L04,#02 [TRUE] L0045
       STORE           G99,#00
       JUMP            L0046
L0031: CALL            R0012 (L01,#40,#01) -> L02
       JZ              L02 [TRUE] L0033
       JZ              L03 [TRUE] L0032
       JE              L03,#fa [FALSE] L0033
L0032: STORE           L03,L02
       STOREW          G9d,#00,L02
       STOREW          G9d,#01,G9b
       STOREW          G9b,#00,L01
       MUL             L00,#02 -> -(SP)
       ADD             (SP)+,#02 -> L08
       LOADB           Ga7,L08 -> -(SP)
       STOREB          G9b,#02,(SP)+
       ADD             L08,#01 -> -(SP)
       LOADB           Ga7,(SP)+ -> -(SP)
       STOREB          G9b,#03,(SP)+
       JUMP            L0045
L0033: CALL            R0012 (L01,#08,#00) -> L02
       JZ              L02 [FALSE] L0035
       JE              L01,"all","one","a" [TRUE] L0034
       CALL            R0012 (L01,#20) -> -(SP)
       JZ              (SP)+ [FALSE] L0034
       CALL            R0012 (L01,#80) -> -(SP)
       JZ              (SP)+ [TRUE] L0040
L0034: STORE           L02,#00
L0035: JG              Gaa,#00 [FALSE] L0036
       ADD             L00,#02 -> -(SP)
       LOADW           Ga7,(SP)+ -> -(SP)
       JE              (SP)+,"of" [FALSE] L0036
       JE              L03,#9b [TRUE] L0036
       JZ              L02 [FALSE] L0036
       JE              L01,"all","one","a" [TRUE] L0036
       JUMP            L0045
L0036: JZ              L02 [TRUE] L0038
       JZ              Gaa [TRUE] L0037
       ADD             L00,#02 -> -(SP)
       LOADW           Ga7,(SP)+ -> -(SP)
       JE              (SP)+,"then","." [FALSE] L0038
L0037: JL              G9a,#02 [FALSE] L0045
       STOREW          G9d,#02,L02
       STOREW          G9d,#03,L01
       JUMP            L0045
L0038: JE              G9a,#02 [FALSE] L0039
       PRINT           "There were more than two nouns in that sentence."
       NEW_LINE        
       RFALSE          
L0039: INC             G9a
       CALL            R0013 (L00,L02,L01) -> L00
       JZ              L00 [TRUE] RFALSE
       JL              L00,#00 [FALSE] L0045
       STORE           G99,#00
       JUMP            L0046
L0040: JE              L01,"carefu","quietl" [TRUE] L0041
       JE              L01,"slowly","quickl","briefl" [FALSE] L0042
L0041: STORE           G54,L01
       JUMP            L0045
L0042: CALL            R0012 (L01,#04) -> -(SP)
       JZ              (SP)+ [TRUE] L0043
       JUMP            L0045
L0043: CALL            R0019 (L00) -> -(SP)
       RFALSE          
L0044: CALL            R0018 (L00) -> -(SP)
       RFALSE          
L0045: STORE           L07,L01
       ADD             L00,#02 -> L00
       JUMP            L0014
L0046: JZ              L05 [TRUE] L0047
       STORE           Gb1,#82
       STORE           Gaf,L05
       RTRUE           
L0047: JZ              Ga2 [TRUE] L0048
       CALL            R0015 -> -(SP)
L0048: LOADW           G9d,#00 -> -(SP)
       JZ              (SP)+ [FALSE] L0049
       STOREW          G9d,#00,#a6
L0049: CALL            R0020 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       CALL            R0031 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       CALL            R0040 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       CALL            R0042 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       RTRUE           

Routine R0012, 5 locals (0000, 0000, 0005, 0005, 0000)

       LOADB           L00,#04 -> L04
       TEST            L04,L01 [FALSE] RFALSE
       JG              L02,#04 [TRUE] RTRUE
       AND             L04,#03 -> L04
       JE              L04,L02 [TRUE] L0001
       INC             L03
L0001: LOADB           L00,L03 -> -(SP)
       RET_POPPED      

Routine R0013, 10 locals (0000, 0000, 0000, 0000, 0000, 0000, 0001, 0000, 0000,
                          0000)

       SUB             G9a,#01 -> -(SP)
       MUL             (SP)+,#02 -> L03
       JZ              L01 [TRUE] L0001
       ADD             #02,L03 -> L04
       STOREW          G9d,L04,L01
       ADD             L04,#01 -> -(SP)
       STOREW          G9d,(SP)+,L02
       ADD             L00,#02 -> L00
       JUMP            L0002
L0001: INC             Gaa
L0002: JZ              Gaa [FALSE] L0003
       DEC             G9a
       RET             #ffff
L0003: ADD             #06,L03 -> L04
       MUL             L00,#02 -> -(SP)
       ADD             Ga7,(SP)+ -> -(SP)
       STOREW          G9d,L04,(SP)+
       LOADW           Ga7,L00 -> -(SP)
       JE              (SP)+,"the","a","an" [FALSE] L0004
       LOADW           G9d,L04 -> -(SP)
       ADD             (SP)+,#04 -> -(SP)
       STOREW          G9d,L04,(SP)+
L0004: DEC_CHK         Gaa,#00 [FALSE] L0005
       ADD             L04,#01 -> L09
       MUL             L00,#02 -> -(SP)
       ADD             Ga7,(SP)+ -> -(SP)
       STOREW          G9d,L09,(SP)+
       RET             #ffff
L0005: LOADW           Ga7,L00 -> L02
       JZ              L02 [FALSE] L0006
       CALL            R0014 (L00) -> L02
       JZ              L02 [TRUE] L0022
L0006: JZ              Gaa [FALSE] L0007
       STORE           L07,#00
       JUMP            L0008
L0007: ADD             L00,#02 -> -(SP)
       LOADW           Ga7,(SP)+ -> L07
L0008: JE              L02,"of" [FALSE] L0009
       LOADW           G9d,#00 -> -(SP)
       JE              (SP)+,#9b [FALSE] L0009
       STOREW          Ga7,L00,"with"
       STORE           L02,"with"
L0009: JE              L02,"." [FALSE] L0010
       JE              L08,"mrs","mr","ms" [FALSE] L0010
       STORE           L08,#00
       JUMP            L0023
L0010: JE              L02,"and","," [FALSE] L0011
       STORE           L05,#01
       JUMP            L0023
L0011: JE              L02,"all","one" [FALSE] L0012
       JE              L07,"of" [FALSE] L0023
       DEC             Gaa
       ADD             L00,#02 -> L00
       JUMP            L0023
L0012: JE              L02,"then","." [TRUE] L0013
       CALL            R0012 (L02,#08) -> -(SP)
       JZ              (SP)+ [TRUE] L0014
       JZ              L06 [FALSE] L0014
L0013: INC             Gaa
       ADD             L04,#01 -> L09
       MUL             L00,#02 -> -(SP)
       ADD             Ga7,(SP)+ -> -(SP)
       STOREW          G9d,L09,(SP)+
       SUB             L00,#02 -> -(SP)
       RET             (SP)+
L0014: CALL            R0012 (L02,#80) -> -(SP)
       JZ              (SP)+ [TRUE] L0017
       CALL            R0012 (L02,#20,#02) -> -(SP)
       JZ              (SP)+ [TRUE] L0015
       JZ              L07 [TRUE] L0015
       CALL            R0012 (L07,#80) -> -(SP)
       JZ              (SP)+ [TRUE] L0015
       JUMP            L0023
L0015: JZ              L05 [FALSE] L0016
       JE              L07,"but","except" [TRUE] L0016
       JE              L07,"and","," [TRUE] L0016
       ADD             L04,#01 -> L09
       ADD             L00,#02 -> -(SP)
       MUL             (SP)+,#02 -> -(SP)
       ADD             Ga7,(SP)+ -> -(SP)
       STOREW          G9d,L09,(SP)+
       RET             L00
L0016: STORE           L05,#00
       JUMP            L0023
L0017: CALL            R0012 (L02,#20) -> -(SP)
       JZ              (SP)+ [FALSE] L0023
       CALL            R0012 (L02,#04) -> -(SP)
       JZ              (SP)+ [TRUE] L0018
       JUMP            L0023
L0018: JZ              L05 [TRUE] L0020
       CALL            R0012 (L02,#10) -> -(SP)
       JZ              (SP)+ [FALSE] L0019
       CALL            R0012 (L02,#40) -> -(SP)
       JZ              (SP)+ [TRUE] L0020
L0019: SUB             L00,#04 -> L00
       ADD             L00,#02 -> -(SP)
       STOREW          Ga7,(SP)+,"then"
       ADD             Gaa,#02 -> Gaa
       JUMP            L0023
L0020: CALL            R0012 (L02,#08) -> -(SP)
       JZ              (SP)+ [TRUE] L0021
       JUMP            L0023
L0021: CALL            R0019 (L00) -> -(SP)
       RFALSE          
L0022: CALL            R0018 (L00) -> -(SP)
       RFALSE          
L0023: STORE           L08,L02
       STORE           L06,#00
       ADD             L00,#02 -> L00
       JUMP            L0004

Routine R0014, 7 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000)

       MUL             L00,#02 -> -(SP)
       ADD             Ga7,(SP)+ -> -(SP)
       LOADB           (SP)+,#02 -> L01
       MUL             L00,#02 -> -(SP)
       ADD             Ga7,(SP)+ -> -(SP)
       LOADB           (SP)+,#03 -> L02
L0001: DEC_CHK         L01,#00 [FALSE] L0002
       JUMP            L0005
L0002: LOADB           Ga6,L02 -> L03
       JE              L03,#3a [FALSE] L0003
       STORE           L05,L04
       STORE           L04,#00
       JUMP            L0004
L0003: JG              L04,#2710 [TRUE] RFALSE
       JL              L03,#3a [FALSE] RFALSE
       JG              L03,#2f [FALSE] RFALSE
       MUL             L04,#0a -> L06
       SUB             L03,#30 -> -(SP)
       ADD             L06,(SP)+ -> L04
L0004: INC             L02
       JUMP            L0001
L0005: STOREW          Ga7,L00,"intnum"
       JG              L04,#03e8 [TRUE] RFALSE
       JZ              L05 [TRUE] L0008
       JL              L05,#08 [FALSE] L0006
       ADD             L05,#0c -> L05
       JUMP            L0007
L0006: JG              L05,#17 [TRUE] RFALSE
L0007: MUL             L05,#3c -> -(SP)
       ADD             L04,(SP)+ -> L04
L0008: STORE           G98,L04
       RET             "intnum"

Routine R0015, 8 locals (ffff, 0000, 0000, 0000, 0000, 0000, 0000, 0000)

       STORE           Ga2,#00
       LOADW           G9d,#00 -> L02
       JZ              L02 [TRUE] L0001
       LOADW           G9c,#00 -> -(SP)
       JE              L02,(SP)+ [FALSE] RFALSE
L0001: JE              G9a,#02 [TRUE] RFALSE
       LOADW           G9c,#06 -> -(SP)
       JE              (SP)+,#01 [FALSE] L0003
       LOADW           G9d,#02 -> L01
       LOADW           G9c,#02 -> -(SP)
       JE              L01,(SP)+ [TRUE] L0002
       JZ              L01 [FALSE] RFALSE
L0002: LOADW           G9d,#06 -> -(SP)
       STOREW          G9c,#06,(SP)+
       LOADW           G9d,#07 -> -(SP)
       STOREW          G9c,#07,(SP)+
       JUMP            L0013
L0003: LOADW           G9c,#08 -> -(SP)
       JE              (SP)+,#01 [FALSE] L0005
       LOADW           G9d,#02 -> L01
       LOADW           G9c,#04 -> -(SP)
       JE              L01,(SP)+ [TRUE] L0004
       JZ              L01 [FALSE] RFALSE
L0004: LOADW           G9d,#06 -> -(SP)
       STOREW          G9c,#08,(SP)+
       LOADW           G9d,#07 -> -(SP)
       STOREW          G9c,#09,(SP)+
       STORE           G9a,#02
       JUMP            L0013
L0005: JZ              Ga0 [TRUE] L0013
       JE              G9a,#01 [TRUE] L0006
       STORE           Ga0,#00
       RFALSE          
L0006: LOADW           G9d,#06 -> L03
       LOADW           G9d,#07 -> L04
L0007: JE              L03,L04 [FALSE] L0009
       JZ              L05 [TRUE] L0008
       CALL            R0016 (L05) -> -(SP)
       JUMP            L0013
L0008: STORE           Ga0,#00
       RFALSE          
L0009: JZ              L05 [FALSE] L0010
       LOADW           L03,#00 -> L06
       LOADB           L06,#04 -> -(SP)
       TEST            (SP)+,#20 [FALSE] L0010
       STORE           L05,L06
       JUMP            L0012
L0010: LOADB           L06,#04 -> -(SP)
       TEST            (SP)+,#80 [TRUE] L0011
       JE              L06,"one" [FALSE] L0012
L0011: JE              L06,G9f,"one" [FALSE] RFALSE
       CALL            R0016 (L05) -> -(SP)
       JUMP            L0013
L0012: ADD             L03,#04 -> L03
       JUMP            L0007
L0013: INC_CHK         L00,#09 [FALSE] L0014
       STORE           Ga1,#01
       RTRUE           
L0014: LOADW           G9c,L00 -> -(SP)
       STOREW          G9d,L00,(SP)+
       JUMP            L0013

Routine R0016, 1 local (0000)

       STORE           Gab,G9c
       ADD             Ga0,#01 -> -(SP)
       CALL            R0026 (Ga0,(SP)+,L00) -> -(SP)
       LOADW           G9c,#08 -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       STORE           G9a,#02
L0001: STORE           Ga0,#00
       RTRUE           

Routine R0017, 2 locals (0000, 0000)

L0001: DEC_CHK         L00,#00 [TRUE] RTRUE
       LOADB           Ga6,L01 -> -(SP)
       PRINT_CHAR      (SP)+
       INC             L01
       JUMP            L0001

Routine R0018, 3 locals (0000, 0000, 0000)

       PRINT           "The word '"
       MUL             L00,#02 -> L01
       ADD             Ga7,L01 -> -(SP)
       LOADB           (SP)+,#02 -> L02
       ADD             Ga7,L01 -> -(SP)
       LOADB           (SP)+,#03 -> -(SP)
       CALL            R0017 (L02,(SP)+) -> -(SP)
       PRINT           "' isn't in your vocabulary."
       NEW_LINE        
       STORE           G99,#00
       STORE           Ga2,#00
       RTRUE           

Routine R0019, 3 locals (0000, 0000, 0000)

       PRINT           "The word '"
       MUL             L00,#02 -> L01
       ADD             Ga7,L01 -> -(SP)
       LOADB           (SP)+,#02 -> L02
       ADD             Ga7,L01 -> -(SP)
       LOADB           (SP)+,#03 -> -(SP)
       CALL            R0017 (L02,(SP)+) -> -(SP)
       PRINT           "' can't be used in that sense."
       NEW_LINE        
       STORE           G99,#00
       STORE           Ga2,#00
       RTRUE           

Routine R0020, 11 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000,
                          0000, 0000)

       LOADW           G9d,#00 -> L07
       JZ              L07 [FALSE] L0001
       PRINT           "There's no verb in that sentence!"
       NEW_LINE        
       RFALSE          
L0001: SUB             #ff,L07 -> -(SP)
       LOADW           Gc5,(SP)+ -> L00
       LOADB           L00,#00 -> L01
       ADD             #01,L00 -> L00
L0002: LOADB           L00,#00 -> -(SP)
       AND             (SP)+,#03 -> L02
       JL              L02,#01 [TRUE] L0004
       JZ              G9a [FALSE] L0004
       LOADW           G9d,#02 -> L06
       JZ              L06 [TRUE] L0003
       LOADB           L00,#01 -> -(SP)
       JE              L06,(SP)+ [FALSE] L0004
L0003: STORE           L04,L00
       JUMP            L0006
L0004: LOADB           L00,#01 -> L0a
       LOADW           G9d,#02 -> -(SP)
       JE              L0a,(SP)+ [FALSE] L0006
       JE              L02,#02 [FALSE] L0005
       JE              G9a,#01 [FALSE] L0005
       STORE           L05,L00
       JUMP            L0006
L0005: LOADB           L00,#02 -> L0a
       LOADW           G9d,#04 -> -(SP)
       JE              L0a,(SP)+ [FALSE] L0006
       CALL            R0029 (L00) -> -(SP)
       RTRUE           
L0006: DEC_CHK         L01,#01 [FALSE] L0008
       JZ              L04 [FALSE] L0009
       JZ              L05 [TRUE] L0007
       JUMP            L0009
L0007: PRINT           "That last sentence didn't make sense."
       NEW_LINE        
       RFALSE          
L0008: ADD             L00,#08 -> L00
       JUMP            L0002
L0009: JZ              L04 [TRUE] L0010
       LOADB           L04,#03 -> L09
       LOADB           L04,#05 -> L0a
       LOADB           L04,#01 -> -(SP)
       CALL            R0030 (L09,L0a,(SP)+) -> L03
       JZ              L03 [TRUE] L0010
       STOREW          G92,G8d,#01
       STOREW          G92,#01,L03
       CALL            R0029 (L04) -> -(SP)
       RET_POPPED      
L0010: JZ              L05 [TRUE] L0011
       LOADB           L05,#04 -> L09
       LOADB           L05,#06 -> L0a
       LOADB           L05,#02 -> -(SP)
       CALL            R0030 (L09,L0a,(SP)+) -> L03
       JZ              L03 [TRUE] L0011
       STOREW          G91,G8d,#01
       STOREW          G91,#01,L03
       CALL            R0029 (L05) -> -(SP)
       RET_POPPED      
L0011: JE              L07,#b6,#fa [FALSE] L0012
       PRINT           "That question cannot be answered."
       NEW_LINE        
       RFALSE          
L0012: CALL            R0021 (L04,L05) -> -(SP)
       PRINT           "What do you want to "
       LOADW           G9c,#01 -> L08
       JZ              L08 [FALSE] L0013
       PRINT           "tell"
       JUMP            L0015
L0013: LOADB           G9b,#02 -> -(SP)
       JZ              (SP)+ [FALSE] L0014
       LOADW           L08,#00 -> -(SP)
       PRINT_ADDR      (SP)+
       JUMP            L0015
L0014: LOADB           L08,#02 -> L0a
       LOADB           L08,#03 -> -(SP)
       CALL            R0017 (L0a,(SP)+) -> -(SP)
       STOREB          G9b,#02,#00
L0015: JZ              L05 [TRUE] L0016
       CALL            R0022 (#06,#07) -> -(SP)
L0016: STORE           Ga2,#01
       JZ              L04 [TRUE] L0017
       LOADB           L04,#01 -> -(SP)
       JUMP            L0018
L0017: LOADB           L05,#02 -> -(SP)
L0018: CALL            R0025 ((SP)+) -> -(SP)
       PRINT           "?"
       NEW_LINE        
       RFALSE          

Routine R0021, 3 locals (0000, 0000, ffff)

       STOREW          G8e,G8d,#00
       STORE           Gab,G9d
L0001: INC_CHK         L02,#09 [FALSE] L0002
       JUMP            L0003
L0002: LOADW           G9d,L02 -> -(SP)
       STOREW          G9c,L02,(SP)+
       JUMP            L0001
L0003: JE              G9a,#02 [FALSE] L0004
       CALL            R0026 (#08,#09) -> -(SP)
L0004: JL              G9a,#01 [TRUE] L0005
       CALL            R0026 (#06,#07) -> -(SP)
L0005: JZ              L00 [TRUE] L0006
       LOADB           L00,#01 -> -(SP)
       STOREW          G9c,#02,(SP)+
       STOREW          G9c,#06,#01
       RTRUE           
L0006: JZ              L01 [TRUE] RFALSE
       LOADB           L01,#02 -> -(SP)
       STOREW          G9c,#04,(SP)+
       STOREW          G9c,#08,#01
       RTRUE           

Routine R0022, 4 locals (0000, 0000, 0001, 0000)

       LOADW           G9d,L00 -> L03
       LOADW           G9d,L01 -> -(SP)
       CALL            R0023 (L03,(SP)+,L02) -> -(SP)
       RET_POPPED      

Routine R0023, 8 locals (0000, 0000, 0000, 0000, 0000, 0001, 0000, 0000)

L0001: JE              L00,L01 [TRUE] RTRUE
       JZ              L03 [TRUE] L0002
       STORE           L03,#00
       JUMP            L0003
L0002: PRINT           " "
L0003: LOADW           L00,#00 -> L04
       JE              L04,"." [FALSE] L0004
       STORE           L03,#01
       JUMP            L0014
L0004: JE              L04,"mrs" [FALSE] L0005
       PRINT           "Mrs."
       STORE           L06,#01
       JUMP            L0014
L0005: JE              L04,"ms" [FALSE] L0006
       PRINT           "Ms."
       STORE           L06,#01
       JUMP            L0014
L0006: JE              L04,"mr" [FALSE] L0007
       PRINT           "Mr."
       STORE           L06,#01
       JUMP            L0014
L0007: JE              L04,"baxter","george","robner" [TRUE] L0008
       JE              L04,"mcnabb","rourke","dunbar" [TRUE] L0008
       JE              L04,"steven","steve","duffy" [FALSE] L0009
L0008: CALL            R0024 (L00) -> -(SP)
       STORE           L06,#01
       JUMP            L0014
L0009: JZ              L05 [TRUE] L0010
       JZ              L06 [FALSE] L0010
       JZ              L02 [TRUE] L0010
       PRINT           "the "
L0010: JZ              Ga2 [TRUE] L0011
       PRINT_ADDR      L04
       JUMP            L0013
L0011: JE              L04,"it" [FALSE] L0012
       JE              Ga3,G00 [FALSE] L0012
       PRINT_OBJ       Ga4
       JUMP            L0013
L0012: LOADB           L00,#02 -> L07
       LOADB           L00,#03 -> -(SP)
       CALL            R0017 (L07,(SP)+) -> -(SP)
L0013: STORE           L05,#00
L0014: ADD             L00,#04 -> L00
       JUMP            L0001

Routine R0024, 2 locals (0000, 0000)

       LOADB           L00,#03 -> -(SP)
       LOADB           Ga6,(SP)+ -> -(SP)
       SUB             (SP)+,#20 -> -(SP)
       PRINT_CHAR      (SP)+
       LOADB           L00,#02 -> -(SP)
       SUB             (SP)+,#01 -> L01
       LOADB           L00,#03 -> -(SP)
       ADD             (SP)+,#01 -> -(SP)
       CALL            R0017 (L01,(SP)+) -> -(SP)
       RET_POPPED      

Routine R0025, 2 locals (0000, 0000)

       JZ              L00 [TRUE] RFALSE
       PRINT           " "
       CALL            R0028 (L00) -> L01
       JE              L01,"agains" [FALSE] L0001
       PRINT           "against"
       RTRUE           
L0001: PRINT_ADDR      L01
       RTRUE           

Routine R0026, 5 locals (0000, 0000, 0000, 0000, 0000)

       LOADW           Gab,L00 -> L03
       LOADW           Gab,L01 -> L04
       LOADW           G8e,G8d -> -(SP)
       MUL             (SP)+,#02 -> -(SP)
       ADD             (SP)+,#02 -> -(SP)
       ADD             G8e,(SP)+ -> -(SP)
       STOREW          G9c,L00,(SP)+
L0001: JE              L03,L04 [FALSE] L0002
       LOADW           G8e,G8d -> -(SP)
       MUL             (SP)+,#02 -> -(SP)
       ADD             (SP)+,#02 -> -(SP)
       ADD             G8e,(SP)+ -> -(SP)
       STOREW          G9c,L01,(SP)+
       RTRUE           
L0002: JZ              L02 [TRUE] L0003
       LOADW           L03,#00 -> -(SP)
       JE              G9f,(SP)+ [FALSE] L0003
       CALL            R0027 (L02) -> -(SP)
L0003: LOADW           L03,#00 -> -(SP)
       CALL            R0027 ((SP)+) -> -(SP)
       ADD             L03,#04 -> L03
       JUMP            L0001

Routine R0027, 2 locals (0000, 0000)

       LOADW           G8e,G8d -> -(SP)
       ADD             (SP)+,#02 -> L01
       SUB             L01,#01 -> -(SP)
       STOREW          G8e,(SP)+,L00
       STOREW          G8e,L01,#00
       STOREW          G8e,G8d,L01
       RTRUE           

Routine R0028, 3 locals (0000, 0000, 0000)

       LOADW           Gc2,#00 -> -(SP)
       MUL             (SP)+,#02 -> L02
L0001: INC_CHK         L01,L02 [TRUE] RFALSE
       LOADW           Gc2,L01 -> -(SP)
       JE              (SP)+,L00 [FALSE] L0001
       SUB             L01,#01 -> -(SP)
       LOADW           Gc2,(SP)+ -> -(SP)
       RET             (SP)+

Routine R0029, 1 local (0000)

       STORE           Gac,L00
       LOADB           L00,#07 -> Gb1
       RET             Gb1

Routine R0030, 4 locals (0000, 0000, 0000, 0000)

       JE              L00,#03 [FALSE] L0001
       RET             #fd
L0001: STORE           G96,L00
       STORE           G97,L01
       STOREW          G8f,G8d,#00
       CALL            R0034 (G8f,#00) -> -(SP)
       JZ              (SP)+ [TRUE] L0004
       STORE           G96,#00
       LOADW           G8f,G8d -> -(SP)
       JE              (SP)+,#01 [FALSE] RFALSE
       LOADW           G8f,#01 -> L03
       PRINT           "("
       JZ              L02 [TRUE] L0003
       CALL            R0028 (L02) -> -(SP)
       PRINT_ADDR      (SP)+
       TEST_ATTR       L03,#14 [TRUE] L0002
       PRINT           " the "
       JUMP            L0003
L0002: PRINT           " "
L0003: PRINT_OBJ       L03
       PRINT           ")"
       NEW_LINE        
       RET             L03
L0004: STORE           G96,#00
       RFALSE          

Routine R0031, 1 local (0000)

       LOADW           G9d,#06 -> L00
       JZ              L00 [TRUE] L0001
       LOADB           Gac,#05 -> G97
       LOADW           G9d,#07 -> -(SP)
       CALL            R0033 (L00,(SP)+,G92) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       LOADW           G90,G8d -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       CALL            R0032 (G92) -> G92
L0001: LOADW           G9d,#08 -> L00
       JZ              L00 [TRUE] RTRUE
       LOADB           Gac,#06 -> G97
       LOADW           G9d,#09 -> -(SP)
       CALL            R0033 (L00,(SP)+,G91) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       LOADW           G90,G8d -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       LOADW           G91,G8d -> -(SP)
       JE              (SP)+,#01 [FALSE] L0002
       CALL            R0032 (G92) -> G92
       RTRUE           
L0002: CALL            R0032 (G91) -> G91
       RTRUE           

Routine R0032, 7 locals (0000, 0000, 0000, 0001, 0000, 0000, 0000)

       LOADW           L00,G8d -> L01
       STOREW          G8f,G8d,#00
L0001: DEC_CHK         L01,#00 [FALSE] L0002
       JUMP            L0005
L0002: LOADW           L00,L03 -> L05
       CALL            R0043 (L05,G90) -> -(SP)
       JZ              (SP)+ [TRUE] L0003
       JUMP            L0004
L0003: ADD             L04,#01 -> -(SP)
       STOREW          G8f,(SP)+,L05
       INC             L04
L0004: INC             L03
       JUMP            L0001
L0005: STOREW          G8f,G8d,L04
       STORE           L06,G8f
       STORE           G8f,L00
       RET             L06

Routine R0033, 9 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000)

       STORE           G8c,#00
       STORE           G8b,L00
       STORE           G8a,L01
       STOREW          G90,G8d,#00
       STOREW          L02,G8d,#00
       LOADW           L00,#00 -> L07
L0001: JE              L00,L01 [FALSE] L0004
       JZ              L04 [TRUE] L0002
       PUSH            L04
       JUMP            L0003
L0002: PUSH            L02
L0003: CALL            R0034 ((SP)+) -> -(SP)
       RET             (SP)+
L0004: LOADW           L00,#02 -> L08
       JE              L07,"all" [FALSE] L0005
       STORE           G8c,#01
       JE              L08,"of" [FALSE] L0020
       ADD             L00,#04 -> L00
       JUMP            L0020
L0005: JE              L07,"but","except" [FALSE] L0008
       JZ              L04 [TRUE] L0006
       PUSH            L04
       JUMP            L0007
L0006: PUSH            L02
L0007: CALL            R0034 ((SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       STORE           L04,G90
       STOREW          L04,G8d,#00
       JUMP            L0020
L0008: JE              L07,"a","one" [FALSE] L0012
       JZ              G94 [FALSE] L0009
       STORE           G8c,#02
       JE              L08,"of" [FALSE] L0020
       ADD             L00,#04 -> L00
       JUMP            L0020
L0009: STORE           G95,Gad
       JZ              L04 [TRUE] L0010
       PUSH            L04
       JUMP            L0011
L0010: PUSH            L02
L0011: CALL            R0034 ((SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       JZ              L08 [TRUE] RTRUE
       JUMP            L0020
L0012: JE              L07,"and","," [FALSE] L0015
       JE              L08,"and","," [TRUE] L0015
       JZ              L04 [TRUE] L0013
       PUSH            L04
       JUMP            L0014
L0013: PUSH            L02
L0014: CALL            R0034 ((SP)+) -> -(SP)
       JZ              (SP)+ [FALSE] L0020
       RFALSE          
L0015: CALL            R0012 (L07,#04) -> -(SP)
       JZ              (SP)+ [TRUE] L0016
       JUMP            L0020
L0016: JE              L07,"and","," [FALSE] L0017
       JUMP            L0020
L0017: JE              L07,"of" [FALSE] L0018
       JZ              G8c [FALSE] L0020
       STORE           G8c,#04
       JUMP            L0020
L0018: CALL            R0012 (L07,#20,#02) -> L06
       JZ              L06 [TRUE] L0019
       JZ              G94 [FALSE] L0019
       STORE           G94,L06
       STORE           G93,L07
       JUMP            L0020
L0019: CALL            R0012 (L07,#80,#00) -> -(SP)
       JZ              (SP)+ [TRUE] L0020
       STORE           G95,L07
       STORE           Gad,L07
L0020: JE              L00,L01 [TRUE] L0001
       ADD             L00,#04 -> L00
       STORE           L07,L08
       JUMP            L0001

Routine R0034, 8 locals (0000, 0001, 0000, 0000, 0000, 0000, 0000, 0000)

       STORE           L04,G97
       LOADW           L00,G8d -> L05
       TEST            G8c,#04 [TRUE] RTRUE
       JZ              G95 [FALSE] L0001
       JZ              G94 [TRUE] L0001
       CALL            R0012 (G93,#80,#00) -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       STORE           G95,G93
       STORE           G94,#00
L0001: JZ              G95 [FALSE] L0002
       JZ              G94 [FALSE] L0002
       JE              G8c,#01 [TRUE] L0002
       JZ              G96 [FALSE] L0002
       JZ              L01 [TRUE] RFALSE
       PRINT           "Your last sentence seemed to be missing a noun."
       NEW_LINE        
       RFALSE          
L0002: JE              G8c,#01 [FALSE] L0003
       JZ              G97 [FALSE] L0004
L0003: STORE           G97,#ffff
L0004: STORE           Gae,L00
L0005: JZ              L06 [TRUE] L0006
       CALL            R0036 (L00) -> -(SP)
       JUMP            L0008
L0006: JZ              G87 [TRUE] L0007
       CALL            R0037 (G00,#10,#20) -> -(SP)
L0007: CALL            R0037 (#a0,#80,#40) -> -(SP)
L0008: LOADW           L00,G8d -> -(SP)
       SUB             (SP)+,L05 -> L03
       TEST            G8c,#01 [FALSE] L0009
       JUMP            L0026
L0009: TEST            G8c,#02 [FALSE] L0011
       JZ              L03 [TRUE] L0011
       JE              L03,#01 [TRUE] L0010
       RANDOM          L03 -> -(SP)
       LOADW           L00,(SP)+ -> -(SP)
       STOREW          L00,#01,(SP)+
       PRINT           "(How about the "
       LOADW           L00,#01 -> -(SP)
       PRINT_OBJ       (SP)+
       PRINT           "?)"
       NEW_LINE        
L0010: STOREW          L00,G8d,#01
       JUMP            L0026
L0011: JG              L03,#01 [TRUE] L0012
       JZ              L03 [FALSE] L0019
       JE              G97,#ffff [TRUE] L0019
L0012: JE              G97,#ffff [FALSE] L0013
       STORE           G97,L04
       STORE           L07,L03
       LOADW           L00,G8d -> -(SP)
       SUB             (SP)+,L03 -> -(SP)
       STOREW          L00,G8d,(SP)+
       JUMP            L0005
L0013: JZ              L03 [FALSE] L0014
       STORE           L03,L07
L0014: JZ              L01 [TRUE] L0017
       JZ              G95 [TRUE] L0017
       CALL            R0035 (L05,L03,L00) -> -(SP)
       JE              L00,G92 [FALSE] L0015
       PUSH            #06
       JUMP            L0016
L0015: PUSH            #08
L0016: STORE           Ga0,(SP)+
       STORE           G9e,G94
       STORE           G9f,G95
       CALL            R0021 (#00,#00) -> -(SP)
       STORE           Ga2,#01
       JUMP            L0018
L0017: JZ              L01 [TRUE] L0018
       PRINT           "You must supply a verb!"
       NEW_LINE        
L0018: STORE           G95,#00
       STORE           G94,#00
       RFALSE          
L0019: JZ              L03 [FALSE] L0025
       JZ              L06 [TRUE] L0025
       JZ              L01 [TRUE] L0024
       JZ              G87 [TRUE] L0023
       PRINT           "You can't see any"
       JZ              Ga2 [TRUE] L0021
       JZ              G94 [TRUE] L0020
       PRINT           " "
       PRINT_ADDR      G93
L0020: JZ              G95 [TRUE] L0022
       PRINT           " "
       PRINT_ADDR      G95
       JUMP            L0022
L0021: CALL            R0023 (G8b,G8a,#00) -> -(SP)
L0022: PRINT           " here."
       NEW_LINE        
       JUMP            L0024
L0023: PRINT           "It's too dark to see."
       NEW_LINE        
L0024: STORE           G95,#00
       STORE           G94,#00
       RFALSE          
L0025: JZ              L03 [FALSE] L0026
       STORE           L06,#01
       JUMP            L0005
L0026: STORE           G94,#00
       STORE           G95,#00
       STORE           G97,L04
       RTRUE           

Routine R0035, 5 locals (0000, 0000, 0000, 0000, 0000)

       STORE           L04,L01
       PRINT           "Which "
       JZ              Ga2 [FALSE] L0001
       JZ              Ga1 [TRUE] L0002
L0001: PRINT           " "
       PRINT_ADDR      G95
       JUMP            L0004
L0002: JE              L02,G92 [FALSE] L0003
       CALL            R0022 (#06,#07,#00) -> -(SP)
       JUMP            L0004
L0003: CALL            R0022 (#08,#09,#00) -> -(SP)
L0004: PRINT           " do you mean, "
L0005: INC             L00
       LOADW           L02,L00 -> L03
       TEST_ATTR       L03,#14 [TRUE] L0006
       PRINT           "the "
L0006: PRINT_OBJ       L03
       JE              L01,#02 [FALSE] L0008
       JE              L04,#02 [TRUE] L0007
       PRINT           ","
L0007: PRINT           " or "
       JUMP            L0009
L0008: JG              L01,#02 [FALSE] L0009
       PRINT           ", "
L0009: DEC_CHK         L01,#01 [FALSE] L0005
       PRINT_RET       "?"

Routine R0036, 8 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000)

       LOADW           L00,G8d -> L01
       STORE           L06,G97
       GET_PROP_ADDR   G00,#0f -> L02
       JZ              L02 [TRUE] L0003
       GET_PROP_LEN    L02 -> -(SP)
       SUB             (SP)+,#01 -> L03
L0001: LOADB           L02,L04 -> L05
       CALL            R0048 (L05,L00) -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       CALL            R0039 (L05,L00) -> -(SP)
L0002: INC_CHK         L04,L03 [FALSE] L0001
L0003: GET_PROP_ADDR   G00,#0b -> L02
       JZ              L02 [TRUE] L0006
       GET_PROP_LEN    L02 -> -(SP)
       DIV             (SP)+,#04 -> -(SP)
       SUB             (SP)+,#01 -> L03
       STORE           L04,#00
L0004: MUL             L04,#02 -> -(SP)
       LOADW           L02,(SP)+ -> -(SP)
       JE              G95,(SP)+ [FALSE] L0005
       MUL             L04,#02 -> -(SP)
       ADD             (SP)+,#01 -> -(SP)
       LOADW           L02,(SP)+ -> -(SP)
       PUT_PROP        "FROBNO",#12,(SP)+
       GET_PROP_ADDR   "FROBNO",#12 -> -(SP)
       SUB             (SP)+,#05 -> L07
       LOADW           G95,#00 -> -(SP)
       STOREW          L07,#00,(SP)+
       LOADW           G95,#01 -> -(SP)
       STOREW          L07,#01,(SP)+
       CALL            R0039 (#fc,L00) -> -(SP)
       JUMP            L0006
L0005: INC_CHK         L04,L03 [FALSE] L0004
L0006: LOADW           L00,G8d -> -(SP)
       JE              (SP)+,L01 [FALSE] RFALSE
       STORE           G97,#ffff
       STORE           Gae,L00
       CALL            R0037 (#ff,#01,#01) -> -(SP)
       STORE           G97,L06
       LOADW           L00,G8d -> -(SP)
       JZ              (SP)+ [FALSE] RFALSE
       JE              Gb1,#4a,#50 [TRUE] L0007
       JE              Gb1,#2f,#32,#2d [FALSE] RFALSE
L0007: CALL            R0037 (#fd,#01,#01) -> -(SP)
       RET_POPPED      

Routine R0037, 4 locals (0000, 0000, 0000, 0000)

       ADD             L01,L02 -> -(SP)
       TEST            G97,(SP)+ [FALSE] L0001
       CALL            R0038 (L00,Gae,#01) -> -(SP)
       RET_POPPED      
L0001: TEST            G97,L01 [FALSE] L0002
       CALL            R0038 (L00,Gae,#00) -> -(SP)
       RET_POPPED      
L0002: TEST            G97,L02 [FALSE] RTRUE
       CALL            R0038 (L00,Gae,#02) -> -(SP)
       RET_POPPED      

Routine R0038, 5 locals (0000, 0000, 0000, 0000, 0000)

       GET_CHILD       L00 -> L00 [FALSE] RFALSE
L0001: JE              L02,#02 [TRUE] L0002
       GET_PROP_ADDR   L00,#13 -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       CALL            R0048 (L00,L01) -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       CALL            R0039 (L00,L01) -> -(SP)
L0002: JE              L02,#00 [FALSE] L0003
       TEST_ATTR       L00,#1a [TRUE] L0003
       TEST_ATTR       L00,#1d [FALSE] L0008
L0003: GET_CHILD       L00 -> L04 [FALSE] L0008
       TEST_ATTR       L00,#1c [TRUE] L0004
       TEST_ATTR       L00,#1b [FALSE] L0008
L0004: TEST_ATTR       L00,#1d [FALSE] L0005
       PUSH            #01
       JUMP            L0007
L0005: TEST_ATTR       L00,#1a [FALSE] L0006
       PUSH            #01
       JUMP            L0007
L0006: PUSH            #00
L0007: CALL            R0038 (L00,L01,(SP)+) -> L03
L0008: GET_SIBLING     L00 -> L00 [TRUE] L0001
       RTRUE           

Routine R0039, 3 locals (0000, 0000, 0000)

       LOADW           L01,G8d -> L02
       ADD             L02,#01 -> -(SP)
       STOREW          L01,(SP)+,L00
       ADD             L02,#01 -> -(SP)
       STOREW          L01,G8d,(SP)+
       RTRUE           

Routine R0040, 0 locals ()

       LOADB           Gac,#05 -> -(SP)
       CALL            R0041 (G92,(SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       LOADB           Gac,#06 -> -(SP)
       CALL            R0041 (G91,(SP)+) -> -(SP)
       RET_POPPED      

Routine R0041, 5 locals (0000, 0000, 0000, 0000, 0000)

       LOADW           L00,G8d -> L02
       JZ              L02 [TRUE] RTRUE
       TEST            L01,#08 [FALSE] RTRUE
L0001: DEC_CHK         L02,#00 [TRUE] RTRUE
       ADD             L02,#01 -> -(SP)
       LOADW           L00,(SP)+ -> L03
       JE              L03,#fb [FALSE] L0002
       STORE           L03,Ga4
L0002: JIN             L03,Ga8 [TRUE] L0001
       STORE           Gaf,L03
       TEST_ATTR       L03,#0b [FALSE] L0003
       STORE           L04,#01
       JUMP            L0005
L0003: CALL            R0078 (#00) -> -(SP)
       JE              (SP)+,#01 [FALSE] L0004
       STORE           L04,#00
       JUMP            L0005
L0004: STORE           L04,#01
L0005: JZ              L04 [TRUE] L0006
       TEST            L01,#02 [FALSE] L0006
       PRINT           "You don't have the "
       PRINT_OBJ       L03
       PRINT           "."
       NEW_LINE        
       RFALSE          
L0006: JZ              L04 [FALSE] L0001
       PRINT           "(Taken)"
       NEW_LINE        
       JUMP            L0001

Routine R0042, 3 locals (0000, 0000, 0000)

       LOADW           G92,G8d -> -(SP)
       JG              (SP)+,#01 [FALSE] L0001
       LOADB           Gac,#05 -> -(SP)
       TEST            (SP)+,#04 [TRUE] L0001
       STORE           L00,#01
       JUMP            L0002
L0001: LOADW           G91,G8d -> -(SP)
       JG              (SP)+,#01 [FALSE] L0002
       LOADB           Gac,#06 -> -(SP)
       TEST            (SP)+,#04 [TRUE] L0002
       STORE           L00,#02
L0002: JZ              L00 [TRUE] RTRUE
       PRINT           "You can't use multiple "
       JE              L00,#02 [FALSE] L0003
       PRINT           "in"
L0003: PRINT           "direct objects with '"
       LOADW           G9d,#01 -> L01
       JZ              L01 [FALSE] L0004
       PRINT           "tell"
       JUMP            L0006
L0004: JZ              Ga2 [TRUE] L0005
       LOADW           L01,#00 -> -(SP)
       PRINT_ADDR      (SP)+
       JUMP            L0006
L0005: LOADB           L01,#02 -> L02
       LOADB           L01,#03 -> -(SP)
       CALL            R0017 (L02,(SP)+) -> -(SP)
L0006: PRINT           "'."
       NEW_LINE        
       RFALSE          

Routine R0043, 4 locals (0000, 0000, ffff, 0001)

       JZ              L01 [TRUE] RFALSE
       JL              L02,#00 [TRUE] L0001
       STORE           L03,#00
       JUMP            L0002
L0001: LOADW           L01,#00 -> L02
L0002: LOADW           L01,L03 -> -(SP)
       JE              L00,(SP)+ [TRUE] RTRUE
       INC_CHK         L03,L02 [FALSE] L0002
       RFALSE          

Routine R0044, 4 locals (0000, 0000, 0000, 0000)

L0001: LOADB           L01,L03 -> -(SP)
       JE              L00,(SP)+ [TRUE] RTRUE
       INC_CHK         L03,L02 [FALSE] L0001
       RFALSE          

Routine R0045, 3 locals (0000, 0000, 0000)

       STORE           G96,#17
       STORE           L01,G00
       STORE           G00,L00
       TEST_ATTR       L00,#17 [TRUE] L0001
       JZ              Gb3 [TRUE] L0002
L0001: STORE           L02,#01
       JUMP            L0004
L0002: STOREW          G8f,G8d,#00
       STORE           Gae,G8f
       STORE           G97,#ffff
       JE              L01,L00 [FALSE] L0003
       CALL            R0037 (Ga8,#01,#01) -> -(SP)
L0003: CALL            R0037 (L00,#01,#01) -> -(SP)
       LOADW           Gae,G8d -> -(SP)
       JG              (SP)+,#00 [FALSE] L0004
       STORE           L02,#01
L0004: STORE           G00,L01
       STORE           G96,#00
       RET             L02

Routine R0046, 1 local (0000)

       JZ              Ga1 [FALSE] L0001
       LOADW           G9d,#06 -> L00
       LOADW           L00,#00 -> -(SP)
       JE              (SP)+,"it" [FALSE] L0002
L0001: PRINT           " "
       PRINT_OBJ       Gaf
       RTRUE           
L0002: LOADW           G9d,#07 -> -(SP)
       CALL            R0023 (L00,(SP)+,#00) -> -(SP)
       RET_POPPED      

Routine R0047, 1 local (0000)

       JZ              Ga1 [FALSE] L0001
       LOADW           G9d,#08 -> L00
       LOADW           L00,#00 -> -(SP)
       JE              (SP)+,"it" [FALSE] L0002
L0001: PRINT           " "
       PRINT_OBJ       Gaf
       RTRUE           
L0002: LOADW           G9d,#09 -> -(SP)
       CALL            R0023 (L00,(SP)+,#00) -> -(SP)
       RET_POPPED      

Routine R0048, 4 locals (0000, 0000, 0000, 0000)

       TEST_ATTR       L00,#1f [TRUE] RFALSE
       JZ              G95 [TRUE] L0001
       GET_PROP_ADDR   L00,#13 -> L02
       GET_PROP_LEN    L02 -> -(SP)
       DIV             (SP)+,#02 -> -(SP)
       SUB             (SP)+,#01 -> -(SP)
       CALL            R0043 (G95,L02,(SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
L0001: JZ              G94 [TRUE] L0002
       GET_PROP_ADDR   L00,#10 -> L02
       JZ              L02 [TRUE] RFALSE
       GET_PROP_LEN    L02 -> -(SP)
       SUB             (SP)+,#01 -> -(SP)
       CALL            R0044 (G94,L02,(SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
L0002: JZ              G96 [TRUE] RTRUE
       TEST_ATTR       L00,G96 [TRUE] RTRUE
       RFALSE          

Routine R0049, 0 locals ()
    Action routine for:
        "verbos"

       STORE           G89,#01
       STORE           G88,#00
       PRINT_RET       "OK, you will get verbose descriptions."

Routine R0050, 0 locals ()
    Action routine for:
        "brief"

       STORE           G89,#00
       STORE           G88,#00
       PRINT_RET       "OK, you will get brief descriptions."

Routine R0051, 0 locals ()
    Action routine for:
        "super"

       STORE           G88,#01
       PRINT_RET       "OK, you will get super-brief descriptions. Remember
that objects and people are not mentioned; only the name of the place you are
in."

Routine R0052, 0 locals ()
    Action routine for:
        "gaze around OBJ"
        "gaze"

       CALL            R0058 (#01) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       CALL            R0059 (#01) -> -(SP)
       RET_POPPED      

Routine R0053, 0 locals ()

       CALL            R0058 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       JZ              G88 [FALSE] RFALSE
       CALL            R0059 -> -(SP)
       RET_POPPED      

Routine R0054, 0 locals ()

       JIN             Gaf,#fd [FALSE] RFALSE
       JE              Gaf,G00 [FALSE] L0001
       STORE           Gaf,#37
       RFALSE          
L0001: PRINT_RET       "You aren't in that room!"

Routine R0055, 0 locals ()
    Pre-action routine for:
        "dig up OBJ"
        "dig in OBJ"
        "dig OBJ"

       CALL            R0054 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       RTRUE           

Routine R0056, 0 locals ()
    Pre-action routine for:
        "watch OBJ"
        "gaze over OBJ"
        "gaze at OBJ"
        "descri OBJ"

       CALL            R0054 -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       JE              G54,"carefu" [FALSE] RFALSE
       CALL            R0105 (#03) -> -(SP)
       JZ              (SP)+ [FALSE] RFALSE
       PRINT           "You never got to finish looking over the "
       PRINT_OBJ       Gaf
       PRINT_RET       "."

Routine R0057, 0 locals ()
    Action routine for:
        "watch OBJ"
        "gaze over OBJ"
        "gaze at OBJ"
        "descri OBJ"

       JIN             Gaf,#ff [FALSE] L0001
       CALL            R0128 (Gaf) -> -(SP)
       RTRUE           
L0001: GET_PROP        Gaf,#04 -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       GET_PROP        Gaf,#04 -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0002: TEST_ATTR       Gaf,#15 [TRUE] L0003
       TEST_ATTR       Gaf,#16 [FALSE] L0004
L0003: CALL            R0133 -> -(SP)
       RET_POPPED      
L0004: TEST_ATTR       Gaf,#14 [FALSE] L0005
       GET_PROP        Gaf,#07 -> -(SP)
       LOADW           G09,(SP)+ -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0005: PRINT           "There's nothing special about the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."

Routine R0058, 3 locals (0000, 0000, 0000)

       JZ              L00 [TRUE] L0001
       PUSH            L00
       JUMP            L0002
L0001: PUSH            G89
L0002: PULL            L01
       TEST_ATTR       G00,#1e [TRUE] L0003
       SET_ATTR        G00,#1e
       STORE           L01,#01
L0003: JIN             G00,#fd [FALSE] L0004
       PRINT_OBJ       G00
       NEW_LINE        
L0004: JZ              L00 [FALSE] L0005
       JZ              G88 [FALSE] L0012
L0005: GET_PARENT      Ga8 -> -(SP)
       TEST_ATTR       (SP)+,#0c [FALSE] L0008
       PRINT           "(You are "
       GET_PARENT      Ga8 -> -(SP)
       TEST_ATTR       (SP)+,#1d [FALSE] L0006
       PRINT           "sitting o"
       JUMP            L0007
L0006: PRINT           "standing i"
L0007: PRINT           "n the "
       GET_PARENT      Ga8 -> -(SP)
       PRINT_OBJ       (SP)+
       PRINT           ".)"
       NEW_LINE        
L0008: JZ              L01 [TRUE] L0009
       GET_PROP        G00,#12 -> -(SP)
       CALL            (SP)+ (#03) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
L0009: JZ              L01 [TRUE] L0010
       GET_PROP        G00,#11 -> L02
       JZ              L02 [TRUE] L0010
       PRINT_PADDR     L02
       NEW_LINE        
       JUMP            L0011
L0010: GET_PROP        G00,#12 -> -(SP)
       CALL            (SP)+ (#04) -> -(SP)
L0011: GET_PARENT      Ga8 -> -(SP)
       JE              G00,(SP)+ [TRUE] L0012
       GET_PARENT      Ga8 -> -(SP)
       GET_PROP        (SP)+,#12 -> -(SP)
       CALL            (SP)+ (#03) -> -(SP)
L0012: GET_PROP        G00,#0c -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       CALL            R0207 -> -(SP)
       RTRUE           

Routine R0059, 1 local (0000)

       JZ              G87 [TRUE] L0003
       GET_CHILD       G00 -> -(SP) [FALSE] RFALSE
       JZ              L00 [TRUE] L0001
       PUSH            L00
       JUMP            L0002
L0001: PUSH            G89
L0002: PULL            L00
       CALL            R0061 (G00,L00,#ffff) -> -(SP)
       RET_POPPED      
L0003: PRINT_RET       "You can't see anything in the dark."

Routine R0060, 5 locals (0000, 0000, 0000, 0000, 0000)

       JZ              L02 [FALSE] L0001
       GET_PROP        L00,#06 -> -(SP)
       CALL            (SP)+ (#05) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
L0001: JZ              L02 [FALSE] L0004
       TEST_ATTR       L00,#1e [TRUE] L0002
       GET_PROP        L00,#09 -> L03
       JZ              L03 [FALSE] L0003
L0002: GET_PROP        L00,#11 -> L03
       JZ              L03 [TRUE] L0004
L0003: PRINT_PADDR     L03
       JUMP            L0006
L0004: JZ              L02 [FALSE] L0005
       PRINT           "There is a "
       PRINT_OBJ       L00
       PRINT           " here."
       JUMP            L0006
L0005: LOADW           G85,L02 -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT           "A "
       PRINT_OBJ       L00
L0006: JZ              L02 [FALSE] L0007
       GET_PARENT      Ga8 -> L04
       JZ              L04 [TRUE] L0007
       TEST_ATTR       L04,#0c [FALSE] L0007
       PRINT           " (outside the "
       PRINT_OBJ       L04
       PRINT           ")"
L0007: NEW_LINE        
       CALL            R0134 (L00) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       GET_CHILD       L00 -> -(SP) [FALSE] RFALSE
       CALL            R0061 (L00,L01,L02) -> -(SP)
       RET_POPPED      

Routine R0061, 9 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000)

       GET_CHILD       L00 -> L03 [FALSE] RTRUE
       GET_PARENT      Ga8 -> L05
       JZ              L05 [TRUE] L0001
       TEST_ATTR       L05,#0c [FALSE] L0001
       JUMP            L0002
L0001: STORE           L05,#00
L0002: STORE           L04,#01
       GET_PARENT      L00 -> -(SP)
       JE              Ga8,L00,(SP)+ [FALSE] L0003
       STORE           L08,#01
       JUMP            L0010
L0003: JZ              L03 [FALSE] L0004
       JUMP            L0010
L0004: JE              L03,L05 [FALSE] L0005
       STORE           L07,#01
       JUMP            L0008
L0005: JE              L03,Ga8 [FALSE] L0006
       JUMP            L0008
L0006: TEST_ATTR       L03,#1f [TRUE] L0008
       TEST_ATTR       L03,#1e [TRUE] L0008
       GET_PROP        L03,#09 -> L06
       JZ              L06 [TRUE] L0008
       TEST_ATTR       L03,#19 [TRUE] L0007
       STORE           L04,#00
       STORE           L02,#00
       PRINT_PADDR     L06
       NEW_LINE        
L0007: CALL            R0134 (L03) -> -(SP)
       JZ              (SP)+ [TRUE] L0008
       GET_PARENT      L03 -> -(SP)
       GET_PROP        (SP)+,#06 -> -(SP)
       JZ              (SP)+ [FALSE] L0008
       GET_CHILD       L03 -> -(SP) [FALSE] L0008
       CALL            R0061 (L03,L01,#00) -> -(SP)
L0008: GET_SIBLING     L03 -> L03 [TRUE] L0009
L0009: JUMP            L0003
L0010: GET_CHILD       L00 -> L03 [TRUE] L0011
L0011: JZ              L03 [FALSE] L0014
       JZ              L07 [TRUE] L0012
       JZ              L05 [TRUE] L0012
       GET_CHILD       L05 -> -(SP) [FALSE] L0012
       CALL            R0061 (L05,L01,L02) -> -(SP)
L0012: JZ              L04 [FALSE] L0013
       PUSH            #01
       RET             (SP)+
L0013: PUSH            #00
       RET             (SP)+
L0014: JE              L03,L05,#a0 [FALSE] L0015
       JUMP            L0020
L0015: TEST_ATTR       L03,#1f [TRUE] L0020
       JZ              L08 [FALSE] L0016
       TEST_ATTR       L03,#1e [TRUE] L0016
       GET_PROP        L03,#09 -> -(SP)
       JZ              (SP)+ [FALSE] L0020
L0016: TEST_ATTR       L03,#19 [TRUE] L0019
       JZ              L04 [TRUE] L0018
       CALL            R0062 (L00,L02) -> -(SP)
       JZ              (SP)+ [TRUE] L0017
       JL              L02,#00 [FALSE] L0017
       STORE           L02,#00
L0017: INC             L02
       STORE           L04,#00
L0018: CALL            R0060 (L03,L01,L02) -> -(SP)
       JUMP            L0020
L0019: GET_CHILD       L03 -> -(SP) [FALSE] L0020
       CALL            R0134 (L03) -> -(SP)
       JZ              (SP)+ [TRUE] L0020
       CALL            R0061 (L03,L01,L02) -> -(SP)
L0020: GET_SIBLING     L03 -> L03 [TRUE] L0021
L0021: JUMP            L0011

Routine R0062, 2 locals (0000, 0000)

       JE              L00,Ga8 [FALSE] L0001
       PRINT_RET       "You are carrying:"
L0001: JIN             L00,#fd [TRUE] RFALSE
       JG              L01,#00 [FALSE] L0002
       LOADW           G85,L01 -> -(SP)
       PRINT_PADDR     (SP)+
L0002: TEST_ATTR       L00,#1d [FALSE] L0003
       PRINT           "Sitting on the "
       PRINT_OBJ       L00
       PRINT_RET       " is:"
L0003: TEST_ATTR       L00,#14 [FALSE] L0004
       PRINT_OBJ       L00
       PRINT_RET       " is holding:"
L0004: PRINT           "The "
       PRINT_OBJ       L00
       PRINT_RET       " contains:"

Routine R0063, 1 local (0001)
    Action routine for:
        "score"

       PRINT_RET       "You are an amateur inspector, at best."

Routine R0064, 2 locals (0001, 0000)
    Action routine for:
        "q"

       JZ              L00 [TRUE] L0001
       PRINT           "Do you wish to stop your investigation (Y/N)"
       CALL            R0065 -> -(SP)
       JZ              (SP)+ [FALSE] L0002
L0001: JZ              L00 [FALSE] L0003
L0002: QUIT            
       RTRUE           
L0003: PRINT_RET       "Ok."

Routine R0065, 0 locals ()

       PRINT           " >"
       READ            Ga6,Ga7
       LOADB           Ga7,#01 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       LOADW           Ga7,#01 -> -(SP)
       JE              (SP)+,"yes","y" [FALSE] RFALSE
       RTRUE           

Routine R0066, 1 local (0011)
    Action routine for:
        "versio"

       PRINT           "DEADLINE: An INTERLOGIC Mystery
Copyright 1982 by Infocom, Inc. All rights reserved.
DEADLINE and INTERLOGIC are trademarks of Infocom, Inc.
Release "
       LOADW           #00,#01 -> -(SP)
       AND             (SP)+,#07ff -> -(SP)
       PRINT_NUM       (SP)+
       PRINT           " / Serial number "
L0001: INC_CHK         L00,#17 [FALSE] L0002
       JUMP            L0003
L0002: LOADB           #00,L00 -> -(SP)
       PRINT_CHAR      (SP)+
       JUMP            L0001
L0003: NEW_LINE        
       RTRUE           

Routine R0067, 1 local (0000)
    Action routine for:
        "again"

       JZ              Gb5 [TRUE] L0001
       GET_PARENT      Gb5 -> -(SP)
       JZ              (SP)+ [FALSE] L0001
       PUSH            Gb5
       JUMP            L0003
L0001: JZ              Gb4 [TRUE] L0002
       GET_PARENT      Gb4 -> -(SP)
       JZ              (SP)+ [FALSE] L0002
       PUSH            Gb4
       JUMP            L0003
L0002: PUSH            #00
L0003: STORE           L00,(SP)+
       JZ              L00 [TRUE] L0004
       PRINT           "You can't see the "
       PRINT_OBJ       L00
       PRINT           " any more."
       NEW_LINE        
       RET             #02
L0004: CALL            R0010 (Gb6,Gb5,Gb4) -> -(SP)
       RET_POPPED      

Routine R0068, 0 locals ()
    Action routine for:
        "restor"

       RESTORE         [FALSE] L0001
       PRINT           "Ok."
       NEW_LINE        
       CALL            R0053 -> -(SP)
       RET_POPPED      
L0001: PRINT_RET       "Failed."

Routine R0069, 0 locals ()
    Action routine for:
        "save"

       SAVE            [FALSE] L0001
       PRINT_RET       "Ok."
L0001: PRINT_RET       "Failed."

Routine R0070, 0 locals ()
    Action routine for:
        "restar"

       PRINT           "Do you wish to restart your investigation (Y/N)"
       CALL            R0065 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       RESTART         
       PRINT_RET       "Failed."

Routine R0071, 0 locals ()
    Action routine for:
        "go around OBJ"

       PRINT_RET       "Use directions for movement here."

Routine R0072, 2 locals (0000, 0000)

       CALL            R0073 (G00,L00) -> L01
       JZ              L01 [TRUE] RFALSE
       CALL            R0110 (L01) -> -(SP)
       RET_POPPED      

Routine R0073, 4 locals (0000, 0000, 0000, 0000)

       LOADW           L01,#00 -> L03
L0001: INC_CHK         L02,L03 [TRUE] RFALSE
       LOADW           L01,L02 -> -(SP)
       JE              (SP)+,L00 [FALSE] L0001
       JE              L02,L03 [TRUE] RFALSE
       ADD             L02,#01 -> -(SP)
       LOADW           L01,(SP)+ -> -(SP)
       RET             (SP)+

Routine R0074, 5 locals (0000, 0000, 0000, 0000, 0000)
    Action routine for:
        "go OBJ"

       JE              Gaf,#53 [FALSE] L0001
       CALL            R0137 -> -(SP)
       RTRUE           
L0001: JZ              Gaf [FALSE] L0002
       PRINT_RET       "You can't go that way."
L0002: GET_PROP_ADDR   G00,Gaf -> L00
       JZ              L00 [TRUE] L0014
       GET_PROP_LEN    L00 -> L01
       JE              L01,#01 [FALSE] L0004
       LOADB           L00,#00 -> L04
       JE              #cb,G00,L04 [FALSE] L0003
       JE              G54,"quietl","slowly" [FALSE] L0003
       PRINT           "The stairs are still quite noisy even when walking up
very slowly."
       NEW_LINE        
L0003: CALL            R0110 (L04) -> -(SP)
       RET_POPPED      
L0004: JE              L01,#02 [FALSE] L0005
       LOADW           L00,#00 -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RET             #02
L0005: JE              L01,#03 [FALSE] L0007
       LOADW           L00,#00 -> -(SP)
       CALL            (SP)+ -> L04
       JZ              L04 [TRUE] L0006
       CALL            R0110 (L04) -> -(SP)
       RET_POPPED      
L0006: RET             #02
L0007: JE              L01,#04 [FALSE] L0010
       LOADB           L00,#01 -> -(SP)
       LOAD            [(SP)+] -> -(SP)
       JZ              (SP)+ [TRUE] L0008
       LOADB           L00,#00 -> -(SP)
       CALL            R0110 ((SP)+) -> -(SP)
       RET_POPPED      
L0008: LOADW           L00,#01 -> L02
       JZ              L02 [TRUE] L0009
       PRINT_PADDR     L02
       NEW_LINE        
       RET             #02
L0009: PRINT           "You can't go that way."
       NEW_LINE        
       RET             #02
L0010: JE              L01,#05 [FALSE] RFALSE
       LOADB           L00,#01 -> L03
       TEST_ATTR       L03,#1c [FALSE] L0011
       LOADB           L00,#00 -> -(SP)
       CALL            R0110 ((SP)+) -> -(SP)
       RET_POPPED      
L0011: TEST_ATTR       L03,#1f [FALSE] L0012
       PRINT_RET       "You can't go that way."
L0012: LOADW           L00,#01 -> L02
       JZ              L02 [TRUE] L0013
       PRINT_PADDR     L02
       NEW_LINE        
       RET             #02
L0013: PRINT           "The "
       PRINT_OBJ       L03
       PRINT           " is closed."
       NEW_LINE        
       STORE           Ga3,G00
       STORE           Ga4,L03
       RET             #02
L0014: JE              Gaf,#15 [FALSE] L0015
       PRINT           "In which direction do you want to go?"
       NEW_LINE        
       RET             #02
L0015: PRINT           "You can't go that way."
       NEW_LINE        
       RET             #02

Routine R0075, 0 locals ()
    Action routine for:
        "i"

       GET_CHILD       Ga8 -> -(SP) [FALSE] L0001
       CALL            R0061 (Ga8) -> -(SP)
       RET_POPPED      
L0001: PRINT_RET       "You are empty-handed."

Routine R0076, 0 locals ()
    Pre-action routine for:
        "carry OBJ from OBJ"
        "carry OBJ off OBJ"
        "carry OBJ out OBJ"
        "carry OBJ"
        "lift OBJ off OBJ"
        "pick up OBJ"

       JE              Gaf,#8c,#6d,#79 [TRUE] RFALSE
       JE              Gaf,#40,#08 [TRUE] RFALSE
       JIN             Gaf,#ff [FALSE] L0001
       CALL            R0128 (Gaf) -> -(SP)
       RET_POPPED      
L0001: JIN             Gaf,Ga8 [FALSE] L0002
       PRINT_RET       "You already have it."
L0002: GET_PARENT      Gaf -> -(SP)
       TEST_ATTR       (SP)+,#15 [FALSE] L0003
       GET_PARENT      Gaf -> -(SP)
       TEST_ATTR       (SP)+,#1c [TRUE] L0003
       PRINT_RET       "You can't reach that."
L0003: JZ              Gb0 [TRUE] L0005
       JE              Gb0,#7e [TRUE] RFALSE
       GET_PARENT      Gaf -> -(SP)
       JE              Gb0,(SP)+ [TRUE] L0004
       PRINT_RET       "It's not in that!"
L0004: STORE           Gb0,#00
       RFALSE          
L0005: GET_PARENT      Ga8 -> -(SP)
       JE              Gaf,(SP)+ [FALSE] RFALSE
       PRINT_RET       "You are in it, loser!"

Routine R0077, 0 locals ()
    Action routine for:
        "carry OBJ from OBJ"
        "carry OBJ off OBJ"
        "carry OBJ out OBJ"
        "carry OBJ"
        "lift OBJ off OBJ"
        "pick up OBJ"

       CALL            R0078 -> -(SP)
       JE              (SP)+,#01 [FALSE] RFALSE
       PRINT_RET       "Taken."

Routine R0078, 4 locals (0001, 0000, 0000, 0000)

       TEST_ATTR       Gaf,#13 [TRUE] L0001
       JZ              L00 [TRUE] RFALSE
       CALL            R0002 (G57) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RFALSE          
L0001: GET_PARENT      Gaf -> -(SP)
       JIN             (SP)+,Ga8 [TRUE] L0005
       CALL            R0096 (Gaf) -> L03
       CALL            R0096 (Ga8) -> -(SP)
       ADD             L03,(SP)+ -> -(SP)
       JG              (SP)+,Gbe [FALSE] L0005
       JZ              L00 [TRUE] L0004
       PRINT           "Your load is too heavy"
       JL              Gbe,Gbf [FALSE] L0002
       PRINT           ", especially in light of your condition."
       JUMP            L0003
L0002: PRINT           "."
L0003: NEW_LINE        
L0004: RET             #02
L0005: CALL            R0095 (Ga8) -> L01
       JG              L01,G84 [FALSE] L0008
       MUL             L01,G83 -> L03
       RANDOM          #64 -> -(SP)
       JG              L03,(SP)+ [FALSE] L0008
       GET_CHILD       Ga8 -> L02 [TRUE] L0006
L0006: GET_SIBLING     L02 -> L02 [TRUE] L0007
L0007: PRINT           "Oh, no. The "
       PRINT_OBJ       L02
       PRINT           " slips from your arms while you are taking the "
       PRINT_OBJ       Gaf
       PRINT           ", and both tumble to the ground."
       NEW_LINE        
       CALL            R0010 (#2a,L02) -> -(SP)
       RET             #02
L0008: INSERT_OBJ      Gaf,Ga8
       SET_ATTR        Gaf,#1e
       RTRUE           

Routine R0079, 0 locals ()
    Pre-action routine for:
        "chuck OBJ over OBJ"
        "chuck OBJ on OBJ"
        "chuck OBJ in OBJ"
        "squeez OBJ on OBJ"
        "insert OBJ on OBJ"
        "insert OBJ in OBJ"
        "drop OBJ on OBJ"
        "drop OBJ in OBJ"
        "drop OBJ down OBJ"
        "apply OBJ to OBJ"

       JIN             Gaf,#ff [TRUE] L0001
       TEST_ATTR       Gaf,#13 [TRUE] RFALSE
L0001: PRINT_RET       "Nice try."

Routine R0080, 1 local (0000)
    Action routine for:
        "chuck OBJ over OBJ"
        "chuck OBJ on OBJ"
        "chuck OBJ in OBJ"
        "squeez OBJ on OBJ"
        "insert OBJ on OBJ"
        "insert OBJ in OBJ"
        "drop OBJ on OBJ"
        "drop OBJ in OBJ"
        "drop OBJ down OBJ"
        "apply OBJ to OBJ"

       TEST_ATTR       Gb0,#1c [TRUE] L0003
       TEST_ATTR       Gb0,#16 [TRUE] L0001
       TEST_ATTR       Gb0,#15 [TRUE] L0003
L0001: TEST_ATTR       Gb0,#0c [FALSE] L0002
       JUMP            L0003
L0002: PRINT_RET       "You can't do that."
L0003: TEST_ATTR       Gb0,#1c [TRUE] L0004
       PRINT           "The"
       CALL            R0047 -> -(SP)
       PRINT_RET       " isn't open."
L0004: JE              Gb0,Gaf [FALSE] L0005
       PRINT_RET       "How can you do that?"
L0005: JIN             Gaf,Gb0 [FALSE] L0006
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT           " is already in the "
       PRINT_OBJ       Gb0
       PRINT_RET       "."
L0006: CALL            R0096 (Gb0) -> L00
       CALL            R0096 (Gaf) -> -(SP)
       ADD             L00,(SP)+ -> L00
       GET_PROP        Gb0,#0a -> -(SP)
       SUB             L00,(SP)+ -> L00
       GET_PROP        Gb0,#08 -> -(SP)
       JG              L00,(SP)+ [FALSE] L0007
       PRINT_RET       "There's no room."
L0007: CALL            R0081 (Gaf) -> -(SP)
       JZ              (SP)+ [FALSE] L0008
       CALL            R0078 -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
L0008: INSERT_OBJ      Gaf,Gb0
       SET_ATTR        Gaf,#1e
       PRINT_RET       "Done."

Routine R0081, 1 local (0000)

L0001: GET_PARENT      L00 -> -(SP)
       JE              (SP)+,#fd,#ff [TRUE] RFALSE
       JIN             L00,Ga8 [TRUE] RTRUE
       GET_PARENT      L00 -> L00
       JUMP            L0001

Routine R0082, 0 locals ()

       GET_PARENT      Ga8 -> -(SP)
       JE              Gaf,(SP)+ [FALSE] RFALSE
       CALL            R0010 (#6f,Gaf) -> -(SP)
       RTRUE           

Routine R0083, 0 locals ()
    Pre-action routine for:
        "donate OBJ to OBJ"

       CALL            R0081 (Gaf) -> -(SP)
       JZ              (SP)+ [FALSE] RFALSE
       JE              Gb0,#a0 [TRUE] RFALSE
       PRINT_RET       "That's easy for you to say, since you don't even have
it."

Routine R0084, 0 locals ()
    Pre-action routine for:
        "donate OBJ OBJ"

       CALL            R0010 (#36,Gb0,Gaf) -> -(SP)
       RTRUE           

Routine R0085, 0 locals ()
    Action routine for:
        "donate OBJ to OBJ"

       TEST_ATTR       Gb0,#14 [TRUE] L0001
       PRINT           "You can't give a "
       PRINT_OBJ       Gaf
       PRINT           " to a "
       PRINT_OBJ       Gb0
       PRINT_RET       "!"
L0001: PRINT_OBJ       Gb0
       PRINT_RET       " refuses your offer."

Routine R0086, 0 locals ()
    Action routine for:
        "donate OBJ OBJ"

       PRINT_RET       "FOOOO!!"

Routine R0087, 0 locals ()
    Action routine for:
        "insert down OBJ"
        "pour OBJ from OBJ"
        "pour OBJ in OBJ"
        "pour OBJ"
        "leave OBJ"
        "drop OBJ"

       CALL            R0091 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT           " is now on the "
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0001
       PRINT           "ground"
       JUMP            L0002
L0001: PRINT           "floor"
L0002: PRINT_RET       "."

Routine R0088, 0 locals ()

       CALL            R0091 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       PRINT_RET       "Thrown."

Routine R0089, 0 locals ()
    Action routine for:
        "chuck OBJ with OBJ"

       TEST_ATTR       Gaf,#14 [TRUE] L0001
       PRINT_RET       "Let's not resort to violence, please."
L0001: CALL            R0088 -> -(SP)
       RET_POPPED      

Routine R0090, 0 locals ()
    Action routine for:
        "chuck OBJ at OBJ"

       CALL            R0091 -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       TEST_ATTR       Gb0,#14 [FALSE] L0001
       PRINT_OBJ       Gb0
       PRINT           ", puzzled by your unorthodox methods, ducks as the "
       PRINT_OBJ       Gaf
       PRINT_RET       " flies by."
L0001: PRINT_RET       "Perhaps you aren't feeling well?"

Routine R0091, 0 locals ()

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT           "It's not likely that "
       PRINT_OBJ       Gaf
       PRINT           " would enjoy that."
       NEW_LINE        
       RFALSE          
L0001: JIN             Gaf,Ga8 [TRUE] L0002
       GET_PARENT      Gaf -> -(SP)
       JIN             (SP)+,Ga8 [TRUE] L0002
       PRINT           "You're not carrying the"
       CALL            R0046 -> -(SP)
       PRINT           "."
       NEW_LINE        
       RFALSE          
L0002: JIN             Gaf,Ga8 [TRUE] L0003
       GET_PARENT      Gaf -> -(SP)
       TEST_ATTR       (SP)+,#1c [TRUE] L0003
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT           " is closed."
       NEW_LINE        
       RFALSE          
L0003: GET_PARENT      Ga8 -> -(SP)
       INSERT_OBJ      Gaf,(SP)+
       RTRUE           

Routine R0092, 2 locals (0000, 0000)
    Action routine for:
        "open OBJ with OBJ"
        "open up OBJ"
        "open OBJ"

       TEST_ATTR       Gaf,#15 [TRUE] L0001
       PRINT           "You must be very clever to do that to the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."
L0001: TEST_ATTR       Gaf,#16 [TRUE] L0002
       GET_PROP        Gaf,#08 -> -(SP)
       JZ              (SP)+ [TRUE] L0008
L0002: TEST_ATTR       Gaf,#1c [FALSE] L0003
       PRINT_RET       "It is already open."
L0003: SET_ATTR        Gaf,#1c
       TEST_ATTR       Gaf,#16 [FALSE] L0004
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT_RET       " is now open."
L0004: GET_CHILD       Gaf -> -(SP) [FALSE] L0005
       TEST_ATTR       Gaf,#1b [FALSE] L0006
L0005: PRINT_RET       "Opened."
L0006: GET_CHILD       Gaf -> L00 [FALSE] L0007
       GET_SIBLING     L00 -> -(SP) [TRUE] L0007
       GET_PROP        L00,#09 -> L01
       JZ              L01 [TRUE] L0007
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT           " opens."
       NEW_LINE        
       PRINT_PADDR     L01
       NEW_LINE        
       RTRUE           
L0007: PRINT           "Opening the "
       PRINT_OBJ       Gaf
       PRINT           " reveals "
       CALL            R0093 (Gaf) -> -(SP)
       PRINT_RET       "."
L0008: PRINT           "The"
       CALL            R0046 -> -(SP)
       PRINT_RET       " cannot be opened."

Routine R0093, 4 locals (0000, 0000, 0000, 0001)

       GET_CHILD       L00 -> L01 [FALSE] RFALSE
L0001: GET_SIBLING     L01 -> L02 [TRUE] L0002
L0002: JZ              L03 [TRUE] L0003
       STORE           L03,#00
       JUMP            L0004
L0003: PRINT           ", "
       JZ              L02 [FALSE] L0004
       PRINT           "and "
L0004: PRINT           "a "
       PRINT_OBJ       L01
       STORE           L01,L02
       JZ              L01 [FALSE] L0001
       RTRUE           

Routine R0094, 0 locals ()
    Action routine for:
        "close OBJ"

       TEST_ATTR       Gaf,#15 [TRUE] L0001
       PRINT           "You must be very clever to do that to the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."
L0001: TEST_ATTR       Gaf,#16 [FALSE] L0003
       TEST_ATTR       Gaf,#1c [FALSE] L0002
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT           " is now closed."
       NEW_LINE        
       CLEAR_ATTR      Gaf,#1c
       RTRUE           
L0002: PRINT_RET       "It is already closed."
L0003: TEST_ATTR       Gaf,#1d [TRUE] L0005
       GET_PROP        Gaf,#08 -> -(SP)
       JZ              (SP)+ [TRUE] L0005
       TEST_ATTR       Gaf,#1c [FALSE] L0004
       CLEAR_ATTR      Gaf,#1c
       PRINT_RET       "Closed."
L0004: PRINT_RET       "It is already closed."
L0005: PRINT_RET       "You cannot close that."

Routine R0095, 3 locals (0000, 0000, 0000)

       GET_CHILD       L00 -> L02 [FALSE] L0002
L0001: INC             L01
       GET_SIBLING     L02 -> L02 [TRUE] L0001
L0002: RET             L01

Routine R0096, 3 locals (0000, 0000, 0000)

       GET_CHILD       L00 -> L01 [FALSE] L0002
L0001: CALL            R0096 (L01) -> -(SP)
       ADD             L02,(SP)+ -> L02
       GET_SIBLING     L01 -> L01 [TRUE] L0001
L0002: GET_PROP        L00,#0a -> -(SP)
       ADD             L02,(SP)+ -> -(SP)
       RET_POPPED      

Routine R0097, 0 locals ()
    Action routine for:
        "bug"

       PRINT_RET       "If there is a problem here, it is unintentional. You
may report your problem to the address provided in your documentation."

Routine R0098, 0 locals ()
    Action routine for:
        "script"

       LOADW           #00,#08 -> -(SP)
       OR              (SP)+,#01 -> -(SP)
       STOREW          #00,#08,(SP)+
       PRINT           "Here begins"
       PRINT_PADDR     G82
       NEW_LINE        
       RTRUE           

Routine R0099, 0 locals ()
    Action routine for:
        "unscri"

       PRINT           "Here ends"
       PRINT_PADDR     G82
       NEW_LINE        
       LOADW           #00,#08 -> -(SP)
       AND             (SP)+,#fffe -> -(SP)
       STOREW          #00,#08,(SP)+
       RTRUE           

Routine R0100, 0 locals ()
    Pre-action routine for:
        "pull on OBJ"
        "pull OBJ"
        "roll up OBJ"
        "move OBJ"

       CALL            R0081 (Gaf) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       PRINT_RET       "Juggling isn't one of your talents."

Routine R0101, 0 locals ()
    Action routine for:
        "pull on OBJ"
        "pull OBJ"
        "roll up OBJ"
        "move OBJ"

       TEST_ATTR       Gaf,#13 [FALSE] L0001
       PRINT           "Moving the"
       CALL            R0046 -> -(SP)
       PRINT_RET       " reveals nothing."
L0001: PRINT           "You can't move the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."

Routine R0102, 0 locals ()
    Action routine for:
        "flip on OBJ"
        "strike OBJ"
        "light OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "Ahem!  You may or may not realize this, but you are on
a case. You shouldn't be wasting your time attempting to flirt with the
suspects. In any event, it's unlikely that you are person enough to do it."
L0001: PRINT_RET       "You can't turn that on."

Routine R0103, 0 locals ()
    Action routine for:
        "flip off OBJ"
        "blow out OBJ"
        "douse OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "Your uncouth manner is certain to turn anyone off."
L0001: PRINT_RET       "You can't turn that off."

Routine R0104, 4 locals (0003, 0000, 0000, 0000)
    Action routine for:
        "wait"

       STORE           G81,#00
       JZ              L02 [FALSE] L0001
       PRINT           "Time passes..."
       NEW_LINE        
L0001: DEC_CHK         L00,#00 [FALSE] L0002
       JUMP            L0015
L0002: CALL            R0006 -> L03
       JZ              L03 [TRUE] L0010
       JE              L03,#02 [FALSE] L0003
       JUMP            L0015
L0003: JE              L01,#3d [FALSE] L0004
       JZ              G77 [FALSE] L0004
       JUMP            L0015
L0004: JZ              L01 [TRUE] L0005
       JIN             L01,G00 [FALSE] L0005
       PRINT_OBJ       L01
       PRINT           ", for whom you are waiting, has arrived."
       NEW_LINE        
       JUMP            L0015
L0005: INC             G81
       LOADB           #00,#01 -> -(SP)
       AND             (SP)+,#10 -> -(SP)
       JZ              (SP)+ [TRUE] L0006
       PRINT           "("
       CALL            R0222 (G76) -> -(SP)
       PRINT           ") "
L0006: JZ              L02 [TRUE] L0007
       PRINT           "Do you want to continue what you were doing? (Y/N)"
       JUMP            L0008
L0007: PRINT           "Do you want to keep waiting? (Y/N)"
L0008: CALL            R0065 -> -(SP)
       JZ              (SP)+ [FALSE] L0009
       JUMP            L0015
L0009: SHOW_STATUS     
       JUMP            L0001
L0010: JE              L01,#3d [FALSE] L0011
       JZ              G77 [FALSE] L0011
       JUMP            L0015
L0011: JZ              L01 [TRUE] L0012
       JIN             L01,G00 [FALSE] L0012
       PRINT_OBJ       L01
       PRINT           ", for whom you are waiting, has arrived."
       NEW_LINE        
       JUMP            L0015
L0012: JZ              L01 [TRUE] L0014
       INC_CHK         G81,#1e [FALSE] L0014
       PRINT_OBJ       L01
       PRINT           " still hasn't arrived. Do you want to keep waiting?
(Y/N) "
       CALL            R0065 -> -(SP)
       JZ              (SP)+ [FALSE] L0013
       JUMP            L0015
L0013: STORE           G81,#00
       SHOW_STATUS     
       JUMP            L0001
L0014: SHOW_STATUS     
       JUMP            L0001
L0015: STORE           Gba,#01
       JZ              L02 [FALSE] RTRUE
       CALL            R0221 -> -(SP)
       RTRUE           

Routine R0105, 3 locals (0000, 0000, 0000)

       STORE           L01,G76
       MUL             L00,#02 -> -(SP)
       RANDOM          (SP)+ -> L02
       CALL            R0104 (L02,#00,#01) -> -(SP)
       SUB             G76,L01 -> -(SP)
       JL              (SP)+,L02 [TRUE] RFALSE
       RTRUE           

Routine R0106, 1 local (0000)
    Action routine for:
        "wait for OBJ"
        "wait OBJ"

       JE              Gaf,#52 [FALSE] L0003
       JG              G98,G76 [FALSE] L0001
       CALL            R0107 -> -(SP)
       RTRUE           
L0001: JG              G98,#b4 [FALSE] L0002
       PRINT_RET       "That's too long to wait."
L0002: CALL            R0104 (G98) -> -(SP)
       RET_POPPED      
L0003: JE              Gaf,#33 [FALSE] L0004
       CALL            R0107 -> -(SP)
       RTRUE           
L0004: JE              Gaf,#3d [FALSE] L0006
       JZ              G77 [TRUE] L0005
       CALL            R0104 (#2710,Gaf) -> -(SP)
       RET_POPPED      
L0005: PRINT_RET       "You would wait quite a while, since Sergeant Duffy is
always nearby, but never approaches you unless requested."
L0006: TEST_ATTR       Gaf,#14 [FALSE] L0008
       GET_PROP        Gaf,#07 -> -(SP)
       LOADW           G06,(SP)+ -> L00
       JIN             L00,G00 [FALSE] L0007
       PRINT_RET       "That person is already here!"
L0007: CALL            R0104 (#2710,L00) -> -(SP)
       RET_POPPED      
L0008: PRINT_RET       "Not a good idea. You might wait all day."

Routine R0107, 0 locals ()
    Action routine for:
        "wait until OBJ"

       JE              Gaf,#33 [FALSE] L0001
       STORE           G98,#02d0
       STORE           Gaf,#52
       JUMP            L0003
L0001: JL              G98,#08 [FALSE] L0002
       ADD             G98,#0c -> -(SP)
       MUL             (SP)+,#3c -> G98
       JUMP            L0003
L0002: JL              G98,#0d [FALSE] L0003
       MUL             G98,#3c -> G98
L0003: JE              Gaf,#52 [FALSE] L0005
       JG              G98,G76 [FALSE] L0004
       SUB             G98,G76 -> -(SP)
       CALL            R0104 ((SP)+) -> -(SP)
       RET_POPPED      
L0004: PRINT_RET       "You are clearly ahead of your time."
L0005: PRINT_RET       "Your sanity is coming into question."

Routine R0108, 0 locals ()
    Action routine for:
        "carry up OBJ"
        "lean up OBJ"
        "lean"

       GET_PARENT      Ga8 -> -(SP)
       TEST_ATTR       (SP)+,#1d [TRUE] L0001
       GET_PARENT      Ga8 -> -(SP)
       TEST_ATTR       (SP)+,#0d [FALSE] L0002
L0001: PRINT           "You are on your own feet again."
       NEW_LINE        
       INSERT_OBJ      Ga8,G00
       RTRUE           
L0002: PRINT_RET       "You're already standing up!"

Routine R0109, 0 locals ()
    Action routine for:
        "carry out OBJ"

       GET_PARENT      Ga8 -> -(SP)
       JE              (SP)+,Gaf [TRUE] L0001
       PRINT           "You're not in that!"
       NEW_LINE        
       RET             #02
L0001: PRINT           "You are on your own feet again."
       NEW_LINE        
       INSERT_OBJ      Ga8,G00
       RTRUE           

Routine R0110, 4 locals (0000, 0001, 0000, 0000)

       GET_PARENT      Ga8 -> -(SP)
       JIN             (SP)+,#fd [TRUE] L0001
       PRINT_RET       "You are seated, if you remember."
L0001: GET_CHILD       G00 -> L02 [TRUE] L0002
L0002: LOADW           G03,#00 -> L03
L0003: JZ              L02 [FALSE] L0004
       JUMP            L0007
L0004: TEST_ATTR       L02,#14 [FALSE] L0005
       JE              L02,#a0 [TRUE] L0005
       GET_PROP        L02,#07 -> -(SP)
       STOREW          L03,(SP)+,G76
L0005: GET_SIBLING     L02 -> L02 [TRUE] L0006
L0006: JUMP            L0003
L0007: INSERT_OBJ      Ga8,L00
       STORE           G00,L00
       STORE           G87,#01
       GET_PROP        G00,#12 -> -(SP)
       CALL            (SP)+ (#02) -> -(SP)
       JZ              L01 [TRUE] RFALSE
       CALL            R0053 -> -(SP)
       RET_POPPED      

Routine R0111, 0 locals ()
    Pre-action routine for:
        "pour OBJ on OBJ"

       PRINT_RET       "You can't pour that on anything."

Routine R0112, 0 locals ()
    Action routine for:
        "pour OBJ on OBJ"

       REMOVE_OBJ      Gaf
       TEST_ATTR       Gb0,#07 [FALSE] L0001
       TEST_ATTR       Gb0,#17 [FALSE] L0001
       PRINT           "The "
       PRINT_OBJ       Gb0
       PRINT_RET       " is extinguished."
L0001: PRINT           "The water spills over the "
       PRINT_OBJ       Gb0
       PRINT_RET       " and to the floor where it evaporates."

Routine R0113, 0 locals ()
    Action routine for:
        "squeez OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT           "It's unclear how "
       PRINT_OBJ       Gaf
       PRINT           " would take this, so you defer until after hours."
       JUMP            L0002
L0001: PRINT           "How singularly useless."
L0002: NEW_LINE        
       RTRUE           

Routine R0114, 1 local (0000)

       JZ              Gb0 [FALSE] L0002
       GET_PROP_ADDR   G00,#0f -> L00
       JZ              L00 [TRUE] L0002
       GET_PROP_LEN    L00 -> -(SP)
       CALL            R0044 (#3f,L00,(SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       STORE           Gb0,#3f
       RFALSE          
L0001: PRINT_RET       "There's nothing to fill it with."
L0002: JE              Gb0,#3f [TRUE] RFALSE
       CALL            R0010 (#13,Gb0,Gaf) -> -(SP)
       RTRUE           

Routine R0115, 0 locals ()
    Action routine for:
        "fill OBJ"
        "fill OBJ with OBJ"

       JZ              Gb0 [FALSE] L0002
       CALL            R0163 (#3f,G00) -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       CALL            R0010 (#31,Gaf,#3f) -> -(SP)
       RET_POPPED      
L0001: PRINT_RET       "There's nothing to fill it with."
L0002: PRINT_RET       "You can't do that."

Routine R0116, 0 locals ()
    Action routine for:
        "brush OBJ with OBJ"
        "brush off OBJ"
        "brush OBJ"

       PRINT_RET       "Cleanliness is next to Godliness, although in this case
it seems to be next to Uselessness."

Routine R0117, 0 locals ()
    Action routine for:
        "peal OBJ with OBJ"
        "peal OBJ"

       PRINT_RET       "How, exactly, does one ring that?"

Routine R0118, 0 locals ()
    Action routine for:
        "drink OBJ"

       CALL            R0119 -> -(SP)
       RET_POPPED      

Routine R0119, 3 locals (0000, 0000, 0000)
    Action routine for:
        "consum OBJ"

       TEST_ATTR       Gaf,#05 [TRUE] L0001
       PUSH            #00
       JUMP            L0002
L0001: PUSH            #01
L0002: STORE           L00,(SP)+
       JZ              L00 [TRUE] L0005
       JIN             Gaf,Ga8 [FALSE] L0005
       JE              Gb1,#29 [FALSE] L0003
       PRINT           "How does one drink that?"
       NEW_LINE        
       JUMP            L0004
L0003: PRINT           "Mmm. That really hit the spot."
       NEW_LINE        
       REMOVE_OBJ      Gaf
L0004: NEW_LINE        
       RTRUE           
L0005: TEST_ATTR       Gaf,#06 [TRUE] L0006
       PUSH            #00
       JUMP            L0007
L0006: PUSH            #01
L0007: STORE           L01,(SP)+
       JZ              L01 [TRUE] L0010
       JIN             Gaf,#ff [TRUE] L0008
       GET_PARENT      Gaf -> L02
       JZ              L02 [TRUE] L0009
       JIN             L02,Ga8 [FALSE] L0009
       TEST_ATTR       L02,#1c [FALSE] L0009
L0008: PRINT           "Mmm. That really hit the spot."
       NEW_LINE        
       REMOVE_OBJ      Gaf
       RTRUE           
L0009: PRINT_RET       "You can't get to it."
L0010: JZ              L00 [FALSE] RFALSE
       JZ              L01 [FALSE] RFALSE
       PRINT           "The"
       CALL            R0046 -> -(SP)
       PRINT_RET       " wouldn't agree with you."

Routine R0120, 0 locals ()
    Action routine for:
        "curse OBJ"
        "curse"

       JZ              Gaf [TRUE] L0002
       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "Insults of this nature won't help you."
L0001: PRINT_RET       "What a loony!"
L0002: CALL            R0002 (G80) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           

Routine R0121, 0 locals ()
    Action routine for:
        "listen at OBJ"
        "listen to OBJ"

       TEST_ATTR       Gaf,#14 [TRUE] L0001
       PRINT           "The "
L0001: PRINT_OBJ       Gaf
       PRINT_RET       " makes no sound."

Routine R0122, 5 locals (0000, 0000, 0000, 0000, 0000)
    Action routine for:
        "chase OBJ"

       GET_PROP        Gaf,#07 -> L00
       LOADW           G06,L00 -> L01
       GET_PARENT      L01 -> L04
       JE              Gaf,#a0 [FALSE] L0001
       PRINT_RET       "It's not clear whom you are talking to."
L0001: TEST_ATTR       Gaf,#14 [TRUE] L0002
       PRINT           "How tragic to see a formerly great detective stalking a
"
       PRINT_OBJ       Gaf
       PRINT_RET       "."
L0002: JE              G00,L04 [FALSE] L0003
       PRINT           "You're in the same place as "
       PRINT_OBJ       L01
       PRINT_RET       "!"
L0003: JZ              L04 [FALSE] L0004
       PRINT_OBJ       L01
       PRINT_RET       " has left the grounds."
L0004: LOADW           G03,#00 -> -(SP)
       LOADW           (SP)+,L00 -> -(SP)
       JE              (SP)+,G76 [FALSE] L0005
       CALL            R0110 (L04) -> -(SP)
       RET_POPPED      
L0005: GET_PROP        G00,#0c -> L02
       JZ              L02 [TRUE] L0006
       GET_PROP        L04,#0c -> L03
       JZ              L03 [TRUE] L0006
       AND             L02,L03 -> -(SP)
       JZ              (SP)+ [TRUE] L0006
       CALL            R0447 (G00,L04) -> Gaf
       CALL            R0074 -> -(SP)
       RET_POPPED      
L0006: PRINT           "You seem to have lost track of "
       PRINT_OBJ       L01
       PRINT_RET       "."

Routine R0123, 2 locals (0000, 0000)
    Action routine for:
        "jump in OBJ"
        "jump across OBJ"
        "jump over OBJ"
        "jump"

       JZ              Gaf [TRUE] L0003
       JIN             Gaf,G00 [FALSE] L0002
       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT_RET       " is too big to jump over."
L0001: CALL            R0124 -> -(SP)
       RET_POPPED      
L0002: PRINT_RET       "That would be a good trick."
L0003: GET_PROP_ADDR   G00,#16 -> L00
       JZ              L00 [TRUE] L0006
       GET_PROP_LEN    L00 -> L01
       JE              L01,#02 [TRUE] L0004
       JE              L01,#04 [FALSE] L0005
       LOADB           L00,#01 -> -(SP)
       LOAD            [(SP)+] -> -(SP)
       JZ              (SP)+ [FALSE] L0005
L0004: PRINT           "For a brief moment, you feel the exhilaration of free
fall. A thought hits you: the ground is moving toward me. It is your last
thought."
       NEW_LINE        
       QUIT            
       RTRUE           
L0005: CALL            R0124 -> -(SP)
       RET_POPPED      
L0006: CALL            R0124 -> -(SP)
       RET_POPPED      

Routine R0124, 0 locals ()
    Action routine for:
        "hop"

       PRINT_RET       "Wheeeeeeeeee!!!!!"

Routine R0125, 0 locals ()
    Action routine for:
        "leave"

       CALL            R0010 (#82,#14) -> -(SP)
       RET_POPPED      

Routine R0126, 0 locals ()
    Action routine for:
        "goodby OBJ"
        "goodby"

       CALL            R0127 (#00) -> -(SP)
       RET_POPPED      

Routine R0127, 1 local (0001)
    Action routine for:
        "hello OBJ"
        "hello"

       JZ              Gaf [TRUE] L0003
       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_OBJ       Gaf
       PRINT_RET       " returns the salutation."
L0001: PRINT           "Only schizophrenics say ""
       JZ              L00 [TRUE] L0002
L0002: PRINT           "" to a "
       PRINT_OBJ       Gaf
       PRINT_RET       "."
L0003: PRINT_RET       "Good day."

Routine R0128, 1 local (0000)

       PRINT           "You can't see "
       TEST_ATTR       L00,#14 [FALSE] L0001
       PRINT_OBJ       L00
       JUMP            L0002
L0001: PRINT           "that"
L0002: PRINT_RET       " here."

Routine R0129, 0 locals ()
    Pre-action routine for:
        "read OBJ with OBJ"
        "read OBJ OBJ"
        "read OBJ"
        "gaze at OBJ with OBJ"

       JZ              G87 [FALSE] L0001
       PRINT_RET       "It is impossible to read in the dark."
L0001: JE              Gaf,#06,#8c [TRUE] RFALSE
       JIN             Gaf,#ff [FALSE] L0002
       CALL            R0128 (Gaf) -> -(SP)
       RET_POPPED      
L0002: TEST_ATTR       Gaf,#0a [FALSE] L0003
       PRINT           "You examine one of the handful of pills:"
       NEW_LINE        
       RFALSE          
L0003: JZ              Gb0 [TRUE] L0004
       TEST_ATTR       Gb0,#1b [TRUE] L0004
       JE              Gb0,#52 [TRUE] L0004
       PRINT           "How does one look through the"
       CALL            R0047 -> -(SP)
       PRINT_RET       "?"
L0004: JE              G54,"carefu" [FALSE] RFALSE
       CALL            R0105 (#03) -> -(SP)
       JZ              (SP)+ [FALSE] RFALSE
       PRINT           "You never got to finish reading the "
       PRINT_OBJ       Gaf
       PRINT_RET       "."

Routine R0130, 0 locals ()
    Action routine for:
        "read OBJ with OBJ"
        "read OBJ OBJ"
        "read OBJ"
        "gaze at OBJ with OBJ"

       TEST_ATTR       Gaf,#12 [TRUE] L0001
       PRINT           "You cannot read the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "?"
L0001: GET_PROP        Gaf,#04 -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           

Routine R0131, 0 locals ()
    Action routine for:
        "gaze under OBJ"

       TEST_ATTR       Gaf,#0d [FALSE] L0001
       PRINT           "You twist your head to look under the"
       CALL            R0046 -> -(SP)
       PRINT_RET       " but find nothing."
L0001: TEST_ATTR       Gaf,#14 [FALSE] L0002
       PRINT           "Nope. Nothing hiding under "
       PRINT_OBJ       Gaf
       PRINT_RET       "."
L0002: GET_PARENT      Gaf -> -(SP)
       JE              (SP)+,G00,#fe,#ff [FALSE] L0003
       PRINT_RET       "There is nothing but dust there."
L0003: PRINT_RET       "That's not so useful."

Routine R0132, 0 locals ()
    Action routine for:
        "gaze behind OBJ"

       PRINT           "There is nothing behind "
       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_OBJ       Gaf
       JUMP            L0002
L0001: PRINT           "the"
       CALL            R0046 -> -(SP)
L0002: PRINT_RET       "."

Routine R0133, 0 locals ()
    Action routine for:
        "what on OBJ"
        "what in OBJ"
        "peek in OBJ"
        "gaze in OBJ"
        "gaze out OBJ"
        "gaze throug OBJ"
        "gaze with OBJ"

       TEST_ATTR       Gaf,#18 [FALSE] L0001
       CALL            R0217 -> -(SP)
       RET_POPPED      
L0001: TEST_ATTR       Gaf,#16 [FALSE] L0004
       TEST_ATTR       Gaf,#1c [FALSE] L0002
       PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT           " is open, but you can't tell what's beyond it."
       JUMP            L0003
L0002: PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT           " is closed."
L0003: NEW_LINE        
       RTRUE           
L0004: TEST_ATTR       Gaf,#15 [FALSE] L0008
       CALL            R0134 (Gaf) -> -(SP)
       JZ              (SP)+ [TRUE] L0007
       GET_CHILD       Gaf -> -(SP) [FALSE] L0005
       CALL            R0061 (Gaf) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
L0005: TEST_ATTR       Gaf,#1d [FALSE] L0006
       PRINT           "There is nothing on the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."
L0006: PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT_RET       " is empty."
L0007: PRINT           "The "
       PRINT_OBJ       Gaf
       PRINT_RET       " is closed."
L0008: PRINT           "One can't look inside the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."

Routine R0134, 1 local (0000)

       TEST_ATTR       L00,#1f [TRUE] RFALSE
       TEST_ATTR       L00,#1b [TRUE] RTRUE
       TEST_ATTR       L00,#1c [TRUE] RTRUE
       RFALSE          

Routine R0135, 0 locals ()
    Pre-action routine for:
        "light OBJ with OBJ"
        "burn down OBJ with OBJ"
        "burn OBJ with OBJ"

       TEST_ATTR       Gb0,#07 [FALSE] L0001
       TEST_ATTR       Gb0,#17 [TRUE] RFALSE
L0001: PRINT           "With the"
       CALL            R0047 -> -(SP)
       PRINT_RET       "??!?"

Routine R0136, 0 locals ()
    Action routine for:
        "light OBJ with OBJ"
        "burn down OBJ with OBJ"
        "burn OBJ with OBJ"

       PRINT           "You can't burn the "
       PRINT_OBJ       Gaf
       PRINT_RET       "."

Routine R0137, 0 locals ()
    Pre-action routine for:
        "flip to OBJ"
        "flip in OBJ"
        "flip OBJ"

       JE              Gaf,#53 [FALSE] L0001
       PRINT_RET       "Specify a direction if you want to move around."
L0001: TEST_ATTR       Gaf,#10 [TRUE] RFALSE
       PRINT_RET       "You can't turn that!"

Routine R0138, 0 locals ()
    Action routine for:
        "flip to OBJ"
        "flip in OBJ"
        "flip OBJ"

       PRINT_RET       "This has no effect."

Routine R0139, 0 locals ()

       PRINT_RET       "It's not awfully clear how."

Routine R0140, 0 locals ()
    Action routine for:
        "lock OBJ with OBJ"

       PRINT_RET       "It doesn't seem to work."

Routine R0141, 0 locals ()
    Action routine for:
        "pick OBJ with OBJ"
        "pick OBJ"

       PRINT_RET       "You can't pick that."

Routine R0142, 0 locals ()
    Action routine for:
        "unlock OBJ"

       PRINT_RET       "It doesn't seem to work."

Routine R0143, 0 locals ()
    Action routine for:
        "cut OBJ with OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       CALL            R0010 (#3e,Gaf,Gb0) -> -(SP)
       RET_POPPED      
L0001: TEST_ATTR       Gaf,#11 [FALSE] L0002
       TEST_ATTR       Gb0,#08 [FALSE] L0002
       REMOVE_OBJ      Gaf
       PRINT           "Your skillful "
       PRINT_OBJ       Gb0
       PRINT           "smanship slices the "
       PRINT_OBJ       Gaf
       PRINT_RET       " into innumerable slivers that evaporate
instantaneously."
L0002: TEST_ATTR       Gb0,#08 [TRUE] L0003
       PRINT           "You find that the "cutting edge" of the"
       CALL            R0047 -> -(SP)
       PRINT_RET       " is inadequate."
L0003: PRINT           "That's a strange concept, cutting the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."

Routine R0144, 0 locals ()
    Action routine for:
        "dispat OBJ with OBJ"
        "dispat OBJ"

       CALL            R0145 (S091) -> -(SP)
       RET_POPPED      

Routine R0145, 1 local (0000)

       JZ              Gaf [FALSE] L0001
       PRINT           "There is nothing here to "
       PRINT_PADDR     L00
       PRINT_RET       "."
L0001: TEST_ATTR       Gaf,#14 [TRUE] L0002
       PRINT           "No doubt you need a refresher course at the academy "
       PRINT           "in the martial arts, but the "
       PRINT_OBJ       Gaf
       PRINT_RET       " is hardly a likely target."
L0002: JE              Gb0,#51 [FALSE] L0003
       PRINT           "A shot rings out and "
       PRINT_OBJ       Gaf
       PRINT           " falls to the ground, dead. Good shot."
       NEW_LINE        
       CALL            R0322 -> -(SP)
       RET_POPPED      
L0003: RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0004
       PRINT_RET       "You rethink your planned action."
L0004: PRINT           "With a lethal blow of your hand, "
       PRINT_OBJ       Gaf
       PRINT           " falls dead."
       NEW_LINE        
       CALL            R0322 -> -(SP)
       RET_POPPED      

Routine R0146, 0 locals ()
    Action routine for:
        "strike OBJ"
        "strike OBJ with OBJ"
        "knock down OBJ"
        "attack OBJ with OBJ"

       CALL            R0145 (S092) -> -(SP)
       RET_POPPED      

Routine R0147, 0 locals ()
    Action routine for:
        "swing OBJ at OBJ"
        "swing OBJ"

       JZ              Gb0 [FALSE] L0001
       PRINT_RET       "Whoosh!"
L0001: CALL            R0010 (#18,Gb0,Gaf) -> -(SP)
       RET_POPPED      

Routine R0148, 0 locals ()
    Action routine for:
        "bite OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "This sort of shabby behavior is disgusting."
L0001: CALL            R0155 (S093) -> -(SP)
       RET_POPPED      

Routine R0149, 0 locals ()
    Action routine for:
        "brandi OBJ at OBJ"
        "brandi OBJ"

       CALL            R0155 (S094) -> -(SP)
       RET_POPPED      

Routine R0150, 0 locals ()
    Action routine for:
        "lift up OBJ"
        "lift OBJ"

       CALL            R0155 (S095) -> -(SP)
       RET_POPPED      

Routine R0151, 0 locals ()
    Action routine for:
        "lower OBJ"

       CALL            R0155 (S095) -> -(SP)
       RET_POPPED      

Routine R0152, 0 locals ()
    Action routine for:
        "feel OBJ with OBJ"
        "feel OBJ"

       CALL            R0155 (S096) -> -(SP)
       RET_POPPED      

Routine R0153, 0 locals ()
    Action routine for:
        "press on OBJ"
        "press OBJ"

       CALL            R0155 (S097) -> -(SP)
       RET_POPPED      

Routine R0154, 0 locals ()
    Action routine for:
        "blind OBJ with OBJ"
        "break down OBJ with OBJ"
        "break OBJ with OBJ"

       CALL            R0155 (S098) -> -(SP)
       RET_POPPED      

Routine R0155, 1 local (0000)

       PRINT_PADDR     L00
       PRINT_OBJ       Gaf
       CALL            R0002 (G7f) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           

Routine R0156, 4 locals (0000, 0000, 0000, 0000)

       GET_PROP_ADDR   L00,#13 -> L02
       GET_PROP_LEN    L02 -> -(SP)
       DIV             (SP)+,#02 -> -(SP)
       SUB             (SP)+,#01 -> -(SP)
       CALL            R0043 (L01,L02,(SP)+) -> -(SP)
       RET_POPPED      

Routine R0157, 0 locals ()
    Action routine for:
        "knock at OBJ"
        "knock on OBJ"

       CALL            R0156 (Gaf,"door") -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       PRINT_RET       "It appears that nobody's home."
L0001: PRINT           "Why knock on a "
       PRINT_OBJ       Gaf
       PRINT_RET       "?"

Routine R0158, 1 local (0000)
    Action routine for:
        "shake OBJ"

       TEST_ATTR       Gaf,#13 [TRUE] L0001
       PRINT_RET       "You can't take it; thus, you can't shake it!"
L0001: TEST_ATTR       Gaf,#1c [TRUE] L0002
       GET_CHILD       Gaf -> -(SP) [FALSE] L0002
       PRINT           "It sounds as though there is something inside the "
       PRINT_OBJ       Gaf
       PRINT_RET       "."
L0002: TEST_ATTR       Gaf,#1c [FALSE] L0005
       GET_CHILD       Gaf -> -(SP) [FALSE] L0005
L0003: GET_CHILD       Gaf -> L00 [FALSE] L0004
       INSERT_OBJ      L00,G00
       JUMP            L0003
L0004: PRINT_RET       "Everything in it spills onto the floor."
L0005: PRINT_RET       "Well, what did you expect to happen?"

Routine R0159, 0 locals ()

       TEST_ATTR       Gb0,#02 [FALSE] L0001
       PRINT           "Digging with the"
       CALL            R0047 -> -(SP)
       PRINT_RET       " is slow and tedious."
L0001: PRINT           "Digging with a "
       PRINT_OBJ       Gb0
       PRINT_RET       " is silly."

Routine R0160, 0 locals ()
    Action routine for:
        "dig OBJ for OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0002
       PRINT_OBJ       Gaf
       PRINT           " resignedly allows you to perform the search."
       NEW_LINE        
       JIN             Gb0,Gaf [FALSE] L0001
       PRINT           "Indeed, "
       PRINT_OBJ       Gaf
       PRINT           " has the "
       PRINT_OBJ       Gb0
       PRINT_RET       "."
L0001: PRINT_OBJ       Gaf
       PRINT_RET       " doesn't have that."
L0002: JIN             Gb0,Gaf [FALSE] L0003
       PRINT_RET       "How observant you are!  There it is!"
L0003: PRINT           "You don't find the"
       CALL            R0047 -> -(SP)
       PRINT_RET       " there."

Routine R0161, 0 locals ()

       PRINT_RET       "What a silly idea!"

Routine R0162, 0 locals ()
    Action routine for:
        "smell OBJ"

       PRINT           "It smells just like a"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."

Routine R0163, 3 locals (0000, 0000, 0000)

       GET_PROP_ADDR   L01,#0f -> L02
       JZ              L02 [TRUE] RFALSE
       GET_PROP_LEN    L02 -> -(SP)
       SUB             (SP)+,#01 -> -(SP)
       CALL            R0044 (L00,L02,(SP)+) -> -(SP)
       RET_POPPED      

Routine R0164, 0 locals ()
    Action routine for:
        "bathe in OBJ"
        "bathe"

       PRINT           "Swimming isn't possible "
       JZ              Gaf [TRUE] L0001
       PRINT           "in the "
       PRINT_OBJ       Gaf
       JUMP            L0003
L0001: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0002
       PRINT           "on the grounds"
       JUMP            L0003
L0002: PRINT           "right on the floor, Sherlock"
L0003: PRINT_RET       "."

Routine R0165, 0 locals ()
    Pre-action routine for:
        "free OBJ from OBJ"
        "free OBJ"

       PRINT_RET       "This cannot be tied, so it cannot be untied!"

Routine R0166, 0 locals ()
    Action routine for:
        "free OBJ from OBJ"
        "free OBJ"

       PRINT_RET       "Foo!"

Routine R0167, 0 locals ()
    Pre-action routine for:
        "attach OBJ to OBJ"

       JE              Gb0,Ga8 [FALSE] RFALSE
       PRINT_RET       "You can't tie it to yourself."

Routine R0168, 0 locals ()
    Action routine for:
        "attach OBJ to OBJ"

       PRINT           "You can't tie the"
       CALL            R0046 -> -(SP)
       PRINT_RET       " to that."

Routine R0169, 0 locals ()
    Action routine for:
        "attach up OBJ with OBJ"

       PRINT_RET       "You could certainly never tie it with that!"

Routine R0170, 0 locals ()
    Action routine for:
        "mumble"

       PRINT_RET       "It has been a long day, hasn't it?"

Routine R0171, 0 locals ()
    Action routine for:
        "awake up OBJ"
        "awake OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "He's wide awake, or haven't you noticed?"
L0001: PRINT           "The"
       CALL            R0046 -> -(SP)
       PRINT_RET       " doesn't sleep."

Routine R0172, 0 locals ()

       PRINT_RET       "A series of fantasy simulation games and a trademark of
Infocom, Inc."

Routine R0173, 0 locals ()
    Action routine for:
        "carry on OBJ"
        "climb on OBJ"

       TEST_ATTR       Gaf,#0d [FALSE] L0001
       TEST_ATTR       Gaf,#0c [FALSE] L0001
       INSERT_OBJ      "player",Gaf
       PRINT           "You are now seated on the "
       PRINT_OBJ       Gaf
       PRINT_RET       "."
L0001: TEST_ATTR       Gaf,#0d [FALSE] L0002
       PRINT_RET       "This isn't the kind of thing to sit on!"
L0002: PRINT           "You can't climb onto the "
       PRINT_OBJ       Gaf
       PRINT_RET       "."

Routine R0174, 0 locals ()
    Action routine for:
        "climb OBJ"

       CALL            R0175 (#17,#01) -> -(SP)
       RET_POPPED      

Routine R0175, 4 locals (0017, 0000, 0000, 0000)
    Action routine for:
        "go up OBJ"
        "climb up OBJ"

       GET_PROP_ADDR   G00,L00 -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       CALL            R0010 (#82,L00) -> -(SP)
       RTRUE           
L0001: JZ              L01 [FALSE] L0002
       PRINT_RET       "You can't go that way."
L0002: JZ              L01 [TRUE] L0003
       GET_PROP_ADDR   Gaf,#13 -> L02
       GET_PROP_LEN    L02 -> -(SP)
       DIV             (SP)+,#02 -> -(SP)
       SUB             (SP)+,#01 -> -(SP)
       CALL            R0043 ("wall",L02,(SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] L0003
       PRINT_RET       "Climbing the walls is to no avail."
L0003: PRINT_RET       "Bizarre!"

Routine R0176, 0 locals ()
    Action routine for:
        "go down OBJ"
        "climb down OBJ"

       TEST_ATTR       Gaf,#0d [FALSE] L0001
       TEST_ATTR       Gaf,#0c [FALSE] L0001
       CALL            R0173 -> -(SP)
       RTRUE           
L0001: CALL            R0175 (#16) -> -(SP)
       RET_POPPED      

Routine R0177, 0 locals ()

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT           "Why would you send for the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "?"
L0001: PRINT_RET       "Sigh."

Routine R0178, 1 local (0000)
    Action routine for:
        "count OBJ"

       GET_PROP        Gaf,#03 -> L00
       TEST_ATTR       Gaf,#0a [FALSE] L0003
       PRINT           "There "
       JE              L00,#01 [FALSE] L0001
       PRINT           "is "
       JUMP            L0002
L0001: PRINT           "are "
L0002: PRINT_NUM       L00
       PRINT_RET       " of them."
L0003: JE              Gaf,#d5 [FALSE] L0004
       PRINT_RET       "There are two in a pair, or have you forgotten?"
L0004: PRINT_RET       "Unless you are drunk, one."

Routine R0179, 0 locals ()
    Action routine for:
        "slide OBJ under OBJ"
        "insert OBJ under OBJ"
        "press OBJ under OBJ"

       PRINT_RET       "There's not enough room."

Routine R0180, 0 locals ()
    Action routine for:
        "enter"

       CALL            R0010 (#82,#15) -> -(SP)
       RET_POPPED      

Routine R0181, 0 locals ()
    Action routine for:
        "exit OBJ"
        "exit"

       CALL            R0010 (#82,#14) -> -(SP)
       RET_POPPED      

Routine R0182, 0 locals ()
    Action routine for:
        "cross OBJ"

       PRINT_RET       "You can't cross that!"

Routine R0183, 0 locals ()
    Action routine for:
        "dig up OBJ"
        "dig in OBJ"
        "dig OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_OBJ       Gaf
       PRINT_RET       " grudgingly allows you to search. You find nothing
whatsoever of interest."
L0001: PRINT_RET       "You find nothing unusual."

Routine R0184, 5 locals (0000, 0000, 0000, 0000, 0000)
    Pre-action routine for:
        "know where OBJ"
        "dig for OBJ"
        "gaze for OBJ"
        "find OBJ"

       STORE           L00,G7e
       STORE           L01,G7d
       JIN             Gaf,#fd [FALSE] L0003
       JE              Gaf,G00 [FALSE] L0001
       PRINT_RET       "You're already here!"
L0001: TEST_ATTR       Gaf,#1e [FALSE] L0002
       PRINT_RET       "You should know - you've been there!"
L0002: PRINT_RET       "You're the detective!"
L0003: JE              Gaf,#7f [FALSE] L0004
       PRINT_RET       "He's in the morgue, no doubt."
L0004: TEST_ATTR       Gaf,#14 [FALSE] RFALSE
       GET_PROP        Ga8,#07 -> -(SP)
       LOADW           G03,(SP)+ -> L04
       GET_PROP        Gaf,#07 -> L02
       LOADW           L04,L02 -> L03
       JIN             Gaf,#ff [FALSE] L0005
       LOADW           G06,L02 -> Gaf
L0005: JE              L02,#05,#06,#03 [FALSE] L0006
       STORE           L00,G7c
       STORE           L01,G7b
L0006: JE              Ga8,#a0 [TRUE] L0007
       CALL            R0462 (Ga8) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
L0007: GET_PARENT      Ga8 -> L04
       GET_PARENT      Gaf -> -(SP)
       JE              L04,(SP)+ [FALSE] L0009
       JE              Ga8,#a0 [FALSE] L0008
       PRINT_RET       "Are you blind?"
L0008: PRINT_RET       ""Ahem...""
L0009: JZ              L03 [FALSE] L0011
       JE              Ga8,#a0 [FALSE] L0010
       PRINT           "You haven't seen "
       PRINT_PADDR     L00
       PRINT_RET       " yet."
L0010: PRINT           ""I haven't seen "
       PRINT_PADDR     L00
       PRINT_RET       " today.""
L0011: SUB             G76,L03 -> L03
       JE              Ga8,#a0 [FALSE] L0012
       PRINT           "You last saw "
       PRINT_PADDR     L00
       PRINT           " "
       JUMP            L0013
L0012: PRINT           ""I last saw "
       PRINT_PADDR     L00
       PRINT           " "
L0013: JG              L03,#78 [FALSE] L0014
       PRINT           "a few hours ago"
       JUMP            L0020
L0014: JG              L03,#50 [FALSE] L0015
       PRINT           "an hour or two ago"
       JUMP            L0020
L0015: JG              L03,#2d [FALSE] L0016
       PRINT           "about an hour ago"
       JUMP            L0020
L0016: JG              L03,#14 [FALSE] L0017
       PRINT           "about half an hour ago"
       JUMP            L0020
L0017: JG              L03,#0a [FALSE] L0018
       PRINT           "about 15 minutes ago"
       JUMP            L0020
L0018: JG              L03,#05 [FALSE] L0019
       PRINT           "less than 10 minutes ago"
       JUMP            L0020
L0019: PRINT           "just a minute ago"
L0020: JE              Ga8,#a0 [TRUE] L0021
       PRINT           ". I don't know where "
       PRINT_PADDR     L01
       PRINT_RET       " went, though.""
L0021: PRINT           "."
       NEW_LINE        
       RTRUE           

Routine R0185, 1 local (0000)
    Action routine for:
        "know where OBJ"
        "dig for OBJ"
        "gaze for OBJ"
        "find OBJ"

       GET_PARENT      Gaf -> L00
       JE              Gaf,#a0 [FALSE] L0001
       PRINT_RET       "You're around here somewhere..."
L0001: JE              #a0,Ga8 [TRUE] L0002
       PRINT_RET       ""I don't know.""
L0002: JE              L00,#ff [FALSE] L0003
       PRINT_RET       "You're the detective."
L0003: JIN             Gaf,Ga8 [FALSE] L0004
       PRINT_RET       "You have it."
L0004: JIN             Gaf,G00 [TRUE] L0005
       JE              Gaf,#fc [FALSE] L0006
L0005: PRINT_RET       "It's right here."
L0006: TEST_ATTR       L00,#14 [FALSE] L0007
       PRINT_OBJ       L00
       PRINT_RET       " has it."
L0007: TEST_ATTR       L00,#15 [FALSE] L0010
       PRINT           "It's "
       TEST_ATTR       L00,#1d [FALSE] L0008
       PRINT           "o"
       JUMP            L0009
L0008: PRINT           "i"
L0009: PRINT           "n the "
       PRINT_OBJ       L00
       PRINT_RET       "."
L0010: PRINT_RET       "Who knows?"

Routine R0186, 0 locals ()
    Action routine for:
        "say to OBJ"
        "tell OBJ"
        "ask OBJ"

       JE              Gaf,#a0 [FALSE] L0001
       PRINT_RET       "Talking to yourself is said to be a sign of impending
mental collapse."
L0001: TEST_ATTR       Gaf,#14 [FALSE] L0004
       JZ              Ga5 [TRUE] L0002
       STORE           Ga8,Gaf
       JUMP            L0003
L0002: PRINT_OBJ       Gaf
       PRINT           " is listening."
       NEW_LINE        
L0003: STORE           G7a,Gaf
       STORE           G79,G00
       RTRUE           
L0004: PRINT           "You can't talk to the"
       CALL            R0046 -> -(SP)
       PRINT           "!"
       NEW_LINE        
       STORE           G99,#00
       STORE           Ga5,#00
       RET             #02

Routine R0187, 0 locals ()
    Action routine for:
        "answer"

       PRINT           "Nobody seems to be awaiting your answer."
       NEW_LINE        
       STORE           Ga5,#00
       STORE           G99,#00
       RTRUE           

Routine R0188, 0 locals ()
    Action routine for:
        "answer OBJ"

       PRINT           "It is hardly likely that the "
       PRINT_OBJ       Gaf
       PRINT           " is interested."
       NEW_LINE        
       STORE           Ga5,#00
       STORE           G99,#00
       RTRUE           

Routine R0189, 0 locals ()
    Action routine for:
        "know about OBJ"
        "what about OBJ"
        "what OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "Surely you have read the interviews."
L0001: PRINT_RET       "Are you talking to yourself again?"

Routine R0190, 0 locals ()
    Action routine for:
        "kiss OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "Section 204D, Paragraph 7.6 of the Connecticut Police
Code of Conduct specifically prohibits kissing suspects."
L0001: PRINT_RET       "What a (ahem!) strange idea!"

Routine R0191, 0 locals ()
    Action routine for:
        "molest OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0002
       RANDOM          #64 -> -(SP)
       JG              #4b,(SP)+ [FALSE] L0001
       PRINT_RET       "Section 29A of the United States Criminal Code, whose
provisions come to your unhealthy mind, tut-tuts this sort of thing. A pity."
L0001: CALL            R0322 -> -(SP)
       RET_POPPED      
L0002: PRINT_RET       "What a (ahem!) strange idea!"

Routine R0192, 0 locals ()
    Action routine for:
        "diagno"

       PRINT_RET       "You're OK for now."

Routine R0193, 1 local (0000)
    Action routine for:
        "say"

       STORE           G99,#00
       STORE           Ga5,#00
       PRINT_RET       "To talk to someone, try 'SAY TO someone "something"'."

Routine R0194, 0 locals ()
    Pre-action routine for:
        "show OBJ to OBJ"

       STORE           Ga1,#01
       CALL            R0010 (#69,Gb0,Gaf) -> -(SP)
       RTRUE           

Routine R0195, 0 locals ()
    Action routine for:
        "show OBJ to OBJ"

       RTRUE           

Routine R0196, 0 locals ()
    Action routine for:
        "carry OBJ to OBJ"
        "show OBJ OBJ"

       JE              Gaf,#a0 [FALSE] L0001
       PRINT_RET       "Do you often talk to yourself?"
L0001: TEST_ATTR       Gaf,#14 [TRUE] L0002
       PRINT           "Do you expect applause from the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "?"
L0002: PRINT_OBJ       Gaf
       CALL            R0002 (G78) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT_RET       "."

Routine R0197, 0 locals ()
    Action routine for:
        "tell OBJ about OBJ"

       CALL            R0198 -> -(SP)
       RET_POPPED      

Routine R0198, 0 locals ()
    Action routine for:
        "confro OBJ with OBJ"

       JE              Gaf,#a0 [FALSE] L0001
       PRINT_RET       "You aren't talking to anyone!"
L0001: TEST_ATTR       Gaf,#14 [TRUE] L0002
       PRINT           "That ought to put a scare into the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."
L0002: PRINT_OBJ       Gaf
       CALL            R0002 (G78) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT_RET       "."

Routine R0199, 1 local (0000)
    Action routine for:
        "send for OBJ"

       TEST_ATTR       Gaf,#14 [TRUE] L0001
       PRINT_RET       "You can only send for a person."
L0001: JIN             Gaf,#ff [FALSE] L0002
       GET_PROP        Gaf,#07 -> -(SP)
       LOADW           G06,(SP)+ -> -(SP)
       JUMP            L0003
L0002: PUSH            Gaf
L0003: STORE           L00,(SP)+
       JIN             L00,G00 [FALSE] L0004
       PRINT_OBJ       L00
       PRINT_RET       " is already here."
L0004: PRINT_RET       "You can't send for people."

Routine R0200, 0 locals ()
    Action routine for:
        "analys off OBJ"
        "analys OBJ"
        "analys OBJ for OBJ"

       JE              Gb0,#6d [FALSE] L0001
       CALL            R0010 (#33,Gaf) -> -(SP)
       RTRUE           
L0001: TEST_ATTR       Gaf,#13 [FALSE] L0002
       CALL            R0330 -> -(SP)
       RET_POPPED      
L0002: JZ              G77 [TRUE] L0003
       PRINT_RET       "Duffy is already occupied with another errand."
L0003: JIN             Gaf,#ff [FALSE] L0004
       PRINT           "Duffy appears in an instant. "Well, I might be able to
analyze the "
       PRINT_OBJ       Gaf
       PRINT_RET       ", but you don't even have it with you!"  With that, he
discreetly leaves."
L0004: PRINT_RET       "Sergeant Duffy appears with a puzzled look on his face.
"With all respect, I don't think I can take THAT to the laboratory! I'll be
nearby if you need me." He leaves, shaking his head slowly."

Routine R0201, 0 locals ()
    Pre-action routine for:
        "accuse OBJ"
        "accuse OBJ with OBJ"

       JZ              Gb0 [FALSE] L0001
       STORE           Gb0,#89
L0001: JE              Gb0,#89 [TRUE] L0002
       PRINT_RET       "What an accusation!"
L0002: TEST_ATTR       Gaf,#14 [TRUE] RFALSE
       PRINT           "What a detective!  Quick, Sergeant!  Arrest that "
       PRINT_OBJ       Gaf
       PRINT_RET       "!"

Routine R0202, 0 locals ()
    Action routine for:
        "accuse OBJ"
        "accuse OBJ with OBJ"

       PRINT_OBJ       Gaf
       PRINT_RET       " shrugs off your suggestion."

Routine R0203, 0 locals ()
    Action routine for:
        "arrest OBJ"
        "arrest OBJ for OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT           "You realize that you don't have enough evidence to
convict "
       PRINT_OBJ       Gaf
       PRINT_RET       " so you resolve to continue the investigation."
L0001: JE              Gaf,#3d [FALSE] L0002
       PRINT           "Oh, come on now!  Not trusty "
       PRINT_OBJ       Gaf
       PRINT_RET       "!"
L0002: PRINT           "Sergeant Duffy enters, strokes his chin, and in a
rather puzzled voice says "Excuse me, sir, but it would cause quite a stir at
the station to be charging a "
       PRINT_OBJ       Gaf
       PRINT_RET       " with murder!"  He leaves quietly."

Routine R0204, 0 locals ()
    Action routine for:
        "ask OBJ about OBJ"

       JE              Gaf,#a0 [FALSE] L0001
       PRINT_RET       "Talking to yourself is said to be a sign of impending
mental collapse."
L0001: JE              Gaf,#44 [FALSE] L0002
       PRINT_RET       "Steven isn't in the area."
L0002: TEST_ATTR       Gaf,#14 [TRUE] L0003
       PRINT           "Do you often talk to a "
       PRINT_OBJ       Gaf
       PRINT_RET       "?"
L0003: PRINT_OBJ       Gaf
       PRINT_RET       " doesn't seem to know about that."

Routine R0205, 0 locals ()
    Action routine for:
        "ask OBJ for OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0003
       JE              Gaf,#a0 [TRUE] L0003
       JE              Gb0,#8f,#43 [FALSE] L0001
       CALL            R0010 (#15,Gaf,Gb0) -> -(SP)
       RTRUE           
L0001: PRINT_OBJ       Gaf
       JIN             Gb0,Gaf [FALSE] L0002
       PRINT           " hands you the "
       PRINT_OBJ       Gb0
       PRINT           "."
       NEW_LINE        
       INSERT_OBJ      Gb0,Ga8
       RTRUE           
L0002: PRINT_RET       " doesn't have that."
L0003: PRINT_RET       "Be serious!"

Routine R0206, 0 locals ()
    Action routine for:
        "carry OBJ up OBJ"

       PRINT_RET       "That doesn't seem to help at all."

Routine R0207, 6 locals (0000, 0000, 0000, 0000, 0000, 0000)

       GET_PROP        G00,#0c -> L01
       JZ              L01 [TRUE] RFALSE
L0001: SUB             L01,#0800 -> L02
       JL              L02,#00 [TRUE] L0002
       STORE           L03,G2c
       JUMP            L0013
L0002: SUB             L01,#0400 -> L02
       JL              L02,#00 [TRUE] L0003
       STORE           L03,G2d
       JUMP            L0013
L0003: SUB             L01,#0200 -> L02
       JL              L02,#00 [TRUE] L0004
       STORE           L03,G2e
       JUMP            L0013
L0004: SUB             L01,#0100 -> L02
       JL              L02,#00 [TRUE] L0005
       STORE           L03,G2f
       JUMP            L0013
L0005: SUB             L01,#80 -> L02
       JL              L02,#00 [TRUE] L0006
       STORE           L03,G30
       JUMP            L0013
L0006: SUB             L01,#40 -> L02
       JL              L02,#00 [TRUE] L0007
       STORE           L03,G31
       JUMP            L0013
L0007: SUB             L01,#20 -> L02
       JL              L02,#00 [TRUE] L0008
       STORE           L03,G32
       JUMP            L0013
L0008: SUB             L01,#10 -> L02
       JL              L02,#00 [TRUE] L0009
       STORE           L03,G33
       JUMP            L0013
L0009: SUB             L01,#08 -> L02
       JL              L02,#00 [TRUE] L0010
       STORE           L03,G34
       JUMP            L0013
L0010: SUB             L01,#04 -> L02
       JL              L02,#00 [TRUE] L0011
       STORE           L03,G35
       JUMP            L0013
L0011: SUB             L01,#02 -> L02
       JL              L02,#00 [TRUE] L0012
       STORE           L03,G36
       JUMP            L0013
L0012: SUB             L01,#01 -> L02
       JL              L02,#00 [TRUE] L0015
       STORE           L03,G37
L0013: CALL            R0208 (L03,L00) -> L04
       JZ              L05 [FALSE] L0014
       STORE           L05,L04
L0014: STORE           L01,L02
       JUMP            L0001
L0015: RET             L05

Routine R0208, 7 locals (0000, 0000, 0002, 0000, 0000, 0000, 0000)

L0001: LOADW           L00,L02 -> L05
       JZ              L05 [TRUE] RFALSE
       JE              L05,G00 [FALSE] L0002
       STORE           L03,#01
       JUMP            L0010
L0002: GET_CHILD       L05 -> L06 [FALSE] L0010
L0003: JZ              L01 [TRUE] L0004
       JE              L06,L01 [FALSE] L0007
       LOADW           L00,L03 -> L04
       JUMP            L0009
L0004: TEST_ATTR       L06,#14 [FALSE] L0007
       CALL            R0317 (L06) -> -(SP)
       JZ              (SP)+ [FALSE] L0007
       PRINT_OBJ       L06
       PRINT           " is "
       GET_PROP        L05,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0005
       PRINT           "off"
       JUMP            L0006
L0005: PRINT           "down the hall"
L0006: PRINT           " to "
       LOADW           L00,L03 -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           "."
       NEW_LINE        
L0007: GET_SIBLING     L06 -> L06 [TRUE] L0008
L0008: JZ              L06 [FALSE] L0003
L0009: JZ              L04 [TRUE] L0010
       RET             L04
L0010: INC             L02
       JUMP            L0001

Routine R0209, 0 locals ()
    Action routine for:
        "insert OBJ agains OBJ"
        "lean OBJ up OBJ"
        "lean OBJ on OBJ"
        "lean OBJ agains OBJ"

       PRINT_RET       "You can't do that!"

Routine R0210, 0 locals ()
    Action routine for:
        "finger OBJ"

       PRINT           "Upon looking over and dusting the"
       CALL            R0046 -> -(SP)
       PRINT_RET       " you notice that there are no good fingerprints to be
found."

Routine R0211, 0 locals ()
    Action routine for:
        "flush OBJ"

       PRINT_RET       "Whatever do you have in mind?"

Routine R0212, 0 locals ()

       PRINT_RET       "You can't do that."

Routine R0213, 0 locals ()
    Action routine for:
        "dig near OBJ"
        "dig around OBJ"
        "gaze near OBJ"

       PRINT_RET       "You don't find anything interesting."

Routine R0214, 0 locals ()
    Action routine for:
        "dig OBJ near OBJ"
        "dig OBJ around OBJ"

       JE              Gaf,#a3 [FALSE] L0001
       PRINT_RET       "You don't find anything interesting."
L0001: PRINT_RET       "Huh?"

Routine R0215, 0 locals ()
    Action routine for:
        "dig OBJ under OBJ"

       CALL            R0214 -> -(SP)
       RET_POPPED      

Routine R0216, 0 locals ()
    Action routine for:
        "taste OBJ"

       PRINT_RET       "That's ridiculous!"

Routine R0217, 1 local (0000)

       STORE           L00,G00
       CALL            R0218 (Gaf) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       STORE           G00,Gaf
       PRINT           "You take a quick peek into the "
       PRINT_OBJ       Gaf
       PRINT           ":"
       NEW_LINE        
       CALL            R0059 -> -(SP)
       STORE           G00,L00
       RTRUE           

Routine R0218, 5 locals (0000, 0000, 0000, 0000, 0000)

       STORE           L01,#00
L0001: GET_NEXT_PROP   G00,L01 -> L01
       JZ              L01 [FALSE] L0002
       PRINT           "You can't seem to find that room."
       NEW_LINE        
       RFALSE          
L0002: JE              L01,#15,#14 [FALSE] L0003
       JUMP            L0001
L0003: JL              L01,Gc0 [TRUE] L0001
       GET_PROP_ADDR   G00,L01 -> L03
       GET_PROP_LEN    L03 -> L02
       JE              L02,#01 [FALSE] L0004
       LOADB           L03,#00 -> -(SP)
       JE              (SP)+,L00 [TRUE] RTRUE
L0004: JE              L02,#05 [FALSE] L0005
       LOADB           L03,#00 -> -(SP)
       JE              (SP)+,L00 [FALSE] L0005
       LOADB           L03,#01 -> -(SP)
       TEST_ATTR       (SP)+,#1c [TRUE] RTRUE
       PRINT           "The door to that room is closed."
       NEW_LINE        
       RFALSE          
L0005: JE              L02,#04 [FALSE] L0001
       LOADB           L03,#00 -> -(SP)
       JE              (SP)+,L00 [FALSE] L0001
       LOADB           L03,#01 -> -(SP)
       LOAD            [(SP)+] -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       PRINT           "You can't seem to find that room."
       NEW_LINE        
       RFALSE          

Routine R0219, 0 locals ()
    Action routine for:
        "write on OBJ with OBJ"
        "write with OBJ"

       PRINT_RET       "You're nuts."

Routine R0220, 5 locals (0000, 0000, 0000, 0000, 0000)
    Action routine for:
        "go with OBJ"
        "go in OBJ"
        "go to OBJ"
        "hide on OBJ"
        "enter OBJ"

       JIN             Gaf,#fd [FALSE] L0003
       JE              G00,Gaf [FALSE] L0001
       PRINT_RET       "Duuuhhh!"
L0001: CALL            R0446 (G00,Gaf) -> L02
       JZ              L02 [TRUE] L0002
       CALL            R0010 (#82,L02) -> -(SP)
       RTRUE           
L0002: PRINT_RET       "You can't go directly from here to there."
L0003: JZ              L00 [FALSE] L0004
       TEST_ATTR       Gaf,#13 [TRUE] L0004
       PRINT           "You hit your head against the"
       CALL            R0046 -> -(SP)
       PRINT_RET       " as you attempt this feat."
L0004: JZ              L00 [TRUE] L0005
       PRINT_RET       "You can't do that!"
L0005: JIN             Gaf,Ga8 [FALSE] L0006
       PRINT_RET       "That would involve quite a contortion!"
L0006: CALL            R0002 (G57) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           

Routine R0221, 0 locals ()
    Action routine for:
        "t"

       PRINT           "It is now "
       CALL            R0222 (G76) -> -(SP)
       PRINT_RET       "."

Routine R0222, 3 locals (0000, 0000, 0000)

       DIV             L00,#3c -> L01
       JG              L01,#0c [FALSE] L0001
       SUB             L01,#0c -> L01
       STORE           L02,#01
       JUMP            L0002
L0001: JE              L01,#0c [FALSE] L0002
       STORE           L02,#01
L0002: PRINT_NUM       L01
       PRINT           ":"
       MOD             L00,#3c -> L01
       JL              L01,#0a [FALSE] L0003
       PRINT           "0"
L0003: PRINT_NUM       L01
       PRINT           " "
       JZ              L02 [TRUE] L0004
       PUSH            S109
       JUMP            L0005
L0004: PUSH            S110
L0005: PRINT_PADDR     (SP)+
       RTRUE           

Routine R0223, 0 locals ()
    Action routine for:
        "use OBJ"

       PRINT_RET       "You should be more specific with what you want to do."

Routine R0224, 0 locals ()
    Action routine for:
        "play OBJ"

       PRINT_RET       "You are adept only at playing the fool."

Routine R0225, 0 locals ()
    Action routine for:
        "flip up OBJ"

       PRINT_RET       "That is silly."

Routine R0226, 0 locals ()
    Action routine for:
        "flip down OBJ"

       PRINT_RET       "That is silly."

Routine R0227, 0 locals ()
    Action routine for:
        "go behind OBJ"
        "hide behind OBJ"

       PRINT           "There's no room to hide behind the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."

Routine R0228, 0 locals ()
    Action routine for:
        "hide"

       JE              G00,#ee [FALSE] L0001
       PRINT_RET       "You might hide behind the shed."
L0001: JE              G00,#b9 [FALSE] L0002
       PRINT_RET       "You might hide on the balcony."
L0002: PRINT_RET       "There's no good hiding place here."

Routine R0229, 0 locals ()
    Action routine for:
        "call"

       PRINT_RET       "You must supply a verb!"

Routine R0230, 2 locals (0000, 0000)
    Action routine for:
        "call OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0006
       GET_PROP        Gaf,#07 -> -(SP)
       LOADW           G06,(SP)+ -> L00
       CALL            R0317 (L00) -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       STORE           L01,#01
L0001: JIN             L00,G00 [TRUE] L0002
       CALL            R0207 (L00) -> -(SP)
       JZ              (SP)+ [TRUE] L0005
L0002: PRINT_OBJ       L00
       CALL            R0462 (L00) -> -(SP)
       JZ              (SP)+ [TRUE] L0004
       JZ              L01 [TRUE] L0003
       PRINT_RET       " stops and turns toward you."
L0003: PRINT_RET       " is facing you."
L0004: PRINT_RET       " takes no notice of your call."
L0005: PRINT           "You don't see "
       PRINT_OBJ       L00
       PRINT_RET       " here."
L0006: CALL            R0229 -> -(SP)
       RET_POPPED      

Routine R0231, 0 locals ()
    Action routine for:
        "go OBJ over OBJ"

       PRINT_RET       "That doesn't make much sense."

Routine R0232, 0 locals ()
    Pre-action routine for:
        "feel OBJ on OBJ"
        "feel OBJ over OBJ"

       CALL            R0010 (#62,Gb0,Gaf) -> -(SP)
       RTRUE           

Routine R0233, 0 locals ()
    Action routine for:
        "feel OBJ on OBJ"
        "feel OBJ over OBJ"

       PRINT_RET       "Do you really expect that to help?"

Routine R0234, 0 locals ()
    Action routine for:
        "space"

       STORE           G75,#01
       PRINT_RET       "Spacing."

Routine R0235, 0 locals ()
    Action routine for:
        "unspac"

       STORE           G75,#00
       PRINT_RET       "No spacing."

Routine R0236, 0 locals ()
    Action routine for:
        "gaze on OBJ"

       TEST_ATTR       Gaf,#1d [FALSE] L0001
       CALL            R0133 -> -(SP)
       RET_POPPED      
L0001: PRINT           "There's no surface on the"
       CALL            R0046 -> -(SP)
       PRINT_RET       "."

Routine R0237, 0 locals ()
    Action routine for:
        "gaze up OBJ"

       TEST_ATTR       Gaf,#14 [FALSE] L0001
       PRINT_RET       "What a pervert!"
L0001: JE              Gaf,#fd [TRUE] L0002
       PRINT_RET       "Your sanity is in question."
L0002: JE              G00,#e4,#df [FALSE] L0003
       PRINT_RET       "You can see a balcony directly above you."
L0003: JE              G00,#e9 [FALSE] L0004
       PRINT_RET       "There's nothing up there."
L0004: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0005
       PRINT_RET       "There is blue sky above you."
L0005: PRINT_RET       "You can see the ceiling. It's not the Sistine Chapel,
but it's nicely painted."

Routine R0238, 0 locals ()
    Action routine for:
        "gaze down OBJ"

       JE              Gaf,#fd [FALSE] L0002
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0001
       PRINT_RET       "There's dirt there, mostly. And grass."
L0001: PRINT_RET       "Nothing's interesting about the floor."
L0002: PRINT_RET       "Your sanity is in question."

Routine R0239, 0 locals ()
    Action routine for:
        "maybe"

       JZ              G7a [TRUE] L0001
       PRINT_OBJ       G7a
       PRINT_RET       " ignores you completely."
L0001: PRINT_RET       "Did you say something?"

Routine R0240, 0 locals ()
    Action routine for:
        "did"
        "thank OBJ"
        "thank"

       JZ              Gaf [FALSE] L0001
       JZ              G7a [TRUE] L0004
L0001: JZ              Gaf [TRUE] L0002
       PUSH            Gaf
       JUMP            L0003
L0002: PUSH            G7a
L0003: PRINT_OBJ       (SP)+
       PRINT_RET       " acknowledges your thanks."
L0004: PRINT_RET       "Whatever do you have to be thankful for?"

Routine R0241, 0 locals ()
    Action routine for:
        "call up OBJ"

       TEST_ATTR       Gaf,#14 [TRUE] L0001
       PRINT_RET       "Perhaps it's time for you to rest...."
L0001: JIN             Gaf,G00 [FALSE] L0002
       PRINT_OBJ       Gaf
       PRINT_RET       " is here!"
L0002: JE              G00,#ca,#b9,#b2 [TRUE] L0003
       PRINT_RET       "There's no phone here."
L0003: PRINT           "There's no sense in phoning "
       PRINT_OBJ       Gaf
       PRINT_RET       "."

Routine R0242, 0 locals ()
    Action routine for:
        "$ve"

       PRINT           "Verifying game..."
       NEW_LINE        
       VERIFY          [FALSE] L0001
       PRINT_RET       "Game correct."
L0001: NEW_LINE        
       PRINT_RET       "** Game File Failure **"

Routine R0243, 3 locals (0000, 0000, 0000)

       PRINT_PADDR     L00
       TEST_ATTR       L01,#1c [FALSE] L0001
       PRINT           "open"
       JUMP            L0002
L0001: PRINT           "closed"
L0002: PRINT_PADDR     L02
       NEW_LINE        
       RTRUE           

Routine R0244, 1 local (0000)

       JE              L00,#01 [FALSE] RFALSE
       JE              Gb1,#82 [FALSE] RFALSE
       JE              Gaf,#1b,#1f [FALSE] RFALSE
       JIN             "wooden ladder","player" [FALSE] RFALSE
       PRINT_PADDR     G74
       NEW_LINE        
       RTRUE           

Routine R0245, 1 local (0000)

       JE              L00,#01 [FALSE] L0001
       JE              Gb1,#82 [FALSE] L0001
       JE              Gaf,#1f [FALSE] L0001
       JIN             "wooden ladder","player" [FALSE] L0001
       PRINT_PADDR     G74
       NEW_LINE        
       RTRUE           
L0001: JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S112,#f5,S113) -> -(SP)
       PRINT_RET       "You can walk around the house from here to the east or
west. To the south a rolling lawn leads to the entrance of the estate."

Routine R0246, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       PRINT_RET       "You are at the edge of a large rose garden,
meticulously maintained by the gardener, Mr. McNabb. He is said to be
exceedingly proud of this particular garden, which is the envy of the
neighbors. Rows of roses are neatly arranged and the sweet fragrance of the
flowers is worth a trip here in itself. An orchard to the east contains many
varieties of fruit trees and wide lawns lie to the west and north. The roses
themselves are to the south, filling the area between you and the back of the
house."

Routine R0247, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       PRINT           "You are amidst lovely trees bearing apples, pears,
peaches, and other fruits. A grape arbor and several berry bushes may also be
seen. The kitchen window and east side of the house are just to your south, and
a path skirts the orchard to your north."
       NEW_LINE        
       JZ              G1c [TRUE] L0001
       PRINT_RET       "A ladder is leaning against the balcony above."
L0001: PRINT_RET       "There is no way into the house from here."

Routine R0248, 1 local (0000)

       JE              L00,#03 [FALSE] L0003
       PRINT           "You are among rows of roses. The ground is soft, and
your footsteps leave a rather bad impression as many poor seedlings are
trampled underfoot. A safer place to admire the flowers lies to the north. A
window to the south allows a view into the house."
       NEW_LINE        
       JZ              G59 [FALSE] L0001
       PRINT           "There is no way into the house from here."
       NEW_LINE        
       JUMP            L0002
L0001: PRINT           "A ladder is leaning against the house, its upper end
against a balcony above."
       NEW_LINE        
L0002: TEST_ATTR       "holes",#1f [TRUE] RTRUE
       PRINT_RET       "There are holes in the soft dirt near your feet."
L0003: JE              L00,#02 [FALSE] RFALSE
       JZ              G72 [FALSE] RFALSE
       JZ              G63 [FALSE] RFALSE
       GET_PARENT      "Mr. McNabb" -> -(SP)
       JE              (SP)+,#e7,#de,#f0 [FALSE] RFALSE
       PRINT           "In the distance you hear "Hey! WHAT? You, there!" and
other choice words muffled by a strong Scottish burr and a stiff breeze. Now,
standing at the edge of the garden, can be seen the person of Mr. Angus McNabb,
the gardener. He advances, looking crazed and gesticulating wildly. With each
carefully chosen step in your direction, a barely visible wince of pain comes
to his deeply-lined face. He regards you as you would regard the man whose car
just ran over your little puppy dog."
       NEW_LINE        
       JZ              G71 [TRUE] L0004
       PRINT           ""I canna believe it! I've already spent an hour fixing
up the ground here where some fool was walkin' aboot--and now you! I canna
believe it!""
       NEW_LINE        
L0004: STORE           G72,#01
       STORE           G73,#01
       CALL            R0004 (#4e4f,#5a) -> -(SP)
       STOREW          (SP)+,#00,#01
       INSERT_OBJ      "Mr. McNabb",G00
       RTRUE           

Routine R0249, 0 locals ()

       STORE           G73,#00
       RTRUE           

Routine R0250, 1 local (0000)

       JE              L00,#02 [FALSE] L0001
       JZ              G42 [FALSE] RFALSE
       JL              G76,#02bc [FALSE] RFALSE
       PRINT           "Mrs. Robner appears, walking down a hallway from the
north."
       NEW_LINE        
       CALL            R0311 -> -(SP)
       RET_POPPED      
L0001: JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S114,#f5,S115) -> -(SP)
       RET_POPPED      

Routine R0251, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S116,#da,S113) -> -(SP)
       RET_POPPED      

Routine R0252, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S117,#d7,S113) -> -(SP)
       CALL            R0243 (S118,#d8,S113) -> -(SP)
       RET_POPPED      

Routine R0253, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S119,#da,S113) -> -(SP)
       RET_POPPED      

Routine R0254, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S120,#d8,S113) -> -(SP)
       RET_POPPED      

Routine R0255, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       STORE           G42,#01
       CALL            R0243 (S121,#f3,S122) -> -(SP)
       PRINT_RET       "A wood pile sits beside a huge fieldstone fireplace. A
double doorway leading to the main hall is the only exit. Pictures of Mrs.
Robner's colonial ancestors line one wall. The room contains formal seating for
at least fifteen people, in several groups of chairs and couches. Tables and
cabinets, all of the finest mahogany and walnut, complete the furnishings. On
one of the tables is a telephone."

Routine R0256, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       PRINT           "You are just west of the staircase. There are doors on
both sides (north and south) of the hallway, which continues west. "
       TEST_ATTR       "south door",#1c [FALSE] L0002
       TEST_ATTR       "bedroom door",#1c [FALSE] L0001
       PRINT_RET       "Both doors are open."
L0001: PRINT_RET       "The door to the south is open."
L0002: TEST_ATTR       "bedroom door",#1c [FALSE] L0003
       PRINT_RET       "The door to the north is open."
L0003: PRINT_RET       "Both doors are closed."

Routine R0257, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S130,#bc,S113) -> -(SP)
       RET_POPPED      

Routine R0258, 1 local (0000)

       JE              L00,#02 [FALSE] L0001
       ADD             G48,#01 -> -(SP)
       JE              G76,(SP)+ [FALSE] L0001
       PRINT           "As you enter the hallway, you catch a glimpse of George
running down the stairs."
       NEW_LINE        
       RFALSE          
L0001: JE              L00,#03 [FALSE] RFALSE
       PRINT_RET       "This is the west end of the upstairs hall. To the north
is the library, where Mr. Robner was found. Its solid oak door has been knocked
down and is lying just inside the entrance to the library. A window which
cannot be opened is at the end of the hallway."

Routine R0259, 1 local (0000)

       STORE           G42,#01
       JE              L00,#03 [FALSE] RFALSE
       PRINT           "This is the library where Mr. Robner's body was found.
It is decorated in a simple but comfortable style. Mr. Robner obviously spent a
great deal of time here. A wide executive desk sits before tall balcony windows
which lie at the north of the room. A telephone is sitting on the desk. The
east side of the room is composed of three large bookshelf units containing
numerous volumes on many topics. The floor is carpeted from wall to wall. The
massive oak door which blocked the entrance has been forcibly knocked off its
hinges and is lying by the doorway."
       NEW_LINE        
       TEST_ATTR       "balcony door",#1c [FALSE] L0001
       PRINT           "The window to the balcony has been opened."
       NEW_LINE        
L0001: TEST_ATTR       "hidden door",#1c [FALSE] RTRUE
       PRINT_RET       "The bookshelf unit on the far left has been swung open,
revealing a room behind it!"

Routine R0260, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S131,#b7,S113) -> -(SP)
       JZ              G59 [TRUE] L0001
       PRINT           "The top of a ladder is resting on the metal railing."
       NEW_LINE        
L0001: JIN             "Mr. McNabb","Garden Path" [FALSE] L0002
       PRINT_RET       "Mr. McNabb is tending to the roses."
L0002: JIN             "Mr. McNabb","North Lawn" [FALSE] RTRUE
       PRINT           "Away to the north, Mr. McNabb can be seen "
       CALL            R0002 (G6f) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT_RET       "."

Routine R0261, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       PRINT           "This is a secret room situated between the library and
the master bedroom. The room is bare and somewhat dusty, as if it were not
often used. An unmarked switchplate surrounds two buttons, one blue and one
red. A formidable safe is embedded in the south wall."
       TEST_ATTR       "safe",#1c [FALSE] L0001
       PRINT           " The heavy safe door is wide open."
L0001: NEW_LINE        
       TEST_ATTR       "hidden door",#1c [FALSE] L0002
       PRINT_RET       "The library can be seen through a door to the west."
L0002: TEST_ATTR       "hidden door",#1c [FALSE] RTRUE
       PRINT_RET       "The master bedroom can be seen through a door to the
east."

Routine R0262, 0 locals ()

       JE              Gb1,#5d [FALSE] RFALSE
       TEST_ATTR       "hidden door",#1c [FALSE] L0001
       CLEAR_ATTR      "hidden door",#1c
       PRINT_RET       "The wall to the west silently closes."
L0001: SET_ATTR        "hidden door",#1c
       PRINT_RET       "The wall to the west swings open, revealing the library
on the other side."

Routine R0263, 0 locals ()

       JE              Gb1,#5d [FALSE] RFALSE
       TEST_ATTR       "hidden door",#1c [FALSE] L0001
       CLEAR_ATTR      "hidden door",#1c
       PRINT_RET       "The wall to the east swings closed."
L0001: SET_ATTR        "hidden door",#1c
       PRINT           "The wall to the east swings open, revealing the master
bedroom on the other side."
       NEW_LINE        
       JZ              G6d [FALSE] RTRUE
       JIN             "Mrs. Robner","Master Bedroom" [FALSE] RTRUE
       PRINT           "Mrs. Robner, sitting on her bed, appears stunned. She
walks over and peeks in, speaks of her complete surprise at the presence of
such a place, and returns to her bed, somewhat shaken."
       NEW_LINE        
       STORE           G6d,#01
       RTRUE           

Routine R0264, 1 local (0000)

       JE              L00,#02 [FALSE] L0001
       JE              G1d,#b2 [FALSE] L0001
       PRINT           "As you walk through the door, there is an explosion
from in front of you! The impact of the bullet knocks you to the ground,
stunned. You struggle, trying to look up. Another explosion! You fall back,
into a long silence."
       NEW_LINE        
       QUIT            
       RTRUE           
L0001: JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S132,#b1,S133) -> -(SP)
       TEST_ATTR       "hidden door",#1c [FALSE] RTRUE
       PRINT_RET       "Part of the west wall has been swung away, revealing a
hidden closet."

Routine R0265, 1 local (0000)

       JE              L00,#02 [FALSE] L0001
       JE              G1d,#af [FALSE] L0001
       PRINT           "As you enter the balcony, there is an explosion and a
burst of flame from your left. The pain freezes you for a moment as everything
becomes black. While you await a choir of angels, a short chuckle and the sound
of running feet are the last you hear."
       NEW_LINE        
       QUIT            
       RTRUE           
L0001: JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S134,#b1,S113) -> -(SP)
       JZ              G1c [TRUE] RTRUE
       PRINT_RET       "The top of a ladder is visible here, leaning on the
railing."

Routine R0266, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S135,#ab,S113) -> -(SP)
       RET_POPPED      

Routine R0267, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       PRINT           "This bathroom contains the usual sink, toilet, and
bath. A medicine cabinet, "
       TEST_ATTR       "cabinet",#1c [FALSE] L0001
       PRINT           "lying partially open"
       JUMP            L0002
L0001: PRINT           "closed"
L0002: CALL            R0243 (S136,#ab,S113) -> -(SP)
       RET_POPPED      

Routine R0268, 1 local (0000)

       JE              L00,#02 [FALSE] L0001
       JZ              G1b [TRUE] L0001
       STORE           G6c,#01
       RTRUE           
L0001: JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S137,#c0,S113) -> -(SP)
       RET_POPPED      

Routine R0269, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       CALL            R0243 (S138,#a5,S113) -> -(SP)
       RET_POPPED      

Routine R0270, 1 local (0000)

       JE              L00,#03 [FALSE] RFALSE
       PRINT           "This is George's bedroom. In addition to the normal
furnishings, there is a small liquor cabinet, and a stereo with records and
tapes. The door, leading to the hallway to the north, is "
       TEST_ATTR       "bedroom door",#1c [FALSE] L0001
       PRINT           "open"
       JUMP            L0002
L0001: PRINT           "closed"
L0002: CALL            R0243 (S139,#a5,S113) -> -(SP)
       JZ              G12 [TRUE] RTRUE
       PRINT           "Playing on the stereo is a "
       PRINT_PADDR     G12
       PRINT_RET       "."

Routine R0271, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The lawn is well manicured."

Routine R0272, 0 locals ()

       JE              Gb1,#4a [FALSE] L0003
       JE              G00,#f4 [FALSE] L0001
       PRINT_RET       "You see the living room through the window."
L0001: JIN             "Mr. McNabb","South Lawn" [FALSE] L0002
       PRINT           "Through the bay windows the gardener, Mr. McNabb, can
be seen "
       CALL            R0002 (G6f) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT_RET       " on the south lawn."
L0002: PRINT_RET       "You can see the south lawn."
L0003: JE              Gb1,#59 [FALSE] RFALSE
       TEST_ATTR       "Foyer",#1e [TRUE] RFALSE
       PRINT_RET       "The window seems to be latched from the inside."

Routine R0273, 0 locals ()

       JE              Gb1,#6b [FALSE] L0001
       PRINT_RET       "They smell nice."
L0001: JE              Gb1,#2f [FALSE] L0002
       PRINT_RET       "There are rows of yellow, red, pink, and white roses
here."
L0002: JE              Gb1,#5b [FALSE] RFALSE
       PRINT_RET       "Taking a rose would be most ungracious, and possibly
dangerous if Mr. McNabb found out."

Routine R0274, 0 locals ()

       JE              Gb1,#32 [FALSE] L0001
       PRINT_RET       "It's right here. Some inspector you are."
L0001: JE              Gb1,#2d [FALSE] L0004
       JE              G00,#f6 [FALSE] L0002
       TEST_ATTR       "front door",#1c [FALSE] L0002
       CALL            R0110 (#dd) -> -(SP)
       RET_POPPED      
L0002: JE              G00,#f2 [FALSE] L0003
       TEST_ATTR       "bay window",#1c [FALSE] L0003
       CALL            R0110 (#ca) -> -(SP)
       RET_POPPED      
L0003: PRINT_RET       "You might try the front door."
L0004: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The house is a magnificent New England colonial, like
many other houses around the lake. It is painted slate gray with white trim."

Routine R0275, 0 locals ()

       JE              Gb1,#19 [FALSE] L0001
       JIN             "fragment","player" [FALSE] L0001
       JZ              G66 [FALSE] L0001
       CALL            R0010 (#19,#63) -> -(SP)
       RTRUE           
L0001: JE              Gb1,#4f,#50,#2f [FALSE] RFALSE
       JE              G00,#d6 [FALSE] L0002
       PRINT_RET       "The floor is hardwood."
L0002: JE              G00,#dd [FALSE] L0003
       PRINT_RET       "The floor is marble."
L0003: JE              G00,#e4 [FALSE] L0006
       TEST_ATTR       "holes",#1f [TRUE] L0004
       CALL            R0010 (#4f,#64) -> -(SP)
       RTRUE           
L0004: JE              Gb1,#52 [FALSE] L0005
       JE              Gb0,#e3 [FALSE] L0005
       PRINT_RET       "The balcony above is very large. Searching the entire
area beneath it would take a great deal of time."
L0005: PRINT_RET       "There are rows upon rows of roses here. It would take
you the best part of a day to search the ground in great detail."
L0006: PRINT_RET       "You don't find anything new there."

Routine R0276, 0 locals ()

       JE              Gb1,#6b [FALSE] RFALSE
       JE              G00,#e7,#e4 [FALSE] L0001
       PRINT_RET       "The smell of roses permeates everything."
L0001: JE              G00,#de,#ee,#f0 [FALSE] L0002
       PRINT_RET       "A breeze carries the faint smell of roses through the
air."
L0002: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0003
       PRINT_RET       "The air is clear and fresh here."
L0003: CALL            R0277 (G00) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       PRINT_RET       "The air is rather musty here."

Routine R0277, 5 locals (0000, 0000, 0000, 0000, 0000)

       STORE           L01,#00
L0001: GET_NEXT_PROP   G00,L01 -> L01
       JZ              L01 [TRUE] RFALSE
       JL              L01,Gc0 [TRUE] L0001
       GET_PROP_ADDR   G00,L01 -> L03
       GET_PROP_LEN    L03 -> L02
       JE              L02,#05 [FALSE] L0001
       LOADB           L03,#01 -> L04
       TEST_ATTR       L04,#1c [FALSE] L0001
       PRINT           "There is a pleasant breeze coming through the "
       PRINT_OBJ       L04
       PRINT_RET       "."

Routine R0278, 0 locals ()

       JE              Gb1,#2d,#3c,#6d [FALSE] L0001
       PRINT_RET       "You're not on vacation, but with ideas like that you
will probably be given a rather long one."
L0001: JE              Gb1,#2f,#4a [FALSE] RFALSE
       JE              G00,#de [FALSE] L0002
       JIN             "wet piece of paper","lake" [FALSE] L0002
       PRINT           "A crumpled piece of paper is floating on the water a
few feet from shore. With an uncommonly agile motion, you retrieve the drenched
paper."
       NEW_LINE        
       INSERT_OBJ      "wet piece of paper",Ga8
       RTRUE           
L0002: PRINT_RET       "Surely you don't suspect the fish also?"

Routine R0279, 0 locals ()

       JE              Gb1,#2d [FALSE] L0002
       JE              G00,#ee,#e8 [FALSE] L0001
       CALL            R0110 (#e9) -> -(SP)
       RTRUE           
L0001: PRINT_RET       "Senility strikes!"
L0002: JE              Gb1,#45 [FALSE] L0003
       JZ              G1f [TRUE] RFALSE
       PRINT_RET       "You hear two muffled voices inside the shed."
L0003: JE              Gb1,#3b [FALSE] RFALSE
       JE              G00,#ee [FALSE] L0004
       PRINT           "You carefully sneak behind the shed. It seems that no
one saw you."
       NEW_LINE        
       JUMP            L0005
L0004: PRINT           "You leave the shed and quietly slip behind it. Nobody
appears to have seen you."
       NEW_LINE        
L0005: CALL            R0110 (#e8) -> -(SP)
       RTRUE           

Routine R0280, 0 locals ()

       RFALSE          

Routine R0281, 0 locals ()

       PRINT           "McNabb grabs your arm and leads you to a spot deep
within the garden and near the house. You might never have found this place
alone. He points at the ground, where you see two holes in the soft earth."
       NEW_LINE        
       CLEAR_ATTR      "holes",#1f
       STORE           G6b,#01
       RTRUE           

Routine R0282, 0 locals ()

       JZ              G6a [FALSE] L0001
       PRINT_RET       "What hole?"
L0001: JE              Gb1,#15 [TRUE] RFALSE
       JE              Gb1,#32 [FALSE] L0005
       JE              G00,#e4 [TRUE] L0002
       PRINT_RET       "They're among the roses, or have you forgotten?"
L0002: TEST_ATTR       "holes",#1f [TRUE] L0003
       PRINT_RET       "They're right here!"
L0003: JZ              G6b [FALSE] L0004
       RANDOM          #64 -> -(SP)
       JG              #50,(SP)+ [FALSE] L0004
       PRINT_RET       "The rose garden is vast and full of thorny roses. You
might look for the rest of the day before you find them."
L0004: PRINT_RET       "The garden is rather big, even just the area you are
searching now, and the holes were small. They're not here, but are probably
nearby."
L0005: JE              #64,Gb0,Gaf [FALSE] L0013
       JE              Gb1,#4a,#2f [FALSE] L0006
       PRINT_RET       "There are two holes here, each about two inches by four
inches. They are at least three inches deep and the soil is compacted around
them."
L0006: JE              Gb1,#51 [FALSE] L0007
       JE              Gaf,#a3 [TRUE] L0008
L0007: JE              Gb1,#4f [FALSE] RFALSE
L0008: GET_PARENT      "Mr. McNabb" -> -(SP)
       JE              (SP)+,G00 [FALSE] L0009
       PRINT           "Mr. McNabb watches you with ill-concealed irritation."
       NEW_LINE        
L0009: JZ              G64 [TRUE] L0010
       PRINT_RET       "Aside from dirt, organic fertilizer, and small crawly
creatures, you turn up nothing but roses."
L0010: INC_CHK         G69,#02 [TRUE] L0011
       RANDOM          #64 -> -(SP)
       JG              #1e,(SP)+ [FALSE] L0012
L0011: PRINT           "Ouch! You cut your finger on a sharp edge as you dig.
You search carefully in the dirt, now that you are sure something is there, and
pull up a piece of porcelain, covered with dirt and dried mud."
       NEW_LINE        
       CALL            R0307 (#63) -> -(SP)
       INSERT_OBJ      "fragment",Ga8
       CLEAR_ATTR      "fragment",#1f
       STORE           G64,#01
       STORE           G65,#01
       RTRUE           
L0012: LOADW           G68,G69 -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0013: PRINT_RET       "There is no hole here."

Routine R0283, 0 locals ()

       JE              Gb1,#2f [FALSE] L0003
       JZ              G66 [TRUE] L0002
       PRINT           "The fragment is beautifully hand-painted"
       STORE           G67,#01
       JZ              G2b [TRUE] L0001
       PRINT           ", exactly like those you saw in the kitchen"
L0001: PRINT_RET       "."
L0002: PRINT_RET       "The piece of porcelain is filthy, coated with dried
mud. You can barely make out some design underneath the dirt."
L0003: JE              Gb1,#33 [FALSE] L0004
       PRINT_RET       "It's covered with dirt and mud. You realize that there
would be no good fingerprints on it."
L0004: JE              Gb1,#10 [FALSE] L0005
       CALL            R0330 -> -(SP)
       RET_POPPED      
L0005: JE              Gb1,#19 [FALSE] RFALSE
       STORE           G66,#01
       PRINT           "As you wipe off the piece of porcelain, you notice that
it is a fragment of some very beautiful piece, handsomely painted."
       JZ              G2b [TRUE] L0006
       PRINT           "  The markings are identical to those you saw on the
china in the kitchen."
L0006: NEW_LINE        
       RTRUE           

Routine R0284, 1 local (0000)

       JE              L00,#05 [FALSE] L0008
       CALL            R0317 (#9f) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       GET_PARENT      "Mr. McNabb" -> -(SP)
       JE              (SP)+,#e2 [FALSE] L0001
       PRINT           "Mr. McNabb is here, pruning the trees."
       JUMP            L0005
L0001: GET_PARENT      "Mr. McNabb" -> -(SP)
       JE              (SP)+,#de,#ee [TRUE] L0002
       GET_PARENT      "Mr. McNabb" -> -(SP)
       JE              (SP)+,#f9,#f0 [FALSE] L0003
L0002: PRINT           "Mr. McNabb is here, "
       CALL            R0002 (G6f) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT           "."
       JUMP            L0005
L0003: JIN             "Mr. McNabb","Garden Path" [FALSE] L0004
       PRINT           "Mr. McNabb is here, "
       CALL            R0002 (G6e) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT           "."
       JUMP            L0005
L0004: PRINT           "Mr. McNabb is here."
L0005: JZ              G71 [TRUE] L0006
       PRINT           " He seems quite worked up and is talking aloud to
himself."
       JUMP            L0007
L0006: JZ              G72 [TRUE] L0007
       PRINT           " He seems pretty angry about something."
L0007: NEW_LINE        
       CALL            R0354 (#9f) -> -(SP)
       RET_POPPED      
L0008: JE              Gb1,#38,#39 [FALSE] L0011
       JZ              G72 [TRUE] L0009
       PRINT_RET       "McNabb grunts briefly in your direction."
L0009: JZ              G71 [TRUE] L0010
       PRINT_RET       "He answers absently and starts to mumble quietly about
the roses."
L0010: PRINT           "He replies with a brief nod, and then starts mumbling
to himself about the "
       CALL            R0002 (G62) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT_RET       "."
L0011: JE              Ga8,#9f [FALSE] L0018
       JE              Gb1,#69 [FALSE] L0017
       JE              Gb0,#65,#64 [TRUE] L0012
       JE              Gb0,#86,#e6 [FALSE] L0017
L0012: JZ              G6a [FALSE] L0013
       JZ              G71 [FALSE] L0013
       PRINT_RET       ""I don't know what you're-a talkin' aboot.""
L0013: JZ              G16 [TRUE] L0014
       PRINT_RET       ""I don't think I remember where it was. Now go away,"
he says. He looks a bit annoyed at you, probably for asking him before and then
running off."
L0014: JZ              G6b [TRUE] L0015
       PRINT_RET       ""I've already shown you plenty. Now, git!""
L0015: JE              G00,#e4 [FALSE] L0016
       STORE           G63,#01
       STORE           G6a,#01
       CALL            R0281 -> -(SP)
       RET_POPPED      
L0016: CALL            R0442 (#9f,#e4,#01) -> -(SP)
       STORE           G63,#01
       STORE           G6a,#01
       PRINT_RET       ""Follow me!" he says, and starts walking toward the
roses."
L0017: JE              Gb1,#32 [TRUE] RFALSE
       CALL            R0397 (#9f) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       CALL            R0002 (G61) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0018: JE              Gb1,#45 [FALSE] L0020
       JZ              G71 [TRUE] L0019
       PRINT           "You can't make out everything, but he seems to be
complaining about weeks of work on the roses ruined by someone stomping around
in the garden. There are references to elephants and holes. When he's worked
up, as now, he doesn't always make much sense."
       NEW_LINE        
       STORE           G6a,#01
       RTRUE           
L0019: PRINT           "He seems to be mumbling about the "
       CALL            R0002 (G62) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT_RET       "."
L0020: JE              Gb1,#15 [FALSE] RFALSE
       JE              Gaf,#9f [FALSE] RFALSE
       JZ              G73 [TRUE] L0021
       JZ              G63 [FALSE] L0021
       PRINT_RET       ""I dinna give a hoot about you or your questions! Now,
begone! Steppin' all o'er me roses. A crime, it is! I'll call the police is
what!" He seems pretty angry."
L0021: JE              Gb0,#65 [FALSE] L0022
       JZ              G6a [TRUE] L0022
       PRINT_RET       ""I've already told you. There's holes in my garden!""
L0022: JE              Gb0,#85 [FALSE] L0023
       JZ              G71 [FALSE] L0023
       PRINT_RET       ""Beautiful! What a fine day. Except for the rain
Wednesday night, I ha'ent had such a fine week in a long spell. Not that I'm
complainin'. You see, with my roses..." He goes on and on about his roses."
L0023: JE              Gb0,#79,#7a [FALSE] L0024
       PRINT_RET       ""What aboot it? I use it for cleanin' the gutters 'n
prunin' the trees.""
L0024: JE              Gb0,#86,#e6,#85 [FALSE] L0026
       JZ              G71 [TRUE] L0025
       PRINT           "He tells you his story. He was tending to the roses
this morning when he noticed two deep holes in the garden, with a few roses
crushed nearby. He doesn't know when he'll be able to repair the damage."
       NEW_LINE        
       STORE           G6a,#01
       RTRUE           
L0025: PRINT_RET       "McNabb goes on for some time about the exquisite nature
of the garden in general and mentions, for your benefit, some of the finer
points of his gardening technique."
L0026: JE              Gb0,#f8 [FALSE] L0027
       PRINT_RET       "McNabb tells a long tale of woe and hardship, of days
and nights sweating with the lawn mower, roller, and weed puller."
L0027: JE              Gb0,#99,#98 [TRUE] L0028
       JE              Gb0,#9d,#9c [TRUE] L0028
       JE              Gb0,#9b,#9a [TRUE] L0028
       JE              Gb0,#97,#96 [TRUE] L0028
       JE              Gb0,#95,#94 [FALSE] L0029
L0028: PRINT_RET       ""I don't care much aboot any of them from in the house.
I barely even know which is which." He shakes his head and continues with his
work."
L0029: JE              Gb0,#7f [FALSE] L0030
       PRINT_RET       ""Too bad aboot Mr. Robner. He was a good man, liked to
talk aboot the garden. He told me 'McNabb', he says, 'this here's the finest
garden I've seen.' We'd talk for hours about planting and gardening. None of
the others knows between a rose and a sunflower." He shakes his head sadly and
continues his work."
L0030: PRINT_RET       ""I dinna know nothin' aboot that.""

Routine R0285, 1 local (0000)

       JE              L00,#05 [FALSE] L0008
       CALL            R0317 (#9d) -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       JUMP            L0007
L0001: JIN             "Mr. Baxter","shed" [FALSE] L0002
       JZ              G1f [TRUE] L0002
       PRINT           "Mr. Baxter and Ms. Dunbar are here talking rapidly with
each other. They haven't noticed you yet."
       NEW_LINE        
       JUMP            L0007
L0002: JZ              G21 [TRUE] L0003
       STORE           G21,#00
       PRINT           "Mr. Baxter is in one corner, talking to Ms. Dunbar. He
notices you and motions Dunbar to stop talking."
       NEW_LINE        
       JUMP            L0007
L0003: JIN             "Mr. Baxter","Living Room" [FALSE] L0006
       JZ              G4f [TRUE] L0004
       PRINT           "Mr. Baxter is offering his sympathies to Mrs. Robner."
       NEW_LINE        
       JUMP            L0007
L0004: JIN             "mystery book","Mr. Baxter" [FALSE] L0005
       SET_ATTR        "mystery book",#19
       PRINT           "Mr. Baxter is sitting here reading a book."
       NEW_LINE        
       JUMP            L0007
L0005: PRINT           "Mr. Baxter is sitting quietly here."
       NEW_LINE        
       JUMP            L0007
L0006: PRINT           "Mr. Baxter is here."
       NEW_LINE        
L0007: CALL            R0354 (#9d) -> -(SP)
       RET_POPPED      
L0008: JE              Gb1,#2f [FALSE] L0010
       JZ              G1a [TRUE] RFALSE
       JIN             "Mr. Baxter","Dunbar's Bedroom" [FALSE] L0009
       PRINT_RET       "Baxter seems out of breath. His hair is disheveled and
his hands are somewhat soiled."
L0009: PRINT_RET       "Mr. Baxter has recovered his composure and looks calm.
His hair is a bit disheveled and his hands are dirty."
L0010: JE              Gb1,#39 [FALSE] L0011
       PRINT_RET       "Mr. Baxter returns your salutation."
L0011: JE              Gb1,#38 [FALSE] L0012
       PRINT_RET       "Mr. Baxter nods."
L0012: JE              Ga8,#9d [FALSE] L0013
       JE              Gb1,#32 [TRUE] RFALSE
       CALL            R0397 (#9d) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       CALL            R0002 (G61) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0013: JE              Gb1,#53,#50 [FALSE] L0014
       PRINT_RET       "Mr. Baxter pushes you away abruptly. "I don't know what
game you're playing, Inspector, and frankly I'm not interested. You have been
invited here to investigate, not molest innocent persons.""
L0014: JE              Gb1,#0e [FALSE] L0015
       JE              Gb0,#89 [FALSE] L0015
       JZ              G60 [TRUE] RFALSE
       PRINT_RET       "Mr. Baxter turns to run away, but notices Sergeant
Duffy by the door. He stops abruptly and faces you."
L0015: JE              Gb1,#14 [FALSE] L0027
       JZ              G60 [FALSE] L0016
       JZ              G19 [TRUE] L0021
L0016: JIN             "Mr. Baxter",G00 [FALSE] L0017
       PRINT           "Sergeant Duffy enters the room solemnly. He places a
pair of handcuffs on Mr. Baxter, who is stiff and unspeaking. "Let's not have
any trouble, now." Duffy remarks to Baxter."
       JUMP            L0018
L0017: PRINT           "A few moments pass and Sergeant Duffy appears,
escorting a handcuffed Mr. Baxter."
L0018: PRINT           " With that, he leads him from your view and into a
police car waiting near the south lawn.

"
       CALL            R0424 (S150) -> -(SP)
       PRINT           "Congratulations on your work in the Robner case. As I'm
sure you are aware, Mr. Baxter was found guilty "
       TEST_ATTR       "stack of papers",#1e [FALSE] L0019
       JZ              G5d [TRUE] L0019
       PRINT           "of two counts of first-degree murder and has been
sentenced to two consecutive terms of life imprisonment. My only regret is that
Dunbar couldn't stand trial with him. We may never know the complete story
behind the Robner murder. But once again, thanks.

"
       JUMP            L0020
L0019: PRINT           "of first-degree murder in the death of Ms. Dunbar.
Unfortunately, Baxter remained tight-lipped throughout the proceedings, and
except for the revelation that Baxter and Dunbar were lovers, there was no
motive established for her murder. The jury acquitted Mr. Baxter in the murder
of Mr. Robner, as a motive had not been established. I am indeed sorry that a
proper conclusion to the case could not have been made.

"
L0020: CALL            R0431 -> -(SP)
       RET_POPPED      
L0021: JIN             "body of Ms. Dunbar","Dunbar's Bedroom" [FALSE] L0023
       PRINT           "Trusty Sergeant Duffy enters and places Mr. Baxter
under arrest. They leave, Baxter remaining calm.

"
       CALL            R0424 (S151) -> -(SP)
       PRINT           "I heard today that the jury in the Robner case has
voted to acquit Mr. Baxter of both murders at the Robner house."
       NEW_LINE        
       TEST_ATTR       "stack of papers",#1e [FALSE] L0022
       PRINT           "While it was clear that Baxter had committed numerous
crimes in the Focus case, the jury was unconvinced of the relation between that
and the murders. They felt that Ms. Dunbar had committed the first murder,
although I can't imagine any scenario in which that would be possible, and had
committed suicide in desperation. These explanations leave much to be desired,
but what's done is done. I can't help feeling that there is more to this case
than has been discovered. Thank you for your work.

"
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0022: PRINT           "The jury believed the more probable story: that Ms.
Dunbar committed the first murder and then committed suicide when her guilt
became clear to you. I don't really believe this any more than you do, but the
evidence is vague, you must agree. Thanks again for handling the case.

"
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0023: TEST_ATTR       "stack of papers",#1e [FALSE] L0025
       TEST_ATTR       "lab report",#1e [FALSE] L0024
       PRINT           "Trusty Sergeant Duffy enters and places Mr. Baxter
under arrest. They leave, Baxter remaining calm.

"
       CALL            R0424 (S152) -> -(SP)
       PRINT           "I am sorry to report that Mr. Baxter was acquitted
yesterday of the murder of Mr. Robner. In speaking to the District Attorney, I
gathered that the jury was almost convinced of Baxter's guilt, given that he
had both motive and a means to enter the house using the ladder. However, the
theory had a number of serious flaws, including the means by which Baxter could
have administered the drug either without Robner's knowledge or without a
struggle. I must confess that I too am baffled. I am convinced that Baxter is
guilty, but I fear we will never know for certain.

"
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0024: CALL            R0286 (#9d,#01) -> -(SP)
       RET_POPPED      
L0025: TEST_ATTR       "lab report",#1e [FALSE] L0026
       PRINT           "Duffy enters and places Mr. Baxter under arrest, then
leads him away without fuss.

"
       CALL            R0424 (S152) -> -(SP)
       PRINT           "I am indeed sorry that Mr. Baxter was acquitted
yesterday of the murder of Mr. Robner. From the District Attorney, I gather
that the jury was completely unconvinced by the our case. They found neither
sufficient motive nor any plausible means of introducing the fatal medicine
into Mr. Robner's drink. I must confess to being baffled by this case. Perhaps
we shall never know the true story of Mr. Robner's murder.

"
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0026: CALL            R0286 (#9d,#00) -> -(SP)
       RET_POPPED      
L0027: JE              Gb1,#16 [FALSE] L0028
       JIN             "body of Ms. Dunbar","Dunbar's Bedroom" [FALSE] L0028
       JE              Gb0,#4d [FALSE] L0028
       PRINT           "Baxter reaches instinctively into his jacket and starts
to pull out a pen. He hesitates suddenly, pen in hand."
       NEW_LINE        
       INSERT_OBJ      "blue pen","Mr. Baxter"
       STORE           G60,#01
       RTRUE           
L0028: JE              Gb1,#15 [FALSE] L0050
       JE              Gaf,#9d [FALSE] L0050
       CALL            R0462 (#9d) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       JE              Gb0,#07 [FALSE] L0029
       PRINT_RET       ""A fascinating story, Inspector. A man is found dead
behind a locked door, a clear suicide. Yet the detective seems bent on proving
that a murder has occured. Rather odd, wouldn't you say?""
L0029: JE              Gb0,#01 [FALSE] L0030
       PRINT_RET       ""A marvelous concert! There were works by Beethoven,
Sibelius, and Ravel. I never would've guessed you were interested in serious
music, Inspector.""
L0030: JE              Gb0,#05 [FALSE] L0034
       JZ              G25 [TRUE] L0031
       PRINT_RET       ""My dear Inspector, it is just as Ms. Dunbar told
you.""
L0031: STORE           G26,#01
       JIN             "Ms. Dunbar",G00 [FALSE] L0032
       STORE           G24,#01
L0032: JZ              G27 [TRUE] L0033
       STORE           G15,#01
L0033: PRINT_RET       ""Ah, that must be Ms. Dunbar's ticket stub. I should
have told you earlier. Ms. Dunbar was with me at the concert on the night that
Marshall killed himself. She became ill at intermission and hired a car to take
her back home. You see, Inspector, I know that Ms. Dunbar appreciates classical
music, so I occasionally ask her along to my subscription series. I really
should have told the other detective, but I didn't think it mattered.""
L0034: JE              Gb0,#79 [FALSE] L0035
       PRINT_RET       ""What ladder? You know, Inspector, your questions are
becoming quite tiresome.""
L0035: JE              Gb0,#38,#87 [FALSE] L0036
       PRINT_RET       ""I didn't realize you had an interest in finance.
Before Marshall died, we agreed that the only reasonable way to protect our
interests was to be bought out by a larger company which could then provide us
with capital for expansion. I had been talking to people at Omnidyne and we
agreed in principle on the terms for such an agreement last week. I'm hopeful
that we can close the deal quickly.""
L0036: JE              Gb0,#82 [FALSE] L0039
       JG              G70,#00 [FALSE] L0038
       PRINT           ""It's fortunate for George that Marshall died when he
did. It must be quite a relief to know that he'll have plenty of money." He
chuckles softly."
       JZ              G41 [TRUE] L0037
       PRINT           " "I guess that explains his reaction at the reading.""
L0037: NEW_LINE        
       RTRUE           
L0038: PRINT_RET       ""I don't know much about the family's affairs. Marshall
threatened to make a new will, but it certainly appears that he never did.""
L0039: JE              Gb0,#80 [FALSE] L0042
       JZ              G5b [TRUE] L0040
       PRINT_RET       ""I told you already. There was no legal wrongdoing,
only some reporters trying to stir up a fuss." He appears quite nervous."
L0040: JZ              G5c [TRUE] L0041
       PRINT_RET       ""I understand the note no more than you do." He turns
away."
L0041: PRINT_RET       "There is a flicker of surprise on Baxter's face. "I'm
not sure what you mean. Focus Corporation has been a subsidiary of Robner Corp.
for some years. I fail to see its import.""
L0042: JE              Gb0,#99,#98 [FALSE] L0043
       CALL            R0353 (#9d,#99) -> -(SP)
       PRINT_RET       ""I've known the boy for some time, and believe me, he's
no good. He's wasted more money this year than you've probably earned. His
father reprimanded him frequently, as you know. George even threatened his
father from time to time.""
L0043: JE              Gb0,#50,#9b,#9a [FALSE] L0044
       PRINT_RET       ""Ms. Dunbar is an efficient and tireless worker. She
has been of tremendous help to Marshall and has been working quite hard for him
lately. She had a great deal of respect for him, that's clear. She has a keen
mind and is an exceptional strategic planner for the corporation.""
L0044: JE              Gb0,#97,#96 [FALSE] L0045
       PRINT_RET       ""Leslie is a fine woman from a distinguished family.
She was much more outgoing than Marshall, but she seems to have become
accustomed to the quiet life here. I am quite grieved for her.""
L0045: JE              Gb0,#95,#94 [TRUE] L0046
       JE              Gb0,#9f,#9e [FALSE] L0047
L0046: PRINT           ""I don't know much about "
       PRINT_OBJ       Gb0
       PRINT_RET       ""."
L0047: JE              Gb0,#83 [FALSE] L0048
       PRINT_RET       ""I really don't know anything about the old will.""
L0048: JE              Gb0,#7f [FALSE] L0049
       PRINT_RET       ""Marshall was a truly great man...a brilliant manager;
he started the corporation single-handedly about 25 years ago and is mostly
responsible for its reputation. I owe him a great deal. He was also a great
philanthropist and got the corporation involved in many charitable works. I am
not given to shows of emotion, Inspector, but I will miss him greatly.""
L0049: PRINT_RET       ""I can't help you there.""
L0050: JE              Gb1,#69,#24 [FALSE] RFALSE
       CALL            R0462 (#9d) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       JE              Gb0,#55 [FALSE] L0051
       PRINT_RET       "Baxter studies the report carefully. "This is quite
peculiar. It appears that Marshall was murdered. I wonder...I would have a word
with George if I were you, Inspector.""
L0051: JE              Gb0,#05 [FALSE] L0052
       CALL            R0010 (#15,#9d,#05) -> -(SP)
       RTRUE           
L0052: JE              Gb0,#92 [FALSE] L0053
       JZ              G5d [TRUE] L0053
       JZ              G5c [FALSE] L0053
       STORE           G5c,#01
       PRINT_RET       "He reads it carefully against the light, then speaks:
"I really don't know what to make of this. Marshall seems to be insisting that
I do something. I'm afraid we will never know, since I never got the note.""
L0053: JE              Gb0,#90 [FALSE] L0054
       JZ              G5b [FALSE] L0054
       STORE           G5b,#01
       PRINT           "He reads slowly and leafs through the pages. "I'm
afraid I haven't been entirely candid with you. There was some trouble a few
years ago with Focus Corp. because of some, let us say, irresponsible dealings
on my part. Marshall agreed to cover up my involvement to save the company any
bad publicity.""
       NEW_LINE        
       JZ              G5c [TRUE] RTRUE
       PRINT_RET       ""I can't understand why he would be insisting that I do
this or that, though, as it says on that note you showed me. He must have
changed his mind, since I never received the note.""
L0054: JE              Gb0,#8a [FALSE] L0055
       PRINT_RET       ""Very interesting, Inspector, but I assure you that
this fellow is quite off base about the business. Marshall and I were in
complete agreement when it came to those matters. I can't imagine where he got
that idea.""
L0055: PRINT           ""I can't understand why you are showing this to me.
Have you nothing better to do than "
       CALL            R0002 (G5f) -> -(SP)
       PRINT_PADDR     (SP)+
       PRINT_RET       "?""

Routine R0286, 2 locals (0000, 0001)

       PRINT           "Sergeant Duffy dutifully appears and escorts "
       PRINT_OBJ       L00
       PRINT           " from the grounds.

"
       CALL            R0424 (S153) -> -(SP)
       PRINT           "I am sorry to inform you that the District Attorney's
office has declined to seek an indictment against "
       PRINT_OBJ       L00
       PRINT           " in the case of the death of Mr. Robner, against your
recommendation. It is still not clear that Mr. Robner was murdered, although,
as you point out, there are a number of suspicious characters in the Robner
household."
       JZ              L01 [FALSE] L0001
       PRINT           "  Additionally, Mr. Baxter seems to have had no clear
motive for killing Mr. Robner."
L0001: NEW_LINE        
       JE              L00,#9d [FALSE] L0002
       PRINT           "Mr. Baxter has threatened to sue the department for
malicious arrest, but we feel that he will prefer to avoid the publicity."
       NEW_LINE        
L0002: PRINT           "     Please be more careful in the future!

"
       CALL            R0431 -> -(SP)
       RET_POPPED      

Routine R0287, 1 local (0000)

       JE              Gb1,#15 [FALSE] L0001
       TEST_ATTR       Gaf,#14 [FALSE] L0001
       JIN             Gaf,#ff [FALSE] RFALSE
L0001: JE              Gb1,#1c,#1d,#35 [TRUE] RFALSE
       JE              Gb1,#7f,#32,#87 [TRUE] RFALSE
       JE              Gb1,#17 [FALSE] L0002
       PRINT           "It's not clear to whom you are referring."
       NEW_LINE        
       STORE           Ga5,#00
       RTRUE           
L0002: TEST_ATTR       Gaf,#14 [FALSE] L0003
       PRINT_OBJ       Gaf
       JUMP            L0004
L0003: PRINT_OBJ       Gb0
L0004: JE              Gb1,#17,#15 [FALSE] L0005
       GET_PROP        Gaf,#07 -> -(SP)
       LOADW           G06,(SP)+ -> -(SP)
       GET_PARENT      (SP)+ -> -(SP)
       GET_PROP        (SP)+,#0c -> L00
       GET_PROP        G00,#0c -> -(SP)
       AND             L00,(SP)+ -> -(SP)
       JZ              (SP)+ [TRUE] L0005
       PRINT           " can't hear you."
       NEW_LINE        
       JUMP            L0007
L0005: JE              Gaf,#96 [FALSE] L0006
       JE              G00,#b0 [FALSE] L0006
       JIN             "Mrs. Robner","Master Bedroom" [FALSE] L0006
       PRINT           " can't hear you."
       NEW_LINE        
       JUMP            L0007
L0006: PRINT           " isn't here!"
       NEW_LINE        
L0007: STORE           Ga5,#00
       RTRUE           

Routine R0288, 1 local (0000)

       JE              L00,#05 [FALSE] L0009
       CALL            R0317 (#99) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       JIN             "George","Kitchen" [FALSE] L0001
       PRINT           "George is here, preparing a snack."
       NEW_LINE        
       JUMP            L0008
L0001: JIN             "George","Dining Room" [FALSE] L0002
       PRINT           "George is sitting at the table, eating some red
herrings."
       NEW_LINE        
       JUMP            L0008
L0002: JIN             "George","Living Room" [FALSE] L0004
       JZ              G4f [TRUE] L0003
       PRINT           "George is staring contentedly out the bay window."
       NEW_LINE        
       JUMP            L0008
L0003: PRINT           "George is here, pacing around the room."
       NEW_LINE        
       JUMP            L0008
L0004: JIN             "George","North Lawn" [FALSE] L0005
       PRINT           "George is here, staring out over the lake."
       NEW_LINE        
       JUMP            L0008
L0005: JIN             "George","George's Bedroom" [FALSE] L0007
       JZ              G4d [FALSE] L0007
       JZ              G12 [TRUE] L0006
       PRINT           "George is lying on his bed, listening intently to a "
       PRINT_PADDR     G12
       PRINT           "."
       NEW_LINE        
       JUMP            L0008
L0006: PRINT           "George is sitting on his bed, deep in thought."
       NEW_LINE        
       JUMP            L0008
L0007: PRINT           "George is here."
       NEW_LINE        
L0008: CALL            R0354 (#99) -> -(SP)
       RET_POPPED      
L0009: JE              Gb1,#38,#39 [FALSE] L0010
       PRINT_RET       "George looks up and grunts disinterestedly."
L0010: JE              Ga8,#99 [FALSE] L0011
       JE              Gb1,#32 [TRUE] RFALSE
       CALL            R0397 (#99) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       CALL            R0002 (G61) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0011: JE              Gb1,#1d [FALSE] L0012
       JG              G48,#00 [FALSE] L0012
       PRINT_RET       ""Don't bother me!" he shouts, and continues on."
L0012: JE              Gb1,#53,#50 [FALSE] L0014
       LOADW           G08,#04 -> -(SP)
       LOADW           (SP)+,#01 -> -(SP)
       JE              (SP)+,#de [FALSE] L0013
       PRINT_RET       "George points accusingly at you. "Don't come near me!
I'm getting sick and tired of your accusing tone. Get lost!""
L0013: PRINT_RET       ""Buzz off! Don't come back until you get a search
warrant!" He chuckles in contempt."
L0014: JE              Gb1,#0e [FALSE] L0015
       PRINT_RET       "George sneers at you. "What an ass! Go on, try to prove
it!""
L0015: JE              Gb1,#14 [FALSE] L0017
       JZ              G45 [FALSE] L0016
       JZ              G48 [TRUE] RFALSE
L0016: PRINT           "Faithful Sergeant Duffy enters and handcuffs George,
who spits at you. "You filthy, stinking..." is all you hear as George is carted
off struggling.

"
       CALL            R0424 (S156) -> -(SP)
       PRINT           "I am sorry to inform you that George Robner was
acquitted in the death of his father today. It seems the evidence, consisting
mainly of a new will which George admitted under pressure that he was trying to
destroy, was insufficient for the jury to return a guilty verdict. Although I
suspect that George may have committed the crime, his arrest was a bit
premature.

"
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0017: JE              Gb1,#69,#24 [FALSE] L0022
       CALL            R0462 (#99) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       JE              Gb0,#55 [FALSE] L0018
       PRINT_RET       "George scans the report. "Killed, eh? I wonder who
might have wanted..." He cocks his head in thought. "I'm sorry, Inspector, I
really should act a bit better with you. I thought you were just snooping
about, digging up dirt about the family. I'm not sure...I can't believe Mom
would have anything to do with it, although...Baxter, now there's a worm for
you. He'd do anything, maybe even murder, to get ahead. I just don't know.""
L0018: JE              Gb0,#8a [FALSE] L0019
       PRINT           "George reads the letter quickly. "Pompous ass! What
does he know about it?" He pauses. "I thought Mom was having an affair. How
nice for the lovebirds that Dad is dead! They can finish their honeymoon plans
without worrying. It's perfect!" With a bitter laugh, he throws the letter to
the ground."
       NEW_LINE        
       STORE           G56,#01
       INSERT_OBJ      "letter",G00
       RTRUE           
L0019: JE              Gb0,#91 [FALSE] L0021
       JE              G55,#08 [FALSE] L0021
       JZ              G4e [FALSE] L0021
       STORE           G5a,#01
       JG              G70,#00 [FALSE] L0020
       PRINT           ""I...uh...I don't really know what to say. I guess that
Dad...but there is no other...I can't help you...sorry." George seems to be
quite agitated."
       NEW_LINE        
       CALL            R0301 -> -(SP)
       RET_POPPED      
L0020: PRINT_RET       "George tilts his head in thought (or perhaps surprise)
but recovers quickly. "All I know is that Coates is my father's personal
attorney.""
L0021: JE              Gb0,#8d [FALSE] RFALSE
       JZ              G53 [TRUE] RFALSE
       CALL            R0353 (#99,#9d) -> -(SP)
       PRINT_RET       ""So Baxter's arranged the merger. I'll be damned.
That's strange, since Dad was opposed to the whole thing. He's worried about
losing control of the company ever since he had to sell off most of his
interest. I bet he doesn't even own enough shares to prevent the deal." He
shakes his head in disbelief."
L0022: JE              Gb1,#15 [FALSE] RFALSE
       JE              Gaf,#99 [FALSE] RFALSE
       CALL            R0462 (#99) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       JE              Gb0,#24 [FALSE] L0025
       JZ              G46 [FALSE] L0023
       JZ              G45 [TRUE] L0024
L0023: PRINT_RET       ""What of it? Dad's safe is there. I don't think anyone
knows about it except Dad and me.""
L0024: PRINT_RET       ""Hidden closet, you say? Hmm. I think I'd know if there
was one, but there isn't!""
L0025: JE              Gb0,#38 [FALSE] L0026
       PRINT_RET       ""I've heard talk of a merger between Dad's company and
another one, but I don't think it's happened yet. Dad would be furious if it
did, though. I can tell you that!""
L0026: JE              Gb0,#44 [FALSE] L0028
       JZ              G56 [TRUE] L0027
       PRINT_RET       ""He's a little worm who's been coming by lately. He's
one of those fancy ski-instructor types, if you know what I mean. From what
I've seen, it wouldn't surprise me if he and Mom are having an affair.""
L0027: CALL            R0353 (#99,#97) -> -(SP)
       PRINT_RET       ""Steven? Oh, you must mean the guy who comes around for
Mom now and then. I don't know much about him. Dresses a bit above himself,
I'll say that much.""
L0028: JE              Gb0,#9d,#9c [FALSE] L0029
       PRINT_RET       ""I don't know much about him, really. With Baxter, it's
always business, and he's not here much except to discuss business with Dad.
You might ask Ms. Dunbar about him, though. She handled lots of Dad's business
matters herself, so they work together a lot. They probably know each other
pretty well.""
L0029: JE              Gb0,#50,#9b,#9a [FALSE] L0030
       PRINT_RET       ""She's been here for about ten years, I guess. She
knows a lot about Dad's business, and he lets her take care of a lot of stuff
by herself. Other than that, I can't say. We don't get in each other's way. I
think she's heard Dad lecture me too often.""
L0030: JE              Gb0,#97,#96 [FALSE] L0031
       PRINT_RET       ""She's OK. Not as stuck up as Dad about money. We've
always gotten along pretty well. I think she understands me better than Dad
ever did.""
L0031: JE              Gb0,#43 [FALSE] L0035
       JZ              G45 [TRUE] L0032
       PRINT_RET       ""Let's not go into it, ok? You caught me looking for
the will. Well, what of it? I didn't kill Dad, if that's what you're thinking.
Leave me alone!""
L0032: JZ              G46 [TRUE] L0033
       PRINT_RET       ""You mean my father's safe? Yeah, if he brings
important papers home he puts them in there. He keeps most important stuff at
the office at the bank. You really startled me in there. I thought I might be
able to get it open. Dad always acted like it was a big secret, something out
of a spy story. Anyway, it turns out I don't remember the combination. It was a
long time ago.""
L0033: JZ              G4e [TRUE] L0034
       PRINT_RET       "George turns toward you with rage in his eyes. "I don't
know anything about any damn safe! Now leave me alone or I'll have you kicked
out of here!" He turns away."
L0034: PRINT_RET       "George looks briefly toward the ceiling, as if
recalling something. "Oh, I'm sorry. A safe? No, I don't know about any
safe...except at the office, that is. I think there's one there.""
L0035: JE              Gb0,#9f,#9e [FALSE] L0036
       PRINT_RET       ""McNabb, that old bore? Always talking about the damn
roses and weeds. Don't ask him about them, unless you have all day.""
L0036: JE              Gb0,#95,#94 [FALSE] L0037
       CALL            R0353 (#99,#95) -> -(SP)
       PRINT_RET       ""She's nice but awfully nosy. She acts like she knows
everything that goes on around here, but she doesn't know the half of it.""
L0037: JE              Gb0,#83 [FALSE] L0038
       PRINT_RET       ""I know what you know.""
L0038: JE              Gb0,#8e,#82 [FALSE] L0046
       JG              G76,G70 [FALSE] L0044
       TEST_ATTR       "new will",#1e [FALSE] L0039
       PRINT_RET       ""You should know what it says.""
L0039: JZ              G45 [TRUE] L0040
       PRINT_RET       ""I don't know what you're talking about. There's no new
will. Dad never wrote one! He would just threaten me when I asked for spending
money.""
L0040: JZ              G4e [TRUE] L0041
       PRINT_RET       ""Look. I know the same as you. There's no new will. I'm
sure of it. Dad would have rubbed my nose in it: you can be sure of that!""
L0041: JZ              G41 [TRUE] L0042
       PRINT_RET       ""You were there when I was. Coates says there's no new
will.""
L0042: JZ              G70 [FALSE] L0043
       PRINT_RET       ""Dad always threatened to write a new will, but I guess
he ran out of time." He chuckles disturbingly."
L0043: PRINT_RET       ""Oh, yeah. You skipped out on the will reading. Anyhow,
Coates says there's no new will, and he should know, right?""
L0044: JZ              G5a [TRUE] L0045
       PRINT_RET       ""I know what you're getting at...the desk calendar.
Look, I've heard nothing about a new will. Maybe the old man just wanted to
change something.""
L0045: PRINT_RET       ""I don't know anything about any new will.""
L0046: JE              Gb0,#7f [FALSE] L0047
       PRINT_RET       ""Like I told your detective friend yesterday, we didn't
get along too well. He was always riding me, giving me a hard time." George
gets worked up talking about it."Look, man. I'm not going to lie and say I
loved him, right? He got what..." He stops in mid-sentence."
L0047: JE              Gb0,#80 [FALSE] L0048
       PRINT_RET       ""Focus...Focus...That name rings a bell. Something
about the company, quite a while ago...what was it? I can't remember now. I
don't pay much attention to business stuff: I've got better things to do.""
L0048: PRINT_RET       ""I haven't a clue.""

Routine R0289, 2 locals (0000, 0000)

       JE              Gb1,#2f,#4e [FALSE] L0003
       JE              Gb0,#52 [FALSE] L0003
       JZ              G98 [TRUE] L0001
       JG              G98,#1e [FALSE] L0002
L0001: PRINT           "Why?  Is it your birthday?"
       NEW_LINE        
       JUMP            L0003
L0002: PRINT           "You flip the pages until you find the page."
       NEW_LINE        
       STORE           G55,G98
L0003: JE              Gb1,#23 [FALSE] L0004
       PRINT           "It's not worth the effort."
       NEW_LINE        
       JUMP            L0006
L0004: JE              Gb1,#78 [FALSE] L0006
       JZ              Gb0 [FALSE] L0006
       JE              G55,#1f [FALSE] L0005
       PRINT_RET       "You have reached the end of the book."
L0005: INC             G55
       STORE           Gb1,#4e
L0006: STORE           L01,G55
       JE              L00,#05 [FALSE] L0007
       PRINT           "A desk calendar is here, open to July "
       PRINT_NUM       G55
       PRINT_RET       "."
L0007: JE              Gb1,#2f,#4e [FALSE] L0010
       PRINT           "It is open to July "
       PRINT_NUM       G55
       PRINT           "."
       NEW_LINE        
       JE              L01,#08 [FALSE] L0008
       PRINT_RET       "There is only one notation here, in the 9AM spot: "Call
Coates: Will completed"."
L0008: JE              L01,#07 [FALSE] L0009
       PRINT_RET       "The only listing here is an appointment with Baxter at
2PM at the Robner Corp. office."
L0009: PRINT_RET       "Nothing of interest is scheduled on this date."
L0010: JE              Gb1,#78 [FALSE] RFALSE
       JE              Gb0,#52 [TRUE] L0011
       PRINT_RET       "Huh?"
L0011: JG              G98,#1e [FALSE] L0012
       PRINT           "Thirty days hath September,
April, June, and November,
All the rest have "
       PRINT_NUM       G98
       PRINT_RET       "???"
L0012: JZ              G98 [FALSE] L0013
       PRINT_RET       "Do you suppose that would be June 30?"
L0013: STORE           G55,G98
       PRINT           "The calendar is now open to July "
       PRINT_NUM       G98
       PRINT_RET       "."

Routine R0290, 0 locals ()

       JE              Gb1,#2f,#4e [FALSE] L0003
       JZ              G5d [TRUE] L0001
       CALL            R0291 (S161) -> -(SP)
       RET_POPPED      
L0001: JE              G54,"carefu" [FALSE] L0002
       PRINT_RET       "There are some indentations on the paper. Something may
have been written on the previous sheet."
L0002: PRINT_RET       "There doesn't seem to be anything written on the pad."
L0003: JE              Gb1,#62 [FALSE] L0005
       JZ              Gb0 [FALSE] L0004
       PRINT_RET       "You should try rubbing or shading the pad with
something."
L0004: JE              Gb0,#0a [FALSE] RFALSE
       CALL            R0291 (S162) -> -(SP)
       RET_POPPED      
L0005: JE              Gb1,#84 [FALSE] L0006
       JE              Gaf,#0a [FALSE] L0006
       CALL            R0291 (S163) -> -(SP)
       RET_POPPED      
L0006: JE              Gb1,#70 [FALSE] RFALSE
       JE              Gb0,#84 [FALSE] RFALSE
       CALL            R0291 (S164) -> -(SP)
       RET_POPPED      

Routine R0291, 1 local (0000)

       STORE           G5d,#01
       PRINT_PADDR     L00
       PRINT_RET       " reveals impressions left by writing on the previous
sheet. The writer must borne down heavily, but only a few words come out
clearly:

  Baxter,

                  st time
 nsist             op       merg
       mnidy               Oth
          forc
         ocumen     y poss
  plica     y      Focus s
          recons
late!
                              rsha
"

Routine R0292, 0 locals ()

       STORE           G53,#01
       PRINT_RET       "In your study of the second section, a small item in
the financial section catches your eye. A merger between Robner Corp. and
Omnidyne is set to be concluded shortly. There is a picture of Mr. Baxter with
Omnidyne president Starkwell, both smiling broadly. Baxter is quoted as saying
that the deal will enable the financially ailing Robner Corp. to continue to
produce the highest-quality products. The article points out that Marshall
Robner, who founded Robner Corp. but is no longer its major stockholder, had
been found dead yesterday morning, an apparent suicide victim. Baxter is quoted
as saying that Robner was in full agreement with the terms of the merger."

Routine R0293, 0 locals ()

       JE              Gb1,#59,#4e,#2f [FALSE] RFALSE
       JE              G54,"carefu","slowly" [FALSE] L0001
       CALL            R0292 -> -(SP)
       RET_POPPED      
L0001: PRINT_RET       "The Daily Herald is a local paper in two sections. In
your cursory look at the first, you find a brief obituary for Mr. Robner. It
details his career, including the formation of Robner Corp. A few years ago,
Mr. Robner and the Robner Corp. were given a prestigious award for works in the
community. At that time Robner said "I am proud to accept this award for the
Corporation. Robner Corp is my whole life, and I will continue to guide it for
the public interest as long as I live." Robner himself had won great public
acclaim for his charitable works."

Routine R0294, 0 locals ()

       JE              Gb1,#5b [FALSE] L0002
       JIN             "Daily Herald",Ga8 [FALSE] L0001
       PRINT_RET       "You already have the whole newspaper."
L0001: CALL            R0010 (#5b,#8d) -> -(SP)
       RTRUE           
L0002: JIN             "Daily Herald",Ga8 [TRUE] L0003
       PRINT_RET       "You don't have the newspaper."
L0003: JE              Gb1,#4e,#2f [FALSE] L0004
       CALL            R0292 -> -(SP)
       RTRUE           
L0004: JE              Gb1,#2a [FALSE] RFALSE
       PRINT_RET       "You shouldn't leave pieces of the paper lying around.
At least leave the whole thing."

Routine R0295, 0 locals ()

       JE              G00,#f6 [TRUE] L0001
       JE              G00,#dd [FALSE] L0002
       TEST_ATTR       "front door",#1c [FALSE] L0002
L0001: PRINT           "A mailman walks briskly up to you, hands you an
envelope, and departs."
       NEW_LINE        
       INSERT_OBJ      "handwritten envelope",Ga8
       SET_ATTR        "handwritten envelope",#1e
       RTRUE           
L0002: JE              G00,#dd [FALSE] L0003
       PRINT           "There is a short rap on the front door. A moment later,
a thin envelope appears under the door."
       NEW_LINE        
       INSERT_OBJ      "handwritten envelope","Foyer"
       PUT_PROP        "handwritten envelope",#09,S165
       CALL            R0004 (#730e,#3c) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           
L0003: INSERT_OBJ      "handwritten envelope","marble-top table"
       CALL            R0004 (#730e,#3c) -> -(SP)
       STOREW          (SP)+,#00,#01
       JE              G00,#f9,#f4,#f2 [FALSE] RFALSE
       PRINT_RET       "You notice a mailman stop by the house briefly and
depart."

Routine R0296, 0 locals ()

       GET_PARENT      "handwritten envelope" -> -(SP)
       JE              (SP)+,#dd,#81 [FALSE] RFALSE
       CALL            R0442 (#95,#dd,#01) -> -(SP)
       CALL            R0004 (#731f,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          

Routine R0297, 0 locals ()

       JZ              G52 [TRUE] L0006
       GET_PARENT      "Mrs. Robner" -> -(SP)
       JIN             "Mrs. Rourke",(SP)+ [FALSE] RFALSE
       CALL            R0004 (#731f,#00) -> -(SP)
       CALL            R0442 (#95,#d6,#01) -> -(SP)
       JIN             "handwritten envelope",Ga8 [FALSE] L0001
       GET_PARENT      "Mrs. Robner" -> -(SP)
       JIN             Ga8,(SP)+ [FALSE] L0001
       PRINT           "Mrs. Rourke walks up to Mrs. Robner. "I'm sorry, Ma'am,
but this gentleman has a letter that just arrived for you." Mrs. Robner grabs
the letter from you. "That is none of your business!""
       NEW_LINE        
       JUMP            L0002
L0001: JIN             "handwritten envelope","Mrs. Rourke" [FALSE] RTRUE
L0002: GET_PARENT      "Mrs. Rourke" -> -(SP)
       JE              G00,(SP)+ [FALSE] L0005
       JIN             "handwritten envelope","Mrs. Rourke" [FALSE] L0003
       PRINT           "Mrs. Rourke hands an envelope to Mrs. Robner."
L0003: INSERT_OBJ      "handwritten envelope","Mrs. Robner"
       JZ              G3a [TRUE] L0004
       PRINT_RET       " Mrs. Robner examines the envelope, then turns to you.
"You did this, I suppose." she says. "You had no right! I expected better
treatment than this. You would think I were suspected of wrongdoing!""
L0004: PRINT           " Mrs. Robner examines the envelope briefly, then puts
it in her pocket."
       NEW_LINE        
       REMOVE_OBJ      "handwritten envelope"
       RTRUE           
L0005: REMOVE_OBJ      "handwritten envelope"
       RFALSE          
L0006: JIN             "Mrs. Rourke","Foyer" [FALSE] RFALSE
       GET_PARENT      "handwritten envelope" -> -(SP)
       JE              (SP)+,#81,#dd [FALSE] L0007
       INSERT_OBJ      "handwritten envelope","Mrs. Rourke"
       SET_ATTR        "handwritten envelope",#1e
       GET_PARENT      "Mrs. Robner" -> -(SP)
       CALL            R0442 (#95,(SP)+,#01) -> -(SP)
       STORE           G52,#01
       JE              G00,#dd [FALSE] RFALSE
       PRINT_RET       "Mrs. Rourke takes the envelope and starts to walk
away."
L0007: CALL            R0441 (#95) -> -(SP)
       RFALSE          

Routine R0298, 0 locals ()

       INSERT_OBJ      "Daily Herald","Front Path"
       JE              G00,#f9,#f6 [FALSE] RFALSE
       PRINT_RET       "The local paperboy, in an amazing athletic feat, throws
a newspaper toward the house from a distance of at least 100 feet. It even
lands beside the front door, rather than in the bushes."

Routine R0299, 0 locals ()

       JL              G76,#02f8 [FALSE] L0003
       JIN             "Mrs. Robner","Living Room" [FALSE] L0001
       JIN             "Ms. Dunbar","Living Room" [FALSE] L0001
       JIN             "Mr. Baxter","Living Room" [FALSE] L0001
       JIN             "George","Living Room" [TRUE] L0003
L0001: STORE           G50,#01
       CALL            R0004 (#743a,#ffff) -> -(SP)
       JE              G00,#ca [FALSE] RFALSE
       RANDOM          #64 -> -(SP)
       JG              #46,(SP)+ [TRUE] RFALSE
       RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0002
       PRINT_RET       "Mr. Coates asks everyone to be patient, as not everyone
is present."
L0002: PRINT_RET       "Mr. Coates appears distracted, looking frequently
toward the door."
L0003: JE              G00,#ca [TRUE] L0005
       INC_CHK         G51,#0f [FALSE] L0004
       CALL            R0004 (#b3fb,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0300 -> -(SP)
       RFALSE          
L0004: CALL            R0004 (#743a,#ffff) -> -(SP)
       RFALSE          
L0005: JE              G00,#ca [FALSE] L0012
       STORE           G41,#01
       JG              G76,#02d0 [FALSE] L0006
       JG              G51,#03 [FALSE] L0006
       PRINT           "The people present turn to look at you. Mrs. Robner
glares at you. "You might at least have the courtesy to be here on time!
Haven't you caused enough disruption already? We should have started without
you. Mr. Coates, please proceed.""
       NEW_LINE        
       JUMP            L0008
L0006: JG              G76,#02f8 [FALSE] L0007
       PRINT           ""It's late, so let's begin!" Coates says."
       NEW_LINE        
       JUMP            L0008
L0007: JZ              G50 [TRUE] L0008
       PRINT           ""Ah!" Mr. Coates says, "Everybody's here now.""
       NEW_LINE        
L0008: PRINT           "Mr. Coates begins: "This is an awkward situation. Mr.
Robner told me five days ago that he wanted to execute a new will, and promised
to call me when it was completed. As I never heard from him, I must assume that
he either changed his mind or did not complete the new will. Therefore, the one
in my possession must be considered the most recent testament.""
       NEW_LINE        
       JZ              G5a [TRUE] L0009
       PRINT           "You notice that George, who was not initially paying
close attention, now perks up and begins to look about anxiously."
       NEW_LINE        
       JUMP            L0010
L0009: PRINT           "From the corner of your eye, you catch George nodding
his head, as if in approval, and smiling broadly."
       NEW_LINE        
L0010: PRINT           "Continuing, Mr. Coates says: "Naturally, should a more
recent will exist and be found within a reasonable period, the present one will
be voided. I will proceed with reading the will here in my hands, which was
executed three years ago last month." He reads the will, simply written and
direct, leaving equal parts of the estate to his son, George Arthur Robner, and
his wife, Mrs. Leslie Phillips Robner."
       NEW_LINE        
       PRINT           "There is some discussion, understated congratulations
and overstated sympathy, which Mr. Coates cuts short by clearing his throat. "I
must leave now, I'm afraid. If you have any questions, I can be contacted
tomorrow." He picks up the phone, dials his office, and asks to be picked up at
the Robner estate."
       NEW_LINE        
       JZ              G5a [TRUE] L0011
       PRINT           "George, now looking quite upset, starts for the door."
       NEW_LINE        
L0011: CALL            R0300 -> -(SP)
       RTRUE           
L0012: CALL            R0300 -> -(SP)
       RFALSE          

Routine R0300, 0 locals ()

       CALL            R0442 (#36,#f9,#01) -> -(SP)
       STORE           G70,G76
       STORE           G4f,#01
       CALL            R0004 (#743a,#00) -> -(SP)
       JZ              G5a [TRUE] RFALSE
       CALL            R0301 -> -(SP)
       RET_POPPED      

Routine R0301, 1 local (0000)

       GET_PARENT      "George" -> L00
       JE              L00,G00 [FALSE] L0003
       JE              L00,#a4 [FALSE] L0001
       PRINT           "George paces around. "I just remembered," he says,
"I've got some personal business to attend to. Would you mind?" He shows you to
the door."
       NEW_LINE        
       JUMP            L0003
L0001: GET_PROP        L00,#0e -> -(SP)
       JE              (SP)+,#00 [FALSE] L0002
       PRINT           ""I'm...I really have some business to do in my room.
I'll speak to you later," George says. He starts off toward his room."
       NEW_LINE        
       JUMP            L0003
L0002: PRINT           ""I've...got to be going now. I'll see you later,"
George says. He starts to leave."
       NEW_LINE        
L0003: JE              L00,#a4 [TRUE] L0004
       CALL            R0442 (#99,#a4,#01) -> -(SP)
L0004: STORE           G4e,#01
       CALL            R0004 (#7737,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           

Routine R0302, 3 locals (0000, 0000, 0000)

       GET_PARENT      "George" -> L00
       GET_PROP        "George",#07 -> -(SP)
       LOADW           G08,(SP)+ -> L01
       JZ              G4c [TRUE] L0002
       JE              G00,L00 [FALSE] L0001
       STORE           G4c,#00
       STORE           G4b,#00
       STORE           G4d,#01
       PRINT           ""I don't understand you, Inspector. I asked to be alone
so I can take care of some business. I...I don't see why you have to snoop
around here like I was some sort of suspect.""
       NEW_LINE        
       JZ              G4b [TRUE] RTRUE
       PRINT_RET       ""I said to close that door and not to come in! You must
be deaf as well as stupid!""
L0001: TEST_ATTR       "bedroom door",#1c [FALSE] RFALSE
       JZ              G4b [FALSE] RFALSE
       PRINT           "As the door opens, you hear George say "Close that
door! I'm working!""
       NEW_LINE        
       STORE           G4b,#01
       RTRUE           
L0002: JZ              G4d [TRUE] L0005
       JE              G00,L00 [FALSE] L0004
       PRINT           "George paces around the room, awaiting your departure
with ill-concealed impatience."
       NEW_LINE        
       INC_CHK         G4d,#0c [FALSE] RTRUE
       PRINT           ""I can't take this. You get on my nerves. I'm
leaving.""
       NEW_LINE        
       LOADW           L01,#06 -> -(SP)
       JE              G00,(SP)+ [FALSE] L0003
       STOREW          L01,#06,#ca
L0003: CALL            R0441 (#99) -> -(SP)
       STORE           G4d,#00
       CALL            R0004 (#7737,#00) -> -(SP)
       CALL            R0004 (#76b2,#1e) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           
L0004: STORE           G4d,#00
       CLEAR_ATTR      "bedroom door",#1c
       JE              G00,#b9,#bb,#bd [FALSE] RFALSE
       PRINT_RET       "You hear George's door close."
L0005: JE              L00,#a4 [FALSE] L0008
       JE              G00,L00 [FALSE] L0006
       PRINT           ""I have business to attend to. Would you mind
leaving?""
       NEW_LINE        
       STORE           G4d,#01
       RTRUE           
L0006: CALL            R0004 (#789e,#05) -> -(SP)
       STOREW          (SP)+,#00,#01
       STORE           G4c,#01
       JE              G00,#bb,#bd [FALSE] L0007
       TEST_ATTR       "bedroom door",#1c [FALSE] L0007
       CLEAR_ATTR      "bedroom door",#1c
       STORE           L02,#01
       PRINT           "You hear George's door close."
       NEW_LINE        
L0007: CLEAR_ATTR      "bedroom door",#1c
       RET             L02
L0008: JE              G00,L00 [FALSE] L0011
       JZ              G4a [FALSE] L0009
       STORE           G4a,#01
       RFALSE          
L0009: RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0010
       PRINT_RET       ""Please stop following me around like this. Can I have
no privacy? I'm simply trying to take care of something personal.""
L0010: PRINT_RET       ""Stop following me. My business is private.""
L0011: JE              L00,#bb [FALSE] L0012
       GET_PROP        G00,#0c -> -(SP)
       AND             (SP)+,#01 -> -(SP)
       JE              (SP)+,#01 [FALSE] RFALSE
       PRINT           "George glances in your direction, then enters his
room."
       NEW_LINE        
       INSERT_OBJ      "George","George's Bedroom"
       RTRUE           
L0012: JE              L00,#bd,#be [FALSE] RFALSE
       JE              G00,#c1,#c2 [FALSE] RFALSE
       PRINT_RET       "George glances back at you briefly, then continues on
his way."

Routine R0303, 0 locals ()

       JZ              G4c [TRUE] L0009
       GET_PROP        G00,#0c -> -(SP)
       AND             (SP)+,#01 -> -(SP)
       JE              (SP)+,#01 [TRUE] L0001
       JE              G00,#b9 [FALSE] L0007
L0001: RANDOM          #09 -> -(SP)
       CALL            R0004 (#789e,(SP)+) -> -(SP)
       JE              G00,#be,#c1,#c2 [FALSE] L0003
       RANDOM          #64 -> -(SP)
       JG              #1e,(SP)+ [FALSE] L0002
       PRINT_RET       "A door opens down the hall. George steps out, spots
you, and looks briefly toward the window. After a moment he steps back into his
room and shuts the door."
L0002: PRINT_RET       "You faintly hear a door open and then close near the
end of the hall."
L0003: JE              G00,#bb,#b9 [FALSE] L0005
       PRINT           "You hear George's door open and "
       RANDOM          #64 -> -(SP)
       JG              #1e,(SP)+ [FALSE] L0004
       PRINT_RET       "you catch a brief glimpse of his head darting back into
the doorway. You watch as the door closes again."
L0004: PRINT_RET       "close again immediately."
L0005: TEST_ATTR       "bedroom door",#1c [FALSE] L0006
       CLEAR_ATTR      "bedroom door",#1c
       PRINT_RET       "George walks up to his door and slams it in your face."
L0006: JE              G00,#bd [FALSE] RFALSE
       PRINT_RET       "George opens his door and peeks out. He is startled by
your presence, excuses himself, and closes the door sharply in your face before
you can utter a word."
L0007: CALL            R0004 (#7737,#00) -> -(SP)
       INSERT_OBJ      "George","Library"
       SET_ATTR        "bedroom door",#1c
       CALL            R0004 (#789e,#00) -> -(SP)
       CALL            R0004 (#79c6,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       JE              G00,#b5 [FALSE] L0008
       PRINT_RET       "You hear George's door open and you see his head poke
out briefly, scanning the hallway. He apparently didn't see you, and darts
across the hall to the library."
L0008: JE              G00,#b6 [FALSE] RFALSE
       PRINT_RET       "You see George through the doorway, looking down the
hallway, then darting into the library."
L0009: RANDOM          #09 -> -(SP)
       CALL            R0004 (#789e,(SP)+) -> -(SP)
       RFALSE          

Routine R0304, 1 local (0000)

       JZ              G49 [FALSE] L0003
       JE              G00,#b6 [FALSE] L0001
       PRINT           "George walks purposefully toward the bookshelves. He
looks around, but you react before he can see you. When you peek out again,
George is fiddling with the shelves. His right arm reaches into the shelf and,
to your amazement, the unit of bookshelves on the left rotates away from the
wall, revealing a darkened room behind. George enters it, trembling with barely
controlled fear and excitement."
       NEW_LINE        
       STORE           L00,#01
       STORE           G47,#01
       STORE           G43,#01
       INSERT_OBJ      "George","Hidden Closet"
       JUMP            L0008
L0001: JE              G00,#b9 [FALSE] L0002
       PRINT           "George hears you walk through the balcony doors and
recoils in horror. He runs across the hall to his own bedroom, slamming his
door shut."
       NEW_LINE        
       STORE           L00,#01
       STORE           G4c,#00
       STORE           G4d,#00
       CLEAR_ATTR      "bedroom door",#1c
       INSERT_OBJ      "George","George's Bedroom"
       CALL            R0004 (#79c6,#00) -> -(SP)
       CALL            R0004 (#789e,#0a) -> -(SP)
       JUMP            L0008
L0002: INSERT_OBJ      "George","Hidden Closet"
       STORE           G47,#01
       JUMP            L0008
L0003: JE              G49,#01 [FALSE] L0004
       JE              G00,#b9,#b6 [FALSE] L0008
       PRINT           "A dim light in the hidden closet comes on. In the faint
light, you can see George motioning with his right hand. All at once, the shelf
swings shut!"
       NEW_LINE        
       STORE           L00,#01
       JUMP            L0008
L0004: JL              G49,#0a [FALSE] L0005
       TEST_ATTR       "hidden door",#1c [FALSE] L0008
       PRINT           "As the bookshelf swings open, you see George carefully
dialing a combination into a large wall safe. He turns in panic and, with an
exclamation, knocks you down and bolts out of the library."
       NEW_LINE        
       STORE           L00,#01
       STORE           G46,#01
       STORE           G49,#00
       CALL            R0004 (#79c6,#00) -> -(SP)
       INSERT_OBJ      "George","Hallway"
       CALL            R0442 (#99,#ee,#01) -> -(SP)
       JUMP            L0008
L0005: JL              G49,#10 [FALSE] L0006
       TEST_ATTR       "hidden door",#1c [FALSE] L0008
       SET_ATTR        "safe",#1c
       STORE           G46,#01
       PRINT           "As the shelf swings open, George spins to face you. His
expression, first seemingly wild with happiness, changes to one of panic and
horror. He jerks around, trying feebly to conceal a piece of paper in his
hands. He jumps toward you, then recoils in fear. Finally, sobbing, he crumples
to the floor, clutching the paper beneath him. A large combination safe,
imbedded in a wall, is lying open. You enter the hidden closet."
       NEW_LINE        
       STORE           L00,#01
       CALL            R0004 (#79c6,#00) -> -(SP)
       INSERT_OBJ      "new will","George"
       CALL            R0110 (#b4) -> -(SP)
       CALL            R0004 (#7c46,#0a) -> -(SP)
       STOREW          (SP)+,#00,#01
       STORE           G00,#b4
       STORE           G45,#01
       JUMP            L0008
L0006: JE              G49,#10 [FALSE] L0008
       CLEAR_ATTR      "safe",#1c
       JE              G00,#b9 [FALSE] L0007
       PRINT           "Suddenly, the bookshelves swing out, forming an opening
to a dark area behind. George starts to emerge but stops suddenly as he notices
you! With jack-rabbit reflexes, he darts back inside. Before you can act, the
shelves close again."
       NEW_LINE        
       STORE           L00,#01
       INSERT_OBJ      "George","North Lawn"
       INSERT_OBJ      "wet piece of paper","lake"
       REMOVE_OBJ      "new will"
       CALL            R0004 (#79c6,#00) -> -(SP)
       STORE           G48,G76
       JUMP            L0008
L0007: INSERT_OBJ      "George","Library"
       CALL            R0004 (#79c6,#00) -> -(SP)
       CALL            R0441 (#99) -> -(SP)
       CALL            R0442 (#99,#de,#01) -> -(SP)
       JE              G00,#b6 [FALSE] L0008
       PRINT           "Suddenly, the shelf swings out, and George emerges. He
walks over to a special place in the shelves and reaches behind some books. The
bookshelves silently assume their normal position."
       NEW_LINE        
       STORE           L00,#01
L0008: INC             G49
       RET             L00

Routine R0305, 0 locals ()

       JIN             "George","Hidden Closet" [FALSE] RFALSE
       CALL            R0442 (#99,#a4) -> -(SP)
       RFALSE          

Routine R0306, 1 local (0000)

       GET_PARENT      "Mrs. Robner" -> L00
       JZ              G44 [TRUE] L0003
       JE              L00,#ca [FALSE] L0002
       STORE           G44,#00
       JE              G00,#ca [FALSE] L0001
       PRINT           "Mrs. Robner picks up the phone. "Oh, hi. Look, I can't
talk now. I'll call you later, okay? Bye, then." She hangs up the phone."
       NEW_LINE        
       CALL            R0314 -> -(SP)
       RTRUE           
L0001: CALL            R0314 -> -(SP)
       RFALSE          
L0002: PRINT           "The phone rings again."
       NEW_LINE        
       CALL            R0163 (#c9,G00) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       CALL            R0307 (#c9) -> -(SP)
       RTRUE           
L0003: JZ              G3f [TRUE] L0006
       INC_CHK         G3f,#0f [FALSE] L0004
       STORE           G3f,#00
       CALL            R0004 (#7c4d,#00) -> -(SP)
       CALL            R0441 (#97) -> -(SP)
       RFALSE          
L0004: TEST_ATTR       "bedroom door",#1c [TRUE] L0005
       JE              G00,#b2 [FALSE] RFALSE
L0005: PRINT           "Mrs. Robner speaks quietly into the phone and hangs
up."
       NEW_LINE        
       STORE           G3f,#00
       CALL            R0004 (#7c4d,#00) -> -(SP)
       CALL            R0441 (#97) -> -(SP)
       RTRUE           
L0006: JZ              G3e [TRUE] L0010
       JE              G00,L00,#b0,#af [FALSE] L0009
       INC_CHK         G3e,#03 [TRUE] L0007
       PRINT_RET       "Mrs. Robner glares at you, holding the phone in one
hand. "Would you mind terribly?", she asks."
L0007: JZ              G3d [TRUE] L0008
       PRINT           ""I can't understand why you won't let me use the phone.
Can't I talk to my best friend? Hummph...I suppose it can wait, since you are
being so...uh...unhelpful." She puts down the receiver, rises from her bed, and
starts to leave."
       NEW_LINE        
       STORE           G3d,#00
       STORE           G3e,#00
       CALL            R0004 (#7c4d,#00) -> -(SP)
       CALL            R0441 (#97) -> -(SP)
       RET_POPPED      
L0008: PRINT           ""I give up. What IS your problem, anyway?," Mrs. Robner
asks, in a barely controllable rage. "I'll call you back," she says, and slams
down the receiver."
       NEW_LINE        
       STORE           G3d,#00
       CALL            R0004 (#7c4d,#00) -> -(SP)
       CALL            R0441 (#97) -> -(SP)
       RET_POPPED      
L0009: CALL            R0308 -> -(SP)
       RFALSE          
L0010: JZ              G3d [TRUE] L0013
       JE              L00,#b2 [FALSE] RFALSE
       JE              G00,#af,#b0,#b2 [FALSE] L0012
       JE              G00,#b2 [TRUE] L0011
       PRINT           "Mrs. Robner enters her bedroom and spots you."
       NEW_LINE        
L0011: PRINT           ""I'd like to make a private phone call, if you have no
objection," she says. She motions toward the door."
       NEW_LINE        
       STORE           G3e,#01
       RTRUE           
L0012: CALL            R0308 -> -(SP)
       RFALSE          
L0013: JE              G00,#b9,#ca,#b2 [FALSE] L0014
       PRINT           "The telephone rings."
       NEW_LINE        
       CALL            R0307 (#c9) -> -(SP)
       CALL            R0442 (#97,#ca,#01) -> -(SP)
       STORE           G44,#01
       CALL            R0004 (#7c4d,#ffff) -> -(SP)
       RET_POPPED      
L0014: JE              G00,L00 [FALSE] L0015
       PRINT           "You can hear a telephone ringing in a nearby room. Mrs.
Robner says "Pardon me" and starts for the door."
       NEW_LINE        
       STORE           G44,#01
       CALL            R0004 (#7c4d,#ffff) -> -(SP)
       CALL            R0442 (#97,#ca,#01) -> -(SP)
       RET_POPPED      
L0015: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [TRUE] L0016
       PRINT           "You hear a phone ringing in a nearby room."
       NEW_LINE        
       STORE           G44,#01
       CALL            R0004 (#7c4d,#ffff) -> -(SP)
       CALL            R0442 (#97,#ca,#01) -> -(SP)
       RET_POPPED      
L0016: RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] RFALSE
       PRINT           "You notice a very faint ringing sound coming from the
house."
       NEW_LINE        
       CALL            R0314 -> -(SP)
       RTRUE           

Routine R0307, 1 local (0000)

       STORE           Ga4,L00
       STORE           Ga3,G00
       RTRUE           

Routine R0308, 1 local (0000)

       STORE           G3d,#00
       STORE           G3f,#01
       CLEAR_ATTR      "bedroom door",#1c
       JE              G00,#c1 [FALSE] L0001
       PRINT_RET       "Mrs. Robner shuts the door to the master bedroom."
L0001: JE              G00,#be,#c2 [FALSE] RFALSE
       PRINT_RET       "You hear the master bedroom door shut."

Routine R0309, 0 locals ()

       JE              Gb1,#45 [FALSE] L0001
       JZ              G3f [TRUE] L0001
       PRINT_RET       "You can hear the muffled voice of Mrs. Robner through
the door."
L0001: JE              Gb1,#40 [FALSE] RFALSE
       JZ              G3f [TRUE] L0002
       PRINT_RET       "Mrs. Robner's calls out. "Wait just one minute!""
L0002: CALL            R0310 -> -(SP)
       RET_POPPED      

Routine R0310, 0 locals ()

       JE              Gb1,#45 [FALSE] L0001
       PRINT_RET       "You can't hear anything through the door."
L0001: JE              Gb1,#40 [FALSE] RFALSE
       JE              Gaf,#f5 [FALSE] L0002
       JZ              G42 [FALSE] L0002
       JL              G76,#02bc [FALSE] L0002
       JE              G00,#f6 [FALSE] L0002
       PRINT           "You hear footsteps inside the house. Mrs. Robner,
dressed in black, opens the door and greets you."
       NEW_LINE        
       CALL            R0311 -> -(SP)
       RET_POPPED      
L0002: CALL            R0313 -> -(SP)
       CALL            R0312 ((SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] L0003
       PRINT_RET       "A muffled voice says, "Come in!""
L0003: PRINT_RET       "There is no answer at the door."

Routine R0311, 0 locals ()

       PRINT           ""Hello," she says, "I'm Mrs. Robner. Please come in.
I'm afraid I really can't help you much. This is surely a terrible waste of
time, not to mention upsetting, having all these police marching around the
house. This has been a trying time, as I suppose you can understand. As I told
Mr. Coates and the other detective, you may look around but you must be out by
8 o'clock at the latest. Oh, I almost forgot...Mr. Coates will be reading my
husband's will at noon in the living room. You may attend if you wish.""
       STORE           G42,#01
       REMOVE_OBJ      "Mrs. Robner"
       JE              G00,#f6 [FALSE] L0001
       NEW_LINE        
       PRINT           "Mrs. Robner leads you into the house and closes the
door behind you."
       NEW_LINE        
       NEW_LINE        
       CALL            R0110 (#dd) -> -(SP)
L0001: INSERT_OBJ      "Mrs. Robner","Foyer"
       PRINT           ""I'm going to make myself some breakfast now. I'll be
around all day if you need anything. I'll do what I can to help. Good day!""
       NEW_LINE        
       CLEAR_ATTR      "front door",#1c
       CALL            R0442 (#97,#c4) -> -(SP)
       RET_POPPED      

Routine R0312, 2 locals (0000, 0000)

       GET_CHILD       L00 -> L01 [FALSE] RFALSE
L0001: TEST_ATTR       L01,#14 [TRUE] RTRUE
       GET_SIBLING     L01 -> L01 [TRUE] L0002
L0002: JZ              L01 [FALSE] L0001
       RFALSE          

Routine R0313, 0 locals ()

       JE              Gaf,#bf [FALSE] L0001
       RET             #b2
L0001: JE              Gaf,#bc [FALSE] L0002
       RET             #a4
L0002: JE              Gaf,#c0 [FALSE] L0003
       RET             #a7
L0003: JE              Gaf,#da [FALSE] RFALSE
       RET             #d6

Routine R0314, 0 locals ()

       GET_PARENT      "Mrs. Robner" -> G3b
       CALL            R0442 (#97,#b2,#01) -> -(SP)
       STORE           G3d,#01
       CALL            R0004 (#7c4d,#ffff) -> -(SP)
       RET_POPPED      

Routine R0315, 0 locals ()

       JE              G00,#b9,#b2,#ca [TRUE] L0001
       PRINT_RET       "There's no telephone here."
L0001: JE              Gb1,#32 [FALSE] L0002
       PRINT_RET       "You are the detective, after all."
L0002: JE              Gb1,#12,#45,#5b [FALSE] RFALSE
       JZ              G44 [TRUE] L0005
       PRINT           "You take the phone and hear an unfamiliar man's voice
say "Hello?  Is Leslie there?"  You start to reply, but Mrs. Robner"
       JE              G00,#ca [FALSE] L0003
       PRINT           " enters and takes the phone from you. "Thank you,
inspector," she says, and then into the telephone: "Hello? Oh, hi. I can't
really talk now. I'll call you back soon, OK? Bye." She hangs up and starts
toward the door."
       NEW_LINE        
       JUMP            L0004
L0003: PRINT           " picks up the phone from another extension and hears
you. "I've got it, inspector," she says. "Hello? Oh, it's you. I can't talk
now. I'll call you back soon. Bye!" You hear two clicks and the line goes
dead."
       NEW_LINE        
L0004: STORE           G44,#00
       INSERT_OBJ      "Mrs. Robner","Living Room"
       CALL            R0314 -> -(SP)
       RET_POPPED      
L0005: JZ              G3f [TRUE] L0006
       PRINT           "You can hear Mrs. Robner and a man whose voice you
don't recognize. Robner: "...much too early to consider it."
Man's Voice: "But we couldn't have planned it better. You're free."
Robner: "Yes, but it will...Wait a second...I think..."
"Click." You realize that the call has been disconnected."
       NEW_LINE        
       STORE           G3c,#01
       STORE           G3f,#00
       CALL            R0004 (#7c4d,#00) -> -(SP)
       CALL            R0441 (#97) -> -(SP)
       RET_POPPED      
L0006: PRINT_RET       "All you hear is a dial tone."

Routine R0316, 0 locals ()

       JE              Gb1,#59 [FALSE] L0002
       GET_PARENT      "Mrs. Robner" -> -(SP)
       JE              (SP)+,G00 [FALSE] L0001
       PRINT           "Mrs. Robner grabs the envelope from you. "That," she
says, "is none of your business!""
       NEW_LINE        
       INSERT_OBJ      "handwritten envelope","Mrs. Robner"
       RTRUE           
L0001: STORE           G3a,#01
       JIN             "handwritten envelope",Ga8 [TRUE] RFALSE
       CALL            R0078 (#00) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       PRINT           "(Taken)"
       NEW_LINE        
       RFALSE          
L0002: JE              Gb1,#23 [FALSE] RFALSE
       JZ              G3a [TRUE] RFALSE
       PRINT           "You close the envelope carefully, but it still looks
like it has been opened."
       NEW_LINE        
       CLEAR_ATTR      "handwritten envelope",#1c
       RTRUE           

Routine R0317, 3 locals (0000, 0000, 0000)

       GET_PROP        L00,#07 -> -(SP)
       LOADW           G08,(SP)+ -> L01
       LOADW           L01,#04 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       LOADW           L01,#01 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       GET_PARENT      L00 -> L02
       LOADW           L01,#00 -> -(SP)
       JE              L02,(SP)+ [TRUE] RFALSE
       RTRUE           

Routine R0318, 1 local (0000)

       JZ              L00 [FALSE] L0001
       JE              Gb1,#36 [FALSE] L0001
       JE              Gaf,#8b [FALSE] L0001
       CALL            R0010 (#69,#97,#8b) -> -(SP)
       RTRUE           
L0001: JE              L00,#05 [FALSE] L0009
       CALL            R0317 (#97) -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       JZ              G3d [TRUE] L0008
       PRINT           "Mrs. Robner appears to be in a hurry."
       NEW_LINE        
       JUMP            L0008
L0002: JZ              G3e [TRUE] L0003
       PRINT           "Mrs. Robner is staring at you."
       NEW_LINE        
       JUMP            L0008
L0003: JIN             "Mrs. Robner","Kitchen" [FALSE] L0004
       PRINT           "Mrs. Robner is preparing a meal."
       NEW_LINE        
       JUMP            L0008
L0004: JIN             "Mrs. Robner","Dining Room" [FALSE] L0005
       PRINT           "Mrs. Robner is eating breakfast here."
       NEW_LINE        
       JUMP            L0008
L0005: JIN             "Mrs. Robner","Living Room" [FALSE] L0006
       JZ              G4f [FALSE] RTRUE
       PRINT           "Mrs. Robner is sitting here, knitting."
       NEW_LINE        
       JUMP            L0008
L0006: JIN             "Mrs. Robner","Master Bedroom" [FALSE] L0007
       PRINT           "Mrs. Robner is sitting on her bed."
       NEW_LINE        
       JUMP            L0008
L0007: PRINT           "Mrs. Robner is here."
       NEW_LINE        
L0008: CALL            R0354 (#97) -> -(SP)
       RET_POPPED      
L0009: JE              Gb1,#38,#39 [FALSE] L0012
       PRINT           "Mrs. Robner says a curt ""
       JE              Gb1,#39 [FALSE] L0010
       PRINT           "Hello"
       JUMP            L0011
L0010: PRINT           "Bye"
L0011: PRINT_RET       ""."
L0012: JE              Ga8,#97 [FALSE] L0015
       JE              Gb1,#32 [TRUE] RFALSE
       JE              Gb1,#59 [FALSE] L0014
       JE              Gaf,#8b [FALSE] L0014
       JZ              G3a [TRUE] L0013
       PRINT_RET       ""You seem to have taken care of that already.""
L0013: PRINT_RET       ""I believe there are laws protecting the privacy of
mail. I will not open the envelope for you or anyone else.""
L0014: CALL            R0397 (#97) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       CALL            R0002 (G61) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0015: JE              Gb1,#14 [FALSE] L0018
       JZ              G3a [FALSE] L0016
       JZ              G3c [TRUE] L0018
L0016: TEST_ATTR       "lab report",#1e [TRUE] L0017
       CALL            R0286 (#97) -> -(SP)
       RTRUE           
L0017: PRINT           "Sergeant Duffy enters and leads Mrs. Robner away.

"
       CALL            R0424 (S166) -> -(SP)
       PRINT           "I am sorry to inform you that the grand jury
investigating the murder charge against Mrs. Robner declined to indict her,
citing a lack of evidence linking her with the execution of the crime. Please
try to be more cautious when making arrests in the future.

"
       NEW_LINE        
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0018: JE              Gb1,#15 [FALSE] L0041
       JE              Gaf,#97 [FALSE] L0041
       CALL            R0462 (#97) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       JE              Gb0,#24 [FALSE] L0020
       JZ              G6d [TRUE] L0019
       PRINT_RET       ""I'm quite shocked about it. I really had no idea!""
L0019: PRINT_RET       ""I don't know what you're talking about, Inspector. I
know of no such closet.""
L0020: JE              Gb0,#0e,#0d,#0f [FALSE] L0021
       PRINT_RET       ""I have some allergies, Inspector. Simply dreadful in
the fall and spring. That's what the Allergone is for. I don't use them much
this time of year, though.""
L0021: JE              Gb0,#11,#10,#12 [FALSE] L0022
       PRINT_RET       ""Sneezo is a wonderful cold remedy. Whenever I get a
cold, I just take a few, and I usually feel much better before long.""
L0022: JE              Gb0,#53 [FALSE] L0025
       JZ              G3c [TRUE] L0023
       JZ              G39 [TRUE] L0023
       PRINT_RET       ""I guess you know it was Steven. I admit we were
lovers, and we planned to marry if I could get a divorce from Marshall. He
refused to consider it, the divorce I mean, even though he had no time for me
anymore. He was married to the company, and he refused to see my side of
things. Steven was suggesting that now we could marry. I told him I thought the
timing was poor, or at least I would have if you hadn't eavesdropped.""
L0023: JZ              G3c [TRUE] L0024
       PRINT_RET       ""I was talking to a good friend of mine. We were
discussing some plans we made; of course they had to be changed, under the
circumstances. They are none of your business. They don't concern my husband's
suicide at all, I assure you.""
L0024: PRINT_RET       ""It was just a friend of mine, offering his
condolences.""
L0025: JE              Gb0,#44 [FALSE] L0028
       JZ              G39 [FALSE] L0026
       PRINT_RET       ""I don't know who you mean. I have no friend named
Steven.""
L0026: JZ              G3c [TRUE] L0027
       JZ              G39 [TRUE] L0027
       PRINT_RET       ""I might as well tell you. Steven and I were lovers and
we were going to be married if I could divorce Marshall. I asked Marshall about
it, but he became angry and refused. I didn't know what to do. Don't look at me
that way. I had nothing to do with my husband's death. Driving him to it with
talk of divorce? You didn't know Marshall, that's for sure! I should've told
the police earlier, I suppose, but it's really none of your business.""
L0027: JZ              G39 [TRUE] RFALSE
       PRINT_RET       ""Steven is a close personal friend. We have known each
other for many years, and I visit his home frequently. Marshall knew of our
friendship and didn't begrudge it in the slightest. My husband and I had a very
trusting relationship. You may find the idea of trust difficult to understand,
I suppose.""
L0028: JE              Gb0,#7f [FALSE] L0029
       PRINT_RET       ""I loved my husband, no matter what you may think. I am
very sorry to have lost him." The speech is almost a set piece, and not too
convincing."
L0029: JE              Gb0,#99,#98 [FALSE] L0030
       CALL            R0353 (#97,#99) -> -(SP)
       PRINT_RET       ""A child. He may be a man in age, but he still hasn't
really grown up. He'll find himself someday, but in the meantime he can be a
trial. I guess Marshall and I were too lenient. We probably still are, but he
is our son, after all. We can't throw him out on the street.""
L0030: JE              Gb0,#9d,#9c [FALSE] L0031
       PRINT_RET       ""Baxter has been my husband's partner for a long time,
but they're not close friends. Baxter has always had the head for making money,
and Marshall had the creative spark for new products. The two of them were
perfect for each other in the early days. Of course, things haven't been going
well lately. I guess none of that matters much now.""
L0031: JE              Gb0,#50,#9b,#9a [FALSE] L0032
       CALL            R0353 (#97,#9b) -> -(SP)
       PRINT_RET       ""I've always thought she was a bit too smug in her
relationships around here. A bit above herself, if you see my meaning. After
all, she's really just a glorified secretary. She acts as though she's part of
the family, and she does get along well with almost everyone here. I swear,
though, Marshall spent more time with her than me, lately. Um...not that I'm
trying to imply that anything went on between them. Quite the contrary.""
L0032: JE              Gb0,#95,#94 [FALSE] L0033
       CALL            R0353 (#97,#95) -> -(SP)
       PRINT_RET       ""She's an excellent housekeeper and sometimes even
helps with the cooking For all her good qualities, though, she's too much of a
snoop and a gossip. She tires to keep track of everyone around here. It's
unnerving sometimes. But, as servants go these days, she's quite
extraordinary.""
L0033: JE              Gb0,#9f,#9e [FALSE] L0034
       PRINT_RET       ""I don't pay much attention to him. He's worked out
well; the grounds are in excellent condition. You must take a look at his roses
while you're here. They're really spectacular.""
L0034: JE              Gb0,#83 [FALSE] L0036
       JG              G70,#00 [FALSE] L0035
       PRINT_RET       ""It's what I expected, really.""
L0035: PRINT_RET       ""Marshall takes care of that sort of thing. The will, I
suppose, leaves the estate to George and me, but I can't be sure.""
L0036: JE              Gb0,#8e [FALSE] L0037
       PRINT_RET       ""What do you know? Marshall changed the will, after
all. Where did you ever find this? What? George was trying to destroy it? I'm
shocked. You don't think George had anything to do..." She stops short."
L0037: JE              Gb0,#82 [FALSE] L0038
       PRINT_RET       ""If there is a new will, I certainly don't know where
it is.""
L0038: JE              Gb0,#80 [FALSE] L0039
       PRINT_RET       ""Oh, you mean the "scandal"? Focus Corporation was a
subsidiary of Robner Corp. some years ago. There was a big to-do about misuse
of funds or some such thing, but Marshall kept it pretty quiet. He told me that
the people responsible were forced out of the company, but that charges weren't
pressed to avoid bad publicity. I didn't realize anyone remembered that.""
L0039: JE              Gb0,#43 [FALSE] L0040
       PRINT_RET       ""I don't know of a safe in the house, although it's
perfectly believable that Marshall has one hidden somewhere. It would appeal to
his childish side, I think.""
L0040: PRINT_RET       ""I don't know much about that.""
L0041: JE              Gb1,#69,#24 [FALSE] RFALSE
       CALL            R0462 (#97) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
       JE              Gb0,#55 [FALSE] L0042
       PRINT_RET       "Mrs. Robner reads the report with shocked disbelief.
"I...I don't know what to say. Who would want to kill Marshall? He was so well
liked and..." She breaks down, sobbing."
L0042: JE              Gb0,#8e [FALSE] L0043
       PRINT_RET       "Mrs. Robner reads the will. "That's that, then," she
says. "I guess Marshall was pushed too far.""
L0043: JE              Gb0,#8b,#8a [FALSE] RFALSE
       JZ              G3a [FALSE] L0044
       PRINT           ""Thank you, Inspector. The envelope is for me." She
takes the envelope from you and examines it briefly."
       NEW_LINE        
       INSERT_OBJ      "handwritten envelope","Mrs. Robner"
       RTRUE           
L0044: STORE           G39,#01
       PRINT           ""You have certainly stooped to a new low, Inspector.
Opening people's mail. I think there are laws against that sort of thing, but I
guess you wouldn't know."
       JZ              G3c [TRUE] L0045
       PRINT_RET       " I suppose you also know that Steven is my lover and
that we were planning to marry. Don't look so melodramatic: I didn't kill my
husband. You think my talk of divorce may have driven him to it? Why don't you
leave me alone!""
L0045: PRINT_RET       " In any case, what of it? It's from a friend of mine,
an old friend from school. We get together now and then to discuss old times. I
don't suppose there is a law against that?""

Routine R0319, 0 locals ()

       JE              Gb1,#5b [FALSE] L0001
       JE              Gb0,#7e [FALSE] L0001
       PRINT_RET       "That would make an ungodly pile of books on the floor
and take most of the day."
L0001: JE              Gb1,#5b [FALSE] L0002
       PRINT_RET       "You have better things to do than taking books from the
shelves."
L0002: JE              Gb1,#4e [FALSE] L0003
       PRINT_RET       "Reading, while educational, will not help you solve
this case."
L0003: JE              Gb1,#4c [FALSE] L0004
       PRINT_RET       "It would take all day to look behind all of the books."
L0004: JE              Gb1,#50,#2f [FALSE] RFALSE
       PRINT           "The shelves contain many books and manuscripts covering
a wide range of subjects. They are meticulously arranged."
       NEW_LINE        
       JZ              G43 [FALSE] L0005
       JZ              G47 [TRUE] RTRUE
       JE              G54,"carefu" [FALSE] RTRUE
L0005: PRINT           "One book is out of place, however, leaving a gap in one
row. On closer inspection, a small black button can be seen at the back of this
gap."
       NEW_LINE        
       STORE           G38,#01
       CLEAR_ATTR      "black button",#1f
       RTRUE           

Routine R0320, 0 locals ()

       JE              Gb1,#5d [FALSE] RFALSE
       TEST_ATTR       "hidden door",#1c [FALSE] L0001
       PRINT           "The bookshelf on the left quietly swings shut."
       NEW_LINE        
       CLEAR_ATTR      "hidden door",#1c
       RTRUE           
L0001: PRINT           "The leftmost shelf quietly swings out against the
balcony window."
       NEW_LINE        
       SET_ATTR        "hidden door",#1c
       RTRUE           

Routine R0321, 0 locals ()

       JE              Gb1,#55,#62,#5b [FALSE] L0001
       PRINT_RET       "These items are very rare and delicate, and were used
only by Mr. Robner himself. You shouldn't even be touching them."
L0001: JE              Gb1,#2f [FALSE] L0002
       PRINT           "Each one is hand-painted and depicts a scene from Greek
mythology."
       NEW_LINE        
       STORE           G2b,#01
       RTRUE           
L0002: JE              Gb1,#58 [FALSE] RFALSE
       RANDOM          #64 -> -(SP)
       JG              #4b,(SP)+ [FALSE] L0003
       PRINT           "As you reach for the "
       PRINT_OBJ       Gaf
       PRINT_RET       ", you think of the pension awaiting you upon
retirement. "Is it worth it?" you think, to be booted off the force for an
impulse of anger and stupidity. Fortunately, you calm your temper."
L0003: PRINT           "With a sweep of your hand, you smash all of them! Mrs.
Rourke runs into the room, screaming."
       NEW_LINE        
       CALL            R0322 -> -(SP)
       RET_POPPED      

Routine R0322, 0 locals ()

       PRINT           "Your mind becomes confused amidst strange screaming,
yelling, and the pangs of your conscience. "How could I have done it?" you ask
yourself, as you hear the distant sound of police sirens. Sergeant Duffy and
two other officers enter and grab you rather unceremoniously. They take you to
a waiting car, where, forlorn and disgusted, you begin to ponder prison life.
"Perhaps," you think, "I shouldn't have done that.""
       NEW_LINE        
       CALL            R0431 -> -(SP)
       RET_POPPED      

Routine R0323, 0 locals ()

       JE              Gb1,#58,#2f [TRUE] L0001
       JE              Gb1,#55,#62,#5b [FALSE] L0002
L0001: CALL            R0321 -> -(SP)
       RET_POPPED      
L0002: JE              Gb1,#25 [FALSE] RFALSE
       PRINT_RET       "There are six hand-painted cups."

Routine R0324, 0 locals ()

       JE              Gb1,#58,#2f [TRUE] L0001
       JE              Gb1,#55,#62,#5b [FALSE] L0002
L0001: CALL            R0321 -> -(SP)
       RET_POPPED      
L0002: JE              Gb1,#25 [FALSE] RFALSE
       PRINT_RET       "There are seven hand-painted saucers."

Routine R0325, 0 locals ()

       JE              Gb1,#58,#2f [TRUE] L0001
       JE              Gb1,#55,#62,#5b [FALSE] L0002
L0001: CALL            R0321 -> -(SP)
       RET_POPPED      
L0002: JE              Gb1,#25 [FALSE] RFALSE
       PRINT_RET       "There are eight large and small plates, seven saucers,
and six cups."

Routine R0326, 0 locals ()

       JE              Gb1,#58,#2f [TRUE] L0001
       JE              Gb1,#55,#62,#5b [FALSE] L0002
L0001: CALL            R0321 -> -(SP)
       RET_POPPED      
L0002: JE              Gb1,#25 [FALSE] RFALSE
       PRINT_RET       "There are eight of both the large and the small
plates."

Routine R0327, 0 locals ()

       JE              Gb1,#13 [FALSE] L0001
       JE              Gb0,#64 [FALSE] L0001
       PRINT           "The ladder fits perfectly in the holes! You slowly
release the ladder and it rests on the railing of the balcony above."
       NEW_LINE        
       STORE           G59,#01
       INSERT_OBJ      "wooden ladder",G00
       STORE           G2a,#01
       SET_ATTR        "wooden ladder",#19
       RTRUE           
L0001: JE              Gb1,#20 [FALSE] L0002
       JZ              G59 [FALSE] L0002
       JZ              G1c [FALSE] L0002
       PRINT_RET       "Climbing a ladder while it is horizontal is, at best, a
contradiction in terms."
L0002: JE              Gb1,#41 [FALSE] L0006
       JE              Gb0,#f7,#e3 [FALSE] L0006
       JE              G00,#e4 [FALSE] L0003
       STORE           G59,#01
       STORE           G1c,#00
       STORE           G2a,#01
       INSERT_OBJ      "wooden ladder",G00
       PRINT           "The ladder is now leaning against the railing of a
balcony above."
       NEW_LINE        
       JUMP            L0005
L0003: JE              G00,#df [FALSE] L0004
       STORE           G59,#00
       STORE           G1c,#01
       INSERT_OBJ      "wooden ladder",G00
       PRINT           "The ladder, firmly planted in the soil of the orchard,
is now leaning against the balcony above."
       NEW_LINE        
       JUMP            L0005
L0004: PRINT_RET       "There is no good spot to lean it against here."
L0005: SET_ATTR        "wooden ladder",#19
       RTRUE           
L0006: JE              Gb1,#55,#5b [FALSE] L0007
       CLEAR_ATTR      "wooden ladder",#19
       STORE           G59,#00
       STORE           G1c,#00
       RFALSE          
L0007: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The ladder is a typical gardening ladder, about fifteen
feet long and caked with dirt and dried mud."

Routine R0328, 0 locals ()

       JE              Gb1,#4a,#2f [FALSE] L0001
       PRINT_RET       "The cup is painted with a scene from Greek mythology
and has a brown discoloration at the bottom."
L0001: JE              Gb1,#6b [FALSE] L0002
       PRINT_RET       "The cup smells faintly of tea."
L0002: JE              Gb1,#33 [FALSE] L0003
       PRINT_RET       "There don't seem to be any fingerprints on the cup."
L0003: JE              Gb1,#10 [FALSE] RFALSE
       JE              #71,Gaf [FALSE] RFALSE
       CALL            R0330 -> -(SP)
       RET_POPPED      

Routine R0329, 1 local (0000)

       JZ              G77 [TRUE] L0001
       PRINT_RET       "Sergeant Duffy is already at the lab running a previous
errand. You will have to wait for him to return."
L0001: JZ              L00 [FALSE] L0002
       PRINT           "You look at the "
       PRINT_OBJ       Gaf
       PRINT           " closely. It appears to have good fingerprints on it,
so you call for Sergeant Duffy."
       NEW_LINE        
L0002: JZ              L00 [TRUE] L0003
       JZ              Gb0 [TRUE] L0003
       STORE           G29,Gb0
       JUMP            L0004
L0003: STORE           G29,#00
L0004: STORE           G77,Gaf
       STORE           G28,L00
       JE              Gaf,#7a [FALSE] L0006
       JG              G76,#02d0 [FALSE] L0005
       PRINT           "Sergeant Duffy arrives and shakes his head sadly. "I'm
sorry, sir, but the Ladder Analysis Department closes at noon." He leaves."
       NEW_LINE        
       STORE           G77,#00
       RFALSE          
L0005: STORE           G59,#00
       STORE           G1c,#00
       CLEAR_ATTR      "wooden ladder",#19
L0006: RANDOM          #0f -> -(SP)
       ADD             #0f,(SP)+ -> -(SP)
       CALL            R0004 (#8db4,(SP)+) -> -(SP)
       STOREW          (SP)+,#00,#01
       REMOVE_OBJ      Gaf
       SET_ATTR        Gaf,#1e
       PRINT           "Sergeant Duffy walks up as quietly as a mouse. He takes
the "
       PRINT_OBJ       Gaf
       PRINT_RET       " from you. "I'll return soon with the results," he
says, and leaves as silently as he entered."

Routine R0330, 0 locals ()

       CALL            R0329 (#01) -> -(SP)
       RET_POPPED      

Routine R0331, 0 locals ()

       PRINT           "Sergeant Duffy "
       JE              G77,#7a [FALSE] L0001
       PRINT           "comes onto the scene. "
       JUMP            L0004
L0001: RANDOM          #64 -> -(SP)
       JG              #1e,(SP)+ [FALSE] L0002
       PRINT           "appears before you, holding the "
       PRINT_OBJ       G77
       PRINT           " carefully in his hands. His quiet efficiency and
youthful vigor impress you quite a bit. "
       JUMP            L0004
L0002: RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0003
       PRINT           "seems to arrive from nowhere, holding the "
       PRINT_OBJ       G77
       PRINT           " in his hands. "
       JUMP            L0004
L0003: PRINT           "returns with the "
       PRINT_OBJ       G77
       PRINT           ". For a moment you muse on his almost magical
entrances. "
L0004: JZ              G28 [FALSE] L0006
       PRINT           ""The fingerprints," he begins, "belong to "
       JE              G77,#71 [FALSE] L0005
       PRINT           "Mr. Robner"
       JUMP            L0013
L0005: JE              G77,#70,#62 [FALSE] L0013
       PRINT           "Mr. Robner and Ms. Dunbar"
       JUMP            L0013
L0006: JZ              G29 [TRUE] L0008
       JE              G77,#63 [FALSE] L0007
       JE              G29,#5c,#5f,#5d [FALSE] L0007
       PRINT           ""The fragment did contain LoBlo. Here is the full
report." He hands you a slip of paper, and departs."
       NEW_LINE        
       INSERT_OBJ      "lab report","player"
       SET_ATTR        "lab report",#1e
       INSERT_OBJ      G77,"player"
       STORE           G77,#00
       RTRUE           
L0007: PRINT           ""The "
       PRINT_OBJ       G77
       PRINT           " analysis yielded nothing useful"
       JUMP            L0013
L0008: JE              G77,#63 [FALSE] L0009
       PRINT           ""The fragment," he begins, "contains traces of tea and
sugar."
       PRINT           " In addition, there seems to be some other chemical
present that is not a common medication. It could take weeks to determine
exactly what it is. It is definitely not Amitraxin (Ebullion), though. There
are no clear fingerprints"
       JUMP            L0013
L0009: JE              G77,#71 [FALSE] L0010
       PRINT           ""The cup," he begins, "contains a trace of tea. The
fingerprints are those of Mr. Robner"
       JUMP            L0013
L0010: JE              G77,#70 [FALSE] L0011
       PRINT           ""The saucer," he begins, "contains traces of tea and
sugar. The fingerprints are those of Mr. Robner and Ms. Dunbar"
       JUMP            L0013
L0011: JE              G77,#62 [FALSE] L0012
       PRINT           ""The bowl," he begins, "has the fingerprints of Mr.
Robner and Ms. Dunbar. The bowl contains common table sugar only."
       JUMP            L0013
L0012: PRINT           ""I am sorry," he begins, " but the lab found nothing of
interest."
L0013: JE              G77,#7a [FALSE] L0014
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [TRUE] L0014
       PRINT           " In the interests of civility, I have left the ladder
outside the house." He leaves."
       NEW_LINE        
       INSERT_OBJ      "wooden ladder","Front Path"
       JUMP            L0015
L0014: PRINT           "". With that, he leaves, handing you the "
       PRINT_OBJ       G77
       PRINT           " as he whisks away."
       NEW_LINE        
       INSERT_OBJ      G77,"player"
L0015: STORE           G77,#00
       RTRUE           

Routine R0332, 1 local (0000)

       JE              L00,#5d,#5c,#5f [FALSE] L0001
       PRINT           "LoBlo"
       JUMP            L0006
L0001: JE              L00,#5a,#5b [FALSE] L0002
       PRINT           "aspirin"
       JUMP            L0006
L0002: JE              L00,#56,#57,#5e [FALSE] L0003
       PRINT           "Ebullion"
       JUMP            L0006
L0003: JE              L00,#58,#59 [FALSE] L0004
       PRINT           "Dum-Kof"
       JUMP            L0006
L0004: JE              L00,#0d,#0f,#0e [FALSE] L0005
       PRINT           "Allergone"
       JUMP            L0006
L0005: PRINT_OBJ       L00
L0006: PRINT           "". "
       RTRUE           

Routine R0333, 0 locals ()

       JE              Gb1,#2f [FALSE] L0001
       PRINT_RET       "The saucer is hand-painted with a mythological scene.
It has a couple of small areas of brown discoloration."
L0001: JE              Gb1,#6b [FALSE] L0002
       PRINT_RET       "There is a faint smell of tea."
L0002: JE              Gb1,#33 [FALSE] L0003
       CALL            R0329 -> -(SP)
       RET_POPPED      
L0003: JE              Gb1,#10 [FALSE] RFALSE
       CALL            R0330 -> -(SP)
       RET_POPPED      

Routine R0334, 0 locals ()

       JE              Gb1,#2d,#5b [FALSE] RFALSE
       PRINT_RET       "Being unusually grubby, even for a police detective,
this is one of your better ideas so far on this case. However, your attire
isn't suitable, and you probably have better things to do."

Routine R0335, 1 local (0064)

       JE              L00,#64 [FALSE] RFALSE
       JE              Gb1,#4a,#2f [FALSE] L0001
       PRINT_RET       "You have stooped to a new low, snooping around toilet
bowls. Wait! Something catches your eye--was it the Tidy-Bowl man? Is he the
murderer?  Naw..."
L0001: JE              Gb1,#34 [FALSE] RFALSE
       PRINT_RET       "Whhoooossshhhhh!"

Routine R0336, 0 locals ()

       JE              Gb1,#44 [FALSE] RFALSE
       PRINT_RET       "You turn the handle and lo! Water starts to run.
Impressed, you turn the handle again, and the water stops running! Bravo!"

Routine R0337, 0 locals ()

       PRINT_RET       "You can't do anything with that."

Routine R0338, 0 locals ()

       JE              Gb1,#58 [FALSE] L0001
       PRINT_RET       "Vandalism is not the answer! Think of your position.
How would it look for a famous police inspector to be arrested?"
L0001: JE              Gb1,#19 [FALSE] L0002
       PRINT_RET       "You think you're clever, don't you? The window is so
dirty that it isn't easily cleaned."
L0002: JE              Gb1,#4a [FALSE] RFALSE
       PRINT_RET       "The window is dirty and impossible to see through
clearly."

Routine R0339, 1 local (0000)

       CALL            R0312 (L00) -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       PRINT_RET       "Someone looks up at you disgustedly."

Routine R0340, 0 locals ()

       JE              Gb1,#19,#58 [FALSE] L0001
       CALL            R0338 -> -(SP)
       RET_POPPED      
L0001: JE              Gb1,#59 [FALSE] L0002
       PRINT_RET       "The window can't be opened."
L0002: JE              Gb1,#40 [FALSE] L0005
       JE              G00,#c4 [FALSE] L0003
       PUSH            #e2
       JUMP            L0004
L0003: PUSH            #c4
L0004: CALL            R0339 ((SP)+) -> -(SP)
       RET_POPPED      
L0005: JE              Gb1,#4a [FALSE] RFALSE
       JE              G00,#c4 [FALSE] L0006
       PRINT_RET       "You can barely see through the thick leaves of the
grape arbor, but a lawn and lake can be seen in the distance."
L0006: PRINT           "You can see the kitchen beyond the tangle of trees and
branches."
       CALL            R0344 (#c4,S167) -> -(SP)
       RET_POPPED      

Routine R0341, 4 locals (0000, 0000, 0000, 0000)

       GET_CHILD       L00 -> L03 [TRUE] L0001
       RET             L02
L0001: TEST_ATTR       L03,#14 [FALSE] L0002
       INC             L02
       JZ              L01 [TRUE] L0002
       CALL            R0345 (L03,S168) -> -(SP)
L0002: GET_SIBLING     L03 -> L03 [TRUE] L0003
L0003: JZ              L03 [FALSE] L0001
       RET             L02

Routine R0342, 0 locals ()

       JE              Gb1,#19,#58 [FALSE] L0001
       CALL            R0338 -> -(SP)
       RET_POPPED      
L0001: JE              Gb1,#59 [FALSE] L0002
       PRINT_RET       "The window can't be opened."
L0002: JE              Gb1,#45 [FALSE] L0003
       JG              G1f,#00 [FALSE] L0003
       PRINT_RET       "You can't make out any of the words."
L0003: JE              Gb1,#4a [FALSE] RFALSE
       JE              G00,#e9 [FALSE] L0004
       PRINT           "Although the window is grimy, you can make out the lawn
outside. "
       CALL            R0344 (#ee,S169) -> -(SP)
       RET_POPPED      
L0004: JE              G1f,#04 [FALSE] L0005
       PRINT_RET       "Mr. Baxter seems furious and about to strike Ms.
Dunbar, then calms himself. Ms. Dunbar starts to cry and is embraced by Mr.
Baxter."
L0005: JG              G1f,#02 [FALSE] L0006
       PRINT_RET       "Mr. Baxter and Ms. Dunbar are inside. Although you
can't hear them, it's clear from their gestures that a serious argument is
occurring. Dunbar appears very upset and breaks into tears. Baxter remains
composed, but tense and  perhaps angry -- you can't be sure."
L0006: JG              G1f,#00 [FALSE] L0007
       PRINT_RET       "Through the grimy window you see Mr. Baxter and Ms.
Dunbar talking. Dunbar is doing most of the talking, barely restraining tears.
Baxter is listening, nodding grimly, and occassionally saying a few words.
Unfortunately, you can't make any of them out."
L0007: PRINT           "You can vaguely make out the inside of the shed through
the grime. "
       CALL            R0344 (#e9,S170) -> -(SP)
       RET_POPPED      

Routine R0343, 0 locals ()

       JE              Gb1,#58 [FALSE] L0001
       CALL            R0338 -> -(SP)
       RET_POPPED      
L0001: JE              Gb1,#59 [FALSE] L0002
       PRINT_RET       "The window can't be opened."
L0002: JE              Gb1,#4a [FALSE] RFALSE
       JE              G00,#e7 [FALSE] L0003
       PRINT           "You can see the dining room through the window."
       CALL            R0344 (#c5,S171) -> -(SP)
       RTRUE           
L0003: JE              G00,#e4 [FALSE] L0004
       PRINT           "You can see the dining room pretty clearly through the
window."
       NEW_LINE        
       CALL            R0341 (#c5,#01) -> -(SP)
       RTRUE           
L0004: PRINT_RET       "Through the window, the rose garden can be seen, and,
off to the north, a wide lawn ending on a blue lake."

Routine R0344, 3 locals (0000, 0000, 0000)

       CALL            R0341 (L00) -> L02
       JZ              L02 [FALSE] L0001
       NEW_LINE        
       RTRUE           
L0001: PRINT           " You can vaguely see "
       JE              L02,#01 [FALSE] L0002
       PRINT           "someone"
       JUMP            L0003
L0002: PRINT_NUM       L02
       PRINT           " people"
L0003: PRINT           " inside the "
       PRINT_PADDR     L01
       PRINT_RET       "."

Routine R0345, 2 locals (0000, 0000)

       PRINT_OBJ       L00
       PRINT           " is "
       JZ              L01 [FALSE] L0001
       PUSH            S172
       JUMP            L0002
L0001: PUSH            L01
L0002: PRINT_PADDR     (SP)+
       PRINT_RET       "."

Routine R0346, 0 locals ()

       JE              Gb1,#2f [FALSE] L0001
       PRINT_RET       "The dresser is a beautiful piece of cabinetry."
L0001: JE              Gb1,#59,#50,#4a [FALSE] RFALSE
       PRINT_RET       "You open all of the drawers, but find only a variety of
stockings, undergarments, and handkerchiefs."

Routine R0347, 1 local (0064)

       JE              L00,#64 [FALSE] RFALSE
       JE              Gb1,#4b [FALSE] RFALSE
       PRINT_RET       "No doubt you are looking for the bogeyman, but you are
out of luck."

Routine R0348, 0 locals ()

       JE              Gb1,#71 [FALSE] L0001
       PRINT_RET       "The powder tastes like sugar."
L0001: JE              Gb1,#6b [FALSE] L0002
       PRINT_RET       "There is no high from sniffing this powder."
L0002: JE              Gb1,#2b [FALSE] L0003
       PRINT_RET       "You eat some, but it is cloyingly sweet, so you stop."
L0003: JE              Gb1,#33 [FALSE] L0004
       CALL            R0329 -> -(SP)
       RET_POPPED      
L0004: JE              Gb1,#10 [FALSE] RFALSE
       CALL            R0330 -> -(SP)
       RET_POPPED      

Routine R0349, 0 locals ()

       JE              Gb1,#5b [FALSE] RFALSE
       PRINT_RET       "The tools are standard gardening tools, in excellent
condition. You have no use for them, unless you are looking for a new
profession."

Routine R0350, 1 local (0000)

       JE              L00,#05 [FALSE] L0007
       CALL            R0317 (#9b) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       JIN             "Mr. Baxter","shed" [FALSE] L0001
       JZ              G1f [FALSE] RTRUE
L0001: JZ              G21 [FALSE] RTRUE
       JIN             "Ms. Dunbar","Dunbar's Bathroom" [FALSE] L0002
       PRINT           "Ms. Dunbar is here, brushing her hair."
       JUMP            L0006
L0002: JIN             "Ms. Dunbar","Dunbar's Bedroom" [FALSE] L0003
       PRINT           "Ms. Dunbar is lying on her bed."
       JUMP            L0006
L0003: JIN             "Ms. Dunbar","Living Room" [FALSE] L0005
       JZ              G4f [TRUE] L0004
       PRINT           "Ms. Dunbar is standing in the corner, looking pensive."
       JUMP            L0006
L0004: PRINT           "Ms. Dunbar is sitting on the sofa here."
       JUMP            L0006
L0005: PRINT           "Ms. Dunbar is here."
L0006: NEW_LINE        
       CALL            R0354 (#9b) -> -(SP)
       RTRUE           
L0007: JE              Ga8,#9b [FALSE] L0009
       JE              Gb1,#32 [TRUE] RFALSE
       CALL            R0397 (#9b) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       JE              Gb1,#38,#39 [FALSE] L0008
       PRINT_RET       "Ms. Dunbar nods at you."
L0008: CALL            R0002 (G61) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0009: JE              Gb1,#69,#15,#39 [FALSE] L0010
       CALL            R0462 (#9b) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
L0010: JE              Gb1,#39 [FALSE] L0011
       PRINT_RET       "Ms. Dunbar nods at you."
L0011: JE              Gb1,#15 [FALSE] L0033
       JE              Gaf,#9b [FALSE] L0033
       JE              Gb0,#01 [FALSE] L0014
       JZ              G27 [FALSE] L0012
       JZ              G25 [TRUE] L0013
L0012: PRINT_RET       ""It was an excellent concert, Inspector, but I don't
see why you're asking about it.""
L0013: PRINT_RET       ""I don't know what you are talking about. I don't go in
for concerts much, you know.""
L0014: JE              Gb0,#05 [FALSE] L0018
       JZ              G24 [TRUE] L0015
       PRINT_RET       ""Why, it's just as Mr. Baxter said.""
L0015: STORE           G27,#01
       JIN             "Mr. Baxter",G00 [FALSE] L0016
       STORE           G25,#01
L0016: JZ              G26 [TRUE] L0017
       STORE           G15,#01
L0017: PRINT_RET       ""Oh, I...well, I guess I should tell you. You see, Mr.
Baxter and I, we go together to concerts, only occasionally, you understand. We
went that night, the night Marshall died. Then he took me home and that's it. I
should have said something before, but I just didn't think it was important,
and, well, I didn't think that the others should know we were seeing each other
socially. Our...nobody knows about it, you know. Please don't say anything!""
L0018: JE              Gb0,#9d,#9c [FALSE] L0019
       PRINT_RET       ""Mr. Baxter? I see him often when he comes here on
business, but I don't really know him that well. We keep to business when he
comes around, and I hardly ever talk with him otherwise. He is, of course, an
excellent executive, and poor Mr. Robner had every confidence in him.""
L0019: JE              Gb0,#5c,#5d,#5f [FALSE] L0021
       JZ              G40 [TRUE] L0020
       PRINT_RET       "Ms. Dunbar is taken aback. "I...I don't really know
what to say. I take the tablets for my blood pressure. I have for a few months
now. I know what you're thinking. I can't understand. Someone must have taken
my pills and poisoned Mr. Robner. That's it. It's probably George. He knew
about my pills. He's always snooping around. He used to talk about how half the
money would be his someday.""
L0020: PRINT_RET       "Ms. Dunbar seems a bit surprised. "You found those in
my bathroom, didn't you? I've been taking them for months for my blood
pressure. Are they important?" she asks."
L0021: JE              Gb0,#99,#98 [FALSE] L0022
       CALL            R0353 (#9b,#99) -> -(SP)
       PRINT_RET       ""Nobody likes George much. He's always alone when he's
here, and that's only when he can't get more money to waste. I think he's just
been waiting for the day when his father's money would be his. I can't say I
miss him when he's not here: A thoroughly obnoxious child.""
L0022: JE              Gb0,#97,#96 [FALSE] L0023
       PRINT_RET       ""She's a lovely person. She and Marshall were always an
odd couple: he was so quiet and reserved, and she's so lively and sociable.
She's changed a lot over the last few years. She used to enjoy her life here,
but lately she's been restless and irritable, and now with Marshall's death,
I'm worried about what may become of her.""
L0023: JE              Gb0,#95,#94 [FALSE] L0024
       PRINT_RET       ""Mrs. Rourke is a very good servant. Always helpful,
and always nearby when needed.""
L0024: JE              Gb0,#9f,#9e [FALSE] L0025
       PRINT_RET       ""He seems nice, if you can talk to him. You usually
can't, really." She laughs briefly. "Don't ever disturb his roses, or you'll
learn the meaning of temper." She giggles again."
L0025: JE              Gb0,#83 [FALSE] L0026
       PRINT_RET       ""I really don't know too much about Marshall's personal
business.""
L0026: JE              Gb0,#82 [FALSE] L0028
       JG              G70,#00 [FALSE] L0027
       PRINT_RET       ""I don't know anything about it. I suppose Marshall
could have written a new will, but I probably would have seen signs of it
around the library.""
L0027: PRINT_RET       ""As far as I know, there was no new will written,
although Marshall did threaten to disinherit George. I guess he could have
written one without my knowledge. I'm not always with him, you know.""
L0028: JE              Gb0,#8e [FALSE] L0029
       PRINT_RET       "Ms. Dunbar reads the will carefully, nodding slowly. "I
guess I'm not surprised that Marshall disinherited George. He's been asking for
it.""
L0029: JE              Gb0,#7f [FALSE] L0030
       PRINT_RET       "Ms. Dunbar looks down at the ground and sniffles
softly. "I've known him for years. He's been tremendously nervous and depressed
lately about business. I don't think all was well in his personal life either.
George has always been a problem for him. He even mentioned suicide once,
although I never took it seriously. It shows you can never tell." She wipes her
eyes with her hands."
L0030: JE              Gb0,#80 [FALSE] L0031
       PRINT_RET       ""Focus? There was once a subsidiary of Robner Corp.
with that name. I can't recall much about it, though.""
L0031: JE              Gb0,#43 [FALSE] L0032
       PRINT_RET       ""A safe? I don't think there's one in the house,
although there's one at the office.""
L0032: PRINT_RET       ""I'm sorry, but I can't help you with that.""
L0033: JE              Gb1,#24,#69 [FALSE] L0036
       JE              Gb0,#05 [FALSE] L0034
       CALL            R0010 (#15,#9b,#05) -> -(SP)
       RTRUE           
L0034: JE              Gb0,#5c [FALSE] L0035
       PRINT_RET       "She glances at the pills. "They're my pills. You must
have taken them from my bathroom. Well, what am I supposed to say?" She looks
away."
L0035: JE              Gb0,#55 [FALSE] RFALSE
       PRINT           "She seems stunned but recovers quickly. "He didn't
commit suicide, then?" she says. "But LoBlo, that's a pill I take for my blood
pressure." She pauses. "I can tell what you're thinking, but I didn't, couldn't
have done it. Why should I? Someone must have taken them, maybe George. He knew
I used them.""
       NEW_LINE        
       RANDOM          #0f -> -(SP)
       ADD             #05,(SP)+ -> -(SP)
       CALL            R0004 (#9a5b,(SP)+) -> -(SP)
       STOREW          (SP)+,#00,#01
       STORE           G40,#01
       RTRUE           
L0036: JE              Gb1,#0e [FALSE] L0038
       JZ              G40 [TRUE] L0037
       PRINT           ""No! I didn't do it! I've worked for Mr. Robner for
years. What possible motive could I have?" With that, Ms. Dunbar begins to cry
and move about the room quite nervously."
       NEW_LINE        
       CALL            R0361 -> -(SP)
       RET_POPPED      
L0037: PRINT_RET       ""What?" she cries. "Murder?" She regains her composure
and asks, "I thought he committed suicide, with his medicine.""
L0038: JE              Gb1,#14 [FALSE] RFALSE
       TEST_ATTR       "lab report",#1e [TRUE] L0039
       CALL            R0286 (#9b) -> -(SP)
       RTRUE           
L0039: PRINT           "Sergeant Duffy enters the room solemnly. He places
handcuffs on Ms. Dunbar and leads her off. She is sobbing hysterically.

"
       CALL            R0424 (S150) -> -(SP)
       JZ              G1e [TRUE] L0040
       PRINT           "What a tragedy! Ms. Dunbar, released on bail during her
trial for the murder of Mr. Robner, was found dead this morning, the victim of
an apparent suicide. Her death is all the more distressing as the district
attorney was trying to arrange some plea-bargaining deal with her in exchange
for information implicating an unnamed accomplice. I am sorry to be the one to
let you know. Thanks for your hard work on the Robner case.

"
       JUMP            L0041
L0040: PRINT           "I wanted to let you know the disposition of the Robner
case. Ms. Dunbar was acquitted today, the jury citing a lack of motive and only
circumstantial evidence. I am extremely sorry.

"
L0041: CALL            R0431 -> -(SP)
       RET_POPPED      

Routine R0351, 0 locals ()

       JZ              G22 [FALSE] RFALSE
       CALL            R0361 -> -(SP)
       RFALSE          

Routine R0352, 1 local (0000)

       JE              L00,#05 [FALSE] L0006
       CALL            R0317 (#95) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       JIN             "Mrs. Rourke","Kitchen" [FALSE] L0001
       PRINT           "Mrs. Rourke is here, cleaning the kitchen."
       NEW_LINE        
       JUMP            L0005
L0001: JIN             "Mrs. Rourke","Dining Room" [FALSE] L0002
       PRINT           "Mrs. Rourke is cleaning the table here."
       NEW_LINE        
       JUMP            L0005
L0002: JIN             "Mrs. Rourke","Living Room" [FALSE] L0003
       PRINT           "Mrs. Rourke is dusting the room."
       NEW_LINE        
       JUMP            L0005
L0003: JIN             "Mrs. Rourke","Mrs. Rourke's Room" [FALSE] L0004
       PRINT           "Mrs. Rourke is resting here."
       NEW_LINE        
       JUMP            L0005
L0004: PRINT           "Mrs. Rourke is here, tidying up."
       NEW_LINE        
L0005: CALL            R0354 (#95) -> -(SP)
       RTRUE           
L0006: JE              Ga8,#95 [FALSE] L0008
       JE              Gb1,#32 [TRUE] RFALSE
       CALL            R0397 (#95) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       JE              Gb1,#38,#39 [FALSE] L0007
       PRINT_RET       "Mrs. Rourke looks up from her work and nods."
L0007: CALL            R0002 (G61) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0008: JE              Gb1,#69,#15,#39 [FALSE] L0009
       CALL            R0462 (#95) -> -(SP)
       JZ              (SP)+ [TRUE] RTRUE
L0009: JE              Gb1,#38,#39 [FALSE] L0010
       PRINT_RET       "Mrs. Rourke looks up from her work and nods."
L0010: JE              Gb1,#15 [FALSE] L0019
       JE              Gaf,#95 [FALSE] L0019
       JE              Gb0,#8b [FALSE] L0011
       JIN             "handwritten envelope","Mrs. Rourke" [FALSE] L0011
       PRINT_RET       ""It's a letter just arrived for Mrs. Robner. I was
going to bring it to her.""
L0011: JE              Gb0,#9d,#9c [FALSE] L0012
       CALL            R0353 (#95,#9d) -> -(SP)
       PRINT_RET       ""Baxter! Hmmmph. Stuffiest person I ever met! I don't
mind telling you I've never liked him much. So serious, businesslike. Thinks
he's hot stuff, I imagine. I really shouldn't be telling you this, though, I
suppose. "Rourke," they tell me, "stop your gossiping." Not that I'm a gossip,
mind you, but I do have my opinions.""
L0012: JE              Gb0,#99,#98 [FALSE] L0013
       CALL            R0353 (#95,#99) -> -(SP)
       PRINT_RET       ""George is something, I tell you. The black sheep of
the family, is what I'd say. Never met nobody with less respect for money.
You'd think it grew on trees; not that it don't around here. Well, there I go,
shooting off my mouth again.""
L0013: JE              Gb0,#50,#9b,#9a [FALSE] L0014
       PRINT_RET       ""Ms. Dunbar is nice; the best of the lot, I think.
She's always been real friendly to me, and helps out when I have a problem. Mr.
Robner, he really liked her too. I don't think Mrs. Robner did, though. He's
been so busy lately with the business and Ms. Dunbar that I don't think the
Mrs. hardly saw him much. Kind of jealous, maybe, of the two of them, I mean.""
L0014: JE              Gb0,#97,#96 [FALSE] L0015
       CALL            R0353 (#95,#97) -> -(SP)
       PRINT_RET       ""Now she's a strange sort. Real lively when she moved
here, but I don't think she ever liked the life here. Her people are from
Boston, one of those old families, and she never got used to Mr. Robner's ways.
She goes out a lot, and sometimes she doesn't even come back at night. Not that
I'm spying on her. But I know about these things. She has callers here, a
number of men. One in particular comes more than others. A widower, I think, a
real live wire. Not what it's any of my business, but I think someone with a
sharp tongue could do her a lot of damage if she doesn't watch herself.""
L0015: JE              Gb0,#44 [FALSE] L0016
       CALL            R0353 (#95,#97) -> -(SP)
       PRINT_RET       ""Ah, that's it! He's the one who's been coming around,
taking Mrs. Robner out. I don't like the look of it. I mean, I think it looks
kind of funny, what with she's a married woman. Mr. Robner takes no notice, of
course, always busy. Oh, well. I shouldn't be telling you this. Now that Mr.
Robner's dead, I don't suppose it matters, but what do you think people were
saying! I tell you, gossip is fierce around here!""
L0016: JE              Gb0,#9f,#9e [FALSE] L0017
       PRINT_RET       ""Oh, don't let him frighten you. Let him alone and
don't bother his roses. Gets positively livid about that. Got the green thumb,
that's for sure.""
L0017: JE              Gb0,#7f [FALSE] L0018
       PRINT_RET       ""A fine man, but his head was always in the clouds.
Just the opposite of Mrs. Robner. Her feet were always on the ground. He's been
so worried, it makes me sick. I don't understand these business things, but he
said something about them taking his business away from him just two nights
ago. I guess the pressure was too much. He was a fine man, full of good works,
though charity does begin at home, as the saying goes. Not that I have anything
to complain about. He always treated me right.""
L0018: PRINT           ""I don't know nothing about no "
       PRINT_OBJ       Gb0
       PRINT_RET       ".""
L0019: JE              Gb1,#24,#69 [FALSE] RFALSE
       JE              Gb0,#55 [FALSE] L0020
       PRINT_RET       ""Well, if that don't beat all! A murder here, right
under my nose! You've got your work cut out for you, Inspector, all right.
There's some pretty strange people around here, and I wouldn't put it past
hardly any of 'em to do it. What do you know!""
L0020: PRINT_RET       "Mrs. Rourke seems uninterested in it."

Routine R0353, 2 locals (0000, 0000)

       JIN             L01,G00 [FALSE] RFALSE
       PRINT_OBJ       L00
       PRINT           " looks briefly toward "
       PRINT_OBJ       L01
       PRINT_RET       " and then speaks in a low whisper."

Routine R0354, 1 local (0000)

       GET_CHILD       L00 -> -(SP) [FALSE] RTRUE
       CALL            R0061 (L00,#01,#00) -> -(SP)
       RTRUE           

Routine R0355, 0 locals ()

       JE              Gb1,#29 [FALSE] L0001
       PRINT           "You drink the remaining cough syrup. Yuk! That was
awful!"
       NEW_LINE        
       REMOVE_OBJ      "quantity of cough syrup"
       RTRUE           
L0001: JE              Gb1,#71 [FALSE] RFALSE
       PRINT_RET       "Yuk! It tastes like cough medicine!"

Routine R0356, 0 locals ()

       JE              Gb1,#71 [FALSE] L0001
       PRINT_RET       "The pills are virtually tasteless."
L0001: JE              Gb1,#6b [FALSE] L0002
       PRINT_RET       "The pills are odorless."
L0002: JE              Gb1,#2b [FALSE] L0003
       PRINT_RET       "Nervous? Blood Pressure high? See a doctor."
L0003: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "These are small, yellow pills."

Routine R0357, 0 locals ()

       JE              Gb1,#71 [FALSE] L0001
       PRINT_RET       "The pills are virtually tasteless."
L0001: JE              Gb1,#6b [FALSE] L0002
       PRINT_RET       "The pills are odorless."
L0002: JE              Gb1,#2b [FALSE] L0003
       PRINT_RET       "You must realize that you aren't sick."
L0003: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "These are small, white pills."

Routine R0358, 0 locals ()

       JE              Gb1,#25 [FALSE] RFALSE
       PRINT_RET       "It's hard to tell with the bottle closed."

Routine R0359, 0 locals ()

       JE              Gb1,#71 [FALSE] L0001
       PRINT_RET       "The pills are bitter on the tongue."
L0001: JE              Gb1,#6b [FALSE] L0002
       PRINT_RET       "The pills are odorless."
L0002: JE              Gb1,#2b [FALSE] L0003
       PRINT_RET       "The only allergy you seem to have is to work."
L0003: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "These are tiny red pills."

Routine R0360, 0 locals ()

       JE              Gb1,#71 [FALSE] L0001
       PRINT_RET       "The pills are quite bitter."
L0001: JE              Gb1,#6b [FALSE] L0002
       PRINT_RET       "The pills have a faint pungent aroma."
L0002: JE              Gb1,#2b [FALSE] L0003
       PRINT_RET       "Are you depressed? Given your performance on this case,
that isn't surprising. In any event, you shouldn't take other people's
medicine!"
L0003: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "These are little white pills."

Routine R0361, 1 local (0000)

       GET_PARENT      "Mr. Baxter" -> L00
       JZ              G22 [FALSE] RFALSE
       JIN             "Ms. Dunbar",L00 [TRUE] L0001
       CALL            R0442 (#9b,L00,#01) -> -(SP)
L0001: STORE           G22,#01
       STORE           G23,L00
       CALL            R0004 (#9fb8,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           

Routine R0362, 1 local (0000)

       GET_PARENT      "Mr. Baxter" -> L00
       JE              L00,G23 [TRUE] L0001
       CALL            R0361 -> -(SP)
       RFALSE          
L0001: GET_PARENT      "Ms. Dunbar" -> -(SP)
       JE              (SP)+,L00 [FALSE] RFALSE
       LOADW           G08,#02 -> -(SP)
       STOREW          (SP)+,#04,#00
       JE              G00,L00 [FALSE] L0002
       PRINT_RET       "Ms. Dunbar glances at Baxter and then at you."
L0002: STORE           G21,#01
       LOADW           G08,#02 -> -(SP)
       STOREW          (SP)+,#04,#01
       CALL            R0004 (#9fb8,#00) -> -(SP)
       CALL            R0004 (#9fe8,#05) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          

Routine R0363, 0 locals ()

       STORE           G21,#00
       CALL            R0442 (#9b,#e9,#01) -> -(SP)
       CALL            R0004 (#a008,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#9ffc,#0a) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          

Routine R0364, 0 locals ()

       CALL            R0442 (#9d,#de,#01) -> -(SP)
       CALL            R0004 (#a15c,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          

Routine R0365, 1 local (0000)

       LOADW           G08,#03 -> L00
       GET_PARENT      "Ms. Dunbar" -> -(SP)
       JE              (SP)+,#e9 [FALSE] L0003
       GET_PARENT      "Mr. Baxter" -> -(SP)
       JE              (SP)+,#e9 [FALSE] L0001
       CALL            R0004 (#a20f,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#a008,#00) -> -(SP)
       RFALSE          
L0001: JE              G00,#e9 [FALSE] RFALSE
       RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0002
       PRINT_RET       "Dunbar paces around the shed nervously. If she was
looking for something, she would have found it by now."
L0002: PRINT_RET       "Ms. Dunbar seems to be looking around for something."
L0003: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0011
       CALL            R0369 (#9b) -> -(SP)
       JZ              (SP)+ [TRUE] L0011
       LOADW           L00,#04 -> -(SP)
       JZ              (SP)+ [TRUE] L0004
       STOREW          L00,#04,#00
       JUMP            L0007
L0004: RANDOM          #64 -> -(SP)
       JG              #1c,(SP)+ [FALSE] L0005
       PRINT_RET       "Ms. Dunbar eyes you nervously."
L0005: RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0006
       PRINT_RET       "Ms. Dunbar stares off toward the south."
L0006: PRINT_RET       "Ms. Dunbar seems to be deep in thought."
L0007: JZ              G20 [FALSE] L0008
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0008
       PRINT           "Ms. Dunbar spots you and stops. She reaches into her
pocket and pulls out a cigarette. As she does so, what appears to be a ticket
stub falls out of her pocket and floats to the ground. She checks her pocket
again, apparently for a match, but finds none and puts the cigarette back in
her pocket."
       NEW_LINE        
       GET_PARENT      "Ms. Dunbar" -> -(SP)
       INSERT_OBJ      "ticket stub",(SP)+
       STORE           G20,#01
       RTRUE           
L0008: RANDOM          #64 -> -(SP)
       JG              #0f,(SP)+ [FALSE] L0009
       PRINT           "Ms. Dunbar glances around as she walks. She takes a
quick glance in your direction, but it doesn't seem like she noticed you."
       NEW_LINE        
       STOREW          L00,#04,#01
       RTRUE           
L0009: RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0010
       PRINT_RET       "Ms. Dunbar looks around as she walks and does a brief
double-take when she looks in your direction. She slows down and stops."
L0010: PRINT_RET       "Ms. Dunbar, who has been looking from side to side as
she goes, comes to a stop. She spins around, looking in all directions."
L0011: STOREW          L00,#04,#01
       RFALSE          

Routine R0366, 0 locals ()

       GET_PARENT      "Mr. Baxter" -> -(SP)
       JE              (SP)+,#de [TRUE] L0001
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#00 [FALSE] RFALSE
L0001: CALL            R0004 (#a15c,#00) -> -(SP)
       CALL            R0442 (#9d,#e9,#01) -> -(SP)
       CALL            R0004 (#a174,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          

Routine R0367, 1 local (0000)

       LOADW           G08,#02 -> L00
       GET_PARENT      "Mr. Baxter" -> -(SP)
       JE              (SP)+,#e9 [FALSE] L0001
       CALL            R0004 (#a174,#00) -> -(SP)
       RFALSE          
L0001: CALL            R0369 (#9d) -> -(SP)
       JZ              (SP)+ [TRUE] L0006
       LOADW           L00,#04 -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       STOREW          L00,#04,#00
       RFALSE          
L0002: RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0003
       PRINT_RET       "Baxter draws a deep breath and looks about
contentedly."
L0003: PRINT_RET       "Baxter stares out over the lake."
       RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0004
       PRINT_RET       "Baxter walks slowly, but with determination. He looks
around often, as if he were a prospective buyer of the property. He stops now,
staring up at the sky."
L0004: PRINT           "Baxter stops, bends down, and ties his shoe."
       RANDOM          #64 -> -(SP)
       JG              #1e,(SP)+ [FALSE] L0005
       PRINT_RET       "  As he finishes, he takes stands up, and stares at
some distant trees."
L0005: PRINT_RET       " He stands up and stares off to the south."
L0006: STOREW          L00,#04,#01
       RFALSE          

Routine R0368, 0 locals ()

       JE              G00,#e9 [FALSE] L0004
       JL              G1f,#02 [TRUE] L0001
       JG              G1f,#05 [FALSE] L0002
L0001: PRINT           "You seem to have walked in on some sort of
get-together, although from the look on Ms. Dunbar's face, you are not the
guest of honor. She is aghast, and she continually looks back and forth between
Mr. Baxter and yourself."
       NEW_LINE        
       JUMP            L0003
L0002: PRINT           "As you enter the shed, Mr. Baxter and Ms. Dunbar, who
were in the midst of a quiet but heated argument, stop at once. Ms. Dunbar is
quite upset and clutches Mr. Baxter. Baxter, who has retained his composure
throughout, attempts to comfort Dunbar. She pushes him away and runs out of the
shed."
       NEW_LINE        
       INSERT_OBJ      "Ms. Dunbar","East Lawn"
       LOADW           G03,#03 -> -(SP)
       STOREW          (SP)+,#00,G76
       LOADW           G03,#00 -> -(SP)
       STOREW          (SP)+,#03,G76
L0003: CALL            R0370 -> -(SP)
       RTRUE           
L0004: GET_PARENT      "Mr. Baxter" -> -(SP)
       JE              (SP)+,#e9 [FALSE] RFALSE
       INC_CHK         G1f,#05 [FALSE] RFALSE
       CALL            R0370 -> -(SP)
       RFALSE          

Routine R0369, 3 locals (0000, 0000, 0000)

       GET_PARENT      L00 -> L01
       JE              L01,G00 [TRUE] RTRUE
       JE              G00,#ad [TRUE] RFALSE
       GET_PROP        L01,#0c -> L02
       GET_PROP        G00,#0c -> -(SP)
       AND             L02,(SP)+ -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       RTRUE           

Routine R0370, 0 locals ()

       JE              G00,#ee,#eb,#f2 [FALSE] L0001
       PRINT           "Baxter and Dunbar both leave the shed, heading off in
different directions."
       NEW_LINE        
       JUMP            L0002
L0001: JE              G00,#e8 [FALSE] L0002
       PRINT           "The voices stop and you hear sets of footsteps leaving
the shed."
       NEW_LINE        
L0002: CALL            R0442 (#9b,#a7,#01) -> -(SP)
       CALL            R0442 (#9d,#de,#01) -> -(SP)
       CALL            R0004 (#a31b,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#a20f,#00) -> -(SP)
       STORE           G1e,G1f
       STORE           G1f,#00
       RTRUE           

Routine R0371, 0 locals ()

       JE              G1d,#b2 [FALSE] L0004
       GET_PROP        G00,#0c -> -(SP)
       AND             (SP)+,#01 -> -(SP)
       JE              (SP)+,#01 [TRUE] RFALSE
       JE              G00,#cb,#cc,#a7 [TRUE] RFALSE
       STORE           G1d,#af
       INSERT_OBJ      "Mr. Baxter","Bedroom Balcony"
       REMOVE_OBJ      "Ms. Dunbar"
       STORE           G1b,#01
       CALL            R0005 (#bcf7) -> -(SP)
       STOREW          (SP)+,#00,#00
       INSERT_OBJ      "smoking gun","Dunbar's Bedroom"
       INSERT_OBJ      "suicide note","Dunbar's Bedroom"
       INSERT_OBJ      "body of Ms. Dunbar","Dunbar's Bedroom"
       CALL            R0004 (#a31b,#00) -> -(SP)
       CALL            R0004 (#a3ab,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#00 [FALSE] L0001
       STORE           G1a,#01
       PRINT           "You hear a pistol shot close by."
       NEW_LINE        
       JUMP            L0003
L0001: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0002
       PRINT           "You hear what sounds like a pistol shot from inside the
house."
       NEW_LINE        
       JUMP            L0003
L0002: PRINT           "From upstairs, you hear a single explosion like a
pistol shot."
       NEW_LINE        
L0003: CALL            R0374 -> -(SP)
       RTRUE           
L0004: JE              G1d,#af [FALSE] L0005
       JE              G00,#b2 [TRUE] RFALSE
       GET_PARENT      "Mrs. Robner" -> -(SP)
       JE              (SP)+,#b2 [TRUE] RFALSE
       INSERT_OBJ      "Mr. Baxter","Master Bedroom"
       STORE           G1d,#b2
       RFALSE          
L0005: JE              G1d,#de [FALSE] L0006
       JIN             "Ms. Dunbar","Dunbar's Bedroom" [FALSE] RFALSE
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [TRUE] RFALSE
       JE              G00,#af [TRUE] RFALSE
       STORE           G1c,#01
       STORE           G59,#00
       INSERT_OBJ      "wooden ladder","Orchard Path"
       CLEAR_ATTR      "wooden ladder",#19
       SET_ATTR        "wooden ladder",#1e
       INSERT_OBJ      "Mr. Baxter","Bedroom Balcony"
       STORE           G1d,#af
       RFALSE          
L0006: JIN             "Mr. Baxter","North Lawn" [FALSE] RFALSE
       STORE           G1d,#de
       RFALSE          

Routine R0372, 1 local (0000)

       JZ              G1a [TRUE] L0003
       STORE           G1a,#00
       JE              G00,#bb,#bd [FALSE] L0001
       PRINT           "As you enter the hallway, you catch a glimpse of
someone running across the eastern end of the hallway from south to north."
       NEW_LINE        
       STORE           L00,#01
       JUMP            L0003
L0001: JE              G00,#b2 [FALSE] L0002
       PRINT           "As you walk into the bedroom, you see Baxter running
past you to the balcony. He doesn't seem to have noticed you."
       NEW_LINE        
       STORE           L00,#01
       STORE           G19,#01
       JUMP            L0003
L0002: GET_PROP        G00,#0c -> -(SP)
       AND             (SP)+,#01 -> -(SP)
       JE              (SP)+,#01 [FALSE] L0003
       PRINT           "As you enter the hallway, you see Baxter running from
Dunbar's room across the hall to the master bedroom."
       NEW_LINE        
       STORE           L00,#01
       STORE           G19,#01
L0003: STORE           G1d,#af
       JE              G00,#e2,#ee,#de [FALSE] L0004
       RET             L00
L0004: INSERT_OBJ      "Mr. Baxter","In the Orchard"
       STORE           G1c,#00
       CALL            R0442 (#9d,#a7,#01) -> -(SP)
       CALL            R0004 (#a3ab,#00) -> -(SP)
       STORE           G1d,#00
       RET             L00

Routine R0373, 0 locals ()

       CALL            R0441 (#9d) -> -(SP)
       RFALSE          

Routine R0374, 0 locals ()

       CALL            R0442 (#97,#a7,#01) -> -(SP)
       CALL            R0442 (#95,#c1,#01) -> -(SP)
       CALL            R0442 (#99,#a7,#01) -> -(SP)
       CALL            R0004 (#a454,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           

Routine R0375, 1 local (0000)

       JIN             "Mrs. Robner","Dunbar's Bedroom" [FALSE] L0002
       JE              G00,#a7 [FALSE] L0001
       PRINT           "Mrs. Robner, standing quietly by the body, starts
sobbing and leaves the room."
       NEW_LINE        
L0001: CALL            R0441 (#97) -> -(SP)
       INSERT_OBJ      "Mrs. Robner","Hallway"
       STORE           L00,#01
       JUMP            L0006
L0002: JIN             "George","Dunbar's Bedroom" [FALSE] L0004
       JE              G00,#a7 [FALSE] L0003
       PRINT           "George says something like "My God" under his breath."
       NEW_LINE        
L0003: CALL            R0441 (#99) -> -(SP)
       JUMP            L0006
L0004: JIN             "Mrs. Rourke","Hallway" [FALSE] L0006
       JE              G00,#c1 [FALSE] L0005
       PRINT           "Mrs. Rourke peeks in the door and looks sick. "I'm
leaving this house," she says, and pops out again."
       NEW_LINE        
L0005: INSERT_OBJ      "Mrs. Rourke","Top of Stairs"
       CALL            R0442 (#95,#d6,#01) -> -(SP)
       STORE           L00,#01
L0006: INC_CHK         G18,#14 [FALSE] L0007
       CALL            R0004 (#a454,#00) -> -(SP)
       RET             L00
L0007: RET             L00

Routine R0376, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       TEST_ATTR       "smoking gun",#1e [FALSE] L0001
       PRINT_RET       "The pistol is bloody and has clearly been used
recently."
L0001: PRINT_RET       "The pistol has bloodstains on it. It has recently been
fired."

Routine R0377, 0 locals ()

       JE              Gb1,#2f [FALSE] L0001
       PRINT_RET       "The corpse is most gruesome. Ms. Dunbar was apparently
shot in the head at close range, leaving a most distasteful mess."
L0001: JE              Gb1,#62 [FALSE] RFALSE
       PRINT           "The body is still quite warm."
       RTRUE           

Routine R0378, 0 locals ()

       JE              Gb1,#32 [FALSE] L0002
       JE              G00,#a7 [FALSE] L0001
       PRINT_RET       "It doesn't seem to be around here."
L0001: PRINT_RET       "There isn't one here."
L0002: JE              Gb1,#15,#16 [TRUE] RFALSE
       PRINT_RET       "There is no pen to be seen here."

Routine R0379, 0 locals ()

       JE              Gb1,#86 [FALSE] RFALSE
       PRINT_RET       "The pen makes a mark in a fine blue line."

Routine R0380, 0 locals ()

       INC_CHK         G17,#04 [FALSE] L0001
       STORE           G16,#01
       CALL            R0004 (#a545,#00) -> -(SP)
       RFALSE          
L0001: JE              G00,#e4 [FALSE] RFALSE
       JE              G17,#01 [TRUE] L0002
       PRINT           "McNabb gives you a sideways glance. "What kept you?" he
asks."
       NEW_LINE        
L0002: CALL            R0281 -> -(SP)
       CALL            R0004 (#a545,#00) -> -(SP)
       RET_POPPED      

Routine R0381, 0 locals ()

       JE              Gb1,#87 [FALSE] RFALSE
       PRINT_RET       "Today is Friday, July 10."

Routine R0382, 0 locals ()

       JE              Gb1,#32,#5b [FALSE] RFALSE
       PRINT_RET       "Knowing the courts, it would take weeks to get one."

Routine R0383, 0 locals ()

       JE              Gb1,#4a [FALSE] RFALSE
       PRINT_RET       "You can see the west lawn through the window."

Routine R0384, 0 locals ()

       INSERT_OBJ      "Mr. Baxter","South Lawn"
       JE              G00,#f9 [FALSE] L0001
       PRINT_RET       "A limosine pulls up the drive. Mr. Baxter exits and the
limo pulls away. Baxter takes a deep breath and looks around."
L0001: JE              G00,#f6,#ee,#f0 [TRUE] L0002
       JE              G00,#f2,#f4 [FALSE] RFALSE
L0002: PRINT_RET       "A car pulls up the drive to the south, and Mr. Baxter
steps out onto the lawn."

Routine R0385, 0 locals ()

       INSERT_OBJ      "Mr. Coates","South Lawn"
       CALL            R0442 (#36,#ca,#01) -> -(SP)
       JE              G00,#f9 [FALSE] L0001
       PRINT_RET       "A large automobile pulls up the drive. Mr. Coates, the
lawyer, steps out of the car. "Oh, hello! You must be the Inspector. I'll be
reading the will at noon, you know. Don't be late!" he says."
L0001: JE              G00,#f6,#ee,#f0 [TRUE] L0002
       JE              G00,#f2,#f4 [FALSE] RFALSE
L0002: PRINT_RET       "A car pulls up the drive to the south, and Mr. Coates
steps out onto the lawn."

Routine R0386, 0 locals ()

       JE              Gb1,#2f,#4e,#5b [FALSE] RFALSE
       SET_ATTR        "bunch of crumpled papers",#1e
       SET_ATTR        "wastepaper basket",#1e
       RFALSE          

Routine R0387, 0 locals ()

       JE              Gb1,#32 [FALSE] RFALSE
       PRINT_RET       "Like a lurking grue in the dark places of the earth,
Sergeant Duffy is always near the scene of a crime. If you want something
analyzed, he will arrive in an instant to take the evidence to the lab. When
the results are available, he rushes them back to you. If you wish to arrest
someone, Duffy will be there with the handcuffs. A more dedicated civil servant
cannot be found."

Routine R0388, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The railing is made of a sturdy metal and helps prevent
nasty falls. There is a small area of paint scraped off the outside edge."

Routine R0389, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "This sturdy railing protects people on the balcony from
being impaled upon the exotic plants below. The railing itself is uniformly
painted."

Routine R0390, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The balcony itself is made of wood, except the railing
which is metal. The balcony is in good repair, but a few spots of dried mud
soil the floor."

Routine R0391, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The balcony is wooden, excepting the metal railing
surrounding it. It is in good repair and is quite clean."

Routine R0392, 1 local (0000)

       JE              Gb1,#40 [FALSE] L0003
       JE              G00,#b5 [FALSE] L0001
       PRINT_RET       "The wall to the north here sounds unusually hollow."
L0001: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0002
       PRINT_RET       "You're acting very strangely!"
L0002: PRINT_RET       "Knocking on the walls reveals nothing unusual."
L0003: JE              Gb1,#4a [FALSE] L0004
       JE              G00,#be [FALSE] L0004
       PRINT_RET       "From here, it looks quite ordinary."
L0004: JE              Gb1,#2f,#50 [FALSE] RFALSE
       GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0005
       STORE           L00,#0a
       JUMP            L0007
L0005: GET_PROP        G00,#0c -> -(SP)
       JZ              (SP)+ [TRUE] L0006
       STORE           L00,#03
       JUMP            L0007
L0006: GET_PROP        G00,#0a -> -(SP)
       ADD             #02,(SP)+ -> L00
L0007: PRINT           "An exhaustive search of even a single room would take
hours. A more productive approach would be to examine or search various items
of interest within the room. A cursory search would take on the order of "
       PRINT_NUM       L00
       PRINT           " minutes, but it wouldn't reveal much. Would you like
to do it anyway? (Y/N)"
       CALL            R0065 -> -(SP)
       JZ              (SP)+ [TRUE] L0009
       CALL            R0105 (L00) -> -(SP)
       JZ              (SP)+ [TRUE] L0008
       PRINT_RET       "Your brief search revealed nothing that was not obvious
before."
L0008: PRINT_RET       "You didn't get a chance to finish looking over the
room."
L0009: PRINT_RET       "Ok."

Routine R0393, 1 local (0000)

       JE              L00,#05 [FALSE] L0003
       CALL            R0317 (#36) -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       JUMP            L0002
L0001: PRINT           "Mr. Coates is here."
       NEW_LINE        
L0002: CALL            R0354 (#36) -> -(SP)
       RET_POPPED      
L0003: JE              Ga8,#36 [FALSE] L0004
       JE              Gb1,#32 [TRUE] RFALSE
       CALL            R0397 (#36) -> -(SP)
       JZ              (SP)+ [FALSE] RTRUE
       CALL            R0002 (G61) -> -(SP)
       PRINT_PADDR     (SP)+
       NEW_LINE        
       RTRUE           
L0004: JE              Gb1,#1e [FALSE] L0007
       PRINT_OBJ       Gaf
       JG              G76,#02c6 [FALSE] L0005
       PRINT_RET       "'s office phone rings. His secretary answers and
informs you that he will be out for the rest of the day."
L0005: JG              G76,#028a [FALSE] L0006
       PRINT_RET       "'s secretary answers and informs you that Mr. Coates is
on his way to the Robner estate."
L0006: PRINT_RET       "'s secretary informs you that Mr. Coates is in a very
important meeting and can't be disturbed. She reminds you that he will be at
the Robner estate before noon."
L0007: JE              Gb1,#15 [FALSE] RFALSE
       JE              Gaf,#36 [FALSE] RFALSE
       JE              Gb0,#83,#82 [TRUE] L0008
       JE              Gb0,#80,#87 [FALSE] L0009
L0008: PRINT_RET       ""I am not at liberty to discuss Mr. Robner's legal
matters. That is privileged information between attorney and client.""
L0009: PRINT_RET       ""I am sorry, but I can't help you there.""

Routine R0394, 0 locals ()

       JE              Gb1,#5b [FALSE] RFALSE
       SET_ATTR        "handwritten envelope",#1e
       RFALSE          

Routine R0395, 0 locals ()

       JE              Gb1,#14 [FALSE] RFALSE
       JL              G76,#0258 [FALSE] L0001
       PRINT_RET       "It is rather early in the case to be making hasty
judgments."
L0001: LOADW           G92,#01 -> -(SP)
       JE              (SP)+,#9d,#9c [FALSE] L0002
       LOADW           G92,#02 -> -(SP)
       JE              (SP)+,#9b,#9a [TRUE] L0003
L0002: LOADW           G92,#01 -> -(SP)
       JE              (SP)+,#9b,#9a [FALSE] L0012
       LOADW           G92,#02 -> -(SP)
       JE              (SP)+,#9d,#9c [FALSE] L0012
L0003: JZ              G6c [TRUE] L0004
       PRINT           "Ms. Dunbar is dead!"
       NEW_LINE        
       JUMP            L0011
L0004: JZ              G1b [TRUE] L0005
       PRINT           "Sergeant Duffy rushes into view. "Ms. Dunbar is dead!
She has shot herself in her room! Come quickly!" He dashes off."
       NEW_LINE        
       JUMP            L0011
L0005: TEST_ATTR       "stack of papers",#1e [FALSE] L0006
       TEST_ATTR       "lab report",#1e [FALSE] L0006
       JZ              G5d [TRUE] L0006
       JZ              G27 [TRUE] L0006
       NEW_LINE        
       CALL            R0424 (S173) -> -(SP)
       PRINT           "Congratulations on your superb handling of the Robner
case. As you have probably heard, a jury convicted Mr. Baxter and Ms. Dunbar
today of the murder of Mr. Robner. Thanks to you, the murderers will be behind
bars, possibly for the rest of their lives. Thanks for a job brilliantly done.
Which reminds me of another fascinating case I would like to assign you to...

Coming soon: Another INTERLOGIC Mystery from Infocom
"
       NEW_LINE        
       CALL            R0396 -> -(SP)
       JUMP            L0011
L0006: JL              G76,#02bc [FALSE] L0007
       PRINT           "You realize the arrest would be a trifle premature,
since you're not even sure that a murder was committed."
       NEW_LINE        
       JUMP            L0011
L0007: TEST_ATTR       "lab report",#1e [TRUE] L0008
       NEW_LINE        
       CALL            R0424 (S174) -> -(SP)
       PRINT           "The District Attorney has decided not to seek an
indictment in the Robner case. He points out that it has never been proven that
a murder was committed, despite the deep suspicions to the contrary. Thanks for
your help on this case. It's too bad we couldn't find out more about the
circumstances surrounding the death of Mr. Robner.

"
       JUMP            L0011
L0008: TEST_ATTR       "stack of papers",#1e [TRUE] L0009
       NEW_LINE        
       CALL            R0424 (S175) -> -(SP)
       PRINT           "A grand jury looking into the death of Mr. Robner has
decided not to indict the accused. They felt that the lack of motive as well as
the contorted hypothesis involving the actual mechanism of the murder of Mr.
Robner was not convincing. Personally, I think you're on the right track, but I
must admit that the evidence is meager. Thank you for helping in the case.

"
       JUMP            L0011
L0009: JZ              G5d [FALSE] L0010
       NEW_LINE        
       CALL            R0424 (S176) -> -(SP)
       PRINT           "The jury in the Robner case has declined to convict Mr.
Baxter and Ms. Dunbar. Appearances indicate that the verdict was difficult, and
that several jury members were convinced that the two were guilty. However, no
evidence was presented directly relating the Focus case with the murder of Mr.
Robner. This left the question of motive unresolved. I appreciate your efforts
in the case and am sorry to report this outcome to you.

"
       JUMP            L0011
L0010: NEW_LINE        
       CALL            R0424 (S177) -> -(SP)
       PRINT           "The jury in the Robner case has declined to convict Mr.
Baxter and Ms. Dunbar. Although most of the jury was convinced of their guilt,
it seems that one or two felt there was some reasonable doubt about the
proposed conspiracy. Their main concern was the lack of evidence that Baxter
was near the grounds on the night of the murder. His alibi of having been to
the symphony was confirmed by several people. Although this doesn't mean that
he didn't go back to the Robner estate later, it nevertheless was not
convincing. Thank you for your excellent efforts. It is sad to think that we
may have let the murderers slip between our fingers.

"
L0011: CALL            R0431 -> -(SP)
       RET_POPPED      
L0012: LOADW           G92,#01 -> -(SP)
       JE              (SP)+,#9d,#9c [FALSE] L0013
       LOADW           G92,#02 -> -(SP)
       JE              (SP)+,#99,#98 [TRUE] L0014
L0013: LOADW           G92,#01 -> -(SP)
       JE              (SP)+,#99,#98 [FALSE] L0018
       LOADW           G92,#02 -> -(SP)
       JE              (SP)+,#9d,#9c [FALSE] L0018
L0014: TEST_ATTR       "lab report",#1e [TRUE] L0015
       PRINT_RET       "You realize that there is no evidence that a murder has
been committed and decide not to go ahead with the arrest."
L0015: JZ              G45 [FALSE] L0016
       JZ              G48 [TRUE] L0017
L0016: TEST_ATTR       "stack of papers",#1e [FALSE] L0017
       JZ              G5d [TRUE] L0017
       NEW_LINE        
       CALL            R0424 (S178) -> -(SP)
       PRINT           " The district attorney, after extensive interrogation
of George Robner and Mr. Baxter, has declined to seek an indictment against
them. He agrees that there has been foul play in the death of Mr. Robner and
that both suspects have motives for the crime. However, no coherent theory
could be proposed which involved the two of them conspiring to murder Mr.
Robner. On the other hand, it seems unlikely that either of them alone could
have committed the crime. I am sorry that your work has gone for naught.

"
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0017: NEW_LINE        
       CALL            R0424 (S179) -> -(SP)
       PRINT           "The district attorney has declined to indict George
Robner and Mr. Baxter in the death of Marshall Robner, noting that there is no
link between the accused, except hatred, and that all of the evidence is
circumstantial. I wish you luck on your future cases.

"
       CALL            R0431 -> -(SP)
       RET_POPPED      
L0018: PRINT_RET       "You realize that this arrest is quite farfetched and
would result only in your humiliation."

Routine R0396, 0 locals ()

       NEW_LINE        
       PRINT           "You have solved the case! If you would like, you may
see the author's summary of the story. We would advise you to come up with your
own first! Would you like to see the author's summary? (Y/N)"
       CALL            R0065 -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       NEW_LINE        
       PRINT           "Mr. Robner's work was his life, as pointed out by a
number of the principals. George knew that his father had lost control of the
company, and a story in the newspaper indicated that Baxter intended to sell
the company to a multi-national conglomerate, presumably to advance his career.
Baxter admitted to the merger plans, but indicated that Mr. Robner was in
complete agreement. This is contrary to what George and Mrs. Robner said. The
note pad found in the library was Robner's last, desperate attempt to save the
company, in which Robner threatened to expose Baxter's involvement in the Focus
scandal. Baxter denied getting the note, but it was not in the trash. The
papers detailing Baxter's criminality in the scandal were kept locked in a safe
in a hidden closet near the library. Only George and Marshall Robner knew the
whereabouts of the safe.
  Baxter planned to murder his partner, aided by the fact that Robner was known
to be depressed, even suicidal. He enlisted the help of his lover, Dunbar, one
of whose medicines was found to interact fatally with the pills Robner was
taking. The relationship of Baxter and Dunbar was kept quiet, although Mrs.
Rourke had an inkling of it. After the concert in Hartford which both Baxter
and Dunbar attended, they returned to the Robner estate. Dunbar placed some
LoBlo in Robner's tea. After Robner died, Baxter used the ladder from the shed
to enter the library and exchange the incriminating cup for a clean one
(counting the china in the kitchen reveals that a cup is missing). Coming down
the ladder, Baxter presumably dropped the cup and inadvertently left one piece
on the ground in the rose garden, near the ladder holes that McNabb found while
tending his roses.

"
L0001: QUIT            

Routine R0397, 1 local (0000)

       JE              Gb1,#87 [FALSE] L0001
       STORE           Ga8,#a0
       CALL            R0010 (#15,L00,Gaf) -> -(SP)
       RTRUE           
L0001: JE              Gb1,#2f [FALSE] L0002
       STORE           Ga8,#a0
       CALL            R0010 (#69,L00,Gaf) -> -(SP)
       RTRUE           
L0002: JE              Gb1,#72 [FALSE] L0003
       JE              Gaf,#a0 [FALSE] L0003
       STORE           Ga8,#a0
       CALL            R0010 (#15,L00,Gb0) -> -(SP)
       RTRUE           
L0003: JE              Gb1,#69 [FALSE] L0004
       JE              Gaf,#a0 [FALSE] L0004
       PRINT_RET       ""I'm sure you can find it, Inspector.""
L0004: JE              Gb1,#35 [FALSE] RFALSE
       JE              Gaf,#a0 [FALSE] RFALSE
       PRINT_RET       ""I would rather not.""

Routine R0398, 0 locals ()

       JE              Gb1,#2f [FALSE] L0001
       PRINT_RET       "There are five portraits: two on each side of and one
above the bay window. The fading portraits are of members of the Phillips
family, among the oldest in New England."
L0001: JE              Gb1,#5b [FALSE] RFALSE
       CALL            R0406 -> -(SP)
       RET_POPPED      

Routine R0399, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The cabinets are beautifully handworked walnut and
mahogany."

Routine R0400, 0 locals ()

       JE              Gb1,#2f [FALSE] L0001
       PRINT_RET       "The painting by Seurat is a cheerful design which suits
the bright decor of the dining room. It must be worth a fortune."
L0001: JE              Gb1,#5b [FALSE] RFALSE
       CALL            R0406 -> -(SP)
       RET_POPPED      

Routine R0401, 0 locals ()

       JE              Gb1,#2f [FALSE] L0001
       PRINT_RET       "The paintings are by various artists. They are brightly
colored (but not overly loud) works of cheerful outdoor scenes and still-lifes.
They give the room a light and pleasant feel."
L0001: JE              Gb1,#5b [FALSE] RFALSE
       CALL            R0406 -> -(SP)
       RET_POPPED      

Routine R0402, 0 locals ()

       JE              Gb1,#7d,#5b [FALSE] RFALSE
       PRINT_RET       "The appliances here are useful in preparing meals,
cleaning dishes, and the like. It is unlikely that Mrs. Rourke would like you
using them."

Routine R0403, 0 locals ()

       RFALSE          

Routine R0404, 0 locals ()

       JE              Gb1,#5b [FALSE] L0001
       PRINT_RET       "Although the set would make a fine addition to your
home, you resist the temptation. You would never get away with it anyway, as
Mrs. Robner will no doubt count the silverware upon your departure."
L0001: JE              Gb1,#25 [FALSE] L0002
       PRINT_RET       "There are 16 complete sets of silver."
L0002: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The silver is of the finest quality and design."

Routine R0405, 0 locals ()

       JE              Gb1,#25 [FALSE] L0001
       PRINT_RET       "There are at least two dozen."
L0001: JE              Gb1,#5b [FALSE] RFALSE
       CALL            R0406 -> -(SP)
       RET_POPPED      

Routine R0406, 0 locals ()

       PRINT_RET       "You would be an impolite guest to fool with these
things without cause."

Routine R0407, 0 locals ()

       JE              Gb1,#2b [FALSE] RFALSE
       PRINT_RET       "Although manners are not taught at the Academy, surely
your mother must have given you some sense of proper behavior."

Routine R0408, 0 locals ()

       JE              Gb1,#5b,#2b,#5a [FALSE] RFALSE
       PRINT_RET       "The fruits are not abundant, and those within reach are
far from ripe."

Routine R0409, 0 locals ()

       JE              Gb1,#5b,#2b,#5a [FALSE] RFALSE
       PRINT_RET       "You pick a few berries and pop them into your mouth.
Delicious!"

Routine R0410, 0 locals ()

       JE              Gb1,#58 [FALSE] L0001
       PRINT_RET       "Don't you know it's bad luck to break mirrors?"
L0001: JE              Gb1,#4a [FALSE] RFALSE
       PRINT_RET       "A weary Police Inspector looks back at you, with a look
that seems to be saying "Look what the cat dragged in.""

Routine R0411, 0 locals ()

       PRINT_RET       "You can't reach the tree tops from here."

Routine R0412, 0 locals ()

       JE              Gb1,#29 [FALSE] RFALSE
       JZ              G14 [TRUE] L0001
       PRINT_RET       "It's one thing to take a bracer on occasion, but you
must resist the temptation to indulge too often."
L0001: PRINT           "You take a small swig of the golden fluid, which burns
as it goes down."
       NEW_LINE        
       STORE           G14,#01
       RTRUE           

Routine R0413, 0 locals ()

       JE              Gb1,#44 [FALSE] L0001
       PRINT           "The stereo is now on."
       NEW_LINE        
       STORE           G13,#01
       RTRUE           
L0001: JE              Gb1,#30 [FALSE] L0004
       JZ              G12 [TRUE] L0002
       JIN             "George",G00 [FALSE] L0002
       PRINT           "George turns toward you in disgust as you turn off the
"
       PRINT_PADDR     G12
       PRINT           "."
       NEW_LINE        
       JUMP            L0003
L0002: PRINT           "The stereo is now off."
       NEW_LINE        
L0003: STORE           G13,#00
       STORE           G12,#00
       RTRUE           
L0004: JE              Gb1,#79 [FALSE] L0006
       JZ              G12 [TRUE] L0005
       PRINT           "The "
       PRINT_PADDR     G12
       PRINT_RET       " is already quite loud. Any louder would probably
disturb the rest of the house."
L0005: PRINT_RET       "It's not on!"
L0006: JE              Gb1,#7a [FALSE] L0009
       JZ              G12 [TRUE] L0008
       JIN             "George",G00 [FALSE] L0007
       PRINT           "George stops you from turning down the volume. He is
practically addicted to the "
       PRINT_PADDR     G12
       PRINT_RET       "."
L0007: PRINT_RET       "You can't."
L0008: PRINT_RET       "It's not on!"
L0009: JE              Gb1,#45 [FALSE] RFALSE
       JZ              G12 [TRUE] L0010
       PRINT_RET       "You can hardly avoid it."
L0010: PRINT_RET       "Nothing's playing."

Routine R0414, 0 locals ()

       JE              Gb1,#45,#56 [FALSE] L0001
       PRINT           "You pick a record at random and start it playing. It is
a "
       CALL            R0002 (G11) -> G12
       PRINT_PADDR     G12
       PRINT           "."
       NEW_LINE        
       CALL            R0004 (#b2da,#14) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           
L0001: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "This is a large collection, with many different types
of music represented. George is evidently not very particular when it comes to
music."

Routine R0415, 0 locals ()

       JE              Gb1,#45,#56 [FALSE] L0001
       PRINT           "You pick one at random and start it up. What you hear
is a "
       CALL            R0002 (G10) -> G12
       CALL            R0004 (#b2da,#1e) -> -(SP)
       STOREW          (SP)+,#00,#01
       PRINT_PADDR     G12
       PRINT_RET       "."
L0001: JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "George's collection of tapes is large and quite odd in
its variety of music."

Routine R0416, 1 local (0000)

       JE              G00,#a4 [FALSE] L0003
       PRINT           "The "
       PRINT_PADDR     G12
       PRINT           " has ended (and not soon enough)."
       NEW_LINE        
       JIN             "George",G00 [FALSE] RTRUE
       PRINT           "George walks over to his stereo and returns the music
to its proper place. He then chooses a "
       RANDOM          #64 -> -(SP)
       JG              #32,(SP)+ [FALSE] L0001
       PRINT           "record"
       STORE           L00,G11
       JUMP            L0002
L0001: PRINT           "tape"
       STORE           L00,G10
L0002: PRINT           " from his large collection and starts it up. Dear Lord!
It's a "
       CALL            R0002 (L00) -> G12
       PRINT_PADDR     G12
       PRINT           "."
       NEW_LINE        
       CALL            R0004 (#b2da,#19) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           
L0003: JIN             "George","George's Bedroom" [FALSE] RFALSE
       CALL            R0002 (G10) -> G12
       CALL            R0004 (#b2da,#23) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          

Routine R0417, 0 locals ()

       JE              Gb1,#7d,#55,#5b [FALSE] L0001
       PRINT_RET       "You have no need for them."
L0001: JE              Gb1,#2f,#50 [FALSE] RFALSE
       PRINT           "You go through the"
       CALL            R0046 -> -(SP)
       PRINT_RET       " and find nothing of interest."

Routine R0418, 0 locals ()

       JE              Gb1,#4b [FALSE] L0001
       PRINT_RET       "The carpeting is wall-to-wall so you can't look under
it."
L0001: JE              Gb1,#2f [FALSE] RFALSE
       PRINT           "The carpet is an expensive affair, and quite clean,
except for a few small areas of dried mud in the vicinity of the desk. There
are no other stains or markings that you can see."
       NEW_LINE        
       CLEAR_ATTR      "mud spots",#1f
       RTRUE           

Routine R0419, 1 local (0000)

       JE              Gb1,#15 [FALSE] RFALSE
       JE              Gb0,#89 [FALSE] L0001
       GET_PROP        Gaf,#07 -> -(SP)
       LOADW           G0f,(SP)+ -> L00
       JZ              L00 [TRUE] RFALSE
       PRINT_PADDR     L00
       NEW_LINE        
       RTRUE           
L0001: PRINT_RET       ""I told everything I know about it to the other
detectives.""

Routine R0420, 0 locals ()

       JE              Gb1,#4a [FALSE] L0001
       PRINT           "From here you have a good view of the east lawn, a
shed, and the lake in the background."
       NEW_LINE        
       PUT_PROP        "Guest Room",#0c,#0200
       CALL            R0207 -> -(SP)
       CALL            R0004 (#b3f7,#02) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           
L0001: JE              Gb1,#59 [FALSE] RFALSE
       PRINT_RET       "This window cannot be opened."

Routine R0421, 0 locals ()

       PUT_PROP        "Guest Room",#0c,#00
       RFALSE          

Routine R0422, 0 locals ()

       JIN             "Mrs. Robner",G00 [FALSE] L0001
       PRINT           "Mrs. Robner turns to you. "I don't understand why you
missed the will reading. You seem so interested in everything else that goes on
around here.""
       NEW_LINE        
       CALL            R0004 (#b3fb,#00) -> -(SP)
       RET_POPPED      
L0001: JIN             "Mr. Coates",G00 [FALSE] RFALSE
       PRINT           "Mr. Coates says, in passing, "To tell you the truth,
Inspector, my suspicions about this case are not quite allayed. I wish you had
been at the will reading. Good day.""
       NEW_LINE        
       CALL            R0004 (#b3fb,#00) -> -(SP)
       RET_POPPED      

Routine R0423, 0 locals ()

       JE              Gb1,#2f [FALSE] RFALSE
       PRINT_RET       "The shelves contain various garden tools."

Routine R0424, 1 local (0000)

       PRINT           "Text of a letter from Police Commissioner Klutz dated "
       PRINT_PADDR     L00
       PRINT           ":

Dear Inspector,

    "
       RTRUE           

Routine R0425, 2 locals (0000, 0000)

       JE              Gb1,#15,#87 [FALSE] RFALSE
       GET_CHILD       G00 -> L01 [TRUE] L0001
L0001: JZ              L01 [FALSE] L0002
       JUMP            L0005
L0002: TEST_ATTR       L01,#14 [FALSE] L0003
       JE              L01,#a0 [TRUE] L0003
       STORE           L00,#01
       CALL            R0060 (L01,#01,#00) -> -(SP)
L0003: GET_SIBLING     L01 -> L01 [TRUE] L0004
L0004: JUMP            L0001
L0005: JZ              L00 [FALSE] RTRUE
       PRINT_RET       "There's nobody else here."

Routine R0426, 0 locals ()

       JE              Gb1,#3b [FALSE] L0005
       TEST_ATTR       Gaf,#1c [TRUE] L0001
       PRINT           "You open the balcony door carefully."
       NEW_LINE        
       SET_ATTR        Gaf,#1c
L0001: JE              G00,#b9 [FALSE] L0002
       CALL            R0110 (#b6) -> -(SP)
       RTRUE           
L0002: JE              G00,#b6 [FALSE] L0003
       CALL            R0110 (#b9) -> -(SP)
       RTRUE           
L0003: JE              G00,#b2 [FALSE] L0004
       CALL            R0110 (#af) -> -(SP)
       RTRUE           
L0004: CALL            R0110 (#b2) -> -(SP)
       RTRUE           
L0005: JE              Gb1,#4a [FALSE] RFALSE
       JE              G00,#b2,#b9 [FALSE] L0006
       PRINT_RET       "You can see the balcony, but not much beyond."
L0006: JE              G00,#b6 [FALSE] L0007
       PRINT_RET       "You can see into the library from here."
L0007: PRINT_RET       "You can see the bedroom from here."

Routine R0427, 0 locals ()

       JIN             "George","Dining Room" [FALSE] L0002
       JE              Gb1,#55,#5b,#2b [FALSE] L0001
       PRINT_RET       "You reach for the juicy herrings, but George forces you
away. He is a killer where herrings are concerned."
L0001: JE              Gb1,#32 [FALSE] RFALSE
       PRINT_RET       "There are more in this room than elsewhere."
L0002: JE              Gb1,#32 [FALSE] L0003
       PRINT_RET       "They're all around you."
L0003: JE              Gb1,#87 [FALSE] RFALSE
       PRINT_RET       "That would be telling."

Routine R0428, 0 locals ()

       JE              Gb1,#4a [FALSE] RFALSE
       PRINT_RET       "There's nothing of interest in the desk."

Routine R0429, 0 locals ()

       JE              Gb1,#16 [FALSE] L0001
       JE              Gaf,#9d [FALSE] L0001
       CLEAR_ATTR      Gb0,#19
       RFALSE          
L0001: JE              Gb1,#5b [FALSE] L0002
       JIN             "mystery book","Mr. Baxter" [FALSE] L0002
       CLEAR_ATTR      Gaf,#19
       RFALSE          
L0002: JE              Gb1,#2f [FALSE] L0003
       PRINT_RET       "This is a novelization of DEADLINE, a classic work of
computer fiction."
L0003: JE              Gb1,#59,#4e [FALSE] RFALSE
       PRINT_RET       "The book is a novelization of DEADLINE. You start to
read it, and it seems oddly familiar, as if you had lived it."

Routine R0430, 0 locals ()

       JIN             "mystery book","player" [FALSE] L0001
       JE              Gb1,#78,#87,#4e [FALSE] RFALSE
       PRINT           "You thumb to the last page and start to read the
ending, in which the protagonist reads the plot of the story and kills himself
in disgust. Disgustedly, you reach into your pocket, remove a gun, and end your
life."
       NEW_LINE        
       QUIT            
       RTRUE           
L0001: JE              Gb1,#87 [FALSE] L0002
       PRINT_RET       "That's up to you!"
L0002: PRINT_RET       "You don't have the book that tells the ending."

Routine R0431, 0 locals ()

       NEW_LINE        
       NEW_LINE        
       PRINT           "The case has ended. Would you like to start your
investigation over from scratch? (Y/N)"
       CALL            R0065 -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       RESTART         
       RTRUE           
L0001: QUIT            

Routine R0432, 0 locals ()

       JE              Gb1,#59 [FALSE] L0001
       TEST_ATTR       "safe",#1c [TRUE] L0001
       PRINT_RET       "The safe is locked."
L0001: JE              Gb1,#46,#23 [FALSE] L0002
       TEST_ATTR       "safe",#1c [FALSE] L0002
       PRINT           "The safe closes and locks."
       NEW_LINE        
       CLEAR_ATTR      "safe",#1c
       RTRUE           
L0002: JE              Gb1,#46 [FALSE] L0003
       PRINT_RET       "It already is."
L0003: JE              Gb1,#7b [FALSE] L0004
       PRINT_RET       "You don't know the combination."
L0004: JE              Gb1,#2f,#4a [FALSE] RFALSE
       CLEAR_ATTR      "stack of papers",#1f
       RFALSE          

Routine R0433, 0 locals ()

       JE              Gb1,#10 [FALSE] RFALSE
       PRINT_RET       "The handwriting is very shaky and would be impossible
to compare with samples on file. The blood makes the finding of fingerprints
impossible."

Routine R0434, 0 locals ()

       JE              Gb1,#35 [FALSE] L0001
       PRINT_RET       "Is this what they call a death wish?"
L0001: JE              Gb1,#1d [FALSE] RFALSE
       PRINT_RET       "You are, for the moment, not with him."

Routine R0435, 0 locals ()

       JE              Gb1,#32,#2b [FALSE] L0001
       PRINT_RET       "Although rather hungry, you realize that the case is
too important for you to be eating meals."
L0001: PRINT_RET       "What a strange notion!"

Routine R0436, 0 locals ()

       JE              Gb1,#83 [FALSE] RFALSE
       PRINT_RET       "Use directions to move around inside the house."

Routine R0437, 0 locals ()

       JE              Gb1,#2b [FALSE] RFALSE
       PRINT_RET       "You pick a few grapes and eat them. Mmmm!"

Routine R0438, 0 locals ()

       JE              Gb1,#45 [FALSE] L0001
       JZ              G1f [TRUE] L0001
       JE              G00,#e8,#ee [FALSE] L0001
       PRINT_RET       "The voices from within the shed are too quiet to make
out."
L0001: JE              Gb1,#45 [FALSE] L0002
       JZ              G3f [TRUE] L0002
       JE              G00,#c1 [FALSE] L0002
       PRINT_RET       "You can't make out the conversation through the door."
L0002: JE              Gb1,#45 [FALSE] RFALSE
       PRINT_RET       "You can't hear any conversation."

Routine R0439, 0 locals ()

       JE              Gb1,#5b [FALSE] RFALSE
       JE              Gaf,#6d [FALSE] RFALSE
       JZ              Gb0 [FALSE] L0001
       PRINT_RET       "You must specify what to take the fingerprints from."
L0001: CALL            R0010 (#33,Gb0) -> -(SP)
       RTRUE           

Routine R0440, 0 locals ()

       JE              G00,#b6 [FALSE] L0001
       JZ              G59 [FALSE] L0002
L0001: JE              G00,#af [FALSE] RFALSE
       JZ              G1c [TRUE] RFALSE
L0002: JE              Gb1,#5b [FALSE] L0003
       PRINT_RET       "It's too difficult from here."
L0003: JE              Gb1,#62 [TRUE] RFALSE
       JE              Gb1,#2f [FALSE] L0004
       PRINT_RET       "The top of the ladder is visible, but the rest is hard
to see."
L0004: PRINT_RET       "You can't do that from here."

Routine R0441, 2 locals (0000, 0000)

       GET_PROP        L00,#07 -> -(SP)
       LOADW           G08,(SP)+ -> L01
       STOREW          L01,#05,#00
       LOADW           L01,#06 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       LOADW           L01,#06 -> -(SP)
       CALL            R0442 (L00,(SP)+) -> -(SP)
       STOREW          L01,#06,#00
       RTRUE           

Routine R0442, 8 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000)

       GET_PARENT      L00 -> L03
       GET_PROP        L00,#07 -> -(SP)
       LOADW           G08,(SP)+ -> L06
       JZ              L02 [TRUE] L0001
       STOREW          L06,#04,#01
       STOREW          L06,#05,#01
       STOREW          L06,#06,L03
L0001: GET_PROP        L03,#0e -> L04
       GET_PROP        L01,#0e -> L05
       JE              L04,L05 [FALSE] L0002
       STOREW          L06,#02,#00
       JUMP            L0008
L0002: JE              L04,#00 [FALSE] L0003
       STOREW          L06,#02,#c2
       JUMP            L0008
L0003: JE              L04,#02 [FALSE] L0004
       STOREW          L06,#02,#f6
       JUMP            L0008
L0004: JE              L04,#03 [FALSE] L0005
       STOREW          L06,#02,#c6
       JUMP            L0008
L0005: JE              L05,#00 [FALSE] L0006
       STOREW          L06,#02,#cc
       JUMP            L0008
L0006: JE              L05,#03 [FALSE] L0007
       STOREW          L06,#02,#dc
       JUMP            L0008
L0007: STOREW          L06,#02,#dd
L0008: GET_PROP        L01,#0d -> -(SP)
       STOREW          L06,#01,(SP)+
       STOREW          L06,#00,L01
       GET_PARENT      L00 -> -(SP)
       RET_POPPED      

Routine R0443, 13 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000,
                          0000, 0000, 0001, 0000)

       GET_PARENT      L00 -> L01
       GET_PROP        L00,#07 -> -(SP)
       LOADW           G08,(SP)+ -> L05
       LOADW           L05,#00 -> -(SP)
       JE              L01,(SP)+ [FALSE] L0001
       CALL            R0444 (L00) -> L07
       STOREW          L05,#01,#00
       RET             L07
L0001: LOADW           L05,#04 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       GET_PROP        L01,#0d -> L0a
       JE              L0a,L01 [TRUE] L0002
       CALL            R0445 (L00,L0a) -> -(SP)
       RET_POPPED      
L0002: LOADW           L05,#02 -> L06
       JZ              L06 [TRUE] L0003
       STORE           L09,#01
       JUMP            L0004
L0003: LOADW           L05,#01 -> L06
L0004: JZ              L06 [TRUE] RFALSE
       JE              L01,#cb [FALSE] L0005
       LOADW           L05,#00 -> -(SP)
       CALL            R0449 (L00,L01,(SP)+) -> -(SP)
       RET_POPPED      
L0005: JE              L01,L06 [FALSE] L0009
       JZ              L09 [TRUE] L0006
       LOADW           L05,#00 -> -(SP)
       CALL            R0449 (L00,L06,(SP)+) -> -(SP)
       RET_POPPED      
L0006: LOADW           L05,#00 -> -(SP)
       JE              L01,(SP)+ [TRUE] L0008
       LOADW           L05,#00 -> -(SP)
       CALL            R0445 (L00,(SP)+) -> L07
       STOREW          L05,#01,#00
       JZ              L07 [TRUE] L0007
       CALL            R0444 (L00) -> -(SP)
       RET             L07
L0007: CALL            R0444 (L00) -> L07
       RET             L07
L0008: STOREW          L05,#01,#00
       CALL            R0444 (L00) -> -(SP)
       RET_POPPED      
L0009: GET_PROP        L06,#0e -> L03
       JE              L03,#00 [FALSE] L0010
       PUSH            G0d
       JUMP            L0013
L0010: JE              L03,#01 [FALSE] L0011
       PUSH            G0c
       JUMP            L0013
L0011: JE              L03,#03 [FALSE] L0012
       PUSH            G0a
       JUMP            L0013
L0012: PUSH            G0b
L0013: STORE           L02,(SP)+
L0014: LOADW           L02,L0b -> L04
       JE              L04,L01 [FALSE] L0017
       JZ              L08 [TRUE] L0015
       SUB             L0b,#03 -> -(SP)
       LOADW           L02,(SP)+ -> L0a
       JUMP            L0016
L0015: ADD             L0b,#03 -> -(SP)
       LOADW           L02,(SP)+ -> L0a
L0016: CALL            R0445 (L00,L0a) -> -(SP)
       RET             (SP)+
L0017: JE              L04,L06 [FALSE] L0018
       STORE           L08,#01
L0018: ADD             L0b,#03 -> L0b
       JUMP            L0014

Routine R0444, 1 local (0000)

       GET_PROP        L00,#07 -> -(SP)
       LOADW           G08,(SP)+ -> -(SP)
       LOADW           (SP)+,#07 -> -(SP)
       CALL            (SP)+ (#01) -> -(SP)
       RET_POPPED      

Routine R0445, 13 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000,
                          0000, 0000, 0000, 0000)

       GET_PROP        L00,#07 -> L07
       LOADW           G08,L07 -> L03
       STORE           L08,L07
       GET_PARENT      L00 -> L04
       CALL            R0446 (L04,L01) -> L02
       GET_PROP_ADDR   L04,L02 -> L0c
       GET_PROP_LEN    L0c -> -(SP)
       JE              (SP)+,#05 [FALSE] L0002
       LOADB           L0c,#01 -> L0c
       TEST_ATTR       L0c,#1c [TRUE] L0001
       SET_ATTR        L0c,#1c
       JUMP            L0003
L0001: STORE           L0c,#00
       JUMP            L0003
L0002: STORE           L0c,#00
L0003: STOREW          L03,#03,L02
       JE              L04,G00 [FALSE] L0010
       STORE           L0b,#01
       PRINT_OBJ       L00
       JE              L02,#14 [FALSE] L0004
       PRINT           " walks out of the room."
       NEW_LINE        
       JUMP            L0028
L0004: JE              L02,#16 [FALSE] L0005
       PRINT           " is going downstairs."
       NEW_LINE        
       JUMP            L0028
L0005: JE              L02,#17 [FALSE] L0006
       PRINT           " is going upstairs."
       NEW_LINE        
       JUMP            L0028
L0006: JE              L02,#15 [FALSE] L0008
       JZ              L0c [TRUE] L0007
       PRINT           " opens the "
       PRINT_OBJ       L0c
       PRINT           " and"
L0007: PRINT           " goes into another room."
       JUMP            L0028
L0008: JZ              L0c [TRUE] L0009
       PRINT           " opens the "
       PRINT_OBJ       L0c
       PRINT           " and"
L0009: PRINT           " heads off to "
       CALL            R0450 (L02) -> -(SP)
       PRINT           "."
       NEW_LINE        
       JUMP            L0028
L0010: JE              L01,G00 [FALSE] L0013
       STORE           L0b,#01
       PRINT_OBJ       L00
       LOADW           L03,#00 -> -(SP)
       JE              G00,(SP)+ [TRUE] L0011
       PRINT           " is walking past you."
       NEW_LINE        
       JUMP            L0028
L0011: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0012
       PRINT           " stops here."
       NEW_LINE        
       JUMP            L0028
L0012: PRINT           " steps into the room."
       NEW_LINE        
       JUMP            L0028
L0013: GET_PROP        G00,#0c -> L05
       JZ              L05 [TRUE] L0028
       GET_PROP        L04,#0c -> L06
       JZ              L06 [TRUE] L0024
       AND             L05,L06 -> -(SP)
       JZ              (SP)+ [TRUE] L0024
       STORE           L0b,#01
       JE              L01,#cb [FALSE] L0014
       PRINT_OBJ       L00
       PRINT           " steps onto the stairs."
       NEW_LINE        
       JUMP            L0028
L0014: GET_PROP        L01,#0c -> -(SP)
       JZ              (SP)+ [FALSE] L0019
       PRINT_OBJ       L00
       PRINT           ", off to "
       CALL            R0447 (G00,L04) -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           ","
       JZ              L0c [TRUE] L0015
       PRINT           " opens a door and"
L0015: GET_PROP        G00,#0e -> -(SP)
       JE              (SP)+,#02 [FALSE] L0016
       PRINT           " leaves your view"
       JUMP            L0018
L0016: JE              L01,#e9 [FALSE] L0017
       PRINT           " darts into the shed"
       JUMP            L0018
L0017: PRINT           " ducks into a room"
L0018: PRINT           " to "
       CALL            R0446 (L04,L01) -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           "."
       NEW_LINE        
       JUMP            L0028
L0019: GET_PROP        L01,#0c -> -(SP)
       AND             L05,(SP)+ -> -(SP)
       JZ              (SP)+ [FALSE] L0023
       PRINT_OBJ       L00
       PRINT           ", off to "
       CALL            R0447 (G00,L04) -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           ", disappears from sight "
       CALL            R0446 (L04,L01) -> L06
       JE              L06,#17 [FALSE] L0020
       PRINT           "up the stairs"
       JUMP            L0022
L0020: JE              L06,#16 [FALSE] L0021
       PRINT           "down the stairs"
       JUMP            L0022
L0021: PRINT           "to "
       CALL            R0450 (L06) -> -(SP)
L0022: PRINT           "."
       NEW_LINE        
       JUMP            L0028
L0023: PRINT_OBJ       L00
       PRINT           " is to "
       CALL            R0447 (G00,L01) -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           ", heading toward "
       CALL            R0446 (L04,L01) -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           "."
       NEW_LINE        
       JUMP            L0028
L0024: GET_PROP        L01,#0c -> L06
       JZ              L06 [TRUE] L0028
       AND             L05,L06 -> -(SP)
       JZ              (SP)+ [TRUE] L0028
       STORE           L0b,#01
       PRINT           "To "
       CALL            R0447 (G00,L01) -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           " "
       PRINT_OBJ       L00
       GET_PROP        L01,#0e -> -(SP)
       JE              (SP)+,#02 [TRUE] L0025
       JE              L01,#cb [FALSE] L0026
L0025: PRINT           " comes into view from "
       JUMP            L0027
L0026: PRINT           " enters the hallway from "
L0027: CALL            R0446 (L01,L04) -> -(SP)
       CALL            R0450 ((SP)+) -> -(SP)
       PRINT           "."
       NEW_LINE        
L0028: LOADW           G03,L07 -> L09
L0029: JG              L0a,#07 [FALSE] L0030
       JUMP            L0035
L0030: LOADW           G06,L0a -> L07
       JE              L07,L00 [FALSE] L0031
       JUMP            L0034
L0031: JZ              L0a [FALSE] L0032
       JZ              L0b [FALSE] L0033
L0032: LOADW           G06,L0a -> -(SP)
       JIN             (SP)+,L04 [FALSE] L0034
L0033: STOREW          L09,L0a,G76
       LOADW           G03,L0a -> -(SP)
       STOREW          (SP)+,L08,G76
L0034: INC             L0a
       JUMP            L0029
L0035: INSERT_OBJ      L00,L01
       RET             L0b

Routine R0446, 6 locals (0000, 0000, 0000, 0000, 0000, 0000)

       STORE           L02,#00
L0001: GET_NEXT_PROP   L00,L02 -> L02
       JZ              L02 [TRUE] RFALSE
       JE              L02,#15,#14 [FALSE] L0002
       JUMP            L0001
L0002: JL              L02,Gc0 [TRUE] L0001
       GET_PROP_ADDR   L00,L02 -> L04
       GET_PROP_LEN    L04 -> L03
       JE              L03,#05,#01,#04 [FALSE] L0001
       LOADB           L04,#00 -> -(SP)
       JE              (SP)+,L01 [FALSE] L0001
       RET             L02

Routine R0447, 7 locals (0000, 0000, 0000, 0000, 0000, 0002, 0000)

       GET_PROP        L01,#0c -> L06
       GET_PROP        L00,#0c -> -(SP)
       AND             L06,(SP)+ -> -(SP)
       CALL            R0448 ((SP)+) -> L02
L0001: LOADW           L02,L05 -> L03
       JE              L03,L00 [FALSE] L0002
       STORE           L04,#01
       JUMP            L0004
L0002: JE              L03,L01 [FALSE] L0003
       JUMP            L0004
L0003: INC             L05
       JUMP            L0001
L0004: LOADW           L02,L04 -> -(SP)
       RET_POPPED      

Routine R0448, 1 local (0000)

       JE              L00,#01 [FALSE] L0001
       RET             G37
L0001: JE              L00,#02 [FALSE] L0002
       RET             G36
L0002: JE              L00,#04 [FALSE] L0003
       RET             G35
L0003: JE              L00,#08 [FALSE] L0004
       RET             G34
L0004: JE              L00,#10 [FALSE] L0005
       RET             G33
L0005: JE              L00,#20 [FALSE] L0006
       RET             G32
L0006: JE              L00,#40 [FALSE] L0007
       RET             G31
L0007: JE              L00,#80 [FALSE] L0008
       RET             G30
L0008: JE              L00,#0100 [FALSE] L0009
       RET             G2f
L0009: JE              L00,#0200 [FALSE] L0010
       RET             G2e
L0010: JE              L00,#0400 [FALSE] L0011
       RET             G2d
L0011: RET             G2c

Routine R0449, 6 locals (0000, 0000, 0000, 0000, 0000, 0000)

       JE              L01,#c2 [FALSE] L0004
       JE              G00,#cc,#dc,#d6 [TRUE] L0001
       JE              G00,#ca,#dd,#c6 [FALSE] L0002
L0001: PRINT           "You can hear footsteps on the staircase."
       NEW_LINE        
       STORE           L04,#01
L0002: CALL            R0445 (L00,#cb) -> -(SP)
       PULL            L05
       JZ              L05 [TRUE] L0003
       RET             L05
L0003: RET             L04
L0004: JE              L01,#cc [FALSE] L0008
       JE              G00,#c2,#c1 [TRUE] L0005
       JE              G00,#be,#bd [FALSE] L0006
L0005: PRINT           "You can hear footsteps on the staircase."
       NEW_LINE        
       STORE           L04,#01
L0006: CALL            R0445 (L00,#cb) -> -(SP)
       PULL            L05
       JZ              L05 [TRUE] L0007
       RET             L05
L0007: RET             L04
L0008: JE              L01,#cb [FALSE] L0010
       GET_PROP        L02,#0e -> -(SP)
       JZ              (SP)+ [FALSE] L0009
       CALL            R0445 (L00,#c2) -> -(SP)
       JUMP            L0014
L0009: CALL            R0445 (L00,#cc) -> -(SP)
       JUMP            L0014
L0010: JE              L01,#f6 [FALSE] L0011
       SET_ATTR        "front door",#1c
       CALL            R0445 (L00,#dd) -> -(SP)
       JUMP            L0014
L0011: JE              L01,#dd [FALSE] L0012
       SET_ATTR        "front door",#1c
       CALL            R0445 (L00,#f6) -> -(SP)
       JUMP            L0014
L0012: JE              L01,#dc [FALSE] L0013
       CALL            R0445 (L00,#c6) -> -(SP)
       JUMP            L0014
L0013: CALL            R0445 (L00,#dc) -> -(SP)
L0014: STORE           L03,(SP)+
       CALL            R0442 (L00,L02) -> -(SP)
       RET             L03

Routine R0450, 2 locals (0000, 0000)

L0001: LOADW           G0e,L01 -> -(SP)
       JE              (SP)+,L00 [FALSE] L0003
       JE              L00,#17,#16 [TRUE] L0002
       PRINT           "the "
L0002: ADD             L01,#01 -> -(SP)
       LOADW           G0e,(SP)+ -> -(SP)
       PRINT_PADDR     (SP)+
       RTRUE           
L0003: INC             L01
       JUMP            L0001

Routine R0451, 0 locals ()

       CALL            R0004 (#bb67,#01) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#bbe0,#01) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#bcf7,#01) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#bd1d,#01) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#bdad,#01) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#bd9e,#01) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#be2f,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0004 (#be50,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           

Routine R0452, 0 locals ()

       STORE           G71,G76
       JE              G00,#e7 [FALSE] RFALSE
       JZ              G6b [FALSE] RFALSE
       STORE           G6a,#01
       PRINT_RET       "All of a sudden, Mr. McNabb starts talking to himself
quite loudly about his poor roses being ruined. He walks up to you and says
"You canna believe the holes someone's made. Crushed my roses. It'll take me
plenty a time to set it right. I just canna believe it!"  He shakes his head
dejectedly."

Routine R0453, 2 locals (0000, 0000)

       GET_PARENT      "Mr. McNabb" -> L01
       JZ              L00 [FALSE] L0001
       CALL            R0459 (#9f,#bb67) -> -(SP)
       RET_POPPED      
L0001: JE              L00,#01 [FALSE] RFALSE
       JE              L01,#e7 [FALSE] L0002
       RANDOM          #0a -> -(SP)
       ADD             #02,(SP)+ -> -(SP)
       CALL            R0004 (#bb06,(SP)+) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          
L0002: JE              L01,#e2 [FALSE] L0006
       JIN             "wooden ladder","Orchard Path" [TRUE] RFALSE
       CLEAR_ATTR      "wooden ladder",#19
       STORE           G59,#00
       STORE           G1c,#00
       SET_ATTR        "wooden ladder",#1e
       JIN             "wooden ladder",Ga8 [FALSE] L0003
       INSERT_OBJ      "wooden ladder","Orchard Path"
       PRINT_RET       "McNabb comes over to you and takes the ladder. He walks
off toward the orchard."
L0003: JIN             "wooden ladder",G00 [FALSE] L0004
       INSERT_OBJ      "wooden ladder","Orchard Path"
       PRINT_RET       "McNabb picks up the ladder and walks away toward the
orchard."
L0004: JE              G00,#e2 [FALSE] L0005
       INSERT_OBJ      "wooden ladder","Orchard Path"
       PRINT_RET       "McNabb places the ladder he was carrying on the
ground."
L0005: INSERT_OBJ      "wooden ladder","Orchard Path"
       RFALSE          
L0006: JE              L01,#e4 [FALSE] RFALSE
       CALL            R0441 (#9f) -> -(SP)
       JE              G00,L01 [FALSE] L0007
       CALL            R0462 (#9f) -> -(SP)
       CALL            R0281 -> -(SP)
       RTRUE           
L0007: CALL            R0004 (#a545,#ffff) -> -(SP)
       STOREW          (SP)+,#00,#01
       RFALSE          

Routine R0454, 2 locals (0000, 0000)

       GET_PARENT      "Mr. Baxter" -> L01
       JZ              L00 [FALSE] L0001
       CALL            R0459 (#9d,#bbe0) -> -(SP)
       RET_POPPED      
L0001: JE              L00,#01 [FALSE] L0002
       JE              L01,#ca [FALSE] L0002
       JIN             "mystery book","Living Room" [FALSE] RFALSE
       INSERT_OBJ      "mystery book","Mr. Baxter"
       SET_ATTR        "mystery book",#19
       RFALSE          
L0002: JE              L00,#01 [FALSE] L0003
       JE              L01,#a7 [FALSE] L0003
       JE              G00,#a7 [FALSE] L0003
       PRINT           "Baxter looks at the body of Ms. Dunbar, lying on the
floor, and falls to his knees. He starts to sob. "I knew she would do this," he
says, sobbing, "but I couldn't stop her. She killed Marshall. She just told me
a few minutes ago. She said that he was going to fire her, just like that,
after all of these years. She was so hysterical, I couldn't understand
everything she said, something about having stolen some money. I don't know." 
With that, he breaks down again."
       NEW_LINE        
       CALL            R0004 (#a43c,#0a) -> -(SP)
       STOREW          (SP)+,#00,#01
       RTRUE           
L0003: JE              L00,#01 [FALSE] L0004
       JE              L01,#e9 [FALSE] L0004
       JE              G00,#e8 [FALSE] RFALSE
       PRINT_RET       "The sound of quick footsteps precedes someone into the
shed. You can make out two voices in rapid conversation. The voices are
muffled, however, and cannot be made out."
L0004: JE              L00,#01 [FALSE] RFALSE
       JE              L01,#f9 [FALSE] RFALSE
       JE              G00,#f9 [FALSE] L0005
       REMOVE_OBJ      "Mr. Baxter"
       PRINT_RET       "A limousine comes up the drive and picks up Mr.
Baxter."
L0005: JE              G00,#f6,#f2,#f4 [FALSE] L0006
       REMOVE_OBJ      "Mr. Baxter"
       PRINT_RET       "To the south, you observe a limousine picking up Mr.
Baxter."
L0006: REMOVE_OBJ      "Mr. Baxter"
       RFALSE          

Routine R0455, 2 locals (0000, 0000)

       GET_PARENT      "Ms. Dunbar" -> L01
       JZ              L00 [FALSE] L0001
       CALL            R0459 (#9b,#bcf7) -> -(SP)
       RET_POPPED      
L0001: JE              L00,#01 [FALSE] RFALSE
       JE              L01,#e9 [FALSE] RFALSE
       JE              G00,#e8 [FALSE] RFALSE
       PRINT_RET       "You hear soft footsteps approaching. Someone has
entered the shed!"

Routine R0456, 2 locals (0000, 0000)

       GET_PARENT      "George" -> L01
       JE              L00,#01 [FALSE] L0001
       JE              L01,#ee [FALSE] L0001
       CALL            R0441 (#99) -> -(SP)
       RFALSE          
L0001: JE              L00,#01 [FALSE] L0002
       JE              L01,#a4 [FALSE] L0002
       STORE           G13,#01
       CALL            R0002 (G11) -> G12
       CALL            R0004 (#b2da,#19) -> -(SP)
       STOREW          (SP)+,#00,#01
       JE              G00,L01 [FALSE] RFALSE
       PRINT           "George walks over to his stereo and puts on a record.
He turns to you. "I naturally assume that you would like to hear a "
       PRINT_PADDR     G12
       PRINT_RET       "." he says, barely concealing his clear distaste for
you and your profession."
L0002: JE              L00,#01 [FALSE] L0003
       JE              L01,#de [FALSE] L0003
       REMOVE_OBJ      "new will"
       INSERT_OBJ      "wet piece of paper","lake"
       STORE           G48,#00
       CALL            R0441 (#99) -> -(SP)
       JE              G00,#de [FALSE] RFALSE
       PRINT_RET       "You catch, out of the corner of one eye, George
motioning with his arm toward the lake."
L0003: JZ              L00 [FALSE] RFALSE
       CALL            R0459 (#99,#bd1d) -> -(SP)
       RET_POPPED      

Routine R0457, 1 local (0000)

       JE              L00,#01 [FALSE] L0001
       JIN             "Mrs. Rourke","Mrs. Rourke's Room" [FALSE] L0001
       CALL            R0441 (#95) -> -(SP)
       RFALSE          
L0001: JZ              L00 [FALSE] RFALSE
       CALL            R0459 (#95,#bd9e) -> -(SP)
       RET_POPPED      

Routine R0458, 2 locals (0000, 0000)

       GET_PARENT      "Mrs. Robner" -> L01
       JE              L00,#01 [FALSE] L0001
       JE              L01,#b2 [FALSE] L0001
       JZ              G6d [FALSE] RFALSE
       TEST_ATTR       "hidden door",#1c [FALSE] RFALSE
       STORE           G6d,#01
       JE              G00,#b4,#b2 [FALSE] RFALSE
       PRINT_RET       "Mrs. Robner stares in complete surprise at the hidden
closet. "I had no idea that such a place existed!"  She sits down on her bed."
L0001: JZ              L00 [FALSE] RFALSE
       CALL            R0459 (#97,#bdad) -> -(SP)
       RET_POPPED      

Routine R0459, 10 locals (0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000,
                          0000)

       GET_PROP        L00,#07 -> L06
       LOADW           G04,L06 -> L02
       LOADW           G08,L06 -> L08
       LOADW           L02,#00 -> L07
       JZ              L07 [TRUE] L0002
       LOADW           L08,#05 -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       STOREW          L08,#06,L07
       JUMP            L0002
L0001: CALL            R0442 (L00,L07) -> -(SP)
L0002: LOADW           L02,#01 -> L05
       JZ              L05 [TRUE] RFALSE
       LOADW           L02,#02 -> L03
       MUL             L03,#02 -> -(SP)
       RANDOM          (SP)+ -> L04
       SUB             L04,L03 -> -(SP)
       ADD             L05,(SP)+ -> -(SP)
       CALL            R0004 (L01,(SP)+) -> -(SP)
       ADD             L02,#06 -> -(SP)
       STOREW          G04,L06,(SP)+
       LOADW           L02,#04 -> -(SP)
       JZ              (SP)+ [TRUE] RFALSE
       LOADW           L02,#04 -> L09
       SUB             L03,L04 -> -(SP)
       ADD             L09,(SP)+ -> -(SP)
       STOREW          L02,#04,(SP)+
       RFALSE          

Routine R0460, 3 locals (0000, 0000, 0000)

L0001: INC_CHK         L01,#07 [FALSE] L0002
       RET             L00
L0002: LOADW           G08,L01 -> L02
       LOADW           L02,#01 -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       LOADW           L02,#04 -> -(SP)
       JZ              (SP)+ [FALSE] L0003
       LOADW           L02,#09 -> -(SP)
       JZ              (SP)+ [FALSE] L0001
L0003: STOREW          L02,#04,#01
       LOADW           G06,L01 -> -(SP)
       CALL            R0443 ((SP)+) -> -(SP)
       JZ              (SP)+ [TRUE] L0001
       STORE           L00,#01
       JUMP            L0001

Routine R0461, 3 locals (0000, 0000, 0000)

L0001: INC_CHK         L01,#07 [FALSE] L0002
       RET             L00
L0002: LOADW           G07,L01 -> -(SP)
       SUB             (SP)+,#01 -> L02
       JE              L02,#01 [FALSE] L0003
       LOADW           G06,L01 -> -(SP)
       JIN             (SP)+,G00 [FALSE] L0004
       LOADW           G06,L01 -> -(SP)
       PRINT_OBJ       (SP)+
       PRINT           " starts to move about distractedly."
       NEW_LINE        
       STORE           L00,#01
       JUMP            L0004
L0003: JZ              L02 [FALSE] L0004
       LOADW           G08,L01 -> -(SP)
       STOREW          (SP)+,#04,#01
L0004: STOREW          G07,L01,L02
       JUMP            L0001

Routine R0462, 4 locals (0000, 0000, 0000, 0000)

       GET_PROP        L00,#07 -> L01
       LOADW           G08,L01 -> L02
       LOADW           L02,#01 -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       LOADW           L02,#08 -> L03
       STOREW          G07,L01,L03
       JZ              L03 [FALSE] L0001
       STOREW          L02,#04,#01
       RFALSE          
L0001: LOADW           L02,#04 -> -(SP)
       JZ              (SP)+ [TRUE] L0002
       STOREW          L02,#04,#00
L0002: STORE           G7a,L00
       STORE           G79,G00
       RTRUE           

Routine R0463, 1 local (0000)

       JE              L00,#01 [FALSE] RFALSE
       JIN             "Mr. Coates","South Lawn" [FALSE] L0002
       REMOVE_OBJ      "Mr. Coates"
       STORE           G4f,#00
       JE              G00,#f9,#f6,#f2 [TRUE] L0001
       JE              G00,#f4,#ee,#f0 [FALSE] RFALSE
L0001: PRINT_RET       "A car pulls up the drive. Coates enters the vehicle,
motions to the driver, and the car starts up and leaves the grounds."
L0002: JIN             "Mr. Coates","Living Room" [FALSE] RFALSE
       JE              G00,#ca [FALSE] L0003
       PRINT           "Mr. Coates shakes your hand. "I'm glad you're here,
Inspector. We'll begin the reading soon.""
       NEW_LINE        
L0003: CALL            R0004 (#743a,#00) -> -(SP)
       STOREW          (SP)+,#00,#01
       CALL            R0299 -> -(SP)
       RET_POPPED      

[End of code]

[Start of text]

S001: "You are on a wide lawn just north of the entrance to the Robner estate.
Directly north at the end of a pebbled path is the Robner house, flanked to the
northeast and northwest by a vast expanse of well-kept lawn. Beyond the house
can be seen the lakefront."
S002: "Leaving the estate would mean quitting the case and, most probably, your
job."
S003: "You are in front of the Robner house just west of the front door. To the
north is a large bay window through which can be seen part of the living room.
To the northwest is the west side of the house."
S004: "You are in front of the Robner house just east of the front door. A
small window, closed and securely locked, is the only thing of note here. To
the northeast is the east side of the house."
S005: "The window is closed and locked."
S006: "This is a sprawling lawn west of the Robner house. To the west and north
is the lake shore. To the northeast is a rose garden, and to the south another
wide lawn."
S007: "You can't go into the lake."
S008: "You are on a neatly manicured lawn, east of the house, which extends
north and east to the shore of a lake. To the northwest is a peaceful orchard,
and toward the south another wide lawn. Southeast, beside the lake, is a small
shed with a solitary dirty window."
S009: "There are no windows or entries of any kind here at the east side of the
house. To the north is the orchard, and the front lawn lies to the south. A
lawn also slopes down toward the shore of a lake to the east."
S010: "You can't enter the house here."
S011: "There are no doors or windows at ground level here on the west side of
the house. A beautiful rose garden, separated by a tall fence, lies to the
north, and the front of the house is to your south. A large lawn bordering the
lake lies to the west."
S012: "A fence prevents your mucking up the rose garden."
S013: "This small garden shed is filled with implements of gardening and lawn
care. Shelves filled with various tools line the walls and a filthy window
looks out on the lawn."
S014: "You are now between the shed and the lake, a position invisible from the
house or the adjacent lawns. There are no windows here, but you can easily
enter the shed via the door around the corner."
S015: "You are on a path at the edge of a small orchard of fruit trees which
abuts the eastern side of the back of the house. The orchard is obviously
intended more to display the beauty of the blossoms in spring than to produce
significant amounts of fruit. The windows of the kitchen look out onto the
orchard, although your view of them is blocked by the trees and a small grape
arbor. To the west is a path along a rose garden, and lawns sweep out to the
north and east."
S016: "This idyllic spot lies on a jut of land well north of the house and is
surrounded on three sides by lake shore. Its charm includes the sweet smell of
roses blown on a southwest breeze from the rose garden and by the sound of the
leaves rustling in the orchard to the southeast."
S017: "This is a hallway north of the foyer. To the west is an open doorway,
and to the east is the foot of a staircase. The hall continues north."
S018: "This is a little-used storage closet containing odds and ends of no
interest whatsoever. The exit is to the north."
S019: "You are at the foot of the stairs to the second floor. Open archways
lead west and south."
S020: "You are at the corner of two halls, one a short hallway to the west
ending with a set of doors, and the other a long hall leading south toward the
front door. To the north are swinging double doors leading into the kitchen."
S021: "You have entered the dining room. A long table seating twelve is in the
center of the room and a large trestle table is against the south wall. A large
picture window to the north allows a view of the rose garden. Hanging on the
wall are several cheerful paintings, including one by Seurat which appears to
be an original."
S022: "This is the Robner kitchen, quite large and with a full complement of
appliances and labor-saving devices. On one wall, a beautifully-crafted shelf
unit contains rare china, a unique hand-painted family heirloom depicting
scenes from Greek mythology. The china consists of many place settings of
plates, teacups, and saucers. There are several cabinets which likely contain
silverware, glasses, and the like. To the east is a pantry."
S023: "This is the pantry with shelves containing a large selection of canned
and packaged foods, such as fruits, vegetables, and dry goods."
S024: "You are on a landing halfway up the flight of stairs. You notice that
the stairs do indeed make quite a noise when stepped upon."
S025: "You are at the top of the staircase where short hallways run north and
south and a corridor the length of the house heads west."
S026: "This is approximately the middle of the corridor, a convenient place for
a closet full of linens. Stairs to the east and a window to the west are about
equidistant. The closet, to the north, is open and rather shallow."
S027: "The hall ends here."
S028: "The fall would probably kill you."
S029: "The closet is rather shallow and has some shelves full of assorted
linens, towels, and uninteresting toilet articles."
S030: "This is Mr. and Mrs. Robner's private bathroom, accessible only from the
bedroom through a door to the west. On one wall is a mirror over a long counter
containing two sinks, and in addition to the usual bathroom fixtures is a
jacuzzi. Hanging plants give the room an almost tropical atmosphere."
S031: "The jump is inadvisable."
S032: "This is the end of a short north-south hallway. To the east is a small
room."
S033: "This room contains the bare essentials for a guest room: bed, tables,
and a chair. A window looks out toward the east."
S034: "The hall ends here. To the south is a walk-in closet."
S035: "This large closet has many shelves containing various cleaning equipment
and supplies."
S036: "FROB"
S037: "Lying atop the desk is a pad of white note paper."
S038: "A stack of papers bound together is in the safe."
S039: "Leafing through these papers, it becomes obvious that they incriminate
Mr. Baxter in wrongdoings regarding the Focus scandal. They document funds
which were embezzled by Baxter and tell how the scandal was hushed up. This
evidence would be sufficient to convict Mr. Baxter in the Focus case."
S040: "This is Mr. Robner's new will, disowning George and giving his entire
estate to his wife."
S041: "Leaning against the front door is today's issue of the Daily Herald."
S042: "A handwritten envelope, recently delivered, is lying on the table."
S043: "
                  CANAAN CT POST OFFICE
                   * JULY 06 * 08:00 *

          Mrs. Marshall Robner
          506 Lake View Rd.
          Maitland, Ct.
"
S044: ""Dear Leslie,
   I am sorry to learn that Marshall has been despondent again. His obsessive
interest in business must be causing you terrible anguish. It doesn't surprise
me that he talks of suicide when he's in this state, but the thought of the
business going to Baxter after he's gone will keep him alive.
   So George has finally gone too far? It's hard to believe, after all those
empty threats, that Marshall actually followed through. It serves that little
leech right, if you ask me. This means that, should the unthinkable happen, you
will be provided for as you deserve.
   I'll see you Friday as usual.

                      Love,
                      Steven"
"
S045: "Leaning in a corner is a wooden ladder."
S046: "Turned onto its side, lying on the floor, is a beautiful teacup."
S047: "Lying on the floor, overturned, is a beautiful saucer."
S048: "Alongside the desk is a wicker wastepaper basket."
S049: "Inside the wastepaper basket are some crumpled papers."
S050: "There are three wads of paper. One is a shopping list. Another is a list
of current stock prices. The last is the start of a letter to the Board of
Directors of the Robner Corp. Unfortunately, it does not contain enough
information to allow even a guess about the intent of the letter."
S051: "The door is a magnificent solid oak piece. Its metal bolt is bent and
the metal piece in which it rested has been sheared off the door frame. It
seems clear that the door was securely locked from the inside when it was
broken down."
S052: "The spots seem to be dried dirt or mud and are bunched in the area
between the balcony and the desk."
S053: "Sitting on the tray is a bowl containing a white powdery substance."
S054: "Beside the desk is a large collapsible tray."
S055: "The ornately carved cornerstone of the house is nearby."
S056: "
   DEADLINE: An INTERLOGIC Mystery
          By Infocom, Inc.
     Marc Blank, Chief Architect
   Copyright 1982 by Infocom, Inc.
        All rights reserved.
DEADLINE and INTERLOGIC are trademarks of Infocom, Inc.
"
S057: "On the bottom shelf is a bottle of tablets labelled 'LoBlo'."
S058: "Frobizz Pharmacy   #69105

Ms. S. Dunbar
LoBLO
Take 1 tablet 3 times daily

Fizmo Labs, Ltd. - Kingston, Ont.
LoBLO Brand of Methsparin, USP
10mg Tablets

Warning:  LoBLO may be dangerous
when used in combination with
other medications. Please read
the enclosed circular prior to
using these tablets.
  "
S059: "On the top shelf, among various toilet items, is a bottle of aspirin."
S060: "

Generic ASPIRIN, usp
     30mg / 5 gr

"
S061: "Standing on a shelf beside some nail polish is a bottle of cough
medicine."
S062: "
General Drug Co.
        DUM - KOF
     Cough Supressant

Directions:  1 tsp every 3-4 hrs
Warning:  Take as Directed. May
cause sedation when taken with other
drugs.

"
S063: "Head Drugs     No. 44543

Mr. Marshall Robner

EBULLION Tablets, 25mg.

Directions: Take 1 or 2 twice
daily for depression.

Warning:  Keep out of the reach
of children. May be harmful or
fatal in sufficient dosage.
"
S064: "Dear Inspector,

    In response to your request for analysis of the ceramic fragment, we have
found evidence of a drug called Methsparin, which is usually sold in this
country under the name "LoBlo". It is a blood pressure lowering agent used
primarily in Europe, which explains the oversight in our blood analysis of the
deceased. A double check reveals a high blood level of Methsparin. While the
amount of Methsparin in the blood isn't dangerous in itself, a strong reaction
between it and various other drugs has been well documented. As you may have
gathered, one of those drugs is Amitraxin (Ebullion). The effect of Methsparin
is to displace Amitraxin from protein binding, leaving more free in the blood
and simulating an overdose.
    Your new evidence leads me to conclude that the cause of death was
Amitraxin toxicity secondary to ingestion of Methsparin and Amitraxin in
combination.

Sincerely,

Arthur Chatworth, Pathologist
"
S065: "Lying beside the body is a smoking gun."
S066: "Sprawled on the floor is the body of Ms. Dunbar."
S067: "Next to the body, near a pool of blood, is a note."
S068: "The note is written in thin blue ink in a very unsteady hand and is
smeared with blood from your touch. It says:

    "I killed Mr. Robner. Please forgive me."
"
S069: "A pool of blood is at the head of the body."
S070: "A half-filled bottle of Scotch is in the cabinet."
S071: "A nearly empty bottle of Bourbon is here."
S072: "On the counter is a bottle of Sneezo tablets."
S073: "Lakeville Pharmacy   #223224

Mrs. M. Robner
Take 1 tablet every 3 hours as needed

Sniffle Labs
Sneezo Tablets
"
S074: "Beside a toothbrush is a bottle of Allergone."
S075: "Lakeville Pharmacy   #220331

Mrs. M. Robner
Take 2 tablets every 4 hours as needed for allergy symptoms. Do not exceed
recommended dosage.

Rash Labs / Allergone Tablets

May cause extreme drowsiness. Do not
use machinery or drive while taking this
medication. Combination of Allergone with
alcohol is dangerous. In case of overdose
consult a physician promptly. Keep out
of the reach of children!
"
S076: "The paper was once some sort of document. It is now smeared and
completely unreadable."
S077: "A pencil is lying on the floor near the desk."
S078: "Sitting on a table is a hardcover book."
S079: "Lying on the ground is what appears to be a ticket stub."
S080: "
   Hartford
 Philharmonic
  Orchestra

 July 7, 1982

   - 8PM -

Row R / Seat 7

-^-^-^-^-^-^-^

"
S081: "  "
S082: "    "
S083: "      "
S084: "        "
S085: "          "
S086: " a transcript of interaction with DEADLINE.
DEADLINE is a trademark of Infocom, Inc.
Copyright (c) 1982 Infocom, Inc. All rights reserved.
"
S087: "You ought to be ashamed of yourself."
S088: "One must try to avoid locker-room talk while working."
S089: "Hello"
S090: "Goodbye"
S091: "kill"
S092: "attack"
S093: "Kicking the "
S094: "Waving the "
S095: "Playing in this way with the "
S096: "Fiddling with the "
S097: "Pushing the "
S098: "Trying to destroy the "
S099: " isn't particularly useful."
S100: " has no effect."
S101: "him"
S102: "he"
S103: "her"
S104: "she"
S105: " doesn't appear interested"
S106: " seems not to care"
S107: " lets out a loud yawn"
S108: " seems to be getting impatient"
S109: "pm"
S110: "am"
S111: "You've got to be crazy, carrying that ladder inside the house!"
S112: "You are at the Robners' front door, which is "
S113: "."
S114: "This is the foyer of the Robner house, beautifully appointed with a fine
crystal chandelier, marble floors, and a large marble-topped table. The front
door, to the south, is "
S115: ". The foyer continues north."
S116: "You are in an east-west hallway south of the staircase. A door to the
south is "
S117: "This is the end of the east-west hallway. To the south a small door is "
S118: "Another door, to the east, is "
S119: "This is the bedroom of the housekeeper, Mrs. Rourke, and is very simply
furnished. A single bed, flanked by bare wooden end tables, sits below a closed
window on the south end of the room. The floor is hardwood, with no rug. The
only exit is a door to the north, which is "
S120: "This is Mrs. Rourke's bathroom. Aside from the usual bathroom fixtures
are two shelves affixed to the wall. The door at the west side of the room is "
S121: "This is a large and impressive room, whose furnishings bespeak the great
personal wealth of the Robners. The south side of the room is a large bay
window, now "
S122: ", which looks out onto the front yard."
S123: "picking weeds"
S124: "mowing the grass"
S125: "wiping his brow"
S126: "examining his work"
S127: "planting seeds"
S128: "cutting fresh flowers"
S129: "pruning stems"
S130: "This section of hallway is near the west end. Through the window at the
end of the hall you can see some trees and the lake beyond. The hallway
continues east and west, and a door to the south is "
S131: "The balcony is bare of furniture, though it has a beautiful view of the
rose garden, the north lawn and the lake. A metal railing around the balcony 
prevents an accidental drop to the thorny roses below. The window between the
balcony and the library is "
S132: "This is the Robners' master bedroom, decorated in the Queen Anne style.
A large four-poster bed with paired end tables fills the south end of the room.
On one of the end tables is a telephone. Dressers, a small chair, and a lounge
are against the walls. The north wall contains a balcony window, which is "
S133: ". An open doorway leads east to the bathroom. A large mirror with a gilt
frame hangs on the west wall."
S134: "This balcony is atop the orchard, with the tallest of the fruit trees
rising to about the level of the balcony. A metal railing surrounds the
balcony, preventing a precipitous descent. A glass door leading to the master
bedroom is "
S135: "The hallway turns a corner here and continues east. To the north is the
head of the stairs. A door to the south is "
S136: ", is above the sink. A door to the north is "
S137: "This is Ms. Dunbar's room. It is furnished in the usual style, with a
few additions indicative of Ms. Dunbar's taste. The bedroom door is "
S138: "This is George's bathroom, with all the appropriate fixtures. Shaving
gear sits near the sink. The door, to the west, is "
S139: ". Another door, to the east, is "
S140: "You are making quite a mess, but you do run across some tiny pieces of a
hard, shiny substance, which drop from your fingers and back onto the ground."
S141: "Although everything is coming up roses, you haven't found anything
unusual except for a few pieces of a hard substance which fall back to the
ground."
S142: "rose garden"
S143: "fruit trees"
S144: "weather"
S145: "snootiness of city slickers"
S146: "intricacies of weeding"
S147: ""You can do that yourself.""
S148: ""Do it yourself!""
S149: ""Why not do it yourself?""
S150: "August 10"
S151: "August 13"
S152: "August 11"
S153: "July 26"
S154: "show me useless items"
S155: "pick up every item in the house and show it to me"
S156: "August 4"
S157: " is standing here."
S158: "Don't be ridiculous."
S159: "Surely you jest."
S160: "You can't be serious!"
S161: "Examination of the paper"
S162: "Shading the paper with the pencil"
S163: "Running the pencil over the paper"
S164: "Looking at the pad against the light"
S165: "Partially exposed under the front door is an envelope."
S166: "August 2"
S167: "kitchen"
S168: "there"
S169: "east lawn"
S170: "shed"
S171: "dining room"
S172: "here"
S173: "September 5"
S174: "August 19"
S175: "September 2"
S176: "October 4"
S177: "October 6"
S178: "November 12"
S179: "August 1"
S180: "Hungarian Rhapsody"
S181: "march by Sir Edward Elgar"
S182: "chorus of African tribal music"
S183: "Hebrew prayer service"
S184: "Pretenders concert"
S185: "cacophonous electronic jumble"
S186: "bluegrass tune"
S187: "Wagnerian opera"
S188: "New Orleans jazz band"
S189: "Bulgarian shepherdess song"
S190: "Navajo night chant"
S191: "simulated rain shower"
S192: "risque Russian drinking song"
S193: ""Murder? My dear inspector, I believe you are reading too many bad
detective stories. It's clear that he committed suicide.""
S194: "Ms. Dunbar turns toward you, looking quite confused. "Murder? But...but
how do you know it was murder? I'm sure..." She stops short, looking
frightened."
S195: ""My father killed himself, as everyone knows. Please leave me alone.""
S196: ""That's odd that you should say murder. Surely you don't suspect foul
play, Inspector. My husband was devoted to his business, and its decline led
him to take his life. The whole affair is tragic enough without your
melodramatic insinuations.""
S197: ""Was it a murder, then?" She bounces with excitement. "In the book I've
been reading, the jealous wife did it, but I don't know about this. A whole
batch of suspects, this group here. What do you know? A murder. Here!" Her
enjoyment is barely concealed."
S198: "north"
S199: "south"
S200: "east"
S201: "west"
S202: "northwest"
S203: "northeast"
S204: "southwest"
S205: "southeast"
S206: "downstairs"
S207: "upstairs"
S208: "in"
S209: "out"
S210: "Mr. McNabb is an elderly Scottish man with a deeply lined face. He is
wearing overalls."
S211: "Baxter is an immaculately dressed middle-aged man with rugged good
looks."
S212: "Ms. Dunbar, wearing a fashionable pants suit, is a rather attractive
woman in her early thirties."
S213: "George is a young man in his mid-twenties. He is poorly dressed in that
each item he is wearing clashes with the others. His attire is of the highest
quality, however. He is wearing various pieces of jewelry."
S214: "Mrs. Robner is a middle-aged woman of great beauty. She is dressed in
black."
S215: "Mrs. Rourke is a short woman, more than a bit overweight. She is wearing
a maid's outfit."
S216: "Mr. Coates is a rather homely man of advancing years."

[End of text]

[End of file]
