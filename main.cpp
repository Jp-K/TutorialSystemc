#include "mux.h"

#define WIDTH  1

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<WIDTH> >w_a,w_b,w_out,w_sel;

    mux add("mux");

    sc_trace_file *wf = sc_create_vcd_trace_file("mux");

    add.a(w_a);
    add.b(w_b);
    add.sel(w_sel);
    add.out(w_out);

    sc_trace(wf, w_a, "a");
    sc_trace(wf, w_b, "b");
    sc_trace(wf, w_out, "out");
    sc_trace(wf, w_sel, "sel");

    w_a.write(1);
    w_b.write(0);

    sc_start(1, SC_NS);

    w_sel.write(0);

    sc_start(10, SC_NS);

    cout<< "resultado: " <<w_out.read()<<"\n";

    w_sel.write(1);

    sc_start(10, SC_NS);

    cout<< "resultado: " <<w_out.read()<<"\n";

    sc_stop();

     cout << "@ " << sc_time_stamp() <<" Terminating simulation\n" << endl;

    sc_close_vcd_trace_file(wf);
    return 0;
}