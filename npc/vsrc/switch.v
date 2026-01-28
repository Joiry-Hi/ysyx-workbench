module switch(
  input a,
  input b,
  output f
);
  assign f = a ^ b;

  initial begin
    $dumpfile("./switch_dump.fst");
    $dumpvars();
  end

endmodule
