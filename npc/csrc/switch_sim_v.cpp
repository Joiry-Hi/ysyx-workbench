#include "Vswitch.h"
#include "verilated.h"
#include "verilated_fst_c.h"

int main(int argc, char **argv)
{
    int sim_time = 11;

    VerilatedContext *contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
    Vswitch *top = new Vswitch{contextp};

    Verilated::traceEverOn(true);
    VerilatedFstC* tfp = new VerilatedFstC;
    top->trace(tfp, 99);
    tfp->open("obj_dir/t_trace_ena_cc/simx.fst");

    while (contextp->time() < sim_time && !contextp->gotFinish())
    {
        contextp->timeInc(1);
        int a = rand() & 1;
        int b = rand() & 1;
        top->a = a;
        top->b = b;
        top->eval();
        printf("a = %d, b = %d, f = %d\n", a, b, top->f);
        tfp->dump(contextp->time());
        assert(top->f == (a ^ b));
    }
    delete top;
    delete contextp;
    return 0;
}
