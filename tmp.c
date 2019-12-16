#include <stdint.h>                                                                                                                        
                                                                                                                                           
int32_t blue (void) {                                                                                                                      
    uint32_t var_14h;                                                                                                                      
    uint32_t var_10h;                                                                                                                      
    int32_t var_ch;                                                                                                                        
    uint32_t var_8h;                                                                                                                       
    int32_t var_4h;                                                                                                                        
    blue_preflight ();                                                                                                                     
    var_4h = obj.graph;                                                                                                                    
    eax = obj.graph;                                                                                                                       
    eax = *((eax + 4));                                                                                                                    
    var_8h = *((eax + 4));                                                                                                                 
    var_ch = 0;         
    //15byte버퍼                                                                                                                   
    while (var_ch <= 0xe) {                                                                                                                
        var_10h = 0;                                                                                                                       
        eax = var_ch;                                                                                                                      
        eax = *((eax + obj.buffer));                                                                                                       
        eax = (int32_t) al;                                                                                                                
        var_14h = eax;                                                                                                                     
        if (var_14h != 0x4c) {    // L                                                                                                         
            if (var_14h != 0x52) {   // R                                                                                                      
                if (var_14h == 0xa) { //'\n'
                    goto label_0;
                }//end-if
            } 
            else {  //var_14h == 0x52 , R
                eax = var_4h;
                eax = *(eax);
                var_4h = *(eax);
                goto label_1;
            }
            eax = var_4h;
            eax = *((eax + 8));
            var_4h = *((eax + 8));
            goto label_1;
        label_0:
            var_10h = 1;
            goto label_1;
        }
        /*else*/
        var_10h = 1;
        puts ("boom");
        label_1:
        if (var_10h != 0) {
            goto label_2;
        }
        eax = var_4h;
        eax = *((eax + 4));
        var_8h ^= eax;
        var_ch++;
    }//end while

    label_2:
        printf ("\e[46m \e[0m\e[36m PROGRAMMING GATE ARRAY... ");
        eax = stdout;
        fflush (eax);
        sleep (1);
        puts ("SUCCEEDED\e[0m");
        usleep (0x7a120);
        eax = solution;

        if (var_8h == eax) {
            puts ("\e[46m \e[0m\e[36m VOLTAGE REROUTED FROM REMOTE DETONATION RECEIVER \e[0m");
            eax = wire_blue;
            eax--;
            *(obj.wire_blue) = eax;
        } 
        else {
            eax = wire_blue;
            eax++;
            *(obj.wire_blue) = eax;
        }

    return eax;
}

