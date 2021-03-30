#include "systemc.h"

#define WIDTH 32

SC_MODULE(reg){
    sc_in_clk clk;
    sc_in<sc_bv<1>> rst;
    sc_in<sc_bv<WIDTH>> input;
    sc_out<sc_bv<WIDTH>> output;
    
    void register_logic(){
        if(rst.read() == "1"){
            output.write("00000000000000000000000000000000");
        } else if(clk.posedge()){
            output.write(input.read());
        }
    }

    SC_CTOR(reg){
        SC_METHOD(register_logic);
        sensitive << clk << rst;
    }
};