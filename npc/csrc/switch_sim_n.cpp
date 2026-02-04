#include <nvboard.h>
#include <Vswitch.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME *top);

int main()
{
    int n = 0;

    nvboard_bind_all_pins(&dut);
    nvboard_init();             

    while (1)
    {
        n = (n + 1) % 10000000; // 这种程度的缩放才能使间隔可感
        nvboard_update();
        if (n) {
            dut.eval();
            continue;
        }
        int a = rand() & 1;
        int b = rand() & 1;
        dut.a = a;
        dut.b = b;
        dut.eval();
        printf("a = %d, b = %d, f = %d\n", a, b, dut.f);
        assert(dut.f == (a ^ b));
    }

    return 0;
}
