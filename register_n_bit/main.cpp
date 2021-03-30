#include "register_n_bit.h"

#define WIDTH  32

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_bv<WIDTH> >w_input,w_output;
    sc_signal<sc_bv<1>> w_rst;
    sc_clock clk;

    reg regis("reg");

    sc_trace_file *wf = sc_create_vcd_trace_file("reg");

    regis.input(w_input);
    regis.output(w_output);
    regis.rst(w_rst);
    regis.clk(clk);

    sc_trace(wf, w_input, "w_input");
    sc_trace(wf, w_output, "w_output");
    sc_trace(wf, w_rst, "w_rst");
    sc_trace(wf, clk, "clk");


    w_rst.write("1");
    w_input.write("00010001000100010001000100010001");

    sc_start(0.5, SC_NS);

    cout << "saida com rst: " << w_output.read() << "\n";

    w_rst.write("0");

    cout << "saida sem rst: " << w_output.read() << "\n";

    sc_start(0.5, SC_NS);

    cout << "saida sem rst: " << w_output.read() << "\n";

    sc_start(0.5, SC_NS);

    cout << "saida sem rst: " << w_output.read() << "\n";

    sc_start(0.5, SC_NS);

    cout << "saida sem rst: " << w_output.read() << "\n";

    sc_start(0.5, SC_NS);

    w_input.write("00010111111111110001000100010001");

    cout << "saida sem rst: " << w_output.read() << "\n";

    sc_start(0.5, SC_NS);

    cout << "saida sem rst: " << w_output.read() << "\n";

    sc_start(0.5, SC_NS);

    cout << "saida sem rst: " << w_output.read() << "\n";

    sc_start(0.5, SC_NS);



    sc_stop();

     cout << "@ " << sc_time_stamp() <<" Terminating simulation\n" << endl;

    sc_close_vcd_trace_file(wf);
    return 0;
}