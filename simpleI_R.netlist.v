/* Generated by Yosys 0.6 (git sha1 UNKNOWN, clang 3.4-1ubuntu3 -fPIC -Os) */

module D_FF(D, clk, rst, q);
  wire _0_;
  input D;
  input clk;
  output q;
  input rst;
  AND2X2 _1_ (
    .A(D),
    .B(rst),
    .Y(_0_)
  );
  DFFPOSX1 _2_ (
    .CLK(clk),
    .D(_0_),
    .Q(q)
  );
endmodule

module simpleI_R(a, b, clk, rst, y);
  input a;
  input b;
  wire c;
  input clk;
  input rst;
  output y;
  AND2X2 _0_ (
    .A(a),
    .B(b),
    .Y(c)
  );
  D_FF dff1 (
    .D(c),
    .clk(clk),
    .q(y),
    .rst(rst)
  );
endmodule