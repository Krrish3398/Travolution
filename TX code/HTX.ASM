
                 
               org       0000h
               mov       tmod,#20h   
               mov       SCON,#40h
	       MOV       TH1,#0E8H
	       setb      tr1
	       
main:	       
	       MOV      SBUF,#'H'
	       JNB      TI,$
	       CLR      TI
               LJMP     MAIN



end 
