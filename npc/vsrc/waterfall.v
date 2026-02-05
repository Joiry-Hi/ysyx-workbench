module waterfall(
  input clk,
  input rst,
  output [15:0] led
);
  reg [31:0] count;
  reg [15:0] ledr;
  // wire a, b; // For testing warning function

  always @(posedge clk) begin
    if (rst) begin ledr <= 16'b1101001000100001; count <= 0; end
    else begin
      if (count == 0) ledr <= {ledr[14:0], ledr[15]};
      count <= (count >= 5000000 ? 32'b0 : count + 1);
    end
  end

  // always_comb begin
  //   a = b;
  //   b = 1;
  // end

  assign led = ledr;

endmodule
