/* Generated by Yosys 0.6 (git sha1 UNKNOWN, clang 3.4-1ubuntu3 -fPIC -Os) */module simpleI_R(a, b, clk, rst, y);  wire _0_;  input a;  input b;  wire c;  input clk;  input rst;  output y;  AND2X2 _1_ (    .A(a),    .B(b),    .Y(c)  );  AND2X2 _2_ (    .A(c),    .B(rst),    .Y(_0_)  );  DFFPOSX1 _3_ (    .CLK(clk),    .D(_0_),    .Q(y)  );endmodule
