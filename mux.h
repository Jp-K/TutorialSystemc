#include "systemc.h"

#define WIDTH  1

SC_MODULE(mux) {
    sc_in<sc_uint<WIDTH> > a, b, sel;
    sc_out<sc_uint<WIDTH> > out;

    void do_mux() {

    if(sel.read()==0){
        out.write(a.read());
    }else {
        out.write(b.read());
    }
        
    }

    SC_CTOR(mux) {
        SC_METHOD(do_mux);
        sensitive << a << b << sel;
    }
};