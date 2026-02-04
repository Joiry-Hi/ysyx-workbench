module waterfall(
  input clk,
  input rst,
  output [15:0] ledr
);
  reg [31:0] count;
  reg [15:0] led;
  always @(posedge clk) begin
    if (rst) begin led <= 16'b1101001000100001; count <= 0; end
    else begin
      if (count == 0) led <= {led[14:0], led[15]};
      count <= (count >= 5000000 ? 32'b0 : count + 1);
    end
  end

    assign ledr = led;
endmodule
